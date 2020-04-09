import os
from os.path import isfile, join
import numpy as np
import random
import json

# config
debug = True
isContinue = False
preLabelCount = 0
exeNames = []
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
        print("Do you want to continue the last labelling? ('': Yes; 'n': No, restart labelling)")
        inputText = input()
        if(inputText == ''):
            isContinue = True
        print("Received", inputText, "continue =", isContinue)

# def autoLabel(traceArr):
#     """Label traces with no value changes (Fix-value)"""
#     label(traceArr, 1)

def saveToFile():
    """Save traces and labels to a folder (out-dataset/dataset.npz)"""
    global isContinue, preLabelCount, traces, labels, exeNames
    
    lengths = [len(i) for i in traces]
    print("Saving...")
    # if(isContinue):
    #     with np.load(dirOut + 'dataset.npz', allow_pickle=True) as dataset: 
    #         tracesOld = dataset['traces'].tolist()
    #         lengthsOld = dataset['lengths'].tolist()
    #         labelsOld = dataset['labels'].tolist()
        
        # tracesOld.extend(traces)
        # lengthsOld.extend(lengths)
        # labelsOld.extend(labels)
        # traces = tracesOld
        # lengths = lengthsOld
        # labels = labelsOld
        
    np.savez(dirOut + 'dataset.npz'
            , traces=traces
            , lengths=lengths
            , labels=labels
            , exeNames=exeNames)
    
    print("File saved to ", dirOut, "dataset.npz", sep='')
    print("Old dataset length:", preLabelCount)
    print("New dataset length:", lengths.__len__())
    
    pass
    

def printTraceText(fileName, traceArr, labelCount):
    """Clean the screen, and print the trace text"""
    _ = os.system('cls')
    print("---", "label count: ", labelCount, "---")
    print('')
    print("File name--- ", fileName, "------", sep="\n")
    print("(value -1: unassigned)")
    print(' -> '.join(traceArr), "------", sep="\n")
    print("('1': Fixed value, '2': Stepper, '3': Gatherer, '': noise, 'q': save & quit)")

def label(stateTraces, stateLabels, exeName): 
    """Process the text into traces:global and labels:global"""
    global exeNames
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
        # x, y = stateTraces, [i for i in stateLabels]
        x, y = np.transpose(stateTraces), [i for i in stateLabels]
        traces.extend(x)
        labels.extend(y)
        exeNames.append(exeName)
        # print("stateTraces len: ", np.array(stateTraces).shape)
        # print(np.array(stateTraces).shape.__len__())
    
    print("\n")
    
        
def toStateTrace():
    """Pack the program into main() so that I can use 'return' to quit"""
    global preLabelCount
    
    validLabels = ['0', '1', '2', '3']
    traceTextFileNames = [f for f in os.listdir(dir) if isfile(join(dir, f))]
    labelCount = preLabelCount
    
    for traceTextFileName in traceTextFileNames: 
        textFilePath = join(dir, traceTextFileName)
        baseName = traceTextFileName.replace('.json', '').replace('logState-', '')
        traceText = baseName.split('-')
        # [0]: program name (*.exe), [1]: roles of variable, [2]: variable address
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
            # Label traces
            for trace in stateJson['stateTraces']: 
                pass
            
        #Label all traces in a file
        # for traceArr in traceTextArr: 
        #     print(traceArr.__len__(), 'roles =', rolesOfVariableId)
        #     if (traceArr.__len__() == 2 and rolesOfVariableId != '1'): 
        #         continue
            
        #     label(traceArr, rolesOfVariableId)
            
        
        #Finished a file, move it out
        # os.rename(textFilePath, join(dirDone, traceTextFileName))
        
    saveToFile()
    

if __name__ == '__main__':
    init()
    toStateTrace()
    
    if(debug == True): 
        print("traces 0:", traces[0])
        print("traces 1:", traces[1])
        print("labels:", labels)
        print("")
        print("Old labels length:", preLabelCount)
        print("New labels length:", labels.__len__())
        print("New traces length:", traces.__len__())
        print("exeNames: ", exeNames.__len__())
    