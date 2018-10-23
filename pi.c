#include<stdio.h>
#include<time.h>
#include <math.h>

#define num_steps 1000000000

int main(void){
	double PI25DT = 3.141592653589793238462643;

	clock_t t1, t2;
	t1 = clock();
	int i;
	double x,pi,sum=0.0,step;

	printf("n=%d\n",num_steps);

	step = 1.0 / (double) num_steps;

	for(i = 1;i <= num_steps; i++){
		x = (i - 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}
	
	pi = step * sum;
	printf("pi is approximately: %5.70f\n",pi);
	printf("           Error is: %5.70f \n",fabs(pi-PI25DT));

	t2 = clock();
	printf("%f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
	
	return(0);
}
