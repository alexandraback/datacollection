#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}
int main()
{
    ifstream in("B-small-attempt2(1).in");
    ofstream out("B-small.out");
#define cin in
#define cout out
    int T=0;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int ans=0;
        int B,N;
        cin>>B>>N;
        vector<int> its;
        int max=0;
        int inpt;
        for(int j=0;j<B;j++)
        {
            cin>>inpt;
            its.push_back(inpt);
        }
        if(B==1)
        {
            ans=1;
            cout<<"Case #"<<i+1<<": "<<ans<<endl;
            continue;
        }
        max=gcd(its[0],its[1]);
        max=its[0]*its[1]/max;
        for(int j=2;j<B;j++)
        {
            int tmax=gcd(max,its[j]);
            max=(max*its[j])/tmax;
        }
        int col_while=0,minut=0;
        while(minut<max)
        {

            for(int k=0;k<B;k++){
                if(minut%its[k]==0)
                {
                    col_while++;
                }
            }
            minut++;
        }
        minut=0;
        int ost=N%col_while;
        printf("%d\n",i);
        //cout<<"\n"<<ost<<" "<<col_while<<" "<<max<<endl;
        if(ost==0)
        {
            // cout<<"Case #"<<i+1<<": "<<ans<<endl;//<<" "<<sum_b<<endl;
            //continue;
            ost=col_while;
        }
            while(true)
            {
                for(int k=0;k<B;k++){
                    if(minut%its[k]==0)
                    {
                        ost--;
                    }
                    if(ost==0)
                    {
                        ans=k+1;
                        goto fuck;
                    }
                }

                minut++;
            }

        fuck:
        cout<<"Case #"<<i+1<<": "<<ans<<endl;//<<" "<<sum_b<<endl;

    }
    return 0;
}
