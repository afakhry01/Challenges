#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    long ndx = 0;
    long count = 0;
    long result = 0;
    int length = s.length();

    // determine how many 'a's are in the string
    for (ndx = 0; ndx < length; ndx++) {
        if (s[ndx] == 'a') {
            count++;
        }
    }

    // how many complete s in n
    result = count * (n / length);
    cout << "result: " << result << endl;

    // partials
    int rem = n % length;
    for(ndx = 0; ndx < rem; ndx++)
    {
        if (s[ndx] == 'a') {
            result++;
            cout << "ndx: " << ndx << endl;
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
