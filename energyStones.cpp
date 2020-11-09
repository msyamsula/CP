#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
typedef pair<int, int> ii;
typedef map<ii, int> miii;

// miii mem;

int dp(int t, viii stones, int idx, miii &mem){
    // if (stones.size() == 0) return 0;
    ii key = {t, idx};
    if (mem.find(key) != mem.end()){
        // cout << "memo" << endl;
        return mem.at(key);
    }

    // cout << "calculate" << endl;
    if (idx == stones.size()){
        mem[key] = 0;
        return 0;
    }

    int n = stones.size();
    int energy = 0;
    iii temp = stones[idx];
    int l = -get<0>(temp);
    int s = get<1>(temp);
    int e = get<2>(temp);
    int eget = max(0, e-l*t);
    if (eget == 0) return dp(t, stones, idx+1, mem);

    mem[key] = max( eget+dp(t+s, stones, idx+1, mem), dp(t, stones, idx+1, mem));
    return mem[key];

    // for (int i=0; i<n; i++){
    //     iii temp = stones[i];
        
    //     int s = get<0>(temp);
    //     int e = get<1>(temp);
    //     int l = get<2>(temp);

    //     int eget = max(0, e-l*t);
    //     if (eget == 0) continue;

    //     stones.erase(stones.begin()+i);
    //     energy = max(energy, eget+dp(t+s, stones));
    //     stones.insert(stones.begin()+i, temp);
    // }
    // return energy;
}

void solve(int tc){
    int n; cin>>n;
    viii stones;
    for (int i=0; i<n; i++){
        int s,e,l;
        cin>>s>>e>>l;
        iii temp = make_tuple(-l,s,e);
        stones.push_back(temp);
    }

    sort(stones.begin(), stones.end());

    // for(int i=0; i<n; i++){
    //     iii temp = stones[i];
    //     int l = -get<0>(temp);
    //     int s = get<1>(temp);
    //     int e = get<2>(temp);
    //     cout << l << ' ' << s << ' ' << e << endl;
    // }

    miii mem;
    int ans = dp(0,stones,0,mem);
    cout << "Case #" << tc << ": " << ans << endl;
}


int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    // iii a = make_tuple(1,1,1);
    // cout << (get<0>(a)) << endl;

    return 0;
}