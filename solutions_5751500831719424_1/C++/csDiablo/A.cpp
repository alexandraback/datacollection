#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

#define stop exit(0)
#define nc -1
#define eps 1e-10
#define inf 1000000000
#define mod 1000000007
#define mp make_pair

#define fill(array,value) memset(array,value,sizeof(array))
#define f(i,beg,end) for(int i=beg; i<=end; i++)
#define F(i,beg,end) for(int i=beg; i>=end; i--)
#define Max(a,b) ( (a>b)?a:b )
#define Min(a,b) ( (a<b)?a:b )
#define pi 3.1415926535897932384626433832
#define iread(var) scanf("%d",&var)
#define dread(var) scanf("%f",&var)
#define lread(var) scanf("%lld",&var)
#define input(name) freopen(name,"r",stdin)
#define output(name) freopen(name,"w",stdout)
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef long long ll;

using namespace std;

int n;
vector <string> word;
vector <string> uniqued;


void init()
{
    cin >> n;
    cin.ignore();

    word.resize(n);
    uniqued.resize(n);

    f(i,0,n-1)
    {
        cin >> word[i];
        uniqued[i] = word[i];
        string::iterator it = unique(uniqued[i].begin(), uniqued[i].end());
        uniqued[i].resize(distance(uniqued[i].begin(),it));
    }
}

int calc(vector<int> cnt, int ans)
{
    int ret = 0;
    f(i,0,n-1)
        ret += abs(cnt[i]-ans);

    return ret;
}

void solve(int testIndex)
{
    f(i,1,n-1)
        if (uniqued[i] != uniqued[i-1])
        {
            printf("Case #%d: Fegla Won\n",testIndex);
            return;
        }

    // we got a solution
    int ans = 0;
    vector<int> p(n,0);
    string pattern = uniqued[0];

    f(charIndex,0,pattern.size()-1)
    {
        // for each letter calculate number of moves to adjust the corresponding part in each string
        char currSymb = pattern[charIndex];
        vector<int> cnt(n,0);

        f(i,0,n-1)
        {
            while (p[i] < word[i].size() && word[i][p[i]]==currSymb) cnt[i]++, p[i]++;
        }

        vector<int>::iterator minIt =  min_element(cnt.begin(),cnt.end()),
        maxIt =  max_element(cnt.begin(),cnt.end());
        int lowBound = *minIt;
        int upBound = *maxIt;

        // calculate optimal number of points
        int currAns = inf;
        f(currNum,lowBound,upBound)
        {
            int temp;
            if ( (temp = calc(cnt,currNum)) < currAns)
            {
                currAns = temp;
            }
        }

        // add to total answer
        ans += currAns;
    }

     printf("Case #%d: %d\n",testIndex,ans);
     return;
}

int main()
{
//    cin.sync_with_stdio(false);
//	input("test.txt");
	input("A-large.in");
    output("A-large.out");

	int numberOfTests = 1;
	cin >> numberOfTests;

	f(i,1,numberOfTests)
	{
		init();
		solve(i);
	}

	return 0;
}
