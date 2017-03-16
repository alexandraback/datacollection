#include<cstdio>
#include<iostream>

using namespace std;
int vals[26];
int n;
bool maj(int k)
{
  int i;
  int tot = 0;
  for(i=0;i<n;i++)
  {
    tot+=vals[i];

  }
  if(2*vals[k]>tot)
    return true;
  return false;
}
int main()
{
    int t;
    cin>>t;

    int count = 1;
    while(t--)
    {

      cin>>n;


      int i;
      for(i=0;i<26;i++)
        vals[i] = 0;

      for(i=0;i<n;i++)
      {
        int r;
        cin>>r;
        vals[i] = r;
      }

      char v1,v2;
      int max1 = 0, max2 = 0;
      int pos1 = -1, pos2 = -1;
      cout<<"Case #"<<count<<": ";
      count++;
      bool fd;
      do{
        fd = false;
        for(pos1=0;pos1<n;pos1++)
        {
          for(pos2=0;pos2<n;pos2++)
          {
              vals[pos1]--;
              vals[pos2]--;
              bool valid = true;
              for(i=0;i<n;i++)
              {
                if(maj(i))
                  valid = false;
              }
              if(!valid || (vals[pos1] < 0) || (vals[pos2] < 0))
              {
                vals[pos1]++;
                vals[pos2]++;
              }
              else
              {  fd = true;
                  break;
              }

          }
          if(fd)
          break;
        }
        if(fd){
         cout<<(char)(pos1+'A');
          cout<<(char)(pos2+'A');
          cout<<" ";
        }
          else{
            int maxi = 0;
            int pos = -1;
            for(i=0;i<n;i++)
            {
              if(vals[i]>maxi)
              {
                maxi = vals[i];
                pos = i;
              }
            }
            if(pos!=-1)
            {
              cout<<(char)(pos + 'A')<<" ";
              vals[pos]--;
              fd = true;
            }
          }

    }
    while(fd);
    cout<<endl;
    }


}
