#include <iostream>
#include <fstream>

using namespace std;

class Barber {
public:
    int time;
    int timeLeft;

    Barber() : time(0), timeLeft(0) {}
    Barber(int t) : time(t), timeLeft(t) {}
};


int gcd(int a, int b) {
    int temp = 0;
    if(a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    while(b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b)/gcd(a, b);
}


int main() {
    ifstream fin("B-small.in");
    ofstream fout("B-small.out");

    int cases;
    fin >> cases;

    for(int i = 0; i < cases; i++) {
        int barbcount, place;

        fin >> barbcount >> place;



        int barbtimes[1000];
        int currtimes[1000];

        int min = 100000;
        int newmin = 100000;

        int rep = 1;

        for(int j = 0; j < barbcount; j++) {
            int temp;
            fin >> temp;

            barbtimes[j] = temp;
            currtimes[j] = temp;

            if(temp < min) {
                min = temp;
            }

            rep = lcm(rep, temp);
        }

        if(place <= barbcount) {    
            fout << "Case #" << i + 1 << ": " << place << "\n";
            continue;
        }

        else {
            place -= barbcount;
        }


        int custPerRep = 0;

        for(int j = 0; j < barbcount; j++) {
            custPerRep += rep / barbtimes[j];
        }

        place = place % custPerRep;

        int barbnum = barbcount - 1;

        while(place > 0) {
            for(int j = 0; j < barbcount; j++) {
                currtimes[j] -= min;
                if(currtimes[j] == 0) {
                    currtimes[j] = barbtimes[j];
                    place--;
                    if(place == 0) {
                        barbnum = j;
                        break;
                    }
                }

                if(currtimes[j] < newmin) {
                    newmin = currtimes[j];
                }
            }

            min = newmin;
            newmin = 100000;
        }

        fout << "Case #" << i + 1 << ": " << barbnum + 1 << "\n";
    }
    return 0;
}
        
