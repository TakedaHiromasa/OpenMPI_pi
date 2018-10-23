#include <stdio.h>
#include <math.h>
#include <mpi.h>
int main(int argc,char* argv[]){
	double PI25DT = 3.141592653589793238462643;
	double mypi,pi,h,sum,x,f,a;
	int n = 1000000000,myid,numprocs,i,rc;
	int ierr;
	ierr = MPI_Init(&argc,&argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	ierr = MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

	if(myid == 0){
		//printf("Enter the number of intervals \n");
		//scanf("%d",&n);
		n=1000000000;
		printf("n=%d \n",n);
	}
	ierr = MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);

	printf("Hello! I am %d of %d.\n",myid,numprocs);

	h = 1.0 / n;
	sum = 0.0;
	
	for(i = myid+1; i<=n; i += numprocs){
		x = h * (i - 0.5);
		sum = sum + 4.0 / (1.0 + x*x);
	}
	
	mypi = h * sum;
	MPI_Reduce(&mypi,&pi,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
	
	if (myid == 0){
		printf("pi is approximately: %18.70f\n",pi);
		printf("           Error is: %18.70f \n",fabs(pi-PI25DT));
	}
	
	rc = MPI_Finalize();
}

