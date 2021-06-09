#include<iostream>
using namespace std;
int getBit(int n, int pos)
{
    return (n&(1<<pos) != 0);
}
int setBit(int n, int pos)
{
    return n | (1<<pos);
}
int clearBit(int n, int pos)
{
    int mask = ~(1<<pos);
    return n& mask;
}
int updateBit(int n, int pos, int value){
    //we first clear the bit and then set the bit
    int mask = ~(1<<pos);
    n= n& mask;
    return n|(value<<pos);
}
int main(){
    cout<<getBit(5,2)<<endl;
}