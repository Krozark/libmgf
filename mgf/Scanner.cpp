#include <Scanner.hpp>

namespace mgf
{
    
    Scanner::Scanner(std::istream& in) : yyFlexLexer(&in), yylval(nullptr)
    {
    }

    int Scanner::yylex(MC::MC_Parser::semantic_type *lval)
    {
        yylval = lval;
        return this->yylex();
    }
}
