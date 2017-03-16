//
//  main.cpp
//
//  Created by Vichare, Vivek on 4/12/14.
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;

void compress(vector<string> &orig, vector<string> &compressed, vector< vector<ll> > &repN)
{
    for (size_t i = 0; i < orig.size(); ++i) {
        string s = orig[i];
        string c;
        c += s[0];
        vector<ll> reps;
        reps.push_back(1);
        for (size_t j = 1; j < s.length(); ++j) {
            if (s[j] == c[c.length()-1]) {
                // repetition
                ++reps[reps.size()-1];
            } else {
                // found a different character
                c+=s[j];
                reps.push_back(1);
            }
        } // for
        // now we have compressed string in s and reps in reps
        compressed.push_back(c);
        repN.push_back(reps);
    }
}

ll minChanges(const vector<vector<ll> > &repN)
{
    ll rv = 0;
    
#define INF_CHANGE 100000LL

    for (size_t i = 0; i < repN[0].size(); ++i) {
        ll costOfJ = INF_CHANGE; // minimize this
        for (size_t j = 0; j < repN.size(); ++j) {
            ll costOfKtoJ = 0; // cost of changing k to j
            for (size_t k = 0; k < repN.size(); ++k) {
                costOfKtoJ += abs(repN[k][i] - repN[j][i]);
            } // for
            costOfJ = min(costOfJ, costOfKtoJ);
        } // for
        rv += costOfJ;
    } // for
    return rv;
}

ll process_testcase_A()
{
    ll rv = 0;
    vector<string>orig;
    vector<string>compressed;
    vector<vector<ll> > repN;

    size_t N = 0;
    cin >> N;
    for (size_t i = 0; i < N; ++i) {
        string s;
        cin >> s;
        orig.push_back(s);
    }
    compress(orig, compressed, repN);
    // check if all compressed strings match
    for (size_t i = 1; i < compressed.size(); ++i) {
        if (compressed[i].length() != compressed[0].length()) {
            // don't match
            cout << "Fegla Won";
            return 0;
        }
    }

    for (size_t i = 1; i < compressed.size(); ++i) {
        for (size_t j = 0; j < compressed[0].length(); ++j) {
            if (compressed[i][j] != compressed[0][j]) {
                // don't match
                cout << "Fegla Won";
                return 0;
            }
        }
    }

    cout << minChanges(repN);
    
    return rv;
}
long long process_testcase_B()
{
    long long A, B, K;
    cin >> A >> B >> K;
    if (A > B) {
        long long t = A;
        A = B;
        B = t;
    }
    K = min(K, A);
    //printf("%lld, %lld, %lld", A, B, K);
    long long rv = 0;
    for (long long i = 0; i < A; ++i) {
        for (long long j = 0; j < B; ++j) {
            rv += ((i&j) < K)? 1 : 0;
        }
    }
    return rv;
}

int main(int argc, char*argv[]) {
    int tc = 0;
	if(argc == 1) {
        freopen("inp.txt", "r", stdin);
        //freopen("outp.txt", "w", stdout);
    }
	else {
        freopen(argv[1], "r", stdin);
        //freopen("outp.txt", "w", stdout);
    }
    
	// find total number of testcases
	cin >> tc;
	
	// for every testcase
	for(int i = 1; i <= tc; i++)
	{
		printf("Case #%d: ",i);
		//cout << process_testcase_B();
        process_testcase_A();
        cout << endl;
	}
    
    return 0;
}