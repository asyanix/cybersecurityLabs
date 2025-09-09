#include <iostream>
#include <string>

using namespace std;

string encryptionMethod(const string input) {
    string result;
    
    for (char ch : input) {
        if (!result.empty() && result.back() == ch) {
            result.pop_back();
        } else {
            result.push_back(ch);
        }
    }
    return result;
}

int main() {
    string input;
    cin >> input;
    
    // wwstdaadierfflitzzz -> stierlitz
    string output = encryptionMethod(input);
    cout << output << "\n";

    return 0;
}