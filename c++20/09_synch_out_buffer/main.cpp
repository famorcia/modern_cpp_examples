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
#include <syncstream>
#include <future>
#include <vector>
#include <thread>
#include <atomic>

int main()
{
	std::atomic_int counter = 0;

	auto print_and_increment = [&counter]()
	{ 
		auto th_id = std::this_thread::get_id();
		for( int j = 0; j< 10000; j++){
			std::osyncstream(std::cout) << "Thread ID: " << th_id << " value of counter is:" << counter++ << std::endl;
		}
	};
	std::vector<std::future<void>> results;
	for(int i = 0; i< 5; i++){
		results.push_back(std::async(std::launch::async, print_and_increment));
	}

	for(auto& elem : results){
		elem.wait();
	}

	return 0;
}
