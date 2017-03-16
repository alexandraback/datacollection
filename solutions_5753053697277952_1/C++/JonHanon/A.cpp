#include <iostream>

using namespace std;

int max(int *P, int N)
{
    int maxIdx = 0, maxVal = -1;
    for(int i = 0; i < N; i++)
        if(P[i] > P[maxIdx]) {
            maxIdx = i;
            maxVal = P[i];
        }
    return maxIdx;
}

string evacSenators(int *P, int N)
{
    int evac = 0, maxP;
    string retVal = "", temp;
    while(N - evac > 2) {
        maxP = max(P, N);
        temp += 'A'+maxP;
        retVal += temp + " ";
        P[maxP]--;
        if(P[maxP] == 0)
            evac++;
        temp = "";
    }
    for(int i = 0; i < N; i++) {
        if(P[i] != 0) {
            temp += 'A'+i;
            maxP = i;
        }
    }
    temp += " ";
    for(int i = 0; i < P[maxP]; i++)
        retVal += temp;
    return retVal;
}

int main()
{
    int T, N, *P;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> N;
        P = new int[N];
        for(int i = 0; i < N; i++)
            cin >> P[i];
        cout << "Case #" << i << ": " << evacSenators(P,N) << endl;
    }
}
