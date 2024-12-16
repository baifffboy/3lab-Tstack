#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string input;
	cout << "Введите алгебраическое выражение, используя операции << *, +, -, /, ^, (, ), cos(), sin(), log(), log10() >> и только однозначные числа/константы:" << endl;
	getline(std::cin, input);
	TArithmetic str = input;
	if (str.scobki()) {
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "ИТОГ" << endl; 
		cout << "Инфиксная форма: " << str.GetInfix() << endl; 
		//cout << "Значения переменных: " << str.coutPeremennie() << endl;
		cout << "Постфиксная форма: " << str.GetPostfix() << endl; 
		cout << "ОТВЕТ: " << str.itogi() << endl;
	}
	return 0;
}
//((a+b*c)*(a/b-c)-1) 4, 2, 1
//(a^b - c) * (e /v + 2 *3) - 9      2, 4, 7 (9), 9, 3 (9) == 9*9-9 == 72
//(log(3) *2) - 1
//((log(3) *2) - 1) * ((a^b - c) * (a /b + 2 *3) - 9 )