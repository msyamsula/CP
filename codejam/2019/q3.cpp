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

vl primes;
ll up = 1000000;
// set<ll> primeschoice;
vl primesarr;
bitset<1000001> bs;
bitset<1000001> used;

void sieve(){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2;i<=up;i++){
        if (bs[i]){
            primes.push_back(i);
            for(ll j=i*i; j<=up; j+=i) bs[j]=0;
        }
    }
}

pair<ll, ll> smallf(ll a){
    ll i=0;
    pair<ll, ll> ans;
    for(ll i=0; i<up; i++){
        if (a%primes[i]==0) return {primes[i], a/primes[i]};
    }

    return {0,0};
}

void solve(){
    used.reset();
    ll n,l; cin>>n>>l;
    primesarr.resize(0); primesarr.assign(l+1,0);
    ll temp; cin>>temp;
    pair<ll, ll> f1 = smallf(temp);
    cin>>temp;
    pair<ll, ll> f2 = smallf(temp);
    if (f1.first == f2.first){
        primesarr[0]=f1.second;
        primesarr[1]=f1.first;
        primesarr[2]=f2.second;
    } else if (f1.first == f2.second) {
        primesarr[0]=f1.second;
        primesarr[1]=f1.first;
        primesarr[2]=f2.first;
    } else if (f1.second == f2.first){
        primesarr[0]=f1.first;
        primesarr[1]=f1.second;
        primesarr[2]=f2.second;
    } else if (f1.second == f2.second){
        primesarr[0]=f1.first;
        primesarr[1]=f1.second;
        primesarr[2]=f2.first;
    }
    used[primesarr[0]] = 1;
    used[primesarr[1]] = 1;
    used[primesarr[2]] = 1;
    ll curr = primesarr[2];
    for(ll i=2; i<l; i++){
        ll t; cin>>t;
        used[t/curr]=1;
        curr = t/curr;
        primesarr[i+1]= t/primesarr[i];
        // primeschoice.insert(primesarr[i+1]);
    }

    map<ll,char> d;
    char c='A';
    for(ll i=0; i<=up; i++){
        if (used[i]){
            d[i]=c;
            c++;
        }
    }

    for(ll i=0; i<=l; i++){
        cout << d[primesarr[i]];
    }
    cout << endl;

    
}

int main(){
    sieve();
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
