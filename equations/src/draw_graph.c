/*
    File which plots graphs given two lines
*/
#include<stdio.h>
#include "simultaneous_equation.h"

void plotGraph(LINEAREQUATION *equations, int numSolutions) {
  /*
    Function for plotting graph using gnuplot
  */
  FILE *plot = popen("gnuplot", "w");
  
  if(numSolutions == UNIQUE_SOLUTION){  
    fprintf(plot, "set term png\n");
    fprintf(plot, "set output  'graph.png'\n");
    fprintf(plot, "plot (%d - %d * x)/%d, (%d - %d * x)/%d \n", (int)equations[0].c, (int)equations[0].a,(int) equations[0].b, 
            (int)equations[1].c, (int)equations[1].a, (int)equations[1].b);
    fprintf(plot, "quit\n");
  } else {
    fprintf(plot, "set term png\n");
    fprintf(plot, "set output  'graph.png'\n");
    fprintf(plot, "plot (%d - %d * x)/%d\n", (int)equations[0].c, (int)equations[0].a, (int)equations[0].b);
    fprintf(plot, "quit\n");
  }
}