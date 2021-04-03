CC=gcc
OBJ=oneDWaveEquation.o initFreeModel.o initFreeWavelet.o fdWaveTimeStep.o 

oneDWave: $(OBJ) oneDWaveEquation.h
	$(CC) -o oneDwave $(OBJ)

$(OBJ): oneDWaveEquation.h

.PHONY clean:
	rm $(OBJ) oneDWave
