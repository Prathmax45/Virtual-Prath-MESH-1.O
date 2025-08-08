#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Lmax 100
#define none 101

char get_opcode (char *inst)        // loads the opcode of each specific instruction
{
    if(strcmp(inst,"HLT") == 0)
        return 0;
    if(strcmp(inst,"LA") == 0)
        return 1;
    if(strcmp(inst,"LB") == 0)
        return 2;
    if(strcmp(inst,"ADD") == 0)
        return 3;
    if(strcmp(inst,"SUB") == 0)
        return 4;
    if(strcmp(inst,"MUL") == 0)
        return 5;
    if(strcmp(inst,"PRN") == 0)
        return 6;
    if(strcmp(inst,"JMP") == 0)
        return 7;
    if(strcmp(inst,"JZ") == 0)
        return 8;
    if(strcmp(inst,"INP_A") == 0)
        return 9;
    if(strcmp(inst,"INP_B") == 0)
        return 10;
    if(strcmp(inst,"TRF") == 0)
        return 11;
    if(strcmp(inst ,"RCV") == 0)
        return 12;
    if(strcmp(inst,"CMP") == 0)
        return 13;
    if(strcmp(inst,"PAU") == 0)
        return 14;

    return none;
    
    
}

int main(int argc , char *argv[])
{
    if(argc > 3)
    {
        printf("insufficient arguments passed !!");
        exit(1);
    }
    FILE *input = fopen(argv[1],"r");   // read only mode
    FILE *output = fopen(argv[2],"wb"); // writing in output file in binary

    char line[Lmax];
    while (fgets(line,sizeof(line),input))
    {
        line[strcspn(line,"\n\r")] = 0;
        if (strlen(line) == 0)
            continue;
        
        char opcode = get_opcode(line);      // conversion to binary

        if(opcode == none)
        {
            printf("Invalid instruction : %s\n",line);
            continue;
        }

        fwrite(&opcode ,sizeof(char), 1 ,output);  // writing in the output binary file


    }
    fclose(input);
    fclose(output);

    printf("Assembling the program is done ");

    return 0;
}