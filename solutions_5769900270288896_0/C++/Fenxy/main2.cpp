#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


template<class T>
void printVec(vector<T> v){

    for(auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

template<class T>
void print2DVec(vector<vector<T> > V){
    for(auto v : V){
        printVec<T> (v);
    }
}

ifstream fin("in1.in");
ofstream fout("out1.out");

int ans;
int n, m, k;

bool vis[100];

int dfs(int ind,int cnt){
    if(ind >= n * m)
        return 1;
    vis[ind] = true;
    if(cnt==k){
        int cur=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j < m-1){
                    int a1=i * m + j;
                    int a2=i * m + j + 1;
                    if(vis[a1] && vis[a2]){
                        cur++;
                    }
                }
                if(i > 0){
                    int a1=i * m + j;
                    int a2=(i-1) * m + j;
                    if(vis[a1] && vis[a2]){
                        cur++;
                    }
                }
            }
        }
        if(cur < ans){
            ans = cur;
        }
    }else{
        dfs(ind+1, cnt+1);
    }
    vis[ind]=false;
    dfs(ind+1,cnt);

    return 0;
}


int calc(){

    fin >> n >> m >> k;
    int ans = n * (m - 1) + m * (n - 1);
    if(k == 0)
        ans = 0;
    else
        dfs(0,1);
    return ans;
}

int main()
{

    int T;
    fin >> T;
    for(int C = 1; C <= T; ++C){
        fout << "Case #" << C << ": " << calc() << endl;
    }
    return 0;
}
