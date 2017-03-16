#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

string x[100];
int calc(int count[100][100],int N, int len)
{
	int ans = 0,temp[100],index;
	int i, j;

	//for (i = 0; i < N; i++)
	//{
	//	for (j = 0; j < len; j++)
	//		printf("%i\t", count[i][j]);
	//	printf("\n");
	//}
	

	for (j = 0; j < len; j++)
	{
		for (i = 0; i < N; i++)
		{
			temp[i] = count[i][j];
		}
		sort(temp, temp + N);
		//for (i = 0; i < N; i++)
			//printf(",%i,", temp[i]);
		index = (N + 1) / 2 - 1;
		//printf("%i", index);
		for (i = 0; i < N; i++)
		{
			if (i < index)
			{
				ans = ans - (temp[i] - temp[index]);
			}
			else
			{
				ans = ans + (temp[i] - temp[index]);
			}
				
		}
	}
	return ans;
}
void solve()
{
	int N, i, j, k,count[100][100], len[100],flag=1,templen;
	char c[100][100],temp,tempc[100];

	for (i = 0; i < 100; i++)
	{
		len[i] = -1;
		for (j = 0; j < 100; j++)
		{
			count[i][j] = 0;
		}
	}
	
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		cin >> x[i];
	
	for (i = 0; i < N; i++)
	{
		temp = ' ';
		//printf("stringline:%d\n", x[i].length());
		for (j = 0; j < x[i].length(); j++)
		{
			if (x[i][j] != temp)
			{
				temp = x[i][j];
				len[i]++;
				c[i][len[i]] = temp;
				count[i][len[i]]=1;
			}
			else
			{
				count[i][len[i]]++;
			}
		}
		//printf("Line:%i\n", len[i]);
		//for (k = 0; k < len[i]+1; k++)
		//{
		//	printf("%c::%i\n", c[i][k], count[i][k]);
		//}		
	}
	templen = len[0] + 1;
	for (k = 0; k < templen; k++)
	{
		tempc[k] = c[0][k];
		//printf("%c", tempc[k]);
	}
	for (i = 1; i < N; i++)
	{
		//printf("\n%i==%i\n", len[i]+1, templen);
		if (len[i]+1 != templen)
		{
			flag = 0;
			break;
		}
		else
		{
			for (k = 0; k < templen; k++)
			{
				//printf("\n%c==%c\n", c[i][k], tempc[k]);
				if (c[i][k] != tempc[k])
				{
					flag = 0;
					k = templen;
					i = N;
				}
			}
		}
	}

	if (flag == 0)
	{
		printf("Fegla Won\n");
	}
	else{
		printf("%i\n",calc(count,N,templen));
	}
			
}

int main()
{
	int T;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}