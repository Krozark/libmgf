%{
/* stl */
#include <string>
#include <sstream>
/* Implementation of yyFlexScanner */
#include <mgf/Scanner.hpp>
 
/* typedef to make the returns for the tokens shorter */
typedef mgf::Parser::token token;
 
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
    return token::T_EOL;
}

#[^/n]* {
    return token::T_COMMENT;
}

[[:space:]] {}


[0-9]+ {
    yylval->v_integer = atoi(yytext);
    return token::V_INTEGER;
}

[0-9]+"."[0-9]* {
    yylval->v_double = atof(yytext);
    return token::V_DOUBLE;
}

[0-9]+("."[0-9]+)?[eE][+-][0-9]+ {
    std::istringstream iss;
    iss.str(std::string(yytext));
    iss >> yylval->v_double;
    return token::V_DOUBLE;
}







"+" {
    return token::T_PLUS;
}

"-" {
    return token::T_MINUS;
}

"=" {
    return token::T_EQUALS;
}

"USER" {
    return token::T_USER;
}

^"BEGIN IONS"[\r\t]* {
    return token::T_BEGIN_IONS;
}

^"END IONS"[\r\t]* {
    return token::T_END_IONS;
}






"ACCESSION" {
    return token::K_ACCESSION;
}

"CHARGE" {
    return token::K_CHARGE;
}

"CLE" {
    return token::K_CLE;
}

"COM" {
    return token::K_COM;
}

"CUTOUT" {
    return token::K_CUTOUT;
}

"COMP" {
    return token::K_COMP;
}

"DB" {
    return token::K_DB;
}

"DECOY" {
    return token::K_DECOY;
}

"ERRORTOLERANT" {
    return token::K_ERRORTOLERANT;
}

"ETAG" {
    return token::K_ETAG;
}

"FORMAT" {
    return token::K_FORMAT;
}

"FRAMES" {
    return token::K_FRAMES;
}

"INSTRUMENT" {
    return token::K_INSTRUMENT;
}

"IT_MODS" {
    return token::K_IT_MODS;
}

"ITOL" {
    return token::K_ITOL;
}

"ITOLU" {
    return token::K_ITOLU;
}

"LOCUS" {
    return token::K_LOCUS;
}

"MASS" {
    return token::K_MASS;
}

"MODS" {
    return token::K_MODS;
}

"MULTI_SITE_MODS" {
    return token::K_MULTI_SITE_MODS;
}

"PEP_ISOTOPE_ERROR" {
    return token::K_PEP_ISOTOPE_ERROR;
}

"PEPMASS" {
    return token::K_PEPMASS;
}

"PFA" {
    return token::K_PFA;
}

"PRECURSOR" {
    return token::K_PRECURSOR;
}

"QUANTITATION" {
    return token::K_QUANTITATION;
}

"RAWFILE" {
    return token::K_RAWFILE;
}

"RAWSCANS" {
    return token::K_RAWSCANS;
}

"REPORT" {
    return token::K_REPORT;
}

"REPTYPE" {
    return token::K_REPTYPE;
}

"RTINSECONDS" {
    return token::K_RTINSECONDS;
}

"SCANS" {
    return token::K_SCANS;
}

"SEARCH" {
    return token::K_SEARCH;
}

"SEG" {
    return token::K_SEG;
}

"SEQ" {
    return token::K_SEQ;
}

"TAG" {
    return token::K_TAG;
}

"TAXONOMY" {
    return token::K_TAXONOMY;
}

"TITLE" {
    return token::K_TITLE;
}

"TOL" {
    return token::K_TOL;
}

"TOLU" {
    return token::K_TOLU;
}

"USEREMAIL" {
    return token::K_USEREMAIL;
}

"USERNAME" {
    return token::K_USERNAME;
}




[A-Za-z][:;,()A-Za-z0-9_.-]* {
    yylval->v_string = new std::string(yytext, yyleng);
    return token::V_STRING;
}

