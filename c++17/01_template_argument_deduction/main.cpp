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

template<typename T = double>
class MyClass{
	private:
	T value;
	public:
	MyClass(){};
	void setValue(const T& p_value) { value = p_value; };
	const T& getValue() const { return value;};
};


int main()
{
	MyClass<std::string> s_class;
	s_class.setValue("test");

	MyClass d_class;
	d_class.setValue(3.14);

	std::cout << "s_class value: " << s_class.getValue() << std::endl;
	std::cout << "d_class value: " << d_class.getValue() << std::endl;
	return 0;
}
