#ifndef SMALL_VECTOR_HPP_214E3703_A050_411A_834B_4E55AEEC18B8
#define SMALL_VECTOR_HPP_214E3703_A050_411A_834B_4E55AEEC18B8

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstddef>

template< std::size_t tSize, typename tType = float >
struct SmallVec
{
	//Store vector elements of arbitrary dimensions using an array
	tType v[tSize];

	//For non-const objects, the corresponding elements can be modified via subscripting
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


template< typename tType >
struct SmallVec<2,tType>
{
	//the first two elements are directly named x and y for 2D vector
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

//Add z to 3D vector
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

//Add w to 4D vector: Homogeneous coordinates
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

template< std::size_t tSize, typename tType > constexpr
std::size_t dimension( SmallVec<tSize,tType> ) noexcept
{
	return tSize;
}

//Vector addition involves adding corresponding elements one by one
//Subtraction also involves subtracting corresponding elements one by one
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

//Scalar multiplication involves multiplying every element in a vector by the same number
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

//Directly modify the left vector and finally return itself
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

//The dot product is the sum of the products of corresponding elements
template< std::size_t tSize, typename tType > constexpr
tType dot( SmallVec<tSize,tType> const& aLhs, SmallVec<tSize,tType> const& aRhs ) noexcept
{
	tType ret = tType(0);
	for( std::size_t i = 0; i < tSize; ++i )
		ret += aLhs[i] * aRhs[i];
	return ret;
}

//The length is equal to the square root of the result of the dot product
template< std::size_t tSize, typename tType > inline
tType length( SmallVec<tSize,tType> const& aVec ) noexcept
{
	return static_cast<tType>( std::sqrt( static_cast<long double>( dot(aVec, aVec) ) ) );
}

//After normalization the direction remains unchanged, but the length becomes 1
template< std::size_t tSize, typename tType > constexpr
SmallVec<tSize,tType> normalize( SmallVec<tSize,tType> const& aVec ) noexcept
{
	return aVec / length(aVec);
}

//The cross product result is perpendicular to both input 3D vectors
template< typename tType > constexpr
SmallVec<3,tType> cross( SmallVec<3,tType> const& aLhs, SmallVec<3,tType> const& aRhs ) noexcept
{
	return SmallVec<3,tType>{
		aLhs[1] * aRhs[2] - aLhs[2] * aRhs[1],
		aLhs[2] * aRhs[0] - aLhs[0] * aRhs[2],
		aLhs[0] * aRhs[1] - aLhs[1] * aRhs[0]
	};
}

#endif
