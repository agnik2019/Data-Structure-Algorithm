//Reverse the bits of an 32 bit unsigned integer A.

unsigned int Solution::reverse(unsigned int n) {
   unsigned int reverse = 0;
   int pos = 31;
   while(pos >= 0 && n){
       if(n&1) reverse = reverse | (1<<pos);
       n>>= 1;
       pos--;
   }
   return reverse;
}
