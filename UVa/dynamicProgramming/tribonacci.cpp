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

vl arr;

void solve(){

}

int main(){
    arr.resize(0); arr.assign(2000001, 0);
    arr[0] = arr[1] = arr[2] = arr[3] = 1;
    for(ll i=4; i<=2000000; i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }

    // for(ll num : arr){
    //     cout << num << ' ';
    // }
    // cout << endl;
    cout << arr[2000000] << endl;
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
