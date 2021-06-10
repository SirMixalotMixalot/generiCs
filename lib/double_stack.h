#ifndef DOUBLE_STACK_H
    #define DOUBLE_STACK_H
    #undef TYPE //Making sure we define type 
    #undef TYPED 
    #define TYPE double
    #define TYPED(ident) d_ ## ident
    #include "stack.h"
    
    
#endif
