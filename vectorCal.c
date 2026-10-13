/**************************************************************************************************************************************
* Fliename: vectorCal.c
* Decription: Define the vectorCal.c functions
* Author: Jackie Herrick
* Date: 09/29/26
**************************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
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
    
    void PrintVect(Vector MyVect[], int size)
    {
        for(int i = 0; i<size;i++)
        {
            printf("The vector %s has an x componet of %0.3f, y componet of %0.3f, z componet of %0.3f\n", MyVect[i].name, MyVect[i].x,MyVect[i].y, MyVect[i].z);
        }
    }

    void Clear(Vector myVect[], int size)
    { 
        //Creating a blank Array of vector
        for(int i = 0; i<size; i++)
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
        printf("\n\tquit                                                      Exit the Program\n");
        printf("\tclear                                                     Clear all Vectors\n");
        printf("\tlist                                                      List all Vectors\n");
        printf("\tvarname                                                   Display a Vector\n");
        printf("\tVector Name = X-componet y-componet z-componet            Creating a Vector\n");
        printf("\tc = a + b                                                 adding 2 vectors and store result\n");
        printf("\tc = a - b                                                 subtracting 2 vectors and store result\n");
        printf("\ta . b                                                     dot product of 2 vectors and the result will be printed\n");
        printf("\tc = a x b                                                 cross product of 2 vectors and store result\n");
        printf("\tc = a * 2                                                 Scalar multiplication\n\n");
    }