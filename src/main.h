#ifndef MAIN_H
#define MAIN_H

struct modelParam {
  int   nx;
  float dx;
  float lx;
  float vel;

  //presure time steps
  float *p0;
  float *p1;
  float *p2;;
};

struct inputWavelet {
  int nt;
  float dt;
  float Lt;

  //wavelet
  float *wavelet;
};


void initModel(struct modelParam *mod);
void freeModel(struct modelParam *mod);

void initWavelet(struct modelParam *mod, struct inputWavelet *inWave);
void freeWavelet(struct inputWavelet *inWave);
#endif
