#include <iostream>
using namespace std;

int main() {
    int i,j,k,T,ans,a,card;
    int first[4];
    int sec[4];
    int rep[4];
    string s;
    cin >> T;
    for (i=0; i<T; i++) {
        rep[0]=rep[1]=rep[2]=rep[3]=0;
        cin >> ans;
        for (j=0; j<4; j++) {
            for (k=0; k<4; k++) {
                cin >> a;
                if (j==ans-1) {
                    first[k]=a;
                }
            }
        }
        
        cin >> ans;
        for (j=0; j<4; j++) {
            for (k=0; k<4; k++) {
                cin >> a;
                if (j==ans-1) {
                    sec[k]=a;
                }
            }
        }
        
        for (j=0; j<4; j++) {
            for (k=0; k<4; k++) {
                if (first[j]==sec[k]) {
                    rep[j]=1;
                    break;
                }
            }
        }
        
        int sum = rep[0]+rep[1]+rep[2]+rep[3];
        
        cout << "Case #" << i+1 << ": ";
        
        switch (sum) {
            case 0:
                cout << "Volunteer cheated!\n";
                break;
            case 1:
                for (j=0; j<4; j++) {
                    if (rep[j]==1) {
                        cout << first[j] << endl;
                        break;
                    }
                }
                break;
            case 2:
            case 3:
            case 4:
                cout << "Bad magician!\n";
                break;
        }
    }
    return 0;
}