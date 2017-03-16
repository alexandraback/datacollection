#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>
#include<list>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define pb push_back
#define MP make_pair
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define ll long long
#define ull unsigned long long
#define eps 1e-9
#define MOD 1E9 +7
#define lim 4

 unsigned long long  givemethecorrectanswer(unsigned long long int  i);
unsigned long long int  tanned[1 << 18];
unsigned long long int  Row;
unsigned long long int  Col, Numbers;
typedef long long int lli;
typedef long int li;

int main() 
{
		 //freopen("lelo.txt","r",stdin);
     	//freopen("pqr.txt","w",stdout);
int  Test;
	cin >> Test;
	int kalukalu=0;
	
	for (lli t = 1; t <= Test; t++)
	{
		kalukalu=0;
	for(int i=0;i<100;i++) kalukalu++;
		cin >> Row >> Col >> Numbers;
 
		unsigned long long  total = Row * Col * Numbers * 100;
		for (lli i = 1; i < (1 << (Row * Col)); i++)
		{
			tanned[i] = tanned[i - (i & -i)] + 1;
			if (tanned[i] == Numbers) total = min(total, givemethecorrectanswer(i));
		}
		printf("Case #%lld: %llu\n", t, total);
	}
	 
return 0;	
}
unsigned long long  givemethecorrectanswer(unsigned long long  numbereee)
{
	unsigned long long  answerreturn = 0;
int kk=0;
	for (unsigned long long  r = 0; r < Row; r++)
	{
		for (unsigned long long  c = 0; c < Col; c++)
		{
			if (c > 0 and (numbereee & (1 << (r * Col + c))) and (numbereee & (1 << (r * Col + c - 1))))
				answerreturn++;
			if (r > 0 and (numbereee & (1 << (r * Col + c))) and (numbereee & (1 << (r * Col + c - Col))))
				answerreturn++;
		}
	}
	 
	return answerreturn;
}

