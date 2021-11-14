#include <iostream>
#include <Array.hpp>

void emptyTest() {
	Array<int> array0;
	Array<std::string> array1;

	try {
		array0[0] = 5;
		std::cout << "WHAT?" << std::endl;
	} catch (...) {
		// PERFECT
	}

	try {
		array1[0] = "BONCHOUR";
		std::cout << "WHAT? AGAIN?" << std::endl;
	} catch (...) {
		// Noice :)
	}
}

void basicArray() {
	Array<int> array(10);
	std::cout << "Basic array tests" << std::endl;

	std::cout << "Default initialized values" << std::endl;
	for (unsigned int i = 0; i < array.size(); ++i) {
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	std::cout << "Filling it with values" << std::endl;
	for (unsigned int i = 0; i < array.size(); ++i) {
		array[i] = i;

		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	std::cout << "(Again)" << std::endl;
	for (unsigned int i = 0; i < array.size(); ++i) {
		array[i] = ((i + 8) * 42) ^ (i + 6);

		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	std::cout << "Modifying ONE value (can you find it? ( ͡° ͜ʖ ͡°) )" << std::endl;
	array[3]++;
	for (unsigned int i = 0; i < array.size(); ++i) {
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	std::cout << "Does it throw an exception?" << std::endl;
	try {
		std::cout << "- Out-of-bound index... ";
		array[456] = 69;
		std::cout << "No! Fail :(" << std::endl;
	} catch (...) {
		std::cout << "Yes! Success :D" << std::endl;
	}

	try {
		std::cout << "- Negative index... ";
		array[-1] = 420;
		std::cout << "No! Fail :(" << std::endl;
	} catch (...) {
		std::cout << "Yes! Success :D" << std::endl;
	}

	try {
		std::cout << "- size() index... ";
		array[array.size()] = 666;
		std::cout << "No! Fail :(" << std::endl;
	} catch (...) {
		std::cout << "No! Fail :( Naaaaah just kinding. Success! 10 points to Hufflepuff" << std::endl;
	}
}

void copyTests() {
	std::cout << "Copy array tests" << std::endl;

	Array<std::string> array(5);
	array[0] = "That's a nice string you've got there";
	array[1] = "OH! Another one!";
	array[2] = "OwO";
	array[3] = "You've got banned by VAC";
	array[4] = "That's nice to dream sometimes";

	std::cout << "Original values" << std::endl;
	for (unsigned int i = 0; i < array.size(); ++i) {
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	Array<std::string> arrayCpy0(array);
	Array<std::string> arrayCpy1 = Array<std::string>(50);

	std::cout << "Constructor-copied values" << std::endl;
	for (unsigned int i = 0; i < arrayCpy0.size(); ++i) {
		std::cout << "[" << i << "]: " << arrayCpy0[i] << std::endl;
	}

	std::cout << "Operator-copied values" << std::endl;
	arrayCpy1 = arrayCpy0;
	for (unsigned int i = 0; i < arrayCpy1.size(); ++i) {
		std::cout << "[" << i << "]: " << arrayCpy1[i] << std::endl;
	}

	std::cout << "Modifying a value of the operator-copied array" << std::endl;
	arrayCpy1[3] = "Wallhack intensifies";

	std::cout << "Original array" << std::endl;
	for (unsigned int i = 0; i < array.size(); ++i) {
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	std::cout << "Constructor-copied array" << std::endl;
	for (unsigned int i = 0; i < arrayCpy0.size(); ++i) {
		std::cout << "[" << i << "]: " << arrayCpy0[i] << std::endl;
	}

	std::cout << "Operator-copied array" << std::endl;
	for (unsigned int i = 0; i < arrayCpy1.size(); ++i) {
		std::cout << "[" << i << "]: " << arrayCpy1[i] << std::endl;
	}

	try {
		arrayCpy1[48] = "WHAT?!";
		std::cout << "Did not throw an exception when it was supposed :(" << std::endl;
	} catch (std::exception &exception) {
		(void)exception;
		std::cout << "Noice :)" << std::endl;
	}

}

int main(void) {
	emptyTest();
	basicArray();
	copyTests();

	return 0;
}