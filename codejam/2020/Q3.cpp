#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<char> vc;
typedef vector<string> vs;

string fbracket(string a){
    string ans;
    int big = int(a[0]) - '0';
    for(int i=0; i<big; i++){
        ans += '(';
    }
    ans+=a[0];

    for(int i=1; i<=a.size(); i++){
        int prev = int(a[i-1]) - '0';
        int cur = (i==a.size()) ? 0 : int(a[i]) - '0';
        for(int ii=0; ii<prev-cur; ii++){
            ans+=')';
        }
        if (i < a.size()) ans+=a[i];
    }

    return ans;
}

void solve(){
    string a; cin>>a;
    string fans = "";
    string rans = "";
    
    for(int i=0; i<a.size(); i++){
        char base = a[i];
        string temp = "";
        while(a[i]<=base && i<a.size()){
            // cout << i << endl;
            base = a[i];
            temp += base;
            i++;
        }
        // cout << i << ' ' << temp << endl;
        // cout << bracket(temp) << endl;
        fans += fbracket(temp);
        i--;
    }
    // cout << fans << endl;

    string ans = "";
    // cout << ans << endl;
    for(int i=0; i<9; i++){
        ans = "";
        for(int i=0; i<fans.size(); i++){
            // cout << i << ' ' << fans[i] << ' ' << fans[i+1] << endl;
            if(fans[i] == ')' && fans[i+1] == '('){
                // cout << i << endl;
                i = min(i+1, (int)fans.size()-1);
                continue;
            }
            ans += fans[i];
        }
        fans = ans;
    }
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout <<"Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}