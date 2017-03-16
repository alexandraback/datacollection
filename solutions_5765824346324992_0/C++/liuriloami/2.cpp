#include <bits/stdc++.h>
using namespace std;

long long int nTests;
long long int b, n;
vector<long long int> vet;

long long int testa(long long int t) {
    long long int res = 0;
    for (long long int i = 0; i < b; i++)
        res += 1 + t/vet[i];
    return res;
}
int main (int argc, char** argv) {    
    cin >> nTests;
    for (long long int test = 1; test <= nTests; test++) {
        vet.clear();
        cin >> b >> n;
        long long int maxTime = -1;
        for (long long int i = 0; i < b; i++) {
            long long int tmp;
            cin >> tmp;
            vet.push_back(tmp);
            maxTime = max(maxTime, tmp);
        }
        long long int ini = 0, end = (maxTime*n)/b;
        while (testa(end) >= n && testa(ini) < n && end-ini != 1) {
            long long int mid = (end+ini)/2;
            long long int res = 0;
            for (long long int i = 0; i < b; i++)
                res += 1 + mid/vet[i];
            if (res >= n)
                end = mid;
            else 
                ini = mid;
        }
        long long int bef = 0;
            for (long long int i = 0; i < b; i++)
                bef += 1 + (end-1)/vet[i];
        long long int res, count = 0;
        for (long long int i = 0; i < b; i++)
            if (end%vet[i] == 0 && count == n-bef-1) {
                res = i+1;
                break;
            } else if (end%vet[i] == 0)
                count++;
        if (n <= b) 
            res = n;
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}