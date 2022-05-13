/*
    Author: Gustavo Aniel Brito Trindade
	Turma: 7 Semestre (S.I)
	Vers�o: 1.0
	Ultima atualiza��o: 13/05/2022 00:40
*/


#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif

// inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// quantidade m�xima de letras no nome do cliente
#define MAX 100

// defini��o da struct cliente
typedef struct cliente
{
	// campos da struct cliente
	int id;
	char nome[MAX];
} t_cliente;

typedef struct produto
{
	// campos da struct cliente
	int id;
	char nome[MAX];
} t_produto;


// prot�tipos de fun��es

/**
 * Exibe o menu com todas as op��es do programa
 * retorno: um caractere do n�mero correspondente a op��o
 */
char menu();



void cadastrar_cliente();
void listar_clientes();

void cadastrar_produto();
void listar_produtos();


/**
 * Procura um cliente pelo seu id
 *
 * Par�metros:
 * arq_clientes: ponteiro para um arquivo aberto
 * id_cliente: ID do cliente que ser� buscado
 * retorno: um ponteiro para o cliente encontrado ou NULL caso o ID n�o exista
 */
t_cliente *obter_cliente(FILE * arq_clientes, int id_cliente);

t_produto *obter_produto(FILE * arq_produtos, int id_produto);

/**
 * Pesquisa um cliente e exibe suas informa��es
 */
void pesquisar_cliente();

void pesquisar_produto();
/**
 * Procura um cliente pelo seu id e informa se ele foi encontrado
 *
 * Par�metros:
 * arq_clientes: ponteiro para um arquivo aberto
 * id_cliente: ID do cliente que ser� buscado
 * retorno: 1 se o cliente existe ou 0 caso o ID n�o exista
 */
int existe_cliente(FILE * arq_clientes, int id_cliente);

int existe_produto(FILE * arq_produtos, int id_produto);



int str_somente_numeros(char str[]);

int main(int argc, char * argv[]) {
  char resp;
  // loop infinito do programa
  while (1) {
    // obt�m a escolha do usu�rio
    resp = menu();
    
    if (resp == '0')
    	break;
    
    switch(resp){
    	case '1':
    		cadastrar_cliente();
    	break;
    	case '2':
    		listar_clientes();
    	break;
    	case '3':
    		pesquisar_cliente();
    	break;
    	case '4':
    		cadastrar_produto();
    	break; 
		case '5':
    		listar_produtos();
    	break;
    	case '6':
    		pesquisar_produto();
    	break;
    	default:
    		printf("\nOpcao invalida! Pressione <Enter> para continuar...");
      		scanf("%*c");
      		// uma forma de "limpar" o buffer de entrada
      		fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
      	break;
	}
    
    system(limpar_tela);
  }
  printf("\nMuito Obrigado por visitar a Padaria Carioca\n");
  return 0;
}
// fun��o que exibe o menu e retorna a op��o escolhida pelo usu�rio
char menu() {
  char resp[2];
  printf("--------------------------------------- Padaria Carioca --------------------------------------------\n");
  printf("                                                                                                    \n");
  printf("                                                                   ^55YY555555PPPP5YJ7~:            \n");
  printf("                                                 .~7?JJJJYYYY?~..  5@&#5????????JJY55GBBGJ^         \n");
  printf("                                         .::.   !5JYB@#J7777?YPGBG55?~?##J!!!!!!!!!!!!!7JP#5:       \n");
  printf("                                    ~YYJJ?J5PPJPG^:::~JGGJ!!!!!7JPGY~::~5@P!!!!!!!!!!!!!!!7#&!      \n");
  printf("                                   7&Y5PGG5J77JPG57^:::^7BG7!!!!!!7YBJ^::7&B7!!!!!!!!!!!!!!7&&^     \n");
  printf("                     .^7JYYYYJJ?JY55~::^~7YG#GJ!!?5G5!^::^P&J!!!!!!!7GP^::7@Y!!!!!!!!!!!!!!!G@J     \n");
  printf("                  .!5P5Y?77777?JYPPP5J!^:::^~JB#Y!!7YBG7::^5&7!!!!!!!!PB!::GP!!!!!!!!!!!!!!!#@J     \n");
  printf("                  Y#55Y555Y?7!!!!!!7?YPPJ!^:^:^7BB7!!75#5^::GP!!!!!!!!!YBY7BY!!!!!!!!!!!!!!Y@#:     \n");
  printf("           ... ..^G!::^^~7YPGG5?!!!!!!!7JP5?~:^:^5#?!!!7PG?^J#!!!!!!!!!!75PY!!!!!!!!!!!!!!J@#^      \n");
  printf("          J&BGGGB&GJ?!~^:::^~7YGGP?!!!!!!!75GY!:::YB!!!!!?5PPJ!!!!!!!!!!!!!!!!!!!!!!!!!!7P@5:       \n");
  printf("        .G@P7777?JY5PGBGP?~::::^~JGGJ!!!!!!!7YBP7~Y#7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!?5#P~         \n");
  printf("       :B@Y!!!!!!!!!!!7?YG#P7^:^^:^7BG7!!!!!!!7YGBG?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?YPPJ^           \n");
  printf("      .B@Y!!!!!!!!!!!!!!!!75BB?^:^^:~#P!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?YPPY7^              \n");
  printf("      5@P!!!!!!!!!!!!!!!!!!!!JGGJ~^^^BB!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?YPPY?^.                 \n");
  printf("     ~@&7!!!!!!!!!!!!!!!!!!!!!!7Y5YYGG?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?YPP5?~.                     \n");
  printf("     J@G!!!!!!!!!!!!!!!!!!!!!!!!!!777!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7J5GG5?~.                         \n");
  printf("     Y@P!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?YPGG5?^.                             \n");
  printf("     ~@&7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?JPGBGY7^.                                 \n");
  printf("      ?@#7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?YPGBBPJ!:                                      \n");
  printf("       !#&57!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77J5PB#BGY7^.                                          \n");
  printf("        .7PBPJ?7!!!!!!!!!!!!!!!!!!!!!!77?Y5GB##BPJ!^.                                               \n");
  printf("           :!J5PPPPP5555555555555PPGBB##BG5J7~:                                                     \n");
  printf("               .:^!7?JY55555555YJJ?7!~^:.                                                           \n");
  printf("-----------------------------------------------------------------------------------------------------\n");
  printf("\n");
	
  printf("          ==================================      ==================================\n");
  printf("          ||                              ||      ||                              ||\n");
  printf("          ||           CLIENTES           ||      ||           PRODUTOS           ||\n");
  printf("          ||                              ||      ||                              ||\n");
  printf("          ==================================      ==================================\n");
  printf("          || 1 - Cadastrar um cliente     ||      || 4 - Cadastrar um produto     ||\n");
  printf("          || 2 - Listar todos os clientes ||      || 5 - Listar todos os produtos ||\n");
  printf("          || 3 - Pesquisar por cliente    ||      || 6 - Pesquisar por produto    ||\n");
  printf("          || 0 - Sair                     ||      || 0 - Sair                     ||\n");
  printf("          ==================================      ==================================\n\n");
  
  printf("\n\nDigite o numero da opcao: ");
  scanf("%1s%*c", resp); // o *c pega o Enter e descarta
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
  // se chegou aqui, � porque a op��o � v�lida
  return resp[0];
}
// fun��o que verifica se uma string cont�m somente n�meros
int str_somente_numeros(char str[]) {
  int i = 0;
  int len_str = strlen(str);
  for (i = 0; i < len_str; i++) {
    if (str[i] < '0' || str[i] > '9')
      return 0;
  }
  return 1;
}


// fun��o para cadastrar cliente
void cadastrar_cliente() {
  // abre o arquivo para escrita
  // a+b => acrescenta dados ao final do arquivo ou cria
  // um arquivo bin�ria para leitura e escrita
  FILE * arq_clientes = fopen("clientes.bin", "a+b");
  // testa a abertura do arquivo
  if (arq_clientes == NULL) {
    printf("\nFalha ao abrir arquivo(s)!\n");
    exit(1); // aborta o programa
  }
  /*
  N�O � interessante que o usu�rio digite o ID do cliente, esse
  ID tem que ser gerado autom�tico, ent�o temos que pegar o
  ID do �ltimo usu�rio cadastrado
  */
  int cont_bytes = 0;
  // cont ir� guardar o n�mero total de bytes
  // seta o ponteiro do arquivo para o final do arquivo
  fseek(arq_clientes, 0, SEEK_END);
  // pegamos a quantidade de bytes com a fun��o ftell
  cont_bytes = ftell(arq_clientes);
  t_cliente cliente;
  if (cont_bytes == 0) {
    // se for 0, ent�o n�o existe cliente cadastrado
    // coloco o ID come�ando de 1
    cliente.id = 1;
  } else {
    t_cliente ultimo_cliente;
    // utilizo a fun��o fseek para posicionar o arquivo
    // cont_bytes - sizeof(t_cliente) serve para posicionar
    // para que possamos pegar o �ltimo cliente cadastrado
    fseek(arq_clientes, cont_bytes - sizeof(t_cliente), SEEK_SET);
    // ler o cliente
    fread( & ultimo_cliente, sizeof(t_cliente), 1, arq_clientes);
    // o ID do cliente � o ID do �ltimo cliente acrescido em 1
    cliente.id = ultimo_cliente.id + 1;
  }
  // ^\n indica para pegar at� a quebra de linha (enter)
  // %*c descarta o enter
  printf("\nDigite o nome do cliente: ");
  scanf("%99[^\n]%*c", cliente.nome);
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
  // se o ponteiro n�o estiver no final do arquivo nada � escrito
  fseek(arq_clientes, 0, SEEK_END);
  // escreve no arquivo
  fwrite( & cliente, sizeof(t_cliente), 1, arq_clientes);
  // fecha o arquivo
  fclose(arq_clientes);
  printf("\nCliente \"%s\" cadastrado com sucesso!\n", cliente.nome);
  printf("\nPressione <Enter> para continuar...");
  scanf("%*c"); // pega o Enter e descarta
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
}


// fun��o para listar todos os clientes
void listar_clientes() {
  // rb => abre arquivo bin�rio para leitura apenas
  FILE * arq_clientes = fopen("clientes.bin", "rb");
  // testa a abertura do arquivo
  if (arq_clientes == NULL) {
    printf("\nFalha ao abrir arquivo(s) ou ");
    printf("Nenhum cliente cadastrado.\n");
    printf("\nPressione <Enter> para continuar...");
    scanf("%*c"); // pega o Enter e descarta
    // uma forma de "limpar" o buffer de entrada
    fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
    return;
  }
  // vari�vel que indica se encontrou pelo menos 1 cliente
  int encontrou_clientes = 0;
  t_cliente cliente;
  printf("\nListando todos os clientes...\n");
  printf("\n==================================\n");
  // loop para percorrer o arquivo
  while (1) {
    // fread retorna o n�mero de elementos lidos com sucesso
    size_t result = fread( & cliente, sizeof(t_cliente), 1, arq_clientes);
    // se for 0, � porque n�o h� mais elemento, ent�o sai do loop
    if (result == 0)
      break;
    // atualiza a vari�vel indicando que encontrou
    // pelo menos um cliente
    encontrou_clientes = 1;
    // mostra os dados do cliente
    printf("\nID do cliente: %d\n", cliente.id);
    printf("Nome do cliente: %s\n", cliente.nome);
    printf("\n==================================\n");
  }
  if (encontrou_clientes == 0)
    printf("\nNenhum cliente cadastrado.\n");
  fclose(arq_clientes);
  printf("\nPressione <Enter> para continuar...");
  scanf("%*c");
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
}


// fun��o que obt�m um cliente pelo ID
t_cliente * obter_cliente(FILE * arq_clientes, int id_cliente) {
  // vai para o in�cio do arquivo
  rewind(arq_clientes);
  t_cliente * cliente;
  // loop para percorrer o arquivo
  // busca linear O(n), como o ID � crescente � poss�vel fazer uma busca bin�ria O(log(n))
  // aloca espa�o mesmo sem saber se o cliente existe
  cliente = (t_cliente * ) malloc(sizeof(t_cliente));
  while (1) {
    // fread retorna o n�mero de elementos lidos com sucesso
    size_t result = fread(cliente, sizeof(t_cliente), 1, arq_clientes);
    // se for 0, � porque n�o h� mais elemento, ent�o sai do loop
    if (result == 0) {
      free(cliente); // libera a m�moria, pois o cliente n�o foi encontrado
      return NULL;
    }
    // verifica se os ID's s�o iguais
    if (cliente -> id == id_cliente)
      break;
  }
  return cliente;
}


// fun��o para pesquisar por algum cliente
void pesquisar_cliente() {
  char nome[MAX];
  int encontrou_cliente = 0;
  // rb+ => abre para leitura somente
  FILE * arq_clientes = fopen("clientes.bin", "rb");
  // testa a abertura do arquivo
  if (arq_clientes == NULL) {
    printf("\nFalha ao abrir arquivo(s)!\n");
    exit(1); // aborta o programa
  }
  printf("\nDigite o nome do cliente: ");
  scanf("%99[^\n]%*c", nome);
  printf("\nClientes com o nome \"%s\":\n\n", nome);
  // loop para percorrer o arquivo
  t_cliente cliente;
  while (1) {
    // fread retorna o n�mero de elementos lidos com sucesso
    size_t result = fread( & cliente, sizeof(t_cliente), 1, arq_clientes);
    // se for 0, � porque n�o h� mais elemento, ent�o sai do loop
    if (result == 0)
      break;
    char nome_aux[MAX];
    // faz uma c�pia para n�o alterar cliente->nome
    strcpy(nome_aux, cliente.nome);
    // verifica se � igual
    if (strcmp(strupr(nome_aux), strupr(nome)) == 0) {
      // mostra os dados do cliente
      printf("ID do cliente: %d\n\n", cliente.id);
      encontrou_cliente = 1;
    }
  }
  if (encontrou_cliente == 0)
    printf("Nenhum cliente encontrado.\n\n");
  // fecha o arquivo
  fclose(arq_clientes);
  printf("Pressione <Enter> para continuar...");
  scanf("%*c");
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
}


// fun��o que verifica se um cliente existe
// retorna 0 se N�O existe e 1 caso contr�rio
int existe_cliente(FILE * arq_clientes, int id_cliente) {
  // vai para o in�cio do arquivo
  rewind(arq_clientes);
  t_cliente cliente;
  // loop para percorrer o arquivo
  // busca linear O(n), como o ID � crescente � poss�vel fazer uma busca bin�ria O(log(n))
  while (1) {
    // fread retorna o n�mero de elementos lidos com sucesso
    size_t result = fread( & cliente, sizeof(t_cliente), 1, arq_clientes);
    // se for 0, � porque n�o h� mais elemento, ent�o sai do loop
    if (result == 0)
      break;
    // verifica se o ID � igual
    if (cliente.id == id_cliente)
      return 1;
  }
  // se chegou aqui � porque N�O existe o cliente, ent�o retorna 0
  return 0;
}


void cadastrar_produto(){
	// abre o arquivo para escrita
  // a+b => acrescenta dados ao final do arquivo ou cria
  // um arquivo bin�ria para leitura e escrita
  FILE * arq_produtos = fopen("produtos.bin", "a+b");
  // testa a abertura do arquivo
  if (arq_produtos == NULL) {
    printf("\nFalha ao abrir arquivo(s)!\n");
    exit(1); // aborta o programa
  }
  /*
  N�O � interessante que o usu�rio digite o ID do produto, esse
  ID tem que ser gerado autom�tico, ent�o temos que pegar o
  ID do �ltimo produto cadastrado
  */
  int cont_bytes = 0;
  // cont ir� guardar o n�mero total de bytes
  // seta o ponteiro do arquivo para o final do arquivo
  fseek(arq_produtos, 0, SEEK_END);
  // pegamos a quantidade de bytes com a fun��o ftell
  cont_bytes = ftell(arq_produtos);
  t_produto produto;
  if (cont_bytes == 0) {
    // se for 0, ent�o n�o existe produto cadastrado
    // coloco o ID come�ando de 1
    produto.id = 1;
  } else {
    t_produto ultimo_produto;
    // utilizo a fun��o fseek para posicionar o arquivo
    // cont_bytes - sizeof(t_cliente) serve para posicionar
    // para que possamos pegar o �ltimo produto cadastrado
    fseek(arq_produtos, cont_bytes - sizeof(t_produto), SEEK_SET);
    // ler o cliente
    fread( & ultimo_produto, sizeof(t_produto), 1, arq_produtos);
    // o ID do cliente � o ID do �ltimo cliente acrescido em 1
    produto.id = ultimo_produto.id + 1;
  }
  // ^\n indica para pegar at� a quebra de linha (enter)
  // %*c descarta o enter
  printf("\nDigite o nome do produto: ");
  scanf("%99[^\n]%*c", produto.nome);
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
  // se o ponteiro n�o estiver no final do arquivo nada � escrito
  fseek(arq_produtos, 0, SEEK_END);
  // escreve no arquivo
  fwrite( & produto, sizeof(t_produto), 1, arq_produtos);
  // fecha o arquivo
  fclose(arq_produtos);
  printf("\nProduto \"%s\" cadastrado com sucesso!\n", produto.nome);
  printf("\nPressione <Enter> para continuar...");
  scanf("%*c"); // pega o Enter e descarta
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
}

void listar_produtos(){
	// rb => abre arquivo bin�rio para leitura apenas
  FILE * arq_produtos = fopen("produtos.bin", "rb");
  // testa a abertura do arquivo
  if (arq_produtos == NULL) {
    printf("\nFalha ao abrir arquivo(s) ou ");
    printf("Nenhum produto cadastrado.\n");
    printf("\nPressione <Enter> para continuar...");
    scanf("%*c"); // pega o Enter e descarta
    // uma forma de "limpar" o buffer de entrada
    fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
    return;
  }
  // vari�vel que indica se encontrou pelo menos 1 produto
  int encontrou_produtos = 0;
  t_produto produto;
  printf("\nListando todos os produtos...\n");
  printf("\n==================================\n");
  // loop para percorrer o arquivo
  while (1) {
    // fread retorna o n�mero de elementos lidos com sucesso
    size_t result = fread( & produto, sizeof(t_produto), 1, arq_produtos);
    // se for 0, � porque n�o h� mais elemento, ent�o sai do loop
    if (result == 0)
      break;
    // atualiza a vari�vel indicando que encontrou
    // pelo menos um produto
    encontrou_produtos = 1;
    // mostra os dados do produto
    printf("\nID do produto: %d\n", produto.id);
    printf("Nome do produto: %s\n", produto.nome);
    printf("\n==================================\n");
  }
  if (encontrou_produtos == 0)
    printf("\nNenhum produto cadastrado.\n");
  fclose(arq_produtos);
  printf("\nPressione <Enter> para continuar...");
  scanf("%*c");
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
}

t_produto *obter_produto(FILE * arq_produtos, int id_produto){
	 // vai para o in�cio do arquivo
  rewind(arq_produtos);
  t_produto * produto;
  // loop para percorrer o arquivo
  // busca linear O(n), como o ID � crescente � poss�vel fazer uma busca bin�ria O(log(n))
  // aloca espa�o mesmo sem saber se o produto existe
  produto = (t_produto * ) malloc(sizeof(t_produto));
  while (1) {
    // fread retorna o n�mero de elementos lidos com sucesso
    size_t result = fread(produto, sizeof(t_produto), 1, arq_produtos);
    // se for 0, � porque n�o h� mais elemento, ent�o sai do loop
    if (result == 0) {
      free(produto); // libera a m�moria, pois o cliente n�o foi encontrado
      return NULL;
    }
    // verifica se os ID's s�o iguais
    if (produto -> id == id_produto)
      break;
  }
  return produto;
}

void pesquisar_produto(){
	char nome[MAX];
  int encontrou_produto = 0;
  // rb+ => abre para leitura somente
  FILE * arq_produtos = fopen("produtos.bin", "rb");
  // testa a abertura do arquivo
  if (arq_produtos == NULL) {
    printf("\nFalha ao abrir arquivo(s)!\n");
    exit(1); // aborta o programa
  }
  printf("\nDigite o nome do produto: ");
  scanf("%99[^\n]%*c", nome);
  printf("\nProdutos com o nome \"%s\":\n\n", nome);
  // loop para percorrer o arquivo
  t_produto produto;
  while (1) {
    // fread retorna o n�mero de elementos lidos com sucesso
    size_t result = fread( & produto, sizeof(t_produto), 1, arq_produtos);
    // se for 0, � porque n�o h� mais elemento, ent�o sai do loop
    if (result == 0)
      break;
    char nome_aux[MAX];
    // faz uma c�pia para n�o alterar produto->nome
    strcpy(nome_aux, produto.nome);
    // verifica se � igual
    if (strcmp(strupr(nome_aux), strupr(nome)) == 0) {
      // mostra os dados do cliente
      printf("ID do produto: %d\n\n", produto.id);
      encontrou_produto = 1;
    }
  }
  if (encontrou_produto == 0)
    printf("Nenhum produto encontrado.\n\n");
  // fecha o arquivo
  fclose(arq_produtos);
  printf("Pressione <Enter> para continuar...");
  scanf("%*c");
  // uma forma de "limpar" o buffer de entrada
  fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
}

int existe_produto(FILE * arq_produtos, int id_produto) {
  // vai para o in�cio do arquivo
  rewind(arq_produtos);
  t_produto produto;
  // loop para percorrer o arquivo
  // busca linear O(n), como o ID � crescente � poss�vel fazer uma busca bin�ria O(log(n))
  while (1) {
    // fread retorna o n�mero de elementos lidos com sucesso
    size_t result = fread( & produto, sizeof(t_produto), 1, arq_produtos);
    // se for 0, � porque n�o h� mais elemento, ent�o sai do loop
    if (result == 0)
      break;
    // verifica se o ID � igual
    if (produto.id == id_produto)
      return 1;
  }
  // se chegou aqui � porque N�O existe o cliente, ent�o retorna 0
  return 0;
}
