// Multivariate Gaussian N(mu, Sigma) with a compile-time dimension.
//
// Articles (src/math/probability/docs/):
//   multivariate_gaussian.md   definition, density, the PSD invariant
//   random_vector_moments.md   mean and covariance, sample estimates
//   gaussian_mle.md            why Fit is the best Gaussian fit
//   sampling.md                drawing samples
// Plan: src/math/probability/docs/plan.md

#pragma once

#include <cmath>
#include <cstddef>
#include <format>
#include <numbers>
#include <ostream>
#include <random>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <Eigen/Dense>

namespace probability {

template <int N>
  requires(N > 0)
class Gaussian {
 public:
  using Vec = Eigen::Vector<double, N>;
  using Mat = Eigen::Matrix<double, N, N>;
  static constexpr size_t kDim = N;

  // Throws if the covariance isn't a valid covariance matrix.
  // See multivariate_gaussian.md.
  Gaussian(const Vec& mean, const Mat& covariance) : mean_(mean), covariance_(covariance) {
    if (Eigen::LLT<Mat>(covariance_).info() != Eigen::Success) {
      throw std::runtime_error("Covariance matrix is not PSD!");
    }
  }

  // One draw from N(mu, Sigma). See sampling.md.
  template <std::uniform_random_bit_generator Gen>
  Vec Sample(Gen& rng) const {
    Eigen::LLT<Mat> cholesky_res(covariance_);
    std::normal_distribution<double> dist(0.0, 1.0);
    const Vec z = Vec::NullaryExpr([&]() { return dist(rng); });
    return mean_ + cholesky_res.matrixL() * z;
  }

  // n independent draws from N(mu, Sigma), in the same way as Sample. Sigma is
  // factored once for the whole batch. See sampling.md.
  template <std::uniform_random_bit_generator Gen>
  std::vector<Vec> SampleN(Gen& rng, std::size_t n) const {
    const Eigen::LLT<Mat> cholesky(covariance_);
    std::normal_distribution<double> standard_normal(0.0, 1.0);

    std::vector<Vec> samples;
    samples.reserve(n);
    for (std::size_t i = 0; i < n; ++i) {
      const Vec z = Vec::NullaryExpr([&] { return standard_normal(rng); });
      samples.push_back(mean_ + (cholesky.matrixL() * z));
    }
    return samples;
  }

  // The sample mean and the unbiased sample covariance. These are also the
  // maximum-likelihood mean and, up to the divisor, covariance.
  // See random_vector_moments.md and gaussian_mle.md.
  static Gaussian<N> Fit(std::span<const Vec> samples) {
    Vec mean = Vec::Zero();
    for (const auto& x : samples) {
      mean += x;
    }
    mean /= samples.size();

    Mat cov = Mat::Zero();
    for (const auto& x : samples) {
      const Vec diff = x - mean;
      cov += diff * diff.transpose();
    }
    cov /= (samples.size() - 1.0);
    return Gaussian{mean, cov};
  }

  // The density p(x) = N(x; mu, Sigma). See multivariate_gaussian.md.
  double Pdf(const Vec& x) const {
    const Vec diff = x - mean_;
    using std::numbers::pi;
    return std::exp(-0.5 * (diff.transpose() * covariance_.inverse() * diff).value()) /
           std::sqrt(std::pow(2 * pi, N) * covariance_.determinant());
  }

  const Vec& Mean() const { return mean_; }

  const Mat& Covariance() const { return covariance_; }

 private:
  Vec mean_;
  Mat covariance_;
};

// Prints as "N(mean=[1, -2], cov=[[2, 0.5], [0.5, 1]])", using the stream's
// precision. googletest uses this for failure messages too.
template <int N>
std::ostream& operator<<(std::ostream& os, const Gaussian<N>& gaussian) {
  // IOFormat(precision, flags, coeffSeparator, rowSeparator, rowPrefix,
  //          rowSuffix, matPrefix, matSuffix)
  const Eigen::IOFormat vector_format(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", ", ", "",
                                      "", "[", "]");
  const Eigen::IOFormat matrix_format(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", ", ", "[",
                                      "]", "[", "]");
  return os << "N(mean=" << gaussian.Mean().format(vector_format)
            << ", cov=" << gaussian.Covariance().format(matrix_format) << ")";
}

}  // namespace probability

// std::format support through operator<<. Inheriting the string formatter
// accepts its specs, e.g. "{:>60}" to pad.
template <int N>
struct std::formatter<probability::Gaussian<N>> : std::formatter<std::string> {
  // The name is the interface std::format requires.
  auto format(const probability::Gaussian<N>& gaussian,  // NOLINT(readability-identifier-naming)
              std::format_context& ctx) const {
    std::ostringstream os;
    os << gaussian;
    return std::formatter<std::string>::format(os.str(), ctx);
  }
};
