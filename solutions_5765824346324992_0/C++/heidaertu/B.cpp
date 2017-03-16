//
//  main.cpp
//  A
//
//  Created by wangdongfang on 15/4/18.
//  Copyright (c) 2015年 _. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::priority_queue;
using std::greater;

int N;
int B;

int M[1005];
int used[1005];

typedef pair<int, int> Pair;

//vector<Pair> barber; // time, id;

int barber [1005];

void find(int round) {
    
    int people = 0;
    int avail_num = 0;
  //  int time = 0;
    while (people < N) {
        
        
        
        for (int b = 1; b <= B; b++) {
            if (used[b] == 0) {
                used[b] = 1;
                people++;
              
  //              cout <<"people: " << people << " barber " << b << endl;
                if (people >= N) {
                    cout << "Case #" << round <<": " << b << endl;
                    return;
                }
                barber[b] = M[b];
                
            }
            
        }
        int min_barber_time = -1;
        int min_barber_id = -1;
        for (int b = 1; b <= B; b++) {
            if (min_barber_time == -1 || min_barber_time > barber[b]) {
                min_barber_time = barber[b];
                min_barber_id = b;
            }
        }
        avail_num = 0;
        used[min_barber_id] = 0;
        avail_num ++;
        for (int b = 1; b <= B; b++) {
            barber[b] -= min_barber_time;
            if (barber[b] == 0) {
                used[b] = 0;
                avail_num ++;
          //      time += M[b];
            }
        }
       
      /*  if (avail_num == B) {
            int serve = 0;
            for (int b = 1; b <= B; b++) {
                serve += time / M[b];
            }
            people = people % serve;
            
        }
       */
    }
    
}


int main() {
    
    freopen("/Users/wangdongfang/Myprogram/codejam2015/round1/B/B/sampledata", "r",stdin);
    int T;
    
    cin >> T;
    
    
    for (int i = 0; i < T; i++) {
        cin >> B >> N;
        int time = 1;
        for (int j = 1; j <= B; j++) {
            cin >> M[j];
            used[j] = 0;
            time *= M[j];

            barber[j] = 0;
           }
        int serve = 0;
        for (int b = 1; b <= B; b++) {
            serve += time / M[b];
        }
   //     cout << "N1: " << N <<endl;
        if (N > serve) {
            N = N % serve + serve;
        }
   //     cout << "serve: " << serve << endl;
   //     cout << "N: " << N << endl;
        
        find(i+1);
        
    }
    
    return 0;
}
