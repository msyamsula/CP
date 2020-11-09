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
void showV(vl temp){
    for(ll t : temp){
        cout << t << ' ';
    }
    cout << endl;
}

void showVV(vvl temp){
    for (vl t : temp){
        for(ll t1 : t){
            cout << t1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
ll n;
vl arr;

void solve(){
    cin>>n;
    arr.resize(0);
    map<ll, ll> mem;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
        mem[temp]++;
    }

    set<double> unique;
    queue<vector<double>> q;
    for(auto it=mem.begin(); it!=mem.end(); it++){
        double num = (double)it->first, cnt = (double)it->second;
        if (it->second == 1){
            unique.insert(num);
        } else {
            q.push({num, cnt});
        }
    }

    // if unique size == n, ans = n, return
    if (unique.size() == n){
        cout << n << endl;
        return;
    }

    while(!q.empty() && q.size() > 1){
        double u = q.front()[0], cnt_u = q.front()[1]; q.pop();
        // while cnt_u == 1
        while(cnt_u == 1){
            // check u in unique
            // if not found then push, pull another u from queue
            // if queue is empty while pulling, break;
            if (unique.find(u) == unique.end()){
                unique.insert(u);
                if (q.empty()) break;
                u = q.front()[0]; cnt_u = q.front()[1]; q.pop();
            } else {
                // if found, add cnt_u, break
                // erase u from unique
                // no pulling needed
                unique.erase(u);
                cnt_u++;
            }
        }

        // after got u, check if queue is empty
        // if empty, break
        if (q.empty()) break;

        // if not empty, pull from queue
        double v = q.front()[0], cnt_v = q.front()[1]; q.pop();
        while(cnt_v == 1){
            // check v in unique
            // if not found then push, pull another v from queue
            // if queue is empty while pulling, break;
            if (unique.find(v) == unique.end()){
                unique.insert(v);
                if (q.empty()) break;
                v = q.front()[0]; cnt_v = q.front()[1]; q.pop();
            } else {
                // if found, add cnt_u, break
                // erase u from unique
                // no pulling needed
                unique.erase(v);
                cnt_v++;
            }
        }

        // merge u and v
        cnt_u--; cnt_v--;
        double new_num = (u+v)/2;
        // push new u with new cnt u, along with v
        q.push({u,cnt_u});
        q.push({v,cnt_v});

        // check new num in unique
        // if not found, push to queue with cnt 2
        // if found, push with cnt 3
        if (unique.find(new_num) == unique.end()){
            q.push({new_num, 2});
        } else {
            q.push({new_num, 3});
        }
    }


    // ans is size of unique+1
    cout << unique.size()+1 << endl;

}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
