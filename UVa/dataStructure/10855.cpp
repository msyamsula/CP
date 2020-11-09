#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vs big, small;

void rotate(){
    vs temp = big;
    int n = temp.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = big[j][n-1-i];
        }
    }
    big = temp;
}

int countMatch(){
    int ans = 0;
    int N = big.size(), n = small.size();
    for(int i=0; i<N-n+1; i++){
        for(int j=0; j<N-n+1; j++){
            bool same = 1;
            for(int ii=0; ii<n; ii++){
                for(int jj=0; jj<n; jj++){
                    if (small[ii][jj] != big[i+ii][j+jj]) same=0;
                    if (!same) break;
                }
                if (!same) break;
            }
            if(same) ans += 1;
        }
    }

    return ans;
}

void solve(int N, int n){
    big.resize(0); small.resize(0);
    big.assign(N, string(N,' '));
    small.assign(n, string(n, ' '));
    for(int i=0; i<N; i++){
        cin>>big[i];
    }
    for(int i=0; i<n; i++){
        cin>>small[i];
    }

    // for(string temp : big){
    //     cout << temp << endl;
    // }
    // cout << endl;

    // for(string temp : small){
    //     cout << temp << endl;
    // }
    // cout << endl;

    vi ans(4,0);
    // ans[0] = countMatch();

    for(int i=0; i<4; i++){
        ans[i] = countMatch();
        // for(string temp : big){
        //     cout << temp << endl;
        // }
        // cout << endl;
        rotate();
    }

    for(int i=0; i<4; i++){
        cout << ans[i] << " \n"[i==3];
    }
}

int main(){
    int N,n;
    while(cin>>N>>n){
        if (!N && !n) break;
        // cout << "Case #" << i+1 << ": ";
        solve(N,n);
    }

    return 0;
}