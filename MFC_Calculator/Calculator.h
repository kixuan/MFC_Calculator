#pragma once

#include <stack>
#include <vector>
#include <string>
#include <afxwin.h>   // MFC核心和标准组件
#include <afxeditbrowsectrl.h>   // CEdit 类相关头文件

using namespace std;


//计算器类
class Calculator
{
public:
	Calculator();
	void calculate(string infix);		//计算方法
	void getFormat(string infix);		//表达式自定义标准格式化
	int getPrior(char c);				//获取算术符号优先级
	void getPostfix();					//后缀表达式转换
	void calResult();					//计算结果
	double getResult();					//获取结果
	//string getErrorImfo();				//获取异常信息
	string operatorSym;					//运算符号
	

private:
	vector<string> postfix;				//后缀表达式向量
	stack<char> symStack;				//符号栈
	stack<double> figStack;				//数字栈
	string stdInfix;					//自定义标准格式化表达式
	double result;						//最终计算结果
	//string cal_ErrorImfo;					//用于向外传递异常信息
	int m_nSelectedRadioButtonID;  // 存储选中的单选按钮的 ID
	CEdit m_editResult;            // 结果显示的编辑框控件变量
};

