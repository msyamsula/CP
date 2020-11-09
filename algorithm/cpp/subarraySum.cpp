#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[11] = {10, 4, 5, 6, 7, 2, 3, 9, 0, 7, 1};
    int* a = arr;
    int* b = arr;

    int target = 8;
    int sum = *a;
    for (int i=0; i<22; i++){
        if (sum == target){
            break;
        } else if (sum > target){
            sum -= *a;
            a++;
        } else if (sum < target) {
            b++;
            sum += *b;
        }

        cout << "sum " << sum << endl;
    }

    cout << *a << ' ' << *b << ' ' << sum << endl;

    return 0;
}