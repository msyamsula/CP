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

unordered_map<ll, ll> cl;
vl st;
ll len_max = 1000000;

void update(ll p, ll a, ll b, ll idx, ll val){
    if (idx<=a && b<=idx){
        st[p] = val;
        return;
    }

    if (b<idx || a>idx) return;

    ll mid = (a+b)/2;
    update(2*p, a, mid, idx, val); update(2*p+1, mid+1, b, idx, val);
    st[p] = max(st[2*p], st[2*p+1]);
}

void update(ll idx, ll val){
    update(1, 0, len_max, idx, val);
}

ll rmq(ll p, ll a, ll b, ll x, ll y){
    if (b<x || a>y) return -MAXLL;
    if (x<=a && b<=y) return st[p];
    ll mid = (a+b)/2;
    ll left = rmq(2*p, a, mid, x, y), right = rmq(2*p+1, mid+1, b, x, y);
    return max(left, right);
}

ll rmq(ll x, ll y){
    return rmq(1, 0, len_max, x, y);
}

ll cycle_length(ll n){
    if (cl.find(n) != cl.end()) return cl.at(n);

    if (n%2 == 0) return cl[n] = 1 + cycle_length(n/2);

    return cl[n] = 1 + cycle_length(3*n+1);
}

void solve(){

}

int main(){
    
    st.assign(4*(len_max+1), 0);
    cl[1] = 1;
    for(ll i=1; i<=len_max; i++){
        update(i, cycle_length(i));
    }
    ll a, b;
    while(cin>>a>>b){
        ll ans = 0;
        vl arr = {a,b};
        sort(arr.begin(), arr.end());
        cout << a << ' ' << b << ' ' << rmq(arr[0],arr[1]) << endl;
    }
    

    return 0;
}

// #include<stdio.h>
// int cycle(int a)
// {
//     int i=0;
//     while(1)
//     {
//              i++;

//         if(a==1)
//             break;
//         if(a%2!=0)
//             a=(3*a)+1;
//         else
//             a=a/2;
//     }
//     return i;

// }
// int main()
// {
//     int a,b,c,temp,i;
//     while(scanf("%d%d",&a,&b)==2)
//     {
//         int max=0;
//         printf("%d %d ",a,b);
//         if(a>b)
//         {
//             temp=a;
//             a=b;
//             b=temp;
//         }
//         for(i=a;i<=b;i++)
//         {
//             c=cycle(i);
//             if(c>=max)
//                 max=c;
//         }
//         printf("%d\n",max);
//     }
//     return 0;
// }