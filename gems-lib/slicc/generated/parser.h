/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     STRING = 259,
     NUMBER = 260,
     FLOATNUMBER = 261,
     LIT_BOOL = 262,
     VOID = 263,
     IMBED = 264,
     IMBED_TYPE = 265,
     CHIP = 266,
     THIS = 267,
     ASSIGN = 268,
     DOUBLE_COLON = 269,
     DOT = 270,
     SEMICOLON = 271,
     COLON = 272,
     GLOBAL_DECL = 273,
     MACHINE_DECL = 274,
     IN_PORT_DECL = 275,
     OUT_PORT_DECL = 276,
     PEEK = 277,
     ENQUEUE = 278,
     COPY_HEAD = 279,
     CHECK_ALLOCATE = 280,
     CHECK_STOP_SLOTS = 281,
     DEBUG_EXPR_TOKEN = 282,
     DEBUG_MSG_TOKEN = 283,
     ACTION_DECL = 284,
     TRANSITION_DECL = 285,
     TYPE_DECL = 286,
     STRUCT_DECL = 287,
     EXTERN_TYPE_DECL = 288,
     ENUM_DECL = 289,
     TYPE_FIELD = 290,
     OTHER = 291,
     IF = 292,
     ELSE = 293,
     RETURN = 294,
     EQ = 295,
     NE = 296,
     LE = 297,
     GE = 298,
     NOT = 299,
     AND = 300,
     OR = 301,
     PLUS = 302,
     DASH = 303,
     STAR = 304,
     SLASH = 305,
     RIGHTSHIFT = 306,
     LEFTSHIFT = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 77 "parser/parser.y"

  string* str_ptr;
  Vector<string>* string_vector_ptr; 

  // Decls
  DeclAST* decl_ptr;
  DeclListAST* decl_list_ptr;
  Vector<DeclAST*>* decl_vector_ptr; 
  
  // TypeField
  TypeFieldAST* type_field_ptr;
  Vector<TypeFieldAST*>* type_field_vector_ptr;
  
  // Type
  TypeAST* type_ptr;
  Vector<TypeAST*>* type_vector_ptr;

  // Formal Params
  FormalParamAST* formal_param_ptr;
  Vector<FormalParamAST*>* formal_param_vector_ptr;

  // Statements
  StatementAST* statement_ptr;
  StatementListAST* statement_list_ptr;
  Vector<StatementAST*>* statement_vector_ptr; 

  // Pairs
  PairAST* pair_ptr;
  PairListAST* pair_list_ptr;

  // Expressions
  VarExprAST* var_expr_ptr;
  ExprAST* expr_ptr;
  Vector<ExprAST*>* expr_vector_ptr; 



/* Line 2068 of yacc.c  */
#line 140 "generated/parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


