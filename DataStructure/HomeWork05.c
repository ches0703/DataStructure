#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum {
	lparen, rparen, plus, minus, times,
	divide, mod, eos, operand
} precedence;
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

// Pstack
precedence Pstack[MAX_STACK_SIZE];
int Ptop = -1;
void Ppush(precedence item);
precedence Ppop();
// Stack
int stack[MAX_STACK_SIZE]; // global stack
int top = -1;
void push(int item);
int pop();
// Convert funtion
precedence get_token(char* expr, char* symbol, int* n); // return precedence
int eval(char* expr); // Calc postfix, return resulte
void postfix(char* expr, char* new_expr); // Convert infix -> postfix
char printToken(precedence token); // return precedence -> char

int main()
{
	char expr[MAX_EXPR_SIZE]; // Input string : infix
	char new_expr[MAX_EXPR_SIZE]; // Save : expr convert to postfix
	printf("Infix : ");
	scanf("%s", expr);
	printf("Infix to Postfix :\n");
	postfix(expr, new_expr);
	printf("\nPostfix : %s\n", new_expr);
	printf("Eval of Postfix :\n");
	printf("Eval = %d", eval(new_expr));
	
	return 0;

}
// stack funthion
void push(int item) {
	if (top < MAX_STACK_SIZE - 1) {
		stack[++top] = item;
	}
	else {
		printf("Stack is full...\n");
	}
}
int pop() {
	if (top < 0) {
		printf("It is empty...\n");
		return -1;
	}
	return stack[top--];
}

// Pstack funthion
void Ppush(precedence item) {
	if (Ptop < MAX_STACK_SIZE - 1) {
		Pstack[++Ptop] = item;
	}
	else {
		printf("Stack is full...\n");
	}
}
precedence Ppop() {
	if (Ptop < 0) {
		printf("It is empty...\n");
		return -1;
	}
	return Pstack[Ptop--];
}

// return precedence
precedence get_token(char* expr, char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}
}
// Calc postfix, return resulte
int eval(char* expr){
	char symbol;
	int  op1, op2;
	int  n = 0; // expr index
	top = -1;
	precedence token = get_token(expr ,&symbol, &n); 
	printf(" Token | Stack\t\t\t\t| Top\n");
	while (token != eos) {
		printf("   %c   | ", symbol);
		if (token == operand) { // Save operand
			push(symbol - '0');
		}
		else { // Save calc resulte
			op2 = pop();
			op1 = pop();
			switch (token) {
			case plus: push(op1 + op2); break;
			case minus: push(op1 - op2); break;
			case times: push(op1 * op2); break;
			case divide: push(op1 / op2); break;
			case mod: push(op1 % op2);
			}
		}
		
		for (int i = 0; i <= top; i++) {
			printf("[%2d] ", stack[i]);
		}
		for (int i = top; i < 4; i++) {
			printf("\t");
		}
		printf("| %2d\n", top);
		token = get_token(expr ,&symbol, &n);
	}
	return pop(); // resulte
}

// Convert infix -> postfix
void postfix(char* expr, char* new_expr){
	char symbol;
	precedence token;
	int n = 0; // expr index
	int index = 0; // new_expr index
	Ptop = 0;
	Pstack[0] = eos;
	printf(" Token | Stack\t\t\t\t| Top | Output\n");
	for (token = get_token(expr, &symbol, &n); token != eos;
		token = get_token(expr, &symbol, &n)) {
		if (token == operand) {
			new_expr[index++] = symbol;
		}
		else if (token == rparen) { // paren process
			while (Pstack[Ptop] != lparen) {
				new_expr[index++] = printToken(Ppop());
			}
			Ppop();
		}
		else {
			while (isp[Pstack[Ptop]] >= icp[token]) {
				new_expr[index++] = printToken(Ppop());
			}
			Ppush(token);
		}
		// Print Area : before expr not NULL
		printf("   %c   | ", symbol);
		for (int i = 0; i <= Ptop; i++) {
			printf("%c", printToken(Pstack[i]));
		}
		for (int i = Ptop; i < 29; i++) {
			printf(" ");
		}
		printf("  | ");
		printf("%2d", Ptop);
		printf("  | ");
		new_expr[index] = NULL;
		printf("%s\n", new_expr);
		
	}
	// Print Area : before Pstack empty
	while ((token = Ppop()) != eos) {
		symbol = printToken(token);
		new_expr[index++] = symbol;
		printf("   %c   | ", symbol);
		for (int i = 0; i <= Ptop; i++) {
			printf("%c", printToken(Pstack[i]));
		}
		for (int i = Ptop; i < 29; i++) {
			printf(" ");
		}
		printf("  | ");
		printf("%2d", Ptop);
		printf("  | ");
		new_expr[index] = NULL;
		printf("%s\n", new_expr);
	}
	// Print Last char : NULL
	printf("       | ");
	for (int i = Ptop + 1; i < 29; i++) {
		printf(" ");
	}
	printf("  | ");
	printf("%2d", Ptop);
	printf("  | ");
	new_expr[index] = NULL;
	printf("%s\n", new_expr);
}
// return precedence -> char
char printToken(precedence token) {
	switch (token) {
	case lparen: return '(';
	case rparen: return ')';
	case plus: return '+';
	case minus: return '-';
	case divide: return '/';
	case times: return '*';
	case mod: return '%';
	case eos: return '\0';
	default: return '\0';
	}
}