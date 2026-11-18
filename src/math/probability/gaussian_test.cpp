#include "src/math/probability/gaussian.hpp"

#include <cmath>
#include <format>
#include <numbers>
#include <random>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <gtest/gtest.h>

namespace probability {
namespace {

using Gaussian1 = Gaussian<1>;
using Gaussian2 = Gaussian<2>;

constexpr double kTolerance = 1e-12;

// Round trip: fitting many samples from a known Gaussian recovers its
// parameters. The seed is fixed, so the result is deterministic on a given
// standard library.
//
// kRoundTripTolerance is provisional: a few standard errors at this sample
// count, picked by eye. Deriving it from the convergence rate is the open
// question in the plan's Validation section.
TEST(GaussianSample, FitRecoversParameters) {
  constexpr int kSampleCount = 10'000;
  constexpr double kRoundTripTolerance = 0.1;

  const Gaussian2::Vec mean{1.0, -2.0};
  Gaussian2::Mat covariance;
  covariance << 2.0, 0.6, 0.6, 1.0;
  const Gaussian2 gaussian(mean, covariance);
  std::mt19937_64 rng(0);

  const Gaussian2 fit = Gaussian2::Fit(gaussian.SampleN(rng, kSampleCount));

  EXPECT_LT((fit.Mean() - mean).cwiseAbs().maxCoeff(), kRoundTripTolerance) << "fit mean:\n"
                                                                            << fit.Mean();
  EXPECT_LT((fit.Covariance() - covariance).cwiseAbs().maxCoeff(), kRoundTripTolerance)
      << "fit covariance:\n"
      << fit.Covariance();
}

// SampleN returns n draws, and each is a valid sample (finite values).
TEST(GaussianSample, SampleNReturnsRequestedCount) {
  const Gaussian2 gaussian(Gaussian2::Vec::Zero(), Gaussian2::Mat::Identity());
  std::mt19937_64 rng(0);

  const std::vector<Gaussian2::Vec> samples = gaussian.SampleN(rng, 5);

  ASSERT_EQ(samples.size(), 5U);
  for (const auto& x : samples) {
    EXPECT_TRUE(x.allFinite()) << x;
  }
  EXPECT_TRUE(gaussian.SampleN(rng, 0).empty());
}

// A covariance that isn't positive definite is rejected at construction.
TEST(GaussianConstruction, RejectsInvalidCovariance) {
  Gaussian2::Mat indefinite;
  indefinite << 1.0, 0.0, 0.0, -1.0;

  // The macro's expansion trips these checks; the code under test doesn't.
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-goto,modernize-type-traits)
  EXPECT_THROW(Gaussian2(Gaussian2::Vec::Zero(), indefinite), std::runtime_error);
}

TEST(GaussianFormat, PrintsMeanAndCovariance) {
  Gaussian2::Mat covariance;
  covariance << 2.0, 0.5, 0.5, 1.0;
  const Gaussian2 gaussian(Gaussian2::Vec{1.0, -2.0}, covariance);

  EXPECT_EQ(std::format("{}", gaussian), "N(mean=[1, -2], cov=[[2, 0.5], [0.5, 1]])");
  std::ostringstream os;
  os << gaussian;
  EXPECT_EQ(os.str(), "N(mean=[1, -2], cov=[[2, 0.5], [0.5, 1]])");
}

// Samples (1, 2), (3, 4), (5, 9): mean (3, 5), deviations (-2, -3), (0, -1),
// (2, 4). The sum of their outer products is [[8, 14], [14, 26]], divided by
// n - 1 = 2.
TEST(GaussianFit, MatchesHandComputedMoments) {
  const std::vector<Gaussian2::Vec> samples = {
      Gaussian2::Vec{1.0, 2.0},
      Gaussian2::Vec{3.0, 4.0},
      Gaussian2::Vec{5.0, 9.0},
  };

  const Gaussian2 fit = Gaussian2::Fit(samples);

  const Gaussian2::Vec expected_mean{3.0, 5.0};
  Gaussian2::Mat expected_covariance;
  expected_covariance << 4.0, 7.0, 7.0, 13.0;
  EXPECT_TRUE(fit.Mean().isApprox(expected_mean, kTolerance)) << fit.Mean();
  EXPECT_TRUE(fit.Covariance().isApprox(expected_covariance, kTolerance)) << fit.Covariance();
}

// The fit doesn't depend on the order of the samples.
TEST(GaussianFit, IsPermutationInvariant) {
  const std::vector<Gaussian2::Vec> samples = {
      Gaussian2::Vec{1.0, 2.0},
      Gaussian2::Vec{3.0, 4.0},
      Gaussian2::Vec{5.0, 9.0},
  };
  const std::vector<Gaussian2::Vec> reversed(samples.rbegin(), samples.rend());

  const Gaussian2 fit = Gaussian2::Fit(samples);
  const Gaussian2 reversed_fit = Gaussian2::Fit(reversed);

  EXPECT_TRUE(fit.Mean().isApprox(reversed_fit.Mean(), kTolerance));
  EXPECT_TRUE(fit.Covariance().isApprox(reversed_fit.Covariance(), kTolerance));
}

// The standard normal's density at its mean is 1 / sqrt(2 pi).
TEST(GaussianPdf, StandardNormalAtMean) {
  const Gaussian1 standard(Gaussian1::Vec::Zero(), Gaussian1::Mat::Identity());

  EXPECT_NEAR(standard.Pdf(Gaussian1::Vec::Zero()), 1.0 / std::sqrt(2.0 * std::numbers::pi),
              kTolerance);
}

// One standard deviation from the mean, the density falls by exp(-1/2).
TEST(GaussianPdf, ScalarOneSigmaFromMean) {
  const double sigma = 2.0;
  const Gaussian1 gaussian(Gaussian1::Vec{1.0}, Gaussian1::Mat{sigma * sigma});

  EXPECT_NEAR(gaussian.Pdf(Gaussian1::Vec{1.0 + sigma}),
              gaussian.Pdf(Gaussian1::Vec{1.0}) * std::exp(-0.5), kTolerance);
}

// Correlated 2D case. With Sigma = [[2, 1], [1, 2]]: det = 3,
// Sigma^-1 = [[2, -1], [-1, 2]] / 3, so at x = (1, 0) the quadratic form is
// 2/3 and p(x) = exp(-1/3) / (2 pi sqrt(3)).
TEST(GaussianPdf, CorrelatedBivariate) {
  Gaussian2::Mat covariance;
  covariance << 2.0, 1.0, 1.0, 2.0;
  const Gaussian2 gaussian(Gaussian2::Vec::Zero(), covariance);

  const double expected = std::exp(-1.0 / 3.0) / (2.0 * std::numbers::pi * std::numbers::sqrt3);
  EXPECT_NEAR(gaussian.Pdf(Gaussian2::Vec{1.0, 0.0}), expected, kTolerance);
}

// The density is symmetric about the mean: p(mu + d) = p(mu - d).
TEST(GaussianPdf, SymmetricAboutMean) {
  Gaussian2::Mat covariance;
  covariance << 2.0, 1.0, 1.0, 2.0;
  const Gaussian2::Vec mean{1.0, -1.0};
  const Gaussian2 gaussian(mean, covariance);
  const Gaussian2::Vec offset{0.5, 1.5};

  EXPECT_NEAR(gaussian.Pdf(mean + offset), gaussian.Pdf(mean - offset), kTolerance);
}

}  // namespace
}  // namespace probability
