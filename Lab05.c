/**************************************************************************************************************************************
* Filename: Lab05.c
* Description: Define the vectorCal.c functions
* Author: Jackie Herrick
* Date: 09/29/26
**************************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vectorCal.h"

int main(void)
{
    
    int size = 10;
    Vector myVect[size];

    char user_input0[80];


    char *token0;
    char *token1;
    char *token2;
    char *token3;
    char *token4;


    int i = 0;


    // Clear vector array
    Clear(myVect, size);


    printf("Welcome to my Vector Calculator program. If you need more info type -h: \n");
    printf("Vector Calculator>> ");
    fgets(user_input0, 80, stdin);
    user_input0[strcspn(user_input0, "\r\n")] = '\0';
    token0 = strtok(user_input0, " ");
    

        if(((strcmp(token0, "quit")) && (strcmp(token0, "list")) && (strcmp(token0, "clear")) && (strcmp(token0, "-h"))))
        {
            token1 = strtok(NULL, " ");

            token2 = strtok(NULL, " ");

            token3 = strtok(NULL, " ");

            token4 = strtok(NULL, " ");
        } 


    while(strcmp(token0, "quit")&&(i<(size-1)))
    {
        if(!strcmp(token0, "-h"))
        {
            help_print();
        }
        else if (!strcmp(token0, "list"))
        {
            PrintVect(myVect, size);
            // printf("i: %d\n", i);
        }      
        else if (!strcmp(token0, "clear"))
        {
            Clear(myVect, size);
            i = 0;
        }             
         else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "+"))&& (token4 != NULL))
        {
            //c = a + b
            int i2 = findvect(token2, myVect, size);
            int i4 = findvect(token4, myVect, size);

            if( i2 == -1 || i4 == -1)
            {
                printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token2, token4);
            } 
            else
            {
                strcpy(myVect[i2].name, token2);
                strcpy(myVect[i4].name, token4);

                int i0 = findvect(token0, myVect, size);
                if(i0 == -1)
                {
                    myVect[i] = add(myVect[i2],myVect[i4]);
                    strcpy(myVect[i].name, token0);
                    i++;
                } 
                else
                {

                    printf("Vector %s is now being replaced\n", myVect[i0].name);
                    myVect[i0] = add(myVect[i2],myVect[i4]);
                    strcpy(myVect[i0].name, token0);

                }
            }

        }        
        else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "-"))&& (token4 != NULL))
        {
            //c = a - b
            int i2 = findvect(token2, myVect, size);
            int i4 = findvect(token4, myVect, size);

            if( i2 == -1 || i4 == -1)
            {
                printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token2, token4);
            } 
            else
            {
                strcpy(myVect[i2].name, token2);
                strcpy(myVect[i4].name, token4);

                int i0 = findvect(token0, myVect, size);
                if(i0 == -1)
                {
                    
                    myVect[i] = sub(myVect[i2],myVect[i4]);
                    strcpy(myVect[i].name, token0);
                    i++;
                } 
                else
                {
                    strcpy(myVect[i0].name, token0);
                    printf("Vector %s is now being replaced\n", myVect[i0].name);
                    myVect[i0] = sub(myVect[i2],myVect[i4]);

                }

            }

        } 
         else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "x"))&& (token4 != NULL))
        {
            //c = a x b
            int i2 = findvect(token2, myVect, size);
            int i4 = findvect(token4, myVect, size);

            if( i2 == -1 || i4 == -1)
            {
               printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token2, token4);
            } 
            else
            {
                strcpy(myVect[i2].name, token2);
                strcpy(myVect[i4].name, token4);
                int i0 = findvect(token0, myVect, size);
                if(i0 == -1)
                {
                    myVect[i] = CrossProduct(myVect[i2],myVect[i4]);
                    strcpy(myVect[i].name, token0);
                    i++;
                } 
                else
                {
                    
                    printf("Vector %s is now being replaced\n", myVect[i0].name);
                    myVect[i0] = CrossProduct(myVect[i2],myVect[i4]);
                    strcpy(myVect[i0].name, token0);

                }

            }
        }
        else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "."))&& (token4 != NULL))
        {
            //c = a x b
            int i2 = findvect(token2, myVect, size);
            int i4 = findvect(token4, myVect, size);

            if( i2 == -1 || i4 == -1)
            {
               printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token2, token4);
            } 
            else
            {
                strcpy(myVect[i2].name, token2);
                strcpy(myVect[i4].name, token4);

                    float dot = DotProduct(myVect[i2],myVect[i4]);
                    printf("The dot product of %s . %s = %f\n", token2, token4, dot);


            }
        }
        else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "*"))&& (token4 != NULL))
            {
                int i2 = findvect(token2, myVect, size);
                float constant = atoi(token4);
                if( i2 == -1 )
                {
                printf("Vector %s do not exist in vector storage.\n", token2);
                } 
                else
                {
                    strcpy(myVect[i2].name, token2);
                    int i0 = findvect(token0, myVect, size);

                    if(i0 == -1)
                    {
                        myVect[i] = Scalar(myVect[i2],constant);
                        strcpy(myVect[i].name, token0);
                        i++;
                    } 
                    else
                    {
                        printf("Vector %s is now being replaced\n", myVect[i0].name);
                        myVect[i0] = Scalar(myVect[i2],constant);
                        strcpy(myVect[i0].name, token0);

                    }

                }

            }       
            else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (token3 != NULL))
            {
                    int i0 = findvect(token0, myVect, size);
                    if(i0 == -1)
                    {
                        strcpy(myVect[i].name, token0);
                        myVect[i].x = atof(token2);
                        myVect[i].y = atof(token3);
                        if(token4 == NULL)
                        {
                            myVect[i].z = 0; 
                        }
                        else
                        {
                            myVect[i].z = atof(token4);
                        }
                        i++;
                    } 
                    else
                    {
                        printf("Vector %s is now being replaced\n", myVect[i0].name);
                        myVect[i0].x = atof(token2);
                        myVect[i0].y = atof(token3);
                        if(token4 == NULL)
                        {
                            myVect[i0].z = 0; 
                        }
                        else
                        {
                            myVect[i0].z = atof(token4);
                        }

                    }

            } 

        printf("Vector Calculator>> ");
        fgets(user_input0, 80, stdin);
        user_input0[strcspn(user_input0, "\r\n")] = '\0';

        token0 = strtok(user_input0, " ");
        // printf("%s", token0);
        // token0[strlen(token0) - 1] = '\0';

        if(((strcmp(token0, "quit")) && (strcmp(token0, "list")) && (strcmp(token0, "clear")) && (strcmp(token0, "-h"))))
        {
            token1 = strtok(NULL, " ");

            token2 = strtok(NULL, " ");

            token3 = strtok(NULL, " ");

            token4 = strtok(NULL, " ");
        } 
   
    }

    printf("Goodbye and here is the vectors the program has collected:\n");
    PrintVect(myVect, size);
    return 0;
}
