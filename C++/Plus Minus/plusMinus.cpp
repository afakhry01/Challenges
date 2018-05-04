#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void plusMinus(vector<int> arr) {
    float positiveFraction = 0.0; 
    float negativeFraction = 0.0; 
    float zeroFraction = 0.0;
    int arraySize = arr.size();
    for (int i = 0; i < arraySize; i++) {
        if (arr[i] > 0) {
            positiveFraction += (float)1/arraySize;
        }
        else if (arr[i] < 0) {
            negativeFraction += (float)1/arraySize;
        }
        else {
            zeroFraction += (float)1/arraySize;
        }
    }
    cout << positiveFraction << endl << negativeFraction << endl << zeroFraction;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
