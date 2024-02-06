

#ifndef MS_LAMS_SRC_LOCALIZATION_PROJECT_MS_LAMS_INCLUDE_EULERANGLESFORROS_H_
#define MS_LAMS_SRC_LOCALIZATION_PROJECT_MS_LAMS_INCLUDE_EULERANGLESFORROS_H_

#include <Eigen/Core>

namespace loc_utils {

/**
 * @brief 从旋转矩阵恢复roll, pitch, yaw
 * 选择pitch角度为[-90, 90],其他为[-180, 180]; 使机器人平面运动时roll, pitch, yaw角变化没有突变
 * @tparam Derived float or double
 * @param coeff 旋转矩阵
 * @return Eigen::Matrix<typename Eigen::MatrixBase<Derived>::Scalar, 3, 1> 0: yaw, 1: pitch, 2: roll
 */
template <typename Derived>
inline Eigen::Matrix<typename Eigen::MatrixBase<Derived>::Scalar, 3, 1> EulerAnglesForROS(
    const Eigen::MatrixBase<Derived>& coeff) {
  EIGEN_USING_STD_MATH(atan2)
  EIGEN_USING_STD_MATH(sin)
  EIGEN_USING_STD_MATH(cos)
  /* Implemented from Graphics Gems IV */
  EIGEN_STATIC_ASSERT_MATRIX_SPECIFIC_SIZE(Derived, 3, 3)
  typedef typename Eigen::MatrixBase<Derived>::Scalar Scalar;
  typedef Eigen::Matrix<Scalar, 2, 1> Vector2;

  Eigen::Matrix<Scalar, 3, 1> res;
  Scalar c2 = Vector2(coeff(2, 2), coeff(2, 1)).norm();
  res[0] = atan2(coeff(1, 0), coeff(0, 0));
  res[1] = atan2(-coeff(2, 0), c2);
  res[2] = atan2(coeff(2, 1), coeff(2, 2));
  return res;
}
}  // namespace loc_utils

#endif  // MS_LAMS_SRC_LOCALIZATION_PROJECT_MS_LAMS_INCLUDE_EULERANGLESFORROS_H_
