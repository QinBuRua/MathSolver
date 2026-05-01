//
// Created by QinBu_Rua on 2026/5/1.
//

#ifndef QINBURUA_MATHSOLVER_SRC_INCLUDE_SRC_DETAILS_UTILITY_INL
#define QINBURUA_MATHSOLVER_SRC_INCLUDE_SRC_DETAILS_UTILITY_INL

namespace QinBuRua::math_solver::details {

template<typename T> requires (std::is_integral_v<T> && !std::is_same_v<std::remove_cv_t<T>, bool>)
std::make_unsigned_t<T> safe_abs(const T& value) {
   using UnsignedT = std::make_unsigned_t<T>;

   if constexpr (!std::is_signed_v<T>) {
      return value;
   } else {
      return value < 0 ? -static_cast<UnsignedT>(value) : static_cast<UnsignedT>(value);
   }
}

}

#endif //QINBURUA_MATHSOLVER_SRC_INCLUDE_SRC_DETAILS_UTILITY_INL
