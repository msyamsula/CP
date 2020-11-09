#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<ll, ll> ii;
typedef pair<ii, int> iii;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

ll N,K;
vector<ii> dog;
map<ll, set<ll>> jump;
vector<vector<ii>> dp;

void solve(){
    cin>>N>>K;
    dog.resize(0); dog.resize(N);
    jump.clear();
    for(ll i=0; i<N; i++){
        cin>>dog[i].first;
    }


    for(ll i=0; i<N; i++){
        cin>>dog[i].second;
        dog[i].second--;
    }

    sort(dog.begin(),dog.end());

    // cout << "sorted dog: " << endl;
    // for(ii p : dog){
    //     cout << p.first << ' ' << p.second << endl;
    // }

    for(ll i=0; i<N; i++){
        ll color = dog[i].second;
        if (i!=0) jump[color].insert(i);
    }


    ii zonk = {MAXLL, MAXLL};
    dp.resize(0); dp.assign(1000, vector<ii>(K+1, zonk));
    // cout << "jump: " << endl;
    for(pair<ll, set<ll>> p : jump){
        ll color = p.first;
        // cout << "color " << color << ": ";
        // for(ll num : p.second){
        //     cout << num << ' ';
        // }
        // cout << endl;
        dp[color][0] = {0,-1};
    }

    // cout << dp.size() << ' ' << dp[0].size() << endl;
    for(ll c=0; c<K; c++){
        for(ll r=0; r<1000; r++){
            if (dp[r][c] == zonk) continue;
            ll index = dp[r][c].second;
            ll next_index = index+1;
            ll cur_pos = (index < 0) ? 0 : dog[index].first;
            if (next_index >= N) continue;
            // cout << r << ' ' << c << ' ' << next_index << endl;
            // if next has same color: take
                // check step
                // add step to current value
                // dp[color][c+1] = {step + current_step, next_index}
            // if not
                // if can jump: jump, delete jump
                // take
            if (dog[next_index].second == r){
                ll step = dog[next_index].first - cur_pos;
                ll new_step = dp[r][c].first + step;
                ii new_status = {new_step, next_index};
                dp[r][c+1] = min(dp[r][c+1], new_status); 
            } else {
                if (jump.find(r) != jump.end() && jump.at(r).size() > 0){
                    auto jump_it = lower_bound(jump.at(r).begin(), jump.at(r).end(), next_index);
                    if (jump_it != jump.at(r).end()){
                        ll jump_index = *jump_it;
                        ll next_dog_pos = dog[jump_index].first;
                        // cout << "tes" << endl;
                        ll step = next_dog_pos - cur_pos;
                        ll new_step = dp[r][c].first + step;
                    // cout << "tes" << endl;
                        ii new_status = {new_step, jump_index};
                        dp[r][c+1] = min(dp[r][c+1], new_status);
                        // jump.at(r).erase(jump_index);
                    }
                }

                ll next_dog_pos = dog[next_index].first;
                ll step = cur_pos + next_dog_pos;
                ll new_step = dp[r][c].first + step;
                ll new_color = dog[next_index].second;
                ii new_status = {new_step, next_index};
                dp[new_color][c+1] = min(dp[new_color][c+1], new_status);

            }
        }
    }

    ll ans = MAXLL;
    for(ll r=0; r<1000; r++){
        ans = min(ans, dp[r][K].first);
    }

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
