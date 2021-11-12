/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHAR_BIT (8)

int charLeadingOnes (char value){

 int count = 0;  
  for (unsigned int mask = 1 << (CHAR_BIT -1); mask >= 1  ; mask >>= 1 ){
    if ((value & mask) == 0) return count;
    else if ((value & mask)) count ++;
  }
return count;
}

int main(){
  for(int i = 0 ; i < 0xFF ; i++){
      printf(" %x tem %d 1s\n", i,charLeadingOnes(i));
    }
    return 0;
}
*/