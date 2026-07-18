#include "src/common/types.hpp"

#include <gtest/gtest.h>

namespace sketchbook {
namespace {

// A deliberately trivial test. Its job is to prove the toolchain, the Eigen
// dependency, and the GoogleTest wiring all work before any real math lands.
TEST(Types, VectorAliasesHaveExpectedDimensions) {
  EXPECT_EQ(Vector3::RowsAtCompileTime, 3);
  EXPECT_EQ(Matrix3::RowsAtCompileTime, 3);
  EXPECT_EQ(Matrix3::ColsAtCompileTime, 3);
}

TEST(Types, IdentityRoundTripsThroughQuaternion) {
  const Quaternion q = Quaternion::Identity();
  const Matrix3 R = q.toRotationMatrix();
  EXPECT_TRUE(R.isApprox(Matrix3::Identity()));
}

}  // namespace
}  // namespace sketchbook
