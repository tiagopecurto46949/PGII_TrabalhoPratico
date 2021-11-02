#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MASK (0xff)
#define CHAR_BIT (8)
#define MAX_BYTES_UTF8 (4)



int charLeadingOnes (char value){

 int count = 0;  
  for (unsigned int mask = 1 << (CHAR_BIT -1); mask >= 1  ; mask >>= 1 ){
    if ((value & mask) == 0) return count;
    else if ((value & mask)) count ++;
  }
return count;
}


int utf8Length(char a[], int i){

  for(int i = 0; i < MAX_BYTES_UTF8; i++){
    if (!i){
      switch(charLeadingOnes(a[i])){
        case 2:
          printf("Two byte sequence");
        break;
        case 3:
          printf("Three byte sequence");
        break;
        case 4:
          printf("Four byte sequence");
        break;
        default:
          printf("One byte sequence");
        break;
      }
    }
  }
  
return i+1;
}