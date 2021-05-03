This is meant as a demonstration of python and C coding with openMP 
parallelization. 

The code simulates wavefield propagation of pressure on a string with a varying 
velocity along its length. In this first iteration, there is only one velocity
contrast in the model. One end of the wave is meant to reflect (as it is tide 
down) and the other end absorbs whatever input hits it. A Ricker wavelet is 
injected over time and is the initial source of input amplitude.

As this is a coding demonstration first, the modeling is not very sophisticated.
I use finite difference in both time and space. I also only use second order.

How to run / what to expect:
Both the python and C codes generate a data file. This data file has a few header
lines followed by the output of the whole pressure field along the string at 
several time slices. The python file moiveMaker1D.py reads this file and 
make a short mp4 of the wavefield as a function of time.

For C code, simply running 'make' should create the executable for you - 
assuming you have a similar set-up to my raspberry pi with all of the needed
libs. Once the executable is ready, run it and the data file should be 
created.

To run both the python scripts, type python3 <script_name>
