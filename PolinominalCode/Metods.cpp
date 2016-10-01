#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include "metods.h"
using namespace std;
string Metods:: SearchCharacter(string name) {
	setlocale(LC_ALL, "rus");
	string Buffer;
	char Buf[50];
	ifstream fin(name + ".txt");//check reading 
	fin.getline(Buf, 50);
	fin.close();
	Buffer = Buf;
	return Buffer;
}
int* Metods::Numbers(string input, string Character) {
	int sx = input.length();
	int * Nubers = new int[sx];
	for (int i = 0;i < input.length();i++) {
		for (int j = 0;j < 33;j++) {
			if (input[i] == Character[j]) {
				Nubers[i] = j;
				break;
			}
		}
	}
	return Nubers;
}
void Metods::ResultNUmbers(int * numbers, string Character, int count) {
	cout << " Answer " << endl;
	for (int i = 0;i < count + 1;i++) {
		cout << Character[numbers[i]];
	}
	cout << endl;
}
Metods::Metods()
{
}

Metods::~Metods()
{
}