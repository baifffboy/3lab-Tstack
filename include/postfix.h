#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include "vector"
#include "string.h"
#include <map>
#include <cmath>

using namespace std;

class TArithmetic {
protected:
	string in;
	map<char, int> peremennie;
	map<char, unsigned> operacii{ {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}, {')', 0}, {'^', 3} };
	string postfix;
public:	
	TArithmetic(string im) {
		in = im;
	}
	~TArithmetic() { in.erase();}

	string GetInfix() const { return in; }
	string GetPostfix() { return postfiks(); }
	//string coutPeremennie() { for (size_t i = 0; i < peremennie.size(); i++) { string s; s[i] = peremennie[i] } }

	string postfiks() {
		vector<char> itog;
		Stack<char> e(in.size());
		char* o = nullptr;
		char p;
		for (size_t i = 0; i < in.size(); i++) {
			if (((in[i] >= 65) && (in[i] <= 90)) || ((in[i] >= 97) && (in[i] <= 122))) {
				if (((in[i] == 67) || (in[i] == 99)) && ((in[i+1] == 'o') && (in[i + 2] == 's'))) { // для косинуса
					while (in[i] != ')') { itog.push_back(in[i]); i++; } itog.push_back(in[i]); continue;
				}
				if (((in[i] == 83) || (in[i] == 115)) && ((in[i + 1] == 'i') && (in[i + 2] == 'n'))) { // для синуса
					while (in[i] != ')') { itog.push_back(in[i]); i++; } itog.push_back(in[i]); continue;
				}
				if (((in[i] == 76) || (in[i] == 108)) && ((in[i + 1] == 'o') && (in[i + 2] == 'g'))) { // для логарифма
					while (in[i] != ')') { itog.push_back(in[i]); i++; } itog.push_back(in[i]); continue;
				}
				if (peremennie.count(in[i]) == 0) {
					cout << "Введите значение константы " << in[i] << ":" << endl;
					cin >> p;
					peremennie[in[i]] = p;
					o = &p;
				}
				else {itog.push_back(peremennie[in[i]]);}
			}
			if (o != nullptr) { 
				itog.push_back(*o); 
				o = nullptr; 
			}
			if (in[i] >= 48 && in[i] <= 57) {
				itog.push_back(in[i]);
			}
			if (in[i] == '(') e.Push(in[i]);
			if (in[i] == ')') {
				while (e.top() != '(') { 
					itog.push_back(e.pop());
				}
				e.pop();
				if (((e.top() != char()) && (e.top() != '(')) && (operacii[in[i + 1]] <= operacii[e.top()])) itog.push_back(e.pop());
			}
			if ((operacii.count(in[i])) && (operacii[in[i]] != 0)) {
				if ((in[i - 1] == '(') && (in[i] = '-')) itog.push_back('0');
				if (e.empty()) e.Push(in[i]);
				else {
					while ((operacii[in[i]] <= operacii[e.top()]) && (operacii[e.top()] != 0)) {
						itog.push_back(e.pop());
					}
					if (operacii[in[i]] > operacii[e.top()]) e.Push(in[i]);
				}
			}
		}
		if (e.empty() == 0) {
			while (e.empty() == 0) {
				itog.push_back(e.pop());
			}
		}
		string n(itog.begin(), itog.end());
		postfix = n;
		return n;
	}


	double itogi() {
		Stack<string> d(postfix.size());
		for (size_t i = 0; i < postfix.size(); i++) {
			if (((postfix[i] == 67) || (postfix[i] == 99)) || ((postfix[i] == 83) || (postfix[i] == 115))) { // для синусов и косинусов
				vector<char> full = {};
				vector<char> znach = {};
				while (postfix[i] != ')') {if (std::isdigit(postfix[i])) znach.push_back(postfix[i]); full.push_back(postfix[i]); i++; } full.push_back(postfix[i]); i++;
				string n(znach.begin(), znach.end());
				double po = {};
				switch (postfix[i - full.size()])
				{
					case 'c':
					case 'C':
						//double i = round(cos(static_cast<double>(atoi(m[2].c_str())))) / 10;
						//if (((int)i + 0.5) > i) i = (int)i; else i = (int)i + 1;
						po = cos(stod(n));
						d.Push(to_string(po)); break; 
					case 'S':
					case 's':
						//double i = round(cos(static_cast<double>(atoi(m[2].c_str())))) / 10;
						//if (((int)i + 0.5) > i) i = (int)i; else i = (int)i + 1;
						po = sin(stod(n));
						d.Push(to_string(po)); break; 
				}
			}
			if ((postfix[i] == 76) || (postfix[i] == 108)) {
				vector<char> full = {};
				vector<char> znach = {};
				bool t = false;
				while (postfix[i] != ')') { if (postfix[i] == '(') t = true; if ((std::isdigit(postfix[i])) && t) znach.push_back(postfix[i]); full.push_back(postfix[i]); i++; } full.push_back(postfix[i]); i++;
				string n(znach.begin(), znach.end());
				double po = {};
				switch (full[3]) {
					case '1': 
						po = log10(stod(n)); 
						d.Push(to_string(po)); break; 
					case '(': 
						po = log(stod(n)); 
						d.Push(to_string(po)); break; 
				}
			}
			if ((postfix[i] >= 48) && (postfix[i] <= 57)) {
				string t(1, postfix[i]);
				d.Push(t);
			}
			if (operacii.count(postfix[i])) {
				string right = d.pop();
				string left = d.pop();
				switch(postfix[i])
				{
					case '*': d.Push(to_string(stod(left) * stod(right))); break;
					case '/': d.Push(to_string(stod(left) / stod(right))); break;
					case '+': d.Push(to_string(stod(left) + stod(right))); break;
					case '-': d.Push(to_string(stod(left) - stod(right))); break;
					case '^': d.Push(to_string(std::pow(stod(left), stod(right)))); break;
				default:
					break;
				}
			}
		}
		return stod(d.top());
	}

	
	bool scobki() {
		int i = 0;
		int g = 0;
		try {
			string m = "()";
			for (size_t r = 0; r < in.size(); r++) {
				if (in[r] == m[0]) i++;
				if (in[r] == m[1]) g++;
			}
			if (i != g) throw "Перепешите значение выражения со скобками корректно!";
		}
		catch (const char* err) {cout << err << endl;}
		return g == i;
	}	
	double proverka_testov() {
		bool t = false;
		t = this->scobki();
		if (t) {
			this->GetPostfix();
			return this->itogi();
		}
	}
};


#endif

