#pragma once

template<typename _Tp>
void iter(_Tp *array, unsigned long length, void (*f)(_Tp &)) {
	for (unsigned long i = 0; i < length; ++i) {
		f(array[i]);
	}
}
