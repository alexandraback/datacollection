#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<pair<char, int> > countChar(string& s){
    char prev = '\0';
    int cnt = 0;
    vector<pair<char, int> > res;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != prev){
            if(cnt > 0){
                res.push_back(pair<char,int>(prev, cnt));
            }
            prev = s[i];
            cnt = 1;
        }else{
            cnt++;
        }
    }
    if(cnt > 0){
        res.push_back(pair<char,int>(prev, cnt));
    }
    return res;
}

int iabs(int v){
    if(v < 0) return -v;
    return v;
}

int solve(vector<string>& strs){
    vector<vector<pair<char, int> > > counts(strs.size());
    for(int i = 0; i < strs.size(); i++){
        counts[i] = countChar(strs[i]);
    }
    int len = counts[0].size();
    for(int i = 0; i < counts.size(); i++){
        if(counts[i].size() != len) return -1;
    }
    for(int i = 0; i < counts.size(); i++){
        for(int j = 0; j < len; j++){
            if(counts[i][j].first != counts[0][j].first) return -1;
        }
    }
    int ans = 0;
    for(int i = 0; i < len; i++){
        int best = 100*100*100;
        for(int j = 0; j < counts.size(); j++){
            int sum = 0;
            for(int k = 0; k < counts.size(); k++){
                sum += iabs(counts[j][i].second - counts[k][i].second);
            }
            best = min(best, sum);
        }
        ans += best;
    }
    return ans;
}

int main(){
    int T;
    int N;

    cin >> T;
    for(size_t t = 1; t <= T; t++){
        cin >> N;
        vector<string> strs(N);
        for(int i = 0; i < N; i++){
            cin >> strs[i];
        }
        int ans = solve(strs);
        cout << "Case #" << t << ": ";
        if(ans == -1){
            cout << "Fegla Won" << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}

