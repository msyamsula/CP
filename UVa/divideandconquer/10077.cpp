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

vl a = {0,1,1}, b = {1,1,0};
ll num,den;
string ans;
double target;

void search(ll al, ll bl, ll ar, ll br){
    // cout << num << ' ' << den << endl;
    ll am = al+ar, bm = bl+br;
    // cout << am << ' ' << bm << endl;
    double mid = (double)am/bm;
    // cout << mid << endl;
    if (mid == target) return;
    if (target > mid){
        ans += 'R';
        return search(am,bm,ar,br);
    }
    ans += 'L';
    return search(al,bl,am,bm);
}

void solve(){
    ans = "";
    target = double(num)/den;
    search(a[0], b[0], a[2], b[2]);
    cout << ans << endl;
}

int main(){
    while(cin>>num>>den){
        if (num==1 && den == 1) break;
        solve();
    }

    return 0;
}
