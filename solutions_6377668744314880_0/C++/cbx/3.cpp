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
const int B=15;
int b;
int x[B],y[B];
int ans[B];
long long crossProduct(int x1,int y1,int x2,int y2) {
	return (long long)x1*y2-(long long)y1*x2;
}
long long crossProduct(int p1,int p2,int p3) {
	int x12=x[p2]-x[p1];
	int y12=y[p2]-y[p1];
	int x23=x[p3]-x[p2];
	int y23=y[p3]-y[p2];
	return crossProduct(x12,y12,x23,y23);
}
bool smaller1(int t1,int t2) {
	if (y[t1]!=y[t2]) {
		return y[t1]<y[t2];
	}
	return x[t1]<x[t2];
}
int x0,y0;
bool smaller2(int t1,int t2) {
	int x1=x[t1]-x0;
	int y1=y[t1]-y0;
	int x2=x[t2]-x0;
	int y2=y[t2]-y0;
	long long p12=crossProduct(x1,y1,x2,y2);
	if (p12!=0) {
		return p12>0;
	}
	return x1<x2;
}
void calc(int remainFlag) {
	int cut=0;
	vector<int> v;
	int i,j;
	for (i=0;i<b;i++) {
		if ((remainFlag&(1<<i))!=0) {
			v.push_back(i);
		}
		else {
			cut++;
		}
	}
	int nv=v.size();
	sort(v.begin(),v.end(),smaller1);
	x0=x[v[0]];
	y0=y[v[0]];
	sort(v.begin()+1,v.end(),smaller2);
	vector<int> z;
	z.push_back(v[0]);
	if (nv>1) {
		z.push_back(v[1]);
	}
	for (i=2;i<nv;i++) {
		while (z.size()>=2) {
			long long p=crossProduct(z[z.size()-2],z[z.size()-1],v[i]);
			if (p>0) {
				break;
			}
			z.pop_back();
		}
		z.push_back(v[i]);
	}
	for (i=0;i<(int)z.size();i++) {
		if (cut<ans[z[i]]) {
			ans[z[i]]=cut;
		}
	}
	z.push_back(z[0]);
	for (i=0;i<(int)v.size();i++) {
		for (j=0;j+1<(int)z.size();j++) {
			if (crossProduct(z[j],v[i],z[j+1])==0) {
				if (cut<ans[v[i]]) {
					ans[v[i]]=cut;
				}
			}
		}
	}

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
		cin>>b;
		int i;
		for (i=0;i<b;i++) {
			cin>>x[i]>>y[i];
			ans[i]=b;
		}
		for (i=1;i<(1<<b);i++) {
			calc(i);
		}
		cout<<"Case #"<<ti<<":"<<endl;
		for (i=0;i<b;i++) {
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}

