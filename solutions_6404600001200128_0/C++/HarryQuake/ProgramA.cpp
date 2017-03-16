#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("D:\\GoogleCodeJam\\in.txt","r",stdin);
    freopen("D:\\GoogleCodeJam\\out.txt","w",stdout);

    int TestNum = 0;
    cin >> TestNum;
    for (int testCase = 0;testCase < TestNum;testCase++)
	{
	    int N;
	    cin >> N;
	    vector<int> v;
	    int temp;
        for (int i=0;i<N;i++)
        {
            cin >> temp;
            v.push_back(temp);
        }

        int m1=0, m2=0, r = 0;
        for (int i=0;i<N-1;i++)
        {
            if (v[i] > v[i+1]) m1 += v[i]-v[i+1];
            if (v[i]-v[i+1] > r) r = v[i]-v[i+1];
        }

        for (int i=0;i<N-1;i++)
        {
            m2 += (v[i]>r ? r : v[i]);
        }

        if (testCase != 0) cout << endl;
        cout << "Case #" << (testCase + 1) << ": " << m1 << " " << m2;
	}
    return 0;
}
