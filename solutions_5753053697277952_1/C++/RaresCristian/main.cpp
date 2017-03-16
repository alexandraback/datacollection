
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <set>
#include <stack>
#include <map>
#include <vector>
using namespace std;
typedef long long int lli;


int main() {
    
    ifstream fin ("input.txt");
    ofstream fout ("ans.txt");
    
    lli T; fin >> T;
    for (lli t = 0; t < T; t++) {
        
        vector<pair<int, int> > st;
        
        int sum = 0;
        int N; fin >> N;
        for (int i = 0; i < N; i++) {
            int x; fin >> x;
            st.push_back(make_pair(x, 'A' + i));
            sum += x;
        }
        
        fout << "Case #" << t+1 << ": ";
        
        sort(st.begin(), st.end());
        while (st[st.size()-1].first != 0) {
            int big = st[st.size()-1].first;
            int next = st[st.size()-2].first;
            
            if (big == 1) {
                if (st.size() >= 3) {
                    if (st[st.size()-3].first == 1) {
                        fout << char(st[st.size()-1].second) << " ";
                        st[st.size()-1].first --;
                        sum --;
                    }
                    else {
                        fout << char(st[st.size()-1].second) << char(st[st.size()-2].second);
                        st[st.size()-1].first --;
                        st[st.size()-2].first --;
                    }

                }
                else {
                    fout << char(st[st.size()-1].second) << char(st[st.size()-2].second);
                    st[st.size()-1].first --;
                    st[st.size()-2].first --;
                }
            }
            
            else if (big - 2 < next) {
                if (next > (sum-2)/2) {
                    fout << char(st[st.size()-1].second) << char(st[st.size()-2].second) << " ";
                    st[st.size()-1].first --;
                    st[st.size()-2].first --;
                    sum -= 2;
                }
                else {
                    fout << char(st[st.size()-1].second) << char(st[st.size()-1].second) << " ";
                    st[st.size()-1].first -= 2;
                    sum -= 2;
                }
            }
            else {
                fout << char(st[st.size()-1].second) << char(st[st.size()-1].second) << " ";
                st[st.size()-1].first -= 2;
                sum -= 2;
            }
            sort(st.begin(), st.end());
        }
        fout << "\n";
    }
    
    
    return 0;
}

