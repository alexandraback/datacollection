//#define DEBUG_TEST 1


#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>

using namespace std;

#define PB push_back
#define PF push_front
#define FOR0(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define FORN0(i,n) for(int i=n;i>=0;i--)
#define FORN1(i,n) for(int i=n;i>=1;i--)
#ifdef DEBUG_TEST
# define DEBUG(X) cout << #X << " = " << (X) << endl;
#else
# define DEBUG(X) while(0){}
#endif


int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

const double pi = atan(1.0)*4.0;
typedef long long ll;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<ll> VLL;

typedef list<int> LI;
typedef list<char> LC;
typedef list<LI> LLI;
typedef list<LC> LLC;
typedef list<ll> LLL;

typedef VI::iterator IT_VI;
typedef VC::iterator IT_VC;
typedef VVI::iterator IT_VVI;
typedef VVC::iterator IT_VVC;
typedef VLL::iterator IT_VLL;

typedef LI::iterator IT_LI;
typedef LC::iterator IT_LC;
typedef LLI::iterator IT_LLI;
typedef LLC::iterator IT_LLC;
typedef LLL::iterator IT_LLL;


int comparechar(const void* a,const void* b)
{
	if(*(char*)a==*(char*)b)
		return 0;
	if(*(char*)a<*(char*)b)
		return -1;
	if(*(char*)a>*(char*)b)
		return 1;
}

int find_max(int array[30],int num)
{

	int max=0,index=0;
	FOR0(i,num)
	{
		if(array[i]!=0)
		if(array[i]>=max)
		{
			max=array[i];
			index=i;
		}
	}
	return index;
}

int check_input(int array[30],int num)
{
	FOR0(i,num)
	{
		if(array[i]!=0)
			return 1;
	}
	return 0;
}

void solve()
{
	int num,sum=0;
	scanf("%d",&num);
	int input[30];
	FOR0(i,num)
	{
		scanf("%d",&input[i]);	  
	}
	
//	  cout << endl<< num <<endl;
	
	FOR0(i,num)
	{
		sum+=input[i];
//	  	  cout << input[i] << "  ";
	}
//	  cout << endl;
	
	if(sum%2==0)
	while(sum>0)
	{
		int x,y;
		x=find_max(input,num);
		input[x]--;
		sum--;
		y=find_max(input,num);
		input[y]--;
		sum--;
		printf("%c%c ",'A'+x,'A'+y);
	}
	else if(sum >=3)
	{
		while(sum>3)
		{
			int x,y;
			x=find_max(input,num);
			input[x]--;
			sum--;
			y=find_max(input,num);
			input[y]--;
			sum--;
			printf("%c%c ",'A'+x,'A'+y);
		}
		int x,y;
		x=find_max(input,num);
		input[x]--;
		sum--;
		printf("%c ",'A'+x);
		x=find_max(input,num);
		input[x]--;
		sum--;
		y=find_max(input,num);
		input[y]--;
		sum--;
		printf("%c%c ",'A'+x,'A'+y);
	}

}


int main() {

	int no_test;

//	  freopen("Ainput.txt", "r", stdin);


//freopen("Asmall.in", "r", stdin);	   
//freopen("Asmallout.txt", "w", stdout);


freopen("Alarge.in", "r", stdin);
freopen("Alargeout.txt", "w", stdout);

	cin>>no_test;
	FOR1(test,no_test) {
		DEBUG(test)
		printf("Case #%d: ",test);
		solve();
		printf("\n");
	}
	return 0;
}

