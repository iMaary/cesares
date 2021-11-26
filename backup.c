#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
	char nome[99];
	char pronomes[20];
	char escolaridade[99];
	char curso[99];
	char data_inicio[99];
	char data_termino[99];
	int idade;
	struct aluno *next;
};

void save_attributes(struct aluno *head)
{

	struct aluno *aux = head;

	FILE *file_pointer;

	file_pointer = fopen("backup.csv", "w+");
	fprintf(file_pointer, "Nome, Idade, Pronomes, Escolaridade, Curso, Data de início, Data de término");
	while (aux != NULL) {
		fprintf(file_pointer, "\n");
		fprintf(file_pointer, "%s", aux->nome);
		fprintf(file_pointer, ",%d", aux->idade);
		fprintf(file_pointer, ",%s", aux->pronomes);
		fprintf(file_pointer, ",%s", aux->escolaridade);
		fprintf(file_pointer, ",%s", aux->curso);
		fprintf(file_pointer, ",%s", aux->data_inicio);
		fprintf(file_pointer, ",%s", aux->data_termino);
		aux = aux->next;
	}
	fclose(file_pointer);
}

struct aluno *push(struct aluno *head, char *n, char *p, char *e, char *c, char *di, char *dt, int i)
{
	struct aluno *novo = malloc(sizeof(struct aluno));

	strcpy(novo->nome, n);
	strcpy(novo->pronomes, p);
	strcpy(novo->escolaridade, e);
	strcpy(novo->curso, c);
	strcpy(novo->data_inicio, di);
	strcpy(novo->data_termino, dt);
	novo->idade = i;

	novo->next = head;
	head = novo;

	return head;
}

struct aluno *cadastro(struct aluno *head)
{
	char n[99], p[20], e[99], c[99], di[15], dt[15];
	int i;

	printf("\n==================================================");
	printf("\nInforme o nome do usuario: ");
	scanf("%99[^\n]s", n);
	getchar();

	printf("Informe os pronomes do usuario (ex: elu/delu): ");
	scanf("%20[^\n]s", p);
	getchar();

	printf("Informe a escolaridade do usuario: ");
	scanf("%99[^\n]s", e);
	getchar();

	printf("Informe o curso do usuario: ");
	scanf("%99[^\n]s", c);
	getchar();

	printf("Informe a data de inicio do curso do usuario (ex: dd/mm/aaaa): ");
	scanf("%15[^\n]s", di);
	getchar();

	printf("Informe a data de termino do curso do usuario (ex: dd/mm/aaaa): ");
	scanf("%15[^\n]s", dt);
	getchar();

	printf("Informe a idade do usuario: ");
	scanf(" %d", &i);
	getchar();

	printf("==================================================\n");

	head = push(head, n, p, e, c, di, dt, i);

	printf("\nUsuario cadastrado!");
	save_attributes(head);

	return head;
}

struct aluno *remover(struct aluno *head, char nome[99])
{
	struct aluno *aux = head;
	struct aluno *prev = NULL;

	while (aux != NULL && strcmp(aux->nome, nome) != 0) {
		prev = aux;
		aux = aux->next;
	}

	if (aux != NULL) {
		if (aux == head) {
			head = head->next;
			free(aux);
		} else if (aux->next != NULL) {
			prev->next = aux->next;
			free(aux);
		} else {
			prev->next = NULL;
			free(aux);
		}

		printf("\nUsuario removido!\n");
		save_attributes(head);

	} else {
		printf("\nUsuario nao encontrado!\n");
	}

	printf("\n==================================================\n");

	return head;
}

struct aluno *alterar(struct aluno *head, char nome[99])
{
	struct aluno *aux = head;

	while (aux != NULL && strcmp(nome, aux->nome) != 0) {
		aux = aux->next;
	}

	if (aux != NULL) {
		printf("\n==================================================");
		printf("\nInforme o nome do usuario: ");
		scanf("%99[^\n]s", aux->nome);
		getchar();

		printf("Informe os pronomes do usuario (ex: elu/delu): ");
		scanf("%20[^\n]s", aux->pronomes);
		getchar();

		printf("Informe a escolaridade do usuario: ");
		scanf("%99[^\n]s", aux->escolaridade);
		getchar();

		printf("Informe o curso do usuario: ");
		scanf("%99[^\n]s", aux->curso);
		getchar();

		printf("Informe a data de inicio do curso do usuario (ex: dd/mm/aaaa): ");
		scanf("%15[^\n]s", aux->data_inicio);
		getchar();

		printf("Informe a data de termino do curso do usuario (ex: dd/mm/aaaa): ");
		scanf("%15[^\n]s", aux->data_termino);
		getchar();

		printf("Informe a idade do usuario: ");
		scanf(" %d", &aux->idade);
		getchar();

		printf("\nUsuario alterado!\n");
		save_attributes(head);


		printf("\n==================================================\n");
	} else {
		printf("\nUsuario nao encontrado!");
	}

	return head;
}

void print_menu(void)
{
	printf("==================================================");
	printf("\nEscolha uma das opcoes abaixo:");
	printf("\n<1> Cadastrar usuario");
	printf("\n<2> Alterar dados do usuario");
	printf("\n<3> Remover usuario");
	printf("\n<4> Mostrar lista de usuarios");
	printf("\n<5> Encerrar programa");
	printf("\n\nEscolha: ");
}

void print_users(struct aluno *head)
{
	struct aluno *aux = head;

	while (aux != NULL) {
		printf("\n");
		printf("Nome: %s", aux->nome);
		printf("\nIdade: %d", aux->idade);
		printf("\nPronomes: %s", aux->pronomes);
		printf("\nEscolaridade: %s", aux->escolaridade);
		printf("\nCurso: %s", aux->curso);
		printf("\nData de inicio: %s", aux->data_inicio);
		printf("\nData do termino: %s", aux->data_termino);

		save_attributes(head);

		aux = aux->next;
		printf("\n");
	}

	printf("\n");
}



int main(void)
{
	struct aluno *head = NULL;

	int escolha;
	char nome[99];

	print_menu();
	scanf("%d", &escolha);
	getchar();
	printf("==================================================\n");

	while (1) {
		if (escolha == 1) {

			head = cadastro(head);
			print_menu();
			scanf(" %d", &escolha);
			getchar();
			printf("==================================================\n");


		} else if (escolha == 2) {

			printf("\nInforme o nome do usuario que deseja alterar: ");
			scanf(" %99[^\n]s", nome);
			getchar();

			head = alterar(head, nome);
			print_menu();
			scanf(" %d", &escolha);
			getchar();
			printf("==================================================\n");

		} else if (escolha == 3) {

			printf("\nInforme o nome do usuario a ser removido: ");
			scanf("%99[^\n]s", nome);
			getchar();
			head = remover(head, nome);
			print_menu();
			scanf(" %d", &escolha);
			getchar();
			printf("==================================================\n");

		} else if (escolha == 4) {

			print_users(head);
			print_menu();
			scanf(" %d", &escolha);
			getchar();
			printf("==================================================\n");

		} else if (escolha == 5) {

			printf("Ate mais! :)\n");
			printf("==================================================\n");
			break;

		} else {

			printf("Opcao invalida!\nSelecione uma opcao valida: ");
			scanf(" %d", &escolha);
			getchar();
			printf("==================================================\n");

		}
	}

	return 0;
}
