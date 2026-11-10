// Toolchain smoke test: proves Bazel, Eigen, GoogleTest, and C++23 are wired
// up, so CI has a target to build and run. Delete once real tests exist.

#include <expected>

#include <Eigen/Core>

#include <gtest/gtest.h>

namespace sketchbook {
namespace {

TEST(Toolchain, EigenLinksAndComputes) {
  const Eigen::Matrix3d identity = Eigen::Matrix3d::Identity();
  EXPECT_TRUE((identity * identity).isApprox(identity));
}

TEST(Toolchain, Cpp23LibraryIsAvailable) {
  const std::expected<int, const char*> value = 42;
  ASSERT_TRUE(value.has_value());
  EXPECT_EQ(*value, 42);
}

}  // namespace
}  // namespace sketchbook
