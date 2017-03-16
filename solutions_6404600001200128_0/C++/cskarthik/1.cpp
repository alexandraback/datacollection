#include <iostream>
using namespace std;
int main()
{
    int T, n;
    cin >> T;
    for(int i = 1; i<=T; i++)
    {
        int max, y, z;
        max = 0;
        y = 0;
        z = 0;
        cin >> n;
        int *a;
        a = new int[n];
        cin >> a[0];
        for(int j=1; j<n; j++)
        {
            int diff = 0;
            cin >> a[j];
            if(a[j] < a[j-1]) 
             diff = a[j-1] - a[j];
            if(diff > max)
            {
                max = diff;
                //cout << diff << endl;
            }
        }    
        //cout << max << endl;
        for(int j=0; j<n-1; j++)
        {
            if(a[j] < max) z+=a[j];
            else z+=max;
        }
        for(int j=0; j<n-1; j++)
        {
            if(a[j] < a[j+1]) y+=0;
            else y+= (a[j] - a[j+1]);
        }
        cout << "Case #" << i << ": " << y << " " << z << endl; 
        delete[] a;
    }
    return 0;
}