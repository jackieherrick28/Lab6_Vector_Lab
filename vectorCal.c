/**************************************************************************************************************************************
* Fliename: vectorCal.c
* Decription: Define the vectorCal.c functions
* Author: Jackie Herrick
* Date: 10/26/26
**************************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "vectorCal.h"


    // // vect is a typedef'ed struct
   Vector add(Vector a, Vector b)
    {
        Vector add;
        add.x = a.x + b.x;
        add.y = a.y + b.y;
        add.z = a.z + b.z;
        return add;
    }


    Vector sub(Vector a, Vector b)
    {
        Vector sub;
        sub.x = a.x - b.x;
        sub.y = a.y - b.y;
        sub.z = a.z - b.z;
        return sub;
    }


    float DotProduct(Vector a, Vector b)
    {
        
        float dot = ((a.x)*(b.x)) + ((a.y)*(b.y))+((a.z)*(b.z));
        return dot;

    }


    Vector CrossProduct(Vector a, Vector b)
    {
        Vector cross;
        cross.x = ((a.y)*(b.z)) - ((a.z)*(b.y));
        cross.y = ((a.z)*(b.x)) - ((a.x)*(b.z));
        cross.z = ((a.x)*(b.y)) - ((a.y)*(b.x));
        return cross;
    }

    Vector Scalar(Vector a, float c)
    {
        Vector scal;
        scal.x = c*(a.x);
        scal.y = c*(a.y);
        scal.z = c*(a.z);
        return scal;
    }
   
    void PrintVect(Vector myVect[], int size)
    {
        int j = 1;
        for(int i = 0; i<size;i++)
        {
            if(!(myVect[i].x == 0 && myVect[i].y == 0 && myVect[i].z == 0))
            {
            j++;
            printf("The vector %s has an x componet of %0.3f, y componet of %0.3f, z componet of %0.3f\n", myVect[i].name, myVect[i].x,myVect[i].y, myVect[i].z);
            }
        }
        if(j==1)
        {
            printf("Vector Storage is empty\n");
        }
    }

    void fileVector(char* userInput, Vector myVect[], int size)
    {
        FILE *file_ptr;
        char filename[100];
        //char *userInput = "vector_Calc";

        sprintf(filename, "%s.csv", userInput);

        file_ptr = fopen(filename, "w");

        if (file_ptr == NULL)
        {
            printf("Error opening file.\n");
            return;
        }

        //fseek(file_ptr,0,SEEK_SET);
        fprintf(file_ptr, "Name:, x: , y: , z:\n");
        for(int i = 0; i<size; i++)
        {
            if(!(myVect[i].x == 0 && myVect[i].y == 0 && myVect[i].z == 0))
            {
            fprintf(file_ptr, "%s,%f,%f,%f\n",  myVect[i].name, myVect[i].x,myVect[i].y, myVect[i].z);
            }
        }
        
        fclose(file_ptr);
        
    }

    Vector *fileReader(char *filename, Vector *myVect, int *size)
    {
        FILE *fp = fopen(filename, "r");
        Clear(myVect, *size, 0);
        if(fp == NULL)
        {
            printf("Unable to open file %s\n", filename);
            return myVect;
        }

        char line[200];
        int i = 0;

        /* skip header */
        fgets(line, sizeof(line), fp);

        while(fgets(line, sizeof(line), fp))
        {
            if(i >= *size)
            {
                *size += 10;

                Vector *temp = realloc(myVect, sizeof(Vector) * (*size));

                if(temp == NULL)
                {
                    printf("Unable to allocate more memory\n");
                    fclose(fp);
                    return myVect;
                }

                myVect = temp;


                //printf("Expanded vector storage to %d vectors\n", *size);
            }

            if(sscanf(line, "%[^,],%f,%f,%f", myVect[i].name, &myVect[i].x, &myVect[i].y, &myVect[i].z) == 4)
            {
                i++;
            }
        }

        fclose(fp);

        printf("%d vectors loaded\n", i);

        return myVect;
    }

    void fill(Vector myVect[], int pos, int size)
    {
        srand(time(NULL));
        char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        for(int i = pos; i < size; i++)
        {
            int ranIndex = rand() % (sizeof(abc) - 1);

            char NewName[2];
            NewName[0] = abc[ranIndex];
            NewName[1] = '\0';

            int index = findvect(NewName, myVect, i);

            if(index == -1)
            {
                strcpy(myVect[i].name, NewName);

                myVect[i].x = rand() % 100;
                myVect[i].y = rand() % 100;
                myVect[i].z = rand() % 100;
            }
            else
            {
                i--;    // retry
            }
        }
    }


    void Clear(Vector myVect[], int size, int pos)
    {
        //Creating a blank Array of vector
        for(int i = pos; i<size; i++)
        {
            strcpy(myVect[i].name, " ");
            myVect[i].x = 0;
            myVect[i].y = 0;
            myVect[i].z = 0;
        }
    }
    // -1 means unique name
    // anything else is the location of the vector with the same name
    int findvect(char *NewName, Vector myVect[], int size)
    {
        for(int i = 0; i < size; i++)
        {
            if(!strcmp(NewName, myVect[i].name))
            {
                return i;
            }
        }  
        return -1;
    }
    void help_print()
    {
        printf("\n\t\t\t\tVector Calculator Help:");
        printf("\n__________________________________________________________________________________________________________");
        printf("\n\n\tCommand                                                   Description\n");
        printf("__________________________________________________________________________________________________________\n");
        printf("\n\tquit                                                     Exit the Program\n");
        printf("\tclear                                                    Clear all Vectors\n");
        printf("\tlist                                                     List all non-zero Vectors\n");
        printf("\tsave <file name>                                         save all non-zero Vectors to the CVS file\n");
        printf("\tload <file name>                                         load all non-zero Vectors from the given CVS file name\n");
        printf("\tVector Name = X-componet y-componet z-componet           Creating a Vector\n");
        printf("\tc = a + b                                                adding 2 vectors and store result\n");
        printf("\tc = a - b                                                subtracting 2 vectors and store result\n");
        printf("\tc = a x b                                                cross product of 2 vectors and store result\n");
        printf("\tc = a * 2                                                Scalar multiplication and store result\n");
        printf("\ta + b                                                    adding 2 vectors\n");
        printf("\ta - b                                                    subtracting 2 vectors\n");
        printf("\ta . b                                                    dot product of 2 vectors\n");
        printf("\ta x b                                                    cross product of 2 vectors\n");
        printf("\ta * 2                                                    Scalar multiplication\n");
        printf("\tfill                                                     fills the vector storage with 10 random vectors\n");
        printf("\t                                                         Note: fill only goes up to max single letters 52\n");
    }


