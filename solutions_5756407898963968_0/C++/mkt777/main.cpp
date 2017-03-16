#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin;
    cin.open("data.in");
    ofstream cout;
    cout.open("output.txt");
    int x, cases, res[4], res2[4], n, fin;
    bool sepuede, rep;
    cin >> cases;
    for(int i=1;i<=cases;i++){
        sepuede=false;
        rep=false;
        cin >> x;
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                cin >> n;
                if(j+1==x){
                    res[k]=n;
                }
            }
        }
        cin >> x;
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                cin >> n;
                if(j+1==x){
                    res2[k]=n;
                }
            }
        }
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(res[j]==res2[k]){
                    if(sepuede){
                        sepuede=false;
                        rep=true;
                        break;
                    }
                    else{
                        sepuede=true;
                        fin=res[j];
                    }
                }
            }
            if(rep)
                break;
        }
        cout << "Case #" << i << ": ";
        if(sepuede)
            cout << fin << endl;
        else{
            if(rep)
                cout << "Bad magician!" << endl;
            else
                cout << "Volunteer cheated!" << endl;
        }
    }
    cin.close();
    cout.close();
    return 0;
}
