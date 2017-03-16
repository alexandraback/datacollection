#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int test(istream& ifp){
    size_t N;
    ifp >> N;
    vector<string> table;
    vector<vector<pair<char, size_t> > > reduced;
    string temp;
    for (size_t i = 0; i < N; ++i){
        ifp >> temp;
        table.push_back(temp);
    }
    for (size_t i = 0; i < N; ++i){
        reduced.push_back(vector<pair<char, size_t> >());
        for(size_t j = 0; j < table[i].size(); ){
            char current = table[i][j];
            size_t cnt=0;
            for (; table[i][j] == current; ++j,++cnt){}
            reduced[i].push_back(pair<char, size_t>(current,cnt));
        }
    }
    for (size_t i = 1; i < N; ++i)
        if (reduced[0].size() != reduced[i].size()) return -1;
    for (size_t i = 0; i < reduced[0].size(); ++i)
        for (size_t j = 1; j < reduced.size(); ++j)
            if (reduced[0][i].first != reduced[j][i].first) return -1;
    /* Now Omar wins */
    // ** the median minimizes average absolute deviation (from Wikipedia)
    bool med_exact_bool=reduced.size()%2;
    size_t steps=0;
    for (size_t i = 0; i < reduced[0].size(); ++i){
        vector<size_t> mediansample(0);
        for (size_t j = 0; j < reduced.size(); ++j)
            mediansample.push_back(reduced[j][i].second);
        sort(mediansample.begin(), mediansample.end());
        size_t objective;
        if (med_exact_bool) 
            objective=mediansample[mediansample.size()/2];
        else
            objective=(mediansample[mediansample.size()/2]+mediansample[mediansample.size()/2-1])/2;
        for (size_t j = 0; j < mediansample.size(); ++j){
            if (2*j < mediansample.size()) steps+= (objective-mediansample[j]);
            else steps+= (mediansample[j]-objective);
        }
    }
    return steps;
}

int main(){
    ifstream fp("input.txt");
    ofstream ofp("output.txt");
    size_t T;
    fp >> T;
    for (size_t i = 0; i < T; ++i){
        int result = test(fp);
        ofp << "Case #" << i+1 << ": ";
        if (result < 0) ofp << "Fegla Won";
        else ofp << result;
        ofp << endl;
    }
    ofp.close();
    fp.close();
    return 0;
}