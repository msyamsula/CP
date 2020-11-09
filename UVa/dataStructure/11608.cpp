#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

void solve(int start){
    // int start; cin>>start;
    // vi ps(13,0);
    // ps[0] = start;
    // vi required(12, 0);
    long bankSoal = start;
    vl create(12,0);
    for(int i=0; i<12; i++){
        cin>>create[i];
        // ps[i+1] = ps[i] + created;
    }
    vl required(12, 0);
    for(int i=0; i<12; i++){
        cin>>required[i];
    }

    for(int i=0; i<12; i++){
        if (bankSoal >= required[i]){
            bankSoal -= required[i];
            cout << "No problem! :D" << endl;
        } else {
            cout << "No problem. :(" << endl;
        }
        bankSoal += create[i];
    }
}

int main(){
    int n,i=0;
    while(cin>>n){
        if (n<0) break;
        cout << "Case " << i+1 << ":" << endl;
        solve(n);
        i++;
    }

    return 0;
}