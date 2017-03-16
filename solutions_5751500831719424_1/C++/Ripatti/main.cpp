#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

int n;
vector< string > S;

string reduce( string str )
{
	string re;
	str.push_back( '$' );
	FA(a,str) if (a) if (str[a-1]!=str[a]) re.push_back(str[a-1]);
	return re;
}

VI get_vec( string str )
{
	VI re;
	str.push_back( '$' );
	int i=1;
	FA(a,str) if (a)
	{
		if (str[a-1]!=str[a])
		{
			re.push_back( i );
			i = 1;
		}
		else i++;
	}
	return re;
}

void sol()
{
	string red = reduce( S[0] );
	FA(a,S) if (reduce(S[a]) != red)
	{
		cout << "Fegla Won";
		return;
	}

	vector< VI > vec;
	FA(a,S)
	{
		vec.push_back( get_vec( S[a] ) );
		//FA(b,vec[a]) cout << vec[a][b] << " ";
		//cout << "\n";
	}

	int ans = 0;
	FA(a,vec[0])
	{
		int mi = 1000;
		FOR(b,1,100)
		{
			int tmp = 0;
			FA(c,vec) tmp += abs( vec[c][a]-b );
			mi = min( mi, tmp );
		}
		ans += mi;
	}

	cout << ans;
}

void sol2()
{
	string red = reduce( S[0] );
	FA(a,S) if (reduce(S[a]) != red)
	{
		cout << "Fegla Won";
		return;
	}

	vector< VI > vec;
	FA(a,S)
	{
		vec.push_back( get_vec( S[a] ) );
		//FA(b,vec[a]) cout << vec[a][b] << " ";
		//cout << "\n";
	}

	int ans = 0;
	FA(a,vec[0])
	{
		VI vv;
		FA(b,vec) vv.push_back( vec[b][a] );
		sort( vv.begin(), vv.end() );

		int i=0, mi=1000, cur1=0, cur2=0;
		FA(b,vv) cur2 += vv[b]-vv[0]+1;
		FOR(b,vv[0],vv[SZ(vv)-1])
		{
			while (i<SZ(vv) && vv[i] < b) i++;
			cur1 += i;
			cur2 -= SZ(vv)-i;
			mi = min( mi, cur1+cur2 );
		}

		ans += mi;
	}

	cout << ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	FOR(a,1,t)
	{
		cerr << a << "\n";

		cin >> n;
		S.clear();
		FOR(b,1,n)
		{
			string tmp;
			cin >> tmp;
			S.push_back( tmp );
		}
		
		cout << "Case #" << a << ": ";
		sol();
		//cout << " ";
		//sol2();
		cout << "\n";
	}
	return 0;
}
