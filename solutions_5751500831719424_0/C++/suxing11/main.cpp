# include <stdio.h>
# include <string.h>


char s[110][110];
char str[110][110];
int dp[110][110];

int n, m;


void strtostr(char s[], char t[])
{
	int i, cc = 1;
	t[0] = s[0];
	for (i = 1; s[i] ; i++)
	{
		if (s[i] != s[i-1])
			t[cc++] = s[i];
	}
	t[cc++] = '\0';
}


int abs(int x){return x < 0 ? -x : x;}


int gao()
{
	int i, j, cc, k;
	for (i = 0; i < n; i++)
		if (strcmp(str[i], str[0])) return -1;
	m = strlen (str[0]);
	
	for (i = 0; i < n; i++)
	{
		cc = 1;
		dp[i][0] = 1;
		for (j = 1; s[i][j]; j++)
			if (s[i][j] != s[i][j-1])
				dp[i][cc++] = 1;
			else
				dp[i][cc-1] ++;
	}
	
	int ans_buff, buff, ans;
	ans = 0;
	for (j = 0; j < m; j++)
	{
		ans_buff = 0x0f0f0f0f;
		for (k = 1; k <= 100; k++)
		{
			buff = 0;
			for (i = 0; i < n; i++)
				buff += abs(dp[i][j] - k);
			if (buff  <  ans_buff) ans_buff = buff;
		}
		ans += ans_buff;
	}
	return ans;
}


int main ()
{
	int T, ans,nCase = 1;
	int i;
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("a_out.txt", "w", stdout);
	scanf ("%d", &T);
	//while (T--)
	for (nCase = 1; nCase <= T; nCase++)
	{
		scanf ("%d", &n);
		for (i = 0; i < n; i++)
			scanf ("%s", s[i]), strtostr(s[i], str[i]);
		ans = gao();
		printf ("Case #%d: ", nCase);
		if (ans == -1) printf ("Fegla Won\n");
		else printf ("%d\n", ans);
	}
	return 0;
}
