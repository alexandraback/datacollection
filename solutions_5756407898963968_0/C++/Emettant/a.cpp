#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <tuple>
#include <cassert>
#include <cstring>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rp(i,s,n) for((i)=(s);(i)<(n);(i)++)	
#define fore(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)
#define repe(it,a) for(auto (it) = (a).begin();(it)!=(a).end();++(it))

#define ll long long
#define MP make_pair 
#define MT make_tuple
#define PB push_back
#define X first
#define Y second
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) (a).size()
#define LEN(s) (s).length() 
#define uset unordered_set
#define umap unordered_map
#define IT iterator

#pragma comment(linker,"/STACK:100000000")

using namespace std;			

#define NUMBERS(a,b) { int _i_; vector<int> _A_(((b))-(a)); rep(_i_,_A_.size()) _A_[_i_] =_i_+(a); out(_A_);}

template <class T> void out(map<char,T> & a,string s="(%3c ->%3d)"){repe(it,a) printf(s.c_str(),it->X,it->Y);printf("\n");}

template <class T>void out(vector<T> & a,string s="%3d "){int i,n=a.size();rep(i,n) printf(s.c_str(),a[i]);printf("\n");}

template <class T>void out(T * a,int n,string s="%3d "){int i;rep(i,n) printf(s.c_str(),a[i]);printf("\n");} 


ll i,j,N,M,n,m,k,p;

int MainSolve(string args=""){
	cout<<args;
	//write code here
	

	return 0;
}


int GoogleSolve(){
	int T,t;
	cin>>t;
	T = t;
	while(t--){
		
		int r,z;
		int a[4][4];
		int ch[17];
		memset(ch, 0 ,sizeof(ch));
		
		cin>>r;
		r--;
		set<int> w;
		rep(i,4) {
			rep(j,4) {
				cin>>z;
				if (i == r) {
					ch[z]++;
					w.insert(z);
				}
			}
		}
		//out(ch,17);
		//cout<<w.size()<<endl;
		
		cin>>r;
		r--;
		set<int> nw;
		rep(i,4) {
			rep(j,4) {
				cin>>z;
				if (i == r) ch[z]++;
				if (w.count(z)) nw.insert(i);
			}
		}
		//out(ch,17);
		//cout<<nw.size()<<endl;
		vector<int> ans;
		rep(i,17) if (ch[i] == 2) ans.PB(i);
		
				
		printf("Case #%d: ",T-t);
		//answer here
		
		if (ans.size() == 0){
			
			printf("Volunteer cheated!\n");
			}
		else {
			if (ans.size() > 1)
			printf("Bad magician!\n");
			else {
				printf("%d\n", ans[0]);
			}
			}
	}
	return 0;
}


string ReadAllLines(char * fileName){
	string s = "";
	const int NMAX = 1000;
	char buf[NMAX]; buf[0] = 0;
	FILE *f = fopen(fileName, "r");
	while (fgets(buf, NMAX, f))
		s = s + string(buf);
	return string(s.begin(), find_if(s.rbegin(), s.rend(), [](char c){return c != '\n'&& c != '\r' && c != '\t' && c != ' '; }).base());
}
int main() {

#ifndef ONLINE_JUDGE
//	freopen("input.txt","r",stdin);
	freopen("A-small-attempt1.in","r",stdin);freopen("output.txt","w",stdout);//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
#endif
	//MainSolve();
	GoogleSolve();
return 0;
}