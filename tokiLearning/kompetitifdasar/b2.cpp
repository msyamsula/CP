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

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}

void solve(){
    ll a,b; cin>>a>>b;
    ll c,d; cin>>c>>d;
    ll num = a*d + b*c;
    ll den = b*d;
    ll fpb = gcd(num,den);
    cout << num/fpb << ' ' << den/fpb << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}