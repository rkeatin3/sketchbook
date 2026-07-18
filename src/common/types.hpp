#pragma once

/// \file types.hpp
/// \brief Shared numeric type aliases used across sketchbook.
///
/// Everything in this repository speaks Eigen. Fixing the scalar type and the
/// common vector/matrix shapes in one place keeps signatures short and makes a
/// future switch to `float` or an autodiff scalar a single-file change.

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace sketchbook {

/// Default scalar type for the repository.
using Scalar = double;

template <int Rows>
using Vector = Eigen::Matrix<Scalar, Rows, 1>;

template <int Rows, int Cols>
using Matrix = Eigen::Matrix<Scalar, Rows, Cols>;

using Vector2 = Vector<2>;
using Vector3 = Vector<3>;
using Vector4 = Vector<4>;
using VectorX = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>;

using Matrix2 = Matrix<2, 2>;
using Matrix3 = Matrix<3, 3>;
using Matrix4 = Matrix<4, 4>;
using MatrixX = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>;

using Quaternion = Eigen::Quaternion<Scalar>;

/// Machine-epsilon-scaled tolerance for approximate comparisons.
inline constexpr Scalar kEpsilon = Scalar(1e-12);

}  // namespace sketchbook
