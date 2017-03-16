#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;
const int N = 100+10;
char str[N][N];
int n;
struct myStr
{
	char ch;
	int freq;
};
vector<myStr>v[N];

void process(char s[], int id)
{
	int len = strlen(s);
	char pre = s[0];
	int cnt = 1;
	for(int i = 1; i < len; i++)
	{
		if(s[i] == pre)
		{
			cnt ++;
		}
		else
		{
			myStr temp;
			temp.ch = pre;
			temp.freq = cnt;
			v[id].push_back(temp);
			pre = s[i];
			cnt = 1;
		}
	}
	myStr temp;
	temp.ch = pre;
	temp.freq = cnt;
	v[id].push_back(temp);
}
int getMinCost(vector<int> t)
{
	int sz = t.size();
	int minCost = 0x7fffffff;
	for(int i = 0; i < sz; i++)
	{
		int curFreq = t[i];
		int curCost = 0;
		for(int j = 0; j < sz; j++)
		{
			int f = t[j];
			curCost += abs(f-curFreq);
		}
		minCost = min(minCost, curCost);
	}
	return minCost;
}
int getAns()
{
	int sz = v[0].size();
	for(int i = 0; i < n; i++)
	{
		int cur_sz = v[i].size();
		if(cur_sz != sz)
		{
			//printf("die size\n");
			return -1;
		}
	}
	int ret = 0;
	for(int j = 0; j < sz; j++)
	{
		myStr first;
		first.ch = v[0][j].ch;
		first.freq = v[0][j].freq;
		vector<int>tmp;
		tmp.push_back(first.freq);
		for(int i = 1; i < n; i++)
		{
			if(v[i][j].ch != first.ch)
			{
				//printf("die char\n");
				return -1;
			}
			else
				tmp.push_back(v[i][j].freq);
		}
		ret += getMinCost(tmp);
	}
	return ret;
}
int main()
{
	int T;
	int p=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d", &n);
		int maxlen = 0;
		for(int i = 0; i < N; i++)
			v[i].clear();
		for(int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
			process(str[i], i);
		}
		int ret = getAns();
		if(ret==-1)
			printf("Case #%d: Fegla Won\n",p++);
		else
			printf("Case #%d: %d\n",p++, ret);
	}
	return 0;
}