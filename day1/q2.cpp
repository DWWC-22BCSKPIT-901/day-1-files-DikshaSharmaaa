#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Input the number
    int count = 0;

    while (n > 0) {
        n /= 10; // Remove the last digit
        count++; // Increment the digit count
    }

    cout << count << endl; // Output the total number of digits
    return 0;
}