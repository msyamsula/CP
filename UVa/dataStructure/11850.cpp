#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

void solve(int n){
    set<int> gs;
    for(int i=0; i<n; i++){
        int station; cin>>station;
        gs.insert(station);
    }

    set<int>::iterator it;
    int prev = *gs.begin();
    for(it = gs.begin(); it != gs.end(); it++){
        // cout << prev << ' ' << *it << endl;
        if (*it - prev > 200){
            cout << "IMPOSSIBLE" << endl; return;
        }
        it++;
        // cout << *it << endl;
        if (it == gs.end()){
            it--;
            // cout << *it << endl;
            if (2*(1421-*it) > 200 ){
                cout << "IMPOSSIBLE" << endl; return;
            } else {
                cout << "POSSIBLE" << endl; return;
            }
        }
        it--;
        prev = *it;
    }

    // for(int loc: gs){
    //     int idx = distance(gs.begin(), gs.find(loc));
    //     if (idx == gs.size()-1) break;
    //     int next = *(gs.begin()+idx+1;
    //     // cout << d << endl;
    //     // cout << (gs.find(loc)-gs.begin()) << endl;
    //     if (gs.find(next) == gs.end() && idx != gs.size()-1){
    //         cout << "IMPOSSIBLE" << endl; return;
    //     }
    // }

    cout << "POSSIBLE" << endl;
}

int main(){
    int n;
    while(cin>>n){
        if (n==0) break;
        // cout << "Case #" << i+1 << ": ";
        solve(n);
    }

    return 0;
}