// C++ 11 Code Use correct compiler.  Or gcc with -std=c++11
#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;


typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;

int main()
{
    int T;
    cin >> T;

    int N;
    for(int step=1; step<=T;step++){

        cin>> N;

        vector<string> val(N);

        for(int i=0; i<N; i++){

            cin>>val[i];
        }


        vector<vector<pair<char,int> >  >stat(N);



        for(int i=0; i<N; i++){
            char prev = 'A';
            for(int j=0; j<val[i].size(); j++){
                if(val[i][j] != prev){

                    stat[i].push_back(make_pair(val[i][j],1));
                    prev = val[i][j];
                } else {
                    stat[i][stat[i].size()-1].second++;
                }
            }
        }
        cout<<"Case #"<<step<<": ";
        bool stop = false;
        for(int i=0; i<N; i++){

            if(stop) break;



            if(stat[i].size() != stat[0].size()){

                stop = true;
                break;
            }

            for(int j=0; j<stat[i].size(); j++){

                if(stat[i][j].first != stat[0][j].first){

                    stop = true;
                    break;
                }
            }
        }

        if(stop){
            cout<<"Fegla Won"<<endl;
            continue;

        }


        int cost = 0;

        for(int i=0; i<stat[0].size(); i++){

            int best = -1;

            for(int pos=1; pos<= 100; pos++){

                int cur = 0;


                for(int j=0; j<N; j++){

                    cur += abs(stat[j][i].second - pos);
                }

                if(best < 0 || cur < best){

                    best = cur;
                }


            }

            cost += best;
        }

        cout<<cost<<endl;



    }

    return 0;
}

