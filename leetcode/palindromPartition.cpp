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

bool checkPalindrome(string s){
    ll n = s.size();
    for(ll i=0; i<n/2; i++){
        if (s[i]!=s[n-1-i]) return 0;
    }

    return 1;
}

class Solution {
public:
    vvs ans;
    vs cur_pal;
    void search(string s){
        if (s.size()==0){
            ans.push_back(cur_pal);
            return;
        }
        ll n=s.size();
        for(ll i=0; i<n; i++){
            string sub_str(s.begin(), s.begin()+i+1);
            if (checkPalindrome(sub_str)){
                cur_pal.push_back(sub_str);
                string new_search(s.begin()+i+1, s.end());
                search(new_search);
                cur_pal.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        search(s);
        return ans;
    }
};

int main(){
    vs a = {"a"}, b = {"b"};
    a.insert(a.end(), b.begin(), b.end());
    
    for(string temp:a){
        cout << temp << endl;
    }
}