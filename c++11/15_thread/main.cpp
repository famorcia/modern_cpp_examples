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
#include <thread>
#include <vector>
#include <array>
#include <cstdlib>
#include <mutex>

int main()
{
    std::vector<std::thread> threadsVector;
    std::array<unsigned int, 5> seed = {1,2,3,4,5};
    std::mutex cout_mutex;
    for (auto a = 0; a < 5; a++)
    {
        threadsVector.emplace_back([&cout_mutex, a, &seed ]()
                                   {
                                       std::thread::id this_id = std::this_thread::get_id();
                                       /* initialize random seed: */
                                      
                                        auto timeToSleep = rand_r( &(seed[a])) % 11;
                                       cout_mutex.lock();
                                       std::cout << "thread " << this_id << " sleeping for " << timeToSleep << "...\n";
                                       cout_mutex.unlock();
                                       std::this_thread::sleep_for(std::chrono::seconds(timeToSleep));
                                       cout_mutex.lock();
                                       std::cout << "thread " << this_id << " finished\n";
                                       cout_mutex.unlock();
                                   });
    }

    for (auto& thread : threadsVector) {
        thread.join(); // Wait for threads to finish
    }   
}
