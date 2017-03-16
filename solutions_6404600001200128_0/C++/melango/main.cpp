#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <gmpxx.h>
using namespace std;

int main()
{
    ifstream input;
    input.open("small.in");
    ofstream output;
    output.open("output.txt");
    int cse=1;
    int t;
    input>>t;

    while(cse<=t)
    {
        int ans1,ans2,N;
        ans1=0;
        ans2=0;
        vector<int> mushrooms;
        input>>N;
        for(int i=0;i<N;i++){
        int a;input>>a;
        mushrooms.push_back(a);
        }
        int maxdiff=0;
        for(int i=0;i<N-1;i++){
        if(mushrooms[i+1]<mushrooms[i]){
        ans1+=mushrooms[i]-mushrooms[i+1];
        maxdiff=max(maxdiff,mushrooms[i]-mushrooms[i+1]);}
        }

        for(int i=0;i<N-1;i++){
        if(mushrooms[i]>=maxdiff){
        ans2+=maxdiff;
        }
        else {ans2+=mushrooms[i];}
        }


        output<<"Case #"<<cse<<": "<<ans1<<" "<<ans2<<endl;
        cout<<"Case #"<<cse<<": "<<ans1<<" "<<ans2<<endl;
        cse++;
    }

    return 0;
}

