#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
    int target; cin>>target;
    int target2; cin>>target2;
    int site; cin>>site;
    vvi price1(site);
    vvi price2(site);
    for(int i=0; i<site; i++){
        price1[i].push_back(0);
        price2[i].push_back(0);
        int k; cin>>k;
        for(int j=0; j<k; j++){
            int temp;
            cin>>temp;
            price1[i].push_back(temp);
        }

        for(int j=0; j<k; j++){
            int temp;
            cin>>temp;
            price2[i].push_back(temp);
        }
    }

    for(int i=0; i<site; i++){
        for(int j=0; j<price1[i].size(); j++){
            cout<<price1[i][j]<<' ';
        }
        cout << endl;
    }

    for(int i=0; i<site; i++){
        for(int j=0; j<price2[i].size(); j++){
            cout<<price2[i][j]<<' ';
        }
        cout << endl;
    }

    int dp[site+1][target+1];
    for(int t=0; t<=target; t++){
        dp[0][t] = 1<<30;
    }

    dp[0][0] = 0;

    for(int s=1; s<=site; s++){
        for(int t=0; t<=target; t++){
            int si = s-1;
            // if (t>s)
            dp[s][t] = dp[s-1][t] + price2[si][price2[si].size()-1];
            for(int take=1; take<=min(t, int(price1[si].size()-1)); take++){
                dp[s][t] = min(dp[s][t], dp[s-1][t-take] + price1[si][take] + price2[si][price2[si].size()-1-take]);
            }


            // if (t==0){
            //     dp[s][t] = 0;
            //     continue;
            // }


            // dp[s][t] = dp[s-1][t] + price2[si][price2[si].size()-1];
            // for(int take=1; take<=min(int(price1[si].size()),t); take++){
            //     dp[s][t] = min(dp[s][t], dp[s-1][t-take] + price1[si][take-1] + price2[si][price1[si].size()-take-1]);
            // }
        }
    }

    cout << endl << "dp :" << endl;

    for(int i=0; i<=site; i++){
        cout << i << ' ';
        for(int j=0; j<=target; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}