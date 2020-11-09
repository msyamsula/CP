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

ll a,b,n,m;

string solve(){
    cin>>a>>b>>n>>m;
    if (a+b <= 0 || n+m > a+b) return "NO";
    
    ll add = max(a,b) - min(a,b);
    
    ll same1 = min(a,b);

    if (add > n) n = 0;
    else n -= add;

    if (m<=same1 && n<=m) return "YES";
    ll same2 = same1-m;
    n -= m;
    if (double(n)/2<=double(same2)) return "YES";
    return "NO";
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        cout << solve() << endl;
    }

    return 0;
}
