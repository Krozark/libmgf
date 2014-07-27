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

#line 37 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "Parser.hpp"

// User implementation prologue.

#line 51 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:406
// Unqualified %code blocks.
#line 46 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:407

    #include <utility>
    #include <mgf/Driver.hpp>
    #include <mgf/Spectrum.hpp>
	/*Prototype for the yylex function*/
	static int yylex(mgf::Parser::semantic_type* yylval, mgf::Scanner& scanner);

    #define DEL(x) delete x; x=nullptr;

#line 63 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:407


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

#line 10 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:473
namespace mgf {
#line 130 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:473

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
#line 158 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=(yystack_[1].value.v_integer);}
#line 565 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 3:
#line 159 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=-(yystack_[1].value.v_integer);}
#line 571 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 4:
#line 160 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=(yystack_[0].value.v_integer);}
#line 577 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 5:
#line 163 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {auto l=MGF_NEW_INTEGER_LIST;l->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=l;}
#line 583 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 6:
#line 164 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yystack_[2].value.v_interger_list)->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=(yystack_[2].value.v_interger_list);(yystack_[2].value.v_interger_list)=nullptr;}
#line 589 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 7:
#line 165 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yystack_[2].value.v_interger_list)->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=(yystack_[2].value.v_interger_list);(yystack_[2].value.v_interger_list)=nullptr;}
#line 595 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 8:
#line 168 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_double)=(yystack_[1].value.v_double);}
#line 601 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 9:
#line 171 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    { (yystack_[2].value.v_double_list)->push_back((yystack_[0].value.v_double));(yylhs.value.v_double_list)=(yystack_[2].value.v_double_list);(yystack_[2].value.v_double_list)=nullptr;}
#line 607 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 10:
#line 172 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {auto l = MGF_NEW_DOUBLE_LIST;l->push_back((yystack_[0].value.v_double));(yylhs.value.v_double_list)=l;}
#line 613 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 11:
#line 176 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yystack_[2].value.v_interger_list)->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=(yystack_[2].value.v_interger_list);(yystack_[2].value.v_interger_list)=nullptr;}
#line 619 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 12:
#line 177 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {auto l = MGF_NEW_INTEGER_LIST;l->push_back((yystack_[0].value.v_integer));(yylhs.value.v_interger_list)=l;}
#line 625 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 13:
#line 180 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_string)=(yystack_[0].value.v_string);(yystack_[0].value.v_string)=nullptr;}
#line 631 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 14:
#line 181 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+=*(yystack_[0].value.v_string);DEL((yystack_[0].value.v_string));(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 637 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 15:
#line 182 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+=std::to_string((yystack_[0].value.v_double));(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 643 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 16:
#line 183 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+="+";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 649 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 17:
#line 184 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+="-";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 655 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 18:
#line 187 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_string)=(yystack_[0].value.v_string);(yystack_[0].value.v_string)=nullptr;}
#line 661 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 19:
#line 188 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+=*(yystack_[0].value.v_string);DEL((yystack_[0].value.v_string));(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 667 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 20:
#line 189 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+=std::to_string((yystack_[0].value.v_double));(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 673 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 21:
#line 190 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+="+";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 679 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 22:
#line 191 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+="-";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 685 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 23:
#line 192 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+=",";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 691 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 24:
#line 193 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {*(yystack_[1].value.v_string)+="=";(yylhs.value.v_string)=(yystack_[1].value.v_string);(yystack_[1].value.v_string)=nullptr;}
#line 697 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 25:
#line 196 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yystack_[2].value.v_string_list)->push_back(*(yystack_[0].value.v_string));(yylhs.value.v_string_list)=(yystack_[2].value.v_string_list);(yystack_[2].value.v_string_list)=nullptr;DEL((yystack_[0].value.v_string));}
#line 703 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 26:
#line 197 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {auto l = MGF_NEW_STRING_LIST;l->push_back(*(yystack_[0].value.v_string));(yylhs.value.v_string_list)=l;}
#line 709 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 27:
#line 201 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_double)=(yystack_[0].value.v_integer);}
#line 715 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 28:
#line 202 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_double)=(yystack_[0].value.v_double);}
#line 721 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 29:
#line 205 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_d_range).min=(yystack_[0].value.v_double);(yylhs.value.v_d_range).max=-1;}
#line 727 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 30:
#line 206 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_d_range).min=(yystack_[2].value.v_double);(yylhs.value.v_d_range).max=(yystack_[0].value.v_double);}
#line 733 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 31:
#line 209 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_i_range).min=(yystack_[0].value.v_integer);(yylhs.value.v_i_range).max=-1;}
#line 739 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 32:
#line 210 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_i_range).min=(yystack_[2].value.v_integer);(yylhs.value.v_i_range).max=(yystack_[0].value.v_integer);}
#line 745 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 33:
#line 213 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=(yystack_[0].value.v_integer);}
#line 751 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 34:
#line 214 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {(yylhs.value.v_integer)=-1;}
#line 757 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 35:
#line 218 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setAccession(*(yystack_[1].value.v_double_list));DEL((yystack_[1].value.v_double_list));}
#line 763 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 36:
#line 219 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setCharge(*(yystack_[1].value.v_interger_list));DEL((yystack_[1].value.v_interger_list));}
#line 769 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 37:
#line 220 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setCle(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 775 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 38:
#line 221 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setCom(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 781 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 39:
#line 222 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setComp(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 787 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 40:
#line 223 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setCutout(*(yystack_[1].value.v_interger_list));DEL((yystack_[1].value.v_interger_list));}
#line 793 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 41:
#line 224 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setDb(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 799 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 42:
#line 225 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setDecoy((yystack_[1].value.v_integer));}
#line 805 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 43:
#line 226 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setErrorTolerant((yystack_[1].value.v_integer));}
#line 811 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 44:
#line 227 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setFormat(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string))}
#line 817 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 45:
#line 228 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setFrames(*(yystack_[1].value.v_interger_list));DEL((yystack_[1].value.v_interger_list));}
#line 823 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 46:
#line 229 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setInstrument(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 829 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 47:
#line 230 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setItMods(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 835 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 48:
#line 231 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setItOl((yystack_[1].value.v_double));}
#line 841 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 49:
#line 232 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setItOlU(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 847 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 50:
#line 233 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setMass(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 853 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 51:
#line 234 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setMods(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 859 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 52:
#line 235 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setMultiSiteMods((yystack_[1].value.v_integer));}
#line 865 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 53:
#line 236 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setPepIsotopeError((yystack_[1].value.v_integer));}
#line 871 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 54:
#line 237 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setPfa((yystack_[1].value.v_integer));}
#line 877 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 55:
#line 238 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setPrecursor((yystack_[1].value.v_double));}
#line 883 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 56:
#line 239 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setQuantitation(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 889 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 57:
#line 240 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setRepport((yystack_[1].value.v_integer));}
#line 895 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 58:
#line 241 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setReptype(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 901 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 59:
#line 242 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setSearch(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 907 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 60:
#line 243 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setSeg((yystack_[1].value.v_double));}
#line 913 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 61:
#line 244 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setTaxonomy(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 919 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 62:
#line 245 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setTol((yystack_[1].value.v_double));}
#line 925 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 63:
#line 246 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setTolU(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 931 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 64:
#line 247 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setUser((yystack_[1].value.v_integer));}
#line 937 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 65:
#line 248 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setUserMail(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 943 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 66:
#line 249 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.header.setUserName(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 949 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 70:
#line 258 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.push((yystack_[2].value.v_double),(yystack_[1].value.v_double),0);}
#line 955 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 71:
#line 259 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.push((yystack_[3].value.v_double),(yystack_[2].value.v_double),(yystack_[1].value.v_integer));}
#line 961 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 74:
#line 266 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {return MGF_END_IONS;}
#line 967 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 75:
#line 267 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {return MGF_END_IONS;}
#line 973 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 79:
#line 275 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setCharge((yystack_[1].value.v_integer));}
#line 979 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 80:
#line 276 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setComp(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 985 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 81:
#line 277 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setEtag(*(yystack_[1].value.v_string_list));DEL((yystack_[1].value.v_string_list));}
#line 991 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 82:
#line 278 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setInstrument(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 997 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 83:
#line 279 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setItMods(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 1003 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 84:
#line 280 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setLocus(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 1009 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 85:
#line 281 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setPepMass((yystack_[1].value.v_double),0);}
#line 1015 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 86:
#line 282 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setPepMass((yystack_[2].value.v_double),(yystack_[1].value.v_double));}
#line 1021 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 87:
#line 283 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setRawFile(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 1027 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 88:
#line 284 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setRawScans((yystack_[1].value.v_i_range).min,(yystack_[1].value.v_i_range).max);}
#line 1033 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 89:
#line 285 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setRtinSeconds((yystack_[1].value.v_d_range).min,(yystack_[1].value.v_d_range).max);}
#line 1039 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 90:
#line 286 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setScans((yystack_[1].value.v_d_range).min,(yystack_[1].value.v_d_range).max);}
#line 1045 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 91:
#line 287 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setSeq(*(yystack_[1].value.v_string_list));DEL((yystack_[1].value.v_string_list));}
#line 1051 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 92:
#line 288 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setTag(*(yystack_[1].value.v_string_list));DEL((yystack_[1].value.v_string_list));}
#line 1057 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 93:
#line 289 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setTitle(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 1063 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 94:
#line 290 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setTol((yystack_[1].value.v_double));}
#line 1069 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;

  case 95:
#line 291 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:846
    {driver.currentSpectrum.header.setTolU(*(yystack_[1].value.v_string));DEL((yystack_[1].value.v_string));}
#line 1075 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
    break;


#line 1079 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:846
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
    -124,     0,     4,  -124,     2,    18,    30,    62,    65,    71,
      89,   101,   111,   112,   113,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   126,   127,   130,   131,   132,
     134,   135,   136,   137,   138,   139,  -124,    41,  -124,    63,
      90,   141,   140,   142,   143,   144,   145,   148,   149,   150,
     143,   151,   152,   154,   155,   156,   157,   160,   161,   162,
      99,   163,     1,   164,   165,    99,   166,    99,   167,   168,
     169,  -124,   147,   146,  -124,  -124,   172,  -124,     5,   109,
    -124,     3,   173,   183,  -124,    42,   184,   185,   186,   187,
     188,    57,   189,   190,   191,   192,   193,   194,   195,   197,
     198,  -124,  -124,   199,   200,  -124,  -124,   201,   202,   203,
     204,   205,   206,   207,   208,   209,  -124,  -124,    92,  -124,
      90,  -124,  -124,  -124,   141,   141,  -124,  -124,  -124,   210,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,    45,  -124,  -124,  -124,
    -124,  -124,  -124,   211,   212,   213,   214,   215,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      99,  -124,    93,  -124,  -124,   141,   229,   230,   231,   232,
     233,    99,   234,   237,    99,    99,   230,   230,   236,    99,
     238,    28,   235,  -124,   239,   248,  -124,    70,    60,   250,
     251,   252,    67,   253,    94,   254,   158,   255,   256,    84,
      85,  -124,    96,   257,   258,  -124,   259,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,   230,  -124,  -124,  -124,  -124,
     260,  -124,   261,  -124,    99,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,    70,
    -124,  -124,  -124
  };

  const unsigned char
  Parser::yydefact_[] =
  {
      68,    76,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,    77,    64,     0,    10,     0,     4,
       5,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    97,     0,    35,
       0,     2,     3,    36,     0,     0,    37,    38,    40,     0,
      39,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    65,    66,     0,     8,     9,     6,
       7,    11,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,    98,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,    13,    26,     0,     0,
       0,     0,     0,     0,    31,     0,    29,     0,     0,     0,
       0,    18,     0,     0,     0,    70,     0,    74,    79,    80,
      16,    17,    14,    15,    81,     0,    82,    83,    84,    85,
       0,    87,     0,    88,     0,    89,    90,    91,    92,    93,
      21,    22,    24,    23,    19,    20,    94,    95,    71,    25,
      86,    32,    30
  };

  const short int
  Parser::yypgoto_[] =
  {
    -124,  -123,  -124,    48,  -124,   100,   -22,  -124,   -81,   -60,
     -20,  -124,  -124,  -124,  -124,    33,  -124,   196,  -124,  -124,
    -124,  -124
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,    80,    81,    77,    78,    85,   207,   222,   208,   180,
     217,   215,   107,    36,     1,   181,   182,    74,    37,   183,
     156,     2
  };

  const unsigned short int
  Parser::yytable_[] =
  {
     103,   159,   160,     3,    38,   110,   123,   112,   119,     4,
     124,   125,   120,   105,    39,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    40,    14,    15,    16,    17,    18,
      19,   225,    20,    21,    22,    23,    41,    24,    25,    26,
      79,    71,    27,    28,    72,   128,    29,    30,   162,   129,
      31,    73,    32,    33,    34,    35,   163,   101,   102,   106,
     135,   164,   204,   234,   129,   165,    75,   235,    42,   166,
     239,    43,   167,   168,   230,   231,   169,    44,   226,   101,
     102,   170,   101,   102,   232,   171,   172,   247,   248,   173,
     174,   235,   235,   175,   176,    45,   177,   178,   179,   249,
     250,   251,   252,   253,   202,   101,   102,    46,   101,   102,
     254,   101,   102,   121,   122,   219,   220,    47,    48,    49,
     201,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   212,    60,    61,   216,   216,    62,    63,    64,   223,
      65,    66,    67,    68,    69,    70,    76,   233,   157,   117,
      91,   242,   240,    79,    82,    84,    83,    73,    86,    87,
      88,    89,   255,   244,    90,    92,    93,    94,   158,    95,
      96,    97,    98,    99,   100,   218,   126,   104,   108,   109,
     111,   113,   114,   115,   262,   118,   127,   130,   131,   132,
     133,   134,   136,   137,   138,   139,   140,   141,   142,   233,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   259,   184,   203,     0,     0,   185,   186,
     187,   188,   161,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,     0,     0,     0,   227,     0,
       0,     0,   228,   205,   206,   209,   210,   211,   213,   214,
     221,   229,   224,   236,   237,   238,   241,   243,   245,   246,
     256,   257,   258,   260,     0,     0,     0,     0,   116,     0,
       0,     0,     0,   261
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
       3,     6,    27,    28,     4,     5,    31,     6,   201,    12,
      13,    36,    12,    13,    14,    40,    41,     3,     3,    44,
      45,     7,     7,    48,    49,     6,    51,    52,    53,     3,
       4,     5,     6,     7,    11,    12,    13,     6,    12,    13,
      14,    12,    13,     4,     5,   196,   197,     6,     6,     6,
     180,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   191,     6,     6,   194,   195,     6,     6,     6,   199,
       6,     6,     6,     6,     6,     6,    56,   207,    56,     3,
      50,    57,   212,    12,    14,    12,    14,    10,    14,    14,
      12,    12,   222,     5,    14,    14,    14,    13,   120,    14,
      14,    14,    12,    12,    12,   195,     3,    14,    14,    14,
      14,    14,    14,    14,   244,    13,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,   259,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,   235,     3,   182,    -1,    -1,     6,     6,
       6,     6,    12,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,    -1,    -1,    -1,     3,    -1,
      -1,    -1,     3,    14,    14,    14,    14,    14,    14,    12,
      14,     3,    14,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    12
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    73,    80,     3,     9,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    25,    26,    27,    28,    29,    30,
      32,    33,    34,    35,    37,    38,    39,    42,    43,    46,
      47,    50,    52,    53,    54,    55,    72,    77,     0,    12,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     0,     3,    10,    76,     3,    56,    62,    63,    12,
      60,    61,    14,    14,    12,    64,    14,    14,    12,    12,
      14,    64,    14,    14,    13,    14,    14,    14,    12,    12,
      12,    12,    13,    68,    14,    12,    58,    71,    14,    14,
      68,    14,    68,    14,    14,    14,    76,     3,    13,     3,
       7,     4,     5,     3,     7,     8,     3,     3,     3,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,    79,    56,    62,    60,
      60,    12,     3,    11,    16,    20,    24,    27,    28,    31,
      36,    40,    41,    44,    45,    48,    49,    51,    52,    53,
      68,    74,    75,    78,     3,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    68,    11,    74,    60,    14,    14,    65,    67,    14,
      14,    14,    68,    14,    12,    70,    68,    69,    69,    67,
      67,    14,    66,    68,    14,     3,    60,     3,     3,     3,
       4,     5,    14,    68,     3,     7,     3,     3,     3,     3,
      68,     3,    57,     3,     5,     3,     3,     3,     3,     3,
       4,     5,     6,     7,    14,    68,     3,     3,     3,    65,
       3,    12,    68
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    59,    60,    60,    60,    61,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     1,     3,     3,     3,     3,
       1,     3,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     4,     4,     1,     0,     2,
       3,     4,     2,     1,     6,     5,     0,     2,     3,     4,
       4,     4,     4,     4,     4,     4,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     0,     2,     3
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
  "double_quoted", "double_quoted_list", "interger_list", "string_st",
  "title", "string_list", "number", "number_range", "raw", "report_val",
  "headerparam", "headerparams", "ion", "ions", "block", "blocks",
  "blockparam", "blockparams", "start", YY_NULL
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   158,   158,   159,   160,   163,   164,   165,   168,   171,
     172,   176,   177,   180,   181,   182,   183,   184,   187,   188,
     189,   190,   191,   192,   193,   196,   197,   201,   202,   205,
     206,   209,   210,   213,   214,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   253,   254,
     258,   259,   262,   263,   266,   267,   270,   271,   272,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   295,   296,   300
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

#line 10 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:1156
} // mgf
#line 1699 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.cpp" // lalr1.cc:1156
#line 304 "C:\\Documents and Settings\\aaa\\Mes documents\\GitHub\\Harpe-client\\Qt\\..\\..\\libmgf\\src\\mgf\\Parser.yy" // lalr1.cc:1157

 
 
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
