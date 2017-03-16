#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;



int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N;
        cin >> N;
        
        vector<int> m(N);
        for(int i=0;i<N;i++) cin >> m[i];
        
        int ans1 = 0;
        for(int i=1;i<N;i++){
            ans1+= max(m[i-1]-m[i],0);
        }
        
        int minR = 0;
        for(int i=1;i<N;i++){
            if(m[i-1]-m[i] > minR) minR = m[i-1]-m[i];
        }
        
        int ans2 = 0;
        for(int i=0;i+1<N;i++){
            ans2 += min(m[i], minR);
        }


        
        cout << "Case #" << t << ": " << ans1 << " " << ans2 << endl;    
    }

    return 0;
}