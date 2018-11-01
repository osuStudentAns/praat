#pragma once
/* VEC.h
 *
 * Copyright (C) 2017,2018 Paul Boersma
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */

inline void operator<<= (const VECVU& x, double number) noexcept {
	for (integer i = 1; i <= x.size; i ++)
		x [i] = number;
}
inline void operator+= (const VECVU& x, double number) noexcept {
	for (integer i = 1; i <= x.size; i ++)
		x [i] += number;
}
inline void operator-= (const VECVU& x, double number) noexcept {
	for (integer i = 1; i <= x.size; i ++)
		x [i] -= number;
}
inline void operator*= (const VECVU& x, double number) noexcept {
	for (integer i = 1; i <= x.size; i ++)
		x [i] *= number;
}
inline void operator/= (const VECVU& x, double number) noexcept {
	for (integer i = 1; i <= x.size; i ++)
		x [i] /= number;
}

inline void operator<<= (VECVU const& target, constVECVU const& source) {
	Melder_assert (target.size == source.size);
	for (integer i = 1; i <= target.size; i ++)
		target [i] = source [i];
}
inline void operator+= (const VECVU& x, const constVECVU& y) noexcept {
	Melder_assert (y.size == x.size);
	for (integer i = 1; i <= x.size; i ++)
		x [i] += y [i];
}
inline void operator-= (const VECVU& x, const constVECVU& y) noexcept {
	Melder_assert (y.size == x.size);
	for (integer i = 1; i <= x.size; i ++)
		x [i] -= y [i];
}
inline void operator*= (const VECVU& x, const constVECVU& y) noexcept {
	Melder_assert (y.size == x.size);
	for (integer i = 1; i <= x.size; i ++)
		x [i] *= y [i];
}
inline void operator/= (const VECVU& x, const constVECVU& y) noexcept {
	Melder_assert (y.size == x.size);
	for (integer i = 1; i <= x.size; i ++)
		x [i] /= y [i];
}

struct TypeVECadd_VEC_NUM {
	const constVECVU &x;
	double addend;
};
inline TypeVECadd_VEC_NUM operator+ (const constVECVU &x, double addend) {
	return { x, addend };
}
inline void operator<<= (const VECVU& target, const TypeVECadd_VEC_NUM& expr) noexcept {
	Melder_assert (expr.x.size == target.size);
	for (integer i = 1; i <= expr.x.size; i ++)
		target [i] = expr.x [i] + expr.addend;
}
inline void operator+= (const VECVU& target, const TypeVECadd_VEC_NUM& expr) noexcept {
	Melder_assert (expr.x.size == target.size);
	for (integer i = 1; i <= expr.x.size; i ++)
		target [i] += expr.x [i] + expr.addend;
}
inline void operator-= (const VECVU& target, const TypeVECadd_VEC_NUM& expr) noexcept {
	Melder_assert (expr.x.size == target.size);
	for (integer i = 1; i <= expr.x.size; i ++)
		target [i] -= expr.x [i] + expr.addend;
}
inline void operator*= (const VECVU& target, const TypeVECadd_VEC_NUM& expr) noexcept {
	Melder_assert (expr.x.size == target.size);
	for (integer i = 1; i <= expr.x.size; i ++)
		target [i] *= expr.x [i] + expr.addend;
}
inline void operator/= (const VECVU& target, const TypeVECadd_VEC_NUM& expr) noexcept {
	Melder_assert (expr.x.size == target.size);
	for (integer i = 1; i <= expr.x.size; i ++)
		target [i] /= expr.x [i] + expr.addend;
}
inline autoVEC newVECadd (const constVEC& x, double addend) {
	autoVEC result = newVECraw (x.size);
	result.all() <<= x  +  addend;
	return result;
}

struct TypeVECadd_VEC_VEC {
	const constVECVU &x, &y;
};
inline TypeVECadd_VEC_VEC operator+ (const constVECVU &x, const constVECVU& y) {
	return { x, y };
}
inline void operator<<= (const VECVU& target, TypeVECadd_VEC_VEC expr) noexcept {
	integer n = target.size;
	Melder_assert (expr.x.size == n);
	Melder_assert (expr.y.size == n);
	for (integer i = 1; i <= n; i ++)
		target [i] = expr.x [i] + expr.y [i];
}
inline void operator+= (const VECVU& target, TypeVECadd_VEC_VEC expr) noexcept {
	integer n = target.size;
	Melder_assert (expr.x.size == n);
	Melder_assert (expr.y.size == n);
	for (integer i = 1; i <= n; i ++)
		target [i] += expr.x [i] + expr.y [i];
}
inline void operator-= (const VECVU& target, TypeVECadd_VEC_VEC expr) noexcept {
	integer n = target.size;
	Melder_assert (expr.x.size == n);
	Melder_assert (expr.y.size == n);
	for (integer i = 1; i <= n; i ++)
		target [i] -= expr.x [i] + expr.y [i];
}
inline void operator*= (const VECVU& target, TypeVECadd_VEC_VEC expr) noexcept {
	integer n = target.size;
	Melder_assert (expr.x.size == n);
	Melder_assert (expr.y.size == n);
	for (integer i = 1; i <= n; i ++)
		target [i] *= expr.x [i] + expr.y [i];
}
inline void operator/= (const VECVU& target, TypeVECadd_VEC_VEC expr) noexcept {
	integer n = target.size;
	Melder_assert (expr.x.size == n);
	Melder_assert (expr.y.size == n);
	for (integer i = 1; i <= n; i ++)
		target [i] /= expr.x [i] + expr.y [i];
}
inline autoVEC newVECadd (const constVECVU& x, const constVECVU& y) {
	autoVEC result = newVECraw (x.size);
	result.all() <<= x  +  y;
	return result;
}

extern void VECVUadd_macfast_ (const VECVU& target, const constVECVU& x, const constVECVU& y) noexcept;
inline void VECVUadd (const VECVU& target, const constVECVU& x, const constVECVU& y) noexcept {
	integer n = target.size;
	Melder_assert (x.size == n);
	Melder_assert (y.size == n);
	#if defined (macintoshXXX)
		if (n >= 64)
			return VECVUadd_macfast_ (target, x, y);
	#endif
	for (integer i = 1; i <= n; i ++)
		target [i] = x [i] + y [i];
}

inline void VECcentre_inplace (const VEC& x, double *out_mean = nullptr) noexcept {
	double xmean = NUMmean (x);
	for (integer i = 1; i <= x.size; i ++)
		x [i] -= xmean;
	if (out_mean)
		*out_mean = xmean;
}

inline autoVEC newVECcolumn (const constMAT& source, integer columnNumber) {
	autoVEC target = newVECraw (source.nrow);
	target.all() <<= source.column (columnNumber);
	return target;
}

inline void VECcolumnMeans_preallocated (const VEC& target, const constMAT& x) noexcept {
	Melder_assert (target.size == x.ncol);
	for (integer icol = 1; icol <= x.ncol; icol ++)
		target [icol] = NUMcolumnMean (x, icol);
}
inline autoVEC newVECcolumnMeans (const constMAT& x) {
	autoVEC result = newVECraw (x.ncol);
	VECcolumnMeans_preallocated (result.get(), x);
	return result;
}

inline void VECdivide_preallocated (VEC const& target, constVEC const& x, double factor) noexcept {
	Melder_assert (x.size == target.size);
	for (integer i = 1; i <= x.size; i ++)
		target [i] = x [i] / factor;
}
inline void VECdivide_preallocated (VEC const& target, constVEC const& x, constVEC const& y) noexcept {
	integer n = target.size;
	Melder_assert (x.size == n);
	Melder_assert (y.size == n);
	for (integer i = 1; i <= n; i ++)
		target [i] = x [i] / y [i];
}
inline autoVEC newVECdivide (constVEC const& x, double factor) {
	autoVEC result = newVECraw (x.size);
	VECdivide_preallocated (result.get(), x, factor);
	return result;
}
inline autoVEC newVECdivide (constVEC const& x, constVEC const& y) {
	autoVEC result = newVECraw (x.size);
	VECdivide_preallocated (result.get(), x, y);
	return result;
}

extern void VECmul_preallocated (const VEC& target, const constVEC& vec, const constMAT& mat) noexcept;
extern void VECmul_preallocated (const VEC& target, const constMAT& mat, const constVEC& vec) noexcept;
extern autoVEC newVECmul (const constVEC& vec, const constMAT& mat) noexcept;
extern autoVEC newVECmul (const constMAT& mat, const constVEC& vec) noexcept;

inline void VECmultiply_preallocated (VEC const& target, constVEC const& x, double factor) noexcept {
	Melder_assert (x.size == target.size);
	for (integer i = 1; i <= x.size; i ++)
		target [i] = x [i] * factor;
}
inline void VECmultiply_preallocated (VEC const& target, constVEC const& x, constVEC const& y) noexcept {
	integer n = target.size;
	Melder_assert (x.size == n);
	Melder_assert (y.size == n);
	for (integer i = 1; i <= n; i ++)
		target [i] = x [i] * y [i];
}
inline autoVEC newVECmultiply (constVEC const& x, double factor) {
	autoVEC result = newVECraw (x.size);
	VECmultiply_preallocated (result.get(), x, factor);
	return result;
}
inline autoVEC newVECmultiply (constVEC const& x, constVEC const& y) {
	autoVEC result = newVECraw (x.size);
	VECmultiply_preallocated (result.get(), x, y);
	return result;
}

inline autoVEC newVECrandomGauss (integer size, double mu, double sigma) {
	autoVEC result = newVECraw (size);
	for (integer i = 1; i <= size; i ++)
		result [i] = NUMrandomGauss (mu, sigma);
	return result;
}

inline autoVEC newVECrandomUniform (integer size, double lowest, double highest) {
	autoVEC result = newVECraw (size);
	for (integer i = 1; i <= size; i ++)
		result [i] = NUMrandomUniform (lowest, highest);
	return result;
}

inline void VECsin_inplace (VEC const& x) noexcept {
	for (double& element : x) element = sin (element);
}

extern void VECsort_inplace (VEC const& x) noexcept;

inline void VECsubtractReversed_inplace (VEC const& x, double number) noexcept {
	for (integer i = 1; i <= x.size; i ++)
		x [i] = number - x [i];
}
inline void VECsubtractReversed_inplace (VEC const& x, constVEC const& y) noexcept {
	Melder_assert (x.size == y.size);
	for (integer i = 1; i <= x.size; i ++)
		x [i] = y [i] - x [i];
}
inline void VECsubtract_preallocated (VEC const& target, constVEC const& x, double number) noexcept {
	Melder_assert (x.size == target.size);
	for (integer i = 1; i <= x.size; i ++)
		target [i] = x [i] - number;
}
inline void VECsubtract_preallocated (VEC const& target, double number, constVEC const& x) noexcept {
	Melder_assert (x.size == target.size);
	for (integer i = 1; i <= x.size; i ++)
		target [i] = number - x [i];
}
inline void VECsubtract_preallocated (VEC const& target, constVEC const& x, constVEC const& y) noexcept {
	integer n = target.size;
	Melder_assert (x.size == n);
	Melder_assert (y.size == n);
	for (integer i = 1; i <= n; i ++)
		target [i] = x [i] - y [i];
}
inline autoVEC newVECsubtract (constVEC const& vec, double number) {
	autoVEC result = newVECraw (vec.size);
	VECsubtract_preallocated (result.get(), vec, number);
	return result;
}
inline autoVEC newVECsubtract (double number, constVEC const& vec) {
	autoVEC result = newVECraw (vec.size);
	VECsubtract_preallocated (result.get(), number, vec);
	return result;
}
inline autoVEC newVECsubtract (constVEC const& x, constVEC const& y) {
	Melder_assert (x.size == y.size);
	autoVEC result = newVECraw (x.size);
	for (integer i = 1; i <= x.size; i ++)
		result [i] = x [i] - y [i];
	return result;
}

inline autoVEC newVECsumPerRow (const constMAT& x) {
	autoVEC result = newVECraw (x.nrow);
	for (integer irow = 1; irow <= x.nrow; irow ++)
		result [irow] = NUMrowSum (x, irow);
	return result;
}

inline autoVEC newVECsumPerColumn (const constMAT& x) {
	autoVEC result = newVECraw (x.ncol);
	for (integer icol = 1; icol <= x.ncol; icol ++)
		result [icol] = NUMcolumnSum (x, icol);
	return result;
}

inline autoVEC newVECto (integer to) {
	autoVEC result = newVECraw (to);
	for (integer i = 1; i <= to; i ++)
		result [i] = (double) i;
	return result;
}

/* End of file VEC.h */
