/* 
 * File:   main.cpp
 * Author: watcharin
 *
 * Created on April 12, 2015, 3:30 AM
 */

#include <stdio.h>

#include <cstdlib>

#include <algorithm>
#include <fstream>

#include <iomanip>
#include <iostream>

#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Type definitions
typedef long long int ll_int;
typedef vector<int>::const_iterator int_const_itr;

//== Vector operations ==
template<typename T> T max(vector<T>& v) {
    T rv = *max_element(v.begin(), v.end());
    
    return rv;
}

template<typename T> vector<T>& sort_asc(vector<T>& v) {
    sort(v.begin(), v.end());
    
    return v;
}

template<typename T> vector<T>& sort_desc(vector<T>& v) {
    sort(v.begin(), v.end(), greater<T>());
    
    return v;
}
//== Vector operations ==

//== String Manipulation ==
bool equals(string& s, const char *t) {
    return s.compare(string(t)) == 0;
}

bool equals(string& s, string& t) {
    return s.compare(t) == 0;
}

template<typename T> T parse(string& s) {
    istringstream iss(s);
    T x;
    
    iss >> x;
    
    return x;
}

template<typename T> vector<T> parse_array(string& s) {
    vector<T> v;
    istringstream iss(s);
    string item;
    
    while (getline(iss, item, ' ')) {
        v.push_back(parse<T>(item));
    }
    
    return v;
}

string trim(string s) {
    int cnt = 0;
    
    for (string::size_type i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n') {
            cnt++;
        }
        else {
            break;
        }
    }
    
    if (cnt > 0)
        s.erase(0, cnt);
    
    cnt = 0;
    
    for (string::size_type i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n') {
            cnt++;
        }
        else {
            break;
        }
    }
    
    if (cnt > 0)
        s.erase(s.length() - cnt, cnt);
    
    return s;
}
//== String Manipulation ==

//== File reader ==
template<typename T> T read(ifstream& infile) {
    string line;
    getline(infile, line);
    
    return parse<T>(line);
}

template<typename T> vector<T> read_array(ifstream& infile) {
    string line;
    getline(infile, line);
    
    return parse_array<T>(line);
}
//== File reader ==

bool equals_double(double a, double b) {
    return abs(a - b) < 1.0e-5;
}

class Point {
public:
    int x;
    int y;
    
    Point(int x, int y): x(x), y(y) {}
};

vector<int> solve(vector<Point> points) {
    vector<int> rv;
    int n = points.size();
    
    for (int i = 0; i < n; i++) {
        Point base = points[i];
        int min_cut = n;
        
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            
            Point p = points[j];
            int high = 0;
            int low = 0;
            
            if (base.x == p.x) {
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    
                    if (points[k].x < base.x) {
                        high++;
                    }
                    else if (points[k].x > base.x) {
                        low++;
                    }
                }
            }
            else {
                double m = (double) (p.y - base.y) / (p.x - base.x);
                double b = p.y - m * p.x;
                
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    
                    if (!equals_double(points[k].y,  m * points[k].x + b)) {
                        if (points[k].y > m * points[k].x + b) {
                            high++;
                        }
                        else if (points[k].y < m * points[k].x + b) {
                            low++;
                        }
                    }
                }
            }
            
            min_cut = min(min(high, low), min_cut);
        }
        
        rv.push_back(min_cut);
    }
    
    return rv;
}

/*
 * 
 */
int main(int argc, char** argv) {
    char in_file_name[256];
    char out_file_name[256];
    
    sprintf(in_file_name, "%s.in", argv[1]);
    sprintf(out_file_name, "%s.out", argv[1]);
    
    ifstream infile(in_file_name);
    ofstream outfile(out_file_name);
    
    int cases = read<int>(infile);
    
    for (int i = 0; i < cases; i++) {
        int n = read<int>(infile);
        
        vector<Point> points;
        for (int j = 0; j < n; j++) {
            vector<int> v = read_array<int>(infile);
            
            Point p(v[0], v[1]);
            points.push_back(p);
        }
        
        cout << "Solving Case " << (i + 1) << " ..." << endl;
        vector<int> rv = solve(points);
        cout << "Solving Case " << (i + 1) << " ... OK" << endl;
        
        outfile << "Case #" << (i + 1) << ":" << endl;
        for (int_const_itr itr = rv.begin(); itr != rv.end(); itr++) {
            outfile << *itr << endl;
        }
    }
    
    return 0;
}
