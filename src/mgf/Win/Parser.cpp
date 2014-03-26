// A Bison parser, made by GNU Bison 3.0.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "Parser.cpp" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "Parser.hpp"

// User implementation prologue.

#line 51 "Parser.cpp" // lalr1.cc:406
// Unqualified %code blocks.
#line 45 "Parser.yy" // lalr1.cc:407

    #include <utility>
    #include <mgf/Driver.hpp>
    #include <mgf/Spectrum.hpp>
	/*Prototype for the yylex function*/
	static int yylex(mgf::Parser::semantic_type* yylval, mgf::Scanner& scanner);

    #define DEL(x) delete x; x=nullptr;

#line 63 "Parser.cpp" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 10 "Parser.yy" // lalr1.cc:473
namespace mgf {
#line 130 "Parser.cpp" // lalr1.cc:473

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
              // Fall through.
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
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
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
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

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
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, scanner));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYLHS.VALUE to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yylhs.value = yystack_[yylen - 1].value;
    else
      yylhs.value = yystack_[0].value;


    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 156 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=(yystack_[1].value.v_integer);}
#line 565 "Parser.cpp" // lalr1.cc:846
    break;

  case 3:
#line 157 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=-(yystack_[1].value.v_integer);}
#line 571 "Parser.cpp" // lalr1.cc:846
    break;

  case 4:
#line 158 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=(yystack_[0].value.v_integer);}
#line 577 "Parser.cpp" // lalr1.cc:846
    break;

  case 5:
#line 161 "Parser.yy" // lalr1.cc:846
    {auto l=MGF_NEW_INTEGER_LIST;l->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=l;}
#line 583 "Parser.cpp" // lalr1.cc:846
    break;

  case 6:
#line 162 "Parser.yy" // lalr1.cc:846
    {(yystack_[2].value.v_interger_list)->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=(yystack_[2].value.v_interger_list);(yystack_[2].value.v_interger_list)=nullptr;}
#line 589 "Parser.cpp" // lalr1.cc:846
    break;

  case 7:
#line 163 "Parser.yy" // lalr1.cc:846
    {(yystack_[2].value.v_interger_list)->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=(yystack_[2].value.v_interger_list);(yystack_[2].value.v_interger_list)=nullptr;}
#line 595 "Parser.cpp" // lalr1.cc:846
    break;

  case 8:
#line 166 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_double)=(yystack_[1].value.v_double);}
#line 601 "Parser.cpp" // lalr1.cc:846
    break;

  case 9:
#line 169 "Parser.yy" // lalr1.cc:846
    { (yystack_[2].value.v_double_list)->push_back((yystack_[0].value.v_double));(yylhs.value.v_double_list)=(yystack_[2].value.v_double_list);(yystack_[2].value.v_double_list)=nullptr;}
#line 607 "Parser.cpp" // lalr1.cc:846
    break;

  case 10:
#line 170 "Parser.yy" // lalr1.cc:846
    {auto l = MGF_NEW_DOUBLE_LIST;l->push_back((yystack_[0].value.v_double));(yylhs.value.v_double_list)=l;}
#line 613 "Parser.cpp" // lalr1.cc:846
    break;

  case 11:
#line 174 "Parser.yy" // lalr1.cc:846
    {(yystack_[2].value.v_interger_list)->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=(yystack_[2].value.v_interger_list);(yystack_[2].value.v_interger_list)=nullptr;}
#line 619 "Parser.cpp" // lalr1.cc:846
    break;

  case 12:
#line 175 "Parser.yy" // lalr1.cc:846
    {auto l = MGF_NEW_INTEGER_LIST;l->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=l;}
#line 625 "Parser.cpp" // lalr1.cc:846
    break;

  case 13:
#line 178 "Parser.yy" // lalr1.cc:846
    {(yystack_[2].value.v_string_list)->push_back(*(yystack_[0].value.v_string));(yylhs.value.v_string_list)=(yystack_[2].value.v_string_list);(yystack_[2].value.v_string_list)=nullptr;DEL((yystack_[0].value.v_string));}
#line 631 "Parser.cpp" // lalr1.cc:846
    break;

  case 14:
#line 179 "Parser.yy" // lalr1.cc:846
    {auto l = MGF_NEW_STRING_LIST;l->push_back(*(yystack_[0].value.v_string));(yylhs.value.v_string_list)=l;}
#line 637 "Parser.cpp" // lalr1.cc:846
    break;

  case 15:
#line 182 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_string)=(yystack_[0].value.v_string);(yystack_[0].value.v_string)=nullptr;}
#line 643 "Parser.cpp" // lalr1.cc:846
    break;

  case 16:
#line 183 "Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+=*(yystack_[0].value.v_string);DEL((yystack_[0].value.v_string));(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 649 "Parser.cpp" // lalr1.cc:846
    break;

  case 17:
#line 184 "Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+=std::to_string((yystack_[0].value.v_double));(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 655 "Parser.cpp" // lalr1.cc:846
    break;

  case 18:
#line 185 "Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+=",";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 661 "Parser.cpp" // lalr1.cc:846
    break;

  case 19:
#line 186 "Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+="+";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 667 "Parser.cpp" // lalr1.cc:846
    break;

  case 20:
#line 187 "Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+="-";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 673 "Parser.cpp" // lalr1.cc:846
    break;

  case 21:
#line 190 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_double)=(yystack_[0].value.v_integer);}
#line 679 "Parser.cpp" // lalr1.cc:846
    break;

  case 22:
#line 191 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_double)=(yystack_[0].value.v_double);}
#line 685 "Parser.cpp" // lalr1.cc:846
    break;

  case 23:
#line 194 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_d_range).min=(yystack_[0].value.v_double);(yylhs.value.v_d_range).max=-1;}
#line 691 "Parser.cpp" // lalr1.cc:846
    break;

  case 24:
#line 195 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_d_range).min=(yystack_[2].value.v_double);(yylhs.value.v_d_range).max=(yystack_[0].value.v_double);}
#line 697 "Parser.cpp" // lalr1.cc:846
    break;

  case 25:
#line 198 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_i_range).min=(yystack_[0].value.v_integer);(yylhs.value.v_i_range).max=-1;}
#line 703 "Parser.cpp" // lalr1.cc:846
    break;

  case 26:
#line 199 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_i_range).min=(yystack_[2].value.v_integer);(yylhs.value.v_i_range).max=(yystack_[0].value.v_integer);}
#line 709 "Parser.cpp" // lalr1.cc:846
    break;

  case 27:
#line 202 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=(yystack_[0].value.v_integer);}
#line 715 "Parser.cpp" // lalr1.cc:846
    break;

  case 28:
#line 203 "Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=-1;}
#line 721 "Parser.cpp" // lalr1.cc:846
    break;

  case 29:
#line 207 "Parser.yy" // lalr1.cc:846
    {driver.header.setAccession(*(yystack_[1].value.v_double_list));DEL((yystack_[1].value.v_double_list));}
#line 727 "Parser.cpp" // lalr1.cc:846
    break;

  case 30:
#line 208 "Parser.yy" // lalr1.cc:846
    {driver.header.setCharge(*(yystack_[1].value.v_interger_list));DEL((yystack_[1].value.v_interger_list));}
#line 733 "Parser.cpp" // lalr1.cc:846
    break;

  case 31:
#line 209 "Parser.yy" // lalr1.cc:846
    {driver.header.setCle(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 739 "Parser.cpp" // lalr1.cc:846
    break;

  case 32:
#line 210 "Parser.yy" // lalr1.cc:846
    {driver.header.setCom(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 745 "Parser.cpp" // lalr1.cc:846
    break;

  case 33:
#line 211 "Parser.yy" // lalr1.cc:846
    {driver.header.setComp(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 751 "Parser.cpp" // lalr1.cc:846
    break;

  case 34:
#line 212 "Parser.yy" // lalr1.cc:846
    {driver.header.setCutout(*(yystack_[1].value.v_interger_list));DEL((yystack_[1].value.v_interger_list));}
#line 757 "Parser.cpp" // lalr1.cc:846
    break;

  case 35:
#line 213 "Parser.yy" // lalr1.cc:846
    {driver.header.setDb(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 763 "Parser.cpp" // lalr1.cc:846
    break;

  case 36:
#line 214 "Parser.yy" // lalr1.cc:846
    {driver.header.setDecoy((yystack_[1].value.v_integer));}
#line 769 "Parser.cpp" // lalr1.cc:846
    break;

  case 37:
#line 215 "Parser.yy" // lalr1.cc:846
    {driver.header.setErrorTolerant((yystack_[1].value.v_integer));}
#line 775 "Parser.cpp" // lalr1.cc:846
    break;

  case 38:
#line 216 "Parser.yy" // lalr1.cc:846
    {driver.header.setFormat(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string))}
#line 781 "Parser.cpp" // lalr1.cc:846
    break;

  case 39:
#line 217 "Parser.yy" // lalr1.cc:846
    {driver.header.setFrames(*(yystack_[1].value.v_interger_list));DEL((yystack_[1].value.v_interger_list));}
#line 787 "Parser.cpp" // lalr1.cc:846
    break;

  case 40:
#line 218 "Parser.yy" // lalr1.cc:846
    {driver.header.setInstrument(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 793 "Parser.cpp" // lalr1.cc:846
    break;

  case 41:
#line 219 "Parser.yy" // lalr1.cc:846
    {driver.header.setItMods(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 799 "Parser.cpp" // lalr1.cc:846
    break;

  case 42:
#line 220 "Parser.yy" // lalr1.cc:846
    {driver.header.setItOl((yystack_[1].value.v_double));}
#line 805 "Parser.cpp" // lalr1.cc:846
    break;

  case 43:
#line 221 "Parser.yy" // lalr1.cc:846
    {driver.header.setItOlU(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 811 "Parser.cpp" // lalr1.cc:846
    break;

  case 44:
#line 222 "Parser.yy" // lalr1.cc:846
    {driver.header.setMass(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 817 "Parser.cpp" // lalr1.cc:846
    break;

  case 45:
#line 223 "Parser.yy" // lalr1.cc:846
    {driver.header.setMods(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 823 "Parser.cpp" // lalr1.cc:846
    break;

  case 46:
#line 224 "Parser.yy" // lalr1.cc:846
    {driver.header.setMultiSiteMods((yystack_[1].value.v_integer));}
#line 829 "Parser.cpp" // lalr1.cc:846
    break;

  case 47:
#line 225 "Parser.yy" // lalr1.cc:846
    {driver.header.setPepIsotopeError((yystack_[1].value.v_integer));}
#line 835 "Parser.cpp" // lalr1.cc:846
    break;

  case 48:
#line 226 "Parser.yy" // lalr1.cc:846
    {driver.header.setPfa((yystack_[1].value.v_integer));}
#line 841 "Parser.cpp" // lalr1.cc:846
    break;

  case 49:
#line 227 "Parser.yy" // lalr1.cc:846
    {driver.header.setPrecursor((yystack_[1].value.v_double));}
#line 847 "Parser.cpp" // lalr1.cc:846
    break;

  case 50:
#line 228 "Parser.yy" // lalr1.cc:846
    {driver.header.setQuantitation(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 853 "Parser.cpp" // lalr1.cc:846
    break;

  case 51:
#line 229 "Parser.yy" // lalr1.cc:846
    {driver.header.setRepport((yystack_[1].value.v_integer));}
#line 859 "Parser.cpp" // lalr1.cc:846
    break;

  case 52:
#line 230 "Parser.yy" // lalr1.cc:846
    {driver.header.setReptype(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 865 "Parser.cpp" // lalr1.cc:846
    break;

  case 53:
#line 231 "Parser.yy" // lalr1.cc:846
    {driver.header.setSearch(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 871 "Parser.cpp" // lalr1.cc:846
    break;

  case 54:
#line 232 "Parser.yy" // lalr1.cc:846
    {driver.header.setSeg((yystack_[1].value.v_double));}
#line 877 "Parser.cpp" // lalr1.cc:846
    break;

  case 55:
#line 233 "Parser.yy" // lalr1.cc:846
    {driver.header.setTaxonomy(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 883 "Parser.cpp" // lalr1.cc:846
    break;

  case 56:
#line 234 "Parser.yy" // lalr1.cc:846
    {driver.header.setTol((yystack_[1].value.v_double));}
#line 889 "Parser.cpp" // lalr1.cc:846
    break;

  case 57:
#line 235 "Parser.yy" // lalr1.cc:846
    {driver.header.setTolU(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 895 "Parser.cpp" // lalr1.cc:846
    break;

  case 58:
#line 236 "Parser.yy" // lalr1.cc:846
    {driver.header.setUser((yystack_[1].value.v_integer));}
#line 901 "Parser.cpp" // lalr1.cc:846
    break;

  case 59:
#line 237 "Parser.yy" // lalr1.cc:846
    {driver.header.setUserMail(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 907 "Parser.cpp" // lalr1.cc:846
    break;

  case 60:
#line 238 "Parser.yy" // lalr1.cc:846
    {driver.header.setUserName(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 913 "Parser.cpp" // lalr1.cc:846
    break;

  case 64:
#line 247 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.push((yystack_[2].value.v_double),(yystack_[1].value.v_double),0);}
#line 919 "Parser.cpp" // lalr1.cc:846
    break;

  case 65:
#line 248 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.push((yystack_[3].value.v_double),(yystack_[2].value.v_double),(yystack_[1].value.v_integer));}
#line 925 "Parser.cpp" // lalr1.cc:846
    break;

  case 68:
#line 255 "Parser.yy" // lalr1.cc:846
    {return MGF_END_IONS;}
#line 931 "Parser.cpp" // lalr1.cc:846
    break;

  case 69:
#line 256 "Parser.yy" // lalr1.cc:846
    {return MGF_END_IONS;}
#line 937 "Parser.cpp" // lalr1.cc:846
    break;

  case 73:
#line 264 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setCharge((yystack_[1].value.v_integer));}
#line 943 "Parser.cpp" // lalr1.cc:846
    break;

  case 74:
#line 265 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setComp(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 949 "Parser.cpp" // lalr1.cc:846
    break;

  case 75:
#line 266 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setEtag(*(yystack_[1].value.v_string_list));DEL((yystack_[1].value.v_string_list));}
#line 955 "Parser.cpp" // lalr1.cc:846
    break;

  case 76:
#line 267 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setInstrument(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 961 "Parser.cpp" // lalr1.cc:846
    break;

  case 77:
#line 268 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setItMods(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 967 "Parser.cpp" // lalr1.cc:846
    break;

  case 78:
#line 269 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setLocus(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 973 "Parser.cpp" // lalr1.cc:846
    break;

  case 79:
#line 270 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setPepMass((yystack_[1].value.v_double),0);}
#line 979 "Parser.cpp" // lalr1.cc:846
    break;

  case 80:
#line 271 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setPepMass((yystack_[2].value.v_double),(yystack_[1].value.v_double));}
#line 985 "Parser.cpp" // lalr1.cc:846
    break;

  case 81:
#line 272 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setRawFile(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 991 "Parser.cpp" // lalr1.cc:846
    break;

  case 82:
#line 273 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setRawScans((yystack_[1].value.v_i_range).min,(yystack_[1].value.v_i_range).max);}
#line 997 "Parser.cpp" // lalr1.cc:846
    break;

  case 83:
#line 274 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setRtinSeconds((yystack_[1].value.v_d_range).min,(yystack_[1].value.v_d_range).max);}
#line 1003 "Parser.cpp" // lalr1.cc:846
    break;

  case 84:
#line 275 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setScans((yystack_[1].value.v_d_range).min,(yystack_[1].value.v_d_range).max);}
#line 1009 "Parser.cpp" // lalr1.cc:846
    break;

  case 85:
#line 276 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setSeq(*(yystack_[1].value.v_string_list));DEL((yystack_[1].value.v_string_list));}
#line 1015 "Parser.cpp" // lalr1.cc:846
    break;

  case 86:
#line 277 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setTag(*(yystack_[1].value.v_string_list));DEL((yystack_[1].value.v_string_list));}
#line 1021 "Parser.cpp" // lalr1.cc:846
    break;

  case 87:
#line 278 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setTitle(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 1027 "Parser.cpp" // lalr1.cc:846
    break;

  case 88:
#line 279 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setTol((yystack_[1].value.v_double));}
#line 1033 "Parser.cpp" // lalr1.cc:846
    break;

  case 89:
#line 280 "Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setTolU(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 1039 "Parser.cpp" // lalr1.cc:846
    break;


#line 1043 "Parser.cpp" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
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
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
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

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
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
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
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
         yyla.  (However, yyla is currently not documented for users.)
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
            // Stay within bounds of both yycheck and yytname.
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


  const signed char Parser::yypact_ninf_ = -124;

  const signed char Parser::yytable_ninf_ = -1;

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

  const short int
  Parser::yypgoto_[] =
  {
    -124,  -123,  -124,    26,  -124,   176,   -83,  -124,   -60,     8,
    -124,  -124,  -124,  -124,    23,  -124,   206,  -124,  -124,  -124,
    -124
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,    80,    81,    77,    78,    85,   207,   221,   180,   216,
     214,   107,    36,     1,   181,   182,    74,    37,   183,   156,
       2
  };

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



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
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
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
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
    const unsigned int user_token_number_max_ = 311;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 10 "Parser.yy" // lalr1.cc:1156
} // mgf
#line 1660 "Parser.cpp" // lalr1.cc:1156
#line 293 "Parser.yy" // lalr1.cc:1157

 
 
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
'_m4eof'
_m4eof
'_m4eof'
_m4eof
