#include<bits/stdc++.h>

using namespace std;

struct word
{
int len;
char ch[100];
int c[100];
}word[100];

int main()
{
    FILE *fp,*fo;
    fp=fopen("input.txt","r");
    fo=fopen("output.txt","w");

    int t,x;
    fscanf(fp,"%d",&t);
    for(x=1;x<=t;x++)
    {
        int n,coun=0,ans;
        char a[150][150];
        fscanf(fp,"%d",&n);

        int i,j,len,p,flag=0;
        for(i=0;i<n;i++)
            fscanf(fp,"%s",a[i]);

            for(i=0;i<n;i++)
            {
                len=strlen(a[i]);
                 int l=0;
                char prev=a[i][0];
                  p=0;
                while(l<len)
                {
                    int count=0;
                  while(prev==a[i][l])
                    {count++; l++; }

                  word[i].ch[p]=prev;
                  word[i].c[p++]=count;

                  prev=a[i][l];
                }

                word[i].len=p;
            }

            /*for(i=0;i<n;i++)
                for(j=0;j<word[i].len;j++)
                    cout<<word[i].ch[j]<<" "<<word[i].c[j]<<endl; */

                   int temp=word[0].len;
            for(i=1;i<n;i++)
             if(temp!=word[i].len)
            {
                //cout<<"hello";
                fprintf(fo,"Case #%d: Fegla Won\n",x);
                flag=1;
              break;
            }




            else
            {
                p=0;
               // temp=word[i].ch[p];
                for(i=0;i<word[0].len;i++)
                {
                    vector<int> v;
                    for(j=1;j<n;j++)
                    {
                        if(word[j].ch[i]==word[j-1].ch[i])
                            v.push_back(word[j].c[i]);

                            else
                            {
                                flag=1;
                                break;
                            }
                    }

                    //if(flag)
                      //  break;



                    v.push_back(word[0].c[i]);
                    sort(v.begin(),v.end());

                    /*for(int k=0;k<n;i++)
                        cout<<v[k]<<" "; */

                       // cout<<endl;


                        ans=v[n/2];

                    for(j=0;j<n;j++)
                        coun+=abs(word[j].c[i]-ans);
                }

                if(!flag)
        fprintf(fo,"Case #%d: %d\n",x,coun);

            else
            fprintf(fo,"Case #%d: Fegla Won\n",x);

            }


    }


    fclose(fp);
    fclose(fo);
    return 0;
}
