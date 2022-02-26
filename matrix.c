//
// Created by Severin on 19.02.2022.
//

#include "matrix.h"
#include "stdio.h"


int diagonal_3_multiply(double *A, double *B, double *C, int n){

    // For first row

    C[0] = A[0] * B[0] + A[1] * B[1];
    C[1] = A[0] * B[1] + A[1] * B[3];
    C[2] = A[1] * B[4];

    // For second row

    C[3] = A[2] * B[0] + A[3] * B[2];
    C[4] = A[2] * B[1] + A[3] * B[3] + A[4] * B[5];
    C[5] = A[3] * B[4] + A[4] * B[6];
    C[6] = A[4] * B[7];

    // For others rows

    for (int i = 3; i < n-1; i+=5) {
        C[5*i-8] = A[3*i-4] * B[3*i-7];
        C[5*i-7] = A[3*i-4] * B[3*i-6] + A[3*i-3] * B[3*i-4];
        C[5*i-6] = A[3*i-4] * B[3*i-5] + A[3*i-3] * B[3*i-3] + A[3*i-2] * B[3*i-1];
        C[5*i-5] = A[3*i-3] * B[3*i-2] + A[3*i-2] * B[3*i];
        C[5*i-4] = A[3*i-2] * B[3*i+1];
    }

    // For pre-last row

    C[5*n-13] = A[3*n-7] * B[3*n-10];
    C[5*n-12] = A[3*n-7] * B[3*n-9] + A[3*n-6] * B[3*n-7];
    C[5*n-11] = A[3*n-7] * B[3*n-8] + A[3*n-6] * B[3*n-6] + A[3*n-5] * B[3*n-4];
    C[5*n-10] = A[3*n-6] * B[3*n-4] + A[3*n-5] * B[3*n-3];

    // For last row

    C[5*n-9] = A[3*n-4] * B[3*n-7];
    C[5*n-8] = A[3*n-4] * B[3*n-6] + A[3*n-3] * B[3*n-4];
    C[5*n-7] = A[3*n-4] * B[3*n-5] + A[3*n-3] * B[3*n-3];

    return 0;
}

int optimised_diagonal_3_multiply(double *A, double *B, double *C, int n){

    // For first row

    C[0] = A[0] * B[0] + A[1] * B[1];
    C[1] = A[0] * B[1] + A[1] * B[3];
    C[2] = A[1] * B[4];

    // For second row

    C[3] = A[2] * B[0] + A[3] * B[2];
    C[4] = A[2] * B[1] + A[3] * B[3] + A[4] * B[5];
    C[5] = A[3] * B[4] + A[4] * B[6];
    C[6] = A[4] * B[7];

    // For others rows

    for (int i = 3; i < n-1; ++i) {
        double *a = A + 3*i;
        double *b = B + 3*i;
        double *c = C + 5*i;

        c[-8] = a[-4] * b[-7];
        c[-7] = a[-4] * b[-6] + a[-3] * b[-4];
        c[-6] = a[-4] * b[-5] + a[-3] * b[-3] + a[-2] * b[-1];
        c[-5] = a[-3] * b[-2] + a[-2] * b[0];
        c[-4] = a[-2] * b[1];
    }

    double *a = A + 3*n - 3;
    double *b = B + 3*n - 3;
    double *c = C + 5*n - 7;

    // For pre-last row

    c[-6] = a[-4] * b[-7];
    c[-5] = a[-4] * b[-6] + a[-3] * b[-4];
    c[-4] = a[-4] * b[-5] + a[-3] * b[-3] + a[-2] * b[-1];
    c[-3] = a[-3] * b[-1] + a[-2] * b[0];

    // For last row

    c[-2] = a[-1] * b[-4];
    c[-1] = a[-1] * b[-3] + a[0] * b[-1];
    c[0] = a[-1] * b[-2] + a[0] * b[0];

    return 0;
}
