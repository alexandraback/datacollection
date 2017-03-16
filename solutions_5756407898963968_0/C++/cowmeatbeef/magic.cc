#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

#define REP(i,a) for(int i=0;i<(a);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define SZ(x) ((int)x.size())

string l; // line of input
#define STR(s) getline(cin,l,'\n');s=l;
#define PAR(...) getline(cin,l,'\n');sscanf(l.c_str(),__VA_ARGS__);

void computeCase(int casen);

int main() {
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);

	int ncases;
	PAR("%d",&ncases);

	FORE(i,1,ncases)
		computeCase(i);

	return 0;
}

void computeCase(int casen) {
	// row with card
	int row;
	PAR("%d",&row);

	// skip to row with card
	REP(i,row - 1)
		getline(cin,l,'\n');

	// remember possible cards
	int frcards[4];
	PAR("%d %d %d %d",&frcards[0], &frcards[1], &frcards[2], &frcards[3]);

	// skip other rows
	REP(i,4 - row)
		getline(cin,l,'\n');

	// row with card
	PAR("%d",&row);

	// skip to row with card
	REP(i,row - 1)
		getline(cin,l,'\n');

	// find possible cards
	int srcards[4];
	PAR("%d %d %d %d",&srcards[0], &srcards[1], &srcards[2], &srcards[3]);

	// skip other rows
	REP(i,4 - row)
		getline(cin,l,'\n');

	stringstream ss;
	string message = "Volunteer cheated!";
	REP(i,4) {
		REP(j,4) {
			if (frcards[i] == srcards[j]) {
				if (message == "Volunteer cheated!") {
					message = "";
					ss << frcards[i];
					ss >> message;
				} else {
					message = "Bad magician!";
				}
			}
		}
	} 


	cout << "Case #" << casen << ": ";
	cout << message;
	cout << endl;
}