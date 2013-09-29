/*
 * main.cpp
 *
 *  Created on: Oct 13, 2012
 *      Author: fmorciano
 */

#include <iostream>

int main()
{
	const long cplusplus_ref_value = 199711L;
	const long cplusplus_compiler_ref = __cplusplus;
	std::string check;
	if(cplusplus_ref_value<cplusplus_compiler_ref)
		check = "yes";
	else
		check = "no";

	std::cout<<"Print __cplusplus macro definition:"<<cplusplus_compiler_ref<<std::endl;
	std::cout<<"Is your compiler c++11 compliant? The answer is: "<<check<<'!'<<std::endl;
	return 0;
}
