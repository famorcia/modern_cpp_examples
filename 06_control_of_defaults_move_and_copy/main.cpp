#include <iostream>


class X
{
public:
  // ...
  //
  X ()
  {
  }
  X & operator= (const X &) = delete;	// Disallow copying
  X (const X &) = delete;
};

class Y
{
public:
  //                 // ...
  Y ()
  {
  }
  Y & operator= (const Y &) = default;
  // default copy semantics
  Y (const Y &) = default;
};


struct Z
{
  // ...
  //
  Z (long long);		// can initialize with an long long
  Z (long) = delete;		// but not anything less
};


using namespace std;

int
main ()
{
  X a, b;
  //*
  X a1 (a);
  b = a;
  //*/

  Y c, d;
  Y c1 (c);
  d = c;

  long long ll1=0;
  long l1=0;
  Z zll(ll1);
  Z zl(l1);


  return (0);
}
