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

bitset<10000007> bs;
vl primes;

void sieve(ll up){
    primes.resize(0);
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<=up; i++){
        if (bs[i]){
            for(ll j=i*i; j<=up; j+=i) bs[j]=0;
            primes.push_back(i);
        }
    }
}

ll n;

void solve(){
    cin>>n;
    sieve(10000000);
    set<ll> tprimes;
    for(ll i=0; i<primes.size(); i++){
        if (primes[i]*primes[i] > 1000000000000) break;
        tprimes.insert(primes[i]*primes[i]);
    }

    // for(ll num : tprimes){
    //     cout << num << endl;
    // }

    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        string ans;
        if (tprimes.find(temp) != tprimes.end()) ans = "YES";
        else ans = "NO";
        cout << ans << endl;
    }
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
