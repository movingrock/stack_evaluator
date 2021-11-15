#include "evaluator.h"
#include "node.h"
#include "stack.h"

int main(void) {
	while (true) {
		evaluator* eva = new evaluator();
		string infix = eva->read_expression();
		if (infix == "q" || infix == "Q") { break; }
		string postfix = eva->convert_to_postfix(infix);
		cout << "postfix: " << postfix << endl;
		cout << "연산 결과: " << eva->evaluate_postfix(postfix) << endl << endl;
		delete eva;
	}
	return 0;
}