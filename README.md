# simultaneous_equation

## Directory structure:
    - simultaneous_equation/
       - include/
          - simultaneous_equation.h
       - src/
          - simultaneous_equation.c (Main function) o substitution_method.c
          - matrix_method.c
          - generic_functions.c
          - draw_graph.c
       - obj/
          - simultaneous_equation.o o substitution_method.o
          - matrix_method.o
          - generic_functions.o
          - draw_graph.o
       - bin/
          - simultaneous_equation (Executable)
          - graph.png (Graph obtained from the equation)
       - makefile
## Dependencies:
      1. To run this application “gnuplot” is required
          a. Mac:
            i. brewinstallgnuplot
          b. Linux:
            i. sudoapt-getinstallgnuplot

## Commands to run:
1. make
2. bin/simultaneous_equation (Provide appropriate inputs)
