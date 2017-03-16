//============================================================================
// Name        : GCJ2012QA.cpp
// Author      : Takatomo Honda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define FORE(i,d,e) for(int i=d;i<e;i++)
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int card1[4][4],card2[4][4];
int select1,select2;

string solve(){
	vector<int> ret;
	int tmp[17]={};
	FORE(i,0,4)tmp[card1[select1-1][i]]=1;
	FORE(i,0,4){
		int num=card2[select2-1][i];
		if(tmp[num]>0)ret.push_back(num);
	}

	if(ret.size()==0)return "Volunteer cheated!";
	if(ret.size()>=2)return "Bad magician!";
	char ans[10];
	sprintf(ans,"%d",ret[0]);
	return ans;

}

int main(int argc, char *args[]) {
	FILE *stream;

	if ( argc==2 && strcmp(args[1], "small")==0 ) {
		if( (stream=freopen("A-small-practice.in","rt",stdin))==NULL){
			printf("file open error");
		}
        //freopen("small.out","wt",stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("large.in","rt",stdin);
        freopen("large.out","wt",stdout);
    }
    else {
	    freopen("A-small-attempt0.in", "rt", stdin);
        freopen("small.out","wt",stdout);
    }

	int N;
	cin>>N;

    vector<string> ans(N);
    ans.clear();

    FORE(i,0,N){
    	cin>>select1;
    	FORE(i,0,4)FORE(j,0,4)cin>>card1[i][j];
    	cin>>select2;
    	FORE(i,0,4)FORE(j,0,4)cin>>card2[i][j];
    	ans.push_back(solve());
    }

    FORE(i,0,N) {
        printf("Case #%d: %s", i+1,ans[i].c_str());
        cout<<endl;
    }

    return 0;
}



