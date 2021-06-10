#ifndef GENERIC_STACK
#define GENERIC_STACK
#ifdef TYPE
    #ifndef TYPED
        #define TYPED(x) x
    #endif
    typedef struct TYPED(Stack) TYPED(Stack);

    TYPED(Stack)* TYPED(create_stack) ();

    TYPE TYPED(push) (TYPED(Stack)* stack, TYPE elm);
    TYPE TYPED(pop) (TYPED(Stack)* stack);
    unsigned int TYPED(len) (TYPED(Stack)*);
    void TYPED(delete_stack)(TYPED(Stack)* stack);

    

#endif
#endif
