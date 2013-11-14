 /* use newer C++ skeleton file */
%skeleton "lalr1.cc"
/* Require bison version or later */
%require "2.5"
/* write a header file containing macro definitions */
%defines
/* namespace to enclose parser in */
%define namespace "mgf"
/* set the parser's class identifier */
%define parser_class_name "Parser"

/*%lex-param { Driver& driver }
%parse-param { Driver& driver }*/
 
%lex-param { mgf::Scanner& scanner }
%parse-param { mgf::Scanner& scanner }

%code requires {
    namespace mgf {
        /*class Driver;*/
        class Scanner;
    }
}
 
 
%code{
	/*Prototype for the yylex function*/
	static int yylex(mgf::Parser::semantic_type* yylval, mgf::Scanner& scanner);
}
 
/* token types */
%union {
    int             v_integer;
    double          v_double;
    std::string*    v_string;
}
 

%token              T_END  0            "end of file"
%token              T_EOL               "end of line"
%token              T_COMMENT           "comment"
%token              T_PLUS              "plus symbol"
%token              T_MINUS             "minus symbol"
%token              T_EQUALS            "equals symbol"
%token              T_COMA              "coma symbol"
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
%token              K_ITOL              "ITOL keyword:  Fragment ion tol. [Unit dependent]"
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
 
/*YYACCEPT pour stoper lex*/


/* start symbol is named "start" */
%start start
/* types */
%type <v_integer> charge 
 
%%

charge : V_INTEGER T_PLUS   {$$=$1;}
       | V_INTEGER T_MINUS  {$$=-$1;}
       ;

double_quoted : '"' V_DOUBLE '"'
              ;

double_quoted_list : double_quoted_list ',' double_quoted
                   | double_quoted
                   ;

interger_list : interger_list ',' V_INTEGER
              | V_INTEGER
              ;

string_list : string_list ',' V_STRING
            | V_STRING
            ;

number : V_INTEGER
       | V_DOUBLE
       ;

number_range : number
             | number '-' number
             ;

raw : V_INTEGER
    | V_INTEGER ':' V_INTEGER
    ;

report_val : V_INTEGER
           | "AUTO"
           ;

ions : ions ion
     | ion
     ;

ion : number number  T_EOL
    | number number charge
    ;

headerparams : /* empty */
             | headerparams headerparam
             ;

headerparam : K_ACCESSION T_EQUALS double_quoted_list T_EOL
            | K_CHARGE T_EQUALS charge T_EOL
            | K_CLE T_EQUALS V_STRING T_EOL
            | K_COMP T_EQUALS V_STRING T_EOL
            | K_CUTOUT T_EQUALS interger_list T_EOL
            | K_DB T_EQUALS V_STRING T_EOL
            | K_DECOY T_EQUALS V_INTEGER T_EOL
            | K_ERRORTOLERANT T_EQUALS V_INTEGER T_EOL
            | K_FORMAT T_EQUALS V_STRING T_EOL
            | K_FRAMES T_EQUALS interger_list T_EOL
            | K_INSTRUMENT T_EQUALS V_STRING T_EOL
            | K_IT_MODS T_EQUALS V_STRING T_EOL
            | K_ITOL T_EQUALS V_DOUBLE T_EOL
            | K_ITOLU T_EQUALS V_STRING T_EOL
            | K_MASS T_EQUALS V_STRING  T_EOL
            | K_MODS T_EQUALS V_STRING T_EOL
            | K_MULTI_SITE_MODS T_EQUALS V_INTEGER T_EOL
            | K_PEP_ISOTOPE_ERROR T_EQUALS V_INTEGER T_EOL
            | K_PFA T_EQUALS V_INTEGER T_EOL
            | K_PRECURSOR T_EQUALS number T_EOL
            | K_QUANTITATION T_EQUALS V_STRING T_EOL
            | K_REPORT T_EQUALS report_val T_EOL
            | K_REPTYPE T_EQUALS V_STRING T_EOL
            | K_SEARCH T_EQUALS V_STRING T_EOL
            | K_SEG T_EQUALS number T_EOL
            | K_TAXONOMY T_EQUALS V_STRING T_EOL
            | K_TOL T_EQUALS number T_EOL
            | K_TOLU T_EQUALS V_STRING T_EOL
            | T_USER V_INTEGER T_EOL
            | K_USEREMAIL T_EQUALS V_STRING T_EOL
            | K_USERNAME T_EQUALS V_STRING T_EOL
            ;

blocks : /* empty */
       | blocks block
       ;

block : T_BEGIN_IONS T_EOL blockparams ions T_END_IONS T_EOL
      | T_BEGIN_IONS T_EOL blockparams T_END_IONS T_EOL
      ;

blockparams : /* empty */
            | blockparams blockparam
            ;

blockparam  : K_CHARGE T_EQUALS charge T_EOL
            | K_COMP T_EQUALS V_STRING T_EOL
            | K_ETAG T_EQUALS string_list T_EOL
            | K_INSTRUMENT T_EQUALS V_STRING T_EOL
            | K_IT_MODS T_EQUALS V_STRING T_EOL
            | K_LOCUS T_EQUALS V_STRING T_EOL
            | K_PEPMASS T_EQUALS number T_EOL
            | K_RAWFILE T_EQUALS V_STRING T_EOL
            | K_RAWSCANS T_EQUALS raw T_EOL
            | K_RTINSECONDS T_EQUALS number_range T_EOL
            | K_SCANS T_EQUALS number_range T_EOL
            | K_SEQ T_EQUALS string_list T_EOL
            | K_TAG T_EQUALS string_list T_EOL
            | K_TITLE T_EQUALS V_STRING T_EOL
            | K_TOL T_EQUALS number T_EOL
            | K_TOLU T_EQUALS V_STRING T_EOL
            ;



start : headerparams blocks T_END
      ;


%%
 
 
void mgf::Parser::error(const mgf::Parser::location_type &loc,const std::string &message)
{
   std::cerr<<"Error: "<<message<<std::endl;; 
}
 
/*Now that we have the Parser declared, we can declare the Scanner and implement the yylex function*/
#include <mgf/Scanner.hpp>
static int yylex( mgf::Parser::semantic_type *yylval,mgf::Scanner& scanner)
{
    return scanner.yylex(yylval);
}
