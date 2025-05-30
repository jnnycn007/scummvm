/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef COMMON_RATIONAL_H
#define COMMON_RATIONAL_H

#include "common/scummsys.h"
#include "common/frac.h"

namespace Common {

/**
 * @defgroup common_rational Rational class
 * @ingroup common
 *
 * @brief API for rational class.
 *
 * @{
 */

/** A simple rational class that holds fractions. */
class Rational {
public:
	Rational();
	Rational(int num);
	Rational(int num, int denom);
	Rational(const Rational &rational);

	Rational &operator=(const Rational &right);
	Rational &operator=(int right);

	Rational &operator+=(const Rational &right);
	Rational &operator-=(const Rational &right);
	Rational &operator*=(const Rational &right);
	Rational &operator/=(const Rational &right);

	Rational &operator+=(int right);
	Rational &operator-=(int right);
	Rational &operator*=(int right);
	Rational &operator/=(int right);

	const Rational operator-() const;

	const Rational operator+(const Rational &right) const;
	const Rational operator-(const Rational &right) const;
	const Rational operator*(const Rational &right) const;
	const Rational operator/(const Rational &right) const;

	const Rational operator+(int right) const;
	const Rational operator-(int right) const;
	const Rational operator*(int right) const;
	const Rational operator/(int right) const;

	bool operator==(const Rational &right) const;
	bool operator!=(const Rational &right) const;
	bool operator>(const Rational &right) const;
	bool operator<(const Rational &right) const;
	bool operator>=(const Rational &right) const;
	bool operator<=(const Rational &right) const;

	bool operator==(int right) const;
	bool operator!=(int right) const;
	bool operator>(int right) const;
	bool operator<(int right) const;
	bool operator>=(int right) const;
	bool operator<=(int right) const;

	void invert();
	Rational getInverse() const;

	int toInt() const;
	double toDouble() const;
	frac_t toFrac() const;

	int getNumerator() const { return _num; }
	int getDenominator() const { return _denom; }

	bool isOne() const { return _num == _denom; }

	void debugPrint(int debuglevel = 0, const char *caption = "Rational:") const;
	void debugPrintC(int debuglevel, uint32 debugChannel, const char *caption = "Rational:") const;

private:
	int _num;
	int _denom;

	void cancel();
};

const Rational operator+(int left, const Rational &right);
const Rational operator-(int left, const Rational &right);
const Rational operator*(int left, const Rational &right);
const Rational operator/(int left, const Rational &right);

bool operator==(int left, const Rational &right);
bool operator!=(int left, const Rational &right);
bool operator>(int left, const Rational &right);
bool operator<(int left, const Rational &right);
bool operator>=(int left, const Rational &right);
bool operator<=(int left, const Rational &right);

/** @} */

} // End of namespace Common

#endif
