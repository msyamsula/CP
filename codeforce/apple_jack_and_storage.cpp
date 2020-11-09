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

ll n, q;
vl arr;

void solve(){
    arr.resize(0);
    cin>>n;
    map<ll,ll> vf;
    map<ll, set<ll>> fv;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
        vf[temp]++;
    }

    for(pair<ll, ll> p:vf){
        ll v = p.first, f = p.second;
        fv[f].insert(v);
    }

    cin>>q;
    
    for(ll i=0; i<q; i++){
        char c; cin>>c;
        ll len; cin>>len;
        if (c == '+'){
            n++;
            if (vf.find(len) == vf.end()){
                vf[len]++;
                fv[1].insert(len);
            } else {
                ll cf = vf.at(len);
                fv.at(cf).erase(len);
                if (fv.at(cf).size() == 0) fv.erase(cf);
                vf.at(len)++;
                fv[cf+1].insert(len);
            }
        } else {
            n--;
            ll cf = vf.at(len);
            fv.at(cf).erase(len);
            if (fv.at(cf).size() == 0) fv.erase(cf);
            vf.at(len)--;
            if (vf.at(len) == 0) vf.erase(len);
            if (cf-1 > 0) fv[cf-1].insert(len);
        }

        // for(pair<ll, set<ll>> p : fv){
        //     cout << "" << p.first << ": ";
        //     // cout << "v = ";
        //     for(ll num : p.second){
        //         cout << num << ' ';
        //     }
        //     cout << endl;
        // }

        if (n<8 || fv.rbegin()->first < 4){
            cout << "NO" << endl;
            continue;
        }

        if (fv.rbegin()->first >= 8){
            cout << "YES" << endl;
            continue;
        }

        if (fv.find(4) != fv.end() && fv.at(4).size()>=2){
            cout << "YES" << endl;
            continue;
        }

        if (fv.find(4) != fv.end() && fv.find(2) != fv.end() && fv.at(2).size() >= 2){
            cout << "YES" << endl;
            continue;
        }

        if (fv.find(6) != fv.end() && fv.find(2) != fv.end()){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;

        // auto it = lower_bound(fv.begin(), fv.end(), 5);
        // bool found = 0;
        // for(ll key=5; key<8; key++){
        //     if (fv.find(key) == fv.end()) continue;
        //     ll left = 8-key;
        //     for(ll log : fv.at(key)){
        //         if (fv.at(left).find(log) != fv.at(left).end()){
        //             found = 1;                    
        //         }
        //         if (found) break;
        //     }
        //     if (found) break;
        // }

        // if (found){
        //     cout << "YES" << endl;
        //     continue;
        // } else {
        //     cout << "NO" << endl;
        //     continue;
        // }

    }
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     // cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
