/* header file for simultaneous equations */

/* HEADER_H is defined to avoid the problem of redefinition, if the same header file is repeated multiple
 time in any file that won't lead to an error */
#ifndef HEADER_H
#define HEADER_H

#define NUMBER_OF_EQUATIONS 2
#define NEWLINE printf("\n")

// Here 10000 is just used to represent INFINITE_SOLUTIONS
#define INFINITE_SOLUTIONS 10000
#define UNIQUE_SOLUTION 1
#define NO_SOLUTIONS 0

#define MINUS_ONE -1

// Used in Swap function to differenetiate between double and int
#define INT 1
#define DOUBLE 2

// Used to decide which coefficient has to be taken in while multiplying the
// equations
#define A 1
#define B 2


// To decide on which variables is to be solved first in the substitution method.
#define X 1
#define Y 2

// Equation structure
typedef struct _equation{
    double a;
    double x;
    double b;
    double y;
    double c;
}LINEAREQUATION;


/* Generic functions */

/* function which if the given lines are parallel */
int checkParallelLines(LINEAREQUATION *);

/* function which checks for number of solutions the given equations have */
int checkNumberOfSolutions(LINEAREQUATION *);

/* function for swapping two variables */
void swap(void *, void *, int );

/* function for checking the solutions obtained from substitution method and matrix method */
int compareResults(double res[][1], LINEAREQUATION *);

/* Function which takes input from user a, b, c, p, q, r */
void getConstantForEquations(LINEAREQUATION *, double matrixA[][2], double matrixB[][1]);



/* Draw graph functions */

/* Function which plots two lines */
void plotGraph(LINEAREQUATION *, int );



/* Functions dealing with Substitution method */

/* function for multiplying the equation with minus 1 */
void multiplyEquationWithMinusOne(LINEAREQUATION *);

/* function for multiplying the equations with some constant used in the substitution method */
void multiplyEquationsByConstant(LINEAREQUATION *, int);

/* function for copying one structure into another */
void copyStructures(LINEAREQUATION *, LINEAREQUATION *);


/* function for getting value of a variables when one of variable is solved */
double getOtherVariableValue(LINEAREQUATION *, int);

/* function for getting value of a variables when one of variable is zero */
double getVariableValue(LINEAREQUATION *, int);

/* function for printing the equations */
void printEquations(LINEAREQUATION *);

/* function for solving the equations by substitution method */
void solveEquationsBySubstitution(LINEAREQUATION *);




/* Function for solving the equations using matrix method */

/* function for inverting the matrices */
void invertMatrix(int row, int col, double matrix[row][col]);

/* function for multiplying the matrices */
void multiplyMatrix(int col1, double matrixA[][col1], int col2, double matrixB[][col2], double res[][col2]);

/* function for solving the equations by matrix method */
void solveEquationsByMatrix(int col1, double matrixA[][col1], int col2, double matrixB[][col2], double res[][col2]);

/* function for printing the matrices */
void printMatrix(int row, int col, double matrix[row][col]);

#endif

