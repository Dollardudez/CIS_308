#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void stringsort(char *strings[], int nstrings, int (*cmpfunc)());
int dictstrcmp(char *str1, char *str2);
int numstrcmp(char *str1, char *str2);
void printArray(char *array[], int size);

int main() {
    char *array1[] = {"Zeppelin", "able", "baker", "Charlie"};
    char *array2[] = {"1", "234", "12", "3", "4", "5", "2"};

    char c = 99;
    printf("%d\n", c);
    printf("---- Before strcmp----\n");
    printArray(array1, 4);
    stringsort(array1, 4, strcmp);
    printf("\n");
    printf("---- After strcmp----\n");
    printArray(array1, 4);

    printf("\n\n");

   /* printf("---- Before Dictionry----\n");
    printArray(array1, 4);
    stringsort(array1, 4, dictstrcmp);
    printf("\n");
    printf("---- After Dictionry----\n");
    printArray(array1, 4);
    printf("\n\n");*/

    printf("---- Before ----\n");
    printArray(array2, 7);
    printf("\n");
    stringsort(array2, 7, numstrcmp);
    printf("---- After ----\n");
    printArray(array2, 7);

    return 0;
}

void stringsort(char *strings[], int nstrings, int (*cmpfunc)()) {

    int i;
    int j;
    for(i = 0; i < nstrings; i++){
        for(j = i+1; j < nstrings; j++){
            if(cmpfunc(strings[i], strings[j]) > 0){
                char * temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

/*int dictstrcmp(char *str1, char *str2) {

    for(int i = 0; i <= strlen(str1); i++){
        str1[i] = tolower(str1[i]);
    }
    for(int i = 0; i <= strlen(str2); i++){
        str2[i] = tolower(str2[i]);
    }
    while(7 !=0 ){
        ;
    }
}*/

    int numstrcmp(char *str1, char *str2) {
        for(int i = 0; i <  strlen(str1); i++){
            for(int j = 0; j < strlen(str2); j++){
                if(strlen(str1) > strlen(str2)) return 1;
                if(str1[i] == str2[j]) {
                    if(strlen(str1) > strlen(str2)) return 1;
                    else return 0;
                }
                else if (str1[i] < str2[j]) return -1;
                else return 1;
            }
        }
        return 1;
    }



void printArray(char *array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");
}
