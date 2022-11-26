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

#include "complex.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	complex c1{1.0,2.0};
	cout<<c1;
	complex c2(1,2);
	cout<<c2;
	complex c3{1,2}; // error not allowed
	cout<<c3;

	vector<complex> complex_vector = {{1.0,1.0}, {2.0,2.0} };

	std::copy(complex_vector.begin(),
			  complex_vector.end(),
			  std::ostream_iterator<complex>(cout));

	return (0);
}
