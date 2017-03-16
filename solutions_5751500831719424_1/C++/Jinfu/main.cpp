//
//  main.cpp
//  gcj
//
//  Created by Jinfu Leng on 4/11/14.
//  Copyright (c) 2014 jinfu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Node{
    char l;
    int cnt;
};

vector<Node> Ana(string a){
    vector<Node> ans;
    char l;
    int cnt;
    for(int i = 0; i < a.length(); i++){
        if(i == 0){
            l = a[i];
            cnt = 1;
        }
        else{
            if(a[i] == a[i-1]){
                cnt++;
            }
            else{
                Node node;
                node.l = l;
                node.cnt = cnt;
                ans.push_back(node);
                l = a[i];
                cnt = 1;
            }
        }
    }
    Node node;
    node.l=l;
    node.cnt=cnt;
    ans.push_back(node);
    return ans;
}
void Solve(){
    int N;
    scanf("%d",&N);
    vector<Node> ans[105];
    string strs[105];
    for(int i = 0; i < N; i++){
        cin>>strs[i];
        ans[i]=Ana(strs[i]);
    }
    bool ok = true;
    for(int i=1;i<N;i++){
        if(ans[i].size()!=ans[i-1].size()) ok=false;
    }
    
    for(int i=1;i<N;i++){
        for(int j=0;j<ans[0].size();j++){
            if(ans[i][j].l!=ans[0][j].l)
                ok=false;
        }
    }
    if(!ok){
        cout << "Fegla Won" << endl;
        return;
    }
    

    int answer = 0;
    for(int i = 0; i < ans[0].size(); i++){
        vector<int> cnts;
        for(int j = 0; j < N; j++){
            cnts.push_back(ans[j][i].cnt);
        }
        sort(cnts.begin(), cnts.end());
        int mid = cnts[N/2];
        for(int i = 0; i < cnts.size(); i++)
            answer += abs(cnts[i] - mid);
    }
    cout << answer << endl;

}
int main(int argc, const char * argv[])
{
    freopen("/Users/jinfu/Workspace/test/input.in","r",stdin);
    freopen("/Users/jinfu/Workspace/test/output","w",stdout);
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        printf("Case #%d: ", t+1);
        Solve();
    }
    return 0;
}