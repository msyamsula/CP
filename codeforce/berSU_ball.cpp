#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

ll b,g;
map<ll, ll> boy, girl;

void solve(){
    cin>>b;
    boy.clear();
    for(ll i=0; i<b; i++){
        ll temp; cin>>temp;
        boy[temp]++;
        // boy.push_back(temp);
    }

    cin>>g;
    girl.clear();
    for(ll i=0; i<g; i++){
        ll temp; cin>>temp;
        girl[temp]++;
        // girl.push_back(temp);
    }

    auto it = boy.begin();
    ll ans = 0;
    while(it != boy.end()){
        ll skill = it->first;
        bool zonk = 1;
        for(ll other=skill-1; other<=skill+1; other++){
            if (girl.find(other) == girl.end() || girl.at(other) == 0) continue;
            it->second--;
            girl.at(other)--;
            // cout << "boy " << skill << " paired with girl " << other << endl;
            zonk = 0;
            ans++;
            break;
        }

        if (zonk) it++;
        else {
            if (it->second == 0) it++;
        }
    }

    cout << ans << endl;
}

int main(){
    solve();

    return 0;
}
