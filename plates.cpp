#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<ii, int> dpt;




void solve(int tc){
    int n,k,p; cin>>n>>k>>p;
    vvi stack(n);
    vvi psumStack(n);
    for(int i=0; i<n; i++){
        vi cs(k);
        vi psum(k+1);
        for(int j=0; j<k; j++){
            cin>>cs[j];
            // if (j>0){
            psum[j+1] = psum[j] + cs[j];
            // }
        }
        stack[i] = cs;
        psumStack[i] = psum;
    }

    int table[55][1505];
    memset(table, -1, sizeof(table));
    for(int ctot=0; ctot<= min(p,k); ctot++){
        // if (ctot > stack[0].size()) break;
        table[0][ctot] = psumStack[0][ctot];
    }

    for(int st=0; st<n-1; st++){
        for(int ctot = 0; ctot<=p; ctot++){
            if (table[st][ctot] != -1){
                int target = p-ctot;
                for(int take = 0; take<=min(k,target); take++){
                    table[st+1][ctot+take] = max(table[st+1][ctot+take], table[st][ctot]+psumStack[st+1][take]);
                }
            }
        }
    }

    int ans = -(1<<30);
    for(int i=0; i<=p; i++){
        ans = max(table[n-1][i], ans);
    }


    cout << "Case #" << tc << ": ";
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}