#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

int b;
int m[1000];
int n;

long long getSum(long long t)
{
    long long sum = 0;
    for (int i = 0; i < b; ++i) {
        sum += (t + m[i] - 1) / m[i];
    }
//    cout << "t " << t << " sum " << sum << endl;
    return sum; 
}

bool feasible(long long t)
{
    return getSum(t) >= n;
}

void work(ifstream & fin, int caseno)
{
    fin >> b >> n;

    int maxi = 0;
    int mini = 10000000;
    for (int i = 0; i < b; ++i) {
        fin >> m[i];
        maxi = max(maxi, m[i]);
        mini = min(mini, m[i]);
    }   

//    cout << "max " << maxi << " min " << mini << endl;

    // binary search
    long long lower = 0;
    long long upper = (long long)(max(0, n-b) / b + 1) * maxi;

 //   cout << "lower " << lower << " upper " << upper << endl;

    while (lower < upper) {
        long long middle = (lower + upper + 1) / 2;
        if (feasible(middle))
            upper = middle - 1;
        else
            lower = middle;
    }

    // the solution 
    long long sol = upper + 1;
    int sum = getSum(sol - 1); 
    int count = n - sum;

    //cout << "sol " << sol << " sum " << sum << " count " << count << endl;

    for (int i = 0; i < b; ++i) {
     //   cout << "m " << m[i] << " sol " << sol << " mod " << sol % m[i] << endl;
        if (sol % m[i] == 1 || m[i] == 1) {
            --count;
            if (count == 0) {
                cout << "Case #" << caseno << ": " << i + 1 << endl;
                return;

            }

        }

    }
    cout << "Case #" << caseno << ": FAIL" << endl;
    cout << b << " " << n << endl;
    for (int i = 0; i < b; ++i)
        cout << m[i] << " ";
    cout << endl;
}


int main()
{
    ifstream fin;
    fin.open("input");
    int c;
    fin >> c;
    for (int i = 0; i < c; ++i) {
        work(fin, i + 1);
    }
    fin.close();
}
