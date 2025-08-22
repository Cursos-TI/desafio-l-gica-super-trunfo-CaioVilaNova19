#include <stdio.h>

//struct para salvar as variáveis
struct carta{
        char Estado[50];
        char Cidade[50];
        char Código[6];
        int População;
        float Área;
        float pib;
        int p_turisticos;
};

// função para mostrar as cartas
void mostrar_carta(struct carta *c){
    //cálculo
    float pib_capta = c->pib / c->População;
    float d_populacional = c->População / c->Área;

         printf("\n=== Dados da Carta ===\n");
         printf("Estado: %s\n", c->Estado);
         printf("Código: %s\n", c->Código);
         printf("Cidade: %s\n", c->Cidade);
         printf("População: %d\n", c->População);
         printf("Área: %.2f\n", c->Área);
         printf("PIB: %.2f\n", c->pib);
         printf("Nº de Pontos Turísticos: %d\n", c->p_turisticos);
         printf("PIB per capta: %f\n", pib_capta); // não precisa de ponteiro
         printf("Densidade Populacional: %f\n", d_populacional);
}

void comparar_cartas(struct carta *c1, struct carta *c2, int compara){

         switch (compara) {
         
        case 1: // População
            if (c1->População > c2->População)
                printf("\n%s vence na população\n", c1->Cidade);
            else if (c1->População < c2->População)
                printf("\n%s vence na população\n", c2->Cidade);
            else
                printf("\nEmpate na população!\n");
            break;

        case 2: // Área
            if (c1->Área > c2->Área)
                printf("\n%s vence na área\n", c1->Cidade);
            else if (c1->Área < c2->Área)
                printf("\n%s vence na área\n", c2->Cidade);
            else
                printf("\nEmpate na área!\n");
            break;

        case 3: // PIB
            if (c1->pib > c2->pib)
                printf("\n%s vence no PIB\n", c1->Cidade);
            else if (c1->pib < c2->pib)
                printf("\n%s vence no PIB\n", c2->Cidade);
            else
                printf("\nEmpate no PIB!\n");
            break;

        case 4: // Pontos turísticos
            if (c1->p_turisticos > c2->p_turisticos)
                printf("\n%s vence nos pontos turísticos\n", c1->Cidade);
            else if (c1->p_turisticos < c2->p_turisticos)
                printf("\n%s vence nos pontos turísticos\n", c2->Cidade);
            else
                printf("\nEmpate nos pontos turísticos!\n");

            break;

        default:
        printf("Parâmetros inválidos");
       }
}

int main(){
   struct carta c1 = {"Recife", "Pernambuco", "A01", 123000, 15400.11, 69999.001, 12};
   struct carta c2 = {"Ceará", "Fortaleza", "A02", 102000, 12400.11, 68900.200, 8};

   int menu;
   int opcao;

   do{
   
       printf("\n+++ MENU PRINCIPAL +++\n");
       printf("1. Iniciar Jogo\n");
       printf("2. Ler regras\n");
       printf("3. Sair\n");
       scanf("%d", &menu);

   switch (menu){

   case 1:
       printf("Iniciando jogo...\n");
       mostrar_carta(&c1);
       mostrar_carta(&c2);
   
       printf("\nGostaria de comparar as cartas? 1 para sim, 2 para não\n");
       scanf("%d", &opcao);
   
       if (opcao == 1){
           int compara;
           int usados[5] = {0}; // inicializa tudo com 0 (senão fica lixo)
   
           while (1){
               printf("Qual atributo gostaria de comparar?\n");
               if (!usados[1]) printf("1 - População\n");
               if (!usados[2]) printf("2 - Área\n");
               if (!usados[3]) printf("3 - PIB\n");
               if (!usados[4]) printf("4 - Pontos Turísticos\n");
               printf("0 - Voltar ao menu\n");
               scanf("%d", &compara);
   
               if (compara == 0) break;
               if (compara < 1 || compara > 4) {
                   printf("Opção inválida! Tente novamente.\n");
                   continue;
               }
               if (usados[compara]) {
                   printf("Esse atributo já foi comparado! Escolha outro.\n");
                   continue;
               }
   
               usados[compara] = 1;
               comparar_cartas(&c1, &c2, compara);
           }
       }
       else if (opcao == 2)
           printf("Abriu o jogo pq então?\n");
       else
           printf("Opção inválida! Tente novamente.\n");
   
       break; // <-- esse break agora pertence corretamente ao case 1
   
   case 2:
       printf("Não sabe jogar supertrunfo?\n");
       break;
   
   case 3:
       printf("Encerrando...\n");
       break;
   
   default:
       printf("Opção inválida! Tente novamente.\n");
       break;
   
    }

   } while (menu != 3);

   return 0;
}
