#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

bool test(int testNum)
{
	printf("Case #%d: ", testNum);

	vector<string> inpStr;

	char buf[300];

	int n;
	scanf("%d", &n);

	rep(i, 0, n)
	{
		scanf(" %s", buf);
		inpStr.push_back(buf);
	}

	string idealString;

	using vi = vector<int>;
	function<string(string, vi&)> makeIdeal = [](string inpStr, vi &groupsLen){
		string res;
		if (inpStr.length() == 0)
			return res;

		res.push_back(inpStr[0]);
		int cgs = 1;
		rep(i, 1, inpStr.length())
		{
			if (res.back() != inpStr[i])
			{
				res.push_back(inpStr[i]);
				groupsLen.push_back(cgs);
				cgs = 1;
			}
			else
			{
				cgs++;
			}
		}

		groupsLen.push_back(cgs);

		return res;
	};

	vector<string> idealStrings;
	vector<vi> groupsLen;

	string ideal = makeIdeal(inpStr[0], vector<int>());

	rep(i, 0, n)
	{
		vi cgl;
		string cId = makeIdeal(inpStr[i], cgl);
		if (cId != ideal)
		{
			printf("Fegla Won\n");
			return true;
		}
		groupsLen.push_back(cgl);
	}

	int res = 0;
	rep(i, 0, groupsLen[0].size())
	{
		int cbr = 1e9;
		rep(cgc, 1, 105)
		{
			int cr = 0;
			rep(j, 0, n)
			{
				cr += mabs(groupsLen[j][i] - cgc);
			}
			cbr = min(cbr, cr);
		}
		res += cbr;
	}
	printf("%d\n", res);
}

void run()
{
	int TC;
	scanf("%d", &TC);
	rep(i, 0, TC)
	{
		test(i + 1);
	}
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else 
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif

    run();

#ifdef LOCAL_DEBUG
    fprintf(stderr, "\n=============\n");
	fprintf(stderr, "Time: %.2lf sec\n", (clock() - st) / double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}