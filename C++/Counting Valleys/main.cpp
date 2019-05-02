#include <bits/stdc++.h>
#include <map>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    map<char, int> map;
    char dir_array[s.length()+1];
    bool is_down = false;
    long elev_count = 0;
    int num_valley = 0;

    // populate the hash map
    map['U'] = 1;
    map['D'] = -1;

    // convert string to array of chars
    strcpy(dir_array, s.c_str());

    // parse string
    for (int ndx = 0; ndx < n; ndx++) 
    {
        elev_count += map[dir_array[ndx]];
        if(elev_count < 0)
        {
            is_down = true;
        }
        else if(elev_count == 0 && is_down)
        {
            num_valley++;
            is_down = false;
        }
    } 
    return num_valley;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
