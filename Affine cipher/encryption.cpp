//input
//Cap WOLFPACK

//output
//Message can only be alphabetic
//Enter message: 
//Cap WOLFPACK
//Encrypted Text: GST QMRBTSGK

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0 
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

void affineCipherEncryption(string message){
    //for this encryption formula y = (7x + 18) mod 26
    
    int g = gcd(7,26);
    
    if(g==1)
    {
        for(int i = 0; i < message.length(); i++){
            message[i] = toupper(message[i]);
        }

        int key = 18;
        string encryptedText = "";
    
        for(int i = 0; i < message.length(); i++){
            if((int)(message[i])==32){
                encryptedText += " ";
                continue;
            }
            int temp = (7 * ((int)(message[i])-65)) + key;

            while(temp >= 26){
                temp -= 26;
            } 
            encryptedText += (char)temp+65;
        } 

        cout << "Encrypted Text: " << encryptedText;
    }
    
    else
        cout<<"Encryption not possible."<<endl;
}

int main()
{
    cout << "Message can only be alphabetic" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();
    cout<<endl<<message<<endl;
    affineCipherEncryption(message);

    return 0;
}

