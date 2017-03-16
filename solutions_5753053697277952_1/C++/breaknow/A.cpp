#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <string>

using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define sl(n)						scanf("%I64d", &n)
#define sc(n)                       scanf("%c",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define INF 2147483647
#define UINF 0xffffffff

#define N 26
#define M 1000

int party[N + 10];
int n;

bool chk(int pos)
{
	party[pos]--;
	int tot = 0;
	forall(i, 0, n)
		tot += party[i];
	forall(i, 0, n)
	{
		if (tot - party[i] < party[i])
		{
			party[pos]++;
			return false;
		}
	}

	party[pos]++;
	return true;
}

void process(int testCase)
{
	s(n);
	forall(i,0,n)
		s(party[i]);

	printf("Case #%d: ", testCase);
	int cnt = 0;
	do
	{
		cnt = 0;
		int max = 0, pos = 0;
		forall(i, 0, n)
		{
			cnt += party[i];
			if (max < party[i] && chk(i))
			{
				max = party[i];
				pos = i;
			}
		}
		if (cnt == 0)
			break;
		if (max == 0)
		{
			forall(i, 0, n)
			{
				if (max < party[i])
				{
					max = party[i];
					pos = i;
				}
			}
			printf("%c", pos + 'A');
			party[pos]--;
			max = pos = 0;
			forall(i, 0, n)
			{
				if (max < party[i])
				{
					max = party[i];
					pos = i;
				}
			}
			printf("%c", pos + 'A');
			party[pos]--;

		}
		else
		{
			printf("%c", pos + 'A');
			party[pos]--;
		}
		printf(" ");
	} while (cnt > 0);
	printf("\n");
}

int main()
{
	int t;
	s(t);
	forall(i, 0, t)
		process(i + 1);
}