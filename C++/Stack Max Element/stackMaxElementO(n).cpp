#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/* 
 * Follows input instructions to do push, pop and getMaxStackValue operations
 * on a stack.
 * @pre: Operates only on integers, first line of input is number of input lines
 *       (1) push , (2) pop , (3) getMaxStackValue
 * @post: Outputs maximum of stack if requested by user
 */
int main() {
    // Variables Initialization
    stack <long int> ourStack;
    long int nmbrOrders, orderValue;
    int orderCode;
    // First line of input is number of input lines
    cin >> nmbrOrders;
    // Loop through lines of input
    for (long int ndx = 0; ndx < nmbrOrders; ndx++) {
        // Order code (1) push , (2) pop , (3) getMaxStackValue
        cin >> orderCode;
        // Push method
        if (orderCode == 1) {
            // Get the value to push
            cin >> orderValue;
            if (ourStack.empty()) {ourStack.push(orderValue);}
            else {ourStack.push(max(ourStack.top(),orderValue));}
        }
        // Pop method
        else if (orderCode == 2) {
            ourStack.pop();
        }
        // getMaxStackValue method
        else if (orderCode == 3) {
            cout << ourStack.top() << endl;
        }
        // Verification of input
        else {
            cout << "Wrong Input";
        }
    }
    return 0;
}
