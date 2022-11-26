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
