#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
    
    else if(isprint(str[i])){ //se for caracter printável
      str[k++] = str[i];  //se forem caracteres copia-se para a posição diponível
      space = 0;          // com a flag do espaço a 0
    }
  }
  //Para formatação da string -> remover o espaço final
  (!isspace(str[k-1])) ? (str[k] = '\0') : (str[k-1] = '\0'); 
  printf("Formatada:|%s|", str);
}

/*BIBLIOGRAFIA: 
https://www.techiedelight.com/remove-extra-spaces-string/

*/