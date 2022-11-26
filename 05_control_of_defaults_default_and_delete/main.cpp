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

class X
{
public:
  // ...
  //
  X ()  {
  }
  X &operator= (const X &) = delete;	// Disallow copying
  X (const X &) = delete;
};

class Y
{
public:
  //                 // ...
  Y ()  {
  }
  Y & operator= (const Y &) = default;
  // default copy semantics
  Y (const Y &) = default;
};


struct Z
{
  // ...
  //
  explicit Z (long long) {
      // can initialize with a long long
  }
  Z (long) = delete; // but not anything less
};


using namespace std;

int main () {
  X a, b;
  /* Can not be done deleted
  X a1 (a);
  b = a;
  //*/

  Y c, d;
  Y c1 (c);
  d = c;

  long long ll1=0;
  Z zll(ll1);
  /* Can not be done deleted
  long l1=0;
  Z zl(l1);
  //*/

  return (0);
}
