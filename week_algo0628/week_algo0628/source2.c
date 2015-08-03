#if 0
#include <stdio.h>
#include <stdlib.h>

#define SHIELD 2
#define MAX 300

int Clustering(int arr[][MAX],int r,int c);
void _Clustering_scan(int arr[][MAX],int r,int c,int i,int j,int cluster_cnt);
int Cluster[MAX][MAX];

void Melting(int arr[][MAX],int r,int c);
int Melt[MAX][MAX];

int is_all_melt(int arr[][MAX],int r,int c);

int main(int argc, char *argv[])
{
	int glacier[MAX][MAX];
	int row,column;
	int i,j;
	int exit,year;
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		/*

		알고리즘이 들어가는 부분

		*/
		scanf("%d %d",&row,&column);

		for(i=0; i<row; i++){
			for(j=0; j<column; j++){
				scanf("%d",&glacier[i][j]);
			}
		}


		year=0; exit=1;

		while(exit)
		{
			if(is_all_melt(glacier,row,column)){
				exit=0;
				year=0;
				break;
			}
			if(Clustering(glacier,row,column)>=2)
				break;
			Melting(glacier,row,column); year++;
		}


		//if(row==30 &&column==30)printf("%d\n",year);
		//else
		//   printf("1\n");

		printf("%d\n",year);

	}
	return 0;
}

int Clustering(int arr[][MAX],int r,int c)
{
	int i,j,cluster_cnt;

	for(i=0; i<r; i++){
		for(j=0 ; j<c; j++){
			Cluster[i][j]=0;
		}
	}

	cluster_cnt=1;
	for(i=0; i<r; i++){
		for(j=0 ; j<c; j++){
			if(Cluster[i][j]==0)
			{
				if(arr[i][j] == 0){
					continue;
				}
				else{
					_Clustering_scan(arr,r,c,i,j,cluster_cnt);
					cluster_cnt++;
				}
			}
		}
	}

	return cluster_cnt-1;
}

void _Clustering_scan(int arr[][MAX],int r,int c,int i,int j,int cluster_cnt)
{
	Cluster[i][j]=cluster_cnt;

	if(i-1>=0){
		if(Cluster[i-1][j]==0){
			if(arr[i-1][j]!=0){
				_Clustering_scan(arr,r,c,i-1,j,cluster_cnt);
			}
		}
	}
	if(i+1<r){
		if(Cluster[i+1][j]==0){
			if(arr[i+1][j]!=0){
				_Clustering_scan(arr,r,c,i+1,j,cluster_cnt);
			}
		}
	}
	if(j-1>=0){
		if(Cluster[i][j-1]==0){
			if(arr[i][j-1]!=0){
				_Clustering_scan(arr,r,c,i,j-1,cluster_cnt);
			}
		}
	}
	if(j+1<c){
		if(Cluster[i][j+1]==0){
			if(arr[i][j+1]!=0){
				_Clustering_scan(arr,r,c,i,j+1,cluster_cnt);
			}
		}
	}
}

void Melting(int arr[][MAX],int r,int c)
{
	int i,j,melting_cnt;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if(arr[i][j]!=0)
			{
				melting_cnt=0;
				if(i-1>=0){
					if(arr[i-1][j]==0){
						melting_cnt++;
					}
				}
				if(i+1<r){
					if(arr[i+1][j]==0){
						melting_cnt++;
					}
				}
				if(j-1>=0){
					if(arr[i][j-1]==0){
						melting_cnt++;
					}
				}
				if(j+1<c){
					if(arr[i][j+1]==0){
						melting_cnt++;
					}
				}
				Melt[i][j]=arr[i][j]-melting_cnt;
				if(Melt[i][j]<0)Melt[i][j]=0;
			}
			else
			{
				Melt[i][j]=0;
			}
		}
	}

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			arr[i][j]=Melt[i][j];
		}
	}
}

int is_all_melt(int arr[][MAX],int r,int c)
{
	int i,j;

	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(arr[i][j]!=0){
				return 0;
			}
		}
	}return 1;
}
#endif