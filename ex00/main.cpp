#include <iostream>

#include "whatever.hpp"

void subjectTests() {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void swapTests() {
	float f0 = 69.420f;
	float f1 = 420.69f;

	std::cout << "original: " << std::endl;
	std::cout << "f0 = " << f0 << std::endl;
	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "swaped: " << std::endl;
	swap(f0, f1);
	std::cout << "f0 = " << f0 << std::endl;
	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "re-swaped: " << std::endl;
	swap(f0, f1);
	std::cout << "f0 = " << f0 << std::endl;
	std::cout << "f1 = " << f1 << std::endl;
}

void minMaxTests() {
	std::string str0 = "This should NOT be the MIN string";
	std::string str1 = "This should NOT be the MAX string";
	std::string equ0 = "MY, THIS IS EQUAL";
	std::string equ1 = "MY, THIS IS EQUAL";

	std::cout << "original: " << std::endl;
	std::cout << "str0 = " << str0 << std::endl;
	std::cout << "str1 = " << str1 << std::endl;
	std::cout << "equ0 = " << &equ0 << std::endl;
	std::cout << "equ1 = " << &equ1 << std::endl;
	std::cout << "results: " << std::endl;
	std::cout << "min(str0, str1) = " << ::min(str0, str1) << std::endl;
	std::cout << "max(str0, str1) = " << ::max(str0, str1) << std::endl;
	std::cout << "min(equ0, equ1) = " << &(::min<std::string &>(equ0, equ1)) << std::endl;
	std::cout << "max(equ0, equ1) = " << &(::max<std::string &>(equ0, equ1)) << std::endl;

	std::cout << "min(50, 12) = " << ::min(50, 12) << std::endl;
	std::cout << "max(50, 12) = " << ::max(50, 12) << std::endl;
	std::cout << "min(12, 50) = " << ::min(12, 50) << std::endl;
	std::cout << "max(12, 50) = " << ::max(12, 50) << std::endl;
}


int main( void ) {
	std::cout << "==== Subject tests ====" << std::endl;
	subjectTests();

	std::cout << "===== Swap  tests =====" << std::endl;
	swapTests();

	std::cout << "==== Min/max tests ====" << std::endl;
	minMaxTests();

	return 0;
}