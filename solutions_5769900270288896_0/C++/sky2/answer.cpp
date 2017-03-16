#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string.h>
#include <limits.h>

//#define MYDEBUG

#define REP(i, m, n) for (int i=(int)(m); i<(int)(n); ++i)

#ifdef MYDEBUG
#define p(_value) cout << "@" << #_value << ":" << _value << endl;
#define pv(_vec) { cout << "@" << #_vec << "--" << endl; REP(_vindex, 0, _vec.size()) cout << _vec[_vindex] << ", "; cout << endl; }
#else
#define p(_value) 
#define pv(_vec) 
#endif


using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef unsigned long long ull;
typedef long long ll;

struct Trial{
    int r;
    int c;
    int n;
};

void ParseTrial(ifstream& ifs, Trial& t){    
    ifs >> t.r;
    ifs >> t.c;
    ifs >> t.n;
}

void ParseProblemFile(string inputFileName, vector<Trial>& trials){
    // Open input file.
    ifstream inputFileStream(inputFileName, ios::in);
    if(!inputFileStream){
        cerr << "can not open file (" << inputFileName << ")." << endl;
        exit(1);
    }

    // Read the number of test case.
    int testCaseNum;
    inputFileStream >> testCaseNum;

    // Read all the input
    REP(testCaseId, 0, testCaseNum){
        Trial t;
        ParseTrial(inputFileStream, t);
        trials.push_back(t);
    }
}

void OutputResult(ostream& out, int caseNum, string s){
    out << "Case #" << caseNum << ":" << " " << s << endl;
}

void OutputResult(vector<string> ans){
    int i=0;
    for(string s : ans){
        OutputResult(std::cout, ++i, s);
    }
}

int R, C, N;
vector<VI > VV;

int solve(const vector<VI >& vv){
    int ret=0;
    REP(i, 0, R)REP(j, 0, C){
        if(i+1<R && vv[i][j]==1 && vv[i+1][j] == 1)ret++;
        if(j+1<C && vv[i][j]==1 && vv[i][j+1] == 1)ret++;
    }
    return ret;
}

int go(int i, int p){
    int r=i/C, c=i%C;
    if(p==N){
        return solve(VV);
    }

    int ret=INT_MAX;
    if(i!=R*C){
        VV[r][c] = 1;
        ret = min(ret, go(i+1, p+1));
        VV[r][c] = 0;
        ret = min(ret, go(i+1, p));
    }

    return ret;
}

string SolveTrial(const Trial& t){    
    R=t.r;
    C=t.c;
    N=t.n;
//    p(R);p(C);p(N);
    VV = vector<VI >(R, VI(C, 0));
    return to_string(go(0, 0));
}

int main(int argc, char** argv){
    string inputFileName;
    if(argc != 2){
        inputFileName = "as.in";
    }else{
        inputFileName = argv[1];
    }

    vector<Trial> trials;
    ParseProblemFile(inputFileName, trials);

    vector<string> ans;
    for(Trial t : trials){

        static int testCaseNum = 0;
        testCaseNum++;
        p(testCaseNum);

//        cout << "start: " << testCaseNum << endl;
        ans.push_back(SolveTrial(t));
    }
    
    OutputResult(ans);

    return 0;
}


