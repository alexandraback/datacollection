#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int s = 0;
        priority_queue<P> que;
        int N;
        cin >> N;
        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            s += tmp;
            que.emplace(tmp, i);
        }
        stringstream ss;
        while(s > 0){
            P p = que.top(); que.pop();
            p.first -= 1;
            s -= 1;
            ss << (char)('A'+p.second);
            if(s % 2 == 1){
                if(que.top().first > p.first){
                    que.push(p);
                    p = que.top(); que.pop();
                }
                p.first -= 1;
                s -= 1;
                ss << (char)('A'+p.second);
            }
            que.push(p);
            if(s != 0) ss << ' ';
        }
        cout <<"Case #" << t+1 << ": " << ss.str() << endl;
    }
    return 0;
}