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
ll s,d;

ll bs(ll a, ll b){
    if (a>b) return -1;
    ll mid = (a+b)/2;
    ll day = (mid)*s + ((mid-1)*mid)/2 + (mid) + s;
    // cout << a << ' ' << b << ' ' << day << endl;
    if (d<=day && a == b) return mid;
    if (d<=day) return bs(a, mid);
    return bs(mid+1, b);
}
void solve(){
    cout << s + bs(0ll,1000000000ll) << endl;
}

int main(){
    while(cin>>s>>d){
        solve();
    }

    return 0;
}
