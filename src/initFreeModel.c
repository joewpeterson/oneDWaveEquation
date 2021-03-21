#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "main.h"

void initModel(struct modelParam *mod){
  mod->nx = 1024;
  mod->lx = 600;
  mod->dx = mod->lx/mod->nx;
  mod->vel = 2000;

  mod->p0 = malloc(mod->nx*sizeof(float));
  mod->p1 = malloc(mod->nx*sizeof(float));
  mod->p2 = malloc(mod->nx*sizeof(float));

  memset(mod->p0, 0, mod->nx*sizeof(float));
  memset(mod->p1, 0, mod->nx*sizeof(float));
  memset(mod->p2, 0, mod->nx*sizeof(float));
}

void freeModel(struct modelParam *mod){
  free(mod->p0);
  free(mod->p1);
  free(mod->p2);
}
