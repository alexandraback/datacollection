#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    FILE *fin = freopen("A-large.in", "r", stdin);
    FILE *fout = freopen("A-large.out", "w", stdout);
    long T,j=0,parties=0,max,remaining;
    string sequence;
    cin>>T;
    while(T--){
        j++;
        sequence="";
        parties=0;
        cin>>parties;
        long strength[26]={0};
        cout<<"Case #"<<j<<": ";

        // fill number of senators of each party
        for(int i=0;i<parties;i++){
            cin>>strength[i];
        }
        while(1){
            max=0;
            remaining=0;
            for(int i=0;i<parties;i++){
                if(strength[i]>strength[max])
                    max=i;
                remaining+=strength[i];
            }
            if(strength[max]==0)
                break;
            sequence+= ('A'+max);
            strength[max]--;
            remaining--;

            if(remaining==2){
                sequence+=" ";
                continue;
            }


            max=0;
            remaining=0;
            for(int i=0;i<parties;i++){
                if(strength[i]>strength[max])
                    max=i;
            }
            sequence+= ('A'+max);
            sequence+=" ";
            strength[max]--;    
            remaining--;    
            
        }
        cout<<sequence;
        cout<<endl;
    }
    
    return 0;
}