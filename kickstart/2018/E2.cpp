#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vector<bitset<100>> person;
set<long long> ban;

void solve(){
    person.resize(0);
    ban.clear();
    int n,m,p; cin>>n>>m>>p;
    for(int i=0; i<n; i++){
        string p; cin>>p;
        bitset<100> bs(p);
        person.push_back(bs);
    }

    for(int i=0; i<m; i++){
        string b; cin>>b;
        bitset<100> bs(b);
        ban.insert(bs.to_ullong());
    }

    // for(bitset<100> a : person){
    //     cout << a << endl;
    // }

    int mincomp = MAXI;
    for(int i=0; i<(1<<p); i++){
        int comp = 0;
        bitset<100> c(i);
        if (ban.find(c.to_ullong()) != ban.end()) continue;
        for(int j=0; j<person.size(); j++){
            bitset<100> a;
            a = c^person[j];
            comp += a.count();
        }
        mincomp = min(mincomp, comp);
    }

    cout << mincomp << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}