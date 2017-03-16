#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#define ll long long
#define life false

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

int main(){
    int t;
    fin>>t;
    for(int asdasd=0; asdasd<t; asdasd++){
        int N;
        fin>>N;
        string muisti[N];

        for(int i=0; i<N; i++)
            fin>>muisti[i];

        string pakattu[N];
        vector<int> toisto[N];

        for(int i=0; i<N; i++){
            pakattu[i]+=muisti[i][0];
            toisto[i].push_back(1);
            int l_tmp=1;

            for(int e=1; e<muisti[i].size(); e++){
                if(muisti[i][e]==muisti[i][e-1]){
                    toisto[i][l_tmp-1]++;
                }else{
                    l_tmp++;
                    pakattu[i]+=muisti[i][e];
                    toisto[i].push_back(1);
                }
            }
        }

        int pituus=pakattu[0].size();
        int vastaus=0;
        bool mahdollista=1;

        for(int i=1; i<N; i++)
            if(pakattu[i]!=pakattu[0])
                mahdollista=0;

        if(!mahdollista){
            fout<<"Case #"<<asdasd+1<<": Fegla Won"<<endl;
            continue;
        }

        for(int e=0; e<pituus; e++){
            int w_min=1000000000;
            for(int t=1; t<200; t++){
                int w_nyt=0;
                for(int i=0; i<N; i++)
                    w_nyt+=abs(t-toisto[i][e]);
                w_min=min(w_min,w_nyt);
            }
            vastaus+=w_min;
        }
        fout<<"Case #"<<asdasd+1<<": "<<vastaus<<endl;
    }
    return 0;
}
