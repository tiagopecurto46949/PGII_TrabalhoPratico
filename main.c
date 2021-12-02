#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHAR_BIT (8)
#define FIRST_BYTE_UTF  (0xc3)
#define FIRST_LOWERCASE (0xa0)
#define CONVR_UPTOLOW  (0x20)
#define MAX_CHARS_LINE (3250)
//FALTA A PONTUAÇÃO


int charLeadingOnes (char value){

 int count = 0;  
  for (unsigned int mask = 1 << (CHAR_BIT -1); mask >= 1  ; mask >>= 1 ){
    if ((value & mask) == 0) return count;
    else if ((value & mask)) count ++;
  }
  return count;
}

char *lineSplitFirst(char line[]){

  if (strlen(line)==0) return NULL;

  char delimeters[] = {' ', '\t', '\n', '.', ',', ';', '!', '?', '"'};

  return strtok(line, delimeters);
}

char *lineSplitNext(){

  char delimeters[] = {' ', '\t', '\n', '.', ',', ';', '!', '?', '"'};

  return strtok(NULL,delimeters);
}

int utf8SetLower(char* symb){

  if (*symb == (char)FIRST_BYTE_UTF){
    if(*(symb + 1) < (char)FIRST_LOWERCASE){
      *(symb+1) = *(symb+1) + CONVR_UPTOLOW;
    }
  }
  else if( *symb >= 'A' && *symb <= 'Z' )
    *symb = *symb + CONVR_UPTOLOW;
  
  return charLeadingOnes(*symb);
}


char* firstChar(char *mixWord){
  while ((!(*mixWord>='A' && *mixWord<='Z') && !(*mixWord>='a' && *mixWord <='z') && !(*mixWord == (char)FIRST_BYTE_UTF))){
      ++mixWord;
  }
  return mixWord;
}

char *normalize( char *word){

  char *ptrFirst = firstChar(word);
  int endOfString= (sizeof(word)/sizeof(char)); 
  int j = 0;
  int flagSpecialChar = 0;

  for(int i=0; i<strlen(word); i++){

    if (ptrFirst[i] == '-' || ptrFirst[i] == '\'' ){
      if(!flagSpecialChar) {
        ptrFirst[j++] = ptrFirst[i];
        flagSpecialChar = 1;
      }
    }

    if( isalnum(ptrFirst[i])){
      ptrFirst[j++] = tolower(ptrFirst[i]);
    }

    if(ptrFirst[i] == (char)FIRST_BYTE_UTF){
      utf8SetLower(ptrFirst+i);
      ptrFirst[j++] = ptrFirst[i];
      ptrFirst[j++] = ptrFirst[i+1];
    }
    else continue;
  }
  ptrFirst[j] = '\0';

  return ptrFirst;
}


int main(int argc, char** argv){

  char line[MAX_CHARS_LINE];

  FILE *fpRead=fopen(argv[1] , "r");
  FILE *fpWrite=fopen("Texto.txt" , "w");
  

   if(fpRead == NULL) {
      perror("Error opening ");
      return(-1);
   }
   if(fpWrite == NULL) {
      perror("Error opening ");
      fclose(fpRead);
      return(-1);
   }

   while( fgets (line, MAX_CHARS_LINE, fpRead) != NULL ) {

      char* word = lineSplitFirst(line);
      
      while ( word != NULL){
        fputs(normalize(word), fpWrite);
        fputs("\n", fpWrite);
        word = lineSplitNext();
      }
   }

   fclose(fpWrite);
   fclose(fpRead);

  /*
  do{
    printf("CHOOSE AN OPTION:\n");
		printf("a : alphabetic order\n");
    printf("w <word>: word frequency\n");
		printf("+ <number> : most frequent words \n");
		printf("- <number> : least frequent words\n");
		printf("q : quit\n");
		
		printf("\n> ");
		
		char option;
		
		
		//option = getMenuOption();
		
		//switch(option)

  }
  while( getchar() == 'q')
  */


return 0;
}