// #include<bits/stdc++.h>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<stack>
#include<queue>
#include<list>
#include<cstring>
#include<string.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vs> vvs;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define accuracy (10e-6)
#define INF (1ll<<62)
#define PI 3.14159265358979323846

void show(vs arr){
    for(string num : arr){
        cout << num << '\n';
    }
    cout << endl;
}


void show(vl arr){
    for(ll i=0; i<arr.size(); i++){
        if (i!=0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;
}

void show(vvl mat){
    for(vl arr : mat){
        show(arr);
    }
    cout << endl;
}

void show(set<ll> s){
    for(ll num : s){
        cout << num << ' ';
    }
    cout << endl;
}

void show(map<pair<ll, ll>, ll> mp){
    for(pair<pair<ll, ll>, ll> p : mp){
        cout << p.first.first << ' ' << p.first.second << ": " << p.second << endl;
    }
    cout << endl;
}

void inputArray(vl &v){
    ll n = v.size();
    for(ll i=0; i<n; i++){
        scanf("%lld", &v[i]);
    }
}

void inputArray2(ll *ptr, ll n){
    for(ll i=0; i<n; i++){
        cin>>*(ptr+i);
    }
}

vector<long long> primes;
bitset<(long long)1e7> bs;
long long limit = 5e6;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i=2; i<=limit; i++){
        if (bs[i]){
            for(long long j=2*i; j<=limit; j+=i) bs[j] = 0;
            primes.push_back(i);
        }
    }
}

int countPrimes(int n) {
    long long left = 0, right = primes.size()-1;
    while(left < right){
        long long mid = (left + right)/2;
        
        bool y;
        if (primes[mid] < (long long)n){
            left = mid+1;
            y = true;
        } else {
            right = mid;
            y = false;
        }
        
        
        if (left == right) {
            if (y) return mid+1;
            return mid;
        }
    }
    
    return 0;
}

void solve(){
    for (auto x : primes){
        cout << x << endl;
    }

    int a = countPrimes(3);
    cout << a << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int tc; cin>>tc;
    int tc; scanf("%lld", &tc);
    sieve();
    for(ll i=0; i<tc; i++){
        // printf("Case #%lld: ", i+1);
        solve();

        bitset<10> a = bitset<10>(93);
        bitset<10> b = bitset<10>(73);
        cout << bitset<10>(93) << endl;
        cout << bitset<10>(73) << endl;
        cout << bitset<10>(a^b) << endl;
    }
    return 0;
}