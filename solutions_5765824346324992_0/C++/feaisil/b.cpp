#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

#define VCERR(vect)for(size_t iiivcerr=0; iiivcerr<vect.size(); iiivcerr++) {errlog(vect[iiivcerr]); errlog(" ");} errlog("\n");
#define VIN(t,vect, len) t vect(len); for(size_t iiivcerr=0; iiivcerr<len; iiivcerr++) cin >> vect[iiivcerr];

typedef vector<string> Vs;
typedef vector<long> Vi;
typedef map<long,Vi> MVi;
typedef vector<string> vstr;

template<typename T, bool a=false>
void errlog(const T& v)
{
    if(a)
    {
        cerr << v;
    }
}

long f(long i, Vi& v)
{
    errlog("f: ");
    long c=0;
    for(long j=0; j<v.size(); j++)
    {
        errlog(c);
        errlog(" ");
        errlog(j);
        errlog(" ");
        errlog(v[j]);
        errlog(" ");
        errlog(i);
        errlog(", ");
        if(i%v[j] == 0)
        {
            c++;
        }
    }
    errlog(c);
    errlog("\n");
    return c;
}

long pgcd(long a, long b)
{
    long pgcd=min(a,b);
    while (pgcd>=1)
    {
        if(a%pgcd==0 && b%pgcd==0)
            break;
        pgcd--;
    }
    return pgcd;
}

long ppcm(long X, long Y)
{
    return (X*Y)/pgcd(X,Y);
}
int main()
{
    long T;
    cin >> T;
    cerr << T << endl;
    string re;

    for(long tt=1; tt <= T; tt++)
    {
        if(tt*1000/T%10 ==0)
            cerr << tt << ", " << tt*100/T<< "%" << endl;
        cout << "Case #" << tt << ": ";

        long B,N;
        cin >> B >> N;
        errlog(B);errlog(" "); errlog(N); errlog("\n");
        VIN(Vi,v, B);
        VCERR(v);

        long s=100000;
        long m=0;
        long pp=1;

        for(long i=0; i<B; i++)
        {
            pp=ppcm(pp,v[i] );
            s=min(v[i],s);
            m=max(v[i],m);
        }
        long c, n=0,l=0;

        for(long i=0; i<B; i++)
        {
            l+=pp/v[i];
        }
        cerr << pp << " "<< l << " " << s << " " << m << endl;
        c=(N/l-1)*l;
        n=c;
        bool o = false;
        for(long i=pp*c; i < N*pp+1 and not o; i=i+s)
        {
            errlog(c);
            errlog(i);
            errlog("\n");
            n+=f(i,v);
            if(N>c and N<=n)
            {
                errlog("res: ");
                long b=0;
                for(long k=0; k<v.size(); k++)
                {
                    errlog(b);
                    errlog(" ");
                    errlog(c+b);
                    errlog(" ");
                    errlog(k);
                    errlog(" ");
                    errlog(v[k]);
                    errlog(" ");
                    errlog(i);
                    errlog(", ");
                    if(i%v[k]== 0)
                    {
                        b++;
                        if(c+b==N)
                        {
                            o = true;
                            c=k+1;
                        }
                    }
                }
            }
            else
            {
                c=n;
            }
        }


        cout << c << endl;
    }

    return 0;
}
