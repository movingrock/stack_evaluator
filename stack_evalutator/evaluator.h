#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <cstring>

#include "stack.h"

using namespace std;

class evaluator {
public:
	string read_expression();
	string convert_to_postfix(string s);
	double evaluate_postfix(string s);
};