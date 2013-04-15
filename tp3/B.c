#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 256

typedef struct timestamp {
	int ano;
	int mes;
	int dia;
	int horas;
	int minutos;
	int segundos;
} timestamp;

typedef struct rota {
	int registo;
	int viatura;
	timestamp t;
	float latitude;
	float longitude;
	char cidade[MAX_STR];
	float distancia;
} rota;

int comparacao_chaves(rota a, rota b)
{
	if (a.viatura != b.viatura)
		return a.viatura - b.viatura;

	if (a.t.ano != b.t.ano)
		return a.t.ano - b.t.ano;

	if (a.t.mes != b.t.mes)
		return a.t.mes - b.t.mes;

	if (a.t.dia != b.t.dia)
		return a.t.dia - b.t.dia;

	if (a.t.horas != b.t.horas)
		return a.t.horas - b.t.horas;

	if (a.t.minutos != b.t.minutos)
		return a.t.minutos - b.t.minutos;

	if (a.t.segundos != b.t.segundos)
		return a.t.segundos - b.t.segundos;
 
	return 0;
}

void insertion_sort_chaves(rota *rotas, int array_size)
{
	int i, j;
	rota temp;
	for (i = 1; i < array_size; ++i)
	{
		temp = rotas[i];
		for (j = i; j > 0 && comparacao_chaves(rotas[j-1], temp) > 0; j--)
			rotas[j] = rotas[j-1];
		rotas[j] = temp;
	}
}

void imprime_rotas(rota *rotas, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d,%d,%02d-%02d-%02d %02d:%02d:%02d,%g,%g,%s\n", rotas[i].registo, rotas[i].viatura, rotas[i].t.ano, 
								  rotas[i].t.mes, rotas[i].t.dia, rotas[i].t.horas, rotas[i].t.minutos,
								  rotas[i].t.segundos, rotas[i].latitude, rotas[i].longitude, rotas[i].cidade);
	}
}

int main(int argc, char ** argv)
{
	int n, i;
	rota *rotas;

	scanf("%d", &n);

	rotas = (rota*) malloc (n * sizeof(rota));

	for (i = 0; i < n; i++)
	{
		scanf("%d,%d,%d-%d-%d %d:%d:%d,%f,%f,%s", &rotas[i].registo, &rotas[i].viatura, &rotas[i].t.ano, 
												  &rotas[i].t.mes, &rotas[i].t.dia, &rotas[i].t.horas, 
												  &rotas[i].t.minutos, &rotas[i].t.segundos, &rotas[i].latitude, 
												  &rotas[i].longitude, rotas[i].cidade);
	}

	insertion_sort_chaves(rotas, n);
	imprime_rotas(rotas, n);

	return 0;
}
