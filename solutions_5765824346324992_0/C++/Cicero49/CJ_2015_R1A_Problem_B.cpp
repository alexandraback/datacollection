#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        int b;
        long n;
        cin >> b >> n;

        int* barbers = new int[b];
        int* current = new int[b];
        for(int j = 0; j < b; j++) {
            cin >> barbers[j];
            current[j] = barbers[j];
        }

        int y = 0;

        if(n <= b) {
            y = n;
        }

        n -= b;
        int startN = n;

        while(n > 0) {
            int next = 0;
            for(int j = 1; j < b; j++) {
                if(current[j] < current[next]) {
                    next = j;
                }
            }

            int subs = current[next];
            bool allout = true;

            for(int j = 0; j < b; j++) {
                current[j] -= subs;
                if(current[j] == 0) {
                    current[j] = barbers[j];
                    n--;
                    if(n == 0) {
                        y = j+1;
                        break;
                    }
                } else {
                    allout = false;
                }
            }

            if(allout) {
                int diff = startN - n;
                while(diff > 0 && n > diff) {
                    n -= diff;
                }
            }
        }

        cout << "Case #" << i << ": ";
        cout << y;
        cout << endl;
    }

    return 0;
}

