#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct p
{
	int nums[9][9];
} puzzle;

//check if there are no -1s
//check rows for numbers
//check columns for numbers
//check squares for numbers
//if everything checks out, we win!
//check -1s
int issolved(puzzle p1)
{
	int i,j,k,l,m,n;
	int num = 0;
	int arr[9];

	for(i = 0;i<9;i++)
		for(j=0;j<9;k++)
			if(p1.nums[i][j] < 0)
				return 0;

	//check rows
	//1+2..+9 = 45
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)	//check both rows and cols 
		{
			num+=p1.nums[i][j];
			arr[j]+=p1.nums[i][j];
		}
		if(num != 45)
			return 0;
		j = 0; num = 0;
	}

	for(i=0;i<9;i++)
			if(arr[i] != 45)
				return 0;

	//check the squares somehow
	/*
	l = 0;m = 0;
	for(i=0;i<9;i++)
	{
		while(j != 3)
		{
			while(k != 3)
			{
				num+=p1.nums[l][m];
				++k;
			}
			++j;
		}
		if(num != 45)
		return 0;
		num = 0;
	}
		*/
		//push from left to right, just add stuff to arr somehow I guess idk
	printf("fart in my mouth!!!");
	num = 0;
	for(i=0;i<9;i++)
	{
		
		for(j=0;j<9;j++)
		{
			arr[num]+=p1.nums[i][j];
			if(!j%3)
				num++;
		}
		if(!i%3)	//if i mod 3 is 0, check if they're 45
		{
			for(j=0;j<3;j++)
				if(arr[j] != 45)
					return 0;
			num = 0;
		}
	}
	
}


int makepuz(puzzle *p1)
{
	//make a random generated completed puzzle
	//take random shit out of it
	//make sure it's solvable for a human??(impossible??)
}

void getpuz(puzzle *p1)
{
	//read puzzle in
	//use escape codes to make this look nice

}

void printpuzzle(puzzle in)
{
	int i, k;
	for(i = 0;i < 9;i++)
	{
		for(k=0;k<9;k++)
			printf("%d ",in.nums[i][j]);
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	puzzle p1;
	printf("welcome to sudoku solver\n");
	if(argc == 2)
	{
		if(strcmp(argv[2],"-input"))
			getpuz(p1);
		else
		{
			printf("enter better arg\n");
			exit(2);
		}
	}
	else
		makepuz(p1);

	while(!issolved(p1))
	{
		//solve the puzzle!
	}

	return 0;
}