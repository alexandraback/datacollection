#include <bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;t++){
        int n;
        cin >> n ;
        priority_queue<pair<int, char> > inside;
        int tot = 0;
        for(int i = 0 ;i < n ; i++){
            int x;
            cin >> x;
            inside.push(make_pair(x, i + 'A')); 
            tot += x;
        }
        vector<string> out;
        if(tot &1){
            string toAdd = "";
            toAdd += inside.top().second;
            out.push_back(toAdd);
            auto top = inside.top();
            inside.pop();
            top.first --;
            inside.push(top);
        }
        for(int i = 0 ;i < tot/2 ; i++){
            auto top1 = inside.top();
            inside.pop();
            top1.first --;
            inside.push(top1);
            
            string toAdd = "";
            toAdd += top1.second;
            
            top1 = inside.top();
            inside.pop();
            top1.first --;
            inside.push(top1);
            
            toAdd += top1.second;
            out.push_back(toAdd);
        }
        cout << "Case #" << t << ":" ;
        for(auto it : out){
            cout << " " << it ;
        }
        cout << endl;
    }
    return 0;
}
