#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

typedef long long ll;

int main(){

    int T;
    cin >> T;

    int A1, A2;
    bool chosen[16];
    int cardread;
    int result=0;
    int cardcount;

    for(int i=1;i<=T;i++){
        for(int k=0;k<16;k++) chosen[k]=true;
        cin >> A1;
        for(int k=1;k<=4;k++) for(int l=1;l<=4;l++){
            cin >> cardread;
            if(k!=A1) chosen[cardread-1]=false;
        }
        cin >> A2;
        for(int k=1;k<=4;k++) for(int l=1;l<=4;l++){
            cin >> cardread;
            if(k!=A2) chosen[cardread-1]=false;
        }
        cardcount=0;
        for(int k=0;k<16;k++) if(chosen[k]){
            cardcount++;
            result=k+1;
        }

        cout << "Case #" << i << ": ";
        if(cardcount==1){
            cout << result;
        }else{
            if(cardcount==0){
                cout << "Volunteer cheated!";
            }else cout << "Bad magician!";
        }
        cout << endl;
    }

    return 0;
}
