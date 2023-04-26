/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string VigenereAlgorithm(string key, string text, bool encrypt) {
    string result = "";
    int keyLen = key.length(), i = 0, j = 0; // include in main function
    char c;
    for (i = 0; i < text.length(); i++) {
        c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char offset = encrypt ? toupper(key[j]) - 'A' : 'Z' - toupper(key[j]) + 1;
            c = (c - base + offset) % 26 + base;
            j = (j + 1) % keyLen;
        }
        result += c;
    }
    return result;
}

int main() {
    string key, original;
    cout << "Enter a word for the encryption key: ";
    cin >> key;
    cout << "Enter a word to encrypt: ";
    cin >> original;
    string encryptedMessage = VigenereAlgorithm(key, original, true);
    string decryptedMessage = VigenereAlgorithm(key, encryptedMessage, false);
    cout << "Original Message: " << original << endl;
    cout << "Encrypted Message: " << encryptedMessage << endl;
    cout << "Decrypted Message: " << decryptedMessage << endl;
    return 0;
}
