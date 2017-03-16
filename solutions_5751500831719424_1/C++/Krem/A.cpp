#include<cstdio>
#include<algorithm>

char txt[110];
char letters[110];
int count[110][110];

int abs(int x) {return (x<0)?-x:x;}

int main()
{
	int T; scanf("%d", &T);
	for(int ii = 0; ii < T; ii++)
	{
		int N; scanf("%d", &N);
		bool total_fail = 0;
		scanf("%s",txt);
		int idx = 0;
		for(int j = 0; txt[j]; j++)
		{
			char c = txt[j];
			int cnt = 1;
			while(c == txt[j+1]) {j++; cnt++;}
			count[idx][0] = cnt;
			letters[idx] = c;
			idx++;
		}
		int len = idx;
		for(int i = 1; i < N; i++)
		{
			scanf("%s",txt);
			if(total_fail) continue;
			idx = 0;
			for(int j = 0; txt[j]; j++)
			{
				char c = txt[j];
				if(c != letters[idx])
					{total_fail = 1; break;}
				int cnt = 1;
				while(c == txt[j+1]) {j++; cnt++;}
				count[idx][i] = cnt;
				idx++;
			}
			if(idx != len)
				total_fail = 1;
		}
		if(total_fail)
			printf("Case #%d: Fegla Won\n",ii+1);
		else
		{
			int res = 0;
			for(int i = 0; i < len; i++)
			{
				std::sort(count[i], count[i]+N);
				for(int j = 0; j < N; j++)
					res += abs(count[i][j] - count[i][N/2]);
			}
			printf("Case #%d: %d\n", ii+1, res);
		}
	}
	
	return 0;
}
