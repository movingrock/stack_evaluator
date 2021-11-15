#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <cstring>

#include "stack.h"

using namespace std;

// 수식을 받고 postfix로 전환후, 연산하는 클래스
class evaluator {
public:
	string read_expression(); //엔터치기 전까지의 입력값을 받아 넘김
	string convert_to_postfix(string s); //입력받은 infix수식을 postfix수식으로 변환함. 변수도 입력받음.
	double evaluate_postfix(string s); // postfix string의 연산을 실행함. 변수를 입력받으면 변수에 넣을 값을 물어봄.
};