/*#define CHAR_BIT (8)

int charLeadingOnes (char value){

 int count = 0;  
  for (unsigned int mask = 1 << (CHAR_BIT -1); mask >= 1  ; mask >>= 1 ){
    if ((value & mask) == 0) return count;
    else if ((value & mask)) count ++;
  }
return count;
}*/