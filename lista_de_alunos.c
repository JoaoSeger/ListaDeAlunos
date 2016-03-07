#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct aluno
{
  int matricula;
  char nome[30];
  int cpf;
  char sexo[1];
};

void LimpaTela(){
  //se for mac use clear se for windows cls
  system("clear");
}

void ChamaMenu() 
{
  LimpaTela();
  printf("Para adicionar um aluno pressione 1 \n");
  printf("Para retirar um aluno pressione 2 \n");
  printf("Para listar todos alunos pressione 3 \n");
  printf("Para sair pressione 0 \n");

}

void adicionaAluno(struct aluno a[]){
   LimpaTela();
   int i=0;
   char achou='f';
        while (i<2 && achou == 'f'){
                if (*a[i].nome == ' '){
                        
                        printf("\nForneca os dados sobre o aluno.\n");
                        fflush(stdin);
                        LimpaTela();
                        printf("Matricula : \n");
                        scanf("%d", &a[i].matricula);
                        LimpaTela();
                        printf("Nome : \n");
                        scanf("%s", a[i].nome);
                        LimpaTela();
                        printf("cpf ( Digite Apenas os Numeros ) : \n");
                        scanf("%d", &a[i].cpf);
                        LimpaTela();
                        printf("Sexo (M) = Masculino (F) = Feminino : \n");
                        scanf("%s", a[i].sexo);
                        achou = 'v';
                        break;
                }
            i++;
        }
        if(achou == 'f') {
          LimpaTela();
          printf("\nDesculpe, nao ha espaco para inserir um novo aluno.\n");
          sleep(2);
        }
}

void listaAlunos(struct aluno a[]){
  int y, aluno=1;
  LimpaTela();
  for(int y=0; y<2; y++){
    if(*a[y].nome != ' '){
      printf("Nome: %s, Matricula: %d, cpf: %d, Sexo: %s \n", a[y].nome, a[y].matricula, a[y].cpf, a[y].sexo);
    }
  }
}

void removeAluno(struct aluno a[]){
  LimpaTela();
  listaAlunos(a);
  int matricula;
  int y, i=0;
  printf("Digite a matricula do aluno que deseja excluir : \n");
  scanf("%d", &matricula);

  for(y=0;y<2;y++){
    if(matricula == a[y].matricula){
      *a[y].nome = ' ';
      a[y].matricula = ' ';
      i=1;
      printf("Excluido com sucesso!\n\n");
      sleep(3);
      LimpaTela();
    }
  }
  if(i==0){
    printf("Nao foi encontrado nenhuma matricula igual a esta.\n\n");
    sleep(2);
  }

LimpaTela();
}

void inicia (struct aluno a[]){
        int i;

        for (i=0; i<2; i++)
                *a[i].nome=' ';
}

int main()
{
  struct aluno a[2];
  int buttonPress = 1;
  int i;

  inicia(a);

  while(buttonPress != 0) 
  {
    ChamaMenu();
    scanf("%d", &buttonPress);
    switch(buttonPress){
      case 1: adicionaAluno(a);break;
      case 2: removeAluno(a);break;
      case 3: listaAlunos(a); printf("\n\n Pressione algum botao e pressione enter para ir para o menu."); scanf("%d", &i);break; 
    }
  }

  return 0;
}