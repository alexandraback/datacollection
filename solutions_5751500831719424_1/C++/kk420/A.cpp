#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MaxInt=numeric_limits<int>::max();
typedef vector<int> VI;
typedef vector<string> VS;
#define For(i,a,n) for (int i=a; i<n; ++i)
#define Fori(n) For(i,0,n)

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    int n, poz[100]={0}, wyn=0;
    string s[100];
    cin>>n;
    Fori(n)
      cin>>s[i];
    for (; ; )
    {
      char znak=s[0][poz[0]];
      int ile[100]={0};
      Fori(n)
      {
        while (poz[i]<s[i].length() && s[i][poz[i]]==znak)
        {
          ++ile[i];
          ++poz[i];
        }
        if (ile[i]==0)
        {
          wyn=-1;
          break;
        }
      }
      if (wyn==-1)
        break;
      int mi=10000000;
      for (int l=1; l<=100; ++l)
      {
        int li=0;
        Fori(n)
          li+=abs(l-ile[i]);
        mi=min(mi, li);
      }
      wyn+=mi;
      int lk=0;
      Fori(n)
        if (poz[i]==s[i].length())
          ++lk;
      if (lk==n)
        break;
      if (lk)
      {
        wyn=-1;
        break;
      }
    }
  
  
    cout<<"Case #"<<ca<<": ";
    if (wyn==-1) cout<<"Fegla Won\n";
    else cout<<wyn<<endl;
  }


  return 0;
}
