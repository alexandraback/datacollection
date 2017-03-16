#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\A-small-attempt1.in","r",stdin)
#define WRITE freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 200009



using namespace std;
///******* Template ********///


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

///***** Template ends here *****///
///********************* Code starts here ****************************

#define YES printf("GABRIEL\n")
#define NO printf("RICHARD\n")

int arr[1009];
int tmp[1009];


int main()
{
    READ;
    WRITE;
    int i, j;
    int num;
    int t,m,n,cases = 1;
    scanf("%d", &t);
    int x;
    string str;
    while(t--)
    {
        cin>>n;
        for(i = 0; i < n; i++){
            cin>>arr[i];
            tmp[i] = arr[i];
        }
        int first = 0, second = 0;
        for(i = 0; i < n - 1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                first += arr[i] - arr[i + 1];
                arr[i] = arr[i + 1];
            }
        }

        for(i = 0; i < n - 2; i++)
        {
                second += tmp[i];

        }
        if(tmp[n - 2] > tmp[n - 1])
        second += abs(tmp[n - 2] - tmp[n - 1]);
        printf("Case #%d: %d %d\n", cases++, first, second);

    }



    return 0;
}

/*


4 left
2 0 2 4
2 0 4 2
2 2 4 8
2 2 4 4

10 up
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0




*/
