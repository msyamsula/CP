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

// vi arr;
vi primes;
bitset<1000007> bs;

void sieve(ll up){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<up; i++){
        if(bs[i]){
            for(ll j=i*i; j<up; j+=i) bs[j]=0;
            primes.push_back(int(i));
        }
    }
}

void solve(){
    int n; cin>>n;
    // arr.resize(0);
    for(int i=0; i<n; i++){
        int temp; cin>>temp;
        cout << primes[temp-1] << endl;
    }
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