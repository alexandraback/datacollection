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

long calc_head(long mid, vector<int>& m, int num_barbers) {
    long went = 0L;
    long head = 0L;
    
    for (int i = 0; i < num_barbers; i++) {
        went += mid / m[i];

        if (mid % m[i] != 0) {
            went++;
        }
    }

    head = went + 1;
    
    return head;
}

int solve(vector<int> m, int n) {
    int num_barbers = m.size();
    long left = 0L;
    long right = max<int>(m) * (long) n;
    
    if (n == 1) {
        return 1;
    }
    
    long mid = 0L;
    long head = 0L;
    
    while (right >= left) {
        mid = (left + right) / 2;
        head = calc_head(mid, m, num_barbers);
        
        if (head > n) {
            right = mid - 1;
        }
        else if (head < n) {
            left = mid + 1;
        }
        else {
            break;
        }
    }
    
    if (head > n) {
        mid--;
        head = calc_head(mid, m, num_barbers);
    }
    
    int candidate = 1;
    int min_remaining = 1000000;
    
    if (head < n) {
        for (int i = 0; i < num_barbers; i++) {
            if (mid % m[i] == 0) {
                if (head == n) {
                    return i + 1;
                }
                
                head++;
            }
        }
    }
    
    for (int i = 0; i < num_barbers; i++) {
        int remaining = mid % m[i] == 0 ? 0 : m[i] - (mid % m[i]);
        
        if (remaining < min_remaining) {
            min_remaining = remaining;
            candidate = i + 1;
        }
    }
    
    return candidate;
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
        vector<int> v = read_array<int>(infile);
        int b = v[0], n = v[1];
        
        vector<int> m = read_array<int>(infile);
        
        cout << "Solving Case " << (i + 1) << " ..." << endl;
        int rv = solve(m, n);
        cout << "Solving Case " << (i + 1) << " ... OK" << endl;
        
        outfile << "Case #" << (i + 1) << ": " << rv << endl;
    }
    
    return 0;
}
