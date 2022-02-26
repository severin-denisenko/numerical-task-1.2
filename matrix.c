//
// Created by Severin on 19.02.2022.
//

#include "matrix.h"
#include "stdio.h"


int diagonal_3_multiply(double *A, double *B, double *C, int n){

    C[0] = A[0] * B[0] + A[1] * B[1];
    C[1] = A[0] * B[1] + A[1] * B[3];
    C[2] = A[1] * B[4];

    C[3] = A[2] * B[0] + A[3] * B[2];
    C[4] = A[2] * B[1] + A[3] * B[3] + A[4] * B[5];
    C[5] = A[3] * B[4] + A[4] * B[6];
    C[6] = A[4] * B[7];

    for (int i = 7; i < 5*n-13; i+=5) {
        C[i] = 
    }

    C[5*n-13] = A[3*n-7] * B[3*n-10];
    C[5*n-12] = A[3*n-7] * B[3*n-9] + A[3*n-6] * B[3*n-7];
    C[5*n-11] = A[3*n-7] * B[3*n-8] + A[3*n-6] * B[3*n-6] + A[3*n-5] * B[3*n-4];
    C[5*n-10] = A[3*n-6] * B[3*n-4] + A[3*n-5] * B[3*n-3];

    C[5*n-9] = A[3*n-4] * B[3*n-7];
    C[5*n-8] = A[3*n-4] * B[3*n-6] + A[3*n-3] * B[3*n-4];
    C[5*n-7] = A[3*n-4] * B[3*n-5] + A[3*n-3] * B[3*n-3];

    return 0;
}

// Элементарнейшее умножение по определению с оптимизациями
// Упрощаем вычисление указателя и вместо обхода по строчкам и столбцам, реализуем обход по строчкм
// якобы первая матрица транспонирована.

int optimised_stupid_multiply(double *A, double *B, double *C, int n){

    for (int i = 0; i < n; ++i)
    {
        double *c = C + i * n;

        for (int j = 0; j < n; ++j){
            c[j] = 0;
        }

        for (int k = 0; k < n; ++k)
        {
            const double *b = B + k * n;
            float a = A[i*n + k];

            for (int j = 0; j < n; ++j) {
                c[j] += a * b[j];
            }
        }
    }

    return 0;
}
