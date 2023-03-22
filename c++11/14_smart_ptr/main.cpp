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
#include <memory>

void observe(std::weak_ptr<int> w_ptr)
{
    std::cout << "w_ptr.use_count() == " << w_ptr.use_count() << "; ";
    // we have to make a copy of shared pointer before usage:
    if (std::shared_ptr<int> s_ptr = w_ptr.lock()) {
        std::cout << "*s_ptr == " << *s_ptr << '\n';
    }
    else {
        std::cout << "w_ptr is expired\n";
    }
}

int main()
{
  std::shared_ptr<int> s_ptr = std::make_shared<int>(5);
  std::unique_ptr<int> u_ptr(new int(4));
  std::weak_ptr<int> w_ptr;

  std::cout << "*** SHARED_PTR ***" << std::endl;
  std::cout << "s_ptr: " << s_ptr.get() <<  " ->  " << *s_ptr << std::endl;
  std::shared_ptr<int> s_ptr_copy = s_ptr;
  std::cout << "*** after copy ***" << std::endl;
  std::cout << "s_ptr_copy: " << s_ptr_copy.get() <<  " ->  " << *s_ptr_copy << std::endl;
  //Increment shared_ptr
  (*s_ptr_copy)++;
  std::cout << "*** after increment of copy ***" << std::endl;
  std::cout << "s_ptr: " << s_ptr.get() <<  " ->  " << *s_ptr << std::endl;
  std::cout << "s_ptr_copy: " << s_ptr_copy.get() <<  " ->  " << *s_ptr_copy << std::endl;

  std::cout << "*** UNIQUE_PTR ***" << std::endl;
  std::cout << "u_ptr: " << u_ptr.get() <<  " ->  " << *u_ptr << std::endl;
  std::unique_ptr<int> u_ptr_new = std::move(u_ptr); // not allowed copy
  std::cout << "*** after move assignement ***" << std::endl;
  std::cout << "u_ptr: " << u_ptr.get() << std::endl;
  std::cout << "u_ptr_new: " << u_ptr_new.get() <<  " ->  " << *u_ptr_new << std::endl;
  //Increment unique_ptr
  (*u_ptr_new)++;
  std::cout << "u_ptr: " << u_ptr.get() <<  std::endl;
  std::cout << "u_ptr_new: " << u_ptr_new.get() <<  " ->  " << *u_ptr_new << std::endl;

  std::cout << "*** WEAK_PTR ***" << std::endl;


  {
        auto sp = std::make_shared<int>(2);
        w_ptr = sp;
 
        observe(w_ptr);
  }
  observe(w_ptr);

}
