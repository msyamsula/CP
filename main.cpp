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

long long binExp(long long a, long long p){
    long long r = 1;
    while(p>0){
        int b = p%2;
        if (b == 1){
            r *= a;
        }
        
        a*=a;
        p>>=1;
    }
    return r;
}



int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // // int tc; cin>>tc;
    // int tc; scanf("%lld", &tc);
    // for(ll i=0; i<tc; i++){
    //     // printf("Case #%lld: ", i+1);
    //     solve();
    // }
    // return 0;
    // initialize(3, 10);
    // show(dp);
    cout << binExp(3, 20) << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int tc; cin>>tc;
    // for(ll i=0; i<tc; i++){
    //     cout << "Case #" << i+1 <<": ";
    //     solve();
    // }

    int *a, *b; a = b = nullptr;
    int val = 8, val2 = 8;
    a = &val;
    b = &val2;
    // *a = 8;
    // *b = 8;
    cout << a << ' ' << b << ' ' << (a == 0) << endl;
    return 0;
}