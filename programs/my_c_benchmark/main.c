#include <stdlib.h>

#ifdef _GEM5_
#include <gem5/m5ops.h>
#endif /*_GEM5_*/

#define N 64

const double v1[N] = {7.2410,67.4193,77.9805,9.5343,34.2370,72.5064,6.6118,12.5612,87.2223,97.2739,30.3539,10.6037,43.8294,20.0284,1.1242,68.3565,97.0846,13.0101,6.1851,77.5373,77.5245,26.8014,85.7489,92.4738,70.7735,1.1214,25.2631,78.0454,5.8797,94.0483,13.2974,33.3577,20.9327,-0.4664,25.7926,11.8382,24.4504,36.2891,15.2716,22.0000,11.9162,52.0634,99.7823,43.1000,94.1769,2.7619,72.9703,68.2834,6.8242,78.8745,98.3101,73.0569,88.2144,78.9440,25.6896,94.4541,76.2678,50.4263,36.5759,99.3918,11.3710,48.3084,88.9468,99.6758};
const double v2[N] = {7.2410,67.4193,77.9805,9.5343,34.2370,72.5064,6.6118,12.5612,87.2223,97.2739,30.3539,10.6037,43.8294,20.0284,1.1242,68.3565,97.0846,13.0101,6.1851,77.5373,77.5245,26.8014,85.7489,92.4738,70.7735,1.1214,25.2631,78.0454,5.8797,94.0483,13.2974,33.3577,20.9327,-0.4664,25.7926,11.8382,24.4504,36.2891,15.2716,22.0000,11.9162,52.0634,99.7823,43.1000,94.1769,2.7619,72.9703,68.2834,6.8242,78.8745,98.3101,73.0569,88.2144,78.9440,25.6896,94.4541,76.2678,50.4263,36.5759,99.3918,11.3710,48.3084,88.9468,99.6758};
const double v3[N] = {7.2410,67.4193,77.9805,9.5343,34.2370,72.5064,6.6118,12.5612,87.2223,97.2739,30.3539,10.6037,43.8294,20.0284,1.1242,68.3565,97.0846,13.0101,6.1851,77.5373,77.5245,26.8014,85.7489,92.4738,70.7735,1.1214,25.2631,78.0454,5.8797,94.0483,13.2974,33.3577,20.9327,-0.4664,25.7926,11.8382,24.4504,36.2891,15.2716,22.0000,11.9162,52.0634,99.7823,43.1000,94.1769,2.7619,72.9703,68.2834,6.8242,78.8745,98.3101,73.0569,88.2144,78.9440,25.6896,94.4541,76.2678,50.4263,36.5759,99.3918,11.3710,48.3084,88.9468,99.6758};
const double v4[N] = {7.2410,67.4193,77.9805,9.5343,34.2370,72.5064,6.6118,12.5612,87.2223,97.2739,30.3539,10.6037,43.8294,20.0284,1.1242,68.3565,97.0846,13.0101,6.1851,77.5373,77.5245,26.8014,85.7489,92.4738,70.7735,1.1214,25.2631,78.0454,5.8797,94.0483,13.2974,33.3577,20.9327,-0.4664,25.7926,11.8382,24.4504,36.2891,15.2716,22.0000,11.9162,52.0634,99.7823,43.1000,94.1769,2.7619,72.9703,68.2834,6.8242,78.8745,98.3101,73.0569,88.2144,78.9440,25.6896,94.4541,76.2678,50.4263,36.5759,99.3918,11.3710,48.3084,88.9468,99.6758};

int main() {


/********************************************************
 *****      Starting Region of Interest (ROI)    ********
********************************************************/
#if _GEM5_
 m5_work_begin(1,1);   
#endif /*_GEM5_*/
    
    volatile double v5[N];
    volatile double v6[N];
    volatile double v7[N];
    // my c benchmark core 
    volatile int m=1 ;/* 64  bit */
    volatile int i;
    volatile double k,p;
    for (i = 0; i < N; i++){
    	if (i %2==0) {
    	    p= v1[i] * ((double)( m<< i));
    	    m = (int)p;
    } else {
    
    	p= v1[i] / ((double)m* i);
    	k =  (double)((int)v4[i]/ 2^i);
    }

    	v5[i] = ((p * v2[i]) + v3[i])+v4[i];

    	v6[i] = v5[i]/(k+v1[i]);

        v7[i] = v6[i]*(v2[i]+v3[i]);

    }


/********************************************************
 *****      End Region of Interest (ROI)         ********
********************************************************/
#ifdef _GEM5_
    m5_work_end(1,1);
#endif /*_GEM5_*/
    return 0;
}





























