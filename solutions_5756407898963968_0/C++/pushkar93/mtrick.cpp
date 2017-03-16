//PUSHKAR SINGH
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include <cassert>
using namespace std;
// Input macros
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define ll long long
// Useful constants
#define INF (int)1e9
#define EPS (int)1e-6
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define in(a,b) ( (b).find(a) != (b).end())
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
//#define sz(a) ((int)(a.size()))
#define mp make_pair
//#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define llu long long unsigned
#define ld long

int scan_d() {
	int ip = getchar_unlocked(), ret = 0, flag = 1;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
ld scan_ld() {
	int ip = getchar_unlocked(), flag = 1;
	ld ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
ll scan_ll() {
	int ip = getchar_unlocked(), flag = 1;
	ll ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
llu scan_llu() {
	int ip = getchar_unlocked();
	llu ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		;
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return ret;
}

//end of fast input

//fast output

//no line break
void print_d(int n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 10;
	char output_buffer[10];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 10);
}
void print_ld(ld n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 11;
	char output_buffer[11];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 11);
}
void print_ll(ll n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 21;
	char output_buffer[21];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 21);
}
void print_llu(llu n) {
	int i = 21;
	char output_buffer[21];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 21);
}

#define DEBUG 1
#define debug(x) {if (DEBUG)cout <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
#define mod 1000000007

#define checkbit(n,b) ( (n >> b) & 1)

int mat[5][5], choosen[5];

int main()
{
	int t;
	s(t);
	int ans1,ans2,num,ret,counter=0;
	int cno = 0;
	while(t--)
	{
		cno++;
		s(ans1);
		ans1--;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				s(mat[i][j]);
			}
		}

		for(int i=0;i<4;i++)
		{
			choosen[i] = mat[ans1][i];
		}

		s(ans2);
		ans2--;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				s(mat[i][j]);
			}
		}
		counter=0;
		for(int i=0;i<4;i++)
		{
			num = choosen[i];
			for(int j=0;j<4;j++)
			{
				if(mat[ans2][j] == num)
				{
					ret = num;
					counter++;
				}
			}
		}

		if(counter == 1)
		{
			printf("Case #%d: %d\n",cno,ret);
		}
		else if(counter == 0)
		{
			printf("Case #%d: Volunteer cheated!\n",cno);
		}
		else
		{
			printf("Case #%d: Bad magician!\n",cno);
		}

	}
}
