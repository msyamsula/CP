#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

void solve(){
    int n,p; cin>>n>>p;
    long total = pow(2,n);
    // vs prefix;
    map<string, int> mem;
    for(int i=0; i<p; i++){
        string temp; cin>>temp;
        mem[temp] += 1;
    }

    map<string, int> cleanMem;
    for(pair<string, int> temp : mem){
        string key = temp.first; int value = temp.second;
        for(int i=1; i<=key.size(); i++){
            string minprefix = key.substr(0,i);
            if (mem.find(minprefix) != mem.end()){
                cleanMem[minprefix] += 1;
                break;
            }
        }
    }

    for(pair<string, int> temp : cleanMem){
        // cout << temp.first << ' ' << temp.second << endl;
        long avail = long(n) - long(temp.first.size());
        long minus = long(pow(2,avail));
        total -= minus;
    }

    cout << total << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}