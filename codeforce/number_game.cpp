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

ll n;
vl primes;
bitset<1000000007> bs;

void sieve(ll up){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<=up; i++){
        if (bs[i]){
            primes.push_back(i);
            for(ll j=i*i; j<=up; j+=i) bs[j]=0;
        }
    }
}

map<ll, ll> primeFactor(ll num){
    map<ll, ll> ans;
    ll idx = 0;
    while(num>1){
        if (num%primes[idx] == 0){
            num /= primes[idx];
            ans[primes[idx]]++;
        } else {
            idx++;
        }
    }

    return ans;
}

void solve(){
    cin>>n;
    if (n==1){
        cout << "FastestFinger" << endl;
        return;
    }
    if (n==2){
        cout << "Ashishgup" << endl;
        return;
    }
    if (n&1){
        cout << "Ashishgup" << endl;
        return;
    }
    map<ll, ll> pf = primeFactor(n);
    // for(pair<ll, ll> p : pf){
    //     cout << p.first << ": " << p.second << endl;
    // }
    // cout << endl;
    if (pf[2]>1){
        if (pf.size()==1){
            cout << "FastestFinger" << endl;
            return;
        } else {
            cout << "Ashishgup" << endl;
            return;
        }
    } else {
        ll prime_tot = 0;
        for(pair<ll, ll> p : pf){
            if (p.first == 2) continue;
            prime_tot += p.second;
        }
        if (prime_tot%2 == 0){
            cout << "Ashishgup" << endl;
            return;
        } else {
            cout << "FastestFinger" << endl;
            return;   
        }
    }
}

int main(){
    sieve(10000000);
    // for(ll num : primes){
    //     cout << num << endl;
    // }
    // cout << endl;
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
