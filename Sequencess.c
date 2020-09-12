//
//
//   Sequences.c
//
//   Created by Sergio Medina Galàn and Gustavo Luna Maya on 12/09/2020
//
//


/*Inlcude standard headers*/
#include <stdio.h>

/*Inlude modules header we directly invoke here: */
#include "Sequences.h"


/**
 * Returns the value of the fibonacci sequence at index n calculated recursively
 * @param
 *      n (long long int):
 *          Index of the fibonacci sequence
 * @return long long int value
*/
extern long long int Sequences_rfibo(long long int n)
{
  if (n==0 || n ==1)
    return n;
  else
    return Sequences_rfibo(n-2) + Sequences_rfibo(n-1);
      }

/**
 * Returns the value of the fibonacci sequence at index n calculated sequentially
 * @param
 *      n (long long int):
 *          Index of the fibonacci sequence
 * @return long long int value
*/
extern long long int Sequences_sfibo(long long int n)
{
  long long int p=0,s=1,u;
  int i;
  for(i=0; i<=n;i++){
    u=p+s;
    p=s;
    s=u;
   
      }
  return u;
}
