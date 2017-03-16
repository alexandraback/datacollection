#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#ifndef for
	#define for if (0) ; else for
#endif
#ifndef ONLINE_JUDGE
	#define DEBUG
#endif
//This file only works in GNU C++
#ifdef DEBUG
	int _CALL_DEPTH=0;
	struct _CALL_STACK
	{
		_CALL_STACK();
		~_CALL_STACK();
	};
	#define _PRINT_STACK_TAB(number) if (number) printf("%5d:\t",__LINE__); else printf("\t"); for (int i=0;i<_CALL_DEPTH;i++) printf("\t");
	#define VAR(f,x) _PRINT_STACK_TAB(true); printf("%s=\t" f "\n",#x,x);
	#define MSG(format,...) _PRINT_STACK_TAB(true); printf(format "\n",##__VA_ARGS__);
	#define FUNC _PRINT_STACK_TAB(true); printf("%s\n",__PRETTY_FUNCTION__); _CALL_STACK _call_stack; 
	_CALL_STACK::_CALL_STACK()
	{
		_PRINT_STACK_TAB(false);
		printf("{\n");
		_CALL_DEPTH++;
	}
	_CALL_STACK::~_CALL_STACK()
	{
		_CALL_DEPTH--;
		_PRINT_STACK_TAB(false);
		printf("}\n");
	}
	void _REDIRECT(bool in,bool out)
	{
		const char * f=__FILE__;
		int i;
		for (i=strlen(f)-1;i>=0;i--)
		{
			if (f[i]=='.')
			{
				break;
			}
		}
		char *p=new char[strlen(f)+10];
		strncpy(p,f,i);
		if (in)
		{
			strcpy(p+i,".in");
			freopen(p,"r",stdin);
		}
		if (out)
		{
			strcpy(p+i,".out");
			freopen(p,"w",stdout);
		}
		delete[] p;
	}
#else
	//display a single variable, like
	//	VAR("%d",x);
	#define VAR
	//display a message, like
	//	MSG("a[%d]=%d",i,a[i]);
	#define MSG
	//put this line at the beginning of a function in order to update the indent of call stack
	#define FUNC
#endif
int a[1010];
int b;
long long calcFinished(long long t) {
	long long f=0;
	int i;
	for (i=0;i<b;i++) {
		f+=(t+a[i]-1)/a[i];
	}
	return f;
}
int main()
{
	#ifdef DEBUG
	_REDIRECT(0,0);
	#else
	ios::sync_with_stdio(false);
	#endif
	int t,ti;
	cin>>t;
	for (ti=1;ti<=t;ti++) {
		int n;
		cin>>b>>n;
		int i;
		for (i=0;i<b;i++) {
			cin>>a[i];
		}
		long long l,r,m;
		l=0;
		r=((long long)1<<62)/b;
		while (l+1<r) {
			m=(l+r)/2;
			if (calcFinished(m)<=n-1) {
				l=m;
			}
			else {
				r=m;
			}
		}
		long long beforeMe=calcFinished(l);
		//MSG("before me = %d",beforeMe);
//		l=0;
//		r=((long long)1<<62)/b;
//		while (l+1<r) {
//			m=(l+r)/2;
//			if (calcFinished(m)<beforeMe) {
//				l=m;
//			}
//			else {
//				r=m;
//			}
//		}
		//MSG("At %d min, it's time for No. %d guest.",l,n);
		int ans=0;
		for (i=0;i<b;i++) {
			beforeMe+=l%a[i]==0;
			if (beforeMe==n) {
				ans=i;
				break;
			}
		}
		cout<<"Case #"<<ti<<": "<<ans+1<<endl;
	}
	return 0;
}

