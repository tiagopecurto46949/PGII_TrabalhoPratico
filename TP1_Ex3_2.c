/*


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
  if(charLeadingOnes(a[i]) < 1) return 1;
  
return charLeadingOnes(a[i]);
}

*/