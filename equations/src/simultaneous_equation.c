/*
    This code solves the simulatenous equations
    Author : Manish Soni
*/

#include<stdio.h>
#include "simultaneous_equation.h"

int main(){
    
    /*
        Main function.
    */
    LINEAREQUATION equations[2];
    double matrixA[2][2], matrixB[2][1], res[2][1];

    getConstantForEquations(equations, matrixA, matrixB);
    
    short int numSolutions = checkNumberOfSolutions(equations);

    if(numSolutions == UNIQUE_SOLUTION){
        solveEquationsBySubstitution(equations);
        solveEquationsByMatrix(2, matrixA, 1, matrixB, res);
        
        if(compareResults(res, equations)){
            printf("Both Methods rightly implemented\n");
        } else {
            printf("Wrong Implementation\n");
        }
        plotGraph(equations, UNIQUE_SOLUTION);
        printf("The given system of equations has unique solutions");
    } else if(numSolutions == INFINITE_SOLUTIONS){
        printf("The given system of equations has infinite solutions");
        plotGraph(equations, INFINITE_SOLUTIONS);
    } else {
        printf("Given lines are parallel lines\n");
        NEWLINE;
        printf("The given system of equations has no solutions");
    }
    
    return 0;
}