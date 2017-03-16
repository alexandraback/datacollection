#include <cstdio>
#include <climits>
#include <algorithm>
#define ABS(x) ((x) < 0 ? -1*(x) : (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define mp make_pair
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int primes[9] = {2,3,5,7,11,13,17,19,23};
int pows[9];
int arr[5];

struct barber
{
	int id;
	int time;
	int t0;
};

barber arr1[5];

bool comp(const barber &a, const barber &b)
{
	if(a.time == b.time) return a.id < b.id;
	return a.time < b.time;
}

inline int fastExp(int a, int b)
{
	if(b == 0 || a == 1) return 1;
	if(b == 1) return a;

	if(b % 2) return a*fastExp(a, b-1);
	
	long long int c = fastExp(a, b/2);
	return c*c;
}

inline void pf(int x)
{
	int i, count;
 
	for(i = 0; i < 9; ++i)
	{
		count = 0;
		while(x % primes[i] == 0)
		{
			++count;
			x /= primes[i];
		}
		if(count > pows[i]) pows[i] = count;

		if(x == 1) return;
	}
 }

inline int lcm(int a, int b, int c, int d, int e)
{
	int i;
	for(i = 0; i < 9; ++i)
		pows[i] = 0;

	pf(a);
	pf(b);
	pf(c);
	pf(d);
	pf(e);

	int ans = 1;

	for(i = 0; i < 9; ++i)
		ans *= fastExp(primes[i], pows[i]);

	return ans;
}

int main()
{
	int T,i,j,k,l,m,B,N,lcm1,ns,ans;

	scanf("%d",&T);

	for(j = 1; j <= T; ++j)
	{
		scanf("%d", &B);
		scanf("%d", &N);

		for(i = 0; i < 5; ++i)
			arr[i] = 1;

		for(i = 0; i < B; ++i)
			scanf("%d", &arr[i]);

		lcm1 = lcm(arr[0],arr[1],arr[2],arr[3],arr[4]);
		//printf("lcm = %d\n", lcm1);
		ns = 0;

		for(i = 0; i < B; ++i)
			ns += lcm1/arr[i];

		if(N >= ns) N %= ns;

		if(N == 0)
		{
		 	for(i = 0; i < B; ++i)
			{
				arr1[i].id = i+1;
				arr1[i].time = arr[i];
				arr1[i].t0 = arr[i];
			}

			sort(arr1, arr1+B, comp);

			ans = arr1[0].id;
		}
		else if(N <= B) ans = N;
		else
		{
			for(i = 0; i < B; ++i)
			{
				arr1[i].id = i+1;
				arr1[i].time = arr[i];
				arr1[i].t0 = arr[i];
			}

			sort(arr1, arr1+B, comp);

			N -= B;

			for(i = 1; i < N; ++i)
			{
				arr1[0].time += arr1[0].t0;
				sort(arr1, arr1+B, comp);
			}
			ans = arr1[0].id;
		}

		printf("Case #%d: %d\n",j, ans);
	}

	return 0;
}