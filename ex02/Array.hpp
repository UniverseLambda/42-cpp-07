#pragma once

#include <stdexcept>

template<typename _Tp>
class Array {
private:
	_Tp *mData;
	unsigned int mLength;

public:
	Array(): mData(new _Tp[0]), mLength(0) {}
	Array(unsigned int n): mData(new _Tp[n]), mLength(n) {}

	Array(const Array<_Tp> &cpy): mData(new _Tp[cpy.mLength]), mLength(cpy.mLength) {
		for (unsigned int i = 0; i < mLength; ++i) {
			mData[i] = cpy.mData[i];
		}
	}

	~Array() {
		delete[] mData;
	}

	Array<_Tp> &operator=(const Array<_Tp> &rhs) {
		delete[] mData;

		mLength = rhs.mLength;

		mData = new _Tp[mLength];
		for (unsigned int i = 0; i < mLength; ++i) {
			mData[i] = rhs.mData[i];
		}

		return (*this);
	}

	_Tp &operator[](unsigned int idx) {
		if (idx >= mLength) {
			throw std::length_error("Array out-of-bound access");
		}

		return mData[idx];
	}

	const _Tp &operator[](unsigned int idx) const {
		if (idx >= mLength) {
			throw std::length_error("Array out-of-bound access");
		}

		return mData[idx];
	}

	unsigned int size() const {
		return mLength;
	}
};
