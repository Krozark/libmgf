%{
/* stl */
#include <string>
#include <sstream>
/* Implementation of yyFlexScanner */
#include <mgf/Scanner.hpp>
#include <mgf/defines.hpp>
 
/* typedef to make the returns for the tokens shorter */
typedef mgf::Parser::token token;
int mgf_line_no = 1;
 
/* define yyterminate as this instead of NULL */
#define yyterminate() return token::T_END;

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H


/*
    token::T_ => general token
    token::V_ => value
    token::K_ => key word
*/

%}
 
%option c++
%option yyclass="Scanner"
%option nodefault
%option noyywrap
 
%%

\n {
    MGF_TOKEN_DEBUG("T_EOL");
    ++mgf_line_no;
    return token::T_EOL;
}

^[#;!/][^\n]*\n {
    MGF_TOKEN_DEBUG("T_COMMENT");
    ++mgf_line_no;
    /*return token::T_COMMENT;*/
}

[[:space:]] {}


[0-9]+ {
    MGF_TOKEN_DEBUG("V_INTEGER"<<" (="<<yytext<<")");
    yylval->v_integer = atoi(yytext);
    return token::V_INTEGER;
}

[0-9]+"."[0-9]* {
    MGF_TOKEN_DEBUG("V_DOUBLE"<<" (="<<yytext<<")");
    yylval->v_double = atof(yytext);
    return token::V_DOUBLE;
}

[0-9]+("."[0-9]+)?[eE][+-][0-9]+ {
    MGF_TOKEN_DEBUG("V_DOUBLE"<<" (="<<yytext<<")");
    std::istringstream iss;
    iss.str(std::string(yytext));
    iss >> yylval->v_double;
    return token::V_DOUBLE;
}







"+" {
    MGF_TOKEN_DEBUG("T_PLUS");
    return token::T_PLUS;
}

"-" {
    MGF_TOKEN_DEBUG("T_MINUS");
    return token::T_MINUS;
}

"=" {
    MGF_TOKEN_DEBUG("T_EQUALS");
    return token::T_EQUALS;
}

"," {
    MGF_TOKEN_DEBUG("T_COMA");
    return token::T_COMA;
}

"and" {
    MGF_TOKEN_DEBUG("T_AND");
    return token::T_AND;
}

^"USER" {
    MGF_TOKEN_DEBUG("T_USER");
    return token::T_USER;
}

^"BEGIN IONS"[\r\t]* {
    MGF_TOKEN_DEBUG("T_BEGIN_IONS");
    return token::T_BEGIN_IONS;
}

^"END IONS"[\r\t]* {
    MGF_TOKEN_DEBUG("T_END_IONS");
    return token::T_END_IONS;
}






^"ACCESSION" {
    MGF_TOKEN_DEBUG("K_ACCESSION");
    return token::K_ACCESSION;
}

^"CHARGE" {
    MGF_TOKEN_DEBUG("K_CHARGE");
    return token::K_CHARGE;
}

^"CLE" {
    MGF_TOKEN_DEBUG("K_CLE");
    return token::K_CLE;
}

^"COM" {
    MGF_TOKEN_DEBUG("K_COM");
    return token::K_COM;
}

^"CUTOUT" {
    MGF_TOKEN_DEBUG("K_CUTOUT");
    return token::K_CUTOUT;
}

^"COMP" {
    MGF_TOKEN_DEBUG("K_COMP");
    return token::K_COMP;
}

^"DB" {
    MGF_TOKEN_DEBUG("K_DB");
    return token::K_DB;
}

^"DECOY" {
    MGF_TOKEN_DEBUG("K_DECOY");
    return token::K_DECOY;
}

^"ERRORTOLERANT" {
    MGF_TOKEN_DEBUG("K_ERRORTOLERANT");
    return token::K_ERRORTOLERANT;
}

^"ETAG" {
    MGF_TOKEN_DEBUG("K_ETAG");
    return token::K_ETAG;
}

^"FORMAT" {
    MGF_TOKEN_DEBUG("K_FORMAT");
    return token::K_FORMAT;
}

^"FRAMES" {
    MGF_TOKEN_DEBUG("K_FRAMES");
    return token::K_FRAMES;
}

^"INSTRUMENT" {
    MGF_TOKEN_DEBUG("K_INSTRUMENT");
    return token::K_INSTRUMENT;
}

^"IT_MODS" {
    MGF_TOKEN_DEBUG("K_IT_MODS");
    return token::K_IT_MODS;
}

^"ITOL" {
    MGF_TOKEN_DEBUG("K_ITOL");
    return token::K_ITOL;
}

^"ITOLU" {
    MGF_TOKEN_DEBUG("K_ITOLU");
    return token::K_ITOLU;
}

^"LOCUS" {
    MGF_TOKEN_DEBUG("K_LOCUS");
    return token::K_LOCUS;
}

^"MASS" {
    MGF_TOKEN_DEBUG("K_MASS");
    return token::K_MASS;
}

^"MODS" {
    MGF_TOKEN_DEBUG("K_MODS");
    return token::K_MODS;
}

^"MULTI_SITE_MODS" {
    MGF_TOKEN_DEBUG("K_MULTI_SITE_MODS");
    return token::K_MULTI_SITE_MODS;
}

^"PEP_ISOTOPE_ERROR" {
    MGF_TOKEN_DEBUG("K_PEP_ISOTOPE_ERROR");
    return token::K_PEP_ISOTOPE_ERROR;
}

^"PEPMASS" {
    MGF_TOKEN_DEBUG("K_PEPMASS");
    return token::K_PEPMASS;
}

^"PFA" {
    MGF_TOKEN_DEBUG("K_PFA");
    return token::K_PFA;
}

^"PRECURSOR" {
    MGF_TOKEN_DEBUG("K_PRECURSOR");
    return token::K_PRECURSOR;
}

^"QUANTITATION" {
    MGF_TOKEN_DEBUG("K_QUANTITATION");
    return token::K_QUANTITATION;
}

^"RAWFILE" {
    MGF_TOKEN_DEBUG("K_RAWFILE");
    return token::K_RAWFILE;
}

^"RAWSCANS" {
    MGF_TOKEN_DEBUG("K_RAWSCANS");
    return token::K_RAWSCANS;
}

^"REPORT" {
    MGF_TOKEN_DEBUG("K_REPORT");
    return token::K_REPORT;
}

^"REPTYPE" {
    MGF_TOKEN_DEBUG("K_REPTYPE");
    return token::K_REPTYPE;
}

^"RTINSECONDS" {
    MGF_TOKEN_DEBUG("K_RTINSECONDS");
    return token::K_RTINSECONDS;
}

^"SCANS" {
    MGF_TOKEN_DEBUG("K_SCANS");
    return token::K_SCANS;
}

^"SEARCH" {
    MGF_TOKEN_DEBUG("K_SEARCH");
    return token::K_SEARCH;
}

^"SEG" {
    MGF_TOKEN_DEBUG("K_SEG");
    return token::K_SEG;
}

^"SEQ" {
    MGF_TOKEN_DEBUG("K_SEQ");
    return token::K_SEQ;
}

^"TAG" {
    MGF_TOKEN_DEBUG("K_TAG");
    return token::K_TAG;
}

^"TAXONOMY" {
    MGF_TOKEN_DEBUG("K_TAXONOMY");
    return token::K_TAXONOMY;
}

^"TITLE" {
    MGF_TOKEN_DEBUG("K_TITLE");
    return token::K_TITLE;
}

^"TOL" {
    MGF_TOKEN_DEBUG("K_TOL");
    return token::K_TOL;
}

^"TOLU" {
    MGF_TOKEN_DEBUG("K_TOLU");
    return token::K_TOLU;
}

^"USEREMAIL" {
    MGF_TOKEN_DEBUG("K_USEREMAIL");
    return token::K_USEREMAIL;
}

^"USERNAME" {
    MGF_TOKEN_DEBUG("K_USERNAME");
    return token::K_USERNAME;
}




[A-Za-z][:;()A-Za-z0-9_.|]* {
    MGF_TOKEN_DEBUG("V_STRING"<<" (="<<yytext<<")");
    yylval->v_string = new std::string(yytext, yyleng);
    return token::V_STRING;
}

