// c.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
//#include <cmath>
#include <cstdlib>

using namespace std;

#define fori(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define fore(i_,c_) for(auto i_=c_.begin();i_!=c_.end();++i_)
#define pb	push_back

typedef unsigned long long u64;

vector<u64> ms;
int B;
u64 N;

u64 fi(u64 l, u64 r)
{
    if (l==r)
        return l;
    u64 a= (l + r)/2;
    u64 n=B;
    fori(i,0,B)
    {
        n+=a / ms[i];
    }

    return (n<N)?fi(a+1,r):fi(l,a);
}

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	fori(t,0,T)
	{

        cin>>B>>N;

        ms.resize(B);
        fori(i,0,B)
        {
            cin>>ms[i];
        }

        auto mm = std::min_element(ms.begin(),ms.end());

        u64 c=fi(0,N * (*mm));

        u64 n=B;
        fori(i,0,B)
        {
            n+=c / ms[i];
        }

        int b = -1;
        if (n<N)
        {
            ++c;

           fori(i,0,B)
           {
               if (c % (ms[i]))
                   ++n;
               if (n==N)
               {
                   b=i;
                   break;
               }
           }
        } else 
        {
           fori(i,0,B)
           {
               if (c % (ms[B-i-1])==0)
               {
                  if (n==N)
                  {
                       b=B-i;
                       break;
                  }
                   --n;
               }
           }

        }
            

        cout<<"Case #"<<t+1<<": ";
        cout<<b<<std::endl;
	}

	return 0;
}

