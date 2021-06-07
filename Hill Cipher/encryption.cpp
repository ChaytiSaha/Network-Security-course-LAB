 //online c++ compiler
    //https://www.tutorialspoint.com/compile_cpp_online.php
    
    #include<stdio.h>
    #include<iostream>
    using namespace std;

    int check(int x,int key_length)
    {
        if (x % key_length == 0)
            return 0;
        int a = x / key_length;
        int b = key_length * (a + 1);
        int c = b - x;
        return c;
    }

     

    int main()
    {
        int l, i, j,temp1,key_length,key1;
        int k[3][3], p[3][1], c[3][1];
        char ch,key;
        
        cout<<"Enter the key matrix length: ";
        cin>>key_length;
        
        cout<< "Enter key text or key matrix. Press 'Y' for key text, 'N' for key matrix.";
        cin>>key;
     
        if(key=='Y'){
            for (i = 0; i < 3; ++i){
                for (j = 0; j < 3; ++j){
                    scanf("%c", &ch);
                    if (65 <= ch && ch <= 91)
                        k[i][j] = (int) ch % 65;
                else
                    k[i][j] = (int) ch % 97;
            }
        }
        }
        
        else{
            for (i = 0; i < 3; ++i){
                for (j = 0; j < 3; ++j){
                    cin>>key1;
                    k[i][j] = key1;
            }
        }
        }
        
        cout<<endl;
        for (i = 0; i < 3; ++i){
            for (j = 0; j < 3; ++j){
                cout << k[i][j] << "  ";
            }
            cout << endl;
        }

        cout << "\nEnter the length of string to be encoded(without spaces). ";
        cin >> l;

        temp1 = check(l,key_length);
        if (temp1 > 0)
            cout << "You have to enter " << temp1 << " xtra characters.";

        char pi[l + temp1];
        cout << "\nEnter the string. ";

        for (i = 0; i < l + temp1; ++i){
            cin >> pi[i];
        }

        int temp2 = l;
        int n = (l + temp1) / key_length;
        int temp3;
        int flag = 0;

        int count;
        cout << "\n\nThe encoded cipher is : ";

        while (n > 0){
            count = 0;

            for (i = flag; i < flag + key_length; ++i){
                if (65 <= pi[i] && pi[i] <= 91)
                    temp3 = (int) pi[i] % 65;
                else
                    temp3 = (int) pi[i] % 97;
                p[count][0] = temp3;
                count = count + 1;
            }
            
            int k1;
            for (i = 0; i < key_length; ++i)
                c[i][0] = 0;

            for (i = 0; i < key_length; ++i){
                for (j = 0; j < 1; ++j){
                    for (k1 = 0; k1 < key_length; ++k1)
                        c[i][j] += k[i][k1] * p[k1][j];
                }
            }

            for (i = 0; i < key_length; ++i){
                c[i][0] = c[i][0] % 26;
                printf("%c ", (char) (c[i][0] + 65));
            }
            
            n = n - 1;
            flag = flag +key_length;
        }
    }

//input
//3
//N
//2 4 5
//9 2 1
//3 17 7
//12
//ATTACKATDAWN


//output
//Enter the key matrix length: Enter key text or key matrix. Press 'Y' for key text, 'N' for key matrix.
//2  4  5  
//9  2  1  
//3  17  7  

//Enter the length of string to be encoded(without spaces). 
//Enter the string. 

//The encoded cipher is : P F O G O A N P G X F X
