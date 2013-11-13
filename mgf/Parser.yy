%code requires {
    namespace mgf {
        class Driver;
        class Scanner;
    }
}

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"
/* Require bison version or later */
%require "2.5"
/* add debug output code to generated parser. */
%debug
/* write a header file containing macro definitions */
%defines
/* namespace to enclose parser in */
%define namespace "mgf"
/* set the parser's class identifier */
%define parser_class_name "Parser"
/* start symbol is named "start" */
%start start
 
%lex-param { Scanner& scanner }
%parse-param { Scanner& scanner }
 
%lex-param { Driver& driver }
%parse-param { Driver& driver }
 
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
    int             v_integer;
    double          v_double;
    std::string*    v_string;
}
 

%token              T_END  0            "end of file"
%token              T_COMMENT           "comment"
%token              T_PLUS              "plus symbol"
%token              T_MINUS             "minus symbol"
%token              T_EQUALS            "equals symbol"
%token              T_USER              "USER token, USER00 to USER12"
%token              T_BEGIN_IONS        "BEGIN IONS token"
%token              T_END_IONS          "END IONS token"

%token <v_integer>  V_INTEGER           "integer"
%token <v_double>   V_DOUBLE            "double"
%token <v_string>   V_STRING            "string"

%token              K_ACCESSION         "ACCESSION keyword : Database entries to be searched. [List of double quoted, comma separated values]"
%token <v_integer>  K_CHARGE            "CHARGE keyword: Peptide charge. [8- to 8+ and combinations]"
%token              K_CLE               "CLE keyword: Enzyme. [Trypsin etc., as defined in enzymes file]"
%token              K_COM               "COM keyword: Search title"
%token              K_CUTOUT            "CUTOUT keyword: Precursor removal. [Pair of comma separated integers]"
%token              K_COMP              "COMP keyword: Amino acid composition"
%token              K_DB                "DB keyword: Database. [As defined in mascot.dat]"
%token              K_DECOY             "DECOY keyword: Perform decoy search. [0(default),1] "
%token              K_ERRORTOLERANT     "ERRORTOLERANT keyword: error tolerant. [0(default),1]"
%token              K_ETAG              "ETAG keyword: Error tolerant sequence tag."
%token              K_FORMAT            "FORMAT keyword: MS/MS data file. [mgf(default),dta,asc,pkl,pks,bruker .xml, mzdata .xml,mzml]"
%token              K_FRAMES            "FRAMES keyword: NA translation. [Comma separated list of frames,Default is 1,2,3,4,5,6]"
%token              K_INSTRUMENT        "INSTRUMENT keyword: MS/MS ion series. [ESI-QUAD-TOF etc., as defined in fragmentation_rules]"
%token              K_IT_MODS           "IT_MODS keyword: Variable Mods. [As defined in unimod.xml]"
%token              K_ITOLU             "ITOLU keyword: Units for ITOL. [Da,mmu]"
%token              K_LOCUS             "LOCUS keyword: Hierarchical scan range identifier. [string]"
%token              K_MASS              "MASS keyword: Mono. or average. [Monoisotopic,Average]"
%token              K_MODS              "MODS keyword: Fixed Mods. [As defined in unimod.xml]"
%token              K_MULTI_SITE_MODS   "MULTI_SITE_MODS keyword: Allow two modifications at a single site. [0(default),1]"
%token              K_PEP_ISOTOPE_ERROR "PEP_ISOTOPE_ERROR keyword: Misassigned 13C. [0 to 2]"
%token              K_PEPMASS           "PEPMASS keyword: Peptide mass. [>100]"
%token              K_PFA               "PFA keyword: Partials. [0 to 9, default = 1]"
%token              K_PRECURSOR         "PRECURSOR keyword: Precursor m/z. [>100]"
%token              K_QUANTITATION      "QUANTITATION keyword: Quantitation method. [as defined in quantitation.xml]"
%token              K_RAWFILE           "RAWFILE keyword: Raw file identifier. [string]"
%token              K_RAWSCANS          "RAWSCANS keyword: Native scan range identifiers. [a[:b]]"
%token              K_REPORT            "REPORT keyword: Maximum hits. [auto or integer]"
%token              K_REPTYPE           "REPTYPE keyword: Type of report. [protein,peptide (Default for MIS),archive,concise (Default for PMF),select,unassigned]"
%token              K_RTINSECONDS       "RTINSECONDS keyword: Retention time or range (in seconds). [a[-b]]"
%token              K_SCANS             "SCANS keyword: Scan number or range. [v[-w]]"
%token              K_SEARCH            "SEARCH keyword: Type of search. [PMF,SQ = MIS, MIS = SQ]"
%token              K_SEG               "SEG keyword: Protein mass (kDa) [empty or >0]"
%token              K_SEQ               "SEQ keyword: Amino acid sequence. [A single query can have multiple SEQs]"
%token              K_TAG               "TAG keyword: Sequence tag. [A single query can have multiple TAGs]" 
%token              K_TAXONOMY          "TAXONOMY keyword : Taxonomy. [As defined in taxonomy file]"
%token              K_TITLE             "TITLE keyword: Query title. [Applies to a single spectrum]"
%token              K_TOL               "TOL keyword: Peptide mass tol. [Unit dependent]"
%token              K_TOLU              "TOLU keyword : Units for TOL. [%,ppm,mmu,Da]"
%token              K_USEREMAIL         "USEREMAIL keyword: User email"
%token              K_USERNAME          "USERNAME keyword: User name"

/*\see http://www.matrixscience.com/help/data_file_help.html for more details*/

%destructor { delete $$; } V_STRING; 

/* destructor rule for <sval> objects */
/*%destructor { if ($$) { delete ($$); ($$) = nullptr; } } <sval>*/
/*
list_option : END 
            | list END;
 
list : item
     | list item;
 
item : UPPER { driver.add_upper(); }
     | LOWER { driver.add_lower(); }
     | WORD { driver.add_word( *$1 ); }
     | NEWLINE { driver.add_newline(); }
     | CHAR { driver.add_char(); };
*/
 
/*YYACCEPT pour stoper lex*/

 
%%

charge : V_INTEGER T_PLUS   {$$=$1;}
       | V_INTEGER T_MINUS  {$$=-$1;}

start : T_END


%%
 
 
void mgf::Parser::error(const mgf::Parser::location_type &l,const std::string &err_message)
{
   std::cerr << "Error: " << err_message << "\n"; 
}
 
 
/* include for access to scanner.yylex */
#include <mgf/Scanner.hpp>
static int yylex( mgf::Parser::semantic_type *yylval,
    mgf::Scanner& scanner,
    mgf::Driver& driver)
    {
        return scanner.yylex(yylval);
    }
