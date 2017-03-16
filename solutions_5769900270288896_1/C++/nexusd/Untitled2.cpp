#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
typedef long long int lli;
typedef long int li;
#define ff first
#define ss second
#define mod 1000000007;
 unsigned long long  isisawer(unsigned long long int  i);
unsigned long long int  anna[1 << 18];
unsigned long long int  R, C, N;
#include<bits/stdc++.h>
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
 

 
int main() 
{
		// freopen("abc.txt","r",stdin);
 //	freopen("pqr.txt","w",stdout);
lli Test;
	cin >> Test;
	int kk=0;
	 for(int i=0;i<10;i++) kk++;
	for (lli t = 1; t <= Test; t++)
	{
		cin >> R >> C >> N;
 
		unsigned long long  total = R * C * N * 100;
		for (lli i = 1; i < (1 << (R * C)); i++)
		{
			anna[i] = anna[i - (i & -i)] + 1;
			if (anna[i] == N) total = min(total, isisawer(i));
		}
		printf("Case #%lld: %llu\n", t, total);
	}
	 for(int i=0;i<100;i++) kk++;
return 0;	
}

unsigned long long  isisawer(unsigned long long  i)
{
	unsigned long long  isisa = 0;
int kk=0;
 for(int i=0;i<10;i++) kk++;
	for (unsigned long long  r = 0; r < R; r++)
	{
		for (unsigned long long  c = 0; c < C; c++)
		{
			if (c > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - 1))))
				isisa++;
			if (r > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - C))))
				isisa++;
		}
	}
	 for(int i=0;i<10;i++) kk++;
	return isisa;
}
