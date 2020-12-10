// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//Calculator 1.0

void ResOutputif2N(char* StartNum, int FirstNum, int SecNum, int firstSymb, int lastSymb) {
	if (lastSymb == 0) {
		switch (StartNum[firstSymb]) {
		case '+':
			cout << FirstNum << '+' << SecNum << '=' << FirstNum + SecNum << endl;
			break;
		case '*':
			cout << FirstNum << '*' << SecNum << '=' << FirstNum * SecNum << endl;
			break;
		case '-':
			cout << FirstNum << '-' << SecNum << '=' << FirstNum - SecNum << endl;
			break;
		case '/':
			cout << FirstNum << '/' << SecNum << '=' << FirstNum / SecNum << endl;
			break;
		default:
			cout << "Error: Try again." << endl;
		}
		
	}
}
void ResOutput(char* StartNum ,int FirstNum, int SecNum, int ThirdNum, int firstSymb, int lastSymb) {
	if (StartNum[firstSymb] == '+' && StartNum[lastSymb] == '+') {
		cout << FirstNum + SecNum + ThirdNum;
	}
	if (StartNum[firstSymb] == '*' && StartNum[lastSymb] == '*') {
		cout << FirstNum * SecNum * ThirdNum;
	}
	if (StartNum[firstSymb] == '-' && StartNum[lastSymb] == '-') {
		cout << FirstNum - SecNum - ThirdNum;
	}
	if (StartNum[firstSymb] == '/' && StartNum[lastSymb] == '/') {
		cout << FirstNum / SecNum / ThirdNum;
	}
	if (StartNum[firstSymb] == '*' && StartNum[lastSymb] == '-') {
		cout << FirstNum * SecNum - ThirdNum;
	}
	if (StartNum[firstSymb] == '*' && StartNum[lastSymb] == '+') {
		cout << FirstNum * SecNum + ThirdNum;
	}
	if (StartNum[firstSymb] == '*' && StartNum[lastSymb] == '/') {
		cout << FirstNum * SecNum / ThirdNum;
	}
	if (StartNum[firstSymb] == '/' && StartNum[lastSymb] == '-') {
		cout << FirstNum / SecNum - ThirdNum;
	}
	if (StartNum[firstSymb] == '/' && StartNum[lastSymb] == '+') {
		cout << FirstNum / SecNum + ThirdNum;
	}
	if (StartNum[firstSymb] == '/' && StartNum[lastSymb] == '*') {
		cout << FirstNum / SecNum * ThirdNum;
	}
	if (StartNum[firstSymb] == '-' && StartNum[lastSymb] == '+') {
		cout << FirstNum - SecNum + ThirdNum;
	}
	if (StartNum[firstSymb] == '-' && StartNum[lastSymb] == '/') {
		cout << FirstNum - SecNum / ThirdNum;
	}
	if (StartNum[firstSymb] == '-' && StartNum[lastSymb] == '*') {
		cout << FirstNum - SecNum * ThirdNum;
	}
	if (StartNum[firstSymb] == '+' && StartNum[lastSymb] == '/') {
		cout << FirstNum + SecNum / ThirdNum;
	}
	if (StartNum[firstSymb] == '+' && StartNum[lastSymb] == '-') {
		cout << FirstNum + SecNum - ThirdNum;
	}
	if (StartNum[firstSymb] == '+' && StartNum[lastSymb] == '*') {
		cout << FirstNum + SecNum * ThirdNum;
	}
	else {
		cout << "Error: Try again." << endl;
	}
		
}

int main()
{
	//Number Input
	char* StartNum = new char[100];
	cout << "Type your expression (One or two operands can be used):" << endl;
	cin >> StartNum;

	int result;
	int lastSymb = 0;
	int firstSymb = 0;

	//Number and operands decode
	for (size_t i = 0; i < strlen(StartNum); i++)
	{
		if (StartNum[i] == '+' || StartNum[i] == '*' || StartNum[i] == '/' || StartNum[i] == '-') {
			firstSymb = i;
			break;
		}
	}

	for (size_t i = firstSymb + 1; i < strlen(StartNum); i++)
	{
		if (StartNum[i] == '+' || StartNum[i] == '*' || StartNum[i] == '/' || StartNum[i] == '-') {
			lastSymb = i;
			break;
		}
	}

	int FirstNum = atoi(StartNum);
	int SecNum = atoi(StartNum + firstSymb + 1);
	int ThirdNum = atoi(StartNum + lastSymb + 1);

	//Result Output if 3 Numb
	ResOutput(StartNum, FirstNum, SecNum, ThirdNum, firstSymb, lastSymb);
	
	//Result output if 2 Numb
	ResOutputif2N(StartNum, FirstNum, SecNum, firstSymb, lastSymb);
	
	//Планы: 
	//- переделать функцию для 3 чисел через стек(Обратная польская нотация)
	//- Свести for в один цикл
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
