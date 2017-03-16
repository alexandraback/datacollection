#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

vector<string> v;
vector<vector<pair<char, int> > > v2;
void Go(){
    for(int i = 0; i < v.size(); i++){
        string s=v[i];
        char lastChar=s[0];
        //cout << lastChar << "\n";
        int ile=0;
        for(int j = 0; j < s.size(); j++){
            if(s[j]==lastChar){
                ile++;
            }
            else{
                //cout << s[j] << "\n";
                v2[i].push_back(make_pair(lastChar, ile));
                lastChar=s[j];
                ile=1;
            }
        }
       // cout << "\n";
    }
}

void Answer(int caseNumb){
    for(int i = 0; i < v2.size(); i++){
        if(v2[i].size()!=v2[0].size()){
            printf("Case #%d: Fegla Won\n", caseNumb);
            return;
        }
    }
    for(int i = 0; i < v2.size(); i++){
        for(int j = 0; j < v2[i].size(); j++){
            if(v2[i][j].first != v2[0][j].first){
                printf("Case #%d: Fegla Won\n", caseNumb);
                return;
            }
        }
    }
    vector<int> vec;
    int result=0;
    for(int i = 0; i< v2[0].size(); i++){
        for(int j = 0; j < v2.size(); j++){
            vec.push_back(v2[j][i].second);
        }
        int suma=0;
        for(int i = 0; i < vec.size(); i++){
            suma+=vec[i];
            //cout << vec[i] << " ";
        }
        //cout << " vec\n";
        //cout << vec.size() << " " << suma << "\n";

        int maxi=0, mini=1000000000;
        for(int i = 0; i < vec.size(); i++){
            maxi=max(maxi, vec[i]);
            mini=min(mini, vec[i]);
        }
        //cout << maxi << " " << mini << " maxi-mini\n";
        int wynik=100000000;
        for(int q = mini; q <= maxi; q++){
            int temp=0;
            for(int w = 0; w < vec.size(); w++){
                temp+=abs(q-vec[w]);
            }
            wynik=min(wynik, temp);
        }
        result+=wynik;

        suma=0;
        vec.clear();
    }
    printf("Case #%d: %d\n", caseNumb, result);
}

int main(){
    ios_base::sync_with_stdio(0);
    int numb;
    cin >> numb;
    for(int T = 0; T < numb; T++){
        int n;
        cin >> n;
        v.clear();
        v2.clear();
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            s+="_";
            v.push_back(s);
        }
        v2.resize(v.size());
        Go();
        Answer(T+1);
    }
}
