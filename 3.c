//importar as bibliotecas
//POR ALGUM MOTIVO SO CONSEGUI RODAR NESSE COMPILADOR ONLINE : ==========  https://www.onlinegdb.com/online_c_compiler
//============================================================================================
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
 int i,j,k,length,rails,contador,codigo[100][1000];
 //recolher os dados
    char str[1000];
    printf("Entre a mensagem secreta\n");
    gets(str);
 
    length=strlen(str);
//testar as chaves possiveis de 2 a 10   
for (rails=2;rails<8;rails++){
    //percorrer os rails
    for(i=0;i<rails;i++){
        //percorrer os caracteres da mensagem
        for(j=0;j<length;j++){
            //zerar todos os codigos 
            codigo[i][j]=0;
        }
    }
contador=0;
j=0;
//percorrer os caracteres da mensagem
//para determinar quando esta descendo ou subindo
while(j<length){
//se o (resto do contador) / 2 = 0  
    if(contador%2==0){
        for(i=0;i<rails;i++){
            //colocar o codigo que (resto do contador) / 2 = 0  igual a -1 para ficar diferente das demais (que sao 0)
            codigo[i][j]=-1;
            //incrementar o j
            j++;
        }
 
    }
    else{
 // enquanto o numero de rails-2 for maior que 0
        for(i=rails-2;i>0;i--){
            // devemos setar o codigo da caractere como -1
            codigo[i][j]=-1;
            j++;
        }
    }
 
contador++;
}
//Decriptaçao:
//zerar o k
k=0;
//varrer tudo
for(i=0;i<rails;i++){
    //varrer tudo
    for(j=0;j<length;j++){
    // se o codigo for diferente de 0 (ou seja que mudamos no procedimento acima)
        if(codigo[i][j]!=0){
            //converter o codigo pra string de acordo com o k
            codigo[i][j]=(int)str[k];
            k++;
        }
    }
}
//para determinar quando esta descendo ou subindo
contador=0;
j=0;
while(j<length){
    //descendo a railfence na diagonal
    if(contador%2==0){
        for(i=0;i<rails;i++){
            printf("%c",codigo[i][j]);
            j++;
        }
    }
    else{
        //subindo a railfence na diagonal
        for(i=rails-2;i>0;i--){
            printf("%c",codigo[i][j]);
            j++;
        }  
    }
    contador++;
}
printf("\n\n");
}}