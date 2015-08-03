/*

VC, GCC에서 사용

*/

#if 0
#include <stdio.h>

#define MAX 100
int x[MAX]={0, };
int y[MAX]={0, };

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	
	int n;

	int i,j,k;

	float det=0.0;
	float sum=0.0;


	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		/*

		알고리즘이 들어가는 부분

		*/
		det=(float)0;
		sum=(float)0;

		scanf("%d",&n);

		for(i=0; i<n; i++)
		{
			scanf("%d %d",&x[i],&y[i]);
		}

		//for(i=0; i<n; i++)
		//{
		//	printf("%d %d\n",x[i],y[i]);
		//}

		for(i=0; i<n-2; i++)
		{
			for(j=i+1; j<n-1; j++)
			{
				for(k=j+1; k<n; k++)
				{
					//printf("%d   %d   %d\n",i,j,k);
					det = (float)(x[j]-x[i])*(y[k]-y[i]) - (float)(x[k]-x[i])*(y[j]-y[i]);
					det = det*det/det;
					sum+=det/2;
					printf("%f\n",det/2);
					//sum+=(float)((x[j]-x[i])*(y[k]-y[i]) - (x[k]-x[i])*(y[j]-y[i]))*((x[j]-x[i])*(y[k]-y[i]) - (x[k]-x[i])*(y[j]-y[i]))/((x[j]-x[i])*(y[k]-y[i]) - (x[k]-x[i])*(y[j]-y[i]))/2;
				}
			}
		}

		printf("%f\n",sum);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
#endif