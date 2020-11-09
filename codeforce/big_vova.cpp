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

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

ll n;
vl arr;

void solve(){
    arr.resize(0);
    cin>>n;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    vl used(n, 0);
    ll i_max=-1;
    ll biggest=-MAXLL;

    for(ll i=0; i<n; i++){
        if (arr[i]>biggest){
            i_max = i;
            biggest = arr[i];
        }
    }

    used[i_max] = 1;

    vl ans = {biggest};
    ll fpb = biggest;
    for(ll i=1; i<n; i++){
        ll choice=-1;
        ll temp_gcd = -MAXLL;
        for(ll j=0; j<n; j++){
            if (used[j]) continue;
            ll cur_fpb = gcd(arr[j], fpb);
            if ( cur_fpb > temp_gcd){
                temp_gcd = cur_fpb;
                choice = j;
            }
        }
        ans.push_back(arr[choice]);
        used[choice] = 1;
        fpb = gcd(fpb, arr[choice]);
    }

    for(ll i=0; i<ans.size(); i++){
        if (i!=0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
