#include "evaluator.h"
#include "node.h"
#include "node.cpp"
#include "stack.h"
#include "stack.cpp"

//엔터치기 전까지의 입력값을 받아 넘김
string evaluator::read_expression() {
	string str;

	cout << "infix 수식을 입력하세요(끝내려면 q나 Q를 입력하세요): ";
	getline(cin, str);
	return str;
}

//입력받은 infix수식을 postfix수식으로 변환함. 변수도 입력받음.
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
		else if (*iter == DECIMAL || isdigit(*iter) || isalpha(*iter)) {
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

	while (!operations->empty()) { //마지막에 스택에 쌓여있는 연산자를 빼내줌.
		output.push_back(operations->top());
		operations->pop();
	}
	return output;
}


// postfix string의 연산을 실행함. 변수를 입력받으면 변수에 넣을 값을 물어봄.
double evaluator::evaluate_postfix(string s) {
	const char DECIMAL = '.';

	stack<double>* evaluator = new stack<double>();
	double result;
	for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
		if (*iter == DECIMAL || isdigit(*iter)) {
			evaluator->push(*iter -'0');
		}
		else if(isalpha(*iter)){
			double temp;
			cout << *iter <<"에 대입할 숫자를 입력하세요: ";
			cin >> temp;
			cin.ignore(); // cin 이후 버퍼를 비워줘야함. -> read_expression에서 getline으로 받았기때문
			evaluator->push(temp);
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