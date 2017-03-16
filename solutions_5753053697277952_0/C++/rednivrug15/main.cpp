#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define N 223456

long long power( long long a,long long b)
{
    long long ret=1;
    while( b ) {
            if( b%2==1 )
                ret = ( ret*a )%mod;
            a = ( a*a )%mod;
            b /= 2;
    }
    return ret;
}

long long gcd( long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for( int tt=1; tt<=t; tt++ )
    {
        printf("Case #%d: ",tt);
        int n;
        scanf("%d",&n);

        vector < pair < int , char > > persons(n);

        for( int i=0; i<n; i++ )
        {
            scanf("%d",&persons[i].first);
            persons[i].second='A'+i;
        }
        sort( persons.begin(), persons.end());
        reverse(persons.begin(),persons.end());

        for( int i=1; i<n; i+=2 ) {
            while( persons[i].first!=persons[i-1].first )
            {
                persons[i-1].first--;
                cout<<persons[i-1].second<<" ";
            }
        }

        if( n%2==1 ) {
            while( persons[n-1].first!=0 )
            {
                persons[n-1].first--;
                cout<<persons[n-1].second<<" ";
            }
        }

        for( int i=1; i<n; i+=2 )
        {
            while( persons[i].first!=0 )
            {
                persons[i].first--;
                cout<<persons[i].second<<persons[i-1].second<<" ";
            }
        }
        printf("\n");
    }
    return 0;
}
