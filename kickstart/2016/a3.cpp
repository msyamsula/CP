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
#define re (long double) 1/1000000000000
vl arr;

// hitung f(x) di x tertentu -- x itu 1+r kalo di soal
long double compute(long double x){
    ll n=arr.size();
    long double ans = 0;
    for(ll i=0; i<n; i++){
        ans *= x;
        ans += arr[i];
    }

    return ans;
}

// karena soal menjamin akar cuma ada 1, maka
// cari akar lewat metode bracketing -- divide and conquer -- akar akan ada di bagian f(a)*f(b)<0, saat pindah tanda 
// cari akar di rentang x=a,x=b -- pemanggilan awal ada di rentang 0-2
long double root(long double a, long double b){
    long double mid = (a+b)/2;
    if (a==b) return a; // kalo merujuk ke satu nilai, base case
    if ( abs(a-b) <= re) return mid; // udah sempit banget jaraknya (lebih kecil dari error relatif)
    long double p = compute(a), q = compute(b), m = compute(mid);
    if (p==0) return a; // akar di ujung a
    if (q==0) return b; // akar di ujung b;
    if (m == 0) return mid; // akar di tengah
    else if(p*m < 0) return root(a, mid); // rekursif ke bagian kiri
    else if (p*m > 0) return root(mid,b); // rekursif ke bagian kanan


    return 0; // harusnya program gak akan pernah ke sini
}

void solve(){
    ll n; cin>>n;
    n++;
    // tampung nilai koefisien di variabel arr
    arr.resize(0); arr.assign(n, 0);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    arr[0] = -arr[0];

    //langusng cari root, x aku buat 1+r, jadi buat cari r tinggal root-1
    cout << fixed << setprecision(12) << root(0,2)-1 << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
