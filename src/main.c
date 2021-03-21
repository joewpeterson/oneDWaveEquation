#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "main.h"

int main(){
  
  //Define the structure
  struct modelParam mod;
  struct inputWavelet inwave;

  //Initialize the model
  initModel(&mod);
  initWavelet(&mod, &inwave);

  //open the datafile
  FILE *fptr;
  fptr = fopen("data.dat", "w");
  fprintf(fptr, "%d\n", mod.nx);
  fprintf(fptr, "%f\n", mod.dx);
  fprintf(fptr, "%f\n", mod.lx);

  int N = 8;
  //Do the wave propagation
  for (int i=0; i<inwave.nt; i++){
    //Inject the source
    mod.p1[mod.nx/4] += inwave.dt * inwave.dt * mod.vel * 2 / mod.dx  * inwave.wavelet[i];

    //Derivative in space
    for (int j=1; j < mod.nx - 1; j++){
      mod.p2[j] = (mod.p1[j-1] - 2*mod.p1[j] + mod.p1[j+1])/mod.dx/mod.dx;

      mod.p2[j] = pow(mod.vel,2)*pow(inwave.dt,2)*mod.p2[j] + 2* mod.p1[j] - mod.p0[j];
    }
   
    mod.p2[mod.nx - 1] = -(mod.p1[mod.nx - 1] - mod.p1[mod.nx - 2])*mod.vel*inwave.dt/mod.dx + mod.p1[mod.nx - 1]; 
    
    //swap the pressure waves to increment to the next time
    float *swapptr;

    swapptr = mod.p0;
    mod.p0 = mod.p1;
    mod.p1 = mod.p2;
    mod.p2 = swapptr;
    
    if (i%N == 0){
      for (int j=0; j < mod.nx; j++){
        fprintf(fptr, "%.12f\n", mod.p2[j]);
      }
    }
  } 

  //free the model
  freeModel(&mod);
  freeWavelet(&inwave);

  fclose(fptr);

  return 0;
}
