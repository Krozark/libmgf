#ifndef MGF_SCANNER_HPP
#define MGF_SCANNER_HPP

#include <mgf/FlexLexer.hpp>
 
#undef YY_DECL
#define YY_DECL int mgf::Scanner::yylex()
 
#include <mgf/Parser.tab.hh>

namespace mgf
{
    class Scanner : public yyFlexLexer
    {
        public:
            Scanner(std::istream& in);
            Scanner(const Scanner&) = delete;
            Scanner& operator=(const Scanner&) = delete;

            int yylex(mgf::Parser::semantic_type *lval);

        protected:

        private:
            /* hide this one from public view */
            int yylex();
            /* yyval ptr */
            mgf::Parser::semantic_type *yylval;
    };
}
#endif
