//on the command line in the directory where the c file is
//Run 'sudo gcc -o assign assign.c'
//Next run './assign arg1 arg2' plus the arguments arg1, arg2, .....

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXCHAR 1000

struct keyword_args{
    char keyword[10];
    int count;
};
int main(int argc, char** argv){
    struct keyword_args kwgs[argc];
    for( int i=0;i<argc;i++){
        int cnt=0;
        strcpy(kwgs[i].keyword,argv[i]);

        //read text from input stream
        char str[100];

        printf("Enter string: \n");

        gets(str);

        //reading text from text file
        //uncomment to test
        //FILE *fp;
        //char fstr[MAXCHAR];

        //char* filename = "test.txt";
        //fp = fopen(filename,"r");
        //if (fp == NULL){
        //    printf("could not open file %s",filename);
        //    return 1;
        //}
        //while(fgets(fstr,MAXCHAR,fp)!=NULL){
        //    printf("Text from file: %s\n", fstr);

        //}
        //fclose(fp);

        //split the string into words

        char *token = strtok(str," ");
        while(token != NULL){

            //check if keyword is in array of words
            if(strcmp(token,kwgs[i].keyword) == 0){

                //if present increment count
                ++cnt;

                //print the keyword and count
                printf("\n%s - %d times\n",kwgs[i].keyword,cnt);

            }
            //printf("\nToken not found\n");


            token = strtok(NULL," ");

        }

    };
    return 0;
}
