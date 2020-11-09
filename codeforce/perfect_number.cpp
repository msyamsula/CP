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

ll k;

void solve(){
    cin>>k;
    ll i = 1;
    ll num = 19;
    // cout << num << ' ';
    while(i<k){
        num+=9;
        ll sum = 0;
        ll temp = num;
        while(temp>0){
            sum += temp%10;
            temp/=10;
        }
        if (sum == 10){
            // cout << num << ' ';
            i++;
        }
    }
    // cout << endl;

    cout << num << endl;
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
