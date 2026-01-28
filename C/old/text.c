#include<stdio.h>

int main(void){

    FILE *fp = fopen("data.txt", "a");
    if (fp == NULL)
    {
        printf("Couldn't open file");
        return 1;}
    char data[50];
    
    printf("Enter your text: ");
    fgets(data,sizeof(data),stdin);
    fprintf(fp,"%s",data);
    printf("\nData written in file successfully\n");
    fclose(fp);
    return 0;


}


