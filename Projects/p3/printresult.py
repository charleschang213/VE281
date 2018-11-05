import numpy as np
import matplotlib.pyplot as plt

a = np.loadtxt('result.txt');
plt.figure(1);
b = np.linspace(50,500,10);
plt.plot(b,a[0,:],label='Unsorted Heap')
plt.plot(b,a[1,:],label='Binary Heap')
plt.plot(b,a[2,:],label='Fibonacci Heap')
plt.xlabel('Size')
plt.ylabel('Total time of runnign 5 times (us)')
plt.legend()
plt.show()