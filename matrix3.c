/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}

int min(int a, int b){
  return a<b?a:b;
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 1 */
  unsigned int size = 1000;
  unsigned int i;
  unsigned int j;
  unsigned int k;
  unsigned int l;
  unsigned int m;
  unsigned int n;
  unsigned int z=25;

  /* declare variables;*/
  double **A;
  double **B;
  double **C;
  
  /* allocate memory for arrays;*/
   A = (double**)malloc (size*sizeof (double));
   for ( i = 0; i < size; ++i)
   {
    A[i]=(double*)malloc(size*sizeof(double));
   }

   B = (double**)malloc (size*sizeof (double));
   for ( i = 0; i < size; ++i)
   {
    B[i]=(double*)malloc(size*sizeof(double));
   }

   C = (double**)malloc (size*sizeof (double));
   for ( i = 0; i < size; ++i)
   {
    C[i]=(double*)malloc(size*sizeof(double));
   }
   
  for (i = 0; i < size; ++i)
  {
    for (j = 1; j < size; ++j)
    {
      A[i][j]=rand()%size;
      B[i][j]=rand()%size;
      C[i][j]=0.0;
    }
  }
  
  t1 = getTime();
  for (l = 0; l < size; l+=z)
  {
    for (m = 0; m < size; m+=z)
    {
      for (n = 0; n < size; n+=z)
      {
        for (i = l; i<min(size,z+l)/*i<size && i<z+l-1*/; ++i)
          {
            for (j = m; j<min(size,z+m)/*j < z+m-1 && j<size*/; ++j)
            {
              for (k = n; k<min(size,z+n)/*k < z+n-1 && k<size*/; ++k)
              {
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
              }
            }
          }
        }
      }
    }
  
  t2 = getTime();

  /* output;*/
  printf("time: %6.2f secs\n",t2 - t1);

  /* free memory;*/
  free(B);
  free(A);
  free(C);

  return 0;  
}

