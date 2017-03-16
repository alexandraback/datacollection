#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    freopen("D:\\GoogleCodeJam\\in.txt","r",stdin);
    freopen("D:\\GoogleCodeJam\\out.txt","w",stdout);

    int TestNum = 0;
    cin >> TestNum;
    for (int testCase = 0;testCase < TestNum;testCase++)
	{
        int B,  temp;
        long long N;
        cin >> B >> N;
        vector<int> m;
        for (int i=0;i<B;i++){
            cin >> temp;
            m.push_back(temp);
        }

        long long maxW = ((long long)(*max_element(m.begin(),m.end())))*N;
        long long low=0, high=maxW;
        long long t = maxW/2;
        long long s = 0,c=0;
        do {
            s = 0;c=0;
            for (int i=0;i<B;i++)
            {
                c += (t/m[i]);
                if (t%m[i] == 0) s++;
                else c++;
            }
            if (N > c && N <= c+s) {break;}
            if (N <= c) {high=t;t=(high+low)/2;}
            if (N > c+s) {low=t;t=(high+low)/2;}
        }while(true);

        int result = 0;
        int choose = N - c;
        int cur=0;
        for (int i=0;i<B;i++)
        {
            if (t%m[i] == 0 )
            {
                cur++;
                if(cur == choose)
                {
                    result = i+1;
                    break;
                }

            }
        }

        if (testCase != 0) cout << endl;
        cout << "Case #" << (testCase + 1) << ": " << result;
	}
    return 0;
}
