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

vi arr;

int main(){
    int n; cin>>n;
    arr.resize(0);
    for(int i=0; i<n;i++){
        int ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    stack<int> st;
    st.push(n-1);

    vi nextBig(n,MAXI);
    for(int i=n-2; i>=0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        nextBig[i] = (st.empty()) ? MAXI : st.top();
        st.push(i);
    }

    // for(int a : nextBig){
    //     cout << a << ' ';
    // }
    // cout << endl;

    vi prevBig(n,MAXI);
    stack<int> st2;
    st2.push(0);
    for(int i=1; i<n; i++){
        while(!st2.empty() && arr[st2.top()] <= arr[i]) st2.pop();
        prevBig[i] = (st2.empty()) ? MAXI : st2.top();
        st2.push(i);
    }

    // for(int a : prevBig){
    //     cout << a << ' ';
    // }
    // cout << endl;

    int total = 0;
    for(int i=0; i<n; i++){
        int c1 = (prevBig[i] == MAXI) ? MAXI : arr[prevBig[i]];
        int c2 = (nextBig[i] == MAXI) ? MAXI : arr[nextBig[i]];
        int ntemp = min(c1,c2);
        if (ntemp == MAXI) continue;
        total += ntemp;
    }

    cout << total << endl;
    return 0;
}
