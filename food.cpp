#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef pair<int,int> ii;
typedef map<ii,int> miii;


int dp(int tot, int idx, vii dist_price, int k, int n, miii &mem, int wp){
    // cout << wp << endl;
    ii key = make_pair(tot,idx);
    if (mem.find(key) != mem.end()){
        // cout << "memo" << endl;
        return mem.at(key);
    }
    // cout << "calculation" << endl;

    int position = dist_price[idx].first, price = dist_price[idx].second;
    if (tot == k) return mem[key] = 0;
    if (idx == n) return mem[key] = 1<<30;
    if (wp == idx) return mem[key] = dp(tot,idx+1,dist_price,k,n,mem,wp);


    
    int pass = dp(tot,idx+1,dist_price,k,n,mem,wp);
    int fs = abs(position-dist_price[wp].first)+price+dp(tot+1,idx+1,dist_price,k,n,mem,wp);
    return mem[key] = min(pass,fs);
}

void solve(int tc){
    int k, n;
    cin>>k>>n;
    vii dist_price(n);
    for(int i=0; i<n;i++){
        cin>>dist_price[i].first;
    }

    for(int i=0; i<n;i++){
        cin>>dist_price[i].second;
    }

    // sort(dist_price.begin(), dist_price.end());

    vi idx_pos;
    int ans = 1<<30;
    int min_idx = 0;
    for (int i=0; i<n; i++){
        miii mem;
        int temp = min(ans, dist_price[i].second+dp(0,0,dist_price,k,n,mem,i));
        if (temp < ans){
            min_idx = i;
            ans = temp;
        }
    }
    // cout << dist_price[min_idx].first << endl;
    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}