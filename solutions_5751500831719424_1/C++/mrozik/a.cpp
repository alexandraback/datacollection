#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


void tokenize(const string& in, string& pattern, vector<int>& cnt) {
    pattern = string()+in[0];
    cnt.clear(); cnt.push_back(1);
    
    for (int i=1; i<int(in.length()); i++)
        if (in[i]==in[i-1])
            cnt.back()++;
        else
            pattern += in[i], cnt.push_back(1);
}


void getColumn(const vector<vector<int> >& in, int j, vector<int>& out) {
    out.clear();
    for (int i=0; i<int(in.size()); i++)
        out.push_back(in[i][j]);
}


int main() {
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        cout<<"Case #"<<t<<": ";
        
        string pattern;
        vector<vector<int> > matrix;
        int N; cin>>N;
        try {
            for (int i=0; i<N; i++) {
                string tmp; cin>>tmp;
                string pattmp; vector<int> row;
                tokenize(tmp, pattmp, row);
                if (i==0)
                    pattern = pattmp;
                else
                    if (pattern != pattmp) {
                        while (++i < N)
                            cin>>tmp;
                        throw 0;
                    }
                
                matrix.push_back(row);
            }
            
            int result = 0;
            for (int i=0; i<int(pattern.length()); i++) {
                vector<int> col; getColumn(matrix, i, col);
                nth_element(col.begin(), col.begin()+col.size()/2, col.end());
                int x = col[col.size()/2];
                for (int j=0; j<int(col.size()); j++)
                    result += abs(col[j]-x);
            }
            
            cout<<result<<endl;
        
        }
        catch (...) {
            cout<<"Fegla Won"<<endl;
        }
        
    }

    return 0;
}
