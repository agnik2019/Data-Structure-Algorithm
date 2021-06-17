#include<iostream>
using namespace std;
void printAllBinaryHelper(int digit, string sofar){
    if(digit == 0)
        cout<<sofar<<endl;
    else{
        printAllBinaryHelper(digit-1, sofar+"0");
        printAllBinaryHelper(digit-1, sofar+"1");
    }
}
void printAllBinary(int numDigits)
{
    printAllBinaryHelper(numDigits,"");
}
int main(){
    int n; 
    cout<<"Enter the length of binary strings to generate ";
    cin>>n;
    printAllBinary(n);
}