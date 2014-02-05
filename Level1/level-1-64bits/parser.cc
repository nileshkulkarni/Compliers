// Generated by Bisonc++ V2.09.03 on Wed, 05 Feb 2014 12:54:22 +0530

// $insert class.ih
#include "parser.ih"

// The FIRST element of SR arrays shown below uses `d_type', defining the
// state's type, and `d_lastIdx' containing the last element's index. If
// d_lastIdx contains the REQ_TOKEN bitflag (see below) then the state needs
// a token: if in this state d_token__ is _UNDETERMINED_, nextToken() will be
// called

// The LAST element of SR arrays uses `d_token' containing the last retrieved
// token to speed up the (linear) seach.  Except for the first element of SR
// arrays, the field `d_action' is used to determine what to do next. If
// positive, it represents the next state (used with SHIFT); if zero, it
// indicates `ACCEPT', if negative, -d_action represents the number of the
// rule to reduce to.

// `lookup()' tries to find d_token__ in the current SR array. If it fails, and
// there is no default reduction UNEXPECTED_TOKEN__ is thrown, which is then
// caught by the error-recovery function.

// The error-recovery function will pop elements off the stack until a state
// having bit flag ERR_ITEM is found. This state has a transition on _error_
// which is applied. In this _error_ state, while the current token is not a
// proper continuation, new tokens are obtained by nextToken(). If such a
// token is found, error recovery is successful and the token is
// handled according to the error state's SR table and parsing continues.
// During error recovery semantic actions are ignored.

// A state flagged with the DEF_RED flag will perform a default
// reduction if no other continuations are available for the current token.

// The ACCEPT STATE never shows a default reduction: when it is reached the
// parser returns ACCEPT(). During the grammar
// analysis phase a default reduction may have been defined, but it is
// removed during the state-definition phase.

// So:
//      s_x[] = 
//      {
//                  [_field_1_]         [_field_2_]
//
// First element:   {state-type,        idx of last element},
// Other elements:  {required token,    action to perform},
//                                      ( < 0: reduce, 
//                                          0: ACCEPT,
//                                        > 0: next state)
// Last element:    {set to d_token__,    action to perform}
//      }

// When the --thread-safe option is specified, all static data are defined as
// const. If --thread-safe is not provided, the state-tables are not defined
// as const, since the lookup() function below will modify them


namespace // anonymous
{
    char const author[] = "Frank B. Brokken (f.b.brokken@rug.nl)";

    enum 
    {
        STACK_EXPANSION = 5     // size to expand the state-stack with when
                                // full
    };

    enum ReservedTokens
    {
        PARSE_ACCEPT     = 0,   // `ACCEPT' TRANSITION
        _UNDETERMINED_   = -2,
        _EOF_            = -1,
        _error_          = 256
    };
    enum StateType       // modify statetype/data.cc when this enum changes
    {
        NORMAL,
        ERR_ITEM,
        REQ_TOKEN,
        ERR_REQ,    // ERR_ITEM | REQ_TOKEN
        DEF_RED,    // state having default reduction
        ERR_DEF,    // ERR_ITEM | DEF_RED
        REQ_DEF,    // REQ_TOKEN | DEF_RED
        ERR_REQ_DEF // ERR_ITEM | REQ_TOKEN | DEF_RED
    };    
    struct PI__     // Production Info
    {
        size_t d_nonTerm; // identification number of this production's
                            // non-terminal 
        size_t d_size;    // number of elements in this production 
    };

    struct SR__     // Shift Reduce info, see its description above
    {
        union
        {
            int _field_1_;      // initializer, allowing initializations 
                                // of the SR s_[] arrays
            int d_type;
            int d_token;
        };
        union
        {
            int _field_2_;

            int d_lastIdx;          // if negative, the state uses SHIFT
            int d_action;           // may be negative (reduce), 
                                    // postive (shift), or 0 (accept)
            size_t d_errorState;    // used with Error states
        };
    };

    // $insert staticdata
    
// Productions Info Records:
PI__ const s_productionInfo[] = 
{
     {0, 0}, // not used: reduction values are negative
     {287, 4}, // 1: program ->  declaration_statement_list procedure_name #0001 procedure_body
     {290, 0}, // 2: #0001 ->  <empty>
     {287, 3}, // 3: program ->  procedure_name #0002 procedure_body
     {291, 0}, // 4: #0002 ->  <empty>
     {288, 3}, // 5: procedure_name (NAME) ->  NAME '(' ')'
     {289, 5}, // 6: procedure_body ('{') ->  '{' declaration_statement_list #0003 basic_block_list '}'
     {292, 0}, // 7: #0003 ->  <empty>
     {289, 3}, // 8: procedure_body ('{') ->  '{' basic_block_list '}'
     {293, 1}, // 9: declaration_statement_list ->  declaration_statement
     {293, 2}, // 10: declaration_statement_list ->  declaration_statement_list declaration_statement
     {294, 3}, // 11: declaration_statement (INTEGER) ->  INTEGER NAME ';'
     {295, 2}, // 12: basic_block_list ->  basic_block_list basic_block
     {295, 1}, // 13: basic_block_list ->  basic_block
     {296, 3}, // 14: basic_block (BASIC_BLOCK) ->  BASIC_BLOCK ':' executable_statement_list
     {297, 1}, // 15: executable_statement_list ->  assignment_statement_list
     {297, 3}, // 16: executable_statement_list (RETURN) ->  assignment_statement_list RETURN ';'
     {297, 2}, // 17: executable_statement_list ->  assignment_statement_list goto_statement
     {297, 2}, // 18: executable_statement_list ->  assignment_statement_list if_else_statement
     {298, 0}, // 19: assignment_statement_list ->  <empty>
     {298, 2}, // 20: assignment_statement_list ->  assignment_statement_list assignment_statement
     {299, 7}, // 21: if_else_statement (IF) ->  IF '(' expression ')' goto_statement ELSE goto_statement
     {300, 3}, // 22: goto_statement (GOTO) ->  GOTO BASIC_BLOCK ';'
     {301, 1}, // 23: atmoic_expression ->  variable
     {301, 1}, // 24: atmoic_expression ->  constant
     {302, 1}, // 25: relational_expression ->  atmoic_expression
     {302, 3}, // 26: relational_expression (GE) ->  relational_expression GE relational_expression
     {302, 3}, // 27: relational_expression (LE) ->  relational_expression LE relational_expression
     {302, 3}, // 28: relational_expression (LT) ->  relational_expression LT relational_expression
     {302, 3}, // 29: relational_expression (GT) ->  relational_expression GT relational_expression
     {303, 1}, // 30: equality_expression ->  relational_expression
     {303, 3}, // 31: equality_expression (EQ) ->  equality_expression EQ relational_expression
     {303, 3}, // 32: equality_expression (NE) ->  equality_expression NE relational_expression
     {304, 1}, // 33: expression ->  equality_expression
     {305, 4}, // 34: assignment_statement (ASSIGN_OP) ->  variable ASSIGN_OP expression ';'
     {306, 1}, // 35: variable (NAME) ->  NAME
     {307, 1}, // 36: constant (INTEGER_NUMBER) ->  INTEGER_NUMBER
     {308, 1}, // 37: program_$ ->  program
};

// State info and SR__ transitions for each state.


SR__ s_0[] =
{
    { { REQ_TOKEN}, { 7} },                              
    { {       287}, { 1} }, // program                   
    { {       293}, { 2} }, // declaration_statement_list
    { {       288}, { 3} }, // procedure_name            
    { {       294}, { 4} }, // declaration_statement     
    { {       258}, { 5} }, // NAME                      
    { {       260}, { 6} }, // INTEGER                   
    { {         0}, { 0} },                              
};

SR__ s_1[] =
{
    { { REQ_TOKEN}, {            2} }, 
    { {     _EOF_}, { PARSE_ACCEPT} }, 
    { {         0}, {            0} }, 
};

SR__ s_2[] =
{
    { { REQ_TOKEN}, { 5} },                         
    { {       288}, { 7} }, // procedure_name       
    { {       294}, { 8} }, // declaration_statement
    { {       258}, { 5} }, // NAME                 
    { {       260}, { 6} }, // INTEGER              
    { {         0}, { 0} },                         
};

SR__ s_3[] =
{
    { { DEF_RED}, {  2} },         
    { {     291}, {  9} }, // #0002
    { {       0}, { -4} },         
};

SR__ s_4[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -9} }, 
};

SR__ s_5[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        40}, { 10} }, // '('
    { {         0}, {  0} },       
};

SR__ s_6[] =
{
    { { REQ_TOKEN}, {  2} },        
    { {       258}, { 11} }, // NAME
    { {         0}, {  0} },        
};

SR__ s_7[] =
{
    { { DEF_RED}, {  2} },         
    { {     290}, { 12} }, // #0001
    { {       0}, { -2} },         
};

SR__ s_8[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -10} }, 
};

SR__ s_9[] =
{
    { { REQ_TOKEN}, {  3} },                  
    { {       289}, { 13} }, // procedure_body
    { {       123}, { 14} }, // '{'           
    { {         0}, {  0} },                  
};

SR__ s_10[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        41}, { 15} }, // ')'
    { {         0}, {  0} },       
};

SR__ s_11[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        59}, { 16} }, // ';'
    { {         0}, {  0} },       
};

SR__ s_12[] =
{
    { { REQ_TOKEN}, {  3} },                  
    { {       289}, { 17} }, // procedure_body
    { {       123}, { 14} }, // '{'           
    { {         0}, {  0} },                  
};

SR__ s_13[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -3} }, 
};

SR__ s_14[] =
{
    { { REQ_TOKEN}, {  7} },                              
    { {       293}, { 18} }, // declaration_statement_list
    { {       295}, { 19} }, // basic_block_list          
    { {       294}, {  4} }, // declaration_statement     
    { {       296}, { 20} }, // basic_block               
    { {       260}, {  6} }, // INTEGER                   
    { {       265}, { 21} }, // BASIC_BLOCK               
    { {         0}, {  0} },                              
};

SR__ s_15[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -5} }, 
};

SR__ s_16[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -11} }, 
};

SR__ s_17[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -1} }, 
};

SR__ s_18[] =
{
    { { REQ_DEF}, {  4} },                         
    { {     292}, { 22} }, // #0003                
    { {     294}, {  8} }, // declaration_statement
    { {     260}, {  6} }, // INTEGER              
    { {       0}, { -7} },                         
};

SR__ s_19[] =
{
    { { REQ_TOKEN}, {  4} },               
    { {       125}, { 23} }, // '}'        
    { {       296}, { 24} }, // basic_block
    { {       265}, { 21} }, // BASIC_BLOCK
    { {         0}, {  0} },               
};

SR__ s_20[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -13} }, 
};

SR__ s_21[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        58}, { 25} }, // ':'
    { {         0}, {  0} },       
};

SR__ s_22[] =
{
    { { REQ_TOKEN}, {  4} },                    
    { {       295}, { 26} }, // basic_block_list
    { {       296}, { 20} }, // basic_block     
    { {       265}, { 21} }, // BASIC_BLOCK     
    { {         0}, {  0} },                    
};

SR__ s_23[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -8} }, 
};

SR__ s_24[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -12} }, 
};

SR__ s_25[] =
{
    { { DEF_RED}, {   3} },                             
    { {     297}, {  27} }, // executable_statement_list
    { {     298}, {  28} }, // assignment_statement_list
    { {       0}, { -19} },                             
};

SR__ s_26[] =
{
    { { REQ_TOKEN}, {  4} },               
    { {       125}, { 29} }, // '}'        
    { {       296}, { 24} }, // basic_block
    { {       265}, { 21} }, // BASIC_BLOCK
    { {         0}, {  0} },               
};

SR__ s_27[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -14} }, 
};

SR__ s_28[] =
{
    { { REQ_DEF}, {   9} },                        
    { {     259}, {  30} }, // RETURN              
    { {     300}, {  31} }, // goto_statement      
    { {     299}, {  32} }, // if_else_statement   
    { {     305}, {  33} }, // assignment_statement
    { {     263}, {  34} }, // GOTO                
    { {     261}, {  35} }, // IF                  
    { {     306}, {  36} }, // variable            
    { {     258}, {  37} }, // NAME                
    { {       0}, { -15} },                        
};

SR__ s_29[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -6} }, 
};

SR__ s_30[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        59}, { 38} }, // ';'
    { {         0}, {  0} },       
};

SR__ s_31[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -17} }, 
};

SR__ s_32[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -18} }, 
};

SR__ s_33[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -20} }, 
};

SR__ s_34[] =
{
    { { REQ_TOKEN}, {  2} },               
    { {       265}, { 39} }, // BASIC_BLOCK
    { {         0}, {  0} },               
};

SR__ s_35[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        40}, { 40} }, // '('
    { {         0}, {  0} },       
};

SR__ s_36[] =
{
    { { REQ_TOKEN}, {  2} },             
    { {       264}, { 41} }, // ASSIGN_OP
    { {         0}, {  0} },             
};

SR__ s_37[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -35} }, 
};

SR__ s_38[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -16} }, 
};

SR__ s_39[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        59}, { 42} }, // ';'
    { {         0}, {  0} },       
};

SR__ s_40[] =
{
    { { REQ_TOKEN}, {  9} },                         
    { {       304}, { 43} }, // expression           
    { {       303}, { 44} }, // equality_expression  
    { {       302}, { 45} }, // relational_expression
    { {       301}, { 46} }, // atmoic_expression    
    { {       306}, { 47} }, // variable             
    { {       307}, { 48} }, // constant             
    { {       258}, { 37} }, // NAME                 
    { {       257}, { 49} }, // INTEGER_NUMBER       
    { {         0}, {  0} },                         
};

SR__ s_41[] =
{
    { { REQ_TOKEN}, {  9} },                         
    { {       304}, { 50} }, // expression           
    { {       303}, { 44} }, // equality_expression  
    { {       302}, { 45} }, // relational_expression
    { {       301}, { 46} }, // atmoic_expression    
    { {       306}, { 47} }, // variable             
    { {       307}, { 48} }, // constant             
    { {       258}, { 37} }, // NAME                 
    { {       257}, { 49} }, // INTEGER_NUMBER       
    { {         0}, {  0} },                         
};

SR__ s_42[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -22} }, 
};

SR__ s_43[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        41}, { 51} }, // ')'
    { {         0}, {  0} },       
};

SR__ s_44[] =
{
    { { REQ_DEF}, {   3} },      
    { {     266}, {  52} }, // EQ
    { {     267}, {  53} }, // NE
    { {       0}, { -33} },      
};

SR__ s_45[] =
{
    { { REQ_DEF}, {   5} },      
    { {     269}, {  54} }, // GE
    { {     268}, {  55} }, // LE
    { {     271}, {  56} }, // LT
    { {     270}, {  57} }, // GT
    { {       0}, { -30} },      
};

SR__ s_46[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -25} }, 
};

SR__ s_47[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -23} }, 
};

SR__ s_48[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -24} }, 
};

SR__ s_49[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -36} }, 
};

SR__ s_50[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        59}, { 58} }, // ';'
    { {         0}, {  0} },       
};

SR__ s_51[] =
{
    { { REQ_TOKEN}, {  3} },                  
    { {       300}, { 59} }, // goto_statement
    { {       263}, { 34} }, // GOTO          
    { {         0}, {  0} },                  
};

SR__ s_52[] =
{
    { { REQ_TOKEN}, {  7} },                         
    { {       302}, { 60} }, // relational_expression
    { {       301}, { 46} }, // atmoic_expression    
    { {       306}, { 47} }, // variable             
    { {       307}, { 48} }, // constant             
    { {       258}, { 37} }, // NAME                 
    { {       257}, { 49} }, // INTEGER_NUMBER       
    { {         0}, {  0} },                         
};

SR__ s_53[] =
{
    { { REQ_TOKEN}, {  7} },                         
    { {       302}, { 61} }, // relational_expression
    { {       301}, { 46} }, // atmoic_expression    
    { {       306}, { 47} }, // variable             
    { {       307}, { 48} }, // constant             
    { {       258}, { 37} }, // NAME                 
    { {       257}, { 49} }, // INTEGER_NUMBER       
    { {         0}, {  0} },                         
};

SR__ s_54[] =
{
    { { REQ_TOKEN}, {  7} },                         
    { {       302}, { 62} }, // relational_expression
    { {       301}, { 46} }, // atmoic_expression    
    { {       306}, { 47} }, // variable             
    { {       307}, { 48} }, // constant             
    { {       258}, { 37} }, // NAME                 
    { {       257}, { 49} }, // INTEGER_NUMBER       
    { {         0}, {  0} },                         
};

SR__ s_55[] =
{
    { { REQ_TOKEN}, {  7} },                         
    { {       302}, { 63} }, // relational_expression
    { {       301}, { 46} }, // atmoic_expression    
    { {       306}, { 47} }, // variable             
    { {       307}, { 48} }, // constant             
    { {       258}, { 37} }, // NAME                 
    { {       257}, { 49} }, // INTEGER_NUMBER       
    { {         0}, {  0} },                         
};

SR__ s_56[] =
{
    { { REQ_TOKEN}, {  7} },                         
    { {       302}, { 64} }, // relational_expression
    { {       301}, { 46} }, // atmoic_expression    
    { {       306}, { 47} }, // variable             
    { {       307}, { 48} }, // constant             
    { {       258}, { 37} }, // NAME                 
    { {       257}, { 49} }, // INTEGER_NUMBER       
    { {         0}, {  0} },                         
};

SR__ s_57[] =
{
    { { REQ_TOKEN}, {  7} },                         
    { {       302}, { 65} }, // relational_expression
    { {       301}, { 46} }, // atmoic_expression    
    { {       306}, { 47} }, // variable             
    { {       307}, { 48} }, // constant             
    { {       258}, { 37} }, // NAME                 
    { {       257}, { 49} }, // INTEGER_NUMBER       
    { {         0}, {  0} },                         
};

SR__ s_58[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -34} }, 
};

SR__ s_59[] =
{
    { { REQ_TOKEN}, {  2} },        
    { {       262}, { 66} }, // ELSE
    { {         0}, {  0} },        
};

SR__ s_60[] =
{
    { { REQ_DEF}, {   5} },      
    { {     269}, {  54} }, // GE
    { {     268}, {  55} }, // LE
    { {     271}, {  56} }, // LT
    { {     270}, {  57} }, // GT
    { {       0}, { -31} },      
};

SR__ s_61[] =
{
    { { REQ_DEF}, {   5} },      
    { {     269}, {  54} }, // GE
    { {     268}, {  55} }, // LE
    { {     271}, {  56} }, // LT
    { {     270}, {  57} }, // GT
    { {       0}, { -32} },      
};

SR__ s_62[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -26} }, 
};

SR__ s_63[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -27} }, 
};

SR__ s_64[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -28} }, 
};

SR__ s_65[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -29} }, 
};

SR__ s_66[] =
{
    { { REQ_TOKEN}, {  3} },                  
    { {       300}, { 67} }, // goto_statement
    { {       263}, { 34} }, // GOTO          
    { {         0}, {  0} },                  
};

SR__ s_67[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -21} }, 
};


// State array:
SR__ *s_state[] =
{
  s_0,  s_1,  s_2,  s_3,  s_4,  s_5,  s_6,  s_7,  s_8,  s_9,
  s_10,  s_11,  s_12,  s_13,  s_14,  s_15,  s_16,  s_17,  s_18,  s_19,
  s_20,  s_21,  s_22,  s_23,  s_24,  s_25,  s_26,  s_27,  s_28,  s_29,
  s_30,  s_31,  s_32,  s_33,  s_34,  s_35,  s_36,  s_37,  s_38,  s_39,
  s_40,  s_41,  s_42,  s_43,  s_44,  s_45,  s_46,  s_47,  s_48,  s_49,
  s_50,  s_51,  s_52,  s_53,  s_54,  s_55,  s_56,  s_57,  s_58,  s_59,
  s_60,  s_61,  s_62,  s_63,  s_64,  s_65,  s_66,  s_67,
};

} // anonymous namespace ends



// If the parsing function call uses arguments, then provide an overloaded
// function.  The code below doesn't rely on parameters, so no arguments are
// required.  Furthermore, parse uses a function try block to allow us to do
// ACCEPT and ABORT from anywhere, even from within members called by actions,
// simply throwing the appropriate exceptions.

ParserBase::ParserBase()
:
    d_stackIdx__(-1),
    // $insert debuginit
    d_debug__(false),
    d_nErrors__(0),
    // $insert requiredtokens
    d_requiredTokens__(0),
    d_acceptedTokens__(d_requiredTokens__),
    d_token__(_UNDETERMINED_),
    d_nextToken__(_UNDETERMINED_)
{}


void ParserBase::clearin()
{
    d_token__ = d_nextToken__ = _UNDETERMINED_;
}

void ParserBase::push__(size_t state)
{
    if (static_cast<size_t>(d_stackIdx__ + 1) == d_stateStack__.size())
    {
        size_t newSize = d_stackIdx__ + STACK_EXPANSION;
        d_stateStack__.resize(newSize);
        d_valueStack__.resize(newSize);
    }
    ++d_stackIdx__;
    d_stateStack__[d_stackIdx__] = d_state__ = state;
    *(d_vsp__ = &d_valueStack__[d_stackIdx__]) = d_val__;
}

void ParserBase::popToken__()
{
    d_token__ = d_nextToken__;

    d_val__ = d_nextVal__;
    d_nextVal__ = STYPE__();

    d_nextToken__ = _UNDETERMINED_;
}
     
void ParserBase::pushToken__(int token)
{
    d_nextToken__ = d_token__;
    d_nextVal__ = d_val__;
    d_token__ = token;
}
     
void ParserBase::pop__(size_t count)
{
    if (d_stackIdx__ < static_cast<int>(count))
    {
        ABORT();
    }

    d_stackIdx__ -= count;
    d_state__ = d_stateStack__[d_stackIdx__];
    d_vsp__ = &d_valueStack__[d_stackIdx__];
}

inline size_t ParserBase::top__() const
{
    return d_stateStack__[d_stackIdx__];
}

void Parser::executeAction(int production)
{
    if (d_token__ != _UNDETERMINED_)
        pushToken__(d_token__);     // save an already available token

                                    // save default non-nested block $$
    if (int size = s_productionInfo[production].d_size)
        d_val__ = d_vsp__[1 - size];

    switch (production)
    {
        // $insert actioncases
        
        case 1:
        {
         program_object.set_procedure_map(*current_procedure);
         if (d_vsp__[-3].symbol_table)
         d_vsp__[-3].symbol_table->global_list_in_proc_map_check(get_line_number());
         delete d_vsp__[-3].symbol_table;
         }
        break;

        case 2:
        d_val__ = d_vsp__[-1];
        {
         program_object.set_global_table(*d_vsp__[-1].symbol_table);
         return_statement_used_flag = false; 
         
         }
        break;

        case 3:
        {
         program_object.set_procedure_map(*current_procedure);
         }
        break;

        case 4:
        d_val__ = d_vsp__[0];
        {
         return_statement_used_flag = false; 
         }
        break;

        case 5:
        {
         current_procedure = new Procedure(void_data_type, *d_vsp__[-2].string_value);
         }
        break;

        case 6:
        {
         if (return_statement_used_flag == false)
         {
         int line = get_line_number();
         report_error("Atleast 1 basic block should have a return statement", line);
         }
         current_procedure->set_basic_block_list(*d_vsp__[-1].basic_block_list);
         
         if(current_procedure->check_for_undefined_blocks(bbNo,gotoNo)){
         ;
         } 
         else{
         ;
         } 
         delete d_vsp__[-1].basic_block_list;
         }
        break;

        case 7:
        d_val__ = d_vsp__[-1];
        {
         current_procedure->set_local_list(*d_vsp__[0].symbol_table);
         delete d_vsp__[0].symbol_table;
         }
        break;

        case 8:
        {
         if (return_statement_used_flag == false)
         {
         int line = get_line_number();
         report_error("Atleast 1 basic block should have a return statement", line);
         }
         current_procedure->set_basic_block_list(*d_vsp__[-1].basic_block_list);
         delete d_vsp__[-1].basic_block_list;
         }
        break;

        case 9:
        {
         int line = get_line_number();
         program_object.variable_in_proc_map_check(d_vsp__[0].symbol_entry->get_variable_name(), line);
         string var_name = d_vsp__[0].symbol_entry->get_variable_name();
         if (current_procedure && current_procedure->get_proc_name() == var_name)
         {
         int line = get_line_number();
         report_error("Variable name cannot be same as procedure name", line);
         }
         d_val__.symbol_table = new Symbol_Table();
         d_val__.symbol_table->push_symbol(d_vsp__[0].symbol_entry);
         }
        break;

        case 10:
        {
         
         
         int line = get_line_number();
         program_object.variable_in_proc_map_check(d_vsp__[0].symbol_entry->get_variable_name(), line);
         string var_name = d_vsp__[0].symbol_entry->get_variable_name();
         if (current_procedure && current_procedure->get_proc_name() == var_name)
         {
         int line = get_line_number();
         report_error("Variable name cannot be same as procedure name", line);
         }
         if (d_vsp__[-1].symbol_table != NULL)
         {
         if(d_vsp__[-1].symbol_table->variable_in_symbol_list_check(var_name))
         {
         int line = get_line_number();
         report_error("Variable is declared twice", line);
         }
         d_val__.symbol_table = d_vsp__[-1].symbol_table;
         }
         else
         d_val__.symbol_table = new Symbol_Table();
         d_val__.symbol_table->push_symbol(d_vsp__[0].symbol_entry);
         }
        break;

        case 11:
        {
         d_val__.symbol_entry = new Symbol_Table_Entry(*d_vsp__[-1].string_value, int_data_type);
         delete d_vsp__[-1].string_value;
         }
        break;

        case 12:
        {
         if (!d_vsp__[0].basic_block)
         {
         int line = get_line_number();
         report_error("Basic block doesn't exist", line);
         }
         bb_strictly_increasing_order_check(d_val__.basic_block_list, d_vsp__[0].basic_block->get_bb_number());
         d_val__.basic_block_list = d_vsp__[-1].basic_block_list;
         d_val__.basic_block_list->push_back(d_vsp__[0].basic_block);
         }
        break;

        case 13:
        {
         if (!d_vsp__[0].basic_block)
         {
         int line = get_line_number();
         report_error("Basic block doesn't exist", line);
         }
         
         d_val__.basic_block_list = new list<Basic_Block *>;
         d_val__.basic_block_list->push_back(d_vsp__[0].basic_block);
         
         }
        break;

        case 14:
        {
         
         if (d_vsp__[0].ast_list != NULL)
         d_val__.basic_block = new Basic_Block(d_vsp__[-2].integer_value, *d_vsp__[0].ast_list);
         else
         {
         list<Ast *> * ast_list = new list<Ast *>;
         d_val__.basic_block = new Basic_Block(d_vsp__[-2].integer_value, *ast_list);
         cout<<"lajfdlkajdfljalsdf"<<endl;
         }
         bbNo.insert(d_vsp__[-2].integer_value);
         }
        break;

        case 15:
        {
         d_val__.ast_list = d_vsp__[0].ast_list;;
         }
        break;

        case 16:
        {
         Ast * ret = new Return_Ast();
         return_statement_used_flag = true; 
         
         if (d_vsp__[-2].ast_list != NULL)
         d_val__.ast_list = d_vsp__[-2].ast_list;
         else
         d_val__.ast_list = new list<Ast *>;
         d_val__.ast_list->push_back(ret);
         }
        break;

        case 17:
        {
         
         if (d_vsp__[-1].ast_list != NULL)
         d_val__.ast_list = d_vsp__[-1].ast_list;
         else
         d_val__.ast_list = new list<Ast *>;
         d_val__.ast_list->push_back(d_vsp__[0].ast);
         
         }
        break;

        case 18:
        {
         if (d_vsp__[-1].ast_list != NULL)
         d_val__.ast_list = d_vsp__[-1].ast_list;
         else
         d_val__.ast_list = new list<Ast *>;
         d_val__.ast_list->push_back(d_vsp__[0].ast);
         }
        break;

        case 19:
        {
         d_val__.ast_list = NULL;
         }
        break;

        case 20:
        {
         if (d_vsp__[-1].ast_list == NULL)
         d_val__.ast_list = new list<Ast *>;
         else
         d_val__.ast_list = d_vsp__[-1].ast_list;
         d_val__.ast_list->push_back(d_vsp__[0].ast);
         
         }
        break;

        case 21:
        {
         d_val__.ast =new IfElse_Ast(d_vsp__[-4].ast,(Goto_Ast*)d_vsp__[-2].ast,(Goto_Ast*)d_vsp__[0].ast); 
         
         }
        break;

        case 22:
        {
         
         
         d_val__.ast = new Goto_Ast(d_vsp__[-1].integer_value);
         gotoNo.insert(d_vsp__[-1].integer_value);
         }
        break;

        case 23:
        {
         d_val__.ast = d_vsp__[0].ast;
        }
        break;

        case 24:
        {
         d_val__.ast = d_vsp__[0].ast;
         }
        break;

        case 25:
        {
         d_val__.ast = d_vsp__[0].ast;
         }
        break;

        case 26:
        {
         Ast* exp = new Expression_Ast(d_vsp__[-2].ast,d_vsp__[0].ast,Expression_Ast::OperatorType::GE ); 
         d_val__.ast = exp;
         }
        break;

        case 27:
        {
         Ast* exp = new Expression_Ast(d_vsp__[-2].ast,d_vsp__[0].ast,Expression_Ast::OperatorType::LE ); 
         d_val__.ast = exp;
         }
        break;

        case 28:
        {
         Ast* exp = new Expression_Ast(d_vsp__[-2].ast,d_vsp__[0].ast,Expression_Ast::OperatorType::LT ); 
         d_val__.ast = exp;
         }
        break;

        case 29:
        {
         Ast* exp = new Expression_Ast(d_vsp__[-2].ast,d_vsp__[0].ast,Expression_Ast::OperatorType::GT ); 
         d_val__.ast = exp;
         }
        break;

        case 30:
        {
         d_val__.ast =d_vsp__[0].ast;
         }
        break;

        case 31:
        {
         Ast* exp = new Expression_Ast(d_vsp__[-2].ast,d_vsp__[0].ast,Expression_Ast::OperatorType::EQ ); 
         d_val__.ast = exp;
         }
        break;

        case 32:
        {
         Ast* exp = new Expression_Ast(d_vsp__[-2].ast,d_vsp__[0].ast,Expression_Ast::OperatorType::NE ); 
         d_val__.ast = exp;
         }
        break;

        case 33:
        {
         d_val__.ast =d_vsp__[0].ast;
        }
        break;

        case 34:
        {
         d_val__.ast = new Assignment_Ast(d_vsp__[-3].ast, d_vsp__[-1].ast);
         int line = get_line_number();
         d_val__.ast->check_ast(line);
         }
        break;

        case 35:
        {
         Symbol_Table_Entry var_table_entry;
         if (current_procedure->variable_in_symbol_list_check(*d_vsp__[0].string_value))
         var_table_entry = current_procedure->get_symbol_table_entry(*d_vsp__[0].string_value);
         else if (program_object.variable_in_symbol_list_check(*d_vsp__[0].string_value))
         var_table_entry = program_object.get_symbol_table_entry(*d_vsp__[0].string_value);
         else
         {
         int line = get_line_number();
         report_error("Variable has not been declared", line);
         }
         d_val__.ast = new Name_Ast(*d_vsp__[0].string_value, var_table_entry);
         delete d_vsp__[0].string_value;
         }
        break;

        case 36:
        {
         d_val__.ast = new Number_Ast<int>(d_vsp__[0].integer_value, int_data_type);
         }
        break;

    }
}

inline void ParserBase::reduce__(PI__ const &pi)
{
    d_token__ = pi.d_nonTerm;
    pop__(pi.d_size);

}

// If d_token__ is _UNDETERMINED_ then if d_nextToken__ is _UNDETERMINED_ another
// token is obtained from lex(). Then d_nextToken__ is assigned to d_token__.
void Parser::nextToken()
{
    if (d_token__ != _UNDETERMINED_)        // no need for a token: got one
        return;                             // already

    if (d_nextToken__ != _UNDETERMINED_)
    {
        popToken__();                       // consume pending token
    }
    else
    {
        ++d_acceptedTokens__;               // accept another token (see
                                            // errorRecover())
        d_token__ = lex();
        if (d_token__ <= 0)
            d_token__ = _EOF_;
    }
    print();
}

// if the final transition is negative, then we should reduce by the rule
// given by its positive value. Note that the `recovery' parameter is only
// used with the --debug option
int Parser::lookup(bool recovery)
{
    // $insert threading
    SR__ *sr = s_state[d_state__];        // get the appropriate state-table
    int lastIdx = sr->d_lastIdx;        // sentinel-index in the SR__ array

    SR__ *lastElementPtr = sr + lastIdx;
    SR__ *elementPtr = sr + 1;            // start the search at s_xx[1]

    lastElementPtr->d_token = d_token__;// set search-token

    while (elementPtr->d_token != d_token__)
        ++elementPtr;

    if (elementPtr == lastElementPtr)   // reached the last element
    {
        if (elementPtr->d_action < 0)   // default reduction
        {
            return elementPtr->d_action;                
        }

        // No default reduction, so token not found, so error.
        throw UNEXPECTED_TOKEN__;
    }

    // not at the last element: inspect the nature of the action
    // (< 0: reduce, 0: ACCEPT, > 0: shift)

    int action = elementPtr->d_action;


    return action;
}

    // When an error has occurred, pop elements off the stack until the top
    // state has an error-item. If none is found, the default recovery
    // mode (which is to abort) is activated. 
    //
    // If EOF is encountered without being appropriate for the current state,
    // then the error recovery will fall back to the default recovery mode.
    // (i.e., parsing terminates)
void Parser::errorRecovery()
try
{
    if (d_acceptedTokens__ >= d_requiredTokens__)// only generate an error-
    {                                           // message if enough tokens 
        ++d_nErrors__;                          // were accepted. Otherwise
        error("Syntax error");                  // simply skip input

    }


    // get the error state
    while (not (s_state[top__()][0].d_type & ERR_ITEM))
    {
        pop__();
    }

    // In the error state, lookup a token allowing us to proceed.
    // Continuation may be possible following multiple reductions,
    // but eventuall a shift will be used, requiring the retrieval of
    // a terminal token. If a retrieved token doesn't match, the catch below 
    // will ensure the next token is requested in the while(true) block
    // implemented below:

    int lastToken = d_token__;                  // give the unexpected token a
                                                // chance to be processed
                                                // again.

    pushToken__(_error_);                       // specify _error_ as next token
    push__(lookup(true));                       // push the error state

    d_token__ = lastToken;                      // reactivate the unexpected
                                                // token (we're now in an
                                                // ERROR state).

    bool gotToken = true;                       // the next token is a terminal

    while (true)
    {
        try
        {
            if (s_state[d_state__]->d_type & REQ_TOKEN)
            {
                gotToken = d_token__ == _UNDETERMINED_;
                nextToken();                    // obtain next token
            }
            
            int action = lookup(true);

            if (action > 0)                 // push a new state
            {
                push__(action);
                popToken__();

                if (gotToken)
                {

                    d_acceptedTokens__ = 0;
                    return;
                }
            }
            else if (action < 0)
            {
                // no actions executed on recovery but save an already 
                // available token:
                if (d_token__ != _UNDETERMINED_)
                    pushToken__(d_token__);
 
                                            // next token is the rule's LHS
                reduce__(s_productionInfo[-action]); 
            }
            else
                ABORT();                    // abort when accepting during
                                            // error recovery
        }
        catch (...)
        {
            if (d_token__ == _EOF_)
                ABORT();                    // saw inappropriate _EOF_
                      
            popToken__();                   // failing token now skipped
        }
    }
}
catch (ErrorRecovery__)       // This is: DEFAULT_RECOVERY_MODE
{
    ABORT();
}

    // The parsing algorithm:
    // Initially, state 0 is pushed on the stack, and d_token__ as well as
    // d_nextToken__ are initialized to _UNDETERMINED_. 
    //
    // Then, in an eternal loop:
    //
    //  1. If a state does not have REQ_TOKEN no token is assigned to
    //     d_token__. If the state has REQ_TOKEN, nextToken() is called to
    //      determine d_nextToken__ and d_token__ is set to
    //     d_nextToken__. nextToken() will not call lex() unless d_nextToken__ is 
    //     _UNDETERMINED_. 
    //
    //  2. lookup() is called: 
    //     d_token__ is stored in the final element's d_token field of the
    //     state's SR_ array. 
    //
    //  3. The current token is looked up in the state's SR_ array
    //
    //  4. Depending on the result of the lookup() function the next state is
    //     shifted on the parser's stack, a reduction by some rule is applied,
    //     or the parsing function returns ACCEPT(). When a reduction is
    //     called for, any action that may have been defined for that
    //     reduction is executed.
    //
    //  5. An error occurs if d_token__ is not found, and the state has no
    //     default reduction. Error handling was described at the top of this
    //     file.

int Parser::parse()
try 
{
    push__(0);                              // initial state
    clearin();                              // clear the tokens.

    while (true)
    {
        try
        {
            if (s_state[d_state__]->d_type & REQ_TOKEN)
                nextToken();                // obtain next token


            int action = lookup(false);     // lookup d_token__ in d_state__

            if (action > 0)                 // SHIFT: push a new state
            {
                push__(action);
                popToken__();               // token processed
            }
            else if (action < 0)            // REDUCE: execute and pop.
            {
                executeAction(-action);
                                            // next token is the rule's LHS
                reduce__(s_productionInfo[-action]); 
            }
            else 
                ACCEPT();
        }
        catch (ErrorRecovery__)
        {
            errorRecovery();
        }
    }
}
catch (Return__ retValue)
{
    return retValue;
}

