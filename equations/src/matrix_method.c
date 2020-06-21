/*
    File which solves the equations by matrix method
*/
#include <stdio.h>
#include "simultaneous_equation.h"


void printMatrix(int row, int col, double matrix[row][col]){
    /*
        prints the matrix
    */
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%0.2lf ", matrix[i][j]);
        }
        NEWLINE;
    }
    NEWLINE;
}



void invertMatrix(int row, int col, double matrix[row][col]){
    /*
        returns the inverted matrix
    */
    double det = ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));

    printf("Matrix Determinant : %0.2lf\n", det);
    NEWLINE;
    swap(&matrix[0][0], &matrix[1][1], DOUBLE);
    matrix[0][1] = -matrix[0][1];
    matrix[1][0] = -matrix[1][0];

    for(int i = 0; i < NUMBER_OF_EQUATIONS; i++){
        for(int j = 0; j < NUMBER_OF_EQUATIONS; j++){
            matrix[i][j] = (1/det)*matrix[i][j];
        }
    }
    printf("Inverse of a matrix\n");
    NEWLINE;
    printMatrix(2, 2, matrix);
}

void multiplyMatrix(int col1, double matrixA[][col1], int col2, double matrixB[][col2], double res[][col2]){
    /*
        multiplies and returns the resultant matrix
    */
    int i, j, k; 
    for (i = 0; i < 2; i++) { 
        for (j = 0; j < 1; j++){ 
            res[i][j] = 0; 
            for (k = 0; k < 2; k++) 
                res[i][j] += (matrixA[i][k] *  
                             matrixB[k][j]); 
        } 
    }
}

void solveEquationsByMatrix(int col1, double matrixA[][col1], int col2, double matrixB[][col2], double res[][col2]){
    /*
        solves the equations by the substituion method.
    */
    invertMatrix(2, 2, matrixA);
    NEWLINE;
    multiplyMatrix(2, matrixA, 1, matrixB, res);
}