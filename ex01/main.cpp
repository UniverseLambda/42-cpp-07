#include <iostream>

#include "iter.hpp"

template<typename _Tp>
void printMe(_Tp &me) {
	std::cout << me << std::endl;
}

void incMe(int &me) {
	++me;
}

int main( void ) {
	int DATS_MA_GUD_BOIS[] = {69, 420, 42, 42, 42, 21};
	std::string areThesesStrings[] = {"AAAAA", "BBBBB", "DDDDD", "That's a prank bro", "It's peanut butter jelly time"};

	std::cout << "original DATS_MA_GUD_BOIS" << std::endl;
	::iter(DATS_MA_GUD_BOIS, 6, printMe);

	std::cout << "incremented DATS_MA_GUD_BOIS" << std::endl;
	::iter(DATS_MA_GUD_BOIS, 6, incMe);
	::iter(DATS_MA_GUD_BOIS, 6, printMe);

	std::cout << "OwO, that's a nice string array you've got there" << std::endl;
	::iter(areThesesStrings, 5, printMe);

	return 0;
}