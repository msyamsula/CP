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

ll n,k,m;
// vvl alice,bob;
vvl book;

bool comp(vl a, vl b){
    if ( (a[1]+a[2]) != (b[1]+b[2]) ) return a[1]+a[2]>b[1]+b[2];
    return a[0]<b[0];
}

void solve(){
    cin>>n>>m>>k;
    // alice.resize(0); bob.resize(0);
    vl both;
    vl alice, bob, reserve;
    for(ll i=0; i<n; i++){
        ll t,a,b; cin>>t>>a>>b;
        if (a && b){
            both.push_back(t);
        } else if (a){
            alice.push_back(t);
        } else if (b){
            bob.push_back(t);
        } else {
            reserve.push_back(t);
        }
    }

    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    // cout << "both" << endl;
    // for(ll num : both){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // cout << "alice" << endl;
    // for(ll num : alice){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // cout << "bob" << endl;
    // for(ll num : bob){
    //     cout << num << ' ';
    // }
    // cout << endl;


    vl ps_both(both.size()+1);
    vl ps_alice(alice.size()+1);
    vl ps_bob(bob.size()+1);

    for(ll i=0; i<both.size(); i++){
        ps_both[i+1] += ps_both[i] + both[i];
    }

    for(ll i=0; i<alice.size(); i++){
        ps_alice[i+1] += ps_alice[i] + alice[i];
    }

    for(ll i=0; i<bob.size(); i++){
        ps_bob[i+1] += ps_bob[i] + bob[i];
    }

    ll time  = MAXLL;
    ll take_both = 0, take_left = 0;
    for(ll i=0; i<=both.size(); i++){
        ll cur_time = ps_both[i];
        ll left = k-i;
        if (left < 0) continue;
        if (left > alice.size()) continue;
        cur_time += ps_alice[left];
        if (left > bob.size()) continue;
        cur_time += ps_bob[left];
        if (cur_time < time){
            time = min(time, cur_time);
            take_both = i;
            take_left = k-i;
        }
    }

    if (time == MAXLL){
        cout << -1 << endl;
        return;
    }

    // cout << take_both << ' ' << take_left << endl;
    ll total_set = take_both + 2*take_left;
    if (total_set > m){
        cout << -1 << endl;
        return;
    }

    if (total_set == m){
        cout << time << endl;
        return;
    }


    for(ll i=take_both; i<both.size(); i++){
        reserve.push_back(both[i]);
    }

    for(ll i=take_left; i<alice.size(); i++){
        reserve.push_back(alice[i]);
    }

    for(ll i=take_left; i<bob.size(); i++){
        reserve.push_back(bob[i]);
    }

    if (reserve.size() < m-total_set){
        cout << -1 << endl;
        return;
    }

    sort(reserve.begin(), reserve.end());

    for(ll i=0; i<m-total_set; i++){
        time += reserve[i];
    }

    cout << time << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     // cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
