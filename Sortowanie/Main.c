#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorytmy.h"


int read_file(int *tabl, int n, int type);
void save_file(FILE *file, int *tabl, int n);
void liczby_losowe(int *tabl, int n);
void liczby_sortowane_losowo(int *tabl, int n);
void liczby_sort(int *tabl, int n);

int main(void){
	srand(time(NULL));
	
	printf("************************MENU***************************\n\n");
	printf("Prosze wpisac rozmiar tablic: ");
	int n; scanf("%d", &n);
	
	int *tabl;
	tabl = (int *)malloc(sizeof(int)*n);

	printf("Prosze czekac, tworza sie tablicy o rozmiarze %d", n);
	FILE *file_rand, *file_sort, *file_sort_rev;
	file_rand = fopen("rand.txt", "w");
	file_sort_rev = fopen("revers.txt", "w");
	file_sort = fopen("sort.txt", "w");
	int i;
	for (i = 0; i < n; i++)
	{
		tabl[i] = rand() % 201 - 100;
		fprintf(file_rand, "%d\t", tabl[i]);
	}
	heapSort(tabl, n);
	for (i = 0; i < n; i++) fprintf(file_sort, "%d\t", tabl[i]);
	for (i = n - 1; i >= 0; i--) fprintf(file_sort_rev, "%d\t", tabl[i]);
	fclose(file_rand);
	fclose(file_sort);
	fclose(file_sort_rev);
	printf("\nTablicy zostaly utworzone\n\n");

	printf("Prosze wybrac rodzaj tablicy:\n\n");
	printf("1 -> Dla danych wygenerowanych losowo\n");
	printf("2 -> Dla danych posortowanych w kolejnosci odwrotnej\n");
	printf("3 -> Dla danych posortowanych wlasciwie\n");
	int cykl = 1;
	while (cykl){
		int q;
		scanf("%d", &q);
		switch (q){
		case 1:
			liczby_losowe(tabl, n);
			cykl = 0;
			break;
		case 2:
			liczby_sortowane_losowo(tabl, n);
			cykl = 0;
			break;
		case 3:
			liczby_sort(tabl, n);
			cykl = 0;
			break;

		default: printf("Wybierz jeszcze raz\n");
		}
	}
	free(tabl);
	system("pause");

}	

int read_file(int *tabl, int n, int type)// 1-losowy 2-odwrotnie 3-normalnie
{
	int i;
	FILE *file;
	switch (type)
	{
	case 1: file = fopen("rand.txt", "r");  break;
	case 2: file = fopen("revers.txt", "r"); break;
	case 3: file = fopen("sort.txt", "r"); break;
	default: file = NULL;
	}

	
	if (file == NULL)
	{
		printf("\nPlik sie nie otwiera\n");
		return -1;
	}

	for (i = 0; i < n; i++)fscanf(file, "%d", &tabl[i]);

	fclose(file);
	return 0;

}

void save_file(FILE *file, int *tabl, int n)
{
	int i;
	for (i=0; i < n; i++)
	
		fprintf(file, "%d\t", tabl[i]);
	

}

void liczby_losowe (int *tabl, int n)
{
	FILE *file_insert, *file_select, *file_buble, *file_quick, *file_shell, *file_heap;
	
	file_insert = fopen("sort_insert.txt ", "w");
	file_select = fopen("sort_select.txt ", "w");
	file_buble = fopen("sort_buble.txt ", "w");
	file_quick = fopen("sort_quick.txt ", "w");
	file_shell = fopen("sort_shell.txt ", "w");
	file_heap = fopen("sort_heap.txt ", "w");
	
	printf("Metoda\t\t\t\tCzas\n\n");

	clock_t t1, t2;
		

	read_file(tabl, n, 1);
	t1 = clock();
	insert_sort(tabl, n);
	t2 = clock();
	save_file(file_insert, tabl, n);
	printf("Przez wstawianie\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 1);
	t1 = clock();
	select_sort(tabl, n);
	t2 = clock();
	save_file(file_select, tabl, n);
	printf("Przez selekcje\t\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);
	
	
	read_file(tabl, n, 1);
	t1 = clock();
	bubble_sort(tabl, n);
	t2 = clock();
	save_file(file_buble, tabl, n);
	printf("Sortowanie babelkowe\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);
	
	
	read_file(tabl, n, 1);
	t1 = clock();
	quick_sort(tabl, 0, n-1);
	t2 = clock();
	save_file(file_quick, tabl, n);
	printf("Quicksort\t\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);
	
	
	read_file(tabl, n, 1);
	t1 = clock();
	Shells_sort(tabl, n);
	t2 = clock();
	save_file(file_shell, tabl, n);
	printf("Sortowanie Shella\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 1);
	t1 = clock();
	heapSort(tabl, n);
	t2 = clock();
	save_file(file_heap, tabl, n);
	printf("Przez kopcowanie\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);
	
	fclose(file_insert);
	fclose(file_select);
	fclose(file_buble);
	fclose(file_quick);
	fclose(file_shell);
	fclose(file_heap);

}



void liczby_sortowane_losowo(int *tabl, int n)
{
	FILE *file_insert, *file_select, *file_buble, *file_quick, *file_shell, *file_heap;

	file_insert = fopen("sort_insert.txt ", "w");
	file_select = fopen("sort_select.txt ", "w");
	file_buble = fopen("sort_buble.txt ", "w");
	file_quick = fopen("sort_quick.txt ", "w");
	file_shell = fopen("sort_shell.txt ", "w");
	file_heap = fopen("sort_heap.txt ", "w");

	printf("Metoda\t\t\t\tCzas\n");

	clock_t t1, t2;


	read_file(tabl, n, 2);
	t1 = clock();
	insert_sort(tabl, n);
	t2 = clock();
	save_file(file_insert, tabl, n);
	printf("Przez wstawianie\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 2);
	t1 = clock();
	select_sort(tabl, n);
	t2 = clock();
	save_file(file_select, tabl, n);
	printf("Przez selekcje\t\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 2);
	t1 = clock();
	bubble_sort(tabl, n);
	t2 = clock();
	save_file(file_buble, tabl, n);
	printf("Sortowanie babelkowe\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 2);
	t1 = clock();
	quick_sort(tabl, 0, n - 1);
	t2 = clock();
	save_file(file_quick, tabl, n);
	printf("Quicksort\t\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 2);
	t1 = clock();
	Shells_sort(tabl, n);
	t2 = clock();
	save_file(file_shell, tabl, n);
	printf("Sortowanie Shella\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 2);
	t1 = clock();
	heapSort(tabl, n);
	t2 = clock();
	save_file(file_heap, tabl, n);
	printf("Przez kopcowanie\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);

	fclose(file_insert);
	fclose(file_select);
	fclose(file_buble);
	fclose(file_quick);
	fclose(file_shell);
	fclose(file_heap);

}



void liczby_sort (int *tabl, int n)
{
	FILE *file_insert, *file_select, *file_buble, *file_quick, *file_shell, *file_heap;

	file_insert = fopen("sort_insert.txt ", "w");
	file_select = fopen("sort_select.txt ", "w");
	file_buble = fopen("sort_buble.txt ", "w");
	file_quick = fopen("sort_quick.txt ", "w");
	file_shell = fopen("sort_shell.txt ", "w");
	file_heap = fopen("sort_heap.txt ", "w");

	printf("Metoda\t\t\t\tCzas\n");

	clock_t t1, t2;


	read_file(tabl, n, 3);
	t1 = clock();
	insert_sort(tabl, n);
	t2 = clock();
	save_file(file_insert, tabl, n);
	printf("Przez wstawianie\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 3);
	t1 = clock();
	select_sort(tabl, n);
	t2 = clock();
	save_file(file_select, tabl, n);
	printf("Przez selekcje\t\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 3);
	t1 = clock();
	bubble_sort(tabl, n);
	t2 = clock();
	save_file(file_buble, tabl, n);
	printf("Sortowanie babelkowe\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 3);
	t1 = clock();
	quick_sort(tabl, 0, n - 1);
	t2 = clock();
	save_file(file_quick, tabl, n);
	printf("Quicksort\t\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 3);
	t1 = clock();
	Shells_sort(tabl, n);
	t2 = clock();
	save_file(file_shell, tabl, n);
	printf("Sortowanie Shella\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);


	read_file(tabl, n, 3);
	t1 = clock();
	heapSort(tabl, n);
	t2 = clock();
	save_file(file_heap, tabl, n);
	printf("Przez kopcowanie\t\t%.3lf\n", (double)(t2 - t1) / (double)CLOCKS_PER_SEC);

	fclose(file_insert);
	fclose(file_select);
	fclose(file_buble);
	fclose(file_quick);
	fclose(file_shell);
	fclose(file_heap);

}
