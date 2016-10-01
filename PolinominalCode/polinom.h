#pragma once
#include "string.h"
#include "stdafx.h"
#include "iostream"
using namespace std;
class Polinom
{
public:
	int degree;
	double *rate;
	Polinom(int count);
	Polinom();
	~Polinom();
	void PolinomInput(int n);
	ostringstream PolinomShow(Polinom& polinom);
	Polinom MultyplyPolinome(Polinom& pol_1, Polinom& pol_2);
	Polinom DividePolinom(Polinom &ob);

};