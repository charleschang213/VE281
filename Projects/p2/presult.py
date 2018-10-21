import numpy as np
import matplotlib.pyplot as plt

a = np.loadtxt('result.txt')
b = np.linspace(100,10000,100)

plt.figure(1)
plt.plot(b,a[0,:],label = 'random')
plt.plot(b,a[1,:],label = 'deterministic')
plt.plot(b,a[2,:],label = 'qsort')

plt.xlabel('size')
plt.ylabel('time(ms)')

plt.legend()
plt.show()
