#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;


void solve(int s, int b){
    // cout << s << endl;
    // mem.clear();
    vi soldier;
    for(int i=0; i<s; i++){
        soldier.push_back(i);
    }

    // for(pair<int, pair<int, int>> temp: mem){
    //     cout << temp.first << ": " << temp.second.first << ' ' << temp.second.second << endl;
    // }
    // cout <<endl;

    for(int i=0; i<b; i++){
        // for(int num : soldier){
        //     cout << num << ' ';
        // }
        // cout << endl;
        int l,r; cin>>l>>r; l--; r--;
        vi::iterator lc = lower_bound(soldier.begin(), soldier.end(), l);
        vi::iterator rc = lower_bound(soldier.begin(), soldier.end(), r);
        if (lc==soldier.begin()) cout << "* ";
        else{
            lc--;
            cout << *lc+1 << ' ';
            lc++;
        }

        if (rc==soldier.end()-1) cout << '*' << endl;
        else{
            rc++;
            cout << *rc+1 << endl;
            rc--;
        }

        rc++;
        soldier.erase(lc,rc);
    }
    cout << '-' << endl;
}

// void solve(int s, int b){
//     // cout << s << endl;
//     // mem.clear();
//     map<int, pair<int,int>> mem;
//     for(int i=0; i<s; i++){
//         int left = (i-1 < 0) ? -1 : i-1;
//         int right = (i+1 >= s) ? -1 : i+1;
//         // cout << i << ' ' << (i+1) << ' ' << s << endl;
//         mem[i] = {left, right};
//     }

//     // for(pair<int, pair<int, int>> temp: mem){
//     //     cout << temp.first << ": " << temp.second.first << ' ' << temp.second.second << endl;
//     // }
//     // cout <<endl;

//     for(int i=0; i<b; i++){
//         int l,r; cin>>l>>r; l--; r--;
//         int lc = mem[l].first, rc = mem[r].second;
//         string ans1 = (lc == -1) ? "*" : to_string(lc+1);
//         string ans2 = (rc == -1) ? "*" : to_string(rc+1);
//         cout << ans1+' ' << ans2 << endl;
//         try{
//             mem.at(rc).first = lc;
//         } catch (const exception &e) {}

//         try{
//             mem.at(lc).second = rc;
//         } catch (const exception &e) {}
//     }

    
//     cout << '-' << endl;
// }

int main(){
    int s,b;
    while(cin>>s>>b){
        if (s==0 && b==0) break;
        solve(s,b);
    }

    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}