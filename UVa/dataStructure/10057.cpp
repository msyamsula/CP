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

vi arr;

void solve(int n){
    arr.resize(0);
    map<int, int> count;
    for(int i=0; i<n; i++){
        int temp; cin>>temp;
        arr.push_back(temp);
        count[temp]++;
    }

    sort(arr.begin(), arr.end());

    int mid = (n-1)/2;
    int mid2 = mid+1;

    int minim = 0;
    for(int i=0; i<n; i++){
        minim += abs(arr[i]-arr[mid]);
    }

    if (n%2 != 0){
        cout << arr[mid] << ' ' << count[arr[mid]] << ' ' << 1 << endl;
        return;
    } else if (arr[mid] == arr[mid+2]){
        cout << arr[mid] << ' ' << count[arr[mid]] << ' ' << 1 << endl;
        return;
    }

    int minim2 = 0;
    for(int i=0; i<n; i++){
        minim2 += abs(arr[i]-arr[mid2]);
    }

    int c = 0;
    for(int i=arr[mid]; i<=arr[mid+1]; i++){
        c += count[i];
    }

    cout << arr[mid] << ' ' << c << ' ' << arr[mid+1]+1-arr[mid] << endl;
    // cout << ans << endl;
}

int main(){
    int n;
    while(cin>>n){
        // cout << "Case #" << i+1 << ": ";
        solve(n);
    }

    return 0;
}