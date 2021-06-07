//input
//GILLIGAN
//ATHREEHOURTOUR. 

//output
//Enter texts in without space & capital letter.
//Enter keyword : 
//GILLIGAN
//Keyword after removing repeatation: GILAN
//So, Cipher text: GILANBCDEFHJKMOPQRSTUVWXYZ
//Enter text to encrypt: 
//ATHREEHOURTOUR.
//Encrypted text is: GTDRNNDOURTOUR.



#include <bits/stdc++.h> 
using namespace std; 
  
string removeDuplicate(string str, int n) 
{
   string str1;
   for (int i=0; i<n; i++) { 
    for (int j=i+1; j<n; j++)  
        if (str[i] == str[j] and str[j]!='_')
            str[j]='_';   
   }
   
   for(int i=0;i<n;i++){
        if(str[i]!='_')
            str1 +=str[i];
   }
     
   return str1; 
} 
 
string cipher(string str) 
{ 
   string str1=str;
   string str2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int len1=str1.size(), len2=str2.size();
   for (int i=0; i<len1; i++) { 
    for (int j=0; j<len2; j++)  
        if (str1[i] == str2[j])
            str2[j]='_';   
   }
   
   for(int i=0;i<len2;i++){
        if(str2[i]!='_')
            str1 +=str2[i];
   }
     
   return str1; 
}
  
int main() 
{ 
    string plain_txt="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipher_txt, x, ans,keyword;
    
    cout<<"Enter texts in without space & capital letter."<<endl;
    
    cout<<"Enter keyword : ";
    cin>>keyword; cout<<endl<<keyword;
    int n = keyword.size(); 
    keyword = removeDuplicate(keyword, n);
    cout<<"\nKeyword after removing repeatation: "<<keyword;
    cipher_txt = cipher(keyword);
    cout<<"\nSo, Cipher text: "<<cipher_txt;
    
    cout<<"\nEnter text to encrypt: ";
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
