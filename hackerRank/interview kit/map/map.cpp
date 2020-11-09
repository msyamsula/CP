#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;

int main(){
    int ans = 0;
    int n, r;
    cin>>n; cin>>r;
    int value;
    // cout << r << endl;
    vi dict;
    for(int ni=0;ni<n;ni++){
        cin>>value;
        dict.push_back(value);
        // if (value%r==0 || value==1){
        //     try{
        //         dict.at(value)++;
        //     } catch (const exception &e){
        //         dict[value] = 1;
        //     }
        // }
    }

    int sz = dict.size();
    for (int i=0; i<sz-2; i++){
        stack<int> st;
        st.push(dict[i]);
        for (int j=i; j<sz; j++){

            if (dict[j] == st.top()*r){
                st.push(dict[j]);
            }

            if (st.size() == 3){
                ans++;
                st.pop();
                // break;
            }
            cout << ans << ' ' << dict[j] << ' ' << st.top() << endl;
        }
    }

    // mii::iterator i;
    // int ans = 0;
    // if (dict.size()<3){
    //     cout << ans << endl;
    //     return 0;
    // }

    // for(i=dict.begin(); i!=dict.end(); i++){
    //     if (ans == 0){
    //         ans = i->second;
    //     } else {
    //         ans *= i->second;
    //     }
    // }

    cout << ans << endl;

    return 0;
}