#include "src/common/probability/gaussian.hpp"

#include <random>

#include <gtest/gtest.h>

namespace probability {
namespace {

using Gaussian2 = Gaussian<2>;

// Placeholder: instantiates Gaussian<2> so the header is compiled. Replace
// with real tests as the class gains behavior.
TEST(Gaussian, Instantiates) {
  const Gaussian2 gaussian(Gaussian2::Vec::Zero(), Gaussian2::Mat::Identity());
  std::mt19937_64 rng(0);

  EXPECT_EQ(gaussian.Sample(rng).rows(), 2);
}

}  // namespace
}  // namespace probability
