import os
from os import listdir
from os.path import isfile, join
import numpy as np

def init():
    for path in [dirDone, dirOut]: 
        try:
            os.makedirs(path)
        except FileExistsError:
            # directory already exists
            pass

def printHints(f, content):
    print('')
    print("File name--- ", f, sep="\n")
    print("------")
    print(content)
    print("------")
    print("('1': Fixed value, '2': Stepper, '3': Gatherer, '': noise, 'q': save & quit)")

def traceToDataset(trace):
    arr = []
    if(int(trace[0][0]) == -1): 
        arr.append(999)
    else: 
        arr.append(int(trace[0][0]))
        
    
    for t in trace: 
        arr.append(int(t[1]))
    
    return arr

datasets = []
labels = []
dir = "out-datasetText/"
dirDone = dir + "labeled/"
dirOut = "out-dataset/"
files = [f for f in listdir(dir) if isfile(join(dir, f))]

init()

for f in files: 
    path = join(dir, f)
    with open(path, "r") as txtFile: 
        content = txtFile.read()
    
    printHints(f, content)
    print("label: ", end='')
    y = input()
    if(y=='q'):
        # dicide save & exit
        break
    
    _ = os.system('cls')
    
    # printDataset
    trace = [i.split(" -> ") for i in content.splitlines()]
    dataset = traceToDataset(trace)
    datasets.append(dataset)
    if(y != ''):
        labels.append(int(y))
    else: 
        labels.append(0)
    print(datasets, labels, sep='\n')
    # move what is done labelling
    os.rename(path, join(dirDone, f))
    
# do save & exits
np.savez(dirOut + 'dataset.npz'
        , traces=datasets
        , lengths=[len(i) for i in datasets]
        , labels=labels)

# np.save(dirOut + 'datasets.npy',np.array(datasets))
# np.save(dirOut + 'lengths.npy', np.array([len(i) for i in datasets]))
# np.save(dirOut + 'labels.npy',np.array(labels))

# print(np.load(dirOut + 'datasets.npy', allow_pickle=True))
# print(np.load(dirOut + 'lengths.npy', allow_pickle=True))
# print(np.load(dirOut + 'labels.npy', allow_pickle=True))

with np.load(dirOut + 'dataset.npz', allow_pickle=True) as dataset: 
    print(dataset['traces']);
    print(dataset['lengths']);
    print(dataset['labels']);
    