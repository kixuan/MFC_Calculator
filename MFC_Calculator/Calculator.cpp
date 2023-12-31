#include "pch.h"
#include "Calculator.h"

#include <stack>
#include <vector>
#include <string>
#include <cmath>
#define M_PI 3.14159265358979323846

//const int MAX_EXP_LEN = 100;			//最大表达式长度

using namespace std;

//绝对值符号个数的奇偶性
enum ABS_ODEVITY {
	ABS_ODD = 1,
	ABS_EVEN = 2,
};

//算术符号优先权等级
enum PRIO_LV {
	PRIO_LV0 = 0,
	PRIO_LV1 = 1,
	PRIO_LV2 = 2,
	PRIO_LV3 = 3,
	PRIO_LV4 = 4,
};


Calculator::Calculator() {				//构造函数，初始化成员变量

	result = 0.0;
	//cal_ErrorImfo = "";
}


//表达式自定义标准格式化
void Calculator::getFormat(string infix) {

	stdInfix = infix;

	//实现正负数
	//for (int i = 0; i < stdInfix.length(); i++) {					//string下标调用运算符时可能会导致类型溢出
	for (size_t i = 0; i < stdInfix.size(); i++) {					//string.size()返回size_type类型，避免下标运算时的类型溢出
		if (stdInfix[i] == '-' || stdInfix[i] == '+') {				//-x转换为0-x，+x转化为0+x
			if (i == 0) {
				stdInfix.insert(0, 1, '0');
			}
			else if (stdInfix[i - 1] == '(') {
				stdInfix.insert(i, 1, '0');
			}
		}
	}
}

//获取算术符号优先级
int Calculator::getPrior(char c) {

	if (c == '+' || c == '-') {
		return PRIO_LV1;
	}
	else if (c == '*' || c == '/') {
		return PRIO_LV2;
	}
	else if (c == '%' || c == '^' ) {
		return PRIO_LV3;
	}
	else if (c == '！' || c == 'S' || c == 'C' || c == 'T' || c == 'L') {
		return PRIO_LV4;
	}
	else {
		return PRIO_LV0;
	}
	//else { cout << c << "非法符号！" << endl; }
}

//后缀表达式转换
void Calculator::getPostfix() {

	int absNumeber = ABS_ODD;				//绝对值符号个数的奇偶性
	string tmp;

	//for (int i = 0; i < stdInfix.length(); i++) {
	for (size_t i = 0; i < stdInfix.size(); i++) {					//string.size()返回size_type类型，避免下标运算时的类型溢出
		tmp = "";
		switch (stdInfix[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
		case '!':
		case 'S': // sin
		case 'C': // cos
		case 'T': // tan
		case 'L': // log10
			if (symStack.empty() || symStack.top() == '(' || symStack.top() == '[' || symStack.top() == '{' || (symStack.top() == '|' && absNumeber == ABS_ODD)) {
				symStack.push(stdInfix[i]);
			}
			else {
				while (!symStack.empty() && (getPrior(symStack.top()) >= getPrior(stdInfix[i]))) {
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				symStack.push(stdInfix[i]);
			}
			break;
		case '|':
			if (absNumeber == ABS_ODD) {
				symStack.push(stdInfix[i]);
				absNumeber = ABS_EVEN;
			}
			else {
				while (!symStack.empty() && symStack.top() != '|') {
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				if (!symStack.empty() && symStack.top() == '|') {
					tmp += symStack.top();
					postfix.push_back(tmp);						//左绝对值符号'|'加入后缀表达式，用于绝对值的检测计算
					symStack.pop();
					absNumeber = ABS_ODD;
				}
			}
			break;
		case '(':
			symStack.push(stdInfix[i]);
			break;
		case ')':
			while (!symStack.empty() && symStack.top() != '(') {
				tmp += symStack.top();
				postfix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '(') {
				symStack.pop();							//将左括号出栈丢弃
			}
			break;
		default:
			if ((stdInfix[i] >= '0' && stdInfix[i] <= '9')) {
				tmp += stdInfix[i];
				while (i + 1 < stdInfix.length() && (stdInfix[i + 1] >= '0' && stdInfix[i + 1] <= '9' || stdInfix[i + 1] == '.')) {		//小数处理

					tmp += stdInfix[i + 1];			//是连续的数字，则追加
					i++;
				}
				if (tmp[tmp.length() - 1] == '.') {
					tmp += '0';						//将x.做x.0处理
				}
				postfix.push_back(tmp);
			}
			break;
		}//end switch
	}//end for

	//if(!symStack.empty()) {
	while (!symStack.empty()) {						//将栈中剩余符号加入后缀表达式
		tmp = "";
		tmp += symStack.top();
		postfix.push_back(tmp);
		symStack.pop();
	}
}

//获取运算结果
void Calculator::calResult() {

	string tmp;
	double number = 0;
	double op1 = 0.0, op2 = 0;

	for (int i = 0; i < postfix.size(); i++) {
		tmp = postfix[i];
		if (tmp[0] >= '0' && tmp[0] <= '9') {
			number = atof(tmp.c_str());
			figStack.push(number);
		}
		else if (postfix[i] == "+") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1 + op2);
		}
		else if (postfix[i] == "-") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1 - op2);
		}
		else if (postfix[i] == "*") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1 * op2);
		}
		else if (postfix[i] == "/") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			if (op2 != 0) {
				///除数不为0，未做处理，默认
			}
			figStack.push(op1 / op2);
		}
		else if (postfix[i] == "%") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(fmod(op1, op2));			//可进行小数求余
		}
		else if (postfix[i] == "^") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(pow(op1, op2));
		}
		else if (postfix[i] == "|") {
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(abs(op1));
		}
		else if (postfix[i] == "!") {
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			if (op1 > 0) {
				//阶乘数应大于；为小数时(转化为整数求阶)
				double factorial = 1;
				for (int i = 1; i <= op1; ++i)
				{
					factorial *= i;
				}
				op1 = factorial;
			}
			figStack.push(op1);
		}
		else if (postfix[i] == "S") {
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			op1 = op1 * M_PI / 180.0;
			double res = std::sin(op1);
			figStack.push(res);
		}
		else if (postfix[i] == "C") {
		if (!figStack.empty()) {
			op1 = figStack.top();
			figStack.pop();
		}
		op1 = op1 * M_PI / 180.0;
		double res = std::cos(op1);
		figStack.push(res);
		}
		else if (postfix[i] == "T") {
		if (!figStack.empty()) {
			op1 = figStack.top();
			figStack.pop();
		}
		op1 =op1 * M_PI / 180.0;
		double res = std::tan(op1);
		figStack.push(res);
		}
		else if (postfix[i] == "L") {
		if (!figStack.empty()) {
			op1 = figStack.top();
			figStack.pop();
		}
		figStack.push(log10(op1));
		}

	}//end for

	if (!figStack.empty()) {
		result = figStack.top();
	}
}


//计算方法
void Calculator::calculate(string infix) {
	getFormat(infix);			//表达式自定义标准格式化
	getPostfix();				//后缀表达式转换
	calResult();				//计算结果
}

//获取结果
double Calculator::getResult() {
	return result;
}

/*
//获取异常信息
string Calculator::getErrorImfo() {
	return cal_ErrorImfo;
}
*/