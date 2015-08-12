#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#ifndef MICROCPPRT_HPP
#	include "microcpprt.hpp"
#endif

extern "C" {
char*	get_current_dir(char *__buf, size_t __size);
void	sleep_ms(unsigned int ms);
}

#endif // SYSTEM_HPP
