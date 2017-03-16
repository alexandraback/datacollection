#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



int main()
{
    std::ios::sync_with_stdio(false);
    int t,T;
    cin >> T;
    for (t=0; t<T; t++)
    {
        int i,N,sum=0;
        cin>>N;
        char carr[3];
        vector<pair<int,int> > vi(N);
        for (i=0; i<N; i++) {
            cin>>vi[i].first;
            vi[i].second = i;
            sum += vi[i].first;
        }
        string ans = "";
        while (sum>0) {
            sort(vi.rbegin(),vi.rend());
            
            if ((vi[0].first == vi[1].first)&&(sum!=3)) {
                carr[0]='A' + vi[0].second;
                carr[1]='A' + vi[1].second;
                carr[2]= '\0';
                sum -= 2;
                vi[0].first--;
                vi[1].first--;
            }
            else
            {
            
                carr[0]='A' + vi[0].second;
                carr[1]= '\0';
                sum -= 1;
                vi[0].first--;
            }
            ans += string(carr)+" ";
        }
        cout <<"Case #"<<t+1<<": " <<ans<<endl;

        
        
    }
    return 0;
}

