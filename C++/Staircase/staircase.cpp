#include <bits/stdc++.h>

using namespace std;

void staircase(int n) {
    for (int height = 1; height <= n; height++) {
        for (int spaces = n-height; spaces > 0; spaces--){
            cout << " ";
        }
        for (int stairs = n-height; stairs < n; stairs++){
            cout << "#";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}