SRC = $(wildcard *.c*)
OBJ = $(SRC:.cpp=.o) $(SRC:*.cpp=.o)

all: Parser Lexer $(OBJ)
#main

.cpp.o:
	$(CC) $(FLAGS) -o "$@" -c "$<" 
	@mv $@ "$(OBJ_DIR)"

.c.o:
	$(CC) $(FLAGS) -o "$@" -c "$<"
	@mv $@ "$(OBJ_DIR)"

Parser: Parser.yy
	bison -v Parser.yy
#mv Parser.tab.hh $(TOP)/include/mgf/
#ln -s $(TOP)/include/mgf/Parser.tab.hh Parser.tab.hh
	$(CC) $(FLAGS) -o "$@.o" -c "$@.tab.cc" 
	@mv "$@.o" "$(OBJ_DIR)"

Lexer: Lexer.lex
	flex --outfile=$@.yy.cc $<
	$(CC) $(FLAGS) -o "$@.o" -c "$@.yy.cc" 
	@mv "$@.o" "$(OBJ_DIR)"



#main: main.cpp 
#	$(CC) $^ $(FLAGS) -o $@


clean:
	@rm -f *.o
	@rm -f *.exe
	@rm -f *.cc
	@rm -f *.hh
	@rm -f *.output

