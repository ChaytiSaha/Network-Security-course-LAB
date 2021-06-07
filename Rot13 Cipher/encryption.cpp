//input
//BOB SACAMANO

//output
//Message can only be alphabetic
//Enter message: 
//BOB SACAMANO
//Encrypted Text: OBO FNPNZNAB


#include <iostream>
using namespace std;

void cipherEncryption(string message){
    
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    int key = 13;
    string encrypText = "";
    
    for(int i = 0; i < message.length(); i++){
        int temp = message[i] + key;
        if(message[i] == 32){
            encrypText += " ";
        } else if(temp > 90){
            temp -= 26;
            encrypText += (char)temp;
        } else 
            encrypText += (char)temp;
    } 

    cout << "Encrypted Text: " << encrypText;
}

int main()
{
    cout << "Message can only be alphabetic" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();
    cout<<endl<<message<<endl;
    cipherEncryption(message);

    return 0;
}
