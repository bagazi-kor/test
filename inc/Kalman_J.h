

#ifndef _KALMAN_H
#define _KALMAN_H

//#define DT 0.002f // 100Hz

// Q diagonal 3x3 with these elements on diagonal
#define Q1 5.0f
#define Q2 100.0f
#define Q3 0.01f

// R diagonal 2x2 with these elements on diagonal
#define R1 1000.0f
#define R2 1000.0f

struct _kalman_data
{
    float x1, x2, x3;
    float p11, p12, p13, p21, p22, p23, p31, p32, p33;
};

typedef struct _kalman_data kalman_data;

void kalman_innovate(kalman_data *data, float z1, float z2);
void kalman_init(kalman_data *data);
#endif
