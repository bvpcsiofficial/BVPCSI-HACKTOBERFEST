#include<iostream> 
using namespace std; 
   
/* 
Program to convert characters  
of a string to opposite case
*/ 
void convertOpposite(string &str) { 
    int n = str.length(); 
       
    for (int i=0; i<n; i++){ 
        if (str[i]>='a' && str[i]<='z'){ 
            str[i] = str[i] - 32; 
        }else if(str[i]>='A' && str[i]<='Z'){ 
            str[i] = str[i] + 32; 
        }
    } 
} 
   
// Driver Code
int main() 
{ 
    string str = "This is tHe Text"; 
    convertOpposite(str); 
    cout << str; 
    return 0; 
} 
