#include <iostream>
#include <climits>
using namespace std;
int gcd(int a, int b)
{
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
 
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}
int main()
{
    int T, B;
    long long int N, res;
    cin >> T;
    for(int i = 1; i<=T; i++)
    {
        cin >> B >> N;
        long long int *m, *a, *b, start;
        m = new long long int[B];
        a = new long long int[B];
        b = new long long int[B];
        for(int j=0; j<B; j++)
        {
            cin >> m[j];
            b[j] = m[j];
        }
        for(int j=0; j<B-1; j++)
        {
            b[j+1] = lcm(b[j], b[j+1]);
        }
        int LCM = b[B-1];
        for(int j=0; j<B; j++)
        {
            b[j] = m[j];
        }
        int seq = 0;
        for(int j=0; j<B; j++)
        {
            seq += (LCM/b[j]);
        }
        //cout << LCM << "  " << seq << endl;
        if(N%seq == 0) 
        {
            start = N - seq + 1;
        }
        else
        {
            start = N - (N % seq) + 1;
        }
        if(N <= B) 
            res = N;
        else
        {
            long long int k = start, ind;
            for(int j=0; j<B; j++)
            {
                a[j] = k;
                k++;
                if(k == N)
                {
                    ind = j;
                    break;
                }
            }
            int pres = k;
            while(pres <= N)
            {
                long long int min = INT_MAX;
                ind = 0;
                for(int j=0; j<B; j++)
                {
                    if(b[j] < min) 
                    {
                        min = b[j];
                        ind = j;
                    }
                }
                for(int j=0; j<B; j++)
                {
                    if(b[j] == min) 
                    {
                        min = b[j];
                        ind = j;
                        break;
                    }
                }
                for(int j=0; j<B; j++)
                {
                    b[j] -= min;
                }
                a[ind] = pres;
                b[ind] = m[ind];
                pres++;
            }
            res = ind + 1;
        }
        cout << "Case #" << i << ": " << res << endl; 
        delete[] m;
        delete[] a;
        delete[] b;
    }
    return 0;
}