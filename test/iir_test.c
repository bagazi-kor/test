#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define __IIR_DIRECT_FORM_2__

#ifdef __IIR_DIRECT_FORM_2__

#define N_th_order 6
#define NUMERATOR 3
#define DENOMINATOR 3
#define Section 3


typedef float float_j_t;


int IIR_filter( float_j_t *output,float_j_t input,int sec,float_j_t Coefficient[][N_th_order],float_j_t Gain[],float_j_t state[][N_th_order/2] ){
/*
	float_j_t temp=0;
	for(i=0;i<NUMERATOR;i++){
		temp += state[sec][i]*Coefficient[sec][i];
	}
	float_j_t y = Gain[sec]*temp;
*/	

	memmove( &state[sec][1], &state[sec][0] ,2*sizeof(float_j_t)  );

	state[sec][0] = input*Coefficient[sec][3]-Coefficient[sec][4]*state[sec][1]-Coefficient[sec][5]*state[sec][2];

	*output = Gain[sec]*(state[sec][0]*Coefficient[sec][0]+state[sec][1]*Coefficient[sec][1]+state[sec][2]*Coefficient[sec][2]);


	return 0;
}



void main(){


//b0 b1 b2 a0 a1 a2
float_j_t Coefficient[Section][N_th_order]={
1,	-1.29632172693744,	1,	1,	-1.80515310279348,	0.88702449464002,
1,	0.38051527431782,	1,	1,	-1.80676488212313,	0.82648708617365,
1,	-1.55996982970591,	1,	1,	-1.82577026864564,	0.96274299269518
};
float_j_t Gain[Section+1]={  
0.29199951748161,
0.23303636811273,
0.00392996161525,
1
};

float_j_t state[Section][N_th_order/2]={0,}; //0 state is lastest



	int testcase ;
	scanf("%d",&testcase);
	int i;
	for(i=0;i<testcase;i++){
	float_j_t in;
	scanf("%f",&in);
	float_j_t st;
	IIR_filter(&st,in,0,Coefficient,Gain,state);
	IIR_filter(&st,st,1,Coefficient,Gain,state);
	IIR_filter(&st,st,2,Coefficient,Gain,state);
	printf("c %f\n",Gain[3]*st);
	}



}

#endif

