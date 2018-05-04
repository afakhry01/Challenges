#include <bits/stdc++.h>
#include <stack>

using namespace std;

vector<string> split_string(string);

int birthdayCakeCandles(int n, vector<int> ar) {
    stack <int> tallestCandles;
    int nmbrTallestCandles = 0;
    // Loop through all the candles
    for (int i=0; i<n; i++) {
        // Push candles of the same height to the stack or if the stack is empty
        if (tallestCandles.empty() || ar[i] == tallestCandles.top()) {
            tallestCandles.push(ar[i]);
        // If taller candle is found, stack is cleared and new candle height is added
        } else if (ar[i] > tallestCandles.top()) {
            tallestCandles = stack<int>();
            tallestCandles.push(ar[i]);        
        }
    }
    // Count the number of tallest candles
    while (!tallestCandles.empty()) {
        nmbrTallestCandles++;
        tallestCandles.pop();
    }
    return nmbrTallestCandles;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int ar_itr = 0; ar_itr < n; ar_itr++) {
        int ar_item = stoi(ar_temp[ar_itr]);

        ar[ar_itr] = ar_item;
    }

    int result = birthdayCakeCandles(n, ar);

    fout << result << "\n";

    fout.close();

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
