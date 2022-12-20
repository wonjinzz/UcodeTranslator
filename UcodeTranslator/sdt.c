#include "Scanner.c"

typedef struct nodeType {
	struct tokenType token;
	enum { terminal, nonterm } noderep;
	struct nodeType* son;        
	struct nodeType* brother;       
	struct nodeType* father;	
} Node;

char* nodeName[] = {	// get Parser.(nodeNumber in Parser.c)
   "ERROR_NODE",
   "ACTUAL_PARAM",	"ADD",			"ADD_ASSIGN",   "ARRAY_VAR",	"ASSIGN_OP",
   "BREAK_ST",		"CALL",			"CASE_ST",		"COMPOUND_ST",	"CONDITION_PART",
   "CONST_TYPE",	"CONTINUE_ST",  "DCL",			"DCL_ITEM",		"DCL_LIST",
   "DCL_SPEC",		"DEFAULT_ST",	"DIV",          "DIV_ASSIGN",	"DO_WHILE_ST" ,
   "EQ",	        "EXP_ST",		"FORMAL_PARA",  "FOR_ST",		"FUNC_DEF",
   "FUNC_HEAD",     "GE",           "GT",			"IDENT",		"IF_ELSE_ST",
   "IF_ST",			"INDEX",        "INIT_PART",    "INT_TYPE",		"LE",
   "LOGICAL_AND",	"LOGICAL_NOT",	"LOGICAL_OR",   "LT",			"MOD_ASSIGN",
   "MUL",			"MUL_ASSIGN",	"NE",	        "NUMBER",		"PARAM_DCL",
   "POST_DEC",		"POST_INC",		"POST_PART",    "PRE_DEC",		"PRE_INC",
   "PROGRAM",		"REMAINDER",    "RETURN_ST",	"SIMPLE_VAR",	"STAT_LIST",
   "SUB",			"SUB_ASSIGN",	"SWITCH_ST",	"UNARY_MINUS",  "VOID_TYPE",
   "WHILE_ST",
   "FUNC_TYPE"
};

void printNode(Node* pt, int indent);
void printTree(Node* pt, int indent);

void printTree(Node* pt, int indent)
{
	Node* p = pt;
	while (p != NULL) {
		printNode(p, indent);
		if (p->noderep == nonterm) printTree(p->son, indent + 5);
		p = p->brother;
	}
}

void printNode(Node* pt, int indent)
{
	extern FILE* astFile;
	int i;

	for (i = 1; i <= indent; i++) fprintf(astFile, " ");
	if (pt->noderep == terminal) {
		if (pt->token.number == tident)
			fprintf(astFile, " Terminal: %s", pt->token.value.id);
		else if (pt->token.number == tnumber)
			fprintf(astFile, " Terminal: %d", pt->token.value.num);
	}
	else { // nonterminal node
		i = (int)(pt->token.number);
		fprintf(astFile, " Nonterminal: %s", nodeName[i]);
	}
	fprintf(astFile, "\n");
}
