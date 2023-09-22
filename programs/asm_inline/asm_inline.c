//#include <stdio.h>

#ifdef _GEM5_
#include <gem5/m5ops.h>
#endif /*_GEM5_*/

int main() {
    int x = 5;
    int y = 10;
    int result;


#if _GEM5_
 m5_work_begin(1,1);   
#endif /*_GEM5_*/

    // Inline RISC-V assembly
    asm volatile (
        "add %0, %1, %2\n\t"
        : "=r" (result) // Output operand
        : "r" (x), "r" (y) // Input operands
    );

    //printf("Result: %d\n", result);
#ifdef _GEM5_
    m5_work_end(1,1);
#endif /*_GEM5_*/
    return 0;
}





























