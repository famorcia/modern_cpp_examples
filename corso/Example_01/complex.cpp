/*
 * complex.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: fmorciano_ubuntu13
 */

#include "complex.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const complex& c)
{
	os<<'('<<c.getReal()<<','<<c.getImag()<<')'<<std::endl;
	return (os);
}


complex::complex(double r, double i)
:real(r)
,imag(i)
{
}

complex::~complex()
{
}

