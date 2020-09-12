//
//  time_test_fibo.c
//  
//
//  Created by Cesar Angeles on 07/09/2020.
//

/*Include standard headers*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Include modules header we directly invoke here: */
#include "Sequences.h"
#include "files.h"
#include "time_test_fibo.h"

/*The function main */
int main(void){

  long long int value =0;
  int index =0;
  clock_t start, stop;
  double cput =0;
  double mean =0;  
  FILE * record = NULL;
  long double buffer [OBSERVATIONS][VALUES] ={0};
  size_t obs =0;

  record = file_new("FIBO_TIME.dat","w");

  for(obs=0; obs < OBSERVATIONS; obs++){
    printf(" %zu\n",obs);
    start = clock();
    for( index=0; index <= 100; index++){
      Sequences_rfibo(obs);
    }
    stop = clock();

    cput= ((double)(stop-start)) /CLOCKS_PER_SEC /100;
     buffer[obs][0] = obs;
     buffer[obs][1] = cput;
    printf("Recursiva %f  s \t", cput);

    
        start = clock();
    for( index=0; index <= 100; index++){
      Sequences_sfibo(obs);
    }
    stop = clock();

    cput= ((double)(stop-start)) /CLOCKS_PER_SEC /100;
   
     buffer[obs][2] = cput*1e3;
     printf("Secuencial %f  ms \t", cput*1e3);
    }
  file_num_write(record, VALUES, buffer, OBSERVATIONS);
  fclose(record);
}

