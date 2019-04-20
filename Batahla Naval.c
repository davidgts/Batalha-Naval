#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#define MAX 9
void menu();//Fun��o menu ultilizada pra selecionar a op��o do usuario e chamar a fun��o nescessaria para dar prosseguimento a aplica��o ou sair do programa
void gameLocal();//Faz todo o controle do jogo local
void limpaMatriz(char x[MAX][MAX]);// Fun��o que faz a matriz receber seus valores como *
void apresentaTabuleiro(char x[MAX][MAX],int player);// mostra todos os dados da matriz de forma tabulada
void setBarcos(char x[MAX][MAX],int player);// Coloca os elementos no tapuleiro
int regras(char x[MAX][MAX],int l,int c,char opc,int qtdElementos);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

main(){
menu();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void menu(){
   setlocale(LC_ALL, "Portuguese");
   int opc;//armazenar� a op��o do usuario
   do {
     system("cls");
     printf("|------------------------------------------|\n");
     printf("|              Batalha Naval               |\n");
     printf("|                [1]-Local                 |\n");
     printf("|                [2]-Multiplayer           |\n");
     printf("|                [3]-Instru��es            |\n");
     printf("|                [4]-sobre                 |\n");
     printf("|                [0]-sair                  |\n");
     printf("|------------------------------------------|\n");
     printf("Opc:");
     scanf("%d",&opc);
     system("cls");
     switch(opc){ //inicializar� a aplica��o selecionada pelo usuario
       case 1:{
         gameLocal();
         system("pause");
         break;
             }
       case 2:{

         break;
		      }
       case 3:{
         printf("|Instru��es iniciais| \n\n");
         printf("1-Cada jogador distribui suas embarca��es pelo tabuleiro.\nIsso � feito informando qual embarca��o e quais celulas\nos X s�o referentes �s suas embarca��es. \n\n");
         printf("2-N�o � permitido que 2 embarca��es se toquem\ndeve sempre existir um espa�o de uma celula entre elas\n\n");

		 printf("|Jogando| \n\n");
		 printf("Na sua vez de jogar, seguir� o seguinte procedimento:\n\n");
		 printf("1-Cada jogador far� um disparo por v�z,\nindicando as coordenadas em linhas e colunas do tabuleiro inimigo\n\n");
		 printf("2- A cada tiro acertado em um alvo,sera marcado no tabuleiro do oponente\num icone para que possa informar quando a enbarca��o for afundada.\n\n");
		 printf("3- O jogador vence quando destruir todas as suas embarca��es do inimigo\n\n");

         system("pause");
		 break;
		      }
       case 4:{
		 	     printf("Este software foi desenvolvido como objetivo de ser um\nProjeto para a disciplina de-Algoritmo e Programa��o Estruturada\n");
		 	     printf("Onde � nescessario criar um jogo de batalha naval\nultilizando alguns dos assunto dados em sala de aula\n\n");
		 	     printf("--------------------------------------------------------------------\n");

		         printf("Este Programa foi desenvolvido pela equipe:\n");
		 	     printf("David Machado - Matricula 20161380029\n");
		 	     printf("Jorge Gomes - Matricula 20161380001\n");
		 	     printf("--------------------------------------------------------------------\n");
		 	     printf("                                                    Vers�o 0.0.8.0\n\n");

		   	     system("pause");
			     break;
	           }
		    }
	    }while(opc);
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void gameLocal(){
	    int l,c,i,p=1,opc;
    	char player1[MAX][MAX];// variavel correspondente ao tabuleiro de cada jogardor
    	char player2[MAX][MAX];
    	limpaMatriz(player1);//chama a fun��o limpaMatriz
    	setBarcos(player1,1);
    	limpaMatriz(player2);
		setBarcos(player2,2);

 	}
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void limpaMatriz(char x[MAX][MAX]){
		int l,c;// Linhas e Colunas
		for(l=0;l<10;l++){
		  for(c=0;c<10;c++)
		    x[l][c]='*';
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void apresentaTabuleiro(char x[MAX][MAX],int player){
		 int l,c;// Linhas e Colunas
		 printf("-------------------\n");
		 printf("player %d\n",player);
		 printf("-------------------\n");
		 printf("  0 1 2 3 4 5 6 7 8");
		 for(l=0;l<MAX;l++){ //Mostra a matriz
		      printf("\n");//	quebra linha quando acrescenta mais um a variavel l
		      for(c=0;c<MAX;c++){//Mostra Coluna
                 if(c==0){// quando for a coluna 0 vai apresentar i indice primeiro e depois o dado da matriz
                 printf("%d %c",l,x[l][c]);
                }else
		        printf(" %c",x[l][c]);
              }
	   	  }
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void setBarcos(char x[MAX][MAX],int player){// Inclui barcos na matriz
        int l=0,c=0,i;// l-linhas,c-colunas,i-contador do comando(for)
        int qtdElementos=0,cont=0;//contador de barcos totais
        char barco,opc;//barco-tipo do barco,
    do{
      do{
        system("cls");
        printf("----------------------------\n|Bem Vindo ao Batalha Naval|\n----------------------------\n");
        apresentaTabuleiro(x,player);
        printf("\nHorizontal ou vertical [h] ou [v]?:\n");
        opc=getche();
      }while((opc!='h')&&(opc!='v'));

     do{
         system("cls");
         apresentaTabuleiro(x,player);
         printf("\n-----------------------------------------\n");
         puts("1 porta-avi�es (4 c�lulas adjacentes) [p]");
         puts("2 encoura�ados (3 c�lulas adjacentes) [e]");
         puts("3 cruzadores (2 c�lulas adjacentes)   [c]");
         puts("4 submarinos (1 c�lula apenas)        [s]");
         printf("opc:");
         barco=getche();
     }while((barco!='e')&&(barco!='s')&&(barco!='p')&&(barco!='c'));

     switch(barco){
       case 'e':{
        qtdElementos=2;
        break;
       }
       case 's':{
        qtdElementos=0;
         break;
       }
       case 'p':{
        qtdElementos=3;
         break;
       }
       case 'c':{
           qtdElementos=1;
            break;
       }
     }

      printf("\ndigite as cordenadas (linha , coluna)\n");
      scanf("%d",&l);
      scanf("%d",&c);
      puts("");
    
      if(regras(x,l,c,opc,qtdElementos)){
        switch(opc){

          case 'h':{

           for(i=c;i<=(c+qtdElementos);i++)
            x[l][i] = barco;
            system("cls");
            apresentaTabuleiro(x,player);
            cont++;
         break;
        }

        case 'v':{
          for(i=l;i<=(l+qtdElementos);i++)
            x[i][c] = barco;
            system("cls");
            apresentaTabuleiro(x,player);
            cont++;
          break;
        }
        default:printf("deixa de ser Burro!");
      }
      }
     }while((cont!=5));
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int regras(char x[MAX][MAX],int l,int c,char opc,int qtdElementos){//testa as condi��es do jogo
      int i;
      if(opc=='h'){
       for(i=c;i<=c+qtdElementos;i++){

   ///////////////////////////////////////////////////////
           if((l==0)&&(c == 0) ){
             if ((x[l+1][i])!='*'){
                puts("n�o pode");
                return 0;
             }
        }else{
          if ((x[l+1][i]!='*')||(x[l-1][i]!='*')){
          printf("Existe navio adjacente\n");
          system("pause");
          return 0;
        }
        if ((x[i][c+1]!='*')||(x[i][c-1]!='*')){
            printf("Existe navios adjacentes <mensagen progrador vertical>\n");
            system("pause");
            return 0;
          }



        }

      return 1;
      }
      }else{
         for(i=l;i<=l+qtdElementos;i++){
          if ((x[i][c-1]!='*')||(x[i][c+1]!='*')){
            printf("Existe navios adjacentes <mensagen progrador vertical>\n");
            system("pause");
            return 0;
          }


         }
       }

        return 1;
      }


