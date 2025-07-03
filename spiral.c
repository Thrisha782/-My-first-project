//print the array elements in the sprial order

//header file
#include<stdio.h>
#define MAX 10
//main function
void main()
{
    int array[3][3];
    int rows=3;//to store no of rows
    int coloums=3;//to store no of coloums
    //counter variables
    int counter1;
    int counter2;
    int row_length;
    int coloum_length;
    int prints=0;



    //getting the input
    printf("Enter the matrix elements for 3X3 matrix:\n");
    for(counter1=0;counter1<rows;counter1++)
    {
        for(counter2=0;counter2<coloums;counter2++)  
        {
            printf("Enter [%d %d]:",counter1,counter2);
            scanf("%d",&array[counter1][counter2]);
        } 
    }
    //printing the array
    printf("Entered the matrix :\n");
    for(counter1=0;counter1<rows;counter1++)
    {
        for(counter2=0;counter2<coloums;counter2++)  
        {
            printf("%d ",array[counter1][counter2]);
        } 
        printf("\n");
    }
    printf("spiral order:");

    //printing the spiral
    while(prints<=rows*coloums)
    {
        while(prints<coloums)
        {
          printf("%d ",array[0][prints]);
          prints++;

        }
        if(prints==coloums)
        {
            counter1=1;
            while(counter1<rows)
            {
                printf("%d ",array[counter1][coloums-1]);
                counter1++;
                prints++;
            }
        }

        if(prints<=rows+coloums)
        {
        counter1=coloums-2;
        while(counter1>=0)
        {
            printf("%d ",array[rows-1][counter1]);
            counter1--;
            prints++;
        }
        }
        counter1=0;
        while(counter1<2)
        {
            printf("%d ",array[rows-2][counter1++]);
           prints++;
        }
        prints++;
    }
}