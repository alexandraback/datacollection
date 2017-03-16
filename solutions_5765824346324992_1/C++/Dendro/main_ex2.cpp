#include <iostream>
#include <random>
#include <time.h>
#include <limits>
#include <vector>
#include <sstream>
using namespace std;


class Instance{
public:
  void read();
  void write();

  void compute();
private:
 long long _n;
 vector< long long > barbers;
 vector< long long > num;
 vector< vector <long long > > time_per_barber;
 vector<long long> res;
};


void Instance::read()
{
  cin >> _n;

  for (long long i = 0; i < _n; ++i) {
    long long ba;

    string s;
    long long n;
    cin >> ba;
    cin >> s; // ATTENTION here!
    n = stoll(s);

//cout << " new " << n << endl;

    barbers.push_back(ba);
    num.push_back(n);

    vector<long long> tpb;
    time_per_barber.push_back(tpb);
    for (long long j = 0; j < ba; ++j) {
      long long m;
      cin >> m;
      time_per_barber[i].push_back(m);
    }
  }
}


void Instance::write()
{
   for (long long i = 0; i < _n; ++i) {
     cout << "Case #" << i+1 << ": " << res[i] << endl;
   }

}




void Instance::compute()
{
  for (long long i = 0; i < _n; ++i) {
    long long n = num[i];
    long long bar = barbers[i];
    vector<long long> tpb = time_per_barber[i];

    vector<long long> num_cust_served;
    vector< vector<long long> > remaining;

// Init array
    vector<long long> remainder;
    long long num_served = 0;
    for (long long j = 0; j < bar; ++j){
      long long t = 1;
      if (tpb[j] == 1 ) {
        num_served ++;
        t = 0;
      }
      remainder.push_back(t);  // soviele sind noch frei zu der Zeit
    }
    remaining.push_back(remainder);
    num_cust_served.push_back(num_served);
//cout << "num served first round " << num_served << endl;

    long long last = 0;

    while (num_cust_served[last] < n) {
      long long num_served = num_cust_served[last] *2;
      vector<long long> old_rem = remaining[last];
      vector<long long> new_rem;
      for (long long j = 0; j < bar; ++ j) {
         long long new_r = old_rem[j] * 2;
         while (new_r >= tpb[j]) { // Zusätzlicher kann bediernt werden...
           new_r -= tpb[j];
           num_served +=1;
         }
         new_rem.push_back(new_r);
      }
      remaining.push_back(new_rem);
      num_cust_served.push_back(num_served);
      last++;
    }
//cout << "Computed last" << last << endl;

    vector<long long> rem;
    for (long long j = 0; j < bar; ++j) {
      rem.push_back(0);
    }


    long long num_cust = 0;
#if 1
    while(num_cust < n - 4*bar) {
     long long r = n - num_cust - 4*bar;
     long long best = 0;
     for (long long j = 0; j < remaining.size(); ++j ){
        if (num_cust_served[j] <= r) {
          best = j;
        }
     }

     num_cust += num_cust_served[best];
     for (long long j = 0; j < bar; ++j) {
       rem[j] += remaining[best][j];
       while (rem[j] >= tpb[j]) {
         rem[j] -= tpb[j];
         num_cust ++;
       }
     }

    }
#endif

    // Add customer that have started ...
/*    for (long long j = 0; j < bar; ++j) {
      if (rem[j] > 0) {
        num_cust++;
      }
    }
*/


// Fill in the rest
    long long mini = -99999999;
    long long pos = 0;

    //cout << "n " << n << " num_cust " << num_cust << endl;

    for (long long l = 0; l< n-num_cust; ++l) {
      // Find first free cust;
      mini = -99999999;
      pos = 0;

      for (long long j = 0; j < bar; ++j) {
        if (rem[j] > mini) {
          mini = rem[j];
          pos = j;
        }
      }
      rem[pos] -= tpb[pos];
    }

    // Hopefully j is the correct result!
    res.push_back(pos+1);
  }

}


int main(int argc, char** argv){
  Instance I;
  I.read();
  I.compute();
  I.write();
}
