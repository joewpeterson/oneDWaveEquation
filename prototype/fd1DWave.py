import numpy as np 

def main():
  '''
  fd1DWave prototypes a finite difference wave equation simulator

  A ricker wavelet is injected onto a string and the wave equation
  is calculated using 2nd order time and space derivatives 

  A dataset is written with the pressure waves recorded every N frames
  '''

  #physical parameters 
  cHigh = 2000.0   # speed of wave
  n = 1024     # number of points
  L = 600      # string length
  dx = L/n     # increment spacing
  tL = 0.8     # Length of simulation 
  dt = dx/cHigh    # time increment
  tn = tL/dt
  
  #initialize time and space arrays
  t = np.arange(0,tL, dt)
  t = t.reshape(len(t),1)
  x = np.arange(0, L, dx).reshape(n,1)

  c = x
  c[:int(3*n/4)] = 1500
  c[int(3*n/4):] = 2000

  #initialize pressure values
  p0 = p1 = p2 = spaceDerive2 = np.zeros(n).reshape(n,1)
  
  #Ricker wavelet for injection as a function of time 
  fc = 20
  t0 = 1.5/fc
  tau = np.pi*(t-t0)*fc
  inputWave = np.multiply( np.exp(-np.square(tau)), (1 - 2*np.square(tau)) )
  
  # frames inc
  N = 8

  # Write the datafile headers
  with open("data.dat", 'w') as fh:
    fh.write("{}\n".format(n))
    fh.write("{}\n".format(dx))
    fh.write("{}\n".format(L))
  
  with open("data.dat", 'ab') as fh:
    for j in range(len(t)):
      #inject source
      p1[int(n/3)] = p1[int(n/3)] + inputWave[j]*dt*dt/dx*c[int(n/3)]*2
    
      #order 2 FD space derivative 
      spaceDerive2[1:n-1] = (p1[0:n-2] - 2*p1[1:n-1] + p1[2:n])/dx/dx

      #order 2 FD time derivative
      csquared = np.multiply(c,c)
      p2 = dt*dt*np.multiply(csquared,spaceDerive2) + 2*p1 - p0
    
      #Set boundary condition at X=L so that wave does not reflect from there
      p2[-1] = -(p1[-1] - p1[-2])*c[-1]*dt/dx + p1[-1] 
    
      #swap the pressure waves to increment to the next time
      p0 = p1
      p1 = p2
    
      #write ever N frames to dataset
      if(j%N == 0):
        np.savetxt(fh, p2, delimiter=",")
   
main()
