#include <vector>
#include <string>
#include <fstream>
//#include <iostream>
#include <algorithm>
using namespace std;

ifstream cin("A-small-attempt1.in");
ofstream cout("output.txt");

string compress(string s){
    string result;
    for(int i = 0; i < s.size(); i++){
        if(i == 0 || s[i] != s[i - 1])
            result.push_back(s[i]);
    }
    return result;
}

vector< pair<char, int> > getSignature(string s){
    vector< pair<char, int> > result;
    int count = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[i - 1]){
            result.push_back(make_pair(s[i - 1], count));
            count = 1;
        }
        else{
            count++;
        }
    }
    result.push_back(make_pair(s[s.size() - 1], count));
    return result;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        vector<string> strings(N);
        for(int i = 0; i < N; i++)
            cin >> strings[i];
        string compressed = compress(strings[0]);

        bool invalid = false;
        for(int i = 1; i < N; i++){
            if(compress(strings[i]) != compressed){
                invalid = true;
                break;                
            }
        }

        cout << "Case #" << t << ": ";

        if(invalid){
            cout << "Fegla won\n";
            continue;
        }

        vector< vector< pair<char, int> > > signatures(N);

        for(int i = 0; i < N; i++)
            signatures[i] = getSignature(strings[i]);

        /*
        for(int i = 0; i < N; i++){
            for(int j = 0; j < signatures[i].size(); j++)
                cout << "(" << signatures[i][j].first << "," << signatures[i][j].second << ") ";
            cout << endl;
        }
        */

        int cost = 0, l = signatures[0].size();
        for(int i = 0; i < l; i++){
            vector<int> freqs(N);
            for(int j = 0; j < N; j++){
                freqs[j] = signatures[j][i].second;
                //cout << signatures[j][i].second << endl;
            }
            sort(freqs.begin(), freqs.end());
            int median = freqs[N/2];
            //cout << median << endl;
            for(int j = 0; j < N; j++)
                cost += abs(freqs[j]-median);
        }

        cout << cost << endl;
    }
    return 0;
}