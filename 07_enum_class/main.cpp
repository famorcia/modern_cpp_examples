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

using namespace std;

void test_enum_type_specification()
{
   enum class Color : char { red, blue };   // compact representation

   enum class TrafficLight { red, yellow, green };  // by default, the underlying type is int

   enum E { E1 = 1, E2 = 2, Ebig = 0xFFFFFFF0U };   // how big is an E?
                                                    // (whatever the old rules say;
                                                    // i.e. "implementation defined")

   enum EE : unsigned long { EE1 = 1, EE2 = 2, EEbig = 0xFFFFFFF0U };   // now we can be specific

}

enum class Color_code : char;     // (forward) declaration
void foobar(Color_code* p);       // use of forward declaration
// ...
enum class Color_code : char { red, yellow, green, blue }; // definition



int main()
{
   enum Alert { green, yellow, election, red }; // traditional enum

   enum class Color { red, blue };   // scoped and strongly typed enum
                                     // no export of enumerator names into enclosing scope
                                     // no implicit conversion to int
   enum class TrafficLight { red, yellow, green };

   // Alert a = 7;              // error (as ever in C++)
   // Color c = 7;              // error: no int->Color conversion

   int a2 = red;             // ok: Alert->int conversion
   int a3 = Alert::red;      // error in C++98; ok in C++11
   //int a4 = blue;            // error: blue not in scope
   //int a5 = Color::blue;     // error: not Color->int conversion

   Color a6 = Color::blue;   // ok

   // solo per evitare i warning di variabili non usate
   int return_val = 0;
   if (a2 > a3 )
      return_val = -1;

   if( a6 == Color::red)
     return_val = 1;

   return return_val;
}
