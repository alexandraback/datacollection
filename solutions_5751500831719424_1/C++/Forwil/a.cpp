/*
ID: forwil11
PROG: gcj rb a
LANG: C++
*/
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,t,T,f[101][101];
string arr[101];

void get_zip(string &to,string &from)
{
	int len = from.size();
	to = "";
	to += from[0];
	for(int i =0;i<len -1;i++)
		if(from[i]!=from[i+1])
			to += from[i+1];	
}

int get_same()
{
	string same,temp;
	get_zip(same,arr[0]);	
	for(int i = 1;i<n;i++)
	{
		get_zip(temp,arr[i]);
		if(temp.compare(same) != 0)
			return 0;
	}	
	return 1;
}

int count(int f[],string s)
{
	char c;
	int len = 0,slen = s.size();
	c = s[0];
	for(int	i =0;i< slen;i++)
	{
		if(c != s[i])
		{
			c = s[i];
			len += 1;
		}
		f[len] += 1;
	}
//	cout << s <<endl;
//	for(int i =0;i<len+1;i++)
//		cout << f[i] << " ";
//	cout << endl;
	return len + 1;
}

int count_max(int x)
{
	int min = 1<<30;
	for(int i =0;i<n;i++)
	{
		int sum = 0;
		for(int j=0;j<n;j++)
			sum += abs(f[i][x] - f[j][x]);
		if(sum < min)
			min = sum;	
	}
	return min;
}

int main(void){
	int len,ans = 0,max = 0;
	cin >> T;
	for(int t = 1;t<=T;t++)
	{
		cout << "Case #" << t << ": ";
		cin >> n;
		for(int i = 0;i<n;i++)
			cin >> arr[i];

		if(! get_same())	
		{
			cout << "Fegla Won"<< endl;
			continue;
		}
		
		memset(f,0,sizeof(f));
		for(int i =0;i<n;i++)
			len = count(f[i],arr[i]);
		ans = 0;
		for(int i =0;i<len;i++)
		{
			max = count_max(i);
			//cout << endl << i << "max" << max; 
			ans += max;
		}
		cout << ans << endl;
	}
	return 0;
}
