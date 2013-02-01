#include <stdio.h>
#include <stdlib.h>
#include "isort.h"
 
int count_lines(FILE* fp);
 
int main(int argc, char** argv) {
FILE* fp = fopen("example.txt", "r");
int lines = count_lines(fp);
 
int* nums = malloc(lines * sizeof(int));
 
char line[128];
int i = 0;
while(fgets(line, 128, fp) != NULL) {
nums[i] = atoi(line);
i++;
}
 
isort(nums, lines);
for(i = 0; i < lines; i++) {
printf("%d\n", nums[i]);
}
}
 
/*
* Note: Assumes no '\n' on last line
*/
int count_lines(FILE* fp) {
int c;
int lines = 0;
while((c = fgetc(fp)) != EOF) {
if(c == '\n') {
lines++;
}
}
fseek(fp, 0, SEEK_SET);
return lines;
}
