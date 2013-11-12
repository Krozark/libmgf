%skeleton "lalr1.cc"
%require "2.5"
%debug
%defines
%define namespace "mgf"
%define parser_class_name "Parser"
 
%code requires{
    namespace mgf {
        class Driver;
        class Scanner;
    }
}
 
%lex-param { Scanner &scanner }
%parse-param { Scanner &scanner }
 
%lex-param { Driver &driver }
%parse-param { Driver &driver }
 
%code{
    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    /* include for all driver functions */
    #include <mgf/Driver.hpp>

    /* this is silly, but I can't figure out a way around */
    static int yylex(mgf::Parser::semantic_type *yylval,
        mgf::Scanner &scanner,
        mgf::Driver &driver);
}
 
/* token types */
%union {
    std::string *sval;
}
 
%token  END     0   "end of file"
%token  UPPER
%token  LOWER
%token  <sval>  WORD
%token  NEWLINE
%token  CHAR
 
 
/* destructor rule for <sval> objects */
/*%destructor { if ($$) { delete ($$); ($$) = nullptr; } } <sval>*/
%destructor { delete( $$ ); } WORD
 
 
%%
 
list_option : END 
            | list END;
 
list : item
     | list item;
 
item : UPPER { /*driver.add_upper();*/ }
     | LOWER { /*driver.add_lower();*/ }
     | WORD { /*driver.add_word( *$1 );*/ }
     | NEWLINE { /*driver.add_newline();*/ }
     | CHAR { /*driver.add_char();*/ };
 
%%
 
 
void mgf::Parser::error(const mgf::Parser::location_type &l,const std::string &err_message)
{
   std::cerr << "Error: " << err_message << "\n"; 
}
 
 
/* include for access to scanner.yylex */
#include <mgf/Scanner.hpp>
static int yylex( mgf::Parser::semantic_type *yylval,
    mfg::Scanner &scanner,
    mgf::Driver &driver)
    {
        return scanner.yylex(yylval);
    }
