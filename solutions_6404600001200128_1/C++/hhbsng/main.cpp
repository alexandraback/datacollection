#include <iostream>
using namespace std;

typedef unsigned int uint;

void run();

int main()
{
    uint T;
    cin >> T;
    for(uint i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        run();
        cout << endl;
    }
    return 0;
}

void run() {
    int N;
    cin >> N;
    int* m = new int [N];
    for(int i = 0; i < N; ++i) {
        cin >> m[i];
    }

    int ans1 = 0;
    for(int i = 1; i < N; ++i) {
        if(m[i] < m[i-1]) ans1 += m[i-1] - m[i];
    }
    cout << ans1 << " ";

    int rate = 0;
    for(int i = 1; i < N; ++i) {
        if(rate < m[i-1] - m[i]) rate = m[i-1] - m[i];
    }
    int ans2 = 0;
    for(int i = 1; i < N; ++i) {
        if(m[i-1] > rate) ans2 += rate;
        else ans2 += m[i-1];
    }
    cout << ans2;
}
