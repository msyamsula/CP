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
#define MAXLL (1ll<<60)
#define MAXI (1<<30)


string encode(string T){
    int n= T.size();
    string ans;
    for(int i=0; i<n; i++){
        char temp = T[i];
        string temp2 = to_string(int(temp));
        for(int j=0; j<temp2.size(); j++){
            ans += temp2[temp2.size()-1-j];
        }
    }

    return ans;
}

string decode(string T){
    int n=T.size();
    // cout << T << endl;
    string ans;
    for(int i=0; i<n; i++){
        string numstr;
        if ( i+2 < n && T[i+2]=='1'){
            numstr += T[i+2];
            numstr += T[i+1];
            // cout << i+1 << ' ' << T[i+1] << ' ' << numstr << endl;
            numstr += T[i];
            int num = stoi(numstr);
            if (num <= 122){
                ans += char(num);
                i++; i++;
                continue;
            }
        }
        numstr = "";
        numstr += T[i+1];
        numstr += T[i];
        int num = stoi(numstr);
        ans += char(num);
        i++;
        
    }

    string t = ans;
    n = t.size();
    for(int i=0; i<n; i++){
        ans[i] = t[n-1-i];
    }

    return ans;
}

void solve(string T){
    int n = T.size();
    string rev;
    for(int i=0; i<n; i++){
        rev += T[n-1-i];
    }

    if (isdigit(rev[0])){
        string ans = decode(T);
        cout << ans << endl;
    } else {
        string ans = encode(rev);
        cout << ans << endl;
    }
}

int main(){
    string T;
    while(getline(cin,T)){
        solve(T);
    }

    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}