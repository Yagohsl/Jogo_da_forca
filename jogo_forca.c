//jogo da forca
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char resp[51], palUser[51], letra, palAtual[51], aux[51];
    int nResp, escolha, erro = 0;
    
    printf("Digite a palavra a ser adivinhada: ");
    fgets(resp,51,stdin);
    resp[strlen(resp)-1] = '\0';
    
    
    
    system("clear");
    printf("---Jogo da Forca---\n\n");

    
    nResp = strlen(resp);
    
    for (int i = 0; i<nResp;i++){
        if(resp[i] == ' '){
            palAtual[i] = ' ';
        }else
	   palAtual[i] = '-';
	    
	    
    }
    printf("%s",palAtual);
    
    while(strcmp(palAtual, resp) !=0 && (erro<6)){
	printf("\n\nEscolha '1' para adivinhar uma letra e '2' para adivinhar a palavra: ");
	scanf("%d",&escolha); getchar();
	
	switch (escolha){
	case 1:
	    
	  scanf("%c",&letra);
	  
	  strcpy(aux, palAtual);

	  
	  for (int i = 0;i<nResp;i++){
	      
	      if(letra == resp[i]){
	      palAtual[i] = letra;

	      }
      }
	if (strcmp(palAtual, aux) == 0) {
	    
        printf("Não há esta letra\n");
        erro++;
        printf("Vidas = %d\n", 6 - erro);
	      
	  }
	  if (strcmp(palAtual, resp) == 0) {
	    printf("Parabéns, voce acertou!\n");
	    
	}
	break;
	case 2:
    	fgets(palUser, 51, stdin);
    	palUser[strlen(palUser)-1] = '\0';
    	
    	if (strcmp(palUser, resp) == 0) {
    	    printf("\nParabéns, você acertou!\n");
    	    strcpy(palAtual, resp);
    	    
    	}else{
    	    printf("Palavra errada!\n");
    	    erro++;
            printf("Vidas = %d\n", 6 - erro);
    	}
    	break;
    	
    	default:
    	printf("\nDigite um valor válido\n");
	}
    if(erro == 6){
	    printf("\nVocê perdeu!\nA palavra era = %s\n",resp);
	}else
	  printf("\n%s\n",palAtual);
    }
    
    return 0;
}
