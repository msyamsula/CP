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

vl arr;
vl intip;

int main(){
    int n; cin>>n;
    arr.resize(0); intip.resize(0); intip.assign(n,1);
    for(int i=0; i<n; i++){
        ll ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    stack<ll> st;
    st.push(0);

    ll count = intip[0];
    for(ll i=1; i<n; i++){
        while(!st.empty() && (arr[st.top()] <= arr[i])) st.pop();
        intip[i] = (st.empty()) ? i+1 : i-st.top();
        count += intip[i];
        st.push(i);
    }

    cout << count << endl;


    return 0;
}
