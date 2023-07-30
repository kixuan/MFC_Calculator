#pragma once

#include <stack>
#include <vector>
#include <string>
#include <afxwin.h>   // MFC���ĺͱ�׼���
#include <afxeditbrowsectrl.h>   // CEdit �����ͷ�ļ�

using namespace std;


//��������
class Calculator
{
public:
	Calculator();
	void calculate(string infix);		//���㷽��
	void getFormat(string infix);		//���ʽ�Զ����׼��ʽ��
	int getPrior(char c);				//��ȡ�����������ȼ�
	void getPostfix();					//��׺���ʽת��
	void calResult();					//������
	double getResult();					//��ȡ���
	//string getErrorImfo();				//��ȡ�쳣��Ϣ
	string operatorSym;					//�������
	

private:
	vector<string> postfix;				//��׺���ʽ����
	stack<char> symStack;				//����ջ
	stack<double> figStack;				//����ջ
	string stdInfix;					//�Զ����׼��ʽ�����ʽ
	double result;						//���ռ�����
	//string cal_ErrorImfo;					//�������⴫���쳣��Ϣ
	int m_nSelectedRadioButtonID;  // �洢ѡ�еĵ�ѡ��ť�� ID
	CEdit m_editResult;            // �����ʾ�ı༭��ؼ�����
};

