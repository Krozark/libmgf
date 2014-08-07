 /* use newer C++ skeleton file */
%skeleton "lalr1.cc"
/* Require bison version or later */
%require "3.0"
/* write a header file containing macro definitions */
%defines
/* verbose error messages */
%error-verbose
/* namespace to enclose parser in */
%define api.namespace {mgf}
/* set the parser's class identifier */
%define parser_class_name {Parser}
 
%lex-param { mgf::Scanner& scanner }
%parse-param { mgf::Scanner& scanner }

/*%lex-param { mgf::Driver& driver }*/
%parse-param { mgf::Driver& driver }

%code requires {
    #include <list>
	#include <string>
    #include <mgf/defines.hpp>
    #include <mgf/stdfx.hpp>

    #define MGF_NEW_INTEGER_LIST new std::list<int>
    #define MGF_NEW_DOUBLE_LIST new std::list<double>
    #define MGF_NEW_STRING_LIST new std::list<std::string>
    #define MGF_NEW_ION_LIST    new std::list<mgf::s_ion>

    extern int mgf_line_no;

    namespace mgf {

        struct s_range {double min,max;};
        struct s_i_range {double min,max;};
        struct s_ion {double mz,it;int charge;};

        class Scanner;
        class Driver;
    }
    
}
 
 
%code{
    #include <utility>
    #include <mgf/Driver.hpp>
    #include <mgf/Spectrum.hpp>
	/*Prototype for the yylex function*/
	static int yylex(mgf::Parser::semantic_type* yylval, mgf::Scanner& scanner);

    #define DEL(x) delete x; x=nullptr;
    #define YYSTOP {yyresult=MGF_END_IONS;goto yyreturn;}
}
 
/* token types */
%union {
    int                         v_integer;
    double                      v_double;
    std::string*                v_string;
    std::list<int>*             v_interger_list;
    std::list<double>*          v_double_list;
    std::list<std::string>*     v_string_list;
    mgf::s_range                v_d_range;
    mgf::s_i_range              v_i_range;
}
 

%token              T_END  0            "end of file"
%token              T_EOL               "end of line"
/*%token              T_COMMENT           "comment"*/
%token              T_PLUS              "plus symbol"
%token              T_MINUS             "minus symbol"
%token              T_EQUALS            "equals symbol"
%token              T_COMA              "coma symbol"
%token              T_AND               "and"
%token              T_USER              "USER token, USER00 to USER12"
%token              T_BEGIN_IONS        "BEGIN IONS token"
%token              T_END_IONS          "END IONS token"

%token <v_integer>  V_INTEGER           "integer"
%token <v_double>   V_DOUBLE            "double"
%token <v_string>   V_STRING            "string"

%token              K_ACCESSION         "ACCESSION keyword : Database entries to be searched. [List of double quoted, comma separated values]"
%token              K_CHARGE            "CHARGE keyword: Peptide charge. [8- to 8+ and combinations]"
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

/*YYACCEPT pour stoper lex*/


/* start symbol is named "start" */
%start start
/* types */
%type <v_integer>           charge
%type <v_interger_list>     charge_list
%type <v_double>            double_quoted
%type <v_double_list>       double_quoted_list
%type <v_interger_list>     interger_list
%type <v_string_list>       string_list
%type <v_string>            string_st
%type <v_string>            title
%type <v_double>            number
%type <v_d_range>           number_range
%type <v_i_range>           raw
%type <v_integer>           report_val


/*ignored : T_EOL
        ;

ignoreds : ignored
         | ignoreds ignored
         ;*/

%%

charge : V_INTEGER T_PLUS   {$$=$1;}
       | V_INTEGER T_MINUS  {$$=-$1;}
       | V_INTEGER {$$=$1;}
       ;

charge_list : charge    {auto l=MGF_NEW_INTEGER_LIST;l->push_back($1);$$=l;}
            | charge_list T_COMA charge {$1->push_back($3);$$=$1;$1=nullptr;}
            | charge_list T_AND charge  {$1->push_back($3);$$=$1;$1=nullptr;}
            ;

double_quoted : '"' V_DOUBLE '"' {$$=$2;}
              ;

double_quoted_list : double_quoted_list T_COMA double_quoted { $1->push_back($3);$$=$1;$1=nullptr;}
                   | double_quoted  {auto l = MGF_NEW_DOUBLE_LIST;l->push_back($1);$$=l;}
                                    
                   ;

interger_list : interger_list T_COMA V_INTEGER {$1->push_back($3);$$=$1;$1=nullptr;}
              | V_INTEGER   {auto l = MGF_NEW_INTEGER_LIST;l->push_back($1);$$=l;}
              ;

string_st : V_STRING {$$=$1;$1=nullptr;}
          | string_st V_STRING  {*$1+=*$2;DEL($2);$$=$1;$1=nullptr;}
          | string_st number {*$1+=std::to_string($2);$$=$1;$1=nullptr;}
          | string_st T_PLUS {*$1+="+";$$=$1;$1=nullptr;}
          | string_st T_MINUS {*$1+="-";$$=$1;$1=nullptr;}
          ;

title   : V_STRING {$$=$1;$1=nullptr;}
        | title V_STRING  {*$1+=*$2;DEL($2);$$=$1;$1=nullptr;}
        | title number {*$1+=std::to_string($2);$$=$1;$1=nullptr;}
        | title T_PLUS {*$1+="+";$$=$1;$1=nullptr;}
        | title T_MINUS {*$1+="-";$$=$1;$1=nullptr;}
        | title T_COMA {*$1+=",";$$=$1;$1=nullptr;}
        | title T_EQUALS {*$1+="=";$$=$1;$1=nullptr;}
        ;

string_list : string_list T_COMA string_st  {$1->push_back(*$3);$$=$1;$1=nullptr;DEL($3);}
            | string_st  {auto l = MGF_NEW_STRING_LIST;l->push_back(*$1);$$=l;}
            ;


number : V_INTEGER  {$$=$1;}
       | V_DOUBLE   {$$=$1;}
       ;

number_range : number   {$$.min=$1;$$.max=-1;}
             | number T_MINUS number {$$.min=$1;$$.max=$3;}
             ;

raw : V_INTEGER {$$.min=$1;$$.max=-1;}
    | V_INTEGER ':' V_INTEGER {$$.min=$1;$$.max=$3;}
    ;

report_val : V_INTEGER  {$$=$1;}
           | "AUTO"     {$$=-1;}
           ;


headerparam : K_ACCESSION T_EQUALS double_quoted_list T_EOL {driver.header.setAccession(*$3);DEL($3);}
            | K_CHARGE T_EQUALS charge_list T_EOL {driver.header.setCharge(*$3);DEL($3);}
            | K_CLE T_EQUALS V_STRING T_EOL {driver.header.setCle(*$3);DEL($3);}
            | K_COM T_EQUALS V_STRING T_EOL {driver.header.setCom(*$3);DEL($3);}
            | K_COMP T_EQUALS V_STRING T_EOL {driver.header.setComp(*$3);DEL($3);}
            | K_CUTOUT T_EQUALS interger_list T_EOL {driver.header.setCutout(*$3);DEL($3);}
            | K_DB T_EQUALS V_STRING T_EOL {driver.header.setDb(*$3);DEL($3);}
            | K_DECOY T_EQUALS V_INTEGER T_EOL {driver.header.setDecoy($3);}
            | K_ERRORTOLERANT T_EQUALS V_INTEGER T_EOL {driver.header.setErrorTolerant($3);}
            | K_FORMAT T_EQUALS V_STRING T_EOL {driver.header.setFormat(*$3);DEL($3)}
            | K_FRAMES T_EQUALS interger_list T_EOL {driver.header.setFrames(*$3);DEL($3);}
            | K_INSTRUMENT T_EQUALS V_STRING T_EOL {driver.header.setInstrument(*$3);DEL($3);}
            | K_IT_MODS T_EQUALS V_STRING T_EOL {driver.header.setItMods(*$3);DEL($3);}
            | K_ITOL T_EQUALS V_DOUBLE T_EOL {driver.header.setItOl($3);}
            | K_ITOLU T_EQUALS V_STRING T_EOL {driver.header.setItOlU(*$3);DEL($3);}
            | K_MASS T_EQUALS V_STRING  T_EOL {driver.header.setMass(*$3);DEL($3);}
            | K_MODS T_EQUALS V_STRING T_EOL {driver.header.setMods(*$3);DEL($3);}
            | K_MULTI_SITE_MODS T_EQUALS V_INTEGER T_EOL {driver.header.setMultiSiteMods($3);}
            | K_PEP_ISOTOPE_ERROR T_EQUALS V_INTEGER T_EOL {driver.header.setPepIsotopeError($3);}
            | K_PFA T_EQUALS V_INTEGER T_EOL {driver.header.setPfa($3);}
            | K_PRECURSOR T_EQUALS number T_EOL {driver.header.setPrecursor($3);}
            | K_QUANTITATION T_EQUALS V_STRING T_EOL {driver.header.setQuantitation(*$3);DEL($3);}
            | K_REPORT T_EQUALS report_val T_EOL {driver.header.setRepport($3);}
            | K_REPTYPE T_EQUALS V_STRING T_EOL {driver.header.setReptype(*$3);DEL($3);}
            | K_SEARCH T_EQUALS V_STRING T_EOL {driver.header.setSearch(*$3);DEL($3);}
            | K_SEG T_EQUALS number T_EOL {driver.header.setSeg($3);}
            | K_TAXONOMY T_EQUALS V_STRING T_EOL {driver.header.setTaxonomy(*$3);DEL($3);}
            | K_TOL T_EQUALS number T_EOL {driver.header.setTol($3);}
            | K_TOLU T_EQUALS V_STRING T_EOL {driver.header.setTolU(*$3);DEL($3);}
            | T_USER V_INTEGER T_EOL {driver.header.setUser($2);}
            | K_USEREMAIL T_EQUALS V_STRING T_EOL {driver.header.setUserMail(*$3);DEL($3);}
            | K_USERNAME T_EQUALS V_STRING T_EOL {driver.header.setUserName(*$3);DEL($3);}
            | T_EOL
            ;

headerparams : /* empty */
             | headerparams headerparam
             ;


ion : number number  T_EOL {driver.currentSpectrum.push($1,$2,0);}
    | number number charge T_EOL {driver.currentSpectrum.push($1,$2,$3);}
    ;

ions : ions ion 
     | ion      
     ;

block : T_BEGIN_IONS T_EOL blockparams ions T_END_IONS T_EOL    {YYSTOP;}
      | T_BEGIN_IONS T_EOL blockparams T_END_IONS T_EOL         {YYSTOP;}
      ;

blocks : /* empty */
       | blocks block
       | blocks T_EOL block
       ;

blockparam  : K_CHARGE T_EQUALS charge T_EOL {driver.currentSpectrum.header.setCharge($3);}
            | K_COMP T_EQUALS V_STRING T_EOL {driver.currentSpectrum.header.setComp(*$3);DEL($3);}
            | K_ETAG T_EQUALS string_list T_EOL {driver.currentSpectrum.header.setEtag(*$3);DEL($3);}
            | K_INSTRUMENT T_EQUALS V_STRING T_EOL {driver.currentSpectrum.header.setInstrument(*$3);DEL($3);}
            | K_IT_MODS T_EQUALS V_STRING T_EOL {driver.currentSpectrum.header.setItMods(*$3);DEL($3);}
            | K_LOCUS T_EQUALS V_STRING T_EOL {driver.currentSpectrum.header.setLocus(*$3);DEL($3);}
            | K_PEPMASS T_EQUALS number T_EOL {driver.currentSpectrum.header.setPepMass($3,0);}
            | K_PEPMASS T_EQUALS number number T_EOL {driver.currentSpectrum.header.setPepMass($3,$4);}
            | K_RAWFILE T_EQUALS V_STRING T_EOL {driver.currentSpectrum.header.setRawFile(*$3);DEL($3);}
            | K_RAWSCANS T_EQUALS raw T_EOL {driver.currentSpectrum.header.setRawScans($3.min,$3.max);}
            | K_RTINSECONDS T_EQUALS number_range T_EOL {driver.currentSpectrum.header.setRtinSeconds($3.min,$3.max);}
            | K_SCANS T_EQUALS number_range T_EOL {driver.currentSpectrum.header.setScans($3.min,$3.max);}
            | K_SEQ T_EQUALS string_list T_EOL {driver.currentSpectrum.header.setSeq(*$3);DEL($3);}
            | K_TAG T_EQUALS string_list T_EOL {driver.currentSpectrum.header.setTag(*$3);DEL($3);}
            | K_TITLE T_EQUALS title T_EOL {driver.currentSpectrum.header.setTitle(*$3);DEL($3);}
            | K_TOL T_EQUALS number T_EOL {driver.currentSpectrum.header.setTol($3);}
            | K_TOLU T_EQUALS V_STRING T_EOL {driver.currentSpectrum.header.setTolU(*$3);DEL($3);}
            | T_EOL
            ;

blockparams : /* empty */
            | blockparams blockparam
            ;


start : headerparams blocks T_END
      ;


%%
 
 
void mgf::Parser::error(const std::string &message)
{
   std::cerr<<"Error line "<<mgf_line_no<<" : "<<message<<std::endl;; 
}
 
/*Now that we have the Parser declared, we can declare the Scanner and implement the yylex function*/
#include <mgf/Scanner.hpp>
#include <mgf/Driver.hpp>
static int yylex( mgf::Parser::semantic_type *yylval,mgf::Scanner& scanner)
{
    return scanner.yylex(yylval);
}
