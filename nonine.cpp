#include<bits/stdc++.h>
using namespace std;

void solve(int tc){
    long long f, l; cin>>f>>l;

    long long ans = 0;
    for (long long i=f; i<=l; i++){
        if (i%9 == 0) continue;
        string num_str = to_string(i);
        bool cont = 0;
        for(long long j=0; j<num_str.size(); j++){
            if (num_str[j] == '9'){
                cont = 1; break;
            }
        }

        if (cont) continue;
        ans++;
    }

    cout << "Case #" << tc << ": " << ans << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    // long long a = 1004123414000000034123414;
    // cout << a << endl;

    return 0;
}