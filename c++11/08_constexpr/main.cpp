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
