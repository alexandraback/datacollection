//In The Name Of GOD
//MME

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<fstream>

using namespace std;
typedef long long ll;
ofstream fout ("1.out");
ifstream fin ("A-large.in");

int main()
{
   int t,tt=0;
   fin >> t;
   while (t)
   {
      t--; tt++;
      int n, ch=0;
      string s[110];
      ll k[110][110];
      memset (k,0,sizeof k);
      fin >> n;
      for (int i=0; i<n; i++)
         fin >> s[i];
      string h;
      char b=s[0][0];
      for (int i=0; i<s[0].size(); i++)
      {
         b=s[0][i];
         h+=b;
         //cerr << "! " << b << endl;
         //cerr << "! " << h << endl;
         while (s[0][i+1]==b && i<s[0].size())
         {
            i++;
         }
      }
      int cnt=0;
      for (int j=0; j<n; j++)
      {
         string f;
         b=s[j][0];
         cnt=0;
         for (int i=0; i<s[j].size(); i++)
         {
            b=s[j][i];
            f+=b;
            while (s[j][i+1]==b && i<s[j].size())
            {
               i++;
               k[j][cnt]++;
            }
            k[j][cnt]++;
            cnt++;
         }
         if (f!=h)
         {
            fout << "Case #" << tt << ": Fegla Won" << endl;
            ch=1;
            break;
         }
      }
      if (ch==1)
         continue;
      ll ans=0;
      for (int i=0; i<cnt; i++)
      {
         ll mn = 1000000000000;
         for (int l=1; l<=100; l++)
         {
            ll cost=0;
            for (int j=0; j<n; j++)
            {
               //cerr << k[j][i] << endl;
               cost+=abs(k[j][i]-l);
            }
            if (cost<mn)
               mn=cost;
         }
         ans+=mn;
      }
      fout << "Case #" << tt << ": " << ans << endl;
   }
}
