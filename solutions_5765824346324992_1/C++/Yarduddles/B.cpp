#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <tuple>
#include <cmath>
#include <climits>
using namespace std;

#define SORT(l) std::sort(l.begin(), l.end())
#define IS_ALPH(c) ((c>='a' && c<='z') || (c>='A' && c<='Z'))
#define IS_NUM(c) (c>='0' && c<='9')
#define FOR(a, min, max) for(int a=min; a<max; ++a)
#define FORS(a, str) for(int a=0; a<str.length(); ++a)
#define FORV(a, vec) for(int a=0; a<vec.size(); ++a)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define COUTV(v) FORV(i,v) { cout << v[i]; if(i<v.size()-1) cout << ","; else cout << endl; }

int main() {
    
    int T;
    cin >> T;
    int cur_case=0;
    while(T--) {
        
        unsigned long long B, N;
        cin >> B >> N;

        vector<int> barbers(B);
        unsigned long long max_haircut_time = 0;
        for(int i=0; i<B; ++i) {
            cin >> barbers[i];
            //max_haircut_time = max(max_haircut_time, barbers[i]);
            if(barbers[i] > max_haircut_time)
                max_haircut_time = barbers[i];
        }

        unsigned long long minMinute = 0;
        unsigned long long maxMinute = max_haircut_time*N;
        unsigned long long curMinute;
        unsigned long long numCuts;
        while(minMinute <= maxMinute) {
            curMinute = (maxMinute - minMinute)/2 + minMinute;

            numCuts=0;
            unsigned long long cuts_this_round = 0;
            for(int i=0; i<B; ++i) {
                numCuts += (curMinute/barbers[i]) + 1;
                
                if(curMinute%barbers[i]==0)
                    cuts_this_round++;
            }

            //cout << "at minute: " << curMinute << endl;

            if(N > (numCuts - cuts_this_round) && N <= numCuts)
                break;
            else if(numCuts < N) {
                minMinute = curMinute+1;
            } else if(numCuts >= N && curMinute > 0) {
                maxMinute = curMinute-1;
            }
        }

        //cout << "End minute: " << curMinute << endl;

        int who_cut = B;
       // cout << "Starting with WHO: " << who_cut << endl;
        while(curMinute%barbers[who_cut-1]!=0) {
            who_cut--;
        }
     
        //cout << "Last cut made by: " << who_cut << endl;
        //cout << "Number of cuts: " << numCuts << endl;
        while(numCuts > N) {
            if(curMinute%barbers[who_cut-1] == 0) {
                //cout << "Barber: " << who_cut << " cut hair" << endl;
                numCuts--;
            }
            who_cut--;
        }

        while(curMinute%barbers[who_cut-1]!=0) {
            who_cut--;
        }

        cout << "Case #" << ++cur_case << ": " << who_cut << endl;
    }

    return 0;
}
