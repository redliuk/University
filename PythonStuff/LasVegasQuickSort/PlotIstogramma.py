#di seguito il plot dell'istogramma normalizzato
import matplotlib.pyplot as plt
import numpy as np

f = open('conteggioConfronti.txt', 'r')
numBin = [50]

for binCount in numBin:
  val = []
  f.seek(0)
  for line in f.readlines():
    val.append(int(line))

  weights = np.ones_like(val)/float(len(val))
  N, bins, patches = plt.hist(val, weights=weights, bins=binCount, edgecolor='white')
  patches[12].set_facecolor('r')
  plt.gca().set(title='LasVegasQuickSort', xlabel='Confronti', ylabel='Frequenza')
  plt.savefig(f'IstogrammaNormalizzato.png')
  plt.close()