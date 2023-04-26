#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

/*
TODO: 
- Finish encryption algorithms vigenereAlgorithm() and playfairAlgorithm
- Account for user errors i.e. entering numbers for encrypted message, a letter for key, etc.
- Create loop that will allow user to continue running program after encryption is finished
*/

class Encrypt {
    // Message to be encrypted will be a private member of class Encrypt
    private:
    string originalMessage;
    int key, i;
    
    public:
    string encryptedMessage;
    bool translate; 


    void caesarAlgorithm() {
        cout << "Enter key: "; cin >> key;
        
        // Encryption
        if (!translate) {
        for(i=0; i < originalMessage.size(); i++) {
            encryptedMessage += (originalMessage[i]-'A'+ key) % 26 + 'A';
            }
        }
        
        // Decryption
        if (translate) {
        for(i=0; i<originalMessage.size(); i++){
            encryptedMessage += (originalMessage[i]-'A'-key + 26) %26 + 'A';
            }
        }
    }
    
    void vigenereAlgorithm() {
        // Keyan's code
        cout << "vigenereAlgorithm() successfully called." << endl;
    }
    
    void playfairAlgorithm() {
        // Logan's code
        cout << "playfairAlgorithm() successfully called." << endl;
    }
    
    // Friend class declaration to allow class Text to access private members of class Encrypt
    friend class Text;
    
};



// Inheritance
class Text: private Encrypt {
    
    public:
    int userChoice;
    int userChoice1;
    
    // Get text to be encrypted or decrypted from user
    void setText() {
        cin >> originalMessage;
        
        
        transform(originalMessage.begin(), originalMessage.end(), originalMessage.begin(), ::toupper);
        cout << "Text entered was: " << originalMessage << "\n\n";
    }
    
    
    
    void setTranslate() {
        // Get from user if they want to encrypt or decrypt
        cout << "1. Encrypt" << endl << "2. Decrypt" << endl;
        cout << "Would you like to encrypt or decrypt? (1/2): ";
        cin >> userChoice;
        switch(userChoice) {
            case 1: translate = 0; break; // translate = 0 = encrypt
            case 2: translate = 1; break; // translate = 1 = decrypt
            default: cout << "Invalid input. Terminating program." << endl; break;
            }
    }
        
        
    void setChoice() {
        // Get from user which type of encryption method
        cout << "\n" << "1. Caesar Cipher Encryption" << endl << "2. Vigenere Cipher Encryption" << endl << "3. Playfair Cipher Encryption" << endl;
        cout << "Enter which encryption method you would like to use (1/2/3): ";
        cin >> userChoice1; cout << "\n";
        switch(userChoice1) {
            case 1: caesarAlgorithm(); break;
            case 2: vigenereAlgorithm(); break;
            case 3: playfairAlgorithm(); break;
            default: cout << "Invalid input. Terminating program." << endl; break;
        }
        
    }
    
    void printText() {
        cout << "Encrypted text: " << encryptedMessage << endl;
    }
    
};

// Driver function
int main() {
    Text encryptor;
    
    cout << "Enter the message you would like to be encrypted: ";
    encryptor.setText();
    encryptor.setTranslate();
    encryptor.setChoice();
    encryptor.printText();
} 