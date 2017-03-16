#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
#define PI 2 * acos (0.0)
#define mod 1000000007
using namespace std;

int bs(int *st,int *en,int val,char c) // en = size+1
{
    int k;
    //first element not less than val,else returns last
    if(c=='l') k=lower_bound(st,en,val)-st;
    //first element greater than val,else returns last
    if(c=='u') k=upper_bound(st,en,val)-st;
    return k;
}

int prime[78500];
int sieve() // RETURNS ACTUAL SIZE!!! NOT SIZE+1!!!! REMEMBER WELL!! >_<
{
    int a,b,c;
    c=0; prime[c]=2;
    bool *m=(bool *)calloc(1000006,sizeof(bool));
    for(a=3;a<=1000000;a=a+2)
    {
        if(!m[a])
        {
            prime[++c]=a;
            for(b=2*a;b<=1000000;b=b+a) m[b]=true;
        }
    }
    free(m);
    return c;
}

// inverse mod of i%prime = bigmod(i,prime-2)
ll bigmod(ll i,ll pow)
{
	if(pow<1) return 1;
	if(pow==1) return i%mod;
	ll j;
	if(pow%2)
	{
		j=(i*bigmod(i,pow-1))%mod;
	}
	else
	{
		j=bigmod(i,pow/2);
		j=(j*j)%mod;
	}
	return j;
}

int mx[20];
int my[20];

int grid[20][20];

void clr(int r,int c)
{
    int a,b;
    for(a=0;a<r;a++)
    {
        for(b=0;b<c;b++) grid[a][b]=0;
    }
}

int cal_ans(int r,int c)
{
    int a,b,k,z;
    z=0;
    for(a=0;a<r;a++)
    {
        for(b=0;b<c;b++)
        {
            if(a+1<r)
            {
                if(grid[a][b] && grid[a+1][b]) z++;
            }
            if(b+1<c)
            {
                if(grid[a][b] && grid[a][b+1]) z++;
            }
        }
    }
    return z;
}

int main()
{

    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    /*
    cout << fixed << setprecision(4);
    std::ios::sync_with_stdio(false);

	*/

	int iter,tn;

	int a,b,c,d,e,x,y,z,n,k,r;

	scanf("%d",&tn);

	for(iter=1;iter<=tn;iter++)
	{
	    printf("Case #%d: ",iter);

	    cin>>r>>c>>k;

	    n=r*c;

	    clr(r,c);

	    e=0;
	    for(a=0;a<r;a++)
	    {
	        for(b=0;b<c;b++)
	        {
	            mx[e]=a;
	            my[e]=b;
	            e++;
	        }
	    }

	    z=r*r*c*c;

	    for(a=0;a<(1<<n);a++)
	    {
	        e=0;
	        for(b=0;b<n;b++)
	        {
	            if((a&(1<<b))) e++;
	        }
	        if(e==k)
	        {
	            clr(r,c);
	            for(b=0;b<n;b++)
                {
                    if((a&(1<<b)))
                    {
                        x=mx[b];
                        y=my[b];
                        grid[x][y]=1;
                    }
                }
                z=min(z,cal_ans(r,c));
	        }
	    }
	    cout<<z<<endl;

	}

    return 0;
}
