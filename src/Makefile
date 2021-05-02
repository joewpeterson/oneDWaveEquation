CC=gcc
OBJ=oneDWaveEquation.o initFreeModel.o initFreeWavelet.o fdWaveTimeStep.o 

oneDWave: $(OBJ) oneDWaveEquation.h
	$(CC) -o oneDWave $(OBJ) -lm

$(OBJ): oneDWaveEquation.h

.PHONY:clean

clean:
	rm $(OBJ) oneDWave

.PHONY:memcheck

memcheck:
	valgrind --tool=memcheck ./oneDWave
