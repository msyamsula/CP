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

ll a,b;
bitset<1000000007> bs;
vl primes;

void sieve(ll up){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<=up; i++){
        if (bs[i]){
            for( ll j=i*i; j<=up; j+=i){
                bs[j]=0;
            }
            primes.push_back(i);
        }
    }
}

bool is_prime(ll num){
    if (num <= 10000000) return bs[num];
    for(ll prime : primes){
        if (num%prime == 0) return 0;
    }
    return 1;
}

void solve(){
    cin>>a>>b;
    // cout << a << ' ' << b <<endl;
    ll temp = a;
    bitset<1000007> local_bs;
    local_bs.set();
    while(!is_prime(temp)){
        bs[temp-a]=0;
        temp++;
    }

    for(ll i=temp; i<=b; i++){
        if(bs[i-a]){
            for(ll j=i*i; j<=b; j+=i) local_bs[j-a]=0;
            cout << i << endl;
        }
    }

    // for(ll i=a; i<=b; i++){
    //     if(local_bs[i-a]){
    //         cout << i << endl;
    //     }
    // }
}

int main(){
    sieve(10000000);
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if (i!=0) cout << endl;
        solve();
    }

    return 0;
}
