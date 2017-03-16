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

typedef pair<ll,ll> otype;
otype calcFunction(ll n, vector<ll> mushs) {
	otype result;
	ll result1=0,result2=0;
	ll rate=0;
	forn(i,mushs.size()-1){
		if(mushs[i+1]<mushs[i]){
			result1+=mushs[i]-mushs[i+1];
			if(mushs[i]-mushs[i+1]>rate)
				rate=mushs[i]-mushs[i+1];
		}
	}
	ll current=mushs[0];
	fornn(i,1,mushs.size()){
		if(current>rate){
			result2+=rate;
			current-=rate;
		} else {
			result2+=current;
			current=0;
		}
		current=mushs[i];
	}
	
	result=mp(result1,result2);
	
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
		ll n;
		infile >> n;
		vector<ll> mushs;
		forn(i,n){
			ll current;
			infile >> current;
			mushs.pub(current);
		}
		//write output
		otype result=calcFunction(n,mushs);
		outfile << "Case #" << test << ": ";
		outfile << result.first << " " << result.second << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}