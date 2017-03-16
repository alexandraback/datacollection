#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::pop_heap;
using std::push_heap;
using std::max;

struct Barber{
    int id, time;
};

struct Heap{
    Barber data[1024];
    int size;
    struct {
        bool operator ()(const Barber& a, const Barber& b){
            return a.time > b.time || a.time == b.time && a.id > b.id;
        }
    }pred;
    Barber top(){
        return data[0];
    }
    void pop(){
        pop_heap(data, data+size, pred);
        --size;
    }
    void push(int id_, int time_){
        data[size].id = id_;
        data[size].time = time_;
        ++size;
        push_heap(data, data+size, pred);
    }
    void init(){
        size = 0;
    }
};

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b);
}

int LCM(int a, int b){
    return a / GCD(a, b) * b;
}

int data[10010];

int main(){
    int T;
    scanf("%d", &T);
    Heap heap;
    for(int _ = 1 ; _ <= T; ++_){
        int n, b;
        scanf("%d%d", &b, &n);
        int lcm = 1;
        heap.init();
        for(int i = 0; i < b; ++i){
            scanf("%d", data+i);
            lcm = LCM(lcm, data[i]);
            heap.push(i, 0);
        }
        int period = 0;
        for(int i = 0; i < b; ++i)
            period += lcm / data[i];
        n = (n-1) % period;
        for(int i = 0; i < n; ++i){
            Barber top = heap.top();
            heap.pop();
            heap.push(top.id, top.time + data[top.id]);
        }
        printf("Case #%d: %d\n", _, heap.top().id+1);
    }
}
