//
// Created by QinBu_Rua on 2026/5/1.
//

#ifndef QINBURUA_MATHSOLVER_INCLUDES_DETAILS_UTILITY_H
#define QINBURUA_MATHSOLVER_INCLUDES_DETAILS_UTILITY_H

namespace QinBuRua::math_solver::details {

template<typename T>
   requires (std::is_integral_v<T> && !std::is_same_v<std::remove_cv_t<T>, bool>)
std::make_unsigned_t<T> safe_abs(const T& value);

}

#include "../../src/include_src/details/Utility.inl"

#endif //QINBURUA_MATHSOLVER_INCLUDES_DETAILS_UTILITY_H
