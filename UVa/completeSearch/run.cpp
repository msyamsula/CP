#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void solve(int num, int tc, int size){
    int m=pow(10,size);
    for (int number=num; number<m; number++){
        vi arr;
        for (int d=1; d<=7; d++){
            int dig = pow(10,d);
            // cout << dig << endl;
            if (number%dig == number) break;
            int n = (number%dig)/(dig/10);
            cout << n << endl;
            arr.push_back(n);
        }

        int sz = arr.size();
        cout << sz << endl;
        vi visited(sz, 0);
        int i=0, count = 0;
        bool status = true;
        while(count < sz){
            int next = (i+arr[i])%sz;
            visited[next] = 1;
            count++;
            i = next;
            if (visited[i] != 1) {
                status = false;
                break;
            }
        }

        if (status){
            printf("%i\n", number);
            break;
        }
    }

}

int main(){

    int num, tc=1;
    while(true){
        scanf("%i", &num);
        string a = to_string(num);
        solve(num, tc, a.size());
        if (num==0) break;
        tc++;
    }

    return 0;
}
