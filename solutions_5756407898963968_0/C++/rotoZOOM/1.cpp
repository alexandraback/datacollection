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

#define in_str(b) scanf("%s",(b))
#define in_int1(a) scanf("%d",&(a))
#define in_int2(a,b) scanf("%d%d",&(a),&(b))
#define in_int3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define in_int4(a,b,c,d) scanf("%d%d%d%d",&(a),&(b),&(c),&(d))

int doit(int guess)
{
	int t, i, j, res = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			in_int1(t);
			if (guess == i) res |= (1 << t);
		}
	}

	return res;
}

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	in_int1(test);
	for (int step=1;step<=test;step++)
	{
		int guess;

		in_int1(guess);
		int a = doit(guess - 1);
		in_int1(guess);
		int b = doit(guess - 1);

		a = a&b;

		if (a & (a - 1)) printf("Case #%d: Bad magician!\n", step);
		else if (!a) printf("Case #%d: Volunteer cheated!\n", step);
		else
		{
			int i;
			for (i = 1; !(a&(1 << i)); i++);
			printf("Case #%d: %d\n", step, i);
		}
	}
	return 0;
}