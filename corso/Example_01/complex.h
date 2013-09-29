/*
 * complex.h
 *
 *  Created on: Sep 29, 2013
 *      Author: fmorciano_ubuntu13
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iosfwd>

class complex {
	double real;
	double imag;
public:

	complex(double r, double i);

	double getReal() const {
		return (this->real);
	}

	double getImag() const {
		return (this->imag);
	}

	virtual ~complex();
};

std::ostream& operator<<(std::ostream& os, const complex& c);

#endif /* COMPLEX_H_ */
