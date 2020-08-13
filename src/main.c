/* Data de submissao:13/08/2020
 * Nome: Tony Tian Rui Li
 * RA:206373
 */

#include <stdio.h>

#define TAM_BUFFER 100
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

/*FUNÇÃO PARA DECIFRAR A ENTRADA CRIPTOGRAFADA*/
char decryption(char a, char b) {
  char c;
  if (a>='A' && a<='Z') {
    c = 'A'+('Z'-'A'+1+a-b)%('Z'-'A'+1);
    return c;
  } else return a;
}
/* CODIGO TOTALMENTE APROVEITADO DA REFERENCIA */
int main() {
  int j=0;
  int i=0;
 
  fgets(buffer_entrada, TAM_BUFFER, stdin);

  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {

    buffer_saida[i] = decryption(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }
  buffer_saida[i]='\0';

  printf("%s\n", buffer_saida);
  
  return 0;
}