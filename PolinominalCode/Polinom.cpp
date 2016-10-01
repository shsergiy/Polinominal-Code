#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include "polinom.h"
void Polinom::PolinomInput(int n) {
	degree = n;
	rate = new double[degree + 1];
	for (int i = n;i >= 0;i--) {
		cout << "Enter " << i << " Rate " << endl;
		cin >> rate[i];
		if (rate[i] == -842150451)
		{
			std::cout << "ќшибка ввода. ¬ведите число\n";
			exit(0);
		}
	}
}
Polinom::Polinom(int count) {
	degree = count;
	rate = new double[degree + 1];
}
ostringstream Polinom::PolinomShow(Polinom & polinom)
{
	ostringstream str;
	str.str("");
	int TypeDegree = polinom.degree;
	while (polinom.rate[TypeDegree] == 0 && TypeDegree >= 0)
		TypeDegree -= 1;
	if (TypeDegree < 0) {
		str << " Polinom =0 " << endl;
	}
	else {
		if (TypeDegree == 0) {
			str << polinom.rate[0];
		}
		else {
			str << polinom.rate[TypeDegree] << "x^" << TypeDegree;
			TypeDegree -= 1;
			for (int i = TypeDegree;i > 0;i--) {
				if (polinom.rate[i] < 0) {
					str << polinom.rate[i];
				}
				if (polinom.rate[i] > 0) { str << "+" << polinom.rate[i]; }
				if (polinom.rate[i] != 0) { str << "x^" << i; }
			}
			if (polinom.rate[0] < 0) str << polinom.rate[0];
			if (polinom.rate[0] > 0) str << "+" << polinom.rate[0];
		}
	}
	return str;
}
Polinom Polinom::MultyplyPolinome(Polinom & pol_1, Polinom& pol_2) {
	Polinom temp;
	int pop;
	temp.degree = pol_1.degree + pol_2.degree;
	temp.rate = new double[temp.degree + 1];
	for (int i = 0;i <= pol_1.degree;i++) {
		for (int j = 0;j <= pol_2.degree;j++)
		{
			temp.rate[i + j] = 0;
		}
	}
	for (int i = 0;i <= pol_1.degree;i++) {
		for (int j = 0;j <= pol_2.degree;j++) {
			pop = pol_1.rate[i] * pol_2.rate[j];
			temp.rate[i + j] = temp.rate[i + j] + pop;

		}

	}
	return temp;
}
Polinom Polinom::DividePolinom(Polinom &ob)
{

	bool inAlgoritm = true;

	Polinom temp;
	Polinom ob_1;
	Polinom ob_2;
	Polinom ob_4;

	temp.degree = degree - ob.degree;
	temp.rate = new double[temp.degree + 1];
	memset(temp.rate, 0, (temp.degree + 1) * sizeof(double));

	ob_1.degree = degree;
	ob_1.rate = new double[degree + 1];
	for (int i = degree; i >= 0; i--)
		ob_1.rate[i] = rate[i];

	ob_2.degree = ob.degree;
	ob_2.rate = new double[ob.degree + 1];
	for (int i = ob.degree; i >= 0; i--)
		ob_2.rate[i] = ob.rate[i];

	ob_4.degree = ob_1.degree;
	ob_4.rate = new double[ob_1.degree + 1];

	double mnojnik;
	int k = 0;
	int i, j;
	while (inAlgoritm)
	{

		for (int i = ob.degree; i >= 0; i--)
			ob_4.rate[i] = ob.rate[i];

		if (ob_2.degree < ob_1.degree)
		{
			for (i = ob_1.degree, j = ob_2.degree; i >= 0; i--, j--)
				if (j < 0)
					ob_4.rate[i] = 0;
				else
					ob_4.rate[i] = ob_2.rate[j];
		}



		mnojnik = ob_1.rate[ob_1.degree] / ob_4.rate[ob_1.degree];

		temp.rate[temp.degree - k] = mnojnik;
		k++;



		for (int i = 0; i <= ob_1.degree; i++)
			ob_4.rate[i] *= mnojnik;

		for (int i = 0; i <= ob_1.degree; i++)
			ob_1.rate[i] -= ob_4.rate[i];

		ob_1.degree--;
		if (ob_2.degree > ob_1.degree) inAlgoritm = false;

	}

	return temp;

}
Polinom::Polinom()
{
}

Polinom::~Polinom()
{
	//delete[]rate;
}