#include <stdio.h>
#include <stdlib.h>
#include "externo2.h"

#define CHUNK_SIZE 2

// typedef struct files
// {
// 	FILE *file;
// 	struct files *next;
// } files;


int fileLength(FILE *file)
{
	int length = 0;
	int num;
	while (fscanf(file, "%d", &num) != EOF)
	{
		length++;
	}
	return length;
}

int compara(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void delete_temp_files(int i)
{
	char filename[20];
	sprintf(filename, "temp/temp%d.txt", i);
	remove(filename);
}

void create_chunks(FILE *file, int i)
{
	int num;
	int j = 0;
	char filename[20];
	sprintf(filename, "temp/temp%d.txt", i);
	while (j < CHUNK_SIZE && fscanf(file, "%d", &num) != EOF)
	{
		FILE *chunk = fopen(filename, "a");
		fprintf(chunk, "%d ", num);
		fclose(chunk);
		j++;
	}
}

void external_sort(FILE *file)
{
	int amountOfChunks = fileLength(file) / CHUNK_SIZE;
	for (int i = 0; i < amountOfChunks; i++)
		delete_temp_files(i);

	rewind(file);

	for (int i = 0; !feof(file); i++)
		create_chunks(file, i);

	rewind(file);

	int i = 0;
	while (!feof(file))
	{
		char filename[20];
		sprintf(filename, "temp/temp%d.txt", i);
		FILE *oldTemp = fopen(filename, "r");
		if (!oldTemp)
		{
			perror("Failed to open temporary file");
			exit(EXIT_FAILURE);
		}

		int vector[CHUNK_SIZE];
		int j = 0;
		while (fscanf(oldTemp, "%d", &vector[j]) != EOF)
			j++;

		qsort(vector, CHUNK_SIZE, sizeof(int), compara);
		remove(filename);

		j = 0;
		FILE *newTemp = fopen(filename, "w");
		while (j < CHUNK_SIZE)
		{
			fprintf(newTemp, "%d ", vector[j]);
			j++;
		}
		i++;
		fclose(oldTemp);
		fclose(newTemp);
	}
}

int main()
{
	FILE *input = fopen("input.txt", "r");
	if (!input)
	{
		perror("Failed to open input file");
		exit(EXIT_FAILURE);
	}
	external_sort(input);
	return 0;
}