#include <bits/stdc++.h>
#define MOD 1000000007
#define MINF -1000000000000000000

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,string> ss;

char getchar(int a)
{
    return a+'A';
}

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int t;
    fin >> t;
    int T=t;

    while(t--)
    {
        fout<<"Case #"<<T-t<<": ";
        int n;
        fin>>n;
        int tot=0;
        priority_queue<ii> emps;
        vector<ii> rez;
        for(int ctr1=0;ctr1<n;ctr1++){
            int t;
            fin>>t;
            tot+=t;
            emps.push({t,ctr1});
        }
        while(emps.top().first!=1){
            ii next=emps.top();
            emps.pop();
            ii nnext=emps.top();
            emps.pop();
            if(2*(next.first-1)>tot-1){
                rez.push_back({next.second,next.second});
                emps.push({next.first-2,next.second});
                emps.push(nnext);
                tot-=2;
            }
            else if (2*nnext.first>tot-1)
            {
                rez.push_back({next.second,nnext.second});
                emps.push({next.first-1,next.second});
                emps.push({nnext.first-1,nnext.second});
                tot-=2;
            }
            else{
                rez.push_back({next.second,-1});
                emps.push({next.first-1,next.second});
                emps.push(nnext);
                tot--;
            }
        }
        if(emps.size()%2){
            ii next=emps.top();
            emps.pop();
            rez.push_back({next.second,-1});
        }
        while(!emps.empty()){
            ii next=emps.top();
            emps.pop();
            ii nnext=emps.top();
            emps.pop();
            rez.push_back({next.second,nnext.second});
        }
        for(int ctr1=0;ctr1<rez.size();ctr1++){
            fout<<getchar(rez[ctr1].first);
            if(rez[ctr1].second!=-1)
                fout<<getchar(rez[ctr1].second);
            fout<<" ";
        }
        fout<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
