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

enum Flags
{ good = 0, fail = 1, bad = 2, eof = 4 , bad_eof = 6 };

constexpr int
operator| (Flags f1, Flags f2)
{
  return Flags (int (f1) | int (f2));
}

void
f1 (Flags x)
{
  switch (x)
    {
    case bad:			/* ... */
      break;
    case eof:			/* ... */
      break;
    case bad | eof:		/* ... */
      break;
    default:			/* ... */
      break;
    }
}

constexpr int x1 = bad | eof;	// ok

void
f2 (Flags f3)
{
  // constexpr int x2 = bad|f3;   // error: can't evaluate at compile time
  int x3 = bad | f3;		// ok
  --x3;
  x3 += 1;
}

int
main ()
{

  int return_val = 0;


  struct Point
  {
    int x, y;
    constexpr Point (int xx, int yy):x (xx), y (yy)
    {
    }
  };

  constexpr Point origo (0, 0);
  constexpr int z = origo.x;
  return_val = z;
  constexpr Point a[] = { Point (0, 0), Point (1, 1), Point (2, 2) };
  constexpr int x = a[1].x;	// x becomes 1
  if (z > x)
    return_val = x;
  return return_val;
}
