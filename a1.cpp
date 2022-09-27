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

struct item {
    string color;
    ll durability, id;
};

bool comp1(item a, item b){
    if (a.color != b.color) return a.color < b.color;
    return a.id < b.id;
}

bool comp2(item a, item b){
    if (a.durability != b.durability) return a.durability < b.durability;
    return a.id < b.id;
}

void solve(){
    ll n; scanf("%lld", &n);
    vector<item> arr;
    for(ll i=0; i<n; i++){
        char s[100]; ll d, id; scanf("%s %lld %lld", &s, &d, &id);
        item ci; ci.color = string(s); ci.durability = d; ci.id = id;
        arr.push_back(ci);
    }

    vector<item> arrColor(arr.begin(), arr.end());
    vector<item> arrDurability(arr.begin(), arr.end());

    sort(arrColor.begin(), arrColor.end(), comp1);
    sort(arrDurability.begin(), arrDurability.end(), comp2);

    ll cnt = 0;
    for(ll i=0; i<n; i++){
        if (arrColor[i].id == arrDurability[i].id) cnt++;
    }

    printf("%lld\n", cnt);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int tc; cin>>tc;
    int tc; scanf("%lld", &tc);
    for(ll i=0; i<tc; i++){
        printf("Case #%lld: ", i+1);
        solve();
    }
    return 0;
}