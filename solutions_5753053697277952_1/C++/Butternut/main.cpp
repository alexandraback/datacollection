// Author:   Charles AUGUSTE

#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <Imagine/LinAlg.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int compt=1; compt<T+1; ++compt){
        int N;
        cin >> N;
        string s= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        vector<int> nb;
        for (int i =0; i<N; i++){
            int p;
            cin >> p;
            nb.push_back(p);
        }
        cout << "Case #" << compt << ": ";
        if (N==2){
            while (nb[0]!=0){
                nb[0]-=1;
                cout << "AB ";
            }
        }
        else{
            int compteur=0;
            int j = 0;
            for (int i = 0; i< nb.size(); ++i){
                if (nb[i]>compteur){
                    j=i;
                    compteur=nb[i];
                }
            }
            while (compteur!=0){
                nb[j]=nb[j]-1;
                cout << s[j] << " ";
                compteur=0;
                if (nb[nb.size()-1]==1 && nb[nb.size()-2]==1 && nb[nb.size()-3]==0){
                    cout << s[nb.size()-2] << s[nb.size()-1];
                    break;
                }
                for (int i = 0; i< nb.size(); ++i){
                    if (nb[i]>compteur){
                        j=i;
                        compteur=nb[i];
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
