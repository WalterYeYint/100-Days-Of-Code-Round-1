#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <time.h>
#include <stddef.h>
#include <sys/un.h>
#include <limits.h>

int main( int argc, char *argv[] ) {
  struct timespec interval, remainder;
	unsigned long nanoseconds;
	unsigned long seconds;
	double precise;

	nanoseconds = (unsigned long)atol( argv[1] );
	if( LONG_MAX == nanoseconds )
		fprintf( stderr, "Value too high! Using maximum allowable value, %lu.\n", nanoseconds );
	seconds = nanoseconds / 1000000000;
	nanoseconds %= 1000000000;	

	interval.tv_sec = seconds;
	interval.tv_nsec = nanoseconds;

	precise = nanoseconds / 1000000000.0;

	//fprintf( stderr, "Sleeping for: %lu seconds, %lu nanoseconds (%0.9f seconds)...\n", seconds, nanoseconds, precise );
	nanosleep(&interval, &remainder);
	return;
}