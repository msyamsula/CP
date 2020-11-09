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

ll N,P,Q;
vl prices;
// vl taken;
set<ll> competed_item;
queue<ll> competed_q;

bool comp(vl a, vl b){
    if (a[0]!=b[0]) return a[0] > b[0];
    return a[1] < b[1];
}

class Person{
public:
    set<ll> target;
    queue<ll> eks_q;
    ll sum;
    Person(){
        target.clear();
        sum = 0;
        while(!eks_q.empty()) eks_q.pop();
    }

    void target_item(ll num){
        target.insert(num);
    }

    bool peek_item(ll num){
        return target.find(num) != target.end();
    }

    void create_eks(){
        vvl eks_arr;
        for(ll num : target){
            ll p = prices[num];
            if (competed_item.find(num) == competed_item.end()) eks_arr.push_back({p, num});
        }

        sort(eks_arr.begin(), eks_arr.end(), comp);
        // cout << "eks_q" << endl;
        for(vl a : eks_arr){
            // cout << a[0] << ' ' << a[1] << endl;
            eks_q.push(a[1]);
        }
        // cout << "--" << endl;
    }

    bool take_eks(){
        if (eks_q.empty()) return 0;
        ll idx = eks_q.front(); eks_q.pop();
        sum += prices[idx];
        // eks_q.pop();
        // cout << " take " << idx << " : has sum = " << sum << endl;
        return 1;
    }

    bool take_compete(){
        if (competed_q.empty()) return 0;
        ll c_idx = competed_q.front();
        if (prices[c_idx] == 0) return 0;
        // if (!eks_q.empty()){
        //     ll e_idx = eks_q.front();
        //     if (prices[e_idx] > prices[c_idx]) return 0;
        // }

        sum += prices[c_idx];
        competed_q.pop();
        // cout << " take " << c_idx << " : has sum = " << sum << endl;
        return 1;
    }
};

void solve(){
    prices.resize(0);
    // taken.resize(0); taken.assign(N, 0);
    for(ll i=0; i<N; i++){
        ll temp; cin>>temp;
        prices.push_back(temp);
    }
    Person me, dengklek;

    // cout << "my item" << endl;
    for(ll i=0; i<P; i++){
        ll temp; cin>>temp; temp--;
        // cout << temp << endl;
        me.target_item(temp);
    }

    // cout << "dengklek item" << endl;
    for(ll i=0; i<Q; i++){
        ll temp; cin>>temp; temp--;
        // cout << temp << endl;
        if (me.peek_item(temp)) competed_item.insert(temp);
        dengklek.target_item(temp);
    }

    vvl temp;
    for(ll num : competed_item){
        ll p = prices[num];
        temp.push_back({p, num});
    }

    // cout << "prices " << endl;
    // for(ll num : prices){
    //     cout << num << ' ';
    // }
    // cout << endl;
    
    sort(temp.begin(), temp.end(), comp);
    // cout << "competed item = " << competed_item.size() << endl;
    for(vl a : temp){
        // cout << a[0] << ' ' << a[1] << endl;
        competed_q.push(a[1]);
    }

    me.create_eks(); dengklek.create_eks();

    while(1){
        // cout << "me";
        if (!me.take_compete()){
            bool ans = me.take_eks();
            if (!ans) break;
        }
        // cout << "dengklek";
        if (!dengklek.take_compete()) dengklek.take_eks();
    }

    cout << me.sum << endl;
}

int main(){
    while(cin>>N>>P>>Q){
        solve();
    }
    // vl arr = {1,2,3,5,7};
    // for(ll num : arr){
    //     cout << num << ' ';
    // }
    // cout << endl;
    // cout << *upper_bound(arr.begin(), arr.end(), 8) << endl;
    // cout << (upper_bound(arr.begin(), arr.end(), 8) == arr.end()) << endl;
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
