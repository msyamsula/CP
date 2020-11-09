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

ll n,r,y,j;
vector<pair<ll, char>> dance;
ll point;
vector<pair<ll, char>> choice;
vl used, judge;
vl jru;

void search(ll idx, bool yakin){
    if (idx == r){
        auto it = lower_bound(judge.begin(), judge.end(), point);
        if (it == judge.begin()) return;
        ll dist = distance(judge.begin(), it) - 1;
        // cout << "choice: " << endl;
        // for(pair<ll, char> p : choice){
        //     cout << p.first << ' ' << p.second << endl;
        // }
        // cout << "points: " << point << endl; 
        // cout << "judge 0 to " << dist << " are happy." << endl;
        // cout << endl;
        jru[0] += 1; jru[dist+1] -= 1;
        return;
    }
    for(ll i=0; i<n; i++){
        bool yakin_local = 0;
        if (used[i]) continue;
        ll d = dance[i].first;
        char t = (choice.empty()) ? 'B' : choice[choice.size()-1].second;
        if (t == 'P') d *= 2;
        else if (t == 'L') d/=2;
        if (yakin) d+=y;
        if (dance[i].second == 'Y') yakin_local = 1;
        point += d;
        used[i] = 1;
        choice.push_back(dance[i]);
        search(idx+1, yakin_local|yakin);
        point -= d;
        used[i] = 0;
        choice.pop_back();
    }
}

void solve(){
    cin>>n>>r>>y>>j;
    dance.resize(0);
    // cout << "nryj: " << n << ' ' << r << ' ' << y << ' ' << j << endl;
    for(ll i=0; i<n; i++){
        ll d; char t;
        cin>>d>>t;
        dance.push_back(make_pair(d,t));
    }

    // cout << "dance: " << endl;
    // for(pair<ll, char> p : dance){
    //     cout << p.first << ' ' << p.second << endl;
    // }
    // cout << endl;

    judge.resize(0);
    for(ll i=0; i<j; i++){
        ll temp; cin>>temp;
        judge.push_back(temp);
    }

    vl real_judge = judge;

    sort(judge.begin(), judge.end());

    // cout << "judge: ";
    // for(ll i=0; i<j; i++){
    //     cout << judge[i] << ' ';
    // }
    // cout << endl;

    point = 0;
    choice.resize(0);
    used.resize(0); used.assign(n, 0);
    jru.resize(0); jru.assign(j+1, 0);
    search(0, 0);

    vl judge_cnt;
    ll sum = 0;
    for(ll num : jru){
        sum+=num;
        judge_cnt.push_back(sum);
    }
    judge_cnt.pop_back();

    unordered_map<ll, ll> jmap;
    for(ll i=0; i<j; i++){
        jmap[judge[i]] = judge_cnt[i];
    }

    // cout << "ans: " << endl;
    for(ll num :real_judge){
        cout << jmap[num] << endl;
    }
}

int main(){
    string t1,t2;
    while(cin>>t1>>t2){
        solve();
    }

    return 0;
}
