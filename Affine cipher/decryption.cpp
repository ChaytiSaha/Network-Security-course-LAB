//input
//YMCFV SWFUU HO

//output
//Message can only be alphabetic
//Enter message: 
//YMCFV SWFUU HO
//Decrypted Text: MOUNT AINEE RS


#include <iostream>
using namespace std;

void affineCipherDecryption(string message){
    //for this encryption formula y = (7x + 18) mod 26
    //decryption formula is: x = 15 (y + 8) mod 2
    
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    int key = 8;
    string decryptedText = "";
    
    for(int i = 0; i < message.length(); i++){
        if((int)(message[i])==32){
            decryptedText += " ";
            continue;
        }
        int temp = 15 * (((int)(message[i])-65) + key);

        while(temp >= 26){
            temp -= 26;
        } 
        decryptedText += (char)temp+65;
    } 

    cout << "Decrypted Text: " << decryptedText;
}

int main()
{
    cout << "Message can only be alphabetic" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();
    cout<<endl<<message<<endl;
    affineCipherDecryption(message);

    return 0;
}
