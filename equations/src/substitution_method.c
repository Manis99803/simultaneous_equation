/* File which solves the equations by substitution method */

#include <stdio.h>
#include "simultaneous_equation.h"
#include "simultaneous_equation.h"


void printEquations(LINEAREQUATION *equations){
    /*
        prints the equations.
    */
    for(int i = 0; i < NUMBER_OF_EQUATIONS; i++){
        printf("Equation %d\n", (i + 1));
        printf("%dx + %dy = %d\n", (int)equations[i].a, (int)equations[i].b, (int)equations[i].c);
        NEWLINE;
    }
}


void copyStructures(LINEAREQUATION *copyEquations, LINEAREQUATION *equations){
    /*
        Copies one structure to another.
    */
    for(int i = 0; i < NUMBER_OF_EQUATIONS; i++){
        copyEquations[i].a = equations[i].a;
        copyEquations[i].b = equations[i].b;
        copyEquations[i].c = equations[i].c;
    }
}


void multiplyEquationWithMinusOne(LINEAREQUATION *equation){
    /* 
        Multiplies any given equation with -1.
    */
    equation->a *= MINUS_ONE;
    equation->b *= MINUS_ONE;
    equation->c *= MINUS_ONE;
}

void multiplyEquationsByConstant(LINEAREQUATION *equations, int constant){
    /*
        Multiplies both the with a constant.
        Ex:
        x + 2y = 3 ---> 1
        4x + 5y = 6 ---> 2
        if A is specified:
        Multiplies Eq. 1 with 4 and Eq. 2 with 1

        if B is specified:
        Multiplies Eq. 1 with 5 and Eq. 2 with 2

        The reason for such implementaion it can handle both the cases.
    */
    
    int m = 0;
    int n = 1;
    if(constant == A){
        double eq_a[2] = {equations[0].a, equations[1].a};
        for(int i = 0; i < NUMBER_OF_EQUATIONS; i++){
            equations[m].a *= eq_a[n];
            equations[m].b *= eq_a[n];
            equations[m].c *= eq_a[n];  
            swap(&m, &n, INT); 
        }
    } else {
        double eq_b[2] = {equations[0].b, equations[1].b};
        for(int i = 0; i < NUMBER_OF_EQUATIONS; i++){
            equations[m].a *= eq_b[n];
            equations[m].b *= eq_b[n];
            equations[m].c *= eq_b[n];  
            swap(&m, &n, INT); 
        }
    }

}

double getOtherVariableValue(LINEAREQUATION *equations, int variableType){
    /*
        solves and return the values of y if x is already solved (or)
        returns value of x is y is already solved.
    */
    if(variableType == X){
        double x;
        double y = (equations[0].b * equations[0].y);
        double c = equations[0].c;
        printf("Intermediate Equations : x = (%0.2lf + (-1 * %0.2lf))/%0.2lf\n", c, y, equations[0].a);
        NEWLINE;
        x = (c + (-1 * y))/equations[0].a;
        return x;
    } else {
        double x = (equations[0].a * equations[0].x);
        double y;
        double c = equations[0].c;
        printf("Intermediate Equations : y = (%0.2lf + (-1 * %0.2lf))/%0.2lf\n", c, x, equations[0].b);
        NEWLINE;
        y = (c + (-1 * x))/equations[0].b;
        return y;
    }
}

double getVariableValue(LINEAREQUATION *equations, int variableType){
    /*
        returns value of X if y is made 0 (or)
        returns value of Y if x is made 0
    */
    if(variableType == X){
        double x;
        double a = (equations[0].a + equations[1].a);
        double c = (equations[0].c + equations[1].c);
        printf("Intermediate Equations : x = %0.2lf/%0.2lf\n", c, a);
        NEWLINE;
        x = c/a;
        return x;
    } else {
        double y;
        double b = (equations[0].b + equations[1].b);
        double c = (equations[0].c + equations[1].c);
        printf("Intermediate Equations : y = %0.2lf/%0.2lf\n", c, b);
        NEWLINE;
        y = c/b;
        return y;
    }
}


void solveEquationsBySubstitution(LINEAREQUATION *equations){
    /*
        solves the simultaneous equation by substitution method
    */
    
    LINEAREQUATION copyEquations[2];

    copyStructures(copyEquations, equations);
    
    printf("Equations before multiplication : \n");
    NEWLINE;
    printEquations(copyEquations);

    multiplyEquationsByConstant(copyEquations, B);

    printf("Equations After multiplication : \n");
    NEWLINE;
    printEquations(copyEquations);
    
    multiplyEquationWithMinusOne(&copyEquations[1]);
    copyEquations[0].y = 0;
    copyEquations[1].y = 0;
    
    equations[0].x = getVariableValue(copyEquations, X);
    equations[1].x = equations[0].x;

    equations[0].y = getOtherVariableValue(equations, Y);
    equations[1].y = equations[0].y;
}



void solveEquationsByFormula(LINEAREQUATION *equations){
    /*
        Formula to get x and y.
        y = (ra - pc)/(qa - pb);
        x = (r - q*y)/p;
    */
    double y = ((equations[1].c * equations[0].a) - (equations[1].b * equations[0].c))/((equations[1].b * equations[0].a) - (equations[1].a - equations[0].b));
    double x = (equations[1].c - equations[1].b * y)/equations[1].b;
}