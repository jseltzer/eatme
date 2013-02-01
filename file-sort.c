/*
Josh Samson - Seltzer
ICS CLass, 2013
Assignment 2
*/


#include <stdio.h>
#include <stdlib.h>

void sort(int array[], int a_count)
{
        int i,n,x;
        for (i = 1; i < a_count; i++)
        {
                n = array[i];
                for (x = i; x > 0 && array[x-1] > n; x--)
                        array[x] = array[x-1];
                array[x] = n;
        }
}

void print(int array[], int leng)
{
        int i;
        for (i=0 ; i!=leng; i++) 
                if (array[i]!='\n') {
			printf("%d ", array[i]);
        	}
	printf("\n");
}

int main(int argc, char** argv) {
	FILE* fp = fopen("2.txt", "r");
	int c;
	int lines = 0;
	while((c = fgetc(fp)) != EOF) {
		if(c == '\n') lines++;
	}
	fseek(fp, 0, SEEK_SET);
	int* list = malloc(lines * sizeof(int)); 
	char line[128];
	int i = 0;
	while(fgets(line, 128, fp) != NULL) {
		list[i] = atoi(line);
		i++;
	}

	printf("Integers from File:\n");
	print(list,lines);
	printf("\nSorted Integers:\n");
	sort(list, lines);
	print(list,lines);
	fclose(fp);
}
