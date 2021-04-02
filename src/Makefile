CC=gcc
OBJ=main.o initFreeModel.o initFreeWavelet.o fdWaveTimeStep.o 

oneDWave: $(OBJ) main.h
	$(CC) -o oneDwave $(OBJ)

$(OBJ): main.h

.PHONY clean:
	rm $(OBJ) oneDWave
