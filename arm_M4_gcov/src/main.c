//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "libgcov-embedded.h"

int Add(int a, int b)
{
    return a + b;
}

int main()
{
  static_init();

  puts("Hello ARM World!");

  return 0;
}
