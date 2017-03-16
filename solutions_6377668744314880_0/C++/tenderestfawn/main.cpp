#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include <stdio.h>


using namespace std;
typedef unsigned long long ull;

int Test, N;



typedef double T;
const T EPS = 1e-7;
struct PT {
    T x, y;
    PT() {}
    PT(T x, T y) : x(x), y(y) {}
    
    PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
    PT operator * (double c)     const { return PT(x*c,   y*c  ); }
    PT operator / (double c)     const { return PT(x/c,   y/c  ); }
    bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
    bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) {
    return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
    && fabs(cross(a-b, a-c)) < EPS
    && fabs(cross(c-d, c-a)) < EPS;
}


T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }


void ConvexHull(vector<PT> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

}


int minRemove[20];

int main(){
    
    ifstream ins("C-small-attempt0.in");
    //ifstream ins("A-small.txt");
    ofstream ofs("C-small-out.txt");
    
    ins >> Test;
    
    for (int cse = 1; cse <= Test; cse++){
        
        for (int i = 0; i < 20; i++)
            minRemove[i] = 100;
        
        ins >> N;
        vector<PT> trees;
        for (int i = 0; i < N; i++){
            long long x, y;
            ins >> x >> y;
            trees.push_back( PT(x,y));
        }
        
        
        for (int i = 0; i < (1<<N); i++){
            vector<PT> next;
            
            int numRemoved = 0;
            
            for (int j = 0; j < N; j++){
                if (i & (1 << j) ){
                    next.push_back(trees[j]);
                }
                else
                    numRemoved++;
            }
            
            ConvexHull(next);
            
            for (int j = 0; j < next.size(); j++){
                
                for (int a = 0; a < N; a++){
                    
                    if (LinesCollinear(next[j], next[ (j+1)%next.size()], next[j], trees[a])){
                        minRemove[a] = min( minRemove[a], numRemoved);
                    }
                }
                

            }
        }
        
        ofs << "Case #" << cse << ":" << endl;
        for (int i = 0; i < N; i++){
            ofs << minRemove[i] << endl;
        }
    }
    
    return 0;
}


