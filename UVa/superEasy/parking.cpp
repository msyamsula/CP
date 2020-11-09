#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)


void solve(){
    int tot;
    scanf("%i", &tot);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);
    stringstream ss(line);
    int value;

    vector<int> arr;
    int sum = 0;
    while(ss>>value){
        sum+=value;
        arr.push_back(value);
    }

    sort(arr.begin(), arr.end());

    int mid = arr[0] + (arr[arr.size()-1]-arr[0])/2;
    cout << mid << endl;
    int dist = 0;
    vector<int>::iterator i;
    iter(arr, i){
        dist += (*i-mid > 0) ? *i-mid : mid-(*i); 
    }

    cout << dist << endl;
}

int main(){
    int T;
    scanf("%i", &T);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    f(t,0,T,1){
        solve();
    }

    return 0;
}