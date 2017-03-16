#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long LL;

#define MAX_TIME 100001

LL gcd(LL a, LL b){
    LL r;
    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

LL lcm(LL a, LL b){
    return (a*b)/gcd(a,b);
}

LL group_lcm(const vector<LL>& mvec){
    if(mvec.size() == 0)
        return 0;
    LL ret = mvec[0];
    for(int ii=1; ii < mvec.size(); ++ii){
        ret = lcm(ret, mvec[ii]);
    }
    return ret;
}

void solve(int case_num){
    printf("Case #%d: ", case_num);
    LL B,N;
    vector<LL> Mvec;
    cin >> B >> N;
    LL input;
    for(int ii=0; ii<B; ++ii){
        cin >> input;
        Mvec.push_back(input);
    }

    LL mvec_lcm = group_lcm(Mvec);
    //how many haircuts in one cycle
    LL cycle_haircuts = 0;
    for(auto Mi: Mvec){
        cycle_haircuts += (mvec_lcm / Mi);
    }
    
    //LL quotient = N / cycle_haircuts;
    N = N % cycle_haircuts;
    //cout << N << ", " << cycle_haircuts << endl;

    if(N == 0){
        int min_time = MAX_TIME;
        int min_barber = -1;
        for(int ii = 0; ii < B; ++ii){
            if(Mvec[ii] <= min_time){
                min_time = Mvec[ii];
                min_barber = ii+1;
            }
        }
        cout << min_barber << endl;
        return;
    }
    
    
    
    vector<LL> time_left;
    int num_in_progress = 0;
    LL min_time = MAX_TIME;
    int ret = -1;
    for(int ii=0; ii < B; ++ii){
        time_left.push_back(Mvec[ii]);
        if(time_left[ii] < min_time)
            min_time = time_left[ii];
        num_in_progress++;
        if(num_in_progress == N){
            ret = ii+1;
            cout << ret << endl;
            return;
        }
    }

    LL time_passed;
    while(ret == -1 && num_in_progress < N){
        time_passed = min_time; 
        min_time = MAX_TIME;
        for(int ii=0; ii < B; ++ii){
            time_left[ii] -= time_passed;
            if(time_left[ii] == 0){
                num_in_progress++;
                if(num_in_progress == N)
                    ret = ii+1; 
                time_left[ii] = Mvec[ii];
            }
            if(time_left[ii] < min_time){
                min_time = time_left[ii];
            } 
        }
    }

    cout << ret << endl;
}

int main(){
    int num_cases;
    cin >> num_cases;
    for(int ii=1; ii <= num_cases; ++ii)
        solve(ii);
    return 0;
}
