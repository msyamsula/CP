#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii; 
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a,i) for(i=a.begin(); i!=a.end(); i++)

void show(int a[3], int s){
    f(i,0,s,1){
        cout << a[i] << " \n"[i==s-1];
    }
}

void change(int a[3]){
    a[1] = 1;
    show(a,3);
}

int main(){

    // vi a;
    // a.resize(3);
    // int a[3] = {0};
    // bitset<(1<<11)> a;
    // a[2] = 1;
    vi a = {1,2,3,4,10,5,6,7};
    // show(a,3);
    // change(a);
    // show(a,3);
    // cout << bitset<(1<<11)>(a) << endl;
    cout << binary_search(a.begin(), a.end(), 10) << endl;

    return 0;
}