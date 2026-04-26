//
// Created by QinBu_Rua on 2026/4/25.
//

#ifndef QINBURUA_MATHSOLVER_INCLUDES_DETAILS_REALNUMBER_H
#define QINBURUA_MATHSOLVER_INCLUDES_DETAILS_REALNUMBER_H

#include <cstdint>
#include <stdfloat>
#include <variant>

#include "BigFixed.h"
#include "BigInt.h"

namespace QinBuRua::math_solver {

class RealNumber {
public:
   using NumberValue = std::variant<
      std::int8_t, std::int16_t, std::int32_t, std::int64_t,
      std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t,
      std::float16_t, std::float32_t, std::float64_t, std::float128_t,
      details::BigInt, details::BigFixed
   >;

public:
   RealNumber();
   template<typename T>
   explicit RealNumber(T val);

   ~RealNumber() = default;

private:
   NumberValue _value;

};

#include "../../src/include_src/details/RealNumber.inl"

}

#endif //QINBURUA_MATHSOLVER_INCLUDES_DETAILS_REALNUMBER_H
