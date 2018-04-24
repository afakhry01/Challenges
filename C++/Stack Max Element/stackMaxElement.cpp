#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/* 
 * Find the maximum value of a single integer inside a stack
 * @pre: Operates only on integers
 * @param: A stack of integers
 * @post: returns an integer
 */
int getMaxStackValue(stack <int> aStack) {
    // Variables Initialization
    int maxNumber = 0;
    int curNumber;
    stack <int> tempStack;
    // Copies main stack to temp stack and finds maximum value
    while (!aStack.empty()) {
        curNumber = aStack.top();
        tempStack.push(curNumber);
        if (curNumber > maxNumber) {
            maxNumber = curNumber;
        }
        aStack.pop();
    }
    // Get main Stack values back
    while (!tempStack.empty()) {
        aStack.push(tempStack.top());
        tempStack.pop();
    }
    
    return maxNumber;
}

/* 
 * Follows input instructions to do push, pop and getMaxStackValue operations
 * on a stack.
 * @pre: Operates only on integers, first line of input is number of input lines
 *       (1) push , (2) pop , (3) getMaxStackValue
 * @post: Outputs maximum of stack if requested by user
 */
int main() {
    // Variables Initialization
    stack <int> ourStack;
    int nmbrOrders, orderCode, orderValue;
    // First line of input is number of input lines
    cin >> nmbrOrders;
    // Loop through lines of input
    for (int ndx = 0; ndx < nmbrOrders; ndx++) {
        // Order code (1) push , (2) pop , (3) getMaxStackValue
        cin >> orderCode;
        // Push method
        if (orderCode == 1) {
            // Get the value to push
            cin >> orderValue;
            ourStack.push(orderValue);
        }
        // Pop method
        else if (orderCode == 2) {
            ourStack.pop();
        }
        // getMaxStackValue method
        else if (orderCode == 3) {
            cout << getMaxStackValue(ourStack) << endl;
        }
        // Verification of input
        else {
            cout << "Wrong Input";
        }
    }
    return 0;
}
