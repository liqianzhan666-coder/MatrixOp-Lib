#include <stdio.h>
#include "matrix_op.h"

int main() {
    
    Matrix3x3 m1 = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix3x3 m2 = {{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}}};

    printf("Matrix 1:\n");
    print_matrix(m1);
    
    printf("Matrix 2:\n");
    print_matrix(m2);

    printf("--- Test: Addition ---\n");
    Matrix3x3 sum = add(m1, m2);
    print_matrix(sum);

    printf("--- Test: Subtraction ---\n");
    Matrix3x3 diff = sub(m1, m2);
    print_matrix(diff);

    printf("--- Test: Element-wise Multiplication ---\n");
    Matrix3x3 emult = element_mult(m1, m2);
    print_matrix(emult);

    return 0;
}
