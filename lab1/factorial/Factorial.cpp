//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
  if (value < -12 || value > 12)
      return 0;
    else if(value == 0)
      return 1;
    else if (value > 0)
      return value * factorial(value - 1);
    else
      return value * factorial(value + 1);
}
