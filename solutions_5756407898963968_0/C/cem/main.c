#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SCANF(fmt, n, args...)						\
do {									\
	int __rc = scanf(fmt, args);					\
	if (__rc != (n))						\
		die("scanf: wanted %d, got %d", (int)(n), __rc);	\
} while (false)

static void
die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);

	exit(1);
}

static void
skip_n(unsigned n)
{
	unsigned x;

	for (unsigned i = 0; i < n; i++)
		SCANF("%u", 1, &x);
}

int
main(void)
{
	uintmax_t T, i;
	unsigned row[4];
	int chose = -1;

	SCANF("%ju", 1, &T);

	for (i = 1; i <= T; i++) {
		unsigned A, ans = 0;

		chose = -1;

		SCANF("%u", 1, &A);

		skip_n(4 * (A - 1));

		for (unsigned XXX = 0; XXX < 4; XXX++)
			SCANF("%u", 1, &row[XXX]);

		skip_n(4 * (4 - A));

		// second answer
		SCANF("%u", 1, &A);

		skip_n(4 * (A - 1));
		for (unsigned XXX = 0; XXX < 4; XXX++) {
			unsigned entry;

			SCANF("%u", 1, &entry);

			for (unsigned z = 0; z < 4; z++) {
				if (row[z] == entry) {
					chose = entry;
					ans++;
				}
			}

		}
		skip_n(4 * (4 - A));

		if (ans == 0)
			printf("Case #%ju: Volunteer cheated!\n", i);
		else if (ans == 1)
			printf("Case #%ju: %d\n", i, chose);
		else
			printf("Case #%ju: Bad magician!\n", i);

	}

	return 0;
}
