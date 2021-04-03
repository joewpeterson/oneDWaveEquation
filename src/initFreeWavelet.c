#include "oneDWaveEquation.h"

void initWavelet(struct modelParam *mod, struct inputWavelet *inWave){
  //Find max velocity
  float maxVel = 0;
  for (int i = 0; i< mod->nx; i++){
    if (mod->vel[i] > maxVel)
      maxVel = mod->vel[i];
  }
     
  maxVel *= 1.1;

  inWave->dt = mod->dx / maxVel;
  inWave->Lt = 0.5;
  inWave->nt = inWave->Lt/inWave->dt;

  //initialize the waveler
  inWave->wavelet = malloc(inWave->nt*sizeof(float));

  //populate the input wavelet
  //Ricker wavelet for injection as a function of time 
  double tau;
  float fc, t0;
  fc = 20;
  t0 = 1.5/fc;
  for (int i=0; i<inWave->nt; i++){
    tau = fc* M_PI * (i*inWave->dt - t0); 
    inWave->wavelet[i] = (1 - 2*(pow(tau, 2))) *exp(-pow(tau,2));
  }
 
}

void freeWavelet(struct inputWavelet *inWave){
  free(inWave->wavelet);
}
