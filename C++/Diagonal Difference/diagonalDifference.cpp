#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int diagonalDifference(vector<vector<int>> a) {
    int sum;
    int leftDiagonalSum = 0;
    int rightDiagonalSum = 0;
    int matrixSize = a.size();
    for (int i = 0; i < matrixSize; i++) {
        sum += 
        leftDiagonalSum += a[i][i];
        rightDiagonalSum += a[(matrixSize-1)-i][i];
    }
    sum = abs(leftDiagonalSum-rightDiagonalSum);
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> a(n);
    for (int a_row_itr = 0; a_row_itr < n; a_row_itr++) {
        a[a_row_itr].resize(n);

        for (int a_column_itr = 0; a_column_itr < n; a_column_itr++) {
            cin >> a[a_row_itr][a_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(a);

    fout << result << "\n";

    fout.close();

    return 0;
}
