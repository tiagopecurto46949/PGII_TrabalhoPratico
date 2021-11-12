/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MASK (0xff)
#define CHAR_BIT (8)
#define MAX_BYTES_UTF8 (4)
#define BUFFER_SIZE (1024)
#define MASK (0xff)


void separatorUnify(char str[]){

  int space = 0;
  int k = 0;
  int max = strlen (str);


  for (int i=0; i < max ;i++){
    while (k==0 && i<max && isspace(str[i])) { //remove espaços iniciais
      i++;
    }
    if(str[i] == ' '){      //se o caracter for espaço
      if(!space){          //e a flag estiver a false
        str[k++]=str[i];  //significa que é um espaço após caracter. 
                          //coloca-se na posição disponível
        space = 1;        //flag dos espaços a true
      }
    }
    
    else if(str[i] != ' ' || str[i] != '\n'|| str[i] != '\t'){ //se for caracter printável
      str[k++] = str[i];  //se forem caracteres copia-se para a posição diponível
      space = 0;          // com a flag do espaço a 0
    }
  }
  //Para formatação da string -> remover o espaço final
  (!isspace(str[k-1])) ? (str[k] = '\0') : (str[k-1] = '\0'); 
  //printf("Formatada:|%s|", str);
}

int main(){	
  
	char buffer[BUFFER_SIZE];
  
  printf("\nInsira texto:\n");
	
  while(fgets(buffer, sizeof(buffer), stdin) != NULL){
    separatorUnify(buffer);
    printf("\nFormatado:\n\n");
    fputs(buffer, stdout);
  }

 return 0;
}
*/