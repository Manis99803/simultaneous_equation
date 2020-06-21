CC = gcc
DEPS = include/simultaneous_equation.h

MKDIR_P = mkdir -p

ODIR = obj
BINDIR = bin
IDIR = include


CFLAGS = -I$(IDIR)


OFILES = simultaneous_equation.o substitution_method.o matrix_method.o generic_functions.o draw_graph.o
OBJ = $(patsubst %,$(ODIR)/%,$(OFILES))
all: directory simultaneous_equation

directory: 
	$(MKDIR_P) $(ODIR) $(BINDIR)

$(OBJ): $(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

simultaneous_equation: $(OBJ)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS) $(LFLAGS) $(LIBS)

clean:
	rm $(ODIR)/*.o $(BINDIR)/demo