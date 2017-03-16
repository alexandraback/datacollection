//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int siatka(int n, int m)
{
    return ((n+1)/2)*((m+1)/2)+(n/2)*(m/2);
}
int rogi(int n, int m)
{
    return (n%2 == 0)+(m%2 == 0)+( (n+m)%2 == 1);
}
int brzegi(int n, int m)
{
    return n/2+m/2+(n%2==0?(m+1)/2:m/2)+(m%2==0?(n+1)/2:n/2)-rogi(n,m)*2;
}
int srodek(int n, int m)
{
    return n*m-siatka(n,m)-brzegi(n,m);
}

int algorytm(int n, int m, int k)
{
    int wyn = 0;
    
    if(n > m) swap(n,m);

    if(n == 1 && m == 1) wyn = 0;
    else if(n == 1)
    {
        k -= (m+1)/2;
        if(k > 0 && m%2 == 0)
        {
            wyn++;
            k--;
        }
        if(k > 0) wyn += k*2;
    }
    else if(n == 3 && m == 3 && k == 8) wyn = 8;
    else
    {
        //cerr << "Siatka: " << siatka(n,m) << " Brzegi: " << brzegi(n,m) << " Rogi: " << rogi(n,m) << endl;
        k -= siatka(n,m);
        if(k > 0) wyn += min(k,rogi(n,m))*2;
        k -= rogi(n,m);
        if(k > 0) wyn += min(k,brzegi(n,m))*3;
        k -= brzegi(n,m);
        if(k > 0) wyn += k*4;
    }
    
    return wyn;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int ti = 1;ti <= t;ti++)
    {
        int n,m,k;
        scanf("%d%d%d", &n, &m, &k);
        
        if(n > m) swap(n,m);
        
        int sciany = algorytm(n,m,n*m);
        
        int wyn = algorytm(n,m,k);
        //cerr << sciany << algorytm(n,m,n*m-k)
        int wyn2 = sciany-((n*m-k)*4-algorytm(n,m,n*m-k));
        
        int Kwyn = wyn;
        if(wyn2 > 0) Kwyn = min(Kwyn, wyn2);
        
        printf("Case #%d: %d\n", ti, Kwyn);
    }
    return 0;
}
