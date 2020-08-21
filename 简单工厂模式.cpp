#include <iostream>
#include <string>
using namespace std;
//抽象的产品类
class Operation
{
protected:
	double numberA;
	double numberB;
public:
	virtual double GetResult() {
		double result = 0.0;
		return result;
	}
	void SetNumberA(double number1) {
		numberA = number1;
		return;
	}
	void SetNumberB(double number2) {
		numberB = number2;
		return;
	}

};
//四种具体的产品类
class OperationAdd :public Operation 
{
public:
	double GetResult() {
		double result = 0.0;
		result = numberA + numberB;
		return result;
	}
};
class OperationSub : public Operation
{
public:
	double GetResult() {
		double result = 0;
		result = numberA - numberB;
		return result;
	}
};


class OperationMul : public Operation
{
public:
	double GetResult()
	{
		double result = 0;
		result = numberA * numberB;
		return result;
	}
};

class OperationDiv : public Operation
{
public:
	double GetResult()
	{
		double result = 0;
		if (numberB != 0)
		{
			result = numberA / numberB;
		}
		return result;
	}
};
//应该考虑用一个单独的类来做这个创造实例的过程，这就是工厂
class OperationFactory
{
public:
	static Operation* createOperate(char type)
	{
		Operation* oper = NULL;
		switch (type)
		{
		case '+':
			oper = new OperationAdd();
			break;
		case '-':
			oper = new OperationSub();
			break;
		case '*':
			oper = new OperationMul();
			break;
		case '/':
			oper = new OperationDiv();
			break;
		default:
			break;
		}
		return oper;
	}
};
//客户端代码
int main()
{
	Operation* oper;
	double strNumberA;
	double strNumberB;
	char type;
	cout << "请输入数字A" << endl;
	cin >> strNumberA;
	cout << "请输入数字B" << endl;
	cin >> strNumberB;
	cout << "请选择运算符号" << endl;
	cin >> type;
	oper = OperationFactory::createOperate(type);
	oper->SetNumberA(strNumberA);
	oper->SetNumberB(strNumberB);
	cout << oper->GetResult() << endl;
	if (oper != NULL)
	{
		delete oper;
		oper = NULL;
	}

	return 0;
}