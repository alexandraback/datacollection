#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)
#define FORB(i,b,n) for(int i=b;i<n;++i)
#define REV(i,n) for(int i=n;i>=0;--i)
#define FOREACH(T, it, v) for(T::iterator it = v.begin(); it !=v.end(); ++it)
#define print(STRING,INT) printf("%s= %d\n", STRING, INT)
#define scan(INT) scanf("%d", &INT)
#define PB(X) push_back(X)


typedef long long ll;
typedef unsigned int u32;
typedef unsigned int uint;
typedef unsigned int uInt;


const int INF = (0u - 11)/2;


typedef set<int> SI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef set<long long> SL;
typedef map<int, int> MII;



int DEBUG = 1;

void log(char* S, long long a)
{
    if(DEBUG)
    {
        printf("%s= %lld\n", S, a);
    }
}

VI primes(int range = 10001)
{
    VI primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    for(int i = 9; i< range;i++)
    {
        int j=0;
        int flag = false;
        while((long long )primes[j]*primes[j]<= i)
        {
            if(i%primes[j++]==0)
            {
                flag = true;
                break;
            }
        }
        if(flag == false) primes.push_back(i);
    }
    return primes;
}

char buf[1000];
int tab[106][106];

int solve()
{
	int n;
	scan(n);
	vector<string> V;
	FOR(i,n)
	{
		scanf("%s", buf);
		V.push_back(string(buf));
	}
	string S = V[0];
	VI znak;
	znak.push_back(S[0]);
	int ile = 0;
	tab[0][0] = 1;
	int i=1;
	while(i < S.length())
	{
		if(S[i-1] == S[i])
		{
			tab[0][ile]++;
		}
		else
		{
			znak.push_back(S[i]);
			tab[0][++ile]=1;
		}
		i++;
	}
	int maxIle = ile;
	FORB(j,1,n)
	{
		S = V[j];
		ile = 0;
		if(S[0] != znak[0])
			return -1;
		tab[j][0] = 1;
		i = 1;
		while(i < S.length())
		{
			if(S[i-1] == S[i])
			{
				tab[j][ile]++;
			}
			else
			{
				if(ile == maxIle || S[i] != znak[ile+1])
					return -1;
				tab[j][++ile] = 1;
			}
			i++;
		}
		if(ile < maxIle) return -1;
	}
	int out = 0;
	FOR(i,ile+1)
	{
		int min = INF;
		FORB(j, 1, 101)
		{
			int value = 0;
			FOR(k,n)
			{
				value += abs(j - tab[k][i]);
			}
			if(value < min) min = value;
		}
		out += min;
	}

	return out;
}

int main()
{
    int T;//, n;//, m;//, q;//, k;
   // int tmp;
    scan(T);
	FOR(i,T)
	{
		int a = solve();
		if (a < 0)
			cout << "Case #" << i+1 << ": Fegla Won" << endl;
		else
		{
			cout << "Case #" << i+1 << ": " << a << endl;
		}

	}



    return 0;
}
