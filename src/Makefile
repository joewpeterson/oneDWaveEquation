oneDWave: main.o initFreeModel.o initFreeWavelet.o
	gcc -o oneDwave main.o initFreeModel.o initFreeWavelet.o

main.o: main.c main.h 
	gcc -c  main.c

initFreeModel.o: initFreeModel.c main.h
	gcc -c initFreeModel.c

initFreeWavelet.o: initFreeWavelet.c main.h
	gcc -c initFreeWavelet.c

.PHONY clean:
	rm main.o initFreeModel.o oneDWave initFreeWavelet.o
