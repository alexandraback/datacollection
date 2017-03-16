
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string
uniq(const string& s) {
    string u;
    
    int i = 0;
    while (i < s.length()) {
          char c = s[i];
          int j = i+1;
          while (j < s.length() && s[j] == c)
                ++j;
          
          u += c;
          i = j;
    }
    
    return u;
}

int
numOfRepeat(const std::string s, int k)
{
    int i = 0;
    
    int p = 0;
    while (p < k) {
        while(s[i] == s[i+1]) {
            ++i;
        }
        ++p;
        ++i;
    }
    
    int ret = 1;
    while (i + 1 < s.length() && s[i] == s [i+1]) {
        ++ret;
        ++i;
    }
    
    return ret;
}

int main()
{
    ifstream infile("file.in");
    ofstream outfile("file.out");
    
    int T;
    infile >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        infile >> N;
        vector<string> words(N);
        for (int i = 0; i<N; ++i) {
            infile >> words[i];
        }
        
        int ans = 0;
        bool ok = true;
        
        if (N > 0) {
           string u = uniq(words[0]);

           for (int i = 1; i < N; ++i) {
               if (uniq(words[i]) != u) {
                   ok = false;
                   break;
               }
           }
           
           if (ok) {
               std::vector<vector<int> > count(u.length());
               
               //countEach(words, u, count);
               for (int i = 0; i < u.length(); ++i) {
                   for (int j = 0; j< N; ++j) {
                       int k = numOfRepeat(words[j], i);
                       count[i].push_back(k);
                   }
               }
                   

               for (int i = 0; i < u.length(); ++i) {
                   sort(count[i].begin(), count[i].end());
                   int m = count[i][N/2];
                   
                   int sum = 0;
                   for (int j = 0; j < N; j++) {
                       sum += std::abs(count[i][j] - m);
                   }
                   ans += sum;
               }
           }
        }
         
        outfile << "Case #" << t << ": ";
        if (ok) {
            outfile << ans << endl;
        }
        else {
            outfile << "Fegla Won" << endl;
        }
    }
}
