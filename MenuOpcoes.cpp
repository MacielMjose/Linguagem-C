#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define Tam 10


void oi();
void tudobem();
void familia();
void sair();

int main()
{
	int continuar;

	do{

		printf("Escolha uma opcao:\n");
		printf("1 - oi:\n");
		printf("2 - Tudo bem?:\n");
		printf("3 - Familia:\n");
		printf("4 - Sair:\n");
		printf("Opcao:");

		scanf("%i",&continuar);
		system("cls");

        switch (continuar)
			{
				case 1:
					oi();

			break;

				case 2:

					familia();

			break;

				case 3:

					tudobem();

			break;

				case 4:

					sair();

			break;

				default:

					printf("Opcao invalida!\n");
					system("cls");

			break;

			}

		}while(continuar != 4);

   return 0;

}
void oi()
{

	printf("RoBot_says(^.^): oi!\n");
	system("pause");
    system("cls");


}
void tudobem()
{
	printf("RoBot_says(^.^):tudo bem?\n");
	system("pause");
	system("cls");

}
void familia()
{

	printf("RoBot_says(^.^):como vai a familia?\n");
	system("pause");
	system("cls");

}
void sair()
{
	printf("RoBot_says(^.^):Adeus ;( \n");
	system("pause");
	system("cls");
}







