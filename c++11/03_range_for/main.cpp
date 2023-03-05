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

#include <iostream>
#include <vector>
using namespace std;

class my_class
{
	vector<int> v_;
	typedef	vector<int>::iterator iterator;
public:
	my_class()
	{
		v_.push_back(-1);
		v_.push_back( 0);
		v_.push_back( 1);
	}

	iterator begin()
	{
		return v_.begin();
	}

	iterator end()
	{
		return v_.end();
	}

};


class my_class_2
{
	vector<int> v_;

public:
	typedef	vector<int>::iterator iterator;
	my_class_2()
	{
		v_.push_back(-1);
		v_.push_back( 0);
		v_.push_back( 1);
	}

	iterator begin_2()
	{
		return v_.begin();
	}

	iterator end_2()
	{
		return v_.end();
	}

};

my_class_2::iterator begin( my_class_2& mc2)
{
	return mc2.begin_2();
}

my_class_2::iterator end( my_class_2& mc2)
{
	return mc2.end_2();
}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for( auto x:v ) cout<<x<<endl;

	my_class a;
	for( auto x:a ) cout<<x<<endl;

	my_class_2 a2;
	for( auto x:a2 ) cout<<x<<endl;

        //*
        // not supporte yet??
	for (const auto x : { 1,2,3,5,8,13,21,34 }) cout << x << '\n';
        // */
       
	return (0);
}
