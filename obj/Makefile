OBJ = $(wildcard *.o)

all: $(EXEC)

lib : $(OBJ)
	ar cr $(TOP)/lib$(EXEC).a $^
	
$(EXEC): $(OBJ)
	$(CC) $^ $(FLAGS) -o "$(TOP)/$(EXEC)"

clean:
	@rm -f *.o
