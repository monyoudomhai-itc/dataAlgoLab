#include <iostream>
using namespace std;

int main()
{
    char text; 
    char vowel[] = {'a','e','i','o', 'u','A','E','I','O','U'};

        cout<<"input Chaaracter : ";cin>>text;
        for (int i = 0 ; i < 10 ; i++)
        {
            if (text == vowel[i])
            {
                cout<<vowel[i]<<" is vowel."<<endl;
                return 0;
            }
        }
        cout<<text<<" is a consonant."<<endl;
   
    
}