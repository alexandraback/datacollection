#include<bits/stdc++.h>
using namespace std;
int p[100];

int main()
{
    ifstream IF;
    IF.open("input.txt");
    ofstream OF;
    OF.open("output.txt");
    int t,i,n;

    IF >> t;
   
    
   
    for(int tc=1;tc<=t;tc++)
    {
      OF <<"Case #"<<tc<<": ";

      IF>>n;
  int sumx=0;
      for(i=0;i<n;i++)
          {IF>>p[i];
             sumx+=p[i];
           }
      int temp=sumx;

     char maxc;


     if(temp%2==0){
      while(temp>2)
      {
         int maxx=-1;

         for(i=0;i<n;i++)
         {
            if(p[i]>maxx){
              maxc = i+65;
              maxx=p[i];
            }
            

         }

         OF<<maxc;
         p[maxc-65]--;
         temp--;


        maxx=-1;

         for(i=0;i<n;i++)
         {
             if(p[i]>maxx){
              maxc = i+65;
              maxx=p[i];
            }

         }

         OF<<maxc;
         p[maxc-65]--;
         temp--;

         OF<<" ";
      }



      for(i=0;i<n;i++)
      {
        if(p[i])
        {
          OF<<char(i+65);
          p[i]--;
         temp--;
          break;
        }
      }


     for(i=0;i<n;i++)
      {
        if(p[i])
        {
          OF<<char(i+65);
          p[i]--;
         temp--;
          break;
        }
      }
      OF<<endl;
    }
    else
    {


    while(temp>3)
      {
         int maxx=-1;

         for(i=0;i<n;i++)
         {
            if(p[i]>maxx){
              maxc = i+65;
              maxx=p[i];
            }
            

         }

         OF<<maxc;
         p[maxc-65]--;
         temp--;


        maxx=-1;

         for(i=0;i<n;i++)
         {
             if(p[i]>maxx){
              maxc = i+65;
              maxx=p[i];
            }

         }

         OF<<maxc;
         p[maxc-65]--;
         temp--;

         OF<<" ";
      }

    for(i=0;i<n;i++)
      {
        if(p[i])
        {
          OF<<char(i+65)<<" ";
          p[i]--;
         temp--;
          break;
        }
      }






      for(i=0;i<n;i++)
      {
        if(p[i])
        {
          OF<<char(i+65);
          p[i]--;
         temp--;
          break;
        }
      }


     for(i=0;i<n;i++)
      {
        if(p[i])
        {
          OF<<char(i+65);
          p[i]--;
         temp--;
          break;
        }
      }
      OF<<endl;











    }
      




      

    }

    OF.close();
    IF.close();
}
