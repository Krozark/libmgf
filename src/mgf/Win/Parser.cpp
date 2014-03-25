/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */

/* Line 283 of lalr1.cc  */
#line 38 "Parser.cpp"


#include "Parser.hpp"

/* User implementation prologue.  */

/* Line 289 of lalr1.cc  */
#line 46 "Parser.cpp"
/* Unqualified %code blocks.  */
/* Line 290 of lalr1.cc  */
#line 45 "Parser.yy"

    #include <utility>
    #include <mgf/Driver.hpp>
    #include <mgf/Spectrum.hpp>
	/*Prototype for the yylex function*/
	static int yylex(mgf::Parser::semantic_type* yylval, mgf::Scanner& scanner);

    #define DEL(x) delete x; x=nullptr;


/* Line 290 of lalr1.cc  */
#line 61 "Parser.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

/* Line 357 of lalr1.cc  */
#line 10 "Parser.yy"
namespace mgf {
/* Line 357 of lalr1.cc  */
#line 157 "Parser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (mgf::Scanner& scanner_yyarg, mgf::Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    YYUSE (yytype);
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    YYUSE (yytype);
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_.clear ();
    yysemantic_stack_.clear ();
    yylocation_stack_.clear ();
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, scanner);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 664 of lalr1.cc  */
#line 156 "Parser.yy"
    {(yyval.v_integer)=(yysemantic_stack_[(2) - (1)].v_integer);}
    break;

  case 3:
/* Line 664 of lalr1.cc  */
#line 157 "Parser.yy"
    {(yyval.v_integer)=-(yysemantic_stack_[(2) - (1)].v_integer);}
    break;

  case 4:
/* Line 664 of lalr1.cc  */
#line 158 "Parser.yy"
    {(yyval.v_integer)=(yysemantic_stack_[(1) - (1)].v_integer);}
    break;

  case 5:
/* Line 664 of lalr1.cc  */
#line 161 "Parser.yy"
    {auto l=MGF_NEW_INTEGER_LIST;l->push_back((yysemantic_stack_[(1) - (1)].v_integer));(yyval.v_interger_list)=l;}
    break;

  case 6:
/* Line 664 of lalr1.cc  */
#line 162 "Parser.yy"
    {(yysemantic_stack_[(3) - (1)].v_interger_list)->push_back((yysemantic_stack_[(3) - (3)].v_integer));(yyval.v_interger_list)=(yysemantic_stack_[(3) - (1)].v_interger_list);(yysemantic_stack_[(3) - (1)].v_interger_list)=nullptr;}
    break;

  case 7:
/* Line 664 of lalr1.cc  */
#line 163 "Parser.yy"
    {(yysemantic_stack_[(3) - (1)].v_interger_list)->push_back((yysemantic_stack_[(3) - (3)].v_integer));(yyval.v_interger_list)=(yysemantic_stack_[(3) - (1)].v_interger_list);(yysemantic_stack_[(3) - (1)].v_interger_list)=nullptr;}
    break;

  case 8:
/* Line 664 of lalr1.cc  */
#line 166 "Parser.yy"
    {(yyval.v_double)=(yysemantic_stack_[(3) - (2)].v_double);}
    break;

  case 9:
/* Line 664 of lalr1.cc  */
#line 169 "Parser.yy"
    { (yysemantic_stack_[(3) - (1)].v_double_list)->push_back((yysemantic_stack_[(3) - (3)].v_double));(yyval.v_double_list)=(yysemantic_stack_[(3) - (1)].v_double_list);(yysemantic_stack_[(3) - (1)].v_double_list)=nullptr;}
    break;

  case 10:
/* Line 664 of lalr1.cc  */
#line 170 "Parser.yy"
    {auto l = MGF_NEW_DOUBLE_LIST;l->push_back((yysemantic_stack_[(1) - (1)].v_double));(yyval.v_double_list)=l;}
    break;

  case 11:
/* Line 664 of lalr1.cc  */
#line 174 "Parser.yy"
    {(yysemantic_stack_[(3) - (1)].v_interger_list)->push_back((yysemantic_stack_[(3) - (3)].v_integer));(yyval.v_interger_list)=(yysemantic_stack_[(3) - (1)].v_interger_list);(yysemantic_stack_[(3) - (1)].v_interger_list)=nullptr;}
    break;

  case 12:
/* Line 664 of lalr1.cc  */
#line 175 "Parser.yy"
    {auto l = MGF_NEW_INTEGER_LIST;l->push_back((yysemantic_stack_[(1) - (1)].v_integer));(yyval.v_interger_list)=l;}
    break;

  case 13:
/* Line 664 of lalr1.cc  */
#line 178 "Parser.yy"
    {(yysemantic_stack_[(3) - (1)].v_string_list)->push_back(*(yysemantic_stack_[(3) - (3)].v_string));(yyval.v_string_list)=(yysemantic_stack_[(3) - (1)].v_string_list);(yysemantic_stack_[(3) - (1)].v_string_list)=nullptr;DEL((yysemantic_stack_[(3) - (3)].v_string));}
    break;

  case 14:
/* Line 664 of lalr1.cc  */
#line 179 "Parser.yy"
    {auto l = MGF_NEW_STRING_LIST;l->push_back(*(yysemantic_stack_[(1) - (1)].v_string));(yyval.v_string_list)=l;}
    break;

  case 15:
/* Line 664 of lalr1.cc  */
#line 182 "Parser.yy"
    {(yyval.v_string)=(yysemantic_stack_[(1) - (1)].v_string);(yysemantic_stack_[(1) - (1)].v_string)=nullptr;}
    break;

  case 16:
/* Line 664 of lalr1.cc  */
#line 183 "Parser.yy"
    {*(yysemantic_stack_[(2) - (1)].v_string)+=*(yysemantic_stack_[(2) - (2)].v_string);DEL((yysemantic_stack_[(2) - (2)].v_string));(yyval.v_string)=(yysemantic_stack_[(2) - (1)].v_string);(yysemantic_stack_[(2) - (1)].v_string)=nullptr;}
    break;

  case 17:
/* Line 664 of lalr1.cc  */
#line 184 "Parser.yy"
    {*(yysemantic_stack_[(2) - (1)].v_string)+=std::to_string((yysemantic_stack_[(2) - (2)].v_double));(yyval.v_string)=(yysemantic_stack_[(2) - (1)].v_string);(yysemantic_stack_[(2) - (1)].v_string)=nullptr;}
    break;

  case 18:
/* Line 664 of lalr1.cc  */
#line 185 "Parser.yy"
    {*(yysemantic_stack_[(2) - (1)].v_string)+=",";(yyval.v_string)=(yysemantic_stack_[(2) - (1)].v_string);(yysemantic_stack_[(2) - (1)].v_string)=nullptr;}
    break;

  case 19:
/* Line 664 of lalr1.cc  */
#line 186 "Parser.yy"
    {*(yysemantic_stack_[(2) - (1)].v_string)+="+";(yyval.v_string)=(yysemantic_stack_[(2) - (1)].v_string);(yysemantic_stack_[(2) - (1)].v_string)=nullptr;}
    break;

  case 20:
/* Line 664 of lalr1.cc  */
#line 187 "Parser.yy"
    {*(yysemantic_stack_[(2) - (1)].v_string)+="-";(yyval.v_string)=(yysemantic_stack_[(2) - (1)].v_string);(yysemantic_stack_[(2) - (1)].v_string)=nullptr;}
    break;

  case 21:
/* Line 664 of lalr1.cc  */
#line 190 "Parser.yy"
    {(yyval.v_double)=(yysemantic_stack_[(1) - (1)].v_integer);}
    break;

  case 22:
/* Line 664 of lalr1.cc  */
#line 191 "Parser.yy"
    {(yyval.v_double)=(yysemantic_stack_[(1) - (1)].v_double);}
    break;

  case 23:
/* Line 664 of lalr1.cc  */
#line 194 "Parser.yy"
    {(yyval.v_d_range).min=(yysemantic_stack_[(1) - (1)].v_double);(yyval.v_d_range).max=-1;}
    break;

  case 24:
/* Line 664 of lalr1.cc  */
#line 195 "Parser.yy"
    {(yyval.v_d_range).min=(yysemantic_stack_[(3) - (1)].v_double);(yyval.v_d_range).max=(yysemantic_stack_[(3) - (3)].v_double);}
    break;

  case 25:
/* Line 664 of lalr1.cc  */
#line 198 "Parser.yy"
    {(yyval.v_i_range).min=(yysemantic_stack_[(1) - (1)].v_integer);(yyval.v_i_range).max=-1;}
    break;

  case 26:
/* Line 664 of lalr1.cc  */
#line 199 "Parser.yy"
    {(yyval.v_i_range).min=(yysemantic_stack_[(3) - (1)].v_integer);(yyval.v_i_range).max=(yysemantic_stack_[(3) - (3)].v_integer);}
    break;

  case 27:
/* Line 664 of lalr1.cc  */
#line 202 "Parser.yy"
    {(yyval.v_integer)=(yysemantic_stack_[(1) - (1)].v_integer);}
    break;

  case 28:
/* Line 664 of lalr1.cc  */
#line 203 "Parser.yy"
    {(yyval.v_integer)=-1;}
    break;

  case 29:
/* Line 664 of lalr1.cc  */
#line 207 "Parser.yy"
    {driver.header.setAccession(*(yysemantic_stack_[(4) - (3)].v_double_list));DEL((yysemantic_stack_[(4) - (3)].v_double_list));}
    break;

  case 30:
/* Line 664 of lalr1.cc  */
#line 208 "Parser.yy"
    {driver.header.setCharge(*(yysemantic_stack_[(4) - (3)].v_interger_list));DEL((yysemantic_stack_[(4) - (3)].v_interger_list));}
    break;

  case 31:
/* Line 664 of lalr1.cc  */
#line 209 "Parser.yy"
    {driver.header.setCle(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 32:
/* Line 664 of lalr1.cc  */
#line 210 "Parser.yy"
    {driver.header.setCom(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 33:
/* Line 664 of lalr1.cc  */
#line 211 "Parser.yy"
    {driver.header.setComp(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 34:
/* Line 664 of lalr1.cc  */
#line 212 "Parser.yy"
    {driver.header.setCutout(*(yysemantic_stack_[(4) - (3)].v_interger_list));DEL((yysemantic_stack_[(4) - (3)].v_interger_list));}
    break;

  case 35:
/* Line 664 of lalr1.cc  */
#line 213 "Parser.yy"
    {driver.header.setDb(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 36:
/* Line 664 of lalr1.cc  */
#line 214 "Parser.yy"
    {driver.header.setDecoy((yysemantic_stack_[(4) - (3)].v_integer));}
    break;

  case 37:
/* Line 664 of lalr1.cc  */
#line 215 "Parser.yy"
    {driver.header.setErrorTolerant((yysemantic_stack_[(4) - (3)].v_integer));}
    break;

  case 38:
/* Line 664 of lalr1.cc  */
#line 216 "Parser.yy"
    {driver.header.setFormat(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string))}
    break;

  case 39:
/* Line 664 of lalr1.cc  */
#line 217 "Parser.yy"
    {driver.header.setFrames(*(yysemantic_stack_[(4) - (3)].v_interger_list));DEL((yysemantic_stack_[(4) - (3)].v_interger_list));}
    break;

  case 40:
/* Line 664 of lalr1.cc  */
#line 218 "Parser.yy"
    {driver.header.setInstrument(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 41:
/* Line 664 of lalr1.cc  */
#line 219 "Parser.yy"
    {driver.header.setItMods(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 42:
/* Line 664 of lalr1.cc  */
#line 220 "Parser.yy"
    {driver.header.setItOl((yysemantic_stack_[(4) - (3)].v_double));}
    break;

  case 43:
/* Line 664 of lalr1.cc  */
#line 221 "Parser.yy"
    {driver.header.setItOlU(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 44:
/* Line 664 of lalr1.cc  */
#line 222 "Parser.yy"
    {driver.header.setMass(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 45:
/* Line 664 of lalr1.cc  */
#line 223 "Parser.yy"
    {driver.header.setMods(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 46:
/* Line 664 of lalr1.cc  */
#line 224 "Parser.yy"
    {driver.header.setMultiSiteMods((yysemantic_stack_[(4) - (3)].v_integer));}
    break;

  case 47:
/* Line 664 of lalr1.cc  */
#line 225 "Parser.yy"
    {driver.header.setPepIsotopeError((yysemantic_stack_[(4) - (3)].v_integer));}
    break;

  case 48:
/* Line 664 of lalr1.cc  */
#line 226 "Parser.yy"
    {driver.header.setPfa((yysemantic_stack_[(4) - (3)].v_integer));}
    break;

  case 49:
/* Line 664 of lalr1.cc  */
#line 227 "Parser.yy"
    {driver.header.setPrecursor((yysemantic_stack_[(4) - (3)].v_double));}
    break;

  case 50:
/* Line 664 of lalr1.cc  */
#line 228 "Parser.yy"
    {driver.header.setQuantitation(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 51:
/* Line 664 of lalr1.cc  */
#line 229 "Parser.yy"
    {driver.header.setRepport((yysemantic_stack_[(4) - (3)].v_integer));}
    break;

  case 52:
/* Line 664 of lalr1.cc  */
#line 230 "Parser.yy"
    {driver.header.setReptype(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 53:
/* Line 664 of lalr1.cc  */
#line 231 "Parser.yy"
    {driver.header.setSearch(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 54:
/* Line 664 of lalr1.cc  */
#line 232 "Parser.yy"
    {driver.header.setSeg((yysemantic_stack_[(4) - (3)].v_double));}
    break;

  case 55:
/* Line 664 of lalr1.cc  */
#line 233 "Parser.yy"
    {driver.header.setTaxonomy(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 56:
/* Line 664 of lalr1.cc  */
#line 234 "Parser.yy"
    {driver.header.setTol((yysemantic_stack_[(4) - (3)].v_double));}
    break;

  case 57:
/* Line 664 of lalr1.cc  */
#line 235 "Parser.yy"
    {driver.header.setTolU(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 58:
/* Line 664 of lalr1.cc  */
#line 236 "Parser.yy"
    {driver.header.setUser((yysemantic_stack_[(3) - (2)].v_integer));}
    break;

  case 59:
/* Line 664 of lalr1.cc  */
#line 237 "Parser.yy"
    {driver.header.setUserMail(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 60:
/* Line 664 of lalr1.cc  */
#line 238 "Parser.yy"
    {driver.header.setUserName(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 64:
/* Line 664 of lalr1.cc  */
#line 247 "Parser.yy"
    {driver.currentSpectrum.push((yysemantic_stack_[(3) - (1)].v_double),(yysemantic_stack_[(3) - (2)].v_double),0);}
    break;

  case 65:
/* Line 664 of lalr1.cc  */
#line 248 "Parser.yy"
    {driver.currentSpectrum.push((yysemantic_stack_[(4) - (1)].v_double),(yysemantic_stack_[(4) - (2)].v_double),(yysemantic_stack_[(4) - (3)].v_integer));}
    break;

  case 68:
/* Line 664 of lalr1.cc  */
#line 255 "Parser.yy"
    {return MGF_END_IONS;}
    break;

  case 69:
/* Line 664 of lalr1.cc  */
#line 256 "Parser.yy"
    {return MGF_END_IONS;}
    break;

  case 73:
/* Line 664 of lalr1.cc  */
#line 264 "Parser.yy"
    {driver.currentSpectrum.header.setCharge((yysemantic_stack_[(4) - (3)].v_integer));}
    break;

  case 74:
/* Line 664 of lalr1.cc  */
#line 265 "Parser.yy"
    {driver.currentSpectrum.header.setComp(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 75:
/* Line 664 of lalr1.cc  */
#line 266 "Parser.yy"
    {driver.currentSpectrum.header.setEtag(*(yysemantic_stack_[(4) - (3)].v_string_list));DEL((yysemantic_stack_[(4) - (3)].v_string_list));}
    break;

  case 76:
/* Line 664 of lalr1.cc  */
#line 267 "Parser.yy"
    {driver.currentSpectrum.header.setInstrument(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 77:
/* Line 664 of lalr1.cc  */
#line 268 "Parser.yy"
    {driver.currentSpectrum.header.setItMods(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 78:
/* Line 664 of lalr1.cc  */
#line 269 "Parser.yy"
    {driver.currentSpectrum.header.setLocus(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 79:
/* Line 664 of lalr1.cc  */
#line 270 "Parser.yy"
    {driver.currentSpectrum.header.setPepMass((yysemantic_stack_[(4) - (3)].v_double),0);}
    break;

  case 80:
/* Line 664 of lalr1.cc  */
#line 271 "Parser.yy"
    {driver.currentSpectrum.header.setPepMass((yysemantic_stack_[(5) - (3)].v_double),(yysemantic_stack_[(5) - (4)].v_double));}
    break;

  case 81:
/* Line 664 of lalr1.cc  */
#line 272 "Parser.yy"
    {driver.currentSpectrum.header.setRawFile(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 82:
/* Line 664 of lalr1.cc  */
#line 273 "Parser.yy"
    {driver.currentSpectrum.header.setRawScans((yysemantic_stack_[(4) - (3)].v_i_range).min,(yysemantic_stack_[(4) - (3)].v_i_range).max);}
    break;

  case 83:
/* Line 664 of lalr1.cc  */
#line 274 "Parser.yy"
    {driver.currentSpectrum.header.setRtinSeconds((yysemantic_stack_[(4) - (3)].v_d_range).min,(yysemantic_stack_[(4) - (3)].v_d_range).max);}
    break;

  case 84:
/* Line 664 of lalr1.cc  */
#line 275 "Parser.yy"
    {driver.currentSpectrum.header.setScans((yysemantic_stack_[(4) - (3)].v_d_range).min,(yysemantic_stack_[(4) - (3)].v_d_range).max);}
    break;

  case 85:
/* Line 664 of lalr1.cc  */
#line 276 "Parser.yy"
    {driver.currentSpectrum.header.setSeq(*(yysemantic_stack_[(4) - (3)].v_string_list));DEL((yysemantic_stack_[(4) - (3)].v_string_list));}
    break;

  case 86:
/* Line 664 of lalr1.cc  */
#line 277 "Parser.yy"
    {driver.currentSpectrum.header.setTag(*(yysemantic_stack_[(4) - (3)].v_string_list));DEL((yysemantic_stack_[(4) - (3)].v_string_list));}
    break;

  case 87:
/* Line 664 of lalr1.cc  */
#line 278 "Parser.yy"
    {driver.currentSpectrum.header.setTitle(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;

  case 88:
/* Line 664 of lalr1.cc  */
#line 279 "Parser.yy"
    {driver.currentSpectrum.header.setTol((yysemantic_stack_[(4) - (3)].v_double));}
    break;

  case 89:
/* Line 664 of lalr1.cc  */
#line 280 "Parser.yy"
    {driver.currentSpectrum.header.setTolU(*(yysemantic_stack_[(4) - (3)].v_string));DEL((yysemantic_stack_[(4) - (3)].v_string));}
    break;


/* Line 664 of lalr1.cc  */
#line 940 "Parser.cpp"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
          }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -124;
  const short int
  Parser::yypact_[] =
  {
      -124,     0,     4,  -124,     2,    18,    30,    62,    71,    76,
      78,    82,    89,   101,   109,   110,   111,   112,   113,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   126,
     127,   130,   131,   132,   134,   135,  -124,    41,  -124,    63,
      46,   133,   128,   129,   136,   138,   139,   137,   142,   141,
     136,   143,   144,    61,   145,   146,   148,   151,   152,   153,
      79,   154,     1,   155,   156,    79,   157,    79,   158,   159,
     160,  -124,   140,   163,  -124,  -124,   162,  -124,     5,   107,
    -124,     3,   164,   173,  -124,    42,   174,   175,   177,   178,
     179,    57,   180,   181,   182,   183,   184,   185,   186,   187,
     188,  -124,  -124,   189,   190,  -124,  -124,   191,   192,   193,
     194,   195,   196,   197,   198,   199,  -124,  -124,    88,  -124,
      46,  -124,  -124,  -124,   133,   133,  -124,  -124,  -124,   200,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,    45,  -124,  -124,  -124,
    -124,  -124,  -124,   201,   150,   202,   203,   204,   205,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      79,  -124,    93,  -124,  -124,   133,   218,   219,   220,   221,
     222,    79,   223,   226,    79,    79,   219,   219,   225,    79,
     227,    28,   224,  -124,   228,   237,  -124,    60,   239,   240,
     241,    67,   242,    90,   243,   244,   245,   247,    68,    80,
    -124,    96,   248,   249,  -124,   250,  -124,  -124,  -124,  -124,
     233,  -124,  -124,  -124,  -124,   251,  -124,   246,  -124,    79,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
        62,    70,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    71,    58,     0,    10,     0,     4,
       5,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,    27,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    91,     0,    29,
       0,     2,     3,    30,     0,     0,    31,    32,    34,     0,
      33,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    59,    60,     0,     8,     9,     6,
       7,    11,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    92,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,    14,     0,     0,     0,
       0,     0,     0,    25,     0,    23,     0,     0,     0,     0,
      15,     0,     0,     0,    64,     0,    68,    73,    74,    75,
       0,    76,    77,    78,    79,     0,    81,     0,    82,     0,
      83,    84,    85,    86,    87,    19,    20,    18,    16,    17,
      88,    89,    65,    13,    80,    26,    24
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -124,  -123,  -124,    26,  -124,   176,   -83,  -124,   -60,     8,
    -124,  -124,  -124,  -124,    23,  -124,   206,  -124,  -124,  -124,
    -124
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,    80,    81,    77,    78,    85,   207,   221,   180,   216,
     214,   107,    36,     1,   181,   182,    74,    37,   183,   156,
       2
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       103,   159,   160,     3,    38,   110,   123,   112,   119,     4,
     124,   125,   120,   105,    39,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    40,    14,    15,    16,    17,    18,
      19,   224,    20,    21,    22,    23,    41,    24,    25,    26,
      79,    71,    27,    28,    72,   128,    29,    30,   162,   129,
      31,    73,    32,    33,    34,    35,   163,   101,   102,   106,
     135,   164,   204,   229,   129,   165,    75,   230,    42,   166,
     234,   242,   167,   168,    94,   230,   169,    43,   225,   101,
     102,   170,    44,   243,    45,   171,   172,   230,    46,   173,
     174,   101,   102,   175,   176,    47,   177,   178,   179,   244,
     245,   246,    76,   247,   202,   101,   102,    48,   101,   102,
     248,   121,   122,   218,   219,    49,    50,    51,    52,    53,
     201,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   211,    64,    65,   215,   215,    66,    67,    68,   222,
      69,    70,    82,    83,   157,    79,   158,   237,    84,    88,
      73,   235,    86,    87,    89,    90,   185,    92,    93,    95,
      96,   249,    97,    98,    99,   100,   117,   126,   104,   108,
     109,   111,   113,   114,   115,   118,   127,   130,   131,   256,
     132,   133,   134,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   217,   184,   203,     0,     0,   186,   187,
     188,   189,   161,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,     0,    91,   226,     0,     0,
       0,   227,   205,   206,   208,   209,   210,   212,   213,   220,
     228,   223,   231,   232,   233,   236,   238,   253,   240,   239,
     241,   250,   251,   252,   254,     0,     0,     0,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        60,   124,   125,     3,     0,    65,     3,    67,     3,     9,
       7,     8,     7,    12,    12,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     6,    25,    26,    27,    28,    29,
      30,     3,    32,    33,    34,    35,     6,    37,    38,    39,
      12,     0,    42,    43,     3,     3,    46,    47,     3,     7,
      50,    10,    52,    53,    54,    55,    11,    12,    13,    58,
       3,    16,   185,     3,     7,    20,     3,     7,     6,    24,
       3,     3,    27,    28,    13,     7,    31,     6,   201,    12,
      13,    36,     6,     3,     6,    40,    41,     7,     6,    44,
      45,    12,    13,    48,    49,     6,    51,    52,    53,     3,
       4,     5,    56,     7,    11,    12,    13,     6,    12,    13,
      14,     4,     5,   196,   197,     6,     6,     6,     6,     6,
     180,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   191,     6,     6,   194,   195,     6,     6,     6,   199,
       6,     6,    14,    14,    56,    12,   120,    57,    12,    12,
      10,   211,    14,    14,    12,    14,     6,    14,    14,    14,
      14,   221,    14,    12,    12,    12,     3,     3,    14,    14,
      14,    14,    14,    14,    14,    13,     3,     3,     3,   239,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,   195,     3,   182,    -1,    -1,     6,     6,
       6,     6,    12,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,    -1,    -1,    50,     3,    -1,    -1,
      -1,     3,    14,    14,    14,    14,    14,    14,    12,    14,
       3,    14,     3,     3,     3,     3,     3,    14,     3,     5,
       3,     3,     3,     3,     3,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    72,    79,     3,     9,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    25,    26,    27,    28,    29,    30,
      32,    33,    34,    35,    37,    38,    39,    42,    43,    46,
      47,    50,    52,    53,    54,    55,    71,    76,     0,    12,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     0,     3,    10,    75,     3,    56,    62,    63,    12,
      60,    61,    14,    14,    12,    64,    14,    14,    12,    12,
      14,    64,    14,    14,    13,    14,    14,    14,    12,    12,
      12,    12,    13,    67,    14,    12,    58,    70,    14,    14,
      67,    14,    67,    14,    14,    14,    75,     3,    13,     3,
       7,     4,     5,     3,     7,     8,     3,     3,     3,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,    78,    56,    62,    60,
      60,    12,     3,    11,    16,    20,    24,    27,    28,    31,
      36,    40,    41,    44,    45,    48,    49,    51,    52,    53,
      67,    73,    74,    77,     3,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    67,    11,    73,    60,    14,    14,    65,    14,    14,
      14,    67,    14,    12,    69,    67,    68,    68,    65,    65,
      14,    66,    67,    14,     3,    60,     3,     3,     3,     3,
       7,     3,     3,     3,     3,    67,     3,    57,     3,     5,
       3,     3,     3,     3,     3,     4,     5,     7,    14,    67,
       3,     3,     3,    14,     3,    12,    67
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    34,    58,   311
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    59,    60,    60,    60,    61,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    79
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     2,     1,     1,     3,     3,     3,     3,
       1,     3,     1,     3,     1,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     3,     1,     3,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     4,
       4,     1,     0,     2,     3,     4,     2,     1,     6,     5,
       0,     2,     3,     4,     4,     4,     4,     4,     4,     4,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       1,     0,     2,     3
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"plus symbol\"", "\"minus symbol\"", "\"equals symbol\"",
  "\"coma symbol\"", "\"and\"", "\"USER token, USER00 to USER12\"",
  "\"BEGIN IONS token\"", "\"END IONS token\"", "\"integer\"",
  "\"double\"", "\"string\"",
  "\"ACCESSION keyword : Database entries to be searched. [List of double quoted, comma separated values]\"",
  "\"CHARGE keyword: Peptide charge. [8- to 8+ and combinations]\"",
  "\"CLE keyword: Enzyme. [Trypsin etc., as defined in enzymes file]\"",
  "\"COM keyword: Search title\"",
  "\"CUTOUT keyword: Precursor removal. [Pair of comma separated integers]\"",
  "\"COMP keyword: Amino acid composition\"",
  "\"DB keyword: Database. [As defined in mascot.dat]\"",
  "\"DECOY keyword: Perform decoy search. [0(default),1] \"",
  "\"ERRORTOLERANT keyword: error tolerant. [0(default),1]\"",
  "\"ETAG keyword: Error tolerant sequence tag.\"",
  "\"FORMAT keyword: MS/MS data file. [mgf(default),dta,asc,pkl,pks,bruker .xml, mzdata .xml,mzml]\"",
  "\"FRAMES keyword: NA translation. [Comma separated list of frames,Default is 1,2,3,4,5,6]\"",
  "\"INSTRUMENT keyword: MS/MS ion series. [ESI-QUAD-TOF etc., as defined in fragmentation_rules]\"",
  "\"IT_MODS keyword: Variable Mods. [As defined in unimod.xml]\"",
  "\"ITOL keyword:  Fragment ion tol. [Unit dependent]\"",
  "\"ITOLU keyword: Units for ITOL. [Da,mmu]\"",
  "\"LOCUS keyword: Hierarchical scan range identifier. [string]\"",
  "\"MASS keyword: Mono. or average. [Monoisotopic,Average]\"",
  "\"MODS keyword: Fixed Mods. [As defined in unimod.xml]\"",
  "\"MULTI_SITE_MODS keyword: Allow two modifications at a single site. [0(default),1]\"",
  "\"PEP_ISOTOPE_ERROR keyword: Misassigned 13C. [0 to 2]\"",
  "\"PEPMASS keyword: Peptide mass. [>100]\"",
  "\"PFA keyword: Partials. [0 to 9, default = 1]\"",
  "\"PRECURSOR keyword: Precursor m/z. [>100]\"",
  "\"QUANTITATION keyword: Quantitation method. [as defined in quantitation.xml]\"",
  "\"RAWFILE keyword: Raw file identifier. [string]\"",
  "\"RAWSCANS keyword: Native scan range identifiers. [a[:b]]\"",
  "\"REPORT keyword: Maximum hits. [auto or integer]\"",
  "\"REPTYPE keyword: Type of report. [protein,peptide (Default for MIS),archive,concise (Default for PMF),select,unassigned]\"",
  "\"RTINSECONDS keyword: Retention time or range (in seconds). [a[-b]]\"",
  "\"SCANS keyword: Scan number or range. [v[-w]]\"",
  "\"SEARCH keyword: Type of search. [PMF,SQ = MIS, MIS = SQ]\"",
  "\"SEG keyword: Protein mass (kDa) [empty or >0]\"",
  "\"SEQ keyword: Amino acid sequence. [A single query can have multiple SEQs]\"",
  "\"TAG keyword: Sequence tag. [A single query can have multiple TAGs]\"",
  "\"TAXONOMY keyword : Taxonomy. [As defined in taxonomy file]\"",
  "\"TITLE keyword: Query title. [Applies to a single spectrum]\"",
  "\"TOL keyword: Peptide mass tol. [Unit dependent]\"",
  "\"TOLU keyword : Units for TOL. [%,ppm,mmu,Da]\"",
  "\"USEREMAIL keyword: User email\"", "\"USERNAME keyword: User name\"",
  "'\"'", "':'", "\"AUTO\"", "$accept", "charge", "charge_list",
  "double_quoted", "double_quoted_list", "interger_list", "string_list",
  "string_st", "number", "number_range", "raw", "report_val",
  "headerparam", "headerparams", "ion", "ions", "block", "blocks",
  "blockparam", "blockparams", "start", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        79,     0,    -1,    12,     4,    -1,    12,     5,    -1,    12,
      -1,    60,    -1,    61,     7,    60,    -1,    61,     8,    60,
      -1,    56,    13,    56,    -1,    63,     7,    62,    -1,    62,
      -1,    64,     7,    12,    -1,    12,    -1,    65,     7,    14,
      -1,    14,    -1,    14,    -1,    66,    14,    -1,    66,    67,
      -1,    66,     7,    -1,    66,     4,    -1,    66,     5,    -1,
      12,    -1,    13,    -1,    67,    -1,    67,     5,    67,    -1,
      12,    -1,    12,    57,    12,    -1,    12,    -1,    58,    -1,
      15,     6,    63,     3,    -1,    16,     6,    61,     3,    -1,
      17,     6,    14,     3,    -1,    18,     6,    14,     3,    -1,
      20,     6,    14,     3,    -1,    19,     6,    64,     3,    -1,
      21,     6,    14,     3,    -1,    22,     6,    12,     3,    -1,
      23,     6,    12,     3,    -1,    25,     6,    14,     3,    -1,
      26,     6,    64,     3,    -1,    27,     6,    14,     3,    -1,
      28,     6,    14,     3,    -1,    29,     6,    13,     3,    -1,
      30,     6,    14,     3,    -1,    32,     6,    14,     3,    -1,
      33,     6,    14,     3,    -1,    34,     6,    12,     3,    -1,
      35,     6,    12,     3,    -1,    37,     6,    12,     3,    -1,
      38,     6,    67,     3,    -1,    39,     6,    14,     3,    -1,
      42,     6,    70,     3,    -1,    43,     6,    14,     3,    -1,
      46,     6,    14,     3,    -1,    47,     6,    67,     3,    -1,
      50,     6,    14,     3,    -1,    52,     6,    67,     3,    -1,
      53,     6,    14,     3,    -1,     9,    12,     3,    -1,    54,
       6,    14,     3,    -1,    55,     6,    14,     3,    -1,     3,
      -1,    -1,    72,    71,    -1,    67,    67,     3,    -1,    67,
      67,    60,     3,    -1,    74,    73,    -1,    73,    -1,    10,
       3,    78,    74,    11,     3,    -1,    10,     3,    78,    11,
       3,    -1,    -1,    76,    75,    -1,    76,     3,    75,    -1,
      16,     6,    60,     3,    -1,    20,     6,    14,     3,    -1,
      24,     6,    65,     3,    -1,    27,     6,    14,     3,    -1,
      28,     6,    14,     3,    -1,    31,     6,    14,     3,    -1,
      36,     6,    67,     3,    -1,    36,     6,    67,    67,     3,
      -1,    40,     6,    14,     3,    -1,    41,     6,    69,     3,
      -1,    44,     6,    68,     3,    -1,    45,     6,    68,     3,
      -1,    48,     6,    65,     3,    -1,    49,     6,    65,     3,
      -1,    51,     6,    66,     3,    -1,    52,     6,    67,     3,
      -1,    53,     6,    14,     3,    -1,     3,    -1,    -1,    78,
      77,    -1,    72,    76,     0,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    11,    13,    17,    21,    25,
      29,    31,    35,    37,    41,    43,    45,    48,    51,    54,
      57,    60,    62,    64,    66,    70,    72,    76,    78,    80,
      85,    90,    95,   100,   105,   110,   115,   120,   125,   130,
     135,   140,   145,   150,   155,   160,   165,   170,   175,   180,
     185,   190,   195,   200,   205,   210,   215,   220,   225,   229,
     234,   239,   241,   242,   245,   249,   254,   257,   259,   266,
     272,   273,   276,   280,   285,   290,   295,   300,   305,   310,
     315,   321,   326,   331,   336,   341,   346,   351,   356,   361,
     366,   368,   369,   372
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   156,   156,   157,   158,   161,   162,   163,   166,   169,
     170,   174,   175,   178,   179,   182,   183,   184,   185,   186,
     187,   190,   191,   194,   195,   198,   199,   202,   203,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   242,   243,   247,   248,   251,   252,   255,   256,
     259,   260,   261,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   284,   285,   289
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    58
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 278;
  const int Parser::yynnts_ = 21;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 38;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 59;

  const unsigned int Parser::yyuser_token_number_max_ = 311;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

/* Line 1135 of lalr1.cc  */
#line 10 "Parser.yy"
} // mgf
/* Line 1135 of lalr1.cc  */
#line 1703 "Parser.cpp"
/* Line 1136 of lalr1.cc  */
#line 293 "Parser.yy"

 
 
void mgf::Parser::error(const mgf::Parser::location_type &loc,const std::string &message)
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
