#include "../lib/int_stack.h"
#include <stdio.h>
int main() {
    i_Stack* s = i_create_stack();
    for(int i = 'L'; i < 'O'; i ++) {
        i_push(s,i);
    }
    for(int i = 'L'; i < 'O'; i++) {
        putc(i_pop(s),stdout);
    }


}
