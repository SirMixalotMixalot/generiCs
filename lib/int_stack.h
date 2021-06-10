#ifndef INT_STACK_H
#undef TYPED 
#undef TYPE
#define TYPED(x) i_ ## x
#define TYPE int
#include "stack.h"
#endif


