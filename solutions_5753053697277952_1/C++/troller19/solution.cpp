#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath> 

using namespace std;

int main(){
    //freopen("practice.in","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t, n;
    cin >> t;
    char letter[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for(int q=0;q<t;q++){
        cout << "Case #" << q+1 << ":";
        cin >> n;
        vector <int> v(n,0);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        bool done = false;
        while(done == false){
            int numlimit = 0;
            int limit = 0;
            for(int i=0;i<n;i++){
                limit += v[i];
            }
            limit = limit/2;
            for(int i=0;i<n;i++){
                if(v[i] == limit){
                    numlimit++;
                }
            }
            //cout << "numlimit"<<limit;
            if(numlimit == 0){
                int max = -1;
                int index = -1;
                for(int i=0;i<n;i++){
                    if(v[i] > max){
                        max = v[i];
                        index = i;
                    }
                }
                cout << " " << letter[index];
                v[index] -= 1;
            }
            else{
                if(numlimit == 2){
                    cout << " ";
                    for(int i=0;i<n;i++){
                        if(v[i] == limit){
                            v[i] -= 1;
                            cout << letter[i]; 
                        }
                    }
                }
                else{
                    int max = -1;
                    int index = -1;
                    for(int i=0;i<n;i++){
                        if(v[i] > max){
                            max = v[i];
                            index = i;
                        }
                    }
                    cout << " " << letter[index];
                    v[index] -= 1;
                    
                }
            }
            done = true;
            for(int i=0;i<n;i++){
                if(v[i] != 0){
                    done = false;
                    break;
                }
            }
        }
        cout << endl;
    }


    return 0;
}