#include <stdio.h>
#include "simultaneous_equation.h"

void getConstantForEquations(LINEAREQUATION *equations, double matrixA[][2], double matrixB[][1]){
    /*
        Takes the constant and assigns to respective equations
    */
    
    printf("Enter Constants values for the equations\n");
    for(int i = 0; i < NUMBER_OF_EQUATIONS; i++){
        NEWLINE;
        printf("Enter a for %d equation : ", (i + 1));
        scanf("%lf", &equations[i].a);
        printf("Enter b for %d equation : ", (i + 1));
        scanf("%lf", &equations[i].b);
        printf("Enter c for %d equation : ", (i + 1));
        scanf("%lf", &equations[i].c);
        equations[i].x = 0;
        equations[i].y = 0;
        NEWLINE;
    }
    for(int i = 0; i < NUMBER_OF_EQUATIONS; i++){
        matrixA[i][0] = equations[i].a;
        matrixA[i][1] = equations[i].b;
        matrixB[i][0] = equations[i].c;
    }
}

int checkParallelLines(LINEAREQUATION *equations){
    /*
        Two lines are parallel if the slopes of the equations are same.
        To get slope of a equation of format : ax + by = c
        Formula : -a/b
        For lines to be parallel : -a1/b1 = -a2/b2
        Here a1, b1 are from equation 1 and a2, b2, are from equation 2
    */
    double slope1 = -(equations[0].a/equations[0].b);
    double slope2 = -(equations[1].a/equations[1].b);
    if (slope1 == slope2)
        return 1;
    return 0;
}

int checkInfiniteSolutions(LINEAREQUATION *equations){
    /*
        Two equations have infinite solutions if:
        a1/a2 = b1/b2 = c1/c2
        Where a1, b1, c1 are from equation 1
        a2, b2, c2 are from equation 2

    */
    if ((equations[0].a / equations[1].a) == (equations[0].b / equations[1].b)){
        if((equations[0].b / equations[1].b) == (equations[0].c / equations[1].c)){
            return 1;
        }
    }
    return 0;
}

int checkNumberOfSolutions(LINEAREQUATION *equations){
    /*
        Returns number of solutions the equations has by checking
        for parallel lines, infinite solutions etc.,
    */
    
    short int numSolutions = 0;
    if(checkInfiniteSolutions(equations))
        numSolutions = INFINITE_SOLUTIONS;
    else if(checkParallelLines(equations))
        numSolutions = NO_SOLUTIONS;
    else
        numSolutions = UNIQUE_SOLUTION;
    return numSolutions;
}

void swap(void *a, void *b, int type){
    /*
        Swapping of two variables using void pointers.
    */
    if(type == INT){
        int temp;
        temp = *((int *)a);
        *((int *)a) = *((int *)b);
        *((int *)b) = temp;
    } else {
        double temp;
        temp = *((double *)a);
        *((double *)a) = *((double *)b);
        *((double *)b) = temp;
    }
}

int compareResults(double res[][1], LINEAREQUATION *equations){
    /*
        function for comparing both the implementation (Substitution method and matrix method)
    */

    
    printf("Solution by Substitution Method : %0.2f, %0.2f \n", equations[0].x, equations[0].y);
    NEWLINE;
    printf("Solution by Matrix Method : %0.2f, %0.2f \n", res[0][0], res[1][0]);
    NEWLINE;
    
    if((equations[0].x == res[0][0]) && (equations[0].y == res[1][0])){
        return 1;
    }
    return 0;
}