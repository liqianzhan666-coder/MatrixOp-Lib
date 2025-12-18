#include "matrix_op.h"


void print_matrix(Matrix3x3 m) {
    int i, j;  
    for(i = 0; i < SIZE; i++) {
        printf("| ");
        for(j = 0; j < SIZE; j++) {
            printf("%.2f ", m.data[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}


Matrix3x3 add(Matrix3x3 a, Matrix3x3 b) {
    Matrix3x3 result;
    int i, j;  
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}


Matrix3x3 sub(Matrix3x3 a, Matrix3x3 b) {
    Matrix3x3 result;
    int i, j;  
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return result;
}


Matrix3x3 element_mult(Matrix3x3 a, Matrix3x3 b) {
    Matrix3x3 result;
    int i, j;  
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            result.data[i][j] = a.data[i][j] * b.data[i][j];
        }
    }
    return result;
}
