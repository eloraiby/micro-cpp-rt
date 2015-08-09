#include <stdio.h>
#include <stdlib.h>

#include "microcpprt.hpp"

void*	operator new(size_t s)			noexcept	{ return malloc(s); }
void	operator delete(void* p)		noexcept	{ return free(p); }
void*	operator new[](size_t s)		noexcept	{ return malloc(s); }
void	operator delete[](void* p)		noexcept	{ return free(p); }
void*	operator new(size_t /*s*/, void* p)	noexcept	{ return p; }
void*	operator new[](size_t /*s*/, void* p)	noexcept	{ return p; }

#if defined(__GNUC__)
extern "C" void __cxa_pure_virtual(void)	noexcept	{ printf("FATAL ERROR: calling pure virtual!!!\n");	exit(1); }
extern "C" void __cxa_deleted_virtual(void)	noexcept	{ printf("FATAL ERROR: calling deleted virtual!!!\n");	exit(1); }
#endif
