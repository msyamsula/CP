#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<char, int> mci;

// mci mem;

void solve(){
    string s; cin>>s;
    bool other = 0;
    int hash = 0;
    for(int i=0; i<s.size(); i++){
        hash += int(s[i])-'a';
    }

    int hashCopy = hash;
    string first = "";
    int n = s.size();
    for(int i=0;i<n; i++){
        if (i == n-1){
            first += char(hash+int('a'));
            // cout << hash << ' ' << first << endl;
            continue;
        }

        int limit = 25*(n-(i+1));
        if (hash < limit){
            first += 'a';
        } else if (hash > limit) {
            int number = hash-limit;
            char temp = char(number+int('a'));
            first += temp;
            hash = limit;
        }
        // cout << first[first.size()-1] << endl;
    }

    // cout << first.size() << ' ' << hashCopy << ' ' << first << endl;
    cout << hashCopy << ' ';
    if (first == s){
        bool dup = 0;
        for(int i=s.size()-1; i>=1; i--){
            if (s[i] == 'a' || s[i-1] == 'z') continue;
            dup = 1;
            first[i-1] = char(int(first[i-1])+1);
            first[i] = char(int(first[i-1])-1);
            break;
        }
        if (dup){
            cout << first << endl;
            return;
        }
        cout << -1 << endl;
    } else {
        cout << first << endl;
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}