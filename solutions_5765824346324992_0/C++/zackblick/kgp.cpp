/*krypto.....................................jagsxi....!! */
#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
vector<int> v;

int f1(int* a)
{
 char c=0;
 while (c<33) 
 c=getchar_unlocked();
 *a=0;
 while (c>33)
{
    *a=*a*10+c-'0';
    c=getchar_unlocked();
}
return 0;
}

long long int f2(long long int* a)
{
 char c=0;
 while (c<33) 
 c=getchar_unlocked();
 *a=0;
 while (c>33)
{
    *a=*a*10+c-'0';
    c=getchar_unlocked();
}
return 0;
}

int main() {
	