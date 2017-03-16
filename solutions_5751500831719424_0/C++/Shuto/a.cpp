#include<iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<sstream>
#include<algorithm>
#include<map>
#include<complex>
#include<ctime>
#include<set>
using namespace std;


#define li			long long int
#define rep(i,to)	for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)	for(li i=(li)(start);i<((li)(to));i++)
#define pb			push_back
#define sz(v)		((li)(v).size())
#define bgn(v)		((v).begin())
#define eend(v)		((v).end())
#define allof(v)	(v).begin(), (v).end()
#define dodp(v,n)		memset(v,(li)n,sizeof(v))
#define bit(n)		(1ll<<(li)(n))
#define mp(a,b)		make_pair(a,b)
#define rin	rep(i,n)
#define EPS 1e-10
#define ETOL 1e-8
#define MOD 100000000
#define F first
#define S second
#define p2(a,b)		cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)		cout<<a<<"\t"<<b<<"\t"<<c<<endl

li n;

string ss[111];

vector<pair<char,li> > decom(string s){
	vector<pair<char,li> > res;
	li cnum=1;
	rep(i,sz(s)){
		if(i==sz(s)-1 || s[i]!=s[i+1]){
			res.pb(mp(s[i],cnum));
			cnum=1;
		}
		else{
			cnum++;
		}
	}
	return res;
}

li dist(string a, string b){
	li res=0;
	vector<pair<char,li> >va=decom(a), vb=decom(b);
	if(sz(va)!=sz(vb))return -1;
	rep(i,sz(va)){
		if(va[i].F!=vb[i].F)return -1;
		res+=abs(va[i].S-vb[i].S);
	}
	return res;
}

li best(vector<li> &v){
	if(sz(v)<=1)return 0;
	li res=0;
	repp(i,1,sz(v))res+=v[i]-v[0];
	li tres=res;
	repp(i,1,sz(v)){
		li sa=v[i]-v[i-1];
		tres=tres+sa*(i-1)-sa*(sz(v)-i-1);
		res=min(tres,res);
	}
	return res;
}

li solve(){
	li res=0;
	repp(i,1,n){
		if(dist(ss[0],ss[i])<0)return -1;
	}

	vector<vector<li> > nums;
	vector<pair<char,li> > decoms[300];
	rep(i,n)decoms[i]=decom(ss[i]);

	rep(i,sz(decoms[0])){
		vector<li> tmp;
		rep(j,n){
			tmp.pb(decoms[j][i].S);
		}
		sort(allof(tmp));
		nums.pb(tmp);
	}
	rep(i,sz(nums))res+=best(nums[i]);
	return res;
}

int main(){
	//vector<pair<char,li> >pp=decom("aaabbcddddaa");
	//rep(i,sz(pp))p2(pp[i].F, pp[i].S);
	li cases;
	cin>>cases;
	rep(caseNum,cases){
		cin>>n;
		rin{
			cin>>ss[i];
		}
		li res=solve();

		cout<<"Case #"<<caseNum+1<<": ";
		if(res>=0)cout<<res<<endl;
		else cout<<"Fegla Won"<<endl;
	}

	return 0;
}