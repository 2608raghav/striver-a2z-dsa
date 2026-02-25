/*
Problem: GCD of two numbers
Platform: GeeksforGeeks
Topic: Basic Math
Approach: Euclidean algorithm
Time Complexity: O(log(min(a, b))) where a and b are the two input numbers
Space Complexity: O(1) for the iterative version, O(log(min(a, b))) 
*/

#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}   
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}   

