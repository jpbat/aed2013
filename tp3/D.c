#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 256

#define PI 3.14159265
#define d2r (PI / 180.0)


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
	double distancia;
} rota;

double distancia(rota r)
{
	/*dlon = lon2 - lon1 */
	/*dlat = lat2 - lat1 */
	/*a = (sin(dlat/2))^2 + cos(lat1) * cos(lat2) * (sin(dlon/2))^2 */
	/*c = 2 * atan2(sqrt(a), sqrt(1-a))  */
	/*d = R * c */

	int R = 6371;

	double lat1 = 38.750;
	double lon1 = -9.110;
	double lat2 = r.latitude;
	double lon2 = r.longitude;

	double dlong = (lon2 - lon1) * d2r;
	double dlat = (lat2 - lat1) * d2r;
	double a = pow(sin(dlat/2.0), 2) + cos(lat1*d2r) * cos(lat2*d2r) * pow(sin(dlong/2.0), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	double d = R * c;

	return d;
}

double comparar(rota a, rota b)
{
	return a.distancia - b.distancia;
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

void swap(rota *a, rota *b)
{
	rota temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort(rota *a, int m, int n)
{
	rota key;
	int i, j, k;

	if (m < n)
	{
		k = (m + n) / 2;
		swap(&a[m], &a[k]);
		key = a[m];
		i = m + 1;
		j = n;

		while(i <= j)
		{
			while(i <= n && comparar(a[i], key) <= 0)
				i++;
			while(j >= m && comparar(a[j], key) > 0)
				j--;
			if( i < j)
				swap(&a[i], &a[j]);
		}
		swap(&a[m], &a[j]);
		quick_sort(a,m,j-1);
		quick_sort(a,j+1,n);
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
		rotas[i].distancia = distancia(rotas[i]);
	}

	quick_sort(rotas, 0, n-1);
	imprime_rotas(rotas, n);

	return 0;
}
