#include "oneDWaveEquation.h"

void fdWaveTimeStep(struct modelParam *mod, struct inputWavelet *inwave){
  //Derivative in space
  for (int j=1; j < mod->nx - 1; j++){
    mod->p2[j] = (mod->p1[j-1] - 2*mod->p1[j] + mod->p1[j+1])/mod->dx/mod->dx;

    mod->p2[j] = pow(mod->vel[j],2)*pow(inwave->dt,2)*mod->p2[j] + 2* mod->p1[j] - mod->p0[j];
  }
  
  mod->p2[mod->nx - 1] = -(mod->p1[mod->nx - 1] - mod->p1[mod->nx - 2])*mod->vel[mod->nx -1]*inwave->dt/mod->dx + mod->p1[mod->nx - 1]; 
  
  //swap the pressure waves to increment to the next time
  float *swapptr;

  swapptr = mod->p0;
  mod->p0 = mod->p1;
  mod->p1 = mod->p2;
  mod->p2 = swapptr;
 }
