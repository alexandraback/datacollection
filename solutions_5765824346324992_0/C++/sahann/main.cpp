#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
//#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <fstream>
#include <cstdio>

using namespace std;


ifstream cin("/users/naginahas/Downloads/gcjround2/B-small-attempt0.in");
ofstream cout("/users/naginahas/Documents/Bsmall.txt");

int main(){
    int T=0;
    cin >> T;
    for(int t=0;t<T;t++){
        long long B,N;
        cin >> B >> N;
        vector <long long> vi;
        for(int i=0;i<B;i++){
            long long x;
            cin >> x;
            vi.push_back(x);
            
        }
        long long lb = -1;
        long long ub = 100000LL * 1000*1000*1000+100;
        while(ub-lb>1){
            long long mid = (ub+lb)/2;
            long long total = 0;
            for(int i=0;i<vi.size();i++){
                total+= (mid/vi[i])+1;
            }
            if(total>=N) ub = mid;
            else lb=mid;
        }
        printf("Ub = %lld\n", ub);
        long long sb = 0;
        
        for(int i=0;i<vi.size();i++){
            if(ub%vi[i] ==0){
                sb+=ub/vi[i];
            }
            else{
                sb+= ub/vi[i]+1;
            }
        }
        printf("sb = %d\n", sb);
        long long z = N-sb;
        long long k=0;
        int ans =-1;
        for(int i=0;i<vi.size();i++){
            if(ub%vi[i]==0){
                k++;
                if(k==z){
                    ans = i+1;
                    break;
                }
            }
        }
        cout << "Case #" << t+1 << ": "<< ans << endl;
    }
    
    
}





