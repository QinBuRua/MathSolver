//
// Created by QinBu_Rua on 2026/4/25.
//

#ifndef QINBURUA_MATHSOLVER_INCLUDES_DETAILS_BIGNUMBER_BIGINT_H
#define QINBURUA_MATHSOLVER_INCLUDES_DETAILS_BIGNUMBER_BIGINT_H

#include <cstdint>
#include <vector>

namespace QinBuRua::math_solver::details {

class BigInt final {
public:
   using AbsValueType = std::vector<std::uint64_t>;
   using SignType     = std::int8_t;

public:
   BigInt()                  = default;
   BigInt(BigInt&&) noexcept = default;
   BigInt(const BigInt&)     = default;

   BigInt& operator=(BigInt&&) noexcept = default;
   BigInt& operator=(const BigInt&)     = default;

   BigInt& operator+=(const BigInt&);

   [[nodiscard]] bool Positive() const;
   [[nodiscard]] bool Negative() const;
   [[nodiscard]] bool IsZero() const;

   std::strong_ordering operator<=>(const BigInt& other) const noexcept;

   friend BigInt operator+(const BigInt& a, const BigInt& b);

private:
   SignType _sign = 1;
   AbsValueType _value{};

   [[nodiscard]] bool IsNormal() const;
   void Normalize();

   void AbsSelfAdd(const BigInt& other);

};

BigInt operator+(const BigInt& a, const BigInt& b);

}

#endif //QINBURUA_MATHSOLVER_INCLUDES_DETAILS_BIGNUMBER_BIGINT_H
