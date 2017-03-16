#include <vector>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    long long N,i,j,k=0; cin>>N;

    for(int _i=0; _i<N; _i++)
    {
        int T; cin>>T;
        int x=0, y=0;
        vector<int> m(T);

        for(i=0; i<T; i++)
            cin>>m[i];

        int maxN=0;

        // Method 1
        for(i=1; i<T; i++) {

            maxN = max(maxN, m[i-1]-m[i]);
            x += max(0, m[i-1]-m[i]);
        }

        for(i=0; i<T-1; i++) {

            y += min(maxN, m[i]);
        }

        cout << "Case #" << _i+1 << ": " << x << " " << y <<endl;
    }

    return 0;
}

