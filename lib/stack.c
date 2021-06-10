#include "stack.h"
#include <stddef.h>
#include <stdlib.h>
//---------Private Function declarations------------
void TYPED(resize)(TYPED(Stack)*);

//-----------TYPES--------------
struct TYPED(Stack) {
  TYPE* data;
  unsigned int size;
  int sp;
};

//---Delete
void TYPED(delete_stack) (TYPED(Stack)* s) {
    free(s->data);
    s = NULL;
}

//--New()--
TYPED(Stack)* TYPED(create_stack) () {
    TYPED(Stack)* s = (TYPED(Stack)*)malloc(sizeof(TYPED(Stack))); // Casting without checking is bad!
    s->data = (TYPE*)(malloc(2 * sizeof(TYPE)));
    s->size = 2;
    s->sp = -1;
    return s;
}

//---Impl---
//POP
TYPE TYPED(pop) (TYPED(Stack)* s) {
    if (s->sp < 0) {
        return (TYPE)NULL; // Indicates failure, maybe
    }
    return s->data[s->sp--];
}
//PUSH
TYPE TYPED(push) (TYPED(Stack)* s, TYPE elm) {
    if (s->sp == s->size - 1) {
        TYPED(resize)(s);  
    }
    return (s->data[++s->sp] = elm);
    
}
//len 
unsigned int TYPED(len)(TYPED(Stack)* s) {
    return s->sp + 1;
}
//resize 
void TYPED(resize)(TYPED(Stack)* s) {

    TYPE* new_block = (TYPE*)malloc(s->size * 2 * sizeof(TYPE)); //How I be looking
                                                         //not checking if malloc is null before casting
                                                         //🤡
   for(int i = 0; i <= s->sp; i++) {
        new_block[i] = s->data[i];
   }
   free(s->data);
   s->data = new_block;
   s->size *= 2;
   new_block = NULL;

}

