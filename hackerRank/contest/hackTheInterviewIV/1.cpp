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


string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getStrength' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING password
 *  2. INTEGER weight_a
 */

int getStrength(string password, int weight_a) {
    // Complete the function
    return 0;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string password;
    getline(cin, password);

    string weight_a_temp;
    getline(cin, weight_a_temp);

    int weight_a = stoi(ltrim(rtrim(weight_a_temp)));

    int strength = getStrength(password, weight_a);

    cout << strength << "\n";

    // fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}