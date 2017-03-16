#include <bits/stdc++.h>
#include <fstream>
int thingy[26];
using namespace std;
int main(){
    fstream potato;
    ofstream optato;
    int t=0, temp=0, sarm=0, magx=0, countah = 0;
    optato.open("Answer.txt");
    potato.open("A-small-attempt0.in");
    potato >> t;
    for(int i=0; i<t; i++){
        optato << "Case #" << i+1 << ": ";
        potato >> temp;
        sarm=0;
        for(int k=0; k<temp; k++){
            potato >> thingy[k];
            sarm+=thingy[k];
        }
        if(sarm%2 == 1){
                magx = 0;
            for(int k=0; k<temp; k++){
                if(thingy[k]>magx){
                        magx = thingy[k];
                        countah = k;
                }
                if(thingy[k]>sarm/2){
                    printf("ERROR ABORTED");
                    return 0;
                }
            }
            optato << (char)(countah+65) << " ";
            thingy[countah]--;
            sarm--;
        }
        while(sarm>0){
            magx = 0;
            for(int k=0; k<temp; k++){
                if(thingy[k]>magx){
                        magx = thingy[k];
                        countah = k;
                }
               if(thingy[k]>sarm/2){
                    printf("ERROR ABORTED: code %d %d %d %d", i, magx, k, thingy[k]);
                    return 0;
                }
            }
            optato << (char)(countah+65);
            thingy[countah]--;
            magx = 0;
            for(int k=0; k<temp; k++){
                if(thingy[k]>magx){
                    magx = thingy[k];
                    countah = k;
                }
            }
            optato << (char)(countah+65) << " ";
            thingy[countah]--;
            sarm -=2;
        }
    optato << "\n";
    }
optato.close();
}
