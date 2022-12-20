
typedef struct Information {
	int typeQualifier;
	int	typeSpecifier;
	int initialValue;
	int base;
	int offset;
	int width;
	char* id;
} Factor;

Factor symbolTable[1000]; // symbol table

int functFlag = 100;
int localFlag = 500;
int base = 1;
int offset = 1;
int temp = 0;

int initSymbolTable() { 
	temp = localFlag; 
	return 1; 
} // local flag is 500

int set() { 
	offset = 1; 
	base = 2; 
	return 1; 
}

int reset() { 
	temp += offset; 
	offset = 1; 
	return 1; 
}

int lookup(char* name) {
	for (int i = 0; i < 1000; i++) {
		if (symbolTable[i].id != NULL) {
			if (strcmp(symbolTable[i].id, name) == 0) { return i; }
		}
	}
	return 0;
}

int insert(char* name, int typeSpecifier, int typeQualifier, int base, int offset, int width, int initialValue)
{
	if (typeQualifier == FUNC_TYPE) {
		symbolTable[functFlag].typeQualifier = typeQualifier;
		symbolTable[functFlag].typeSpecifier = typeSpecifier;
		symbolTable[functFlag].initialValue = initialValue;
		symbolTable[functFlag].base = base;
		symbolTable[functFlag].offset = offset;
		symbolTable[functFlag].width = width;
		symbolTable[functFlag].id = name;
		functFlag++;
	}
	else {
		symbolTable[localFlag].typeQualifier = typeQualifier;
		symbolTable[localFlag].typeSpecifier = typeSpecifier;
		symbolTable[localFlag].initialValue = initialValue;
		symbolTable[localFlag].base = base;
		symbolTable[localFlag].offset = offset;
		symbolTable[localFlag].width = width;
		symbolTable[localFlag].id = name;
		localFlag++;
	}
	return 1;
}
