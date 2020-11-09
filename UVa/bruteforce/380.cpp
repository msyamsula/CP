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

// struct phone{
//     string extension;
//     vs forward;
//     phone(){
//         extension="";
//         forward.assign(8785, "");
//     }
// };

// vector<phone> phones;
map<string, vs> phones;

void solve(){
    phones.clear();
    string source;
    while(cin>>source){
        if(source == "0000") break;
        string start_str, duration_str, target;
        cin>>start_str>>duration_str>>target;
        ll start = stoll(start_str), duration = stoll(duration_str);
        if (phones.find(source) == phones.end()){
            vs temp; temp.assign(8785, "OK");
            for(ll i=start; i<=start+duration; i++){
                temp[i] = target;
            }
            phones[source] = temp;
        } else {
            for(ll i=start; i<=start+duration; i++){
                phones[source][i] = target;
            }
        }

        if(phones.find(target) == phones.end()){
            vs temp; temp.assign(8785, "OK");
            phones[target] = temp;
        }
    }

    // for(pair<string, vs> temp: phones){
    //     string ext = temp.first;
    //     cout << temp.first << endl;
    //     for(string num : temp.second){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    string call_time_str; string ext;
    while(cin>>call_time_str){
        if (call_time_str == "9000") break;
        cin>>ext;
        // cout << "call at " << call_time_str << " to " << ext << endl;
        ll call_time = stoll(call_time_str);
        if (phones.find(ext) == phones.end()){
            cout << "AT " << call_time_str << " CALL TO " << ext << " RINGS " << ext << endl;
            continue;
        }

        set<string> call_path;
        call_path.insert(ext);
        string cur_ext = ext;
        string forward = phones[ext][call_time];
        string ans = cur_ext;
        while(forward != "OK"){
            cur_ext = forward;
            if (call_path.find(cur_ext) != call_path.end()){
                // cout << "9999" << endl;
                ans = "9999";
                break;
            } else {
                call_path.insert(cur_ext);
                forward = phones[cur_ext][call_time];
                ans = cur_ext;
            }
        }
        cout << "AT " << call_time_str << " CALL TO " << ext << " RINGS " << ans << endl;
    }
}

int main(){
    int tc; cin>>tc;
    cout << "CALL FORWARDING OUTPUT" << endl;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        cout << "SYSTEM " << i+1 << endl;
        solve();
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
