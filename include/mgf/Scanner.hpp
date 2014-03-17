#ifndef MGF_SCANNER_HPP
#define MGF_SCANNER_HPP

#if ! defined(yyFlexLexerOnce)
#include <mgf/FlexLexer.hpp>
#endif

// Override the interface for yylex since we namespaced it
#undef YY_DECL
#define YY_DECL int mgf::Scanner::yylex()

// Include Bison for types / tokens
#include <mgf/Parser.hpp>

namespace mgf
{
    class Parser;
    //typename Parser::semantic_type;

    /**
     * \brief The lexer that tokenize the input
     */
    class Scanner : public yyFlexLexer
    {
        public:
            /**
             * \brief Construct from a input
             * \param in MGF imput
             */
            Scanner(std::istream& in);
            Scanner(const Scanner&) = delete;
            Scanner& operator=(const Scanner&) = delete;
            /**
             * \breif save the pointer to yylval so we can change it, and invoke scanner
             * \parap lval For Lex/bison
             * \return 0 if all input is parse, MGF_END_IONS if end of ion, else, error
             */
            int yylex(mgf::Parser::semantic_type *lval);

        protected:

        private:
            /**
             * \breif Scanning function created by Flex; make this private to force usage
             * of the overloaded method so we can get a pointer to Bison's yylval
             */
            int yylex();
            /* yyval ptr */
            mgf::Parser::semantic_type *yylval; ///< For Lex/bison
    };
}
#endif
