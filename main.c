#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct livro {
    
    char nome[100];
    char isbn[100];
    float preco;
    int score;
    char editora[100];
}tLivro, *pLivro;

pLivro livro_aloc(int qtde);
void livro_ler(pLivro livros, int qtde);
void livro_exibe(pLivro livros, int qtde);
void livro_desaloca(pLivro livros);

int main(){   
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int qtde;
    scanf("%d",&qtde);
    getchar();

    pLivro arrayLivros;

    arrayLivros = livro_aloc(qtde);

    livro_ler(arrayLivros,qtde);

    livro_exibe(arrayLivros,qtde);

    livro_desaloca(arrayLivros);

    return 0;
}

pLivro livro_aloc(int qtde){
    pLivro arrayLivro;

    arrayLivro = (pLivro)malloc(qtde * sizeof(tLivro));

    return arrayLivro;
}

void livro_ler(pLivro livros, int qtde){
    int i;
    char holder[100];
    for(i = 0; i < qtde; i++){
        //nome
        fgets(holder,100,stdin);
        holder[strcspn(holder, "\n")] = '\0';
        strcpy(livros[i].nome,holder);

        //isbn
        fgets(holder,100,stdin);
        holder[strcspn(holder, "\n")] = '\0';
        strcpy(livros[i].isbn,holder);

        //preço
        scanf("%f",&livros[i].preco);
        getchar();

        //score
        scanf("%d",&livros[i].score);
        getchar();
        
        //editora
        fgets(holder,100,stdin);
        //holder[strcspn(holder, "\n")] = '\0';
        strcpy(livros[i].editora,holder);
        
    }
}

void livro_exibe(pLivro livros, int qtde){
    int i;
    for(i = 0; i < qtde; i++){
        printf("Livro %d:\n",i+1);
        printf("Nome: %s\n",livros[i].nome);
        printf("ISBN: %s\n",livros[i].isbn);
        printf("Preço: %.2f\n",livros[i].preco);
        printf("Score: %d\n",livros[i].score);
        printf("Editora: %s\n",livros[i].editora);
    }
}

void livro_desaloca(pLivro livros){
    free(livros);
}
