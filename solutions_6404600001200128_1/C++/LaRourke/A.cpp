#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int T; cin>>T;
    for(int case_id = 1;case_id<=T;case_id++){
        long long method_1 = 0, method_2 = 0;
        long long N; cin>>N;
        long long ms[N];
        for(long long i=0;i<N;i++){
            cin>>ms[i];
        }
        long long max_d = 0;
        for(long long i=1;i<N;i++){
            if (ms[i]<ms[i-1]) {
                method_1+=ms[i-1]-ms[i];
                if (ms[i-1]-ms[i]>max_d) max_d = ms[i-1]-ms[i];
            }
        }
        for(int i=0;i<N-1;i++){
            method_2+=min(ms[i], max_d);
        }
        printf("Case #%d: %lld %lld\n", case_id, method_1, method_2);
    }
}