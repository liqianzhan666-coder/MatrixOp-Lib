#include <stdio.h>
#include "matrix_op.h"

int main() {
   
    Matrix3x3 m1 = {{{1, 2, 3}, {0, 1, 4}, {5, 6, 0}}};
    
    printf("Original Matrix:\n");
    print_matrix(m1);

    printf("--- Test: Inverse Matrix ---\n");
    Matrix3x3 inv = inverse(m1);
    print_matrix(inv);

    printf("--- Verification: Matrix * Inverse (Should be Identity Matrix) ---\n");
    Matrix3x3 identity = multiply(m1, inv);
    print_matrix(identity);

    return 0;
}
