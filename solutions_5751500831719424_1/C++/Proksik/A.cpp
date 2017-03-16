//--BY--©--WA-
#include<iostream> //cout, cin, getline

#include<algorithm> //find, reaplce, swap, sort, lower_bound, uper_bound, binnary_search...
#include<vector> //push_back, size, resize, 
#include<string>
#include<queue> //empty, front, back, push
#include<stack> //push, top, empty
#include<map>
#include<set>
#include<list> //spajazny zoznam .. vsetko v O(1)

#include<stdio.h> //printf, scanf, getchar, putchar
#include<math.h> //cos, sin, exp, pow, sqrt,  flnoor, cell
#include<stdlib.h> //atio, atl, strtod, strtol, atof, abs, 
#include<ctype.h> //isalnum, isalpha, isdigit, islower, isupper, toupper, tolower, 
#include<string.h> //strcm, strstr, strlen,

using namespace std;

#define FOREACH(obj,it) for(__typeof(obj.begin()) it = (obj).begin(); it != (obj).end(); (it)++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)
#define DEBUG(V,S) FOR(i,0,S-1){cout << i << ". " << V[i] << endl;}

#define PB push_back
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define fi first
#define se second

#define SIZE(s) (int) (s).size()

#define INF 987654321
#define EPS 1e-9
#define ld long double // %Lf, double %lf
#define ll long long   // %llf

//--------------------------------------------------------------------------------------

vector<string> V;

#define MAX 105

string VP[MAX];
int dupl[MAX][150];

int process(int id)
{
	string s = V[id];
	char last = s[0];
	int p = 1;
	int k = 0;
	VP[id] ="";
	FOR(i,1,SIZE(s)-1)
	{
		if (last == s[i]) p++;
		else
		{
			dupl[id][k] = p;
			k++;
			VP[id] += last;
			last = s[i];
			p = 1;
		}
	}
	dupl[id][k] = p;
	VP[id] += last;
}

int N;

int solve()
{
	string fir = VP[0];
	FOR(i,1,N-1) if (fir != VP[i]) return -1;
	int best = -1;
	//toto je referencna
	FOR(i,0,N-1)
	{
		int sum = 0;
		FOR(k,0,N-1)
			FOR(j,0,SIZE(VP[i])-1)
					sum+= abs(dupl[i][j] - dupl[k][j]);
		if (sum < best || best == -1) best = sum;
	}
	return best;
}


int main()
{
	int Q;
	cin >> Q;
	FOR(q,1,Q)
	{
		cin >> N;
		V.resize(N);
		FOR(i,0,N-1)
		{
				cin >> V[i];
				process(i);
		}
		
		int res =  solve();
		cout << "Case #" << q << ": ";
		if (res == -1) cout <<  "Fegla Won"<< endl;
		else cout << res << endl;

/*
		FOR(i,0,N-1)
		{
			cout << V[i] << " " << VP[i] << endl;
			FOR(j,0,SIZE(VP[i])-1) cout << dupl[i][j] << " ";
			cout << endl;
		}
	*/
	}
	return 0;
}
