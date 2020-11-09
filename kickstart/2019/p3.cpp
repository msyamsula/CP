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
#define modulo 1000000007ll
// #define modulo (15)

ll N,K,x1,ye1,C,D,E1,E2,F;
vl x, y;
vl A;
ll x_gcd, y_gcd, d_gcd;

void gcd_extended(ll a, ll b){
    if (b==0) {
        x_gcd = 1;
        y_gcd = 0;
        d_gcd = a;
        return;
    }
    gcd_extended(b, a%b);
    ll x1 = y_gcd;
    ll y1 = x_gcd - (a/b)*y_gcd;
    x_gcd = x1;
    y_gcd = y1;
}

ll exponent(ll x, ll y){
    x%=modulo;
    ll res = 1;
    while(y>0){
        if(y&1){
            res*=x;
            if(res<0) res+=modulo;
            res%=modulo;
        }
        y = y>>1;
        x *=x; 
        if(x<0) x+=modulo;
        x%=modulo;
    }

    return res%modulo;
}

ll compute(vl subarr, ll exp){
    ll n = subarr.size();
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll e = exponent(i+1, exp);
        ll add = (subarr[i]%modulo)*(e%modulo); add%=modulo;
        ans += add;
        if (ans < 0) ans+=modulo;
        ans %= modulo;
    }

    return ans%modulo;
}

void solve(){
    cin>>N>>K>>x1>>ye1>>C>>D>>E1>>E2>>F;
    // cout << F << endl;
    A.resize(0); x.resize(0); y.resize(0);
    A.assign(N, 0); x.assign(N, 0); y.assign(N, 0);
    A[0] = (x1%F+ye1%F)%F;
    x[0] = x1; y[0]=ye1;
    for(ll i=1; i<N; i++){
        x[i] = C*x[i-1]; x[i]%=F; x[i]+=D*y[i-1]; x[i]%=F; x[i]+=E1; x[i]%=F;
        y[i] = D*x[i-1]; y[i]%=F; y[i]+=C*y[i-1]; y[i]%=F; y[i]+=E2; y[i]%=F;
        // x[i] = C*x[i-1]+D*y[i-1]+E1; x[i]%=F;
        // y[i] = D*x[i-1]+C*y[i-1]+E2; y[i]%=F;
        A[i] = (x[i]%F+y[i]%F)%F;
    }

    // for(ll num : A){
    //     cout << num << ' ';
    // }
    // cout << endl;

    vl coef; coef.assign(N+1, 0);
    coef[1]=K;
    for(ll i=2; i<=N; i++){
        ll numerator = exponent(i,K)-1; numerator%=modulo;
        numerator *= i; numerator%=modulo;
        ll denumerator = (i-1);
        gcd_extended(denumerator, modulo);
        if (x_gcd < 0) x_gcd+=modulo;
        x_gcd%=modulo;
        ll res = numerator*x_gcd; res%=modulo;
        coef[i] = res;
    }

    // for(ll num : coef){
    //     cout << num << ' ';
    // }
    // cout << endl;

    vl ps_coef; ps_coef.assign(N+2, 0);
    for(ll i=0; i<N+1; i++){
        ps_coef[i+1] = ps_coef[i]+coef[i];
        ps_coef[i+1]%=modulo;
    }

    // for(ll num : ps_coef){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(ll num : A){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll power = 0;

    for(ll i=0; i<N; i++){
        ll idx = i+1;
        // cout << idx << endl;
        ll add = A[i]*(N-i); add%=modulo;
        add *= ps_coef[idx+1]-ps_coef[1]; add%=modulo;
        power += add; power%=modulo;
    }

    cout << power << endl;

    // // for (ll k=1; k<=K; k++){
    // //     for(ll size = 1; size<=N; size++){
    // //         for(ll start=0; start<=N-size; start++){
    // //             vl temp(A.begin()+start, A.begin()+start+size);
    // //             // for(ll num : temp){
    // //             //     cout << num << ' ';
    // //             // }
    // //             // cout << endl;
    // //             // cout << "exp " << k << ' ' << compute(temp, k) << endl;
    // //             power += compute(temp, k);
    // //             if (power < 0) power+=modulo;
    // //             power %= modulo;
    // //         }
    // //     }
    // // }

    // cout << power << endl;
}

int main(){
    // vl a(1000, 1000);
    // cout << compute(a, 20) << endl;
    // cout << exponent(999, 20) << endl;
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    // ll a = 3, b = 8;
    // gcd_extended(a,b);
    // cout << d_gcd << endl;
    // if (x_gcd < 0) x_gcd += b;
    // if (y_gcd < 0) y_gcd += a;
    // cout << a << '*' << x_gcd << " + " << b << '*' << y_gcd << endl;
    // cout << ((1ll<<63)-1)*10 << endl;

    return 0;
}
