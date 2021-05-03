#include "oneDWaveEquation.h"

/*
 * Runs a wave equation simulation. Injects a wavelet on a string
 * with a wave velocity defined at each point of a regularly spaced grid.
 *
 * The result is a file with header information followed by the displacement
 * on the string at each of the the chosen output time intervals.
 *
 */

void p_to_file (FILE *fptr, float *p_array, int len);

int main()
{
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
	
	struct timeval start, end;
	gettimeofday(&start, NULL);

	int N = 8;
	//Do the wave propagation sequentially.
	for (int i=0; i<inwave.nt; i++){
		//Inject the source
		mod.p1[mod.nx/4] += inwave.dt * inwave.dt * mod.vel[mod.nx/4]*2/mod.dx  
		      	      * inwave.wavelet[i];
		
		fdWaveTimeStep(&mod, &inwave);
		
		//every N, print the displacements
		if (i%N == 0){
			p_to_file(fptr, mod.p2, mod.nx);
		}
	} 
	gettimeofday(&end, NULL);
	
	int elapse;
        elapse = (end.tv_sec - start.tv_sec)*1e6 + end.tv_usec - start.tv_usec;
        printf("run time: %d\n", elapse);

	//close the file we are writing your data to
	fclose(fptr);
	
	//free the model
	freeModel(&mod);
	freeWavelet(&inwave);
	
	return 0;
}

void p_to_file (FILE *fptr, float *p_array,int len)
{
	for (int j=0; j < len; j++){
		fprintf(fptr, "%.12f\n", p_array[j]);
	}
}
