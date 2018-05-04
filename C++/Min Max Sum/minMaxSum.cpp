#include <bits/stdc++.h>
#include <deque>

using namespace std;

vector<string> split_string(string);

void miniMaxSum(vector<int> arr) {
    deque <long long int> sumDQ;
    long long int sumTotal = 0;
    long long int sumOnlyFour;
    for (int i=0; i<5; i++) {
        sumTotal += arr[i];
    }
    for (int i=0; i<5; i++) {
        sumOnlyFour = sumTotal - arr[i];
        if (sumOnlyFour > sumDQ.front()) {
            sumDQ.push_front(sumOnlyFour);
        } else if (sumOnlyFour < sumDQ.back()) {
            sumDQ.push_back(sumOnlyFour);
        }
    }
    cout << sumDQ.back() << " " << sumDQ.front() << endl;
}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int arr_itr = 0; arr_itr < 5; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    miniMaxSum(arr);

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
