#include<stdio.h>
#include<string.h>

int abs(int n)
{
	return n<0?-n:n;
}

void GetBaseString(char* str, char* base, int freq[])
{
	base[0] = str[0];
	freq[0] = 1;
	int length = 1;
	for(int i=1; str[i]!=NULL; i++)
	{
		if(str[i] == base[length-1])
			freq[length-1]++;
		else
		{
			freq[length] = 1;
			base[length] = str[i];
			++length;
		}
	}
	base[length] = NULL;
}

int N;
char str[105][105];
char base[105][105];
int freq[105][105];

int diff()
{
	for(int i=0;i<N;i++)
		GetBaseString(str[i], base[i], freq[i]);
	for(int i=1;i<N;i++)
	{
		if(strcmp(base[0], base[i])!=0)
			return -1;
	}
	int length = strlen(base[0]);
	int res = 0;
	for(int i=0;i<length;i++)
	{
		int max = 0;
		for(int j=0;j<N;j++)
		{
			if(freq[j][i]>max)
				max = freq[j][i];
		}
		int min = 999999999;
		for(int test = 1; test <= max; test++)
		{
			int total = 0;
			for(int j=0;j<N;j++)
				total += abs(test - freq[j][i]);
			if(total < min)
				min = total;
		}
		res+=min;
	}
	return res;
}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%s", str[i]);
		int res = diff();
		if(res==-1)
			printf("Case #%d: Fegla Won\n", cs);
		else
			printf("Case #%d: %d\n", cs, res);
	}
}