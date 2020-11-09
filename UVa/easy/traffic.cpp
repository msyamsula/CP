#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(int c, string s){
    stringstream ss(s);
    vi cycle;
    int value;
    while(ss>>value){
        cycle.push_back(value);
    }

    // vi::iterator i;
    // iter(cycle, i){
    //     cout << *i << ' ';
    // }
    // cout << endl;

    int group = 1;
    // vi time;
    // int idx = 0;
    value = 0;
    while (value <3600){
        // cout << value << endl;
        f(idx,0,cycle.size(),1){
            value = cycle[idx]*group;
            if (value >3600){
                cout << "Set " << c << " is unable to synch after one hour." << endl;
                return;
            }
            // cout << value << endl;
            vi::iterator i;
            int status = 1;
            iter(cycle, i){
                int min = *i-5;
                int max = (*i)*2;
                if ((value%max) >= min ){
                    status = 0;// group++;
                    // value = value*group;
                    break;
                }
                // green++;
            }

            if (status == 1){
                int minutes = value/60;
                int second = value%60;
                cout << "Set " << c << " synchs again at " << minutes << " minute(s)" << " and " << second << " second(s) after all turning green." << endl;
                return;
            }
        }

        group++;

    }    
}

// void solve(int num){
//     string s;
//     int idx = 1;
//     while(getline(cin, s)){
//         solve(idx, s);
//         idx++;
//     }
// }

int main(){
    string s;
    int tc = 1;
    while(getline(cin, s)){
        solve(tc, s);
        tc++;
    }

    return 0;
}