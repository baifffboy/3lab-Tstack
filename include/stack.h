#ifndef __STACK_H__
#define __STACK_H__
#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Stack
{
protected:
	T* begin;
	size_t size;
	int m;
public:
	Stack() { m = 0; size = 1; begin = new T[size]; for (size_t i = 0; i < size; i++) { begin[i] = T(); }}
	Stack(size_t _n){
		m = 0;
		size = _n;
		begin = new T[size];
		for (size_t i = 0; i < size; i++) { begin[i] = T(); }
	}
	Stack(const Stack& _A) {
		size = _A.size;
		begin = new T[size];
		for (size_t i = 0; i < size; i++) {
			begin[i] = _A.begin[i];
		}
	}
	~Stack() { delete[] begin; }
	void Push(T a) {
		if (m < size) {
			begin[m] = a;
			m++;
		}
		else { 
			size *= 2; 
			T* b = new T[size]; 
			std::copy(begin, begin + size/2, b);
			delete[] begin;
			begin = new T[size]; 
			std::copy(b, b + size/2, begin);
			delete[] b;
			begin[m] = a; 
			m++;
		}
	}
	T top() {
		if(m != 0) return begin[m-1]; else return begin[m];
	}
	T pop(){
		T y;
		if (m != 0) {
			y = begin[m - 1];
			begin[m - 1] = T();
			--m;
		}
		return y;
	}
	bool empty() { if ((m == 0) || ((begin[0] == '(') && (begin[1] == ' '))) return 1; else return 0; }
	int Size() { return size; }
	bool operator==(Stack<T>& a) { 
		if (size == a.size) { 
			for (int i = 0; i < size; i++) { 
				if (a.begin[i] != begin[i]) 
					return 0; 
			} 
			return 1; 
		} 
		else return 0; 
	}
	friend ostream& operator<<(ostream& out, const Stack& a) {
		for (int i = 0; i < a.end - a.begin; i++)
			out << a.begin[i] << ' ';
		return out;
	}
};
#endif
