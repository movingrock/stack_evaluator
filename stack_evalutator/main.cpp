#include "evaluator.h"
#include "node.h"
#include "node.cpp"
#include "stack.h"
#include "stack.cpp"

int main(void) {
	evaluator* eva = new evaluator();
	while (true) {
		string infix = eva->read_expression();
		if (infix == "q" || infix == "Q") { break; }
		string postfix = eva->convert_to_postfix(infix);
		cout << "postfix: " << postfix << endl;
		cout << "연산 결과: " << eva->evaluate_postfix(postfix) << endl << endl;
	}
	return 0;
}