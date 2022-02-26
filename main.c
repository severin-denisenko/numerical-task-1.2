//
// Created by Severin on 19.02.2022.
//

#include "stdio.h"
#include "stdlib.h"

#include "matrix.h"

int main(){

    //////////////////
    /// File staff ///
    //////////////////

    // Creating and opening files

    FILE *A, *B, *C;
    A = fopen("data1.dat", "r");
    B = fopen("data2.dat", "r");
    C = fopen("result.dat", "w+");

    if (A == NULL){
        printf("Error: file data1.dat doesn't exist.");
        exit(1);
    }

    if (B == NULL){
        printf("Error: file data2.dat doesn't exist.");
        exit(1);
    }

    // Checking for right formatting

    char a = getc(A);
    char b = getc(B);

    if(a != '#'){
        printf("Error: file data1.dat in wrong format.");
        exit(1);
    }

    if(b != '#'){
        printf("Error: file data2.dat in wrong format.");
        exit(1);
    }

    // Checking for same size

    int n_a, n_b, n;

    fscanf(A, "%d", &n_a);
    fscanf(B, "%d", &n_b);

    if (n_a != n_b){
        printf("Error: file matrices from data1.dat and data2.dat are not multiplicable");
    } else {
        n = n_a;
    }

    if (n < 5) {
        printf("Error: matrices are too small");
    }

    // Allocating memory for matrices

    double *matrix_A = malloc(sizeof(double) * (n * 3 - 2));
    double *matrix_B = malloc(sizeof(double) * (n * 3 - 2));
    double *matrix_C = malloc(sizeof(double) * (n * 5 - 6));

    if (matrix_A == NULL){
        printf("Error reallocating space for matrix A.");
        exit(1);
    }

    if (matrix_B == NULL){
        printf("Error reallocating space for matrix B.");
        exit(1);
    }

    if (matrix_C == NULL){
        printf("Error reallocating space for matrix C.");
        exit(1);
    }

    // Finally reading

    for (int i = 0; i < n * 3 - 2; ++i) {
        fscanf(A, "%lf", &matrix_A[i]);
        fscanf(B, "%lf", &matrix_B[i]);
    }

    ///////////////////
    /// Multiplying ///
    ///////////////////

    if(optimised_diagonal_3_multiply(matrix_A, matrix_B, matrix_C, n) == 1){
        printf("Error occur during multiplication. Exiting...");
        exit(1);
    }

    ///////////////////////
    /// More file staff ///
    ///////////////////////

    fprintf(C, "# %d", n);

    fprintf(C, "\n");

    fprintf(C, "%lf ", matrix_C[0]);
    fprintf(C, "%lf ", matrix_C[1]);
    fprintf(C, "%lf ", matrix_C[2]);

    fprintf(C, "\n");

    fprintf(C, "%lf ", matrix_C[3]);
    fprintf(C, "%lf ", matrix_C[4]);
    fprintf(C, "%lf ", matrix_C[5]);
    fprintf(C, "%lf ", matrix_C[6]);

    fprintf(C, "\n");

    for (int i = 3; i < n - 1; ++i) {
        double *c = matrix_C + 5*i;

        fprintf(C, "%lf %lf %lf %lf %lf ", c[-8], c[-7], c[-6], c[-5], c[-4]);
        fprintf(C, "\n");
    }

    fprintf(C, "%lf ", matrix_C[5 * n - 13]);
    fprintf(C, "%lf ", matrix_C[5 * n - 12]);
    fprintf(C, "%lf ", matrix_C[5 * n - 11]);
    fprintf(C, "%lf ", matrix_C[5 * n - 10]);

    fprintf(C, "\n");

    fprintf(C, "%lf ", matrix_C[5 * n - 9]);
    fprintf(C, "%lf ", matrix_C[5 * n - 8]);
    fprintf(C, "%lf ", matrix_C[5 * n - 7]);


    fclose(A);
    fclose(B);
    fclose(C);

    return 0;
}
