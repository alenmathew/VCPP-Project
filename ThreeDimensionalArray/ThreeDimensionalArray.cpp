// ThreeDimensionalArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    int x=2;
    int y=3;
    int z=2;
    int ***DynamicThreeDimensionalArray= new int**[x];
   
    for(int i=0;i<x;i++)
    {
        DynamicThreeDimensionalArray[i]= new int*[y];
    }
    for(i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			DynamicThreeDimensionalArray[i][j]= new int[z];
		}
	}
    for( i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
			for(int k=0;k<z;k++)
			{
            DynamicThreeDimensionalArray[i][j][k]=i*j*k; 
			}
        }
    }


    printf("DynamicThreeDimensionalArray Results.. ");

    for( i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
			for(int k=0;k<z;k++)
			{
            printf("%d",DynamicThreeDimensionalArray[i][j][k]);
			}
        }
    }

    printf("\n ");	
}

