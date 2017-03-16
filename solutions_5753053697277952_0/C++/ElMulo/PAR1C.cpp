#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<long long> vll;

#define forn(i,n) for(int i=0;i<(int)n;i++)

struct party{
	int num;
	char name;
};


bool comp(party i, party j);

ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

int main(){
	int T,N,S;
	party p;
	p.num=0;
	p.name='A';

	fin >> T;
	forn(t,T){
		fin >> N;
		vector<party> P(N,p);
		S=0;
		forn(i,N){
			fin >> P[i].num;
			P[i].name+=i;
			S+=P[i].num;
		}

		fout << "Case #" << t+1 << ": ";
		int sum=S;
		forn(i,sum){
			sort(P.begin(),P.end(),&comp);
			P[0].num--;
			S--;
			fout << P[0].name;
			if((double)P[1].num/(double)S>0.5){
				P[1].num--;
				S--;
				sum--;
				fout << P[1].name;
			}
			fout << " ";
		}
		fout << endl;
	}

	return 0;
}


bool comp(party i, party j){
	return i.num>j.num;
}
