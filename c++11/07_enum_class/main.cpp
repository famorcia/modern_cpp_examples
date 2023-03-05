/**************************************************************************\
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, Fabrizio Morciano
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

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
