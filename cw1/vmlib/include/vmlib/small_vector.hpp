#ifndef SMALL_VECTOR_HPP_214E3703_A050_411A_834B_4E55AEEC18B8
#define SMALL_VECTOR_HPP_214E3703_A050_411A_834B_4E55AEEC18B8

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstddef>

/** SmallVec<N,type>: N-D vector of type elements.
 *
 * The type deliberately stores its elements directly.  This keeps it
 * standard-layout and trivially copyable, with no dynamic memory allocation.
 */
template< std::size_t tSize, typename tType = float >
struct SmallVec
{
	tType v[tSize];

	constexpr
	tType& operator[] (std::size_t aIdx) noexcept
	{
		assert( aIdx < tSize );
		return v[aIdx];
	}

	constexpr
	tType const& operator[] (std::size_t aIdx) const noexcept
	{
		assert( aIdx < tSize );
		return v[aIdx];
	}
		
	// 中文提示：返回可修改的数据指针，便于传给需要连续数组的 API。
	constexpr
	tType* data() noexcept
	{
		return v;
	}

	constexpr
	tType const* data() const noexcept
	{
		return v;
	}
};

/* Named accessors for 2D vectors. */
template< typename tType >
struct SmallVec<2,tType>
{
	tType x, y;

	constexpr
	tType& operator[] (std::size_t aIdx) noexcept
	{
		assert( aIdx < 2 );
		return (&x)[aIdx];
	}

	constexpr
	tType const& operator[] (std::size_t aIdx) const noexcept
	{
		assert( aIdx < 2 );
		return (&x)[aIdx];
	}

	constexpr
	tType* data() noexcept
	{
		return &x;
	}

	constexpr
	tType const* data() const noexcept
	{
		return &x;
	}
};

/* Named accessors for 3D vectors. */
template< typename tType >
struct SmallVec<3,tType>
{
	tType x, y, z;

	constexpr
	tType& operator[] (std::size_t aIdx) noexcept
	{
		assert( aIdx < 3 );
		return (&x)[aIdx];
	}

	constexpr
	tType const& operator[] (std::size_t aIdx) const noexcept
	{
		assert( aIdx < 3 );
		return (&x)[aIdx];
	}

	constexpr
	tType* data() noexcept
	{
		return &x;
	}

	constexpr
	tType const* data() const noexcept
	{
		return &x;
	}
};

/* Named accessors for 4D vectors. */
template< typename tType >
struct SmallVec<4,tType>
{
	tType x, y, z, w;

	constexpr
	tType& operator[] (std::size_t aIdx) noexcept
	{
		assert( aIdx < 4 );
		return (&x)[aIdx];
	}

	constexpr
	tType const& operator[] (std::size_t aIdx) const noexcept
	{
		assert( aIdx < 4 );
		return (&x)[aIdx];
	}

	constexpr
	tType* data() noexcept
	{
		return &x;
	}

	constexpr
	tType const* data() const noexcept
	{
		return &x;
	}
};

// Helpers
template< std::size_t tSize, typename tType > constexpr
std::size_t dimension( SmallVec<tSize,tType> ) noexcept
{
	return tSize;
}

// Operators
template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType> operator+ (SmallVec<tSize,tType> const& aVec ) noexcept
{
	return aVec;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType> operator- (SmallVec<tSize,tType> const& aVec ) noexcept
{
	SmallVec<tSize, tType> ret{};
	for( std::size_t i = 0; i < tSize; ++i )
		ret[i] = -aVec[i];
	return ret;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType> operator+ (SmallVec<tSize,tType> const& aLhs, SmallVec<tSize,tType> const& aRhs ) noexcept
{
	SmallVec<tSize, tType> ret{};
	for( std::size_t i = 0; i < tSize; ++i )
		ret[i] = aLhs[i] + aRhs[i];
	return ret;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType> operator- (SmallVec<tSize,tType> const& aLhs, SmallVec<tSize,tType> const& aRhs ) noexcept
{
	SmallVec<tSize, tType> ret{};
	for( std::size_t i = 0; i < tSize; ++i )
		ret[i] = aLhs[i] - aRhs[i];
	return ret;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType> operator* (tType aScalar, SmallVec<tSize,tType> const& aRhs ) noexcept
{
	SmallVec<tSize, tType> ret{};
	for( std::size_t i = 0; i < tSize; ++i )
		ret[i] = aScalar * aRhs[i];
	return ret;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType> operator* (SmallVec<tSize,tType> const& aLhs, tType aScalar ) noexcept
{
	return aScalar * aLhs;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType> operator/ (SmallVec<tSize,tType> const& aLhs, tType aScalar ) noexcept
{
	SmallVec<tSize, tType> ret{};
	for( std::size_t i = 0; i < tSize; ++i )
		ret[i] = aLhs[i] / aScalar;
	return ret;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType>& operator+= (SmallVec<tSize,tType>& aLhs, SmallVec<tSize,tType> const& aRhs ) noexcept
{
	for( std::size_t i = 0; i < tSize; ++i )
		aLhs[i] += aRhs[i];
	return aLhs;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType>& operator-= (SmallVec<tSize,tType>& aLhs, SmallVec<tSize,tType> const& aRhs ) noexcept
{
	for( std::size_t i = 0; i < tSize; ++i )
		aLhs[i] -= aRhs[i];
	return aLhs;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType>& operator*= (SmallVec<tSize,tType>& aLhs, tType aScalar ) noexcept
{
	for( std::size_t i = 0; i < tSize; ++i )
		aLhs[i] *= aScalar;
	return aLhs;
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize, tType>& operator/= (SmallVec<tSize,tType>& aLhs, tType aScalar ) noexcept
{
	for( std::size_t i = 0; i < tSize; ++i )
		aLhs[i] /= aScalar;
	return aLhs;
}

// Common operations
template< std::size_t tSize, typename tType > constexpr
tType dot( SmallVec<tSize,tType> const& aLhs, SmallVec<tSize,tType> const& aRhs ) noexcept
{
	tType ret = tType(0);
	for( std::size_t i = 0; i < tSize; ++i )
		ret += aLhs[i] * aRhs[i];
	return ret;
}

template< std::size_t tSize, typename tType > inline
tType length( SmallVec<tSize,tType> const& aVec ) noexcept
{
	return static_cast<tType>( std::sqrt( static_cast<long double>( dot(aVec, aVec) ) ) );
}

template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize,tType> normalize( SmallVec<tSize,tType> const& aVec ) noexcept
{
	return aVec / length(aVec);
}

// Only for Vec<3,type>
template< typename tType > constexpr
SmallVec<3,tType> cross( SmallVec<3,tType> const& aLhs, SmallVec<3,tType> const& aRhs ) noexcept
{
	return SmallVec<3,tType>{
		aLhs[1] * aRhs[2] - aLhs[2] * aRhs[1],
		aLhs[2] * aRhs[0] - aLhs[0] * aRhs[2],
		aLhs[0] * aRhs[1] - aLhs[1] * aRhs[0]
	};
}

#endif // SMALL_VECTOR_HPP_214E3703_A050_411A_834B_4E55AEEC18B8
