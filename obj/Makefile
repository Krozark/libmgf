OBJ = $(wildcard *.o)

all: $(EXEC)

static : $(OBJ)
	ar rcs $(TOP)/$(STATIC) $^

shared : $(OBJ)
	gcc -shared -Wl,-soname,$(TOP)/$(SHARED) -o $(TOP)/$(SHARED) $^
	
$(EXEC): $(OBJ)
	$(CC) $^ $(FLAGS) -o "$(TOP)/$(EXEC)"

clean:
	@rm -f *.o
