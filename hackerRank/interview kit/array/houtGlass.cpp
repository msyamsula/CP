#include <bits/stdc++.h>

using namespace std;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
typedef vector<vector<int> > vvi;
typedef vector<int> vi;

// Complete the hourglassSum function below.
int rectangleSum(vvi ps, int y, int x, int ys=0, int xs=0){
    int sum =0;
    f(i,ys,y+1,1){
        // f(j,0,x+1,1){
        sum += ps[i][x+1]-ps[i][xs];
        // }
    }

    return sum;

}


vvi prefixSum(vvi a, int s=6){
    vvi ps;
    f(i,0,s,1){
        int sum=0;
        vi psRow;
        psRow.push_back(0);
        f(j,0,s,1){
            sum += a[i][j];
            psRow.push_back(sum);
        }
        ps.push_back(psRow);
    }

    return ps;
}

void showMat(vvi a, int y=6, int x=6){
    f(i,0,y,1){
        f(j,0,x,1){
            cout << a[i][j] << " \n"[j==x-1];
        }
    }
}

int hourglassSum(vector<vector<int>> arr, vvi ps) {
    int max = -(1<<31);
    f(i,0,4,1){
        f(j,0,4,1){
            int x=j+2;
            int y=i+2;
            int value = rectangleSum(ps,y,x,i,j) - arr[i+1][j] - arr[i+1][j+2];
            // printf("%i %i %i\n", arr[i+1][j], arr[i+1][j+2], value+arr[i+1][j]+arr[i+1][j+2]);
            // printf("%i %i %i %i %i\n",y,x,i,j,value);
            if (value>max){
                max = value;
            }
        }
    }
    return max;
}


int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vvi ps = prefixSum(arr);
    // cout << endl;
    // showMat(ps,6,7);
    // cout << endl;

    // cout << rectangleSum(ps, 2, 5, 0, 3) << endl;

    int result = hourglassSum(arr, ps);

    cout << result << endl;
    // fout << result << "\n";

    // fout.close();

    return 0;
}
