#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
char str[110][110];

char us[110][110];
int cnt[110][110];

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t, tt=0;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i=0; i<n; i++) scanf ("%s", str[i]);

		for (int i=0; i<n; i++) {
			strcpy (us[i], str[i]);
			us[i][ unique (us[i], us[i]+strlen(us[i])) - us[i] ] = 0;
		}
		bool fwin = false;
		for (int i=1; i<n; i++) {
			if (strcmp (us[i], us[0]) != 0) {
				fwin = true;
				break;
			}
		}
		printf ("Case #%d: ", ++tt);
		if (fwin) {printf ("Fegla Won\n"); continue;}

		m = strlen (us[0]);

		memset(cnt, 0, sizeof(cnt));
		for (int i=0; i<n; i++) {
			int p = 0;
			for (int j=0; j<m; j++) {
				while (str[i][p] == us[i][j]) cnt[i][j]++, p++;
			}
		}

		int ans=0;
		for (int i=0; i<m; i++) {
			int tmp[110];
			for (int j=0; j<n; j++) {
				tmp[j] = cnt[j][i];
			}
			sort (tmp, tmp+n);
			int mid = tmp[n/2];

			for (int j=0; j<n; j++)
				ans += abs (tmp[j] - mid);
		}

		printf ("%d\n", ans);
	}
	return 0;
}
