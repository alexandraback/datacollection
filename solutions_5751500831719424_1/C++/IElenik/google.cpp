#define _cRT_SEcURE_NO_DEPREcATE
//#define long long long long

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <deque>
#include <math.h>
#include <time.h>

using namespace std;

FILE * in, * out;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

int ri() { int a; fscanf(in, "%d", &a ); return a; }
double rf() 
{ 
	double a; 
	fscanf(in, "%lf", &a ); 
	return a; 
}

char * sbuf = 0; 
string rstr() 
{
	//fscanf(in, "%lf", sbuf); 
	if(sbuf == 0)
		sbuf = new char [(1<<20)+1];

	char c;
	char * b = sbuf;
	while(c = fgetc(in))
	{
		if(c == '\r' || c == '\n' || c == -1) 
		{
			if(b - sbuf > 0)
				break;
			continue;
		}
		*b++=c;
	}
	*b = 0;
	return sbuf; 
}
long long rll() { long long a; fscanf(in, "%lld", &a ); return a; }

long long readbi(int l)
{
	long long res = 0;
	int count = 0;
	int c;
	while( (c = fgetc(in)) && l != 0)
	{
		if(c == '1' || c == '0') 
		{
			res *= 2;
			if(c == '1') res |= 1;
			l--;
		}
	}
	return res;
}

int countdown(int x, int cf, vector<vector<int>> & edges)
{
	int res = 1;
	for(int i = 0; i<edges[x].size(); i++)
	{
		if(edges[x][i] == cf) continue;
		res += countdown(edges[x][i], x, edges);
	}
	return res;
}

int trynode(int x, int cf, vector<vector<int>> & edges)
{
	if(edges[x].size() == 1) return 0;
	if(edges[x].size() == 2) 
	{
		if(edges[x][0] == cf)
			return countdown(edges[x][1],x,edges);
		else
			return countdown(edges[x][0],x,edges);
	}
	
	int res = 1000000;
	for(int i = 0; i<edges[x].size(); i++)
	{
		if(edges[x][i] == cf) continue;
		for(int j = i+1; j<edges[x].size(); j++)
		{
			if(edges[x][j] == cf) continue;
			int cur = trynode(edges[x][i],x,edges)+trynode(edges[x][j],x,edges);
			for(int k = 0; k<edges[x].size(); k++)
			{
				if(edges[x][k] == cf) continue;
				if(k != i && k!=j)
					cur += countdown(edges[x][k],x,edges);
			}
			if(cur < res) res = cur;
		}
	}
	return res;
}



int main(int argc, char * argv[])
{
	in	= fopen("A-large (2).in","rt");
	out	= fopen("out.txt","wt");

	int numcases = ri();
	for(int ca = 1; ca<=numcases; ca++)
	{
		int n = ri();
		vector<string> str(n);
		for(int i = 0; i<n; i++)
			str[i] = rstr();

		bool bDone = false;
		int numm = 0;
		while(!bDone)
		{
			if(str[0].length() == 0) break;
			char c = str[0][0];
			vector<int> num(n);
			int max = 0;
			int min = 0xFFFFFF;
			for(int i = 0; i<n; i++)
			{
				num[i] = 0;
				while(str[i].length() > 0 && str[i][0] == c)
				{
					num[i]++;
					str[i].erase(str[i].begin(),str[i].begin()+1);
				}
				if(num[i] > max) max = num[i];
				if(num[i] < min) min = num[i];
			}
			if(min == 0) break;
			int len = 0xFFFFFFF;
			for(int j = min; j<=max; j++)
			{
				int clen = 0;
				for(int i = 0; i<n; i++)
					clen += abs(num[i]-j);
				if(clen < len) len = clen;
			}
			numm += len;
			bDone = true;
			for(int i = 0; i<n && bDone; i++)
				bDone = (str[i].length() == 0);
		}

		if(!bDone)		
			fprintf(out,"Case #%d: Fegla Won\n", ca);
		else
			fprintf(out,"Case #%d: %d\n", ca, numm);
	}
	return 0;
}

