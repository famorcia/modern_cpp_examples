/**************************************************************************\
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, Fabrizio Morciano
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

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
