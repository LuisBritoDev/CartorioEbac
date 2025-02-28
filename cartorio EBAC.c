#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registro() // Fun��o de registro
{
	//inicio da cria��o de vari�veis
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo! \n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar ()
{
	char cpf [40];
	
	printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("O usu�rio n�o existe! \n");
    	system("pause");
	}
	
	else
	{
		fclose(file);
		
		remove(cpf);
		
		printf("O usu�rio deletado! \n");
		system("pause");
		
	}
}

int main() // fun��o main
{
	
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;)
    {
    	
       system("cls"); //limpar tela
	
	   setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
	
	
	   printf("***Cart�rio EBAC***\n\n"); //in�cio do menu
	   printf("MENU\n\n");
	   printf("Escolha a op��o desejada:\n\n");
	   printf("\t1 - Registrar nomes de usu�rio\n");
	   printf("\t2 - Consultar nomes de usu�rio\n");
	   printf("\t3 - Deletar nomes de usu�rio\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Op��o:"); //fim do menu

       scanf("%d", &opcao); //armazenar respostas
    
       system("cls"); //limpar tela
       
       switch(opcao)   //inicio da sele��o
       {
       	    case 1:
       	    registro(); //chamada de fun��es
        	break;
       	    
       	    case 2:
       	    consultar();
       	    break;
       	    	
       	    case 3:
       	    deletar();
       	    break;
       	    
       	    case 4:
       	    printf("Obrigado por utilizar o sistema!\n");
       	    return 0;
       	    break;
       	    
       	    default:
       	    	printf("Essa op��o n�o est� dispon�vel\n");  //fim da sele��o
       	    	system("pause");
       	    break;
       	    	
	   }
        
	}    
	    
}
