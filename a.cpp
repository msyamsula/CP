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

void solve(){
    ll L,N; scanf("%lld %lld\n", &L, &N);
    ll D; char C; 
    scanf("%lld %c", &D, &C);
    // printf("%lld %c\n", D, C);
    ll pos = D%L;
    char ld = C;
    ll counter = D/L;
    // printf("%lld %lld %lld %c\n", D, counter, pos, ld);
    for(ll i=0; i<N-1; i++){
        scanf("%lld %c", &D, &C);
        // printf("%lld %c\n", D, C);
        ll delta;
        ll add;
        if (C == 'C'){
            delta = (pos+(D%L)) >= L ? 1 : 0;
            pos = (pos+D)%L;
            add = (D/L) + delta;
            if (ld != C){
                add = max(0ll, add-1);
            }
            if ((D/L) + delta >= 1) ld = C;
        } else if (C == 'A') {
            delta = (pos-(D%L)) <= 0 ? 1 : 0;
            pos = (pos-D)%L;
            pos = (pos<0) ? pos+L : pos;
            add = (D/L) + delta;
            if (ld != C){
                add = max(0ll, add-1);
            }
            if ((D/L) + delta >= 1){
                // printf("goes here\n");
                ld = C;
            }
            // printf("add: %lld\n", add);
        }

        counter += add;

        // if (ld == C){
        // } else {
        //     add = max(0ll, add-1);
        //     counter += add;
        // }

        // if (add > 0) ld = C;
        // printf("%lld %lld %lld %c\n", D, counter, pos, ld);

    }

    printf("%lld\n", counter);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; scanf("%lld", &tc);
    for(ll i=0; i<tc; i++){
        printf("Case #%lld: ", i+1);
        solve();
    }

    // ll a = (-1)%5;
    // printf("%lld\n",a);
    return 0;
}