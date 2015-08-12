#include <stdio.h>
#include <stdlib.h>

#include "microcpprt.hpp"

MICROCPP_RT_API void*	operator new(size_t s)			noexcept	{ return malloc(s); }
MICROCPP_RT_API void	operator delete(void* p)		noexcept	{ return free(p); }
MICROCPP_RT_API void*	operator new[](size_t s)		noexcept	{ return malloc(s); }
MICROCPP_RT_API void	operator delete[](void* p)		noexcept	{ return free(p); }
MICROCPP_RT_API void*	operator new(size_t /*s*/, void* p)	noexcept	{ return p; }
MICROCPP_RT_API void*	operator new[](size_t /*s*/, void* p)	noexcept	{ return p; }

#if defined(__GNUC__)
extern "C" {
MICROCPP_RT_API void	__cxa_pure_virtual(void)		noexcept	{ assert("FATAL ERROR: calling pure virtual!!!\n");	exit(1); }
MICROCPP_RT_API void	__cxa_deleted_virtual(void)		noexcept	{ assert("FATAL ERROR: calling deleted virtual!!!\n");	exit(1); }
}
#endif
