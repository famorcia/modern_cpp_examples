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

#include <regex>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

bool is_identifier(const std::string& s)
{
	regex pat{R"([_[:alpha:]]\w*)"};
	return regex_match(s,pat);
}

void test1()
{
	try
	{
		string id1{"a1"};
		assert(true == is_identifier(id1));
		string id2{"2a"};
		assert(false == is_identifier(id1));
	}
	catch(regex_error& e)
	{
		cout<<e.what()<<endl;
	}
}

// from cplusplus.com
void test2()
{

	if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
		std::cout << "string literal matched\n";

	std::string s ("subject");
	std::regex e ("(sub)(.*)");
	if (std::regex_match (s,e))
		std::cout << "string object matched\n";

	if ( std::regex_match ( s.begin(), s.end(), e ) )
		std::cout << "range matched\n";

	std::cmatch cm;    // same as std::match_results<const char*> cm;
	std::regex_match ("subject",cm,e);
	std::cout << "string literal with " << cm.size() << " matches\n";

	std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
	std::regex_match (s,sm,e);
	std::cout << "string object with " << sm.size() << " matches\n";

	std::regex_match ( s.cbegin(), s.cend(), sm, e);
	std::cout << "range with " << sm.size() << " matches\n";

	// using explicit flags:
	std::regex_match ( "subject", cm, e, std::regex_constants::match_default );

	std::cout << "the matches were: ";
	for (unsigned i=0; i<sm.size(); ++i) {
		std::cout << "[" << sm[i] << "] ";
	}

	std::cout << std::endl;
}

void test3()
{
	regex pat{"(AAAA)(BBB)?"};
	string s{"AAAA"};
	smatch m;
	regex_search(s,m, pat );
	cout<<boolalpha;
	cout<<m[0].matched<<endl;
	cout<<m[1].matched<<endl;
	cout<<m[2].matched<<endl;
	cout<<m[3].matched<<endl;
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}
