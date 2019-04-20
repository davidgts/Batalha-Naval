#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#define MAX 9
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu();//Função menu ultilizada pra selecionar a opção do usuario e chamar a função nescessaria para dar prosseguimento a aplicação ou sair do programa
void gameLocal();//Faz todo o controle do jogo local
void limpaMatriz(char x[MAX][MAX]);// Função que faz a matriz receber seus valores como *
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
   int opc;//armazenará a opção do usuario
   do {
     system("cls");
     printf("|------------------------------------------|\n");
     printf("|              Batalha Naval               |\n");
     printf("|                [1]-Local                 |\n");
     printf("|                [2]-Multiplayer           |\n");
     printf("|                [3]-Instruções            |\n");
     printf("|                [4]-sobre                 |\n");
     printf("|                [0]-sair                  |\n");
     printf("|------------------------------------------|\n");
     printf("Opc:");
     scanf("%d",&opc);
     system("cls");
     switch(opc){ //inicializará a aplicação selecionada pelo usuario
       case 1:{
         gameLocal();
         system("pause");
         break;
             }
       case 2:{

         break;
		      }
       case 3:{
         printf("|Instruções iniciais| \n\n");
         printf("1-Cada jogador distribui suas embarcações pelo tabuleiro.\nIsso é feito informando qual embarcação e quais celulas\nos X são referentes às suas embarcações. \n\n");
         printf("2-Não é permitido que 2 embarcações se toquem\ndeve sempre existir um espaço de uma celula entre elas\n\n");

		 printf("|Jogando| \n\n");
		 printf("Na sua vez de jogar, seguirá o seguinte procedimento:\n\n");
		 printf("1-Cada jogador fará um disparo por vêz,\nindicando as coordenadas em linhas e colunas do tabuleiro inimigo\n\n");
		 printf("2- A cada tiro acertado em um alvo,sera marcado no tabuleiro do oponente\num icone para que possa informar quando a enbarcação for afundada.\n\n");
		 printf("3- O jogador vence quando destruir todas as suas embarcações do inimigo\n\n");

         system("pause");
		 break;
		      }
       case 4:{
		 	     printf("Este software foi desenvolvido como objetivo de ser um\nProjeto para a disciplina de-Algoritmo e Programação Estruturada\n");
		 	     printf("Onde é nescessario criar um jogo de batalha naval\nultilizando alguns dos assunto dados em sala de aula\n\n");
		 	     printf("--------------------------------------------------------------------\n");

		         printf("Este Programa foi desenvolvido pela equipe:\n");
		 	     printf("David Machado - Matricula 20161380029\n");
		 	     printf("Jorge Gomes - Matricula 20161380001\n");
		 	     printf("--------------------------------------------------------------------\n");
		 	     printf("                                                    Versão 0.0.8.0\n\n");

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
    	limpaMatriz(player1);//chama a função limpaMatriz
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
         puts("1 porta-aviões (4 células adjacentes) [p]");
         puts("2 encouraçados (3 células adjacentes) [e]");
         puts("3 cruzadores (2 células adjacentes)   [c]");
         puts("4 submarinos (1 célula apenas)        [s]");
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
    int regras(char x[MAX][MAX],int l,int c,char opc,int qtdElementos){//testa as condições do jogo
      int i;
      if(opc=='h'){
       for(i=c;i<=c+qtdElementos;i++){

   ///////////////////////////////////////////////////////
           if((l==0)&&(c == 0) ){
             if ((x[l+1][i])!='*'){
                puts("não pode");
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


