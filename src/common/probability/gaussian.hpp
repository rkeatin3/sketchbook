// Multivariate Gaussian. Articles: src/common/probability/README.md

#pragma once

#include <random>

#include <Eigen/Core>

namespace probability {

template <int N>
class Gaussian {
 public:
  using Vec = Eigen::Vector<double, N>;
  using Mat = Eigen::Matrix<double, N, N>;

  Gaussian(const Vec& mean, const Mat& covariance) : mean_(mean), covariance_(covariance) {}

  template <std::uniform_random_bit_generator Gen>
  Vec Sample(Gen& rng) const {
    return Vec{};
  }

  const Vec& Mean() const { return mean_; }

  const Mat& Covariance() const { return covariance_; }

 private:
  Vec mean_;
  Mat covariance_;
};

}  // namespace probability
