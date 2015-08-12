#ifndef MICROCPPRT_HPP
#define MICROCPPRT_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <climits>

#include <cassert>

#ifdef max
#	undef max
#endif

#ifdef min
#	undef min
#endif

#ifndef MICROCPP_RT_API
#	ifdef BUILDING_MICROCPP_RT_STATIC
#		define MICROCPP_RT_API
#		define MICROCPP_RT_LOCAL_API
#	else
#		if defined _WIN32 || defined __CYGWIN__
#			ifdef BUILD_MICROCPP_RT_SHARED
#				ifdef __GNUC__
#					define MICROCPP_RT_API __attribute__ ((dllexport))
#				else
#					define MICROCPP_RT_API __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#				endif
#			else
#				ifdef __GNUC__
#					define MICROCPP_RT_API __attribute__ ((dllimport))
#				else
#					define MICROCPP_RT_API __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#				endif
#			endif	// BUILD_MICROCPP_RT_SHARED
#			define MICROCPP_RT_LOCAL_API
#		else
#			if __GNUC__ >= 4
#				define MICROCPP_RT_API __attribute__ ((visibility ("default")))
#				define MICROCPP_RT_LOCAL_API  __attribute__ ((visibility ("hidden")))
#			else
#				define MICROCPP_RT_API
#				define MICROCPP_RT_LOCAL_API
#			endif
#		endif
#	endif
#endif	// MICROCPP_RT_API

MICROCPP_RT_API void*	operator new(size_t s)			noexcept;
MICROCPP_RT_API void	operator delete(void* p)		noexcept;
MICROCPP_RT_API void*	operator new[](size_t s)		noexcept;
MICROCPP_RT_API void	operator delete[](void* p)		noexcept;
MICROCPP_RT_API void*	operator new(size_t /*s*/, void* p)	noexcept;
MICROCPP_RT_API void*	operator new[](size_t /*s*/, void* p)	noexcept;

namespace mcpp {

	template <typename T>
	T min(const T& a, const T& b) noexcept { return a < b ? a : b; }

	template <typename T>
	T max(const T& a, const T& b) noexcept { return a > b ? a : b; }


	template <typename T>
	void fill_n(T* arr, size_t s, const T& val) noexcept { for( size_t i = 0; i < s; ++i ) arr[i] = val; }

}

#include "system.hpp"

#endif // MICROCPPRT_HPP
