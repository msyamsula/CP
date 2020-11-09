#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
typedef vector<int> vi;

void show(vi a){
    int s=a.size();
    f(i,0,s,1){
        cout << a[i] << " \n"[i==s-1];
    }
}

vi leftRotate(vi a, int lr){
    int s = a.size();
    int shift = lr%s;
    int idx;
    vi result;
    f(i,0,s,1){
        idx = (i+shift);
        if (idx>=s){
            idx -= s;
        }

        result.push_back(a[idx]);
    }

    return result;
}

int main(){
    int n, lr;
    scanf("%i %i", &n, &lr);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    int value;
    string arr;
    getline(cin, arr);
    stringstream ss(arr);
    
    vi strArr;
    while(ss>>value){
        strArr.push_back(value);
    }

    vi leftRot = leftRotate(strArr, lr);

    show(leftRot);

    return 0;
}