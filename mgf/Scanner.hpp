#ifndef MGF_SCANNER_HPP
#define MGF_SCANNER_HPP

#if ! defined(yyFlexLexerOnce)
#include <mgf/FlexLexer.hpp>
#endif

// Override the interface for yylex since we namespaced it
#undef YY_DECL
#define YY_DECL int mgf::Scanner::yylex()

// Include Bison for types / tokens
#include <mgf/Parser.tab.hh>

namespace mgf
{
    class Scanner : public yyFlexLexer
    {
        public:
            Scanner(std::istream& in);
            Scanner(const Scanner&) = delete;
            Scanner& operator=(const Scanner&) = delete;

            // save the pointer to yylval so we can change it, and invoke scanner
            int yylex(mgf::Parser::semantic_type *lval);

        protected:

        private:
            // Scanning function created by Flex; make this private to force usage
			// of the overloaded method so we can get a pointer to Bison's yylval
            int yylex();
            /* yyval ptr */
            mgf::Parser::semantic_type *yylval;
    };
}
#endif
