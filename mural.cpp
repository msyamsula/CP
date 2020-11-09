#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// void build(vi &segment, vi arr, int p, int x, int y){
//     if (x==y) segment[p] = arr[x];
//     else {
//         int mid = (x+y)/2;
//         build(segment, arr, 2*p, x, mid);
//         build(segment, arr, 2*p+1, mid+1, y);
//         segment[p] = segment[2*p] + segment[2*p+1];
//     }
// }

// int rq(vi segment, int p, int x, int y, int a, int b){
//     if (x>b || y<a) return 0;
//     else if ( a<=x && y<=b ) return segment[p];

//     int mid = (x+y)/2;
//     int left = rq(segment, 2*p, x, mid, a, b);
//     int right = rq(segment, 2*p+1, mid+1, y, a, b);

//     return left+right;
// }

void solve(int tc){
    int n; cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vi arr(n+1, 0);
    string line;
    getline(cin, line);
    int sum = 0;
    for (int i=1; i<n+1; i++){
        sum += int(line[i-1]) - '0';
        arr[i] = sum;
        // cout << arr[i] << ' ';
    }
    // cout << endl;

    int max = 0;
    int pseg = (n%2==0) ? n/2 : (n+1)/2;

    for (int i=pseg; i<n+1; i++){
        int temp = arr[i] - arr[i-pseg];
        if (temp > max) max = temp;
    }

    cout << "Case #" << tc << ": " << max << endl;
}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}