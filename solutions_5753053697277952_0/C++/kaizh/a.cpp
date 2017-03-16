#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int N;
        cin>>N;
        priority_queue<pair<int, int>> que;
        for(int i=0, v;i<N;i++) {
            cin>>v;
            que.emplace(v, i);
        }
        cout<<"Case #"<<t<<":";
        if(N==2) {
            for(int i=que.top().first; i>0;i--) {
                cout<<" AB";
            }
            cout<<endl;
        } else {
            while(que.size()>2||que.top().first>1) {
                auto tp = que.top();
                que.pop();
                cout<<" "<<char('A' + tp.second);
                if(tp.first!=1)
                    que.emplace(tp.first-1, tp.second);
            }
            cout<<" ";
            cout<<char('A'+que.top().second);
            que.pop();
            cout<<char('A'+que.top().second)<<endl;
        }
    }
    return 0;
}
