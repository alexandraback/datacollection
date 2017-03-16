#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream in("A-small-attempt0(1).in");
    ofstream out("A-small.out");
#define cin in
#define cout out
    int T=0;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N=0;
        cin>>N;
        vector<int> mush;
        int sum_a=0,sum_b=0;
        int c,pc,mini=0;
        cin>>c;
        pc=c;
        mush.push_back(c);
        for(int j=1;j<N;j++)
        {
            cin>>c;
            mush.push_back(c);
            sum_a+=(pc-c)>0?(pc-c):0;
            if((pc-c)>0)
            {
                if(mini<(pc-c))
                {
                    mini=(pc-c);
                }
            }
            pc=c;
        }
        for(int j=0;j<N-1;j++)
        {
            int eated=mush[j]-mini;
            if(eated>0)
                sum_b+=mini;
            else
                sum_b+=mush[j];

        }
        cout<<"Case #"<<i+1<<": "<<sum_a<<" "<<sum_b<<endl;
    }
    return 0;
}
