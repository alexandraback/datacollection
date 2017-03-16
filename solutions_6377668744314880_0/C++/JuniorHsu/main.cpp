#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<iterator>
#include<functional>
#include<time.h>
#include<iomanip>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define INF 100000000000000000LL

ll diff(ll a,ll b)
{
    return a>b ? a-b : b-a;
}

/*#define COMB_NUM 10001L
ll comb[COMB_NUM][COMB_NUM];
//need init_comb();
void init_comb()
{
    comb[0][0]=1;
    ll i,j;
    for(i=1;i<COMB_NUM;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(j=1;j<i;j++)
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    }
}
*/

#define print(a)      for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
#define print2n(a,n)      for(int i=0;i<=n;i++) cout<<a[i]<<" "; cout<<endl;

void llFromString(const string &s,ll &a,ll &b)
{
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
               
    istringstream buffer(replacedString);
    buffer>>a;
    if(buffer.good())
    {
        buffer>>b;
    }
    else
    {
        b=0;
    }
}


template<class T>
vector<T> split(const std::string &s) {
    
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
    
    vector<T> ret;
    istringstream buffer(replacedString);
    copy(istream_iterator<T>(buffer),
         istream_iterator<T>(), back_inserter(ret));
    return ret;    
}// vector<ll> k = split<ll>(s);


int main()
{
	fstream in,out;
	//in.open("test.in.txt",ios::in); out.open("test.out.txt",ios::out);
	in.open("C-small-attempt2.in",ios::in); out.open("C-small-0.out",ios::out);
	//in.open("C-large.in",ios::in); out.open("C-large-0.out",ios::out);

	istream& input = in;
	ostream& output = out;

	ll case_id,total_case,temp, I,H,K,N,x[3001],y[3001], m[3001],a, b,c, t[3001],p,n;
    
	input>>total_case; 
	for(case_id=1;case_id<=total_case;case_id++)
	{
        input>>N;
        for(I=0;I<N;I++) {
            input>>x[I]>>y[I];
            m[I] = N;
        }
        if(N==1) {
            m[0]=0;
                        goto ANS;
        }
        for(I=0;I<N-1;I++) {
            for(H=I+1;H<N;H++) {
                a=y[H]-y[I];
                b=x[I]-x[H];
                c=x[H]*y[I]-x[I]*y[H];
                p=0;
                n=0;
                for(K=0;K<N;K++) {
                    if(a*x[K]+b*y[K]+c==0) t[K]=0;
                    else if(a*x[K]+b*y[K]+c>0) {
                        t[K]=1;
                        p++;
                    }
                    else  {
                        t[K]=-1;
                        n++;
                    }
                    //cout<<t[K]<<" ";
                }
                //cout<<"p="<<p<<" n="<<n<<endl<<"m:";
                p = min(p,n);
                for(K=0;K<N;K++) {
                    /*if(t[K]>=0) {
                        m[K] = min(m[K], n);
                    }
                    if(t[K]<=0) {
                        m[K] = min(m[K], p);
                    }
                    */
                    if(t[K]==0) m[K] = min(m[K], p);
                  //  cout<<m[K]<<" ";
                }
                //cout<<endl;
            }
        }
        //cout<<endl;
ANS:
		output<<"Case #"<<case_id<<":";
		for(I=0;I<N;I++) output<<endl<<m[I];
		output<<endl;
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}











