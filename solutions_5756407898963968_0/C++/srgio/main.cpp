#include <iostream>

using namespace std;

int main()
{
    int tests,a,b,m[4],n[4], t = 1;
    cin >> tests;
    while(tests--){
        for(int j = 0; j <= 1; ++j){
            cin >> a;
            a -= 1;
            a *= 4;
            int c = 0;
            while(c < 16){
                cin >> b;
                if(c >= a && c < a+4){
                    if(j) n[c%4] = b;
                    else m[c%4] = b;

                }
                c++;
            }
        }
        int cnt = 0;
        int ind = 0;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                if(m[i] == n[j]){
                    cnt++;
                    ind = i;
                }
            }
        }
        if(cnt == 1) cout << "Case #" << t << ":" << " " << m[ind] << endl;
        else if(cnt == 0) cout << "Case #" <<t<< ": Volunteer cheated!" << endl;
        else if(cnt > 1) cout << "Case #" << t <<": Bad magician!" << endl;
        t++;
    }
    return 0;
}
