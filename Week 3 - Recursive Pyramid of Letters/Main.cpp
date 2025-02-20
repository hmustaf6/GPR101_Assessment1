#include <iostream>
#include <iomanip>
using namespace std;

void printRow(int current) {
    for (char ch = 'A'; ch < 'A' + current; ch++) {
        cout << ch;
    }
    for (char ch = 'A' + current - 2; ch >= 'A'; ch--) {
        cout << ch;
    }
    cout << endl;
}

void pyramid(int n, int current = 1) {
    if (current > n) return;

    int spaces = n - current;
    cout << string(spaces, ' ');

    printRow(current);

    pyramid(n, current + 1);
}

int main() {
    int number;
    cout << "What number you want for the amount of rows for your pyramid? Steep & take a guess: ";
    cin >> number;
    
    if (number <= 0) {
        cout << "A pyramid can only be made by more than a one digit or at least one digit for an output, a zero means no pyramid & a negative number is invalid please type in a positive number." << endl;
    } else {
        pyramid(number);
    }
    
    return 0;
}
