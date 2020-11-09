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

ll N;

bool comp(vs a, vs b){
    ll na = a[2].size(), nb = b[2].size();
    if (na != nb) return na < nb;
    if (a[2] != b[2]) return a[2]<b[2];
    if (a[3].size() != b[3].size()) return a[3].size() < b[3].size();
    return a[3] < b[3];
}

string kurang(string a, string b){
    ll na=a.size(), nb=b.size();
    string big, small;
    if (na != nb){
        big = (na<nb) ? b : a;
        small = (na<nb) ? a : b;
    } else {
        if (a==b) return "0";
        big = (a<b)? b : a;
        small = (a<b)? a : b;
    }

    // cout << big << ' ' << small << endl;

    string big_rev,small_rev;
    for (ll i=big.size()-1; i>=0; i--){
        big_rev+=big[i];
    }

    for (ll i=small.size()-1; i>=0; i--){
        small_rev+=small[i];
    }

    // cout << big_rev << endl;
    // cout << small_rev << endl;

    ll carry = 0;
    string ans;
    for(ll i=0; i<max(na,nb); i++){
        // cout << small_rev[0] << endl;
        ll cur_digit = carry;
        cur_digit += (i<big.size()) ? (ll)big_rev[i]-'0' : 0;
        cur_digit -= (i<small.size()) ? (ll)small_rev[i]-'0' : 0;

        if (cur_digit < 0){
            cur_digit+=10;
            carry = -1;
        } else {
            carry = 0;
        }

        ans+=to_string(cur_digit);
    }

    // cout << ans << endl;

    string ans_rev;
    for(ll i=ans.size()-1; i>=0; i--){
        ans_rev+=ans[i];
    }

    while(*ans_rev.begin()=='0'){
        ans_rev.erase(0,1);
    }


    return ans_rev;
}

void solve(){
    cin>>N;
    // scanf("%lli", &N);
    // cout << N << endl;
    vector<vs> arr;
    for(ll i=0; i<N; i++){
        char x_temp[5001], y_temp[5001];
        scanf("%s %s", x_temp, y_temp);
        // cout << x_temp << endl;
        string x_str = x_temp, y_str=y_temp;
        // cout << "size " << x_str << ' ' << x_str.size() << endl;
        // cin>>x_str>>y_str;
        // char x_str[5001], y_str[5001];
        // string x_str(5001, ' '), y_str(5001, ' ');
        // char x_str[5001], y_str[5001];
        // scanf("%s %s", &x_str[0], &y_str[0]);
        // scanf("%s %s", x_str, y_str);
        // string x_str(x_temp, x_temp+5001);
        // string y_str(y_temp, y_temp+5001);
        // cout << x_str << endl;
        // cout << y_str << endl;
        // cout << sizeof(x_str)/sizeof(x_str[0]) << endl;
        // scanf("%s %s", &x_str[0], &y_str[0]);
        // cout << x_str << ' ' << y_str << endl;
        // string x_str = to_string(x);
        // string y_str = to_string(y);
        string i_str = to_string(i);
        string key = kurang(x_str, y_str);
        arr.push_back({x_str,y_str,key,i_str});
    }

    vector<vs> arr_cpy=arr;
    sort(arr_cpy.begin(), arr_cpy.end(), comp);
    unordered_map<string, ll> mem;
    for(ll i=0; i<N; i++){
        // cout << arr_cpy[i][0] << ' ' << arr_cpy[i][1] << ' ' << arr_cpy[i][2] << endl;
        string key = arr_cpy[i][0] + '-' + arr_cpy[i][1] + '-' + arr_cpy[i][3];
        mem[key] = i;
    }

    for(ll i=0; i<N; i++){
        // cout << arr[i][0] << ' ' << arr[i][1] << endl;
        string key = arr[i][0]+ '-'+ arr[i][1]+ '-'+ arr[i][3];
        ll ans = mem[key]+1;
        printf("%lld\n", ans);
        // cout << mem[key]+1 << endl;
    }
}

int main(){
    solve();
    // string a = "100", b="120000000000000000000000000000000000000000000000000000000";
    // string a="999", b="100";
    // cout << kurang(a, b) << endl;
    // cout << (a < b) << endl;
    // cout << (a == b) << endl;
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
