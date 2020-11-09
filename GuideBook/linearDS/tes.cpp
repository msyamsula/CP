#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        double A; cin>>A;
        double B; cin>>B;
        double C; cin>>C;
        cout << setw(0) << "0x" << setbase(16) << int(A) << endl;
        cout << setfill('_') << fixed << setprecision(2) << setw(15) << showpos << right << B << endl;
        // printf("%*c%+*.2lf\n", (15-sz-1), '_', sz, B);
        // printf("%.9E\n", C);
        cout << noshowpos << scientific << uppercase << setprecision(9) << C << nouppercase << endl;
    }
    return 0;
}