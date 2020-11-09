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

vi primes;
bitset<1000007> bs;

void sieve(ll up){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<=up; i++){
        if (bs[i]){
            for(ll j=i*i; j<=up; j+=i) bs[j]=0;
            primes.push_back(int(i));
        }
    }
}

map<int, int> primeF(int num){
    map<int, int> ans;
    int pi = 0;
    while(num!=1){
        if(num%primes[pi] == 0){
            num /= primes[pi];
            ans[primes[pi]]++;
        } else {
            pi++;
        }
    }

    return ans;
}

void solve(){
    int n; cin>>n;
    map<int, int> kpk;
    for(int i=0; i<n; i++){
        int num; cin>>num;
        map<int, int> pF;
        pF = primeF(num);
        for(pair<int, int> a : pF){
            int key = a.first;
            // cout << key << ' ' << a.second << endl;
            kpk[key] = max(kpk[key], pF[key]);
        }
    }

    ll ans = 1;
    for(pair<int, int> a : kpk){
        ans *= pow(a.first,a.second);
    }

    cout << ans << endl;
}

int main(){
    sieve(1000000);
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}