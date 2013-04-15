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
} rota;

rota *aux;

int comparar(rota a, rota b)
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

void merge(rota *a, int size)
{
	int mid, i, j, k;

	mid = size / 2;

	i = 0;
	j = mid;
	k = 0;

	for (k=0 ; i<mid && j<size ; k++)
	{

		if (comparar(a[i], a[j]) < 0)
			aux[k]=a[i++];

		else if (comparar(a[i], a[j]) > 0)
			aux[k]=a[j++];

		else
			aux[k]=a[j++];
	}

	if (i == mid)
		while (j < size)
			aux[k++]= a[j++];

	else
		while (i < mid)
			aux[k++]= a[i++];

	for (i = 0; i < size; ++i)
		a[i]= aux[i];
}

void merge_sort(rota *rotas, int size)
{
	int mid;

	if (size > 1)
	{
		mid = size / 2;
		merge_sort(rotas, mid);
		merge_sort(rotas + mid, size - mid);
		merge(rotas, size);
	}
}

int main(int argc, char ** argv)
{
	int n, i;
	rota *rotas;


	scanf("%d", &n);

	rotas = (rota*) malloc (n * sizeof(rota));
	aux = (rota*) malloc (n * sizeof(rota));

	for (i = 0; i < n; i++)
	{
		scanf("%d,%d,%d-%d-%d %d:%d:%d,%f,%f,%s", &rotas[i].registo, &rotas[i].viatura, &rotas[i].t.ano, 
												  &rotas[i].t.mes, &rotas[i].t.dia, &rotas[i].t.horas, 
												  &rotas[i].t.minutos, &rotas[i].t.segundos, &rotas[i].latitude, 
												  &rotas[i].longitude, rotas[i].cidade);
	}

	merge_sort(rotas, n);
	/*imprime_rotas(rotas, n);*/

	return 0;
}

