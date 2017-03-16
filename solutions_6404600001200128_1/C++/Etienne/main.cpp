#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void doTest()
{
    int n;
    cin >> n;
    vector<int> ms;
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        ms.push_back(tmp);
    }

    int method1=0;
    int maxgap = 0;
    for(int i=1; i<n; i++)
        if(ms[i] < ms[i-1])
        {
            method1 += ms[i-1] - ms[i];
            maxgap = max(maxgap, ms[i-1]-ms[i]);
        }

    int method2 = 0;
    for(int i=0; i<n-1; i++)
        method2 += min(ms[i], maxgap);

    cout << method1 << " " << method2 << endl;
}


int main()
{
    int ncases;
    cin >> ncases;
    for(int i=0; i<ncases; i++)
    {
        std::cout << "Case #" << i+1 << ": ";
        doTest();
    }
}
