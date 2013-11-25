SRC = $(wildcard *.c*)
OBJ = $(SRC:.cpp=.o) $(SRC:*.cpp=.o)

all: Parser Lexer $(OBJ)
#main

.cpp.o:
	$(CC) $(FLAGS) -o "$@" -c "$<" 
	@cp $@ "$(OBJ_DIR)"

.c.o:
	$(CC) $(FLAGS) -o "$@" -c "$<"
	@cp $@ "$(OBJ_DIR)"

Parser: Parser.yy
	bison -v Parser.yy
	$(CC) $(FLAGS) -o "$@.o" -c "$@.tab.cc" 
	@cp "$@.o" "$(OBJ_DIR)"

Lexer: Lexer.lex
	flex --outfile=$@.yy.cc $<
	$(CC) $(FLAGS) -o "$@.o" -c "$@.yy.cc" 
	@cp "$@.o" "$(OBJ_DIR)"



#main: main.cpp 
#	$(CC) $^ $(FLAGS) -o $@


clean:
	@rm -f *.o
	@rm -f *.exe
	@rm *.cc
	@rm *.hh

