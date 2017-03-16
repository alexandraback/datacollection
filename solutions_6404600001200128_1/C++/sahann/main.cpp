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


ifstream cin("/users/naginahas/Downloads/gcjround2/A-Large.in");
ofstream cout("/users/naginahas/Documents/A-Largeout.txt");



int main(){
    int T=0;
    cin >> T;
    for(int t=0;t<T;t++){
        int N;
        cin >> N;
        vector <int> vi;
        for(int i=0;i<N;i++){
            int x;
            cin >> x;
            vi.push_back(x);
        }
        int ans1 = 0;
        for(int i=1;i<vi.size();i++){
            ans1+= max(0,-vi[i]+vi[i-1]);
        }
        vector <int> difs;
        for(int i=1;i<vi.size();i++){
            difs.push_back(max(0,-vi[i]+vi[i-1]));
        }
        int z = *max_element(difs.begin(), difs.end());
        
        int ans2=0;
        for(int i=0;i<N-1;i++){
            ans2+= min(z,vi[i]);
        }
        printf("%d %d ", ans1, ans2);
        cout << "Case #" << t+1 << ": " << ans1 << " "<< ans2 << endl;
    }
    
    
}



