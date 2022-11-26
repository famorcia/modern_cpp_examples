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

int main()
{
	const long cplusplus_ref_value = 199711L;
	const long cplusplus_compiler_ref = __cplusplus;
	std::string check;
	if(cplusplus_ref_value < cplusplus_compiler_ref)
		check = "yes";
	else
		check = "no";

	std::cout<<"Print __cplusplus macro definition:"<<cplusplus_compiler_ref<<std::endl;
	std::cout<<"Is your compiler c++11 compliant? The answer is: "<<check<<'!'<<std::endl;
	return 0;
}
