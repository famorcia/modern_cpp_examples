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

#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

std::mutex g_display_mutex;

void f()
{
    g_display_mutex.lock();
    cerr<<"f piccolo"<<endl;
    g_display_mutex.unlock();
}

struct F {
    void operator()()
    {
        g_display_mutex.lock();
        cerr<<"F GRANDE"<<endl;
        g_display_mutex.unlock();
    }
};

int main()
{
    thread t1(f); // f() executes in separate thread
    F f1;
    thread t2(f1); // F()() executes in separate thread
    t1.join();
    t2.join();
}
