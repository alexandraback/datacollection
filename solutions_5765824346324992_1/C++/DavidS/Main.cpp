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
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define hash unordered_map

#define it(container) typeof((container).begin())
#define all(x) (x).begin(), (x).end()
#define select(x,i) (x).begin()+(i), (x).begin()+(i)+1
#define foreach(cit,container) for(typeof((container).begin()) cit = (container).begin(); cit != (container).end(); cit++)
#define foreachc(c,cit,container) {ll c=0;for(typeof((container).begin()) cit = (container).begin(); cit != (container).end(); c++, cit++)
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define fornn(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)

pair<ll,ll> helper(ll n, ll min, vector<ll> barbers){
	ll minRest=min+1;
	ll minID=0;
	ll served=0;
	ll servedExtra=0;
	foreachc(counter,bar,barbers){
		ll current=*bar;
		ll rest=min%current;
		if(current-rest<minRest || (rest==0 && minRest>0)){
			minRest=current-rest;
			if(rest==0)
				minRest=0;
			minID=counter;
		}
		if(rest==0){
			served+=min/current;
			servedExtra++;
		}
		else
			served+=1+min/current;
	}}
	if(served<n-1 && minRest==0 && servedExtra+served>=n){
		foreachc(counter,bar,barbers){
			ll current=*bar;
			ll rest=min%current;
			if(rest==0 && served<n-1){
				served++;
			} else if(rest==0 && served==n-1){
				minID=counter;
				break;
			}
		}}
	} else if(served>=n-1)
		return mp(served,minID);
	else
		return mp(served+servedExtra-1,minID);
	return mp(served,minID);
}

typedef ll otype;
otype calcFunction(ll b,ll n,vector<ll> barbers) {
	otype result=0;
	ll getMinimum=barbers[0];
	foreach(bar,barbers){
		if(*bar<getMinimum)
			getMinimum=*bar;
	}
	ll currentMin=0;
	ll oldMin=0;
	while(true){
		pair<ll,ll> servedNext=helper(n, currentMin,barbers);
		if(servedNext.first==n-1)
			return 1+servedNext.second;
		ll changeMin=(n-1-servedNext.first)/b*getMinimum;
		if(changeMin==0){
			if(servedNext.first<n-1)
				changeMin=1;
			else
				changeMin=-1;
		}
		currentMin+=changeMin;
	}
	return result;
}

int main(int argc, char* argv[]) {
	ifstream infile;
	if(argc>1){
		stringstream sstream;
		sstream << argv[1] << ".in.txt";
		infile.open(sstream.str());
	}
	else
		infile.open("sample.txt");
	ofstream outfile;
	if(argc>1){
		stringstream sstream;
		sstream << "output-" << argv[1] << ".txt";
		outfile.open(sstream.str());
	}
	else
		outfile.open("output-sample.txt");
	ll tests = 0;
	infile >> tests;
	fore(test, 1, tests){
		//read input
		ll b, n;
		infile >> b >> n;
		vector<ll> barbers;
		forn(i,b){
			ll mb;
			infile >> mb;
			barbers.pub(mb);
		}
		//write output
		otype result=calcFunction(b,n,barbers);
		outfile << "Case #" << test << ": ";
		outfile << result << endl;continue;
		if(result>=0)
				outfile << result << endl;
		else if(result<0)
			outfile << "FALSE" << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}