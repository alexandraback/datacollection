#include <bits/stdc++.h>
using namespace std;
#define FREP(b) for(int i=0;i<b;i++)
#define REP(a,b,c) for(int a=b;a<c;a++)
#define asd(x) cout << "Here for " << #x << " :" <<x << endl;
#define asdf(x, y)  cout << "Here FOR " << #x << " :" << x << " " << #y  << " :" << y << endl;
typedef pair<int,int> ii;
typedef long long LL;
struct data{
    int no;
    char c;
    data(char cc, int noo){
        c = cc, no = noo;
    }
    data(){}
};
vector<data> G[108];
string inp[108];
void fillin(int v){
    char p;
    int cnt = 0;
    for(int i = 0; i < inp[v].size(); i++){
        if(i == 0){
            p = inp[v][i];
            cnt=1;
            continue;
        }
        if(p != inp[v][i]){
            G[v].push_back(data(p, cnt));
            p = inp[v][i], cnt = 1;
        }
        else cnt++;
    }
    G[v].push_back(data(p, cnt));
}
vector<int> cur;
int fee(){
    sort(cur.begin(), cur.end());
    if(cur.size() == 0) return 0;
    int mini = INT_MAX;
    for(int i =0 ; i < cur.size(); i++){
        if(i != 0 && cur[i] == cur[i-1]) continue;
        int ans = cur[i], cnt = 0;
        REP(j,0,cur.size()){
            cnt += abs(ans - cur[j]);
        }
        mini = min(mini, cnt);
    }
    cur.clear();
    return mini;
}
int solve(){
    int N;
    cin >> N;
    FREP(N+2) G[i].clear(), inp[i].clear();
    FREP(N){
        cin >> inp[i];
//        asd(i);
        fillin(i);
   //     REP(j,0,G[i].size()){
  //         asdf(G[i][j].c, G[i][j].no);
     //   }
    }
    int ans = 0, cnt;
    char p;

    for(int idx = 0; idx < 100; idx++){ // 1st element .. 
        cnt = -1;
        cur.clear();
        for(int v = 0; v < N; v++){
            if(idx >= G[v].size()) continue;
            if(cnt == -1) p = G[v][idx].c, cnt = 0;
            if(p != G[v][idx].c) return -1;
            cur.push_back(G[v][idx].no);
            cnt++;
        }
        if(cnt == -1) continue;
        if(cnt != N) return -1;
//        printf("sending for .. %c\n",p);
  //      REP(j,0,cur.size()) cout << cur[j] << " ";
    //    cout << endl;
        ans += fee();
    }
    return ans;
}
int main()
{
    
    int test;
    cin >> test;
    REP(t,1,test+1){
        int z = solve();
        if(z == -1) printf("Case #%d: Fegla Won\n",t);
        else printf("Case #%d: %d\n",t,z);
    }
    return 0;
}
