SRC = $(wildcard *.c*)
OBJ = $(SRC:.cpp=.o) $(SRC:*.cpp=.o)

all: Parser lexer $(OBJ)
#main

.cpp.o:
	$(CC) $(FLAGS) -o "$@" -c "$<" 
	@cp $@ "$(OBJ_DIR)"

.c.o:
	$(CC) $(FLAGS) -o "$@" -c "$<"
	@cp $@ "$(OBJ_DIR)"

Parser: Parser.yy
	bison -d -v Parser.yy
	$(CC) $(FLAGS) -o "$@.o" -c "$@.tab.cc" 
	@cp "$@.o" "$(OBJ_DIR)"


#main: main.cpp 
#	$(CC) $^ $(FLAGS) -o $@


clean:
	@rm -f *.o
	@rm -f *.exe
	@rm *.output
	@rm *.cc
	@rm *.hh

