/**************************************************************************************************************************************
* Fliename: vectorCal.h
* Decription: Declare the vectorCal.c functions
* Author: Jackie Herrick
* Date: 10/26/26
**************************************************************************************************************************************/
#include <stdio.h>
#include <string.h>


typedef struct
{
    char name[50];
    float x;
    float y;
    float z;
} Vector;



Vector add(Vector a, Vector b);
Vector sub(Vector a, Vector b);
float DotProduct(Vector a, Vector b);
Vector CrossProduct(Vector a, Vector b);
Vector Scalar(Vector a, float c);

void help_print();
void PrintVect(Vector MyVect[], int size);
void fileVector(char* userInput, Vector myVect[], int size);
Vector *fileReader(char *filename, Vector *myVect, int *size);

void Clear(Vector myVect[], int size, int pos);
void fill(Vector myVect[], int pos, int size);
int findvect(char *NewName, Vector myVect[], int size);










