#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<char> vc;

void solve(){
    int n; cin>>n;
    viii workList;
    for(int i=0; i<n; i++){
        int s,e; cin>>s>>e;
        workList.push_back({s,e,i});
    }
    sort(workList.begin(), workList.end());
    // for(int i=0; i<workList.size(); i++){
    //     cout << get<0>(workList[i]) << ' ' << get<1>(workList[i]) << ' ' << get<2>(workList[i]) << endl;
    // }
    viii j,c;
    // vc agent;
    j.push_back(workList[0]);
    // agent.push_back('J');
    for(int i=1; i<n; i++){
        iii jw = j[j.size()-1];
        iii cw = workList[i];
        int cws = get<0>(cw), jws = get<0>(jw), jwe = get<1>(jw);
        if (jws<=cws && cws<jwe){
            if (c.empty()){
                c.push_back(cw);
                // agent.push_back('C');
            } else {
                iii camw = c[c.size()-1];
                int camws = get<0>(camw), camwe = get<1>(camw);
                if (camws<=cws && cws<camwe){
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
                c.push_back(cw);
                // agent.push_back('C');
            }
        } else {
            j.push_back(cw);
            // agent.push_back('J');
        }
    }
    vc ans(n);
    for(int i=0; i<j.size(); i++){
        int idx = get<2>(j[i]);
        ans[idx] = 'J';
    }

    for(int i=0; i<c.size(); i++){
        int idx = get<2>(c[i]);
        ans[idx] = 'C';
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout <<"Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}