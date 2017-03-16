#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
class Party{
public:
    int col;
    char leter;
    bool operator <(const Party &p)const
    {
        return col>p.col;
    }
    bool operator ==(const Party &p)const
    {
        return col==p.col;
    }
    Party(int c=0):col(c){}
   // Party(Party& c):col(c.col),leter(c.leter){}
};
int arr[27];
void solve()
{
    vector<Party> way;

    int N;
    cin>>N;
    way.resize(N);
    for(int i=0;i<N;i++){
        cin>>way[i].col;
        way[i].leter=('A'+(char)i);
    }
    sort(way.begin(),way.end());

    while(!way.empty())
    {
        if(way.size()>2)
        {

            if((way[0].col-2)>=way[1].col)
            {
                cout<<way[0].leter<<way[0].leter<<" ";
                way[0].col-=2;
            }
            else if((way[0].col-1)>=way[1].col)
            {
                    cout<<way[0].leter<<" ";
                    way[0].col-=1;
            }else if(way[0].col==way[1].col)
            {
                if(way[1].col==way[2].col)
                {
                    cout<<way[0].leter<<" ";
                    way[0].col-=1;
                }else if(way[1].col>way[2].col)
                {
                    cout<<way[0].leter<<way[1].leter<<" ";
                    way[0].col-=1;
                    way[1].col-=1;
                }

            }else{
                cerr<<"WRONG!!!!\n";
            }

        }else if(way.size()==2){
            if(((way[0].col-2)>=way[1].col)&&(way[0].col>=2))
            {
                cout<<way[0].leter<<way[0].leter<<" ";
                way[0].col-=2;
            }
            else if(((way[0].col-1)>=way[1].col)&&(way[0].col>=1))
            {
                    cout<<way[0].leter<<" ";
                    way[0].col-=1;
            }else if(way[0].col==way[1].col)
            {
                cout<<way[0].leter<<way[1].leter<<" ";
                way[1].col-=1;
                way[0].col-=1;
            }
        }
        else{
            cerr<<"Wrong!\n";
        }
        sort(way.begin(),way.end());
//        remove_if(way.begin(),way.end(),Party(0));
        way.erase(remove( way.begin(), way.end(), Party(0) ), way.end() );
                   /* for(int i=0;i<way.size();i++)
                        cout<<way[i].col<<" ";
                    cout<<endl;
        int k;
        cin>>k;*/
    }


}
int main()
{
   freopen("A-large(1).in","r",stdin);
   freopen("out.txt","w+",stdout);

    int T;
    cin>>T;

    for(int iT=0;iT<T;iT++)
    {
        cout<<"Case #"<<iT+1<<": ";
        solve();
        cout<<"\n";
    }
    return 0;
}
