#include "oneDWaveEquation.h"

void initModel(struct modelParam *mod)
{
	mod->nx = 1024;
	mod->lx = 600;
	mod->dx = mod->lx/mod->nx;
	
	mod->p0 = malloc(mod->nx*sizeof(float));
	mod->p1 = malloc(mod->nx*sizeof(float));
	mod->p2 = malloc(mod->nx*sizeof(float));
	
	memset(mod->p0, 0, mod->nx*sizeof(float));
	memset(mod->p1, 0, mod->nx*sizeof(float));
	memset(mod->p2, 0, mod->nx*sizeof(float));
	
	//In principle we read the velocity model from a file stored elsewhere
	mod->vel = malloc(mod->nx*sizeof(float));
	
	for (int i=0; i < 3*mod->nx/4; i++)
		mod->vel[i] = 1500;
	
	for (int i = 3*mod->nx/4; i<mod->nx; i++)
		mod->vel[i] = 2000;
}

void freeModel(struct modelParam *mod)
{
	free(mod->p0);
	free(mod->p1);
	free(mod->p2);
	free(mod->vel);
}
