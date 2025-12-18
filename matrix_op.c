#include "matrix_op.h"

// 1. 印出矩陣
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

// 2. 加法
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

// 3. 減法
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

// 4. 元素相乘
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

// 5. 矩陣乘法 (Linear)
Matrix3x3 multiply(Matrix3x3 a, Matrix3x3 b) {
    Matrix3x3 result;
    int i, j, k;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
            for(k = 0; k < SIZE; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

// 6. 轉置 (Linear)
Matrix3x3 transpose(Matrix3x3 a) {
    Matrix3x3 result;
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            result.data[j][i] = a.data[i][j];
        }
    }
    return result;
}

// 7. 行列式 (Advanced)
float determinant(Matrix3x3 m) {
    return m.data[0][0]*(m.data[1][1]*m.data[2][2] - m.data[1][2]*m.data[2][1])
         - m.data[0][1]*(m.data[1][0]*m.data[2][2] - m.data[1][2]*m.data[2][0])
         + m.data[0][2]*(m.data[1][0]*m.data[2][1] - m.data[1][1]*m.data[2][0]);
}

// 8. 伴隨矩陣 (Advanced)
Matrix3x3 adjoint(Matrix3x3 m) {
    Matrix3x3 adj;
    adj.data[0][0] =  (m.data[1][1]*m.data[2][2] - m.data[1][2]*m.data[2][1]);
    adj.data[0][1] = -(m.data[0][1]*m.data[2][2] - m.data[0][2]*m.data[2][1]);
    adj.data[0][2] =  (m.data[0][1]*m.data[1][2] - m.data[0][2]*m.data[1][1]);
    adj.data[1][0] = -(m.data[1][0]*m.data[2][2] - m.data[1][2]*m.data[2][0]);
    adj.data[1][1] =  (m.data[0][0]*m.data[2][2] - m.data[0][2]*m.data[2][0]);
    adj.data[1][2] = -(m.data[0][0]*m.data[1][2] - m.data[0][2]*m.data[1][0]);
    adj.data[2][0] =  (m.data[1][0]*m.data[2][1] - m.data[1][1]*m.data[2][0]);
    adj.data[2][1] = -(m.data[0][0]*m.data[2][1] - m.data[0][1]*m.data[2][0]);
    adj.data[2][2] =  (m.data[0][0]*m.data[1][1] - m.data[0][1]*m.data[1][0]);
    return adj;
}

// 9. 反矩陣 (Advanced)
Matrix3x3 inverse(Matrix3x3 m) {
    Matrix3x3 inv;
    float det = determinant(m);
    Matrix3x3 adj = adjoint(m);
    int i, j;
    if(det == 0) {
        printf("Det is 0, no inverse!\n");
        return m;
    }
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            inv.data[i][j] = adj.data[i][j] / det;
        }
    }
    return inv;
}
