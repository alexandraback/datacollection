#include <stdio.h>
#include <algorithm>
#include <string.h>

int main() {

	int t, _t;
	scanf("%d", &t);

	for ( _t = 0; _t < t; ++_t ) {
		int n;
		scanf("%d", &n);
		char str[101][101];
		int len[101];
		int i;
		for ( i = 0; i < n; ++i ) {
			scanf("%s", str[i]);
			len[i] = strlen(str[i]);
		}

		int count[101][107];
		char what[101][107];
		memset(count, 0, sizeof(count));
		memset(what, 0, sizeof(what));

		int j = 0;
		int last1 = 0;
		for ( j = 0; j < n; ++j ) {
		int last = 1;
		last1 = 0;
		for ( i = 1; i < len[j]; ++i ) {
			if ( str[j][i] == str[j][i-1] )
				++last;
			else {
				count[j][last1++] = last;
				what[j][last1-1] = str[j][i-1];
				last = 1;
			}
		}
		if ( len[j] == 1 || last ) {
			count[j][last1++] = last;
			what[j][last1-1] = str[j][i-1];
		}
		}

		int skip = 0;
		for ( i = 0; i < n-1; ++i ) {
		if ( strcmp(what[i], what[i+1]) != 0 ) {
			printf("Case #%d: Fegla Won\n", _t+1);
			skip = 1;
			break;
		}
		}
		if ( skip ) continue;

		int ret = 0;
		for ( i = 0; i < last1; ++i ) {
			int j;
			int ss[107];
			for ( j = 0; j < n; ++j ) {
				ss[j] = count[j][i];
			}
			std::sort(ss, ss+n);
			int med = ss[n/2];
			for ( j = 0; j < n; ++j )
				ret += abs(med - count[j][i]);
		}

		printf("Case #%d: %d\n", _t+1, ret);
	}

	return 0;

}
