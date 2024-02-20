#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 10

// A função menu é responsável por exibir um menu de opções para um sistema de notas e ler a escolha do usuário. essa função exibe um menu para o usuário, lê a opção escolhida e a retorna como um valor inteiro. Isso permite que o programa principal saiba qual opção foi selecionada e execute a ação correspondente com base nessa escolha.
int menu() {
  printf("SISTEMA DE NOTAS ");
  printf("\n");
  printf("\n");

  printf("Menu: ");

  printf("\n");
  printf("\n");

  printf(" 1 - Cadastro de turmas");

  printf("\n");

  printf(" 2 - Inscrição de alunos");

  printf("\n");

  printf(" 3 - Descadastrar aluno ");

  printf("\n");

  printf(" 4 - Cadastrar notas ");

  printf("\n");

  printf(" 5 - Gerar relatório");

  printf("\n");

  printf("Escolha: ");

  int op;

  scanf("%d", &op);
  getchar();

  return op;
}


// A função "cadastroDisciplina" realiza o cadastro de uma disciplina em um sistema. Ela solicita ao usuário o nome do professor, nome da disciplina e código da disciplina. Em seguida, verifica se já existe uma disciplina cadastrada com o mesmo nome e, caso exista, recomenda recomeçar o cadastro. Se o arquivo não existir, cria um arquivo binário com o nome da disciplina e escreve as informações da disciplina nele.  Após isso, escreve as informações da disciplina em um arquivo chamado "disciplinas.bin" e exibe uma mensagem de sucesso.
typedef struct {
  char nome[100];
  char professor[100];
  char codigo[100];
} Disciplina;
void cadastroDisciplina() {
    Disciplina disciplina;
    FILE *arquivo;
    char nomeArquivo[100];

    printf("=== Cadastro de Turma ===\n");
    printf("Digite o nome do professor: ");
    fgets(disciplina.professor, sizeof(disciplina.professor), stdin);
    disciplina.professor[strcspn(disciplina.professor, "\n")] = '\0';
   
    printf("Digite o nome da disciplina: ");
    fgets(disciplina.nome, sizeof(disciplina.nome), stdin);
    disciplina.nome[strcspn(disciplina.nome, "\n")] = '\0';
    
    printf("Digite o código da disciplina: ");
    fgets(disciplina.codigo, sizeof(disciplina.codigo), stdin);
    disciplina.codigo[strcspn(disciplina.codigo, "\n")] = '\0';
    
    sprintf(nomeArquivo, "%s.bin", disciplina.nome);
    
    arquivo = fopen(nomeArquivo, "rb");

    if (arquivo != NULL) {
        printf("\nJá existe uma disciplina cadastrada com esse nome. O sistema recomenda que recomece o cadastramento indicando o número da turma.\n");
        fclose(arquivo);
        return;
    }

    arquivo = fopen(nomeArquivo, "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char gambiarra[100];//Variavel de improviso para me permitir salvar as informações como caracter no arquivo binario.

    sprintf(gambiarra, "Disciplina: %s / Código: %s / Professor: %s\n",
            disciplina.nome, disciplina.codigo, disciplina.professor);// Essa linha usa a função sprintf para formatar uma string e armazená-la na variável gambiarra. A string formatada inclui informações sobre uma disciplina, como nome, código e professor. Os valores dessas informações são fornecidos pelas variáveis disciplina.nome, disciplina.codigo e disciplina.professor.
  
    fwrite(gambiarra, sizeof(char), strlen(gambiarra), arquivo);
    gambiarra[strcspn(gambiarra, "\n")] = '\0';
    fclose(arquivo);

    int conta_linhas = 0;
    char linha[100];

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    
    

    fclose(arquivo);

    arquivo = fopen("disciplinas.bin", "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo disciplinas.bin.\n");
        return;
    }

    sprintf(gambiarra, "Disciplina: %s / Código: %s / Professor: %s\n",
            disciplina.nome, disciplina.codigo, disciplina.professor);// Essa linha usa a função sprintf para formatar uma string e armazená-la na variável gambiarra. A string formatada inclui informações sobre uma disciplina, como nome, código e professor. Os valores dessas informações são fornecidos pelas variáveis disciplina.nome, disciplina.codigo e disciplina.professor.
    fwrite(gambiarra, sizeof(char), strlen(gambiarra), arquivo);

    fclose(arquivo);

    printf("Disciplina cadastrada com sucesso.\n");
}


// A função "cadastroAluno" permite cadastrar um aluno em uma disciplina específica. Ela verifica se a disciplina existe, se há espaço disponível para cadastrar o aluno e, em seguida, solicita ao usuário as informações do aluno. Após o cadastro, as informações são armazenadas em um arquivo da disciplina correspondente. Em resumo, a função realiza o cadastro de um aluno em uma disciplina, salvando as informações em um arquivo.
void cadastroAluno() {
  FILE *arquivo;
  char nomeDisciplina[50];
  char nomeAluno[50];
  char localizador[50];

  printf("\n");
  printf("=== Cadastro de Aluno ===\n");
  printf("\n");
  printf("Disciplinas cadastradas:\n");
  printf("\n");
  FILE *disciplinas = fopen("disciplinas.bin", "rb");
    if (disciplinas == NULL) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    char disciplina[50];// Abaixo existe o início de um loop while. A condição do loop verifica se a função fgets retorna um valor diferente de NULL. A função fgets é usada para ler uma linha de texto do arquivo "disciplinas" e armazená-la na variável disciplina. O segundo parâmetro indica o tamanho máximo que a função deve ler, e o terceiro parâmetro é o arquivo de onde a linha de texto será lida. O código dentro do loop é executado quando a função fgets não retorna NULL, o que significa que uma linha de texto foi lida com sucesso do arquivo. A função strcspn é usada para encontrar a posição do caractere de nova linha ('\n') na string disciplina. A função retorna o número de caracteres antes do caractere de nova linha. Esse valor é usado como índice para acessar o caractere de nova linha na string disciplina e substituí-lo por um caractere nulo ('\0'), indicando o final da string. A linha de texto modificada é impressa na tela usando a função printf com o especificador de formato "%s" para imprimir uma string. O loop continua até que a função fgets retorne NULL, o que indica que todas as linhas do arquivo foram lidas. Em resumo, o código lê cada linha de texto do arquivo "disciplinas", remove o caractere de nova linha, e imprime cada linha na tela.
    while (fgets(disciplina, 50, disciplinas) != NULL) {
        disciplina[strcspn(disciplina, "\n")] = '\0'; 
        printf(" %s\n", disciplina);
    }
  fclose(disciplinas);
  
  printf("\n");
  printf("Digite o nome da disciplina em que o aluno será cadastrado: ");
  fgets(nomeDisciplina, 50, stdin);
  nomeDisciplina[strcspn(nomeDisciplina, "\n")] = '\0';

  char nomeArquivo[100];
  strcpy(nomeArquivo, nomeDisciplina);
  strcat(nomeArquivo, ".bin");
  arquivo = fopen(nomeArquivo, "rb");
  if (arquivo == NULL) {
    printf("Disciplina '%s' não encontrada.\n", nomeDisciplina);
    return;
  }

  fseek(arquivo, 0, SEEK_END);
  long tamanhoArquivo = ftell(arquivo);
  int numeroAlunos = tamanhoArquivo / sizeof(char) / 50;
  if (numeroAlunos >= MAX_ALUNOS) {
    printf("Limite máximo de alunos atingido para a disciplina '%s'.\n",
           nomeDisciplina);
    fclose(arquivo);
    return;
  }
  fclose(arquivo);

  printf("Digite o nome do aluno: ");
  fgets(nomeAluno, 50, stdin);
  nomeAluno[strcspn(nomeAluno, "\n")] = '\0';

  printf("Digite o número de identificação do aluno: ");
  fgets(localizador, 50, stdin);
  localizador[strcspn(localizador, "\n")] = '\0';

  arquivo = fopen(nomeArquivo, "ab");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo da disciplina.\n");
    return;
  }

  fprintf(arquivo, "Aluno: %s / N° %s\n", nomeAluno, localizador);

  fclose(arquivo);

  printf("Aluno cadastrado com sucesso na disciplina '%s'.\n", nomeDisciplina);
}



// A função "apagaAluno" realiza a remoção de um aluno em um sistema de cadastro de disciplinas. Ela solicita ao usuário o nome da disciplina e o número de identificação do aluno a ser removido. Em seguida, ela lê o arquivo da disciplina, procura pelo aluno pelo número de identificação e cria um arquivo temporário sem o aluno removido. Se o aluno for encontrado, o arquivo original é substituído pelo arquivo temporário, indicando que o aluno foi removido com sucesso. Caso contrário, o arquivo temporário é removido e uma mensagem informando que o aluno não foi encontrado é exibida.
void apagaAluno() {
    char nomeDisciplina[100];
    char localizador[100];
    FILE *arquivo_disciplina;

    printf("\n");
    printf("=== Descadastro de Aluno ===\n");
    printf("\n");
    printf("Disciplinas cadastradas:\n");
    printf("\n");
    FILE *disciplinas = fopen("disciplinas.bin", "rb");
    if (disciplinas == NULL) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    char disciplina[50];
    while (fgets(disciplina, 50, disciplinas) != NULL) {
        disciplina[strcspn(disciplina, "\n")] = '\0';
        printf(" %s\n", disciplina);
    }

    fclose(disciplinas);
    printf("\n");
    printf("Digite o nome da disciplina: ");
    fgets(nomeDisciplina, 50, stdin);
    nomeDisciplina[strcspn(nomeDisciplina, "\n")] = '\0';
    printf("\n");
    char nomeArquivo[100];

    strcpy(nomeArquivo, nomeDisciplina);
    strcat(nomeArquivo, ".bin");

    arquivo_disciplina = fopen(nomeArquivo, "rb");
    if (arquivo_disciplina == NULL) {
        printf("Arquivo da disciplina '%s' não encontrado.\n", nomeDisciplina);
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo_disciplina) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        printf("%s\n", linha);
    }
    printf("\n");
    fclose(arquivo_disciplina);

    printf("Digite o número de identificação do aluno: ");
    fgets(localizador, 50, stdin);
    localizador[strcspn(localizador, "\n")] = '\0';

    arquivo_disciplina = fopen(nomeArquivo, "rb");
    if (arquivo_disciplina == NULL) {
        printf("Erro ao abrir o arquivo da disciplina.\n");
        return;
    }

    FILE *novoArquivo = fopen("temp.txt", "w");
    if (novoArquivo == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo_disciplina);
        return;
    }

    //O codigo baixo lê um arquivo de disciplinas e procura por linhas que contenham um localizador específico. Se o localizador for encontrado, a linha correspondente é removida do arquivo. No final, o arquivo é atualizado e uma mensagem é exibida informando se o localizador foi encontrado ou não.
    char linhas[100];
    int encontrado = 0;
    while (fgets(linhas, sizeof(linhas), arquivo_disciplina) != NULL) {
        if (strstr(linhas, localizador) == NULL) {
            fprintf(novoArquivo, "%s", linhas);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo_disciplina);
    fclose(novoArquivo);

    if (encontrado) {
        if (remove(nomeArquivo) != 0) {
            printf("Erro ao remover o arquivo da disciplina.\n");
            remove("temp.txt");
            return;
        }

        if (rename("temp.txt", nomeArquivo) != 0) {
            printf("Erro ao atualizar o arquivo da disciplina.\n");
            remove("temp.txt");
            return;
        }

        printf("Aluno com o N° '%s' removido com sucesso.\n", localizador);
    } else {
        remove("temp.txt");
        printf("Aluno com o N° '%s' não encontrado.\n", localizador);
    }
}

// A função cadastroNotas permite cadastrar as notas de um aluno em uma disciplina específica. O usuário insere o nome da disciplina, o nome e número do aluno, a quantidade de notas, as notas e pesos correspondentes. Em seguida, é calculada a média ponderada das notas e essa informação, juntamente com os dados do aluno, é armazenada em um arquivo de notas da disciplina. Ao final, uma mensagem de sucesso é exibida. Existe um erro na função, tendo em vista que a mesma não possue um tratamento de um erro caso o aluno não for encontrado.
void cadastroNotas() {
  FILE *arquivo_disciplina;
  char nome_disciplina[100], nome_aluno[100],linhas[100], disciplina[50], nomeArquivo[100];
  int quantidade_notas, numero_aluno;
  float notas[100], pesos[100], media_ponderada = 0.0, media_aprovacao;

  printf("Disciplinas cadastradas:\n");
  printf("\n");

  FILE *disciplinas = fopen("disciplinas.bin", "rb");
  if (disciplinas == NULL) {
    printf("Nenhuma disciplina cadastrada.\n");
    return;
  }

  
  while (fgets(disciplina, sizeof(disciplina), disciplinas) != NULL) {
    disciplina[strcspn(disciplina, "\n")] = '\0';
    printf(" %s\n", disciplina);
  }
  fclose(disciplinas);

  printf("\n");
  printf("Digite a disciplina: ");
  fgets(nome_disciplina, sizeof(nome_disciplina), stdin);
  nome_disciplina[strcspn(nome_disciplina, "\n")] = '\0';
  printf("\n");

  
  strcpy(nomeArquivo, nome_disciplina);
  strcat(nomeArquivo, ".bin");

  arquivo_disciplina = fopen(nomeArquivo, "rb");

  if (arquivo_disciplina == NULL) {
    printf("Arquivo da disciplina '%s' não encontrado.\n", nomeArquivo);
    return;
  }

  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo_disciplina) != NULL) {
    linha[strcspn(linha, "\n")] = '\0';
    printf("%s\n", linha);
  }

  fclose(arquivo_disciplina);

  printf("\n");
  printf("Digite o nome do aluno: ");
  fgets(nome_aluno, sizeof(nome_aluno), stdin);
  nome_aluno[strcspn(nome_aluno, "\n")] = '\0';

  printf("Digite o número do aluno: ");
  scanf("%d", &numero_aluno);
  getchar();

  printf("Digite a quantidade de notas: ");
  scanf("%d", &quantidade_notas);
  getchar();

  for (int i = 0; i < quantidade_notas; i++) {
    printf("Digite a %da nota: ", i + 1);
    scanf("%f", &notas[i]);
    getchar();

    printf("Peso da %da nota de zero a um: ", i + 1);
    scanf("%f", &pesos[i]);
    getchar();
  }

  printf("Digite a média de aprovação para a disciplina: ");
  scanf("%f", &media_aprovacao);
  

  for (int i = 0; i < quantidade_notas; i++) {
    media_ponderada += notas[i] * pesos[i];
  }

  media_ponderada /= quantidade_notas;

  char nome_arquivo_notas[100];
  strcpy(nome_arquivo_notas, nome_disciplina);
  strcat(nome_arquivo_notas, "_notas.bin");

  FILE *arquivo_notas = fopen(nome_arquivo_notas, "ab");

  if (arquivo_notas == NULL) {
    printf("Erro ao abrir o arquivo de notas.\n");
    return;
  }

  char dados[200];
  if (media_ponderada >= media_aprovacao) {
    sprintf(dados, "Nome: %s / N°: %d / Média ponderada: %.2f / Média da disciplina: %.2f/ Situação: Aprovado\n",
            nome_aluno, numero_aluno, media_ponderada, media_aprovacao);
  } else {
    sprintf(dados, "Nome: %s / N°: %d / Média ponderada: %.2f / Média da disciplina: %.2f / Situação: Reprovado\n",
            nome_aluno, numero_aluno, media_ponderada, media_aprovacao);
  }

  fwrite(dados, sizeof(char), strlen(dados), arquivo_notas);
  
  
  for (int i = 0; i < quantidade_notas; i++) {
    sprintf(dados, "Nota %d: %.2f\n", i + 1, notas[i]);
    fwrite(dados, sizeof(char), strlen(dados), arquivo_notas);
    
  }
  sprintf(linhas ,"\n=======================\n");
    fwrite(linhas, sizeof(char), strlen(linhas), arquivo_notas);

  fclose(arquivo_notas);

  printf("\n");
  printf("Nota do aluno %s / N° %d em %s cadastrada com sucesso.\n", nome_aluno, numero_aluno, nome_disciplina);
  printf("\n");
}

// A função gerar_relatorio lê disciplinas cadastradas, permite escolher uma disciplina para gerar um relatório de turma, lê as notas dessa disciplina, imprime as notas em um relatório e gera um arquivo CSV com as mesmas informações.
void gerar_relatorio() {
  FILE *arquivo_disciplinas;
  FILE *arquivo_notas;
  char nome_disciplina[100];
  printf("\n");
  printf("Disciplinas cadastradas:\n");
  printf("\n");
  arquivo_disciplinas = fopen("disciplinas.bin", "r");
  if (arquivo_disciplinas == NULL) {
    printf("Nenhuma disciplina cadastrada.\n");
    return;
  }

  char disciplina[50];
  while (fgets(disciplina, sizeof(disciplina), arquivo_disciplinas) != NULL) {
    disciplina[strcspn(disciplina, "\n")] = '\0';
    printf("%s\n", disciplina);
  }
  fclose(arquivo_disciplinas);
  printf("\n");
  printf("Digite o nome da disciplina para gerar o relatório: ");
  fgets(nome_disciplina, sizeof(nome_disciplina), stdin);
  nome_disciplina[strcspn(nome_disciplina, "\n")] = '\0';
  printf("\n");

  char nomeArquivo[50];
  sprintf(nomeArquivo, "%s_notas.bin", nome_disciplina);

  arquivo_notas = fopen(nomeArquivo, "r");
  if (arquivo_notas == NULL) {
    printf("Arquivo da disciplina '%s' não encontrado.\n", nome_disciplina);
    return;
  }

  printf("\n==== RELATÓRIO DE TURMA ====\n\n");

  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo_notas) != NULL) {
    linha[strcspn(linha, "\n")] = '\0';
    printf("%s\n", linha);
  }
  char nomeArquivoCSV[50];
  sprintf(nomeArquivoCSV, "%s_notas.csv", nome_disciplina);
  FILE *arquivo_csv = fopen(nomeArquivoCSV, "w");
  if (arquivo_csv == NULL) {
    printf("Erro ao criar o arquivo .csv.\n");
    fclose(arquivo_notas);  
    return;
  }

  rewind(arquivo_notas);  

  while (fgets(linha, sizeof(linha), arquivo_notas) != NULL) {
    linha[strcspn(linha, "\n")] = '\0';
    fprintf(arquivo_csv, "%s\n", linha);
  }

  if (fclose(arquivo_notas) != 0) {
    printf("Erro ao fechar o arquivo de notas.\n");
  }
  if (fclose(arquivo_csv) != 0) {
    printf("Erro ao fechar o arquivo CSV.\n");
  }

  printf("\nArquivo .csv gerado com sucesso: %s\n", nomeArquivoCSV);
  printf("\n");
}




