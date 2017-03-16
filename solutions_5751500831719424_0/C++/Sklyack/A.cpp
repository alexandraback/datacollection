#include <cstdio>
#include <cstring>

const int INF = 1e9;
const int MAXN = 100, MAXLEN = 100;
char L[MAXN][MAXLEN+1];
int cnt[MAXN][MAXLEN];
char buf[MAXLEN+1];

int conv(char *S, int iword)
{
	char *ptr, c0, c1;
	int ngroups = 0, curr_cnt;
	ptr = S;
	c0 = *ptr;
	while(c0)
	{
		curr_cnt = 0;
		for(c1 = c0; c1 == c0; ++ptr, c1 = *ptr)
			++curr_cnt;
		L[iword][ngroups] = c0;
		cnt[iword][ngroups] = curr_cnt;
		++ngroups;
		c0 = c1;
	}
	L[iword][ngroups] = 0;
	return ngroups;
}

inline int mabs(int x)
{
	return x < 0 ? -x : x;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ncases, cs;
	scanf("%d", &ncases);
	for(cs = 1; cs <= ncases; ++cs)
	{
		int nwords, iword, igroup;
		int ngroups;
		scanf("%d", &nwords);
		scanf("%s", buf);
		ngroups = conv(buf, 0);
		bool imp = false;
		for(iword = 1; iword < nwords; ++iword)
		{
			scanf("%s", buf);
			if(conv(buf, iword) != ngroups)
				imp = true;
			if(strcmp(L[0], L[iword]) != 0)
				imp = true;
		}
		if(imp)
		{
			printf("Case #%d: Fegla Won\n", cs);
			continue;
		}

		int ans = 0, gr_ans, gr_tmp;
		int mx_cnt;
		int curr_cnt;
		for(igroup = 0; igroup < ngroups; ++igroup)
		{
			mx_cnt = 0;
			for(iword = 0; iword < nwords; ++iword)
				if(cnt[iword][igroup] > mx_cnt)
					mx_cnt = cnt[iword][igroup];
			gr_ans = INF;
			for(curr_cnt = 1; curr_cnt <= mx_cnt; ++curr_cnt)
			{
				gr_tmp = 0;
				for(iword = 0; iword < nwords; ++iword)
					gr_tmp += mabs(cnt[iword][igroup] - curr_cnt);
				if(gr_tmp < gr_ans)
					gr_ans = gr_tmp;
			}
			ans += gr_ans;
		}

		printf("Case #%d: %d\n", cs, ans);
	}
	return 0;
}
