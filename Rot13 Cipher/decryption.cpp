//input
//OBO FNPNZNAB

//output
//Message can only be alphabetic
//Enter message: 
//OBO FNPNZNAB
//Decrypted Text: BOB SACAMANO

#include <iostream>
using namespace std;

void cipherDecryption(string message){

    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    int key = 13;
    string decrypText = "";

    for(int i = 0; i < message.length(); i++){
        int temp = message[i] - key;
        if(message[i] == 32){
            decrypText += " ";
        } else if(temp < 65){
            temp += 26;
            decrypText += (char)temp;
        } else 
            decrypText += (char)temp;
    } 

    cout << "Decrypted Text: " << decrypText;
}


int main()
{
    cout << "Message can only be alphabetic" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();
    cout<<endl<<message<<endl;
    cipherDecryption(message);

    return 0;
}
