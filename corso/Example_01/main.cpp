#include "complex.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	complex c1{1.0,2.0};
	cout<<c1;
	complex c2(1,2);
	cout<<c2;
	complex c3{1,2}; // error not allowed
	cout<<c3;

	vector<complex> complex_vector = {{1.0,1.0}, {2.0,2.0} };

	std::copy(complex_vector.begin(),
			  complex_vector.end(),
			  std::ostream_iterator<complex>(cout));

	return (0);
}
