#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int,int> mii;
typedef vector<mii> vmii;

// int dp(vi arr, int l, int r, mii trinkets, int s, bool status, bool ps){
//     if (r==arr.size() || (status == 0 && ps == 1)){
//         // mii::iterator it = trinkets.begin();
//         // int count = 0;
//         // while(it != trinkets.end()){
//         //     if (it->second <= s) count+=it->second;
//         //     it++;
//         // }
//         // return count;
//         return 0;
//     }

//     if (trinkets[arr[r]] < 2){
//         int leave = dp(arr, r+1, r+1, trinkets, s, 0, status);
//         trinkets[arr[l]] += 1;
//         int take = 1+dp(arr,l,r+1, trinkets,s,1,status);
//         return max(take, leave);
//     }

//     return dp(arr,r+1,r+1,trinkets,s,0,status);

    

//     // trinkets[arr[l]] += 1;
//     // int take = solve(arr,l,r+1,trinkets,s);
//     // trinkets[arr[l]] -= 1;
//     // int leave = solve(arr,l+1,r+1,trinkets,s)
//     // return max(take, leave);
// }

// void solve(int tc){
//     int n, s;
//     cin>>n>>s;
//     vi arr(n);
//     for (int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     // mii trinkets;
//     // bool status = 0, ps = 0;
//     // cout << dp(arr,0,0,trinkets,s,status,ps) << endl;
//     vmii ps(n+1);
//     for (int i=0; i<n; i++){
//         int tt = arr[i];
//         ps[i+1] = ps[i];
//         ps[i+1][tt] = ps[i][tt]+1;
//     }

//     // vmii::iterator ii = ps.begin();
//     // while(ii!=ps.end()){
//     //     cout << "ps index " << ii - ps.begin() << endl;
//     //     mii::iterator jj = ii->begin();
//     //     while(jj!=ii->end()){
//     //         cout << jj->first << ' ' << jj->second << endl;
//     //         jj++;
//     //     }
//     //     ii++;
//     // }



//     int maxCount = -1;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int count = 0;
//             mii::iterator it=ps[j+1].begin();
//             while(it!=ps[j+1].end()){
//                 if (it->second - ps[i][it->first] > s){
//                     count += 0; 
//                     // count++;
//                 } else {
//                     count+=it->second - ps[i][it->first];
//                 }
//                 it++;
//             }

//             // cout << i << ' ' << j << ' ' << count << endl;
//             maxCount = max(count, maxCount);                                                      
//         }
//     }

//     cout << "Case #" << tc << ": " << maxCount << endl;
// }

void build(vi arr, vmii &segment, int p, int x, int y){
    if (x==y){
        mii temp;
        temp[arr[x]] = 1;
        segment[p] = temp;
    } else {
        int mid = (x+y)/2;
        build(arr, segment, 2*p, x, mid);
        build(arr, segment, 2*p+1, mid+1, y);
        segment[p] = segment[2*p];
        mii::iterator ii=segment[2*p+1].begin();
        while(ii!=segment[2*p+1].end()){
            segment[p][ii->first] += ii->second;
            ii++;
        }
    }
}


void solve(int tc){
    int n,s;
    cin>>n>>s;
    vi arr(n);
    vmii segment(4*n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    build(arr, segment, 1, 0, arr.size()-1);
}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}