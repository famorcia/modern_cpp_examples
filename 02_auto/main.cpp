/*
 * main.cpp
 *
 *  Created on: Oct 13, 2012
 *      Author: fmorciano
 */
#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

template<class T> void printall(const vector<T>& v)
{
	for (auto p = v.begin(); p!=v.end(); ++p)
		cout << *p << "\n";
}
/*
 * The same as before, but before c++11
	template<class T> void printall(const vector<T>& v)
	{
		for (typename vector<T>::const_iterator p = v.begin(); p!=v.end(); ++p)
			cout << *p << "\n";
	}
 */

template<class T, class U> void multiply(const vector<T>& vt, const vector<U>& vu)
{
	//
	int min_size = min(vt.size(),vu.size());
	for(int i=0;i<min_size;++i)
	{
		auto tmp = vt[i]*vu[i];
		// ...
		cout<<"typeinfo says that vt[0] is:"<<typeid(vt.front()).name()<<endl;
		cout<<"typeinfo says that vu[0] is:"<<typeid(vu.front()).name()<<endl;
		cout<<"typeinfo says that auto  is:"<<typeid(tmp).name()<<endl;

		cout<<"product is:"<<tmp<<endl;
	}
}

class MyClass{};

MyClass returnMyClass()
{
	return MyClass();
}

int main()
{
	{
		auto x = 7;
		cout<<"typeinfo says that x in 'auto x = 7;' is:"<<typeid(x).name()<<endl;
	}
	{
		auto x = returnMyClass();
		cout<<"typeinfo says that x in 'auto x = returnMyClass();' is:"<<typeid(x).name()<<endl;
	}

	vector<int> vt;
	vt.push_back(1);
	vt.push_back(2);
	vt.push_back(3);

	printall(vt);

	vector<double> vu;
	vu.push_back(3.0);
	vu.push_back(2.0);
	vu.push_back(1.0);

	multiply(vu,vt);

	return 0;
}
