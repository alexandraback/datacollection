#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;

int a[30];
int main() {
    int t, n;
    cin >> t;
    for(int v=0; v < t; v++){
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }

        cout << "Case #" << v + 1 << ": ";
        while(sum > 0){
            int max1 = 0;
            for(int i = 0; i < n; i ++)
                if(a[i] > a[max1])
                    max1 = i;

            a[max1]--; sum--;
            int max2 = 0;
            for(int i = 0; i < n; i ++)
                if(a[i] > a[max2])
                    max2 = i;
            a[max2]--;sum--;
            bool zz = true;
            for(int i = 0; i < n; i ++)
                if(a[i] >= sum /2 + 1)
                    zz = false;
            if(!zz){
                a[max2]++;sum++;
                char z = 'A' + max1;
                cout <<  z << " ";
            }else{
                char z = 'A' + max1;
                char z1 = 'A' + max2;
                cout <<  z << z1 << " ";
            }
        }
        cout << endl;
    }

}
