#include "evaluator.h"
#include "node.h"
#include "node.cpp"
#include "stack.h"
#include "stack.cpp"

string evaluator::read_expression() {
	string str;

	cout << "infix 수식을 입력하세요(끝내려면 q나 Q를 입력하세요): ";
	getline(cin, str);
	return str;
}

string evaluator::convert_to_postfix(string s) {
	const char DECIMAL = '.';
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';

	stack<char>* operations = new stack<char>();
	string output;

	for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
		if (*iter == LEFT_PARENTHESIS) {
			operations->push(*iter);
		}
		else if (*iter == DECIMAL || isdigit(*iter)) {
			output.push_back(*iter);
		}
		else if (strchr("+-*/", *iter)) {
			if (operations->empty() == false && operations->top() != LEFT_PARENTHESIS && !(strchr("+-", operations->top()) && strchr("*/", *iter))) {
				output.push_back(operations->top());
				operations->pop();
				operations->push(*iter);
			}
			else {
				operations->push(*iter);
			}
		}
		else if (*iter == RIGHT_PARENTHESIS) {
			while (operations->top() != LEFT_PARENTHESIS) {
				output.push_back(operations->top());
				operations->pop();
			}
			operations->pop();
		}
	}

	while (!operations->empty()) {
		output.push_back(operations->top());
		operations->pop();
	}
	return output;
}


double evaluator::evaluate_postfix(string s) { //변수를 넘겨줬을 경우, 변수 값을 입력하게 해야됨. 무친
	const char DECIMAL = '.';

	stack<double>* evaluator = new stack<double>();
	double result;

	for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
		if (*iter == DECIMAL || isdigit(*iter)) {
			evaluator->push(*iter -'0');
		}
		else if (strchr("+-*/", *iter)) {
			double operand1, operand2;
			operand2 = evaluator->top();
			evaluator->pop();
			operand1 = evaluator->top();
			evaluator->pop();

			switch (*iter) {
			case '+':
				evaluator->push(operand1 + operand2);
				break;
			case '-':
				evaluator->push(operand1 - operand2);
				break;
			case '*':
				evaluator->push(operand1 * operand2);
				break;
			case '/':
				evaluator->push(operand1 / operand2);
				break;
			}
		}
	}

	result = evaluator->top();
	evaluator->pop();

	return result;
}