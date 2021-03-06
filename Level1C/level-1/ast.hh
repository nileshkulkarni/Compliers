
/*********************************************************************************************

                                cfglp : A CFG Language Processor
                                --------------------------------

           About:

           Implemented   by  Tanu  Kanvar (tanu@cse.iitb.ac.in) and Uday
           Khedker    (http://www.cse.iitb.ac.in/~uday)  for the courses
           cs302+cs306: Language  Processors  (theory and  lab)  at  IIT
           Bombay.

           Release  date  Jan  15, 2013.  Copyrights  reserved  by  Uday
           Khedker. This  implemenation  has been made  available purely
           for academic purposes without any warranty of any kind.

           Documentation (functionality, manual, and design) and related
           tools are  available at http://www.cse.iitb.ac.in/~uday/cfglp


***********************************************************************************************/

#ifndef AST_HH
#define AST_HH

#include<string>
#include <assert.h>



#define AST_SPACE "         "
#define AST_NODE_SPACE "            "
#define AST_CONDITION_SPACE "               "
#define GLOB_SPACE "\t"
using namespace std;

class Ast;

class Ast
{
protected:
	Data_Type node_data_type;
public:
	Ast();
	~Ast();

	virtual Data_Type get_data_type();
	virtual bool check_ast(int line);

	virtual void print_ast(ostream & file_buffer) = 0;
	virtual void print_value(Local_Environment & eval_env, ostream & file_buffer);

	virtual Eval_Result & get_value_of_evaluation(Local_Environment & eval_env);
	virtual void set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result);
	virtual Eval_Result & evaluate(Local_Environment & eval_env, ostream & file_buffer) = 0;
	
	virtual string generate_code(ostream &file_buffer,Symbol_Table local_symbol_table);

};






//////////////////////////////////////////////////////////////////////////////////////////////
class Assignment_Ast:public Ast
{
	Ast * lhs;
	Ast * rhs;

public:
	Assignment_Ast(Ast * temp_lhs, Ast * temp_rhs);
	~Assignment_Ast();

	Data_Type get_data_type();
	bool check_ast(int line);

	void print_ast(ostream & file_buffer);
	string generate_code(ostream &file_buffer,Symbol_Table local_symbol_table);
	Eval_Result & evaluate(Local_Environment & eval_env, ostream & file_buffer);
};









//////////////////////////////////////////////////////////////////////////////////////////////
class Name_Ast:public Ast
{
	string variable_name;
	Symbol_Table_Entry variable_symbol_entry;
	int get_position(Symbol_Table local_table);
public:
	Name_Ast(string & name, Symbol_Table_Entry & var_entry);
	~Name_Ast();

	Data_Type get_data_type();	
	void print_ast(ostream & file_buffer);
	string generate_code(ostream &file_buffer,Symbol_Table local_symbol_table);
	void print_value(Local_Environment & eval_env, ostream & file_buffer);
	Eval_Result & get_value_of_evaluation(Local_Environment & eval_env);
	void set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result);
	Eval_Result & evaluate(Local_Environment & eval_env, ostream & file_buffer);
	
};








////////////////////////////////////////////////////////////////////////////////////////////
class Goto_Ast:public Ast
{
	int bb;
	
public:
	Goto_Ast(int _bb);
	~Goto_Ast();

//	Data_Type get_data_type();
//	bool check_ast(int line);

	int get_bb();
	string generate_code(ostream &file_buffer,Symbol_Table local_symbol_table);
	void print_ast(ostream & file_buffer);

	Eval_Result & evaluate(Local_Environment & eval_env, ostream & file_buffer);
};











////////////////////////////////////////////////////////////////////////////////////////////
class IfElse_Ast:public Ast
{
	Ast * condition; //Condition Ast
	Goto_Ast * ifGoto;  //If GOTO STATEMENT
	Goto_Ast * elseGoto; //Else GOTO STATEMENT

public:
	IfElse_Ast(Ast * _condition , Goto_Ast * if_Goto, Goto_Ast * else_Goto);
	~IfElse_Ast();
	string generate_code(ostream &file_buffer,Symbol_Table local_symbol_table);
//	Data_Type get_data_type();
//	bool check_ast(int line);

	void print_ast(ostream & file_buffer);

	Eval_Result & evaluate(Local_Environment & eval_env, ostream & file_buffer);
};












////////////////////////////////////////////////////////////////////////////////////////////
class Expression_Ast:public Ast{
	
	
public:

	enum OperatorType{
		LE,
		GE,
		EQ,
		NE,
		LT,
		GT
	};
private:
	map<string,bool> reg_map;
	Ast *lhs;
	OperatorType op;
	Ast *rhs;
		
		
	
public:


	Expression_Ast(Ast * _lhs , Ast *  _rhs , OperatorType _op);
	~Expression_Ast();
	void set_reg_map(map<string, bool> m);
	Data_Type get_data_type();
	bool check_ast(int line);
	void initialise_reg_map();
	void print_ast(ostream & file_buffer);
	void printOperator(ostream & file_buffer,Expression_Ast::OperatorType op);
	void printOperator_gen_code(ostream & file_buffer,Expression_Ast::OperatorType op);
	string generate_code(ostream &file_buffer,Symbol_Table local_symbol_table);
	Eval_Result & evaluate(Local_Environment & eval_env, ostream & file_buffer);
	string get_free_reg();
};









//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Number_Ast:public Ast
{
	T constant;

public:
	Number_Ast(T number, Data_Type constant_data_type);
	~Number_Ast();

	Data_Type get_data_type();

	void print_ast(ostream & file_buffer);
	string generate_code(ostream &file_buffer,Symbol_Table local_symbol_table);
	Eval_Result & evaluate(Local_Environment & eval_env, ostream & file_buffer);
};




//////////////////////////////////////////////////////////////////////////////////////////////
class Return_Ast:public Ast
{

public:
	Return_Ast();
	~Return_Ast();

	void print_ast(ostream & file_buffer);
	string generate_code(ostream &file_buffer,Symbol_Table local_symbol_table);
	Eval_Result & evaluate(Local_Environment & eval_env, ostream & file_buffer);
};

#endif
