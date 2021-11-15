#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <cstring>

#include "stack.h"

using namespace std;

// ������ �ް� postfix�� ��ȯ��, �����ϴ� Ŭ����
class evaluator {
public:
	string read_expression(); //����ġ�� �������� �Է°��� �޾� �ѱ�
	string convert_to_postfix(string s); //�Է¹��� infix������ postfix�������� ��ȯ��. ������ �Է¹���.
	double evaluate_postfix(string s); // postfix string�� ������ ������. ������ �Է¹����� ������ ���� ���� ���.
};