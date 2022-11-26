/*
 *  cpp11 examples
 *  Copyright (C) 2022  Fabrizio Morciano
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
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
