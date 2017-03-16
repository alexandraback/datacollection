#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef deque<char> str;

ostream& operator<<(ostream& os, str charlist){
	str::iterator it;
	for(it=charlist.begin();it!=charlist.end();it++)
		os << *it;
	return os;
}

ll strToInt(str s){
	ll result=0;
	for(ll i=0;i<s.size();i++){
		result*=10;
		result+=s[i]-'0';
	}
	return result;
}

template <typename T>
bool next_selection(T* begin, T* end, T** selectBegin, T** selectEnd){
	if(*(selectEnd-1)<end-1){
		(*(selectEnd-1))++;
		return true;
	}
	else if(selectBegin+1==selectEnd){
		*selectBegin=begin;
		return false;
	}
	else{
		bool result=next_selection(begin,end-1,selectBegin,selectEnd-1);
		*(selectEnd-1)=1+*(selectEnd-2);
		return result;
	}
}

ll facll(ll n){
	if(n)
		return n*facll(n-1);
	return 1;
}

ld facld(ll n){
	if(n)
		return (ld)n * facld(n-1);
	return 1.;
}

#define mp make_pair
#define x first
#define y second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define hash unordered_map

#define v(type) deque<type >
#define it(container) typeof((container).begin())
#define all(x) (x).begin(), (x).end()
#define select(x,i) (x).begin()+(i), (x).begin()+(i)+1
#define foreach(cit,container) for(typeof((container).begin()) cit = (container).begin(); cit != (container).end(); cit++)
#define foreachc(c,cit,container) {ll c=0;for(typeof((container).begin()) cit = (container).begin(); cit != (container).end(); c++, cit++)
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define fornn(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)

#define inf 9000000000000000000L
#define eps 1e-15

void init(){
}

typedef ll otype;
otype calcFunction(ll r, ll c, ll n) {
	otype result=0;
	if(n<=r*c/2+(r*c)%2)
		return 0;
	if(r==1 || c==1){
		ll total=r*c;
		if(total%2==0){
			n-=total/2;
			result+=min((ll)1,n);
			n-=min((ll)1,n);
			result+=2*n;
			return result;
		} else{
			n-=total/2+1;
			return 2*n;
		}
	}
	if(r*c%2==0){
		n-=r*c/2;
		result+=2*min((ll)2,n);
		n-=min((ll)2,n);
		if(n==0)
			return result;
		ll numberEdge=(2*r+2*c-4)/2-2;
		result+=3*min(numberEdge,n);
		n-=min(numberEdge,n);
		if(n==0)
			return result;
		result+=4*n;
		return result;
	} else {
		if(r%2 && c%2){
			if(n<=r*c-(r-2)*(c-2)/2-1){
				if(n>=r*c-(r-2)*(c-2)/2-1-(r/2+c/2-2)*2){
					result=-1;
				}
			}
		}
		n-=r*c/2+1;
		ll numberEdge=(2*r+2*c-4)/2;
		result+=3*min(numberEdge,n);
		n-=min(numberEdge,n);
		if(n==0)
			return result;
		result+=4*n;
		return result;
	}
	return result;
}

int main() {
	init();
	ofstream outfile("output.txt");
	ll tests = 0;
	cin >> tests;
	fore(test, 1, tests){
		//read input
		ll r,c,n;
		cin >> r >> c >> n;
		//write output
		otype result=calcFunction(r,c,n);
		outfile << "Case #" << test << ": ";
		outfile << result << endl;continue;
		if(result>=0)
				outfile << result << endl;
		else if(result<0)
			outfile << "FALSE" << endl;
	}
	outfile.close();
	return 0;
}