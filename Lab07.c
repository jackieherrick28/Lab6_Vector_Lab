/**************************************************************************************************************************************
* Filename: Lab05.c
* Description: Define the vectorCal.c functions
* Author: Jackie Herrick
* Date: 10/14/26
**************************************************************************************************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "vectorCal.h"
 
int main(void)
{
    int size = 10;
    int i = 0;

    char *token0;
    char *token1;
    char *token2;
    char *token3;
    char *token4;
    char user_input0[80];
   
         srand(time(NULL));

        Vector *myVect = malloc(sizeof(Vector) * size);

            if (myVect == NULL)
            {
                printf("Memory allocation failed\n");
            }
        // Clear vector array
         Clear( myVect, size, 0);

        
        printf("Welcome to my Vector Calculator program. If you need more info type -h: \n");
        printf("Vector Calculator>> ");
        fgets(user_input0, 80, stdin);
        user_input0[strcspn(user_input0, "\r\n")] = '\0';
        token0 = strtok(user_input0, " ");
    
 
        if((strcmp(token0, "quit")) && (strcmp(token0, "list")) && (strcmp(token0, "clear")) && (strcmp(token0, "-h")) && (strcmp(token0, "fill")) && (strcmp(token0, "export") && (strcmp(token0, "save"))))
        {
            token1 = strtok(NULL, " ");
 
            token2 = strtok(NULL, " ");
 
            token3 = strtok(NULL, " ");
 
            token4 = strtok(NULL, " ");
        } 
  
    while(strcmp(token0, "quit"))
    {
        if(!strcmp(token0, "-h"))
        {
            help_print();
        }
        else if (!strcmp(token0, "list"))
        {
            PrintVect(myVect,size);
        }      
        else if (!strcmp(token0, "clear"))
        {
                size = 10;
                i = 0;
                Clear(myVect, size, i);
                Vector *temp = realloc(myVect, sizeof(Vector) * size);
                if(temp == NULL)
                {
                    printf("Unable to allocate more memory\n");
                    free(myVect);
                }

                myVect = temp;
        }       
        else if (!strcmp(token0, "fill"))
        {
                if(i<50)
                {
                fill(myVect, i, size);
                i = size-1;
                }
                
 
        }    
        else if (!strcmp(token0, "save"))
        {
            if (token1 == NULL)
            {
                printf("please enter in this: save <filename>\n");
            }
            else
            {
                if (*token1 == '<')
                {
                    token1++;
                }
                char *end = strchr(token1, '>');
                if (end != NULL)
                {
                    *end = '\0';
                }
                fileVector(token1, myVect, size);
                size = 10;
                i = 0;
                Clear(myVect, size, i);
                Vector *temp = realloc(myVect, sizeof(Vector) * size);
                if(temp == NULL)
                {
                    printf("Unable to allocate more memory\n");
                    free(myVect);
                }

                myVect = temp;
            }
        }  else if (!strcmp(token0, "load"))
        {
            if (token1 == NULL)
            {
                printf("please enter in this: load <filename>\n");
            }
            else
            {
                if (*token1 == '<')
                {
                    token1++;
                }

                char *end = strchr(token1, '>');
                if (end != NULL)
                {
                    *end = '\0';
                }
                Clear(myVect, size, i);
                char filename[100];
                sprintf(filename, "%s.csv", token1);

                myVect = fileReader(filename, myVect, &size);
                i = size;
            }
        }
             
         else if((token0 != NULL) && (!strcmp(token1, "+"))&& (token2 != NULL))
        {
            // printf("a + b\n");
            //a + b
            int i0 = findvect(token0, myVect,size);
            int i2 = findvect(token2, myVect,size);
 
            if( i0 == -1 || i2 == -1)
            {
                printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token0, token2);
            } 
            else
            {
                Vector result = add(myVect[i0], myVect[i2]);
                printf("%s + %s gives you a vector has an x componet of %0.3f, y componet of %0.3f, z componet of %0.3f\n", myVect[i0].name, myVect[i2].name, result.x, result.y, result.z);
            }
 
        }        
        else if((token0 != NULL) && (!strcmp(token1, "-"))&& (token2 != NULL))
        {
            // printf("a - b\n");
            //a - b
            int i0 = findvect(token0, myVect,size);
            int i2 = findvect(token2, myVect,size);
 
            if( i0 == -1 || i2 == -1)
            {
                printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token0, token2);
            } 
            else
            {
                Vector result = sub(myVect[i0], myVect[i2]);
                printf("%s - %s gives you a vector has an x componet of %0.3f, y componet of %0.3f, z componet of %0.3f\n", myVect[i0].name, myVect[i2].name, result.x, result.y, result.z);
            }
  
            
 
        } 
         else if((token0 != NULL) && (!strcmp(token1, "x"))&& (token2 != NULL))
        {
            // printf("a x b\n");
            //a x b
            int i0 = findvect(token0, myVect,size);
            int i2 = findvect(token2, myVect,size);
 
            if( i0 == -1 || i2 == -1)
            {
                printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token0, token2);
            } 
            else
            {
                Vector result = CrossProduct(myVect[i0], myVect[i2]);
                printf("%s x %s gives you a vector has an x componet of %0.3f, y componet of %0.3f, z componet of %0.3f\n", myVect[i0].name, myVect[i2].name, result.x, result.y, result.z);
            }
        }
        else if((token0 != NULL) && (!strcmp(token1, "."))&& (token2 != NULL))
        {
            // printf("a . b\n");
            //a . b
            int i0 = findvect(token0, myVect,size);
            int i2 = findvect(token2, myVect,size);
 
            if( i0 == -1 || i2 == -1)
            {
               printf("Vector(s) %s and/or %s do not exist in vector storage.\n", myVect[i0].name, myVect[i2].name);
            } 
            else
            {
                float dot =  DotProduct(myVect[i0],myVect[i2]);
                printf("The dot product of %s . %s = %f\n", myVect[i0].name, myVect[i2].name, dot);
 
            }
        }
        else if((token0 != NULL) && (!strcmp(token1, "*"))&& (token2 != NULL))
        {
            // printf("a * constant\n");
            //a * constant
            int i0 = findvect(token0, myVect,size);
            float c = atof(token2);
 
            if(i0 == -1)
            {
                printf("Vector %s do not exist in vector storage.\n", myVect[i0].name);
            } 
            else
            {
                Vector result = Scalar(myVect[i0], c);
                printf("%s * %f gives you a vector has an x componet of %0.3f, y componet of %0.3f, z componet of %0.3f\n", myVect[i0].name, c, result.x, result.y, result.z);
                
            }
 
        } 
        else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "+"))&& (token4 != NULL))
        {
            // printf("c = a + b\n");
            //c = a + b
            int i2 = findvect(token2, myVect,size);
            int i4 = findvect(token4, myVect,size);
            int i0 = findvect(token0, myVect,size);
 
            if(i<size)
            {
                if( i2 == -1 || i4 == -1)
                {
                        printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token2, token4);
                }
                else
                { 
 
                        strcpy(myVect[i2].name, token2);
                        strcpy(myVect[i4].name, token4);
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
            else               
            {
                if(i0 == -1)
                {
                    printf("Unable to do this command becuase the vector Storage is full\n");
                }else
                {
                        printf("Vector %s is now being replaced\n", myVect[i0].name);
                        myVect[i0] = add(myVect[i2],myVect[i4]);
                        strcpy(myVect[i0].name, token0);
                }
            }
        }  
        else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "-"))&& (token4 != NULL))
        {
            // printf("c = a - b\n");
            //c = a - b
            int i2 = findvect(token2, myVect,size);
            int i4 = findvect(token4, myVect,size);
            int i0 = findvect(token0, myVect,size);
 
            if(i<size)
            {
                if( i2 == -1 || i4 == -1)
                {
                printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token2, token4);
                }
                else
                {   
                        strcpy(myVect[i2].name, token2);
                        strcpy(myVect[i4].name, token4);
                    if(i0 == -1)
                    {
                        myVect[i] = sub(myVect[i2],myVect[i4]);
                        strcpy(myVect[i].name, token0);
                        i++;
                    }
                    else
                    {
                    
                        printf("Vector %s is now being replaced\n", myVect[i0].name);
                        myVect[i0] = sub(myVect[i2],myVect[i4]);
                        strcpy(myVect[i0].name, token0);
  
                    }
                }
            }
            else               
            {
                if(i == -1)
                 {
                        printf("Unable to do this command becuase the vector Storage is full\n");
                 }
                 else
                 {
                        printf("Vector %s is now being replaced\n", myVect[i0].name);
                        myVect[i0] = sub(myVect[i2],myVect[i4]);
                        strcpy(myVect[i0].name, token0);
                 }
            }
        }
        else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "x"))&& (token4 != NULL))
        {
            // printf("c = a x b\n");
            //c = a x b
            int i2 = findvect(token2, myVect,size);
            int i4 = findvect(token4, myVect,size);
            int i0 = findvect(token0, myVect,size);
 
            if(i<size)
            {
                if( i2 == -1 || i4 == -1)
                {
                        printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token2, token4);
                }
                else
                {
                        strcpy(myVect[i2].name, token2);
                        strcpy(myVect[i4].name, token4);
                    
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
            else               
            {
                 if(i == -1)
                 {
                    printf("Unable to do this command becuase the vector Storage is full\n");
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
                // printf("c = a . b\n");
                //c = a . b
                int i2 = findvect(token2, myVect,size);
                int i4 = findvect(token4, myVect,size);
 
                if( i2 == -1 || i4 == -1)
                {
                printf("Vector(s) %s and/or %s do not exist in vector storage.\n", token2, token4);
                }
                else
                {
 
                        float dot = DotProduct(myVect[i2],myVect[i4]);
                        printf("Note: the dot product is a Scalar not an vector. So nothing is stored but %s . %s = %f\n", (myVect[i2].name), (myVect[i4].name), dot);
 
                }
        }
 
          else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (!strcmp(token3, "*"))&& (token4 != NULL))
            {
                int i2 = findvect(token2, myVect,size);
                int i0 = findvect(token0, myVect,size);
                int i4 = findvect(token4, myVect,size);
 
                if( i2 == -1 && i4 == -1 )
                {
                        printf("Vector %s and %s do not exist in vector storage.\n", token2, token4);

                }
                else if((i<size) && (i2 != -1))
                {
                        float constant = atoi(token4);
                        strcpy(myVect[i2].name, token2);
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
                else if((i<size) &&(i4 != -1))
                {
                        float constant = atoi(token2);
                        strcpy(myVect[i4].name, token4);
                        if(i0 == -1)
                        {
                            myVect[i] = Scalar(myVect[i4],constant);
                            strcpy(myVect[i].name, token0);
                            i++;
                        }
                        else
                        {
                            printf("Vector %s is now being replaced\n", myVect[i0].name);
                            myVect[i0] = Scalar(myVect[i4],constant);
                            strcpy(myVect[i0].name, token0);
                        }
                } 
                else 
                {
                            printf("Unable to do this command becuase the vector Storage is full\n");
                }
 
            }   
        
 
        else if((token0 != NULL) && (!strcmp(token1, "=")) && (token2 != NULL) && (token3 != NULL))
        {
            int i0 = findvect(token0, myVect,size);
            if(i<size)
            {
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
            else
            {
                if(i0==-1)
                {
                    printf("Unable to do this command becuase the vector Storage is full\n");
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
 
        } 
        else
        {
             printf("invalid command\n");
        } 
           if(i >= size-1)
            {
                int oldSize = size;
                size += 10;

                Vector *temp = realloc(myVect, sizeof(Vector) * size);

                if(temp == NULL)
                {
                    printf("Unable to allocate more memory\n");
                    free(myVect);
                }

                myVect = temp;

                /* ONLY clear the NEW elements */
                Clear(myVect, size, oldSize);
            }
 
                printf("Vector Calculator>> ");
                fgets(user_input0, 80, stdin);
                user_input0[strcspn(user_input0, "\r\n")] = '\0';
 
                token0 = strtok(user_input0, " ");
 
            if(((strcmp(token0, "quit")) && (strcmp(token0, "list")) && (strcmp(token0, "clear")) && (strcmp(token0, "-h"))&&(strcmp(token0, "fill"))))
            {
                token1 = strtok(NULL, " ");
 
                token2 = strtok(NULL, " ");
 
                token3 = strtok(NULL, " ");
 
                token4 = strtok(NULL, " ");
            } 
        //size = sizeof(*myVect);
    }
 
    printf("Goodbye and here is the vectors the program has collected:\n");
    PrintVect(myVect,size); 
    free(myVect);
    return 0;
}