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
void showV(vl temp){
    for(ll t : temp){
        cout << t << ' ';
    }
    cout << endl;
}

void showVV(vvl temp){
    for (vl t : temp){
        for(ll t1 : t){
            cout << t1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

ll n;
vl arr;
map<ll, ll> mem;

ll makeTeam(ll m){
    ll ans = 0;
    map<ll, ll> memtemp = mem;

    for(pair<ll, ll> p : memtemp){
        ll other = m-p.first;
        if (other == p.first){
            continue;
        }
        if (memtemp.find(other) != memtemp.end() && memtemp.at(other) > 0){
            ll add = min(p.second, memtemp.at(other));
            // p.second -= add;
            memtemp.at(p.first) -= add;
            memtemp.at(other) -= add;
            ans += add;
        }
    }

    if (m%2 == 0){
        ans += memtemp[m/2]/2;
    }

    return ans;
}

void solve(){
    cin>>n;
    arr.resize(0);
    mem.clear();
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    for(ll i=0; i<n; i++){
        mem[arr[i]]++;
    }

    // cout << "mem" << endl;
    // for(pair<ll, ll> p : mem){
    //     cout << p.first << ": " << p.second << endl;
    // }

    // ll i_min = (n-1)/2;
    // ll i_max = ceil(double(n-1)/2);
    // double med = double(arr[i_min]+arr[i_max])/2;
    // med *= 2;
    // cout << "med: " << med << endl;
    // ll med_min = floor(med), med_max = ceil(med);
    // cout << "med_min: " << med_min << endl;
    // cout << "med_max: " << med_max << endl;
    ll ans = 0;
    // cout << makeTeam(6) << endl;
    for(ll i=1; i<=100; i++){
        ans = max(ans, makeTeam(i));
        // cout << "med: " << i << ", will create " << makeTeam(i) << ' ' << makeTeam(6) << " team" << endl;
    }
    // ll ans = max(makeTeam(med_min), makeTeam(med_max));

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
