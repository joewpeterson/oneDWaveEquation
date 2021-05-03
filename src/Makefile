CC=gcc
OBJ=oneDWaveEquation.o initFreeModel.o initFreeWavelet.o fdWaveTimeStep.o 

oneDWave: $(OBJ) oneDWaveEquation.h
	$(CC) -o oneDWave $(OBJ) -fopenmp -lm

oneDWaveEquation.o: fdWaveTimeStep.o oneDWaveEquation.h
	$(CC) -c  -o oneDWaveEquation.o oneDWaveEquation.c -fopenmp -lm

fdWaveTimeStep.o: initFreeWavelet.o oneDWaveEquation.h
	$(CC) -c  -o fdWaveTimeStep.o fdWaveTimeStep.c -fopenmp -lm

initFreeWavelet.o: initFreeModel.o oneDWaveEquation.h
	$(CC) -c  -o initFreeWavelet.o initFreeWavelet.c -fopenmp -lm

initFreeModel.o: oneDWaveEquation.h
	$(CC) -c -o initFreeModel.o initFreeModel.c -fopenmp -lm

.PHONY:clean

clean:
	rm $(OBJ) oneDWave

.PHONY:memcheck

memcheck:
	valgrind --tool=memcheck ./oneDWave
