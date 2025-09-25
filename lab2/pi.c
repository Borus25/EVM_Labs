#include <stdio.h>
#include <sys/times.h>
#include <unistd.h>

int main() {
	unsigned long long  N;
	scanf("%lld\n", &N);
	
	struct tms start, end;
	long clocks_per_sec = sysconf(_SC_CLK_TCK);
	long clocks;

	double pi = 0;

	times(&start);
	for (int i = 0; (unsigned long long)i < N; i++) {
		double  add_or_sub = (i % 2 == 0) ? 1.0 : -1.0;
		pi += 4 * add_or_sub / (2 * i + 1);
	}
	times(&end);

	printf("Pi: %10.8f\n", pi);
	clocks = end.tms_utime - start.tms_utime;
	printf("Times taken: %lf sec.\n", (double) clocks / clocks_per_sec);
	
	return 0;
}

