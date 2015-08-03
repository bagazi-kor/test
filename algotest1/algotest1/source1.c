/*

VC, GCC���� ���

*/
#if 1
#include <stdio.h>

#define MAX 60

#define ROAD '.'
#define FIRE '*'
#define FIRE_SEED '+'
#define PIPE 'X'
#define FINISH 'D'	//SAFE
#define START 'S'
#define START_SEED 's'

char arr[MAX][MAX] = {0, };
char fire[MAX][MAX] = {0, };
int success = 0;

void memset(int Row, int Col)
{
	int i,j;
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Col; j++)
		{
			arr[i][j]=0;
			fire[i][j]=0;
		}
	}
}

void copy_arr(char a[][MAX] ,char b[][MAX])
{
	int i,j;
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void foo_onetick(int Row, int Col)
{
	int i,j;

	
	printf("--------------------\n");
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Col; j++)
		{
			if(arr[i][j] == START)
				printf("%2c ",'S');
			else
				printf("%2c ",fire[i][j]);
		}printf("\n");
	}

	/*
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Col; j++)
		{
			printf("%c ",new_arr[i][j]);
		}printf("\n");
	}*/

	/*��*/
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Col; j++)
		{		
			if(fire[i][j] == START)
					fire[i][j] = ROAD;
			if(fire[i][j] == FIRE)
			{
				if(arr[i][j] == START)
					arr[i][j] = ROAD;
				//��
				if(i-1>=0)
				{
					if(fire[i-1][j] == ROAD || fire[i-1][j] == START)
					{
						fire[i-1][j] = FIRE_SEED;
					}			
				}
				//��
				if(i+1<Row)
				{
					if(fire[i+1][j] == ROAD || fire[i-1][j] == START)
					{
						fire[i+1][j] = FIRE_SEED;
					}			
				}
				//��
				if(j-1>=0)
				{
					if(fire[i][j-1] == ROAD || fire[i-1][j] == START)
					{
						fire[i][j-1] = FIRE_SEED;
					}			
				}
				//��
				if(j+1<Col)
				{
					if(fire[i][j+1] == ROAD || fire[i-1][j] == START)
					{
						fire[i][j+1] = FIRE_SEED;
					}			
				}
			}
		}
	}

	
	/*
	//FIRE_SEED to FIRE
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Col; j++)
		{
			if(fire[i][j] == FIRE_SEED)
			{
					fire[i][j] = FIRE;
			}
		}
	}*/

	/*���*/
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Col; j++)
		{
			//FIRE_SEED to FIRE
			if(fire[i][j] == FIRE_SEED)
			{
					fire[i][j] = FIRE;
			}
			if(arr[i][j] == START)
			{
				//FIRE_SEED to FIRE
				//if(fire[i][j] == FIRE_SEED)
				//{
				//	fire[i][j] = FIRE;
				//}
				//��
				if(i-1>=0)
				{
					if(arr[i-1][j] == FINISH)
					{
						success=1; return;
					}
					if(fire[i-1][j] == ROAD)
					{
						arr[i-1][j] = START_SEED;
					}
				}
				//��
				if(i+1<Row)
				{
					if(arr[i+1][j] == FINISH)
					{
						success=1; return;
					}
					if(fire[i+1][j] == ROAD)
					{
						arr[i+1][j] = START_SEED;
					}
				}
				//��
				if(j-1>=0)
				{
					if(arr[i][j-1] == FINISH)
					{
						success=1; return;
					}
					if(fire[i][j-1] == ROAD)
					{
						arr[i][j-1] = START_SEED;
					}
				}
				//��
				if(j+1<Col)
				{
					if(arr[i][j+1] == FINISH)
					{
						success=1; return;
					}
					if(fire[i][j+1] == ROAD)
					{
						arr[i][j+1] = START_SEED;
					}
				}
			}
		}
	}

	//START_SEED to START
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Col; j++)
		{
			if(arr[i][j] == START_SEED)
			{
				arr[i][j] = START;
			}
		}
	}
}

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */
	int i,j;
	int Row,Col;	//R�� C��
	int tick;

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		/*

		�˰����� ���� �κ�

		*/
		scanf("%d %d",&Row,&Col);
		for(i=0; i<Row; i++)
		{
			for(j=0; j<Col; j++)
			{
				scanf("\n%c",&arr[i][j]);
			}
		}

		/*
		printf("\n -- input end --\n");
		for(i=0; i<Row; i++)
		{
			for(j=0; j<Col; j++)
			{
				printf("%c  ",arr[i][j]);
			}printf("\n");
		}*/

		tick=1;
		success=0;

		copy_arr(arr,fire);

		for(i=0; i<Row+Col; i++)
		{
			foo_onetick(Row,Col);
			if(success==1)
			{
				printf("%d\n",tick);
				break;
			}tick++;
		}
		if(success==0)
		{
			printf("impossible");
		}

		memset(Row,Col);
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}
#endif