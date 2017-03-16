#include <iostream>
using namespace std;
 

int Row, Col, Number;
 #include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<list>
#include<queue>
#include<vector>
#include<set>
#include<stdlib.h>
#include<queue>
#include<stack>
#define ff first
#define ss second
#define mod 1000000007
int hasherarray[1000];
int counting[1 << 18];
using namespace std;
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
long long int calculate(long long int); 
int main() 
{
freopen("abc.txt","r",stdin);
	freopen("prq.txt","w",stdout);
	int T;
	//cin >> T;
	T=read_int();
	for (int t = 1; t <= T; t++)
	{
		//cin >> Row >> Col >> Number;
          Row=read_int();
          Col=read_int();
          Number=read_int();
          long long int temp=0;
 		long long int  bestestans = Row * Col * Number * 100;
		for (long long int i = 1; i < (1 << (Row * Col)); i++)
		{
			counting[i] = counting[i - (i & -i)] + 1;
			if (counting[i] == Number)
			{
			 temp=calculate(i);
			 bestestans = min(bestestans, temp);
		     }
		}
		printf("Case #%d: %d\n", t, bestestans);
	}
}
long long int calculate(long long int num)
{
	long long int answer = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			
			if (i > 0 and (num & (1 << (i * Col + j))) and (num & (1 << (i * Col + j - Col))))
				answer++;
				if (j > 0 and (num & (1 << (i * Col + j))) and (num & (1 << (i * Col + j - 1))))
				answer++;
		}
	}
	return answer;
}

