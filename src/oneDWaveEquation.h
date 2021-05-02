#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#ifndef MAIN_H
#define MAIN_H

/* 
 * Structure for 1D model. Constants and pointers to 
 * the second order time FD arrays
*/
struct modelParam {
	int   nx;
	float dx;
	float lx;
	
	//presure time steps
	float *p0;
	float *p1;
	float *p2;;
	float *vel;
};

/* 
 * Structure for 1D wavelet. Constants and pointers to 
 * the wavelet to be injected
*/
struct inputWavelet {
	int nt;
	float dt;
	float Lt;
	
	//wavelet pointers
	float *wavelet;
};


/*
 * initModel
 * SYNOPSIS: Initialize the values in the modelParam Structure
*/
void initModel(struct modelParam *mod);

/*
 * freeModel
 * SYNOPSIS: Frees the points in the modelParam structure
*/
void freeModel(struct modelParam *mod);

/*
 * initWavelet
 * SYNOPSIS: Initialize the values in the inputWavelet Structure
 * INPUTS: need a modelParam structure and the input wavelet structure
*/
void initWavelet(struct modelParam *mod, struct inputWavelet *inWave);

/*
 * freeWavelet
 * SYNOPSIS: Frees the points in the inputWavelet structure
*/
void freeWavelet(struct inputWavelet *inWave);

/*
 * fdWaveTimeStep
 * SYNOPSIS: Conducts a FD time step using the model parameters, input wavelet and 
 * timestep increment
 *
 * INPUTS: modelParam, inputWavel, 
*/
void fdWaveTimeStep(struct modelParam *mod, struct inputWavelet *inwave);
#endif
