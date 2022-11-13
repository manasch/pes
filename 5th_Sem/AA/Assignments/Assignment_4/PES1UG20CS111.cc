#include <iostream>
#include <utility>
#include <string>
using namespace std;

// Do not change
const int P = 53;
const int Q = 59;
const int E = 3;

long long pow(int base, int exp) {
    long long result = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}

string encryptLetter(char c) {
    int N = P * Q;
    int M = int(c);
    long long C = pow(M, E) % N;

    return to_string(C);
}

string encrypt(string message) {
    string ans = "";
    for (auto i: message) {
        ans += encryptLetter(i);
        ans += " ";
    }
    return ans;
}

int main() {
    string message;
    getline(cin, message);
    cout << encrypt(message) << "\n";
    return 0;
}
