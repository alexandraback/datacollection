#include <bits/stdc++.h>

using namespace std;

int t;
int sum, n;
set<pair<int, char> >s;
set<pair<int, char> >::iterator it;
int num[10000];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin>>t;
    for(int o = 1; o <= t; ++o){

        cin>>n;
        sum = 0;
        for(int i = 0; i < n; ++i){
            cin>>num[i];
            sum += num[i];
            s.insert(make_pair(num[i], (char)(i + 'A')));
        }
        cout<<"Case #"<<o<<": ";
        while(!s.empty()){
            it = s.end();
            it--;
            pair<int, char> temp1 = *it;
            it--;
            pair<int, char> temp2 = *it;
            //cout<<temp1.first<<" "<<temp1.second<<endl;
            //cout<<temp2.first<<" "<<temp2.second<<endl;
            if(s.size() == 2){
                if(temp1.first == 1){
                    cout<<temp1.second<<temp2.second<<endl;
                    break;
                }
            }
            if(temp1.first - 1 >= (sum + 1) / 2){
                cout<<temp1.second<<temp1.second<<" ";
                it = s.end();
                it--;
                s.erase(it);
                s.insert(make_pair(temp1.first - 2, temp1.second));
                sum -= 2;
            }
            else if(s.size() == 3 && sum == 3){
                cout<<temp1.second<<" ";
                it = s.end();
                it--;
                s.erase(it);
                sum --;
            }else{
                sum -= 2;
                //cout<<"xa"<<endl;
                cout<<temp1.second<<temp2.second<<" ";
                it = s.end();
                it--;
                s.erase(it);
                it = s.end();
                it--;
                s.erase(it);
                if(temp1.first - 1 > 0)
                    s.insert(make_pair(temp1.first - 1, temp1.second));
                if(temp2.first - 1 > 0)
                    s.insert(make_pair(temp2.first - 1, temp2.second));
            }
        }

        s.clear();
    }


    return 0;
}
