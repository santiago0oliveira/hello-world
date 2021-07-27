#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUMS 60 			/* numeros total do jogo*/
#define MIN_APOSTA 6		/* Aposta minima*/
#define NUM_LIN 10			/*numeros a aparecer por linha*/

/*Declarações das funções*/

	void inic_random();
	void inic(int v[NUMS]);
	int ler_ns_apostar();
	void gerar(int *v, int n);
	void apresentar(int res[]);

/* Função main principal*/

	int main()
	{
		int vetor[NUMS];
		int n_nums;		/* numero de numeros para jogar o jogo 6...60*/

		inic_random();
		while(1)
		{
			inic(vetor);

			if((n_nums = ler_ns_apostar()) == 0)
				break;

			gerar(vetor, n_nums);		/* Gerar os numeros a apostar*/
			apresentar(vetor);
		}
		return 0;
	}

/*
 *	inicia o gerador numeros aleatórios
 *	com numero que depende da hora que
 *	se executa a função
 */
	void inic_random()
	{
		long ultime;
		time(&ultime);
		srand((unsigned) ultime);
	}

	/* inicia com zero o vetor dos numeros selecionados*/

	void inic(int v[])
	{
		int i;

		for(i = 0; i < NUMS; i++)
			v[i] = 0;
	}

/*
 *	Lê o numero de numeros a apostar.
 *	Aceita valores entre MIN_APOSTA e NUMS.
 *	Aceita o valor ZERO para terminar a aposta.
 */

	int ler_ns_apostar()
	{
		int n;

		do
		{
			printf("Quantos numeros quer apostar, ( 0 - para terminar): ");
			scanf("%d", &n);
		}
		while((n < MIN_APOSTA || n > NUMS) && n != 0);

		return n;
	}

/*
 * gera n numeros aleatorios e coloca a respectiva 
 * posição do vetor com o valor 1 que indica que
 * esse numero foi selecionado.
 */

	void gerar(int *v, int n)
	{
		int i, indice;

		for(i = 1; i <= n; i++)
		{
			indice = rand() % NUMS; /* devolve numero aleatorio entre 0 e NUMS - 1*/

			if(v[indice] == 0)		/*Não foi selecionado*/
				v[indice] = 1;
			else				/* este numero ja foi selecionado*/
				i--;			 /* logo decrementa-se o contador*/
								 /* para voltar a calcular*/
								 /* mais uma vez o i-ésimo numero*/
								 /* aleatório.*/
		}
	}

/*
 * Apresenta o formato do volante colocando XX nos numeros
 * selecionados para a aposta.
 */

	void apresentar(int res[])
	{
		int i;

		for(i = 0; i < NUMS; i++)
		{
			if(res[i] == 0)
				printf(" %2d", i+1);
			else
				printf(" XX");
			if((i + 1) % NUM_LIN == 0)
				putchar('\n');
		}
		putchar('\n');
	}
