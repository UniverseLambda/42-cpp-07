#pragma once

template<typename _ArgType>
_ArgType max(_ArgType a, _ArgType b) {
	return (a > b) ? a : b;
}

template<typename _ArgType>
_ArgType min(_ArgType a, _ArgType b) {
	return (a < b) ? a : b;
}

template<typename _ArgType>
void swap(_ArgType &refA, _ArgType &refB) {
	_ArgType tmp = refA;

	refA = refB;
	refB = tmp;
}
