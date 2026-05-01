//
// Created by QinBu_Rua on 2026/5/1.
//

#ifndef QINBURUA_MATHSOLVER_SRC_INCLUDE_SRC_DETAILS_BIGINT_INL
#define QINBURUA_MATHSOLVER_SRC_INCLUDE_SRC_DETAILS_BIGINT_INL

#include <cassert>

#include "details/Utility.h"

namespace QinBuRua::math_solver::details {

template<typename T> requires (std::is_integral_v<T> && !std::is_same_v<std::remove_cv_t<T>, bool>)
BigInt::BigInt(const T& value) {
   if (value == 0) {
      return;
   }

   constexpr auto sizeT         = sizeof(T);
   constexpr auto sizeContainer = sizeof(std::uint64_t);

   if constexpr (sizeT <= sizeContainer) {
      if constexpr (!std::is_signed_v<T>) {
         _sign = 1;
         _value.push_back(static_cast<std::uint64_t>(value));
      } else {
         _value.push_back(safe_abs(value));
         _sign = value < 0 ? -1 : 1;
      }

   } else {
      constexpr auto bitContainer = sizeContainer * 8;
      constexpr auto loopTimes    = (sizeT + (sizeContainer - 1)) / sizeContainer;

      if constexpr (!std::is_signed_v<T>) {
         _sign = 1;
         _value.resize(loopTimes);
         [&]<std::uint64_t... I>(std::index_sequence<I...>) {
            ((_value[I] = (value >> (I * bitContainer)) & UINT64_MASK), ...);
         }(std::make_index_sequence<loopTimes>());
      } else {
         _sign               = value < 0 ? -1 : 1;
         const auto absValue = safe_abs(value);

         _value.resize(loopTimes);
         [&]<std::uint64_t... I>(std::index_sequence<I...>) {
            ((_value[I] = (absValue >> (I * bitContainer)) & UINT64_MASK), ...);
         }(std::make_index_sequence<loopTimes>());
      }
   }

   assert(IsNormal());
}

}

#endif //QINBURUA_MATHSOLVER_SRC_INCLUDE_SRC_DETAILS_BIGINT_INL
