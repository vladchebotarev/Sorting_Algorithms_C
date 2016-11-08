#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void insert_sort(int *a, int n)
{
	int i, j, x;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while ((j>0) && (a[j]>x))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}


void select_sort(int *a, int n) {
	int i, j, k, x;


	for (i = 0; i < n; i++) {
		k = i;
		x = a[i];

		for (j = i + 1; j < n; j++)
		if (a[j] < x) {
			k = j;
			x = a[j];
		}

		a[k] = a[i];
		a[i] = x;
	}
}


void bubble_sort(int *a, int n)
{
	int i, j, k, tmp;
	for (i = 0; i<n - 1; i++)
	{
		for (j = n - 2; j >= i; j--)
		if (a[j]>a[j + 1])
		{
			tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
	}
}


void quick_sort(int *a, int p, int k)
{
	int i = p, j = k, s, tmp;
	s = a[(i + j) / 2];
	do
	{
		while (a[i]<s)
			i++;
		while (a[j]>s)
			j--;
		if (i <= j)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j>p) quick_sort(a, p, j);
	if (i<k) quick_sort(a, i, k);
}

void Shells_sort(int *a, int n){

	int i, j, k, t;
	for (k = n / 2; k > 0; k /= 2)
	for (i = k; i < n; i++)
	{
		t = a[i];
		for (j = i; j >= k; j -= k)
		{
			if (t < a[j - k])
				a[j] = a[j - k];
			else
				break;
		}
		a[j] = t;
	}
}


void siftDown(int *numbers, int root, int bottom) {
	int done, maxChild, temp;
	done = 0;
	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom)
			maxChild = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if (numbers[root] < numbers[maxChild]) {
			temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
}


void heapSort(int *numbers, int array_size) {
	int i, temp;
	for (i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size);
	for (i = array_size - 1; i >= 1; i--) {
		temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}