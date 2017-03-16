#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    string c, j;
    int casos;
    cin >> casos;
    for(int cas = 1; cas <= casos; cas++) {
        int n, sum = 0;
        cin >> n;
        cout << "Case #" << cas << ": ";
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            sum += p[i];
        }
        while(sum > 2) {
            int mayor = 0;
            for(int i = 0; i < n; i++)
                mayor = max(mayor, p[i]);
            int x = 0;
            for(int i = 0; i < n; i++) {
                if(p[i] == mayor) {
                    x++;
                    cout << ((char)(i + 'A'));
                    p[i]--;
                    sum--;
                    if(x == 2 || (x == 1 && mayor == 1)) break;
                }
            }
            cout << ' ';
        }
        for(int i = 0; i < n; i++)
            if(p[i] > 0) {
                p[i]--;
                cout<<((char)(i + 'A'));
            }
        cout << endl;

    }
}
