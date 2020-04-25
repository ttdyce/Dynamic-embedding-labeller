import os
from os.path import isfile, join
import numpy as np
import random
import json

# config
debug = True

isContinue = True
preLabelCount = 0
exeNames = []
roleInStates = []
dir = "out-datasetText/"
dirDone = dir + "labeled/"
dirOut = "out-dataset/"
traces = []
labels = []

def init():
    """Initiate folders & config"""
    for path in [dirDone, dirOut]: 
        try:
            os.makedirs(path)
        except FileExistsError:
            # directory already exists
            pass
    
    #config
    global isContinue, preLabelCount
    
    if isfile(join(dirOut, "dataset.npz")): 
        #dataset exist
        with np.load(dirOut + 'dataset.npz', allow_pickle=True) as dataset: 
            preLabelCount = dataset['labels'].__len__()
            
        print("Found previous dataset.npz", "(", preLabelCount, ")", " in", dirOut)
        print("Do you want to continue the last labelling? ('N': No, restart labelling, 'y': Yes)")
        inputText = input()
        if(inputText == ''):
            isContinue = False
        print("Received", inputText, "continue =", isContinue)

def saveToFile():
    """Save traces and labels to a folder (out-dataset/dataset.npz)"""
    global isContinue, preLabelCount, traces, labels, exeNames
    
    lengths = [len(i) for i in traces]
    print("Saving...")
        
    np.savez(dirOut + 'dataset.npz'
            , traces=traces
            , lengths=lengths
            , labels=labels
            , exeNames=exeNames
            , roleInStates=roleInStates
            )
    
    print("File saved to ", dirOut, "dataset.npz", sep='')
    print("Old dataset length:", preLabelCount)
    print("New dataset length:", lengths.__len__())
    

def label(stateTraces, stateLabels, exeName): 
    """Process the text into traces:global and labels:global"""
    #replace '-1' to '0' for input format
    if(stateTraces.__len__() > 0):
        for stateTrace in stateTraces:
            for i in range(stateTrace.__len__()): 
                item = stateTrace[i]
                if (item == '-1'):
                    stateTrace[i] = 0
                    # print(item)
                
                
    # split multiple trace & label to 1 tuple & array item
    if(np.array(stateTraces).shape.__len__() > 1): 
        # x, y = np.transpose(stateTraces), [i for i in stateLabels]
        # traces.extend(x)
        # labels.extend(y)
        x, y = stateTraces, stateLabels
        traces.append(x)
        labels.append(y)
        exeNames.append(exeName)
        roleInStates.append(stateTrace.__len__())
        # print("stateTraces len: ", np.array(stateTraces).shape)
        # print(np.array(stateTraces).shape.__len__())
    
    print("\n")
    
        
def main():
    """Pack the program into main() so that I can use 'return' to quit"""
    traceTextFileNames = [f for f in os.listdir(dir) if isfile(join(dir, f))]
    
    for traceTextFileName in traceTextFileNames: 
        textFilePath = join(dir, traceTextFileName)
        baseName = traceTextFileName.replace('.json', '').replace('logState-', '')
        traceText = baseName.split('-')
        # [0]: program name (*.exe), [1]: state address
        if(len(traceText) != 2): 
            continue
        
        exeName = traceText[0]
        stateId = traceText[1]
        print(exeName, stateId)
    
        with open(textFilePath, "r") as txtFile: 
            jsonText = txtFile.read()
            stateJson = json.loads(jsonText)
            # print(stateJson['labels'])
            # print(stateJson['stateTraces'])
            label(stateJson['stateTraces'], stateJson['labels'], exeName)
        
    saveToFile()
    

if __name__ == '__main__':
    init()
    main()
    
    if(debug == True): 
        print("traces 0:", traces[0])
        print("traces 1:", traces[1])
        print("labels:", labels)
        print("")
        print("Old labels length:", preLabelCount)
        print("---")
        print("New labels length:", labels.__len__())
        print("New traces length:", traces.__len__())
        print("Traces length max:", np.array([len(i) for i in traces]).max())
        print("exeNames: ", exeNames.__len__())
    