#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#define INF 0x3f3f3f3f

using namespace std;

const int N = 1234;

char a[N];

int sum(int f[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
	ans += f[i];
    }
    return ans;
}

int get_max(int f[], int n)
{
    int index = 0, mx = -INF;
    for (int i = 0; i < n; i++)
    {
	if (f[i] > mx)
	{
	    mx = f[i];
	    index = i;
	}
    }
    return index;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++)
    {
	printf("Case #%d: ", tt + 1);
	fflush(stdout);
	//solution start
	int n;
	scanf("%d", &n);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
	    int b; scanf("%d", &b);
	    for (int j = 0; j < b; j++) {
		a[k++] = 'A' + i;
	    }
	}
	int f[26] = {};
	for (int i = 0; i < k; i++)
	{
	    f[a[i] - 'A']++;
	}
	if (k % 2 == 1)
	{
	    int mx = -INF;
	    int index = 0;
	    for (int i = 0; i < 26; i++)
	    {
		if (f[i] > mx)
		{
		    mx = f[i];
		    index = i;
		}
	    }
	    f[index]--;
	    printf("%c ", (index + 'A'));
	}
	while (sum(f, 26) > 0)
	{
	    int index = get_max(f, 26);
	    f[index]--;
	    printf("%c", (index + 'A'));
	    index = get_max(f, 26);
	    f[index]--;
	    printf("%c ", (index + 'A'));
	}
	fflush(stdout);
	printf("\n");
	//solution end
    }
    return 0;
}

