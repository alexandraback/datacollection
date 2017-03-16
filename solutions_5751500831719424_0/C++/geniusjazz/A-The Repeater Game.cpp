#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small-attempt0.out");
    int T, N;
    vector<string> input;
    vector<int> index;
    fin >> T;
    
    for (int t = 1 ; t <= T; t++)
    {  
        fin >> N;
        string temp; input.clear(); index.clear();
        for (int i = 0 ; i < N ; i++) {
            fin >> temp;
            input.push_back(temp);
            index.push_back(0);
        }
        
        int answer = 0;
        bool findans = true;
        while (findans) {
              char cur = input[0][index[0]];
              for (int i = 1; i < N ; i++)
                  if (cur != input[i][index[i]])
                     findans = false;
              if (findans == false) break;
                 
              vector<int> count;

              int reachend = 0;
              for (int i = 0 ; i < N ; i++) {
                  int tempcount = 0;
                  while (true) {
                        if (index[i] < input[i].length()) {                        
                            index[i]++;
                            tempcount++;
                        }
                        else {
                             reachend++;
                             break;
                        }
                        if (cur != input[i][index[i]])
                           break;
                  }

                  count.push_back(tempcount);
              }
              
              sort(count.begin(), count.end());
              for (int i = 0 ; i < N; i++)
                  answer += abs(count[i] - count[floor(N/2)]);

              if (reachend == N) break;
              if (reachend != 0) {findans = false; break;}
        }
        
        if (findans)
               fout << "Case #" << t << ": " << answer << endl; 
        else
            fout << "Case #" << t << ": " << "Fegla Won" << endl; 
    }
}
