#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set> 
#include<cstdlib>
#include<cmath>
#include<climits>
#include<string> 
#include<sstream>
#include<queue>
#include<stack>
#include<list>

using namespace std; 

int work(vector<string> & vs){
    int N = vs.size();
    vector<int> ids(N,0); 
    vector<int> lens(N,0); 
    int re = 0; 
    while(true){
        char c = vs[0][ids[0]];
        for(int i = 0;i < N; i ++){
            while(ids[i] < vs[i].size() && vs[i][ids[i]] == c){
                ids[i]++;
                lens[i]++;
            }
            if(lens[i] == 0)
                return -1;
            //cout << "lens i " << lens[i] << endl;
        }
        int mini = -1; 
        int maxi = -1; 
        for(int i = 0; i < N; i ++){
            if(mini == -1 || mini > lens[i])
                mini = lens[i]; 
            if(maxi == -1 || maxi < lens[i])
                maxi = lens[i]; 
            //cout << lens[i] << "lens i" << endl;
        }
        //cout << mini << " " << maxi << endl; 
        int dist = INT_MAX;
        for(int x = mini ; x <= maxi; x++){
            int temp = 0; 
            for(int i = 0; i < lens.size(); i ++){
                temp += abs(lens[i]-x); 
            }
            if(temp < dist) 
                dist = temp; 
        }
        re += dist; 
        int ends = 0; 
        for(int i = 0; i < N; i ++){
            if(ids[i] == vs[i].size())
                ends++;
        }
        if(ends == N)
            break; 
        else if(ends > 0)
            return -1;
        for(int i = 0;i < N;i ++)
            lens[i] = 0; 
    }
    return re;
}

int main(){
    int T; 
    cin >> T; 
    for(int t = 1; t <= T; t++){
        int N; 
        cin >> N; 
        vector<string> vs(N); 
        for(int i = 0; i < N; i++)
            cin >> vs[i] ; 
        int re = work(vs);  
        cout << "Case #" << t << ": "; 
        if(re == -1)
            cout << "Fegla Won" << endl; 
        else 
            cout << re << endl; 
    }
}
