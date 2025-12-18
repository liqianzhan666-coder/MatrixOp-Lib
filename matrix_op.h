#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#include <stdio.h>

#define SIZE 3

typedef struct {
    float data[SIZE][SIZE];
} Matrix3x3;


void print_matrix(Matrix3x3 m);
Matrix3x3 add(Matrix3x3 a, Matrix3x3 b);
Matrix3x3 sub(Matrix3x3 a, Matrix3x3 b);
Matrix3x3 element_mult(Matrix3x3 a, Matrix3x3 b);


Matrix3x3 multiply(Matrix3x3 a, Matrix3x3 b);
Matrix3x3 transpose(Matrix3x3 a);


float determinant(Matrix3x3 m);
Matrix3x3 adjoint(Matrix3x3 m);
Matrix3x3 inverse(Matrix3x3 m);

#endif
