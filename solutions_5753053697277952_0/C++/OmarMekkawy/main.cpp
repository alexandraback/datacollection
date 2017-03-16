#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("ii.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    int cases =0;
    while(t--){
        cases++;
        int n;
        cin>>n;
        priority_queue<pair<int,int> > Senators;
        for(int i=0;i<n;i++){
            int T;
            cin>>T;
            Senators.push(make_pair(T,i));
        }
            vector<string> ans;
            while(true){
                if(Senators.size()==2){
                    pair<int,int> cur1=Senators.top();
                    Senators.pop();
                    pair<int,int> cur2=Senators.top();
                    Senators.pop();
                    if(cur1.first>cur2.first){
                        Senators.push(cur1);
                        Senators.push(cur2);
                        goto HERE;
                    }
                    string ansss;
                        ansss.push_back(cur1.second+'A');
                        ansss.push_back(cur2.second+'A');
                        while(cur1.first--)
                            ans.push_back(ansss);
                            break;

                }
                HERE:
                pair<int,int> cur=Senators.top();
                Senators.pop();
                cur.first--;
                string tmp;
                tmp.push_back('A'+cur.second);
                ans.push_back(tmp);
                if(cur.first!=0)Senators.push(cur);
            }
            cout<<"Case #"<<cases<<": ";
            for(int i=0;i<ans.size();i++)cout<<ans[i]<<" \n"[i==ans.size()-1];
        }

    return 0;
}
