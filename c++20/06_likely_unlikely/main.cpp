/*
 *  cpp11 examples
 *  Copyright (C) 2023  Matteo Botticci
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
	for( int i = 0;  i < 15; i++){
		if(i < 10 )[[likely]]{
			std::cout << "Minor" << std::endl;
		}else{
			std::cout << "Major" << std::endl;
		}
	}

	int n = 55;
	switch (n){
		case 32:
			break;
		[[unlikely]]case 34:
			break;
		case 55:
			break;
	}

	return 0;
}
