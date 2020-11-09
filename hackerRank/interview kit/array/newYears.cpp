#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
typedef vector<int> vi;
typedef map<int, int> mii;

void min(vi a){
    int sum=0 ;
    int N = a.size();
    f(i,0,N-1,1){
        int value = a[i];
        if (a[i]==i+1){
            continue;
        }

        int currBribe=0;
        f(j,i+1,N,1){
            if (a[j]<value){
                currBribe++;
            }

            if (currBribe>2){
                printf("Too chaotic\n");
                return;
            }
        }
        sum += currBribe;
    }

    printf("%i\n", sum);
}

void solve(){
    int N;
    scanf("%i", &N);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input;
    getline(cin, input);
    stringstream ss(input);
    int value;
    vi arr;
    int idx=0;
    while(ss>>value){
        arr.push_back(value);
        // arr[idx] = value;
        // cout << arr[idx] << endl;
        // idx++;
    }

    min(arr);
}

int main(){
    int T;
    scanf("%i", &T);
    f(t,0,T,1){
        solve();
    }

    return 0;
}