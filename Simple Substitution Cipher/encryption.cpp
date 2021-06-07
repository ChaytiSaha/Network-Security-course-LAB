//input
//XQKMDBPSETCLORUJVAFWZGHNI 
//QUOTHTHERAVENNEVERMORE.5 

//output
//Enter texts in without space & capital letter.
//Enter cipher text : 
//XQKMDBPSETCLORUJVAFWZGHNI
//Enter text to enceypt : 
//QUOTHTHERAVENNEVERMORE.5
//Encrypted text is: VZUWSWSDAXGDRRDGDAOUAD.5



#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    char plain_txt[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipher_txt, x, ans;
    
    cout<<"Enter texts in without space & capital letter."<<endl;
    cout<<"Enter cipher text : ";
    cin>>cipher_txt; cout<<endl<<cipher_txt;
    cout<<"\nEnter text to enceypt : ";
    cin>>x; cout<<endl<<x;
    
    int flag=0, len = x.size();
    for(int i=0; i<len; i++){
        for(int j=0; j<26; j++){
            if(x[i] == plain_txt[j]){
                ans += cipher_txt[j];
                flag=1;
                break;
            }
        }
        if(flag == 0)
            ans += x[i];
        else 
            flag =0;
    }
    
    cout<<"\nEncrypted text is: "<<ans<<endl;
    
    return 0;
}
