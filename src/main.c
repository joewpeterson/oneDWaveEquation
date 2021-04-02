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

    fdWaveTimeStep(&mod, &inwave);
    
    if (i%N == 0){
      for (int j=0; j < mod.nx; j++){
        fprintf(fptr, "%.12f\n", mod.p2[j]);
      }
    }
  } 

  //free the model
  freeModel(&mod);
  freeWavelet(&inwave);

  //close the file we are writing your data to
  fclose(fptr);

  return 0;
}


