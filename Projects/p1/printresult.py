import numpy as np
import matplotlib.pyplot as plt

a = np.loadtxt('result.out')
namelist = ['Bubble Sort','Insertion Sort','Selection Sort','Merge Sort','Quick Sort with Extra Space','In Place Quick Sort']

plt.figure(1)
for i in range(6):
    plt.plot(np.linspace(1,100,100),a[i]*1000,label=namelist[i])
plt.xlabel('n')
plt.ylabel('Average Time(us)')
plt.legend()
plt.show()
