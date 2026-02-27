// Copyright 2022 NNTU-CS
#include <cmath>
#include <cstdint>

bool checkPrime(uint64_t value) {
  for (uint64_t i = 2; i <= sqrt(value); i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int m = 0;
  for (uint64_t i = 2; i <= 1000; i++) {
    if (checkPrime(i)) {
      m += 1;
      if (m == n) {
        return i;
      }
    }
  }
  return 2;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t i = value + 1;
  for (int p = 1; p <= 100; p++) {
    if (checkPrime(i)) {
      return i;
    }
    i += 1;
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (int i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t start = (lbound > 2) ? lbound : 2;
  for (uint64_t i = start; i < hbound; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count += 1;
    }
  }
  return count;
}
