#include<bits/stdc++.h>
using namespace std;

int main(){
    double a = 2;
    double b = 3;
    double c = a/b;
    cout << setprecision(3) << fixed << c << endl;
}

// #define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
// #define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
// typedef vector<int > vi;
// typedef map<string, string> mss;
// typedef vector< vector<int> > vvi;
// typedef vector<string> vs;


// void solve(int sz){
//     string input;
//     vi distance;
//     int min = (1<<30);
//     int idx = 0;
//     while(idx < sz){
//         getline(cin, input);
//         // cout << input << endl;
//         int is = strstr(input.c_str(), "X ") - &input[0];
//         int ie = strstr(input.c_str(), " X") - &input[0];
//         ie++;
//         int dist = ie - is - 1;
//         distance.push_back(dist);
//         if (dist < min){
//             min = dist;
//         }
//         idx++;
//     }

//     int sum = 0;
//     vi::iterator i;
//     iter(distance, i){
//         sum += *i-min;
//     }

//     cout << sum << endl;

// }


// int main(){
//     int sz;
//     scanf("%i", &sz);
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     while(sz != 0){
//         solve(sz);
//         scanf("%i", &sz);
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
    

//     return 0;
// }