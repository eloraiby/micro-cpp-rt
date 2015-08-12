#ifdef WIN32
#	include <windows.h>
#	include <direct.h>
extern "C" {
char*
get_current_dir(char *__buf, size_t __size) {
	return _getcwd(__buff, __size);
}

void
sleep_ms(unsigned int x) {
	Sleep(x);
}
}
#else
#	include <unistd.h>
#	include <errno.h>
extern "C" {
char*
get_current_dir(char *__buff, size_t __size) {
	return getcwd(__buff, __size);
}

void
sleep_ms(unsigned int x) {
	usleep((x)*1000);
}
}
#endif

