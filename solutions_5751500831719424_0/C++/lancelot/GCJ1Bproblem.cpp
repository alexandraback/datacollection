#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int charcount[101][101];
char charat[101][101];
char str[202];
int tcount[101];
int maxnum[101];
int minnum[101];

int num[101];
int mincost(int n)
{
	sort(num, num+n);
	int a = num[n/2];
	int b = num[(n-1)/2];
	int suma = 0, sumb = 0;
	for(int i=0;i<n;i++)
	{
		suma += abs(num[i] - a);
		sumb += abs(num[i] - b);
	}
	return suma>sumb?sumb:suma;
}

int main()
{
	freopen("as.in", "r" ,stdin);
	freopen("as.out", "w",stdout);
	memset(charat,0,sizeof(charat));
	int casen;
	scanf("%d",&casen);
	for(int C = 1;C<= casen;C++)
	{
		int n;
		scanf("%d", &n);
		for(int i =0 ;i<n;i++)
		{
			scanf("%s",str);
			int len = strlen(str);
			// cerr<<str<<" "<<strlen(str)<<endl;
			int ct = 0;
			for(int j = 0; j< len;j++)
			{
				if( j ==0)
				{
					charat[i][ct] = str[j];
					charcount[i][ct] = 1;
				}
				else if( str[j]!=charat[i][ct])
				{
					ct++;
					charat[i][ct] = str[j];
					charcount[i][ct] = 1;
				}
				else if(str[j]==charat[i][ct])
				{
					charcount[i][ct]++;
				}
			}
			ct++;
			tcount[i]=ct;
		}
		for(int i = 0; i < n;i++)
		{
			if(tcount[i]!=tcount[0])
				tcount[0]= -1;
			for(int j = 0; j<tcount[i];j++)
			{
				if(charat[i][j]!=charat[0][j])
					tcount[0]= -1;
			}
		}

		int res = 0;

		for(int j=0 ;j < tcount[0];j++)
		{
			maxnum[j] = 0;
			minnum[j] = 101;
			for(int i = 0; i < n;i++)
			{
				num[i] = charcount[i][j];
				// if(charcount[i][j]>maxnum[j])
				// 	maxnum[j] = charcount[i][j];
				// if(charcount[i][j]<minnum[j])
				// 	minnum[j] = charcount[i][j];
			}
			// int mintmp = 0, maxtmp = 0;
			// for(int i = 0;i<n;i++)
			// 	mintmp+= charcount[i][j] - minnum[j];
			
			// for(int i = 0;i<n;i++)
			// 	maxtmp += maxnum[j] - charcount[i][j];
			res+= mincost(n);


		}

		printf("Case #%d: ",C);
		if(tcount[0] == -1)
			printf("Fegla Won\n");
		else 
		{
			printf("%d\n", res);
		}
	}

	return 0;
}