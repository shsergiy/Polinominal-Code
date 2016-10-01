// PolinominalCode.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include "polinom.h"
#include "metods.h"
using namespace std;
int main()
{
	cout << "write name of the file with character" << endl;
	string Name;
	cin >> Name;
	Metods type;
	string Character ;
	Character = type.SearchCharacter(Name);
	cout << "Write input values" << endl;
	string InputValue;
	cin >> InputValue;
	int * NumbersCharacter = new int[InputValue.length()];
	NumbersCharacter = type.Numbers(InputValue, Character);
	for (int i = 0;i < InputValue.length();i++) {
		cout << NumbersCharacter[i] << " ";
	}
	cout << endl;
	cout << "Polinom's Initialization" << endl;
	cout << "Write degree of Polinom" << endl;
	int Dgr;
	cin >> Dgr;
	Polinom p1(Dgr);
	p1.PolinomInput(Dgr);
	cout << "Write degree of secound Polinom" << endl;
	int Dgr1;
	cin >> Dgr1;
	Polinom p2(Dgr1);
	p2.PolinomInput(Dgr1);
	ostringstream str = p1.PolinomShow(p1);
	string s = str.str();
	cout << "First Polinome " << s << endl;
	ostringstream str1 = p2.PolinomShow(p2);
	string s1 = str1.str();
	cout << "Secound Polinome " << s1 << endl;
	cout << "Multyply of Polinomes " << endl;
	Polinom temp;
	temp = temp.MultyplyPolinome(p1, p2);
	ostringstream str2;
	str2 = temp.PolinomShow(temp);
	string s2;
	s2 = str2.str();
	cout << "Result of multiply " << s2 << endl;
	int* OutputNumbers = new int[temp.degree + 1];
	int COUNT = temp.degree;
	for (int i = temp.degree;i>=0;i--)
	{
		OutputNumbers[i] = temp.rate[i];
		cout << OutputNumbers[i] << " ";
	}
	cout << endl;
	type.ResultNUmbers(OutputNumbers, Character, COUNT);
	system("pause");
	return 0;
}

