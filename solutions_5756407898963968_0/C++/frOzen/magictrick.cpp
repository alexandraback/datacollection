#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[])
{

   // insert code here...
   ifstream fin;
   ofstream fout;
   int n;
   fin.open("data.in",std::ofstream::in);
   fout.open("data.out",std::ofstream::out);
   fin>>n;
   for (int i=0;i<n;i++)
   {
       int x;
       bool f[20];

       fin>>x;
       for (int j=0;j<4;j++)
           for (int k=0;k<4;k++)
           {
               int y;
               fin>>y;
               if (j+1==x) f[y]=true;
               else f[y]=false;
           }
       fin>>x;
       int count=0,ans=0;

       for (int j=0;j<4;j++)
           for (int k=0;k<4;k++)
           {
               int y;
               fin>>y;
               if (j+1==x) {
                   if (f[y]) {ans=y; count++;}
               }
           }
       if (count==0) fout<<"Case #"<<i+1<<": Volunteer cheated!"<<endl;
       if (count==1) fout<<"Case #"<<i+1<<": "<<ans<<endl;
       if (count>1)  fout<<"Case #"<<i+1<<": Bad magician!"<<endl;
   }

   fin.close();
   fout.close();
   return 0;
}
