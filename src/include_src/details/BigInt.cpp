//
// Created by QinBu_Rua on 2026/4/25.
//

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <ranges>
#include <stdckdint.h>

#include "details/BigInt.h"

using namespace QinBuRua::math_solver::details;

namespace stdv = std::views;
namespace stdr = std::ranges;

BigInt::BigInt(const bool& bool_value) {
   if (bool_value != false) {
      _sign = 1;
      _value.push_back(1);
   }

   assert(IsNormal());
}

BigInt& BigInt::operator+=(const BigInt& other) {
   if (_sign == other._sign) {
      AbsSelfAdd(other);
      return *this;
   }

   assert("Incomplete function!!!");
   return *this;
}

bool BigInt::Positive() const {
   return _sign > 0;
}

bool BigInt::Negative() const {
   return _sign < 0;
}

bool BigInt::IsZero() const {
   return _sign == 0;
}

std::strong_ordering BigInt::operator<=>(const BigInt& other) const noexcept {
   assert(IsNormal());

   if (_sign != other._sign) {
      return _sign <=> other._sign;
   }

   auto selfRange  = _value | stdv::reverse;
   auto otherRange = other._value | stdv::reverse;

   const auto absCompared = std::lexicographical_compare_three_way(
      selfRange.begin(), selfRange.end(),
      otherRange.begin(), otherRange.end()
   );

   return _sign == -1
             ? (0 <=> absCompared)
             : absCompared;
}

BigInt QinBuRua::math_solver::details::operator+(const BigInt& a, const BigInt& b) {
   assert(a.IsNormal());
   assert(b.IsNormal());

   if (a.IsZero()) {
      return b;
   }
   if (b.IsZero()) {
      return a;
   }

   if (a._sign == b._sign) {

   }
   assert("Incomplete function!!!");
   return BigInt{};
}

bool BigInt::IsNormal() const {
   if (_value.empty()) {
      return _sign == 0;
   }
   if (_value.back() == 0) {
      return false;
   }
   if (_sign == -1 || _sign == 1) {
      return true;
   }
   return false;
}

void BigInt::Normalize() {
   while (!_value.empty() && _value.back() == 0) {
      _value.pop_back();
   }
   if (_value.empty()) {
      _sign = 0;
   }

   assert(IsNormal());
}

void BigInt::AbsSelfAdd(const BigInt& other) {
   const auto newSize = std::max(_value.size(), other._value.size()) + 1;
   _value.resize(newSize);

   std::uint8_t addNum = 0;
   auto zipped         = stdv::zip(_value, other._value);
   for (auto&& [self, other_] : zipped) {
      if (ckd_add(&self, self, addNum)) {
         addNum = 1;
         self   = other_;
         continue;
      }

      addNum = ckd_add(&self, self, other_);
   }


   if (addNum == 0) {
      Normalize();
      return;
   }

   auto valueRest = _value | stdv::drop(zipped.size());
   stdr::all_of(
      valueRest,
      [](auto&& self) {
         return ckd_add(&self, self, 1);
      });

   Normalize();
}
