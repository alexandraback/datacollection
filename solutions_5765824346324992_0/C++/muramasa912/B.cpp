#include <bits/stdc++.h>
#define MAXN 5000000
using namespace std;

typedef long long ll;
int which[MAXN];
int m[2000];
ll lcm,n,b;
int where;


struct PII{

	ll first;
	ll second;
	PII() {}
	PII(ll x,ll y) {first=x;second=y;}
	bool operator < (const PII & other) const{
		if(first!=other.first) return first > other.first;
		return second > other.second;
	}
};

ll gcd(ll x,ll y)
{
    while( y != 0)
    {
        ll  t = y;
        y= x %t;
        x = t;
    }
    return x;}

void LCM(){

		lcm=1;
		for(int i=0;i<b;++i){
			lcm=(lcm*m[i]/gcd(lcm,m[i]));
			}
		
	}

void pre(){
	ll loop=0;
	for(int i=0;i<b;++i){
		loop+=(lcm/m[i]);
	}
	//cout << "dsf" << lcm << ' ' << loop << endl;

	priority_queue<PII> q;
	for(int i=0;i<b;++i){
		q.push(PII(0,i));
		}

	ll k=1;
	while(!q.empty()){
		PII tmp=q.top();
		ll tm=tmp.first;
		ll bb=tmp.second;
		q.pop();
		which[k]=bb;
	//	cout << k << ' ' << bb << endl;
		q.push(PII(tm+m[bb],bb));
		k++;
		if(k>loop) break;

		}
	if(n%loop)
	where=n%loop;
	else where=loop;
	
	}

int main(){


	int test;
	cin >> test;
	for(int ti=1;ti<=test;++ti){
		cin >> b >> n;
		for(int i=0;i<b;++i){
			cin >> m[i];
			}
		LCM();
		pre();
		
		printf("Case #%d: %d\n",ti,1+which[where]);
			
		}
	return 0;
}
