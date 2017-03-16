#include <iostream>
#include <cstring>

using namespace std;

int senators[26];

int main(){
    int TC, c = 1;
    cin >> TC;
    while (TC--){
        int N;
        cin >> N;
        memset(senators, 0, sizeof senators);
        int totalNum = 0;
        for (int i = 0; i < N; i++){
            cin >> senators[i];
            totalNum += senators[i];
        }
        cout << "Case #" << c++ << ": ";
        while (totalNum > 0){
            int max = senators[0];
            int maxIdx = 0;
            int typeSenLeft = 0;
            for (int i = 0; i < N; i++){
                if (senators[i])
                    typeSenLeft++;
            }
            if (typeSenLeft == 2){
                int idx1, idx2;
                bool foundOne = false;
                for (int i = 0; i < N; i++){
                    if (senators[i]){
                        if (foundOne){
                            idx2 = i;
                        }
                        else{
                            idx1 = i; foundOne = true;
                        }
                    }
                }
                totalNum -= 2;
                cout << (char)(idx1 + 'A') << (char)(idx2 + 'A') << " ";
            }
            else{
                for (int i = 0; i < N; i++){
                    if (senators[i] > max){
                        max = senators[i];
                        maxIdx = i;
                    }
                }
                cout << (char)(maxIdx + 'A') << " ";
                senators[maxIdx]--;
                totalNum--;
            }
        }
        cout << endl;
    }
}
