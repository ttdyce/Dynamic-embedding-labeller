import os
from os.path import isfile, join
import numpy as np
import random

# config
debug = True
isContinue = False
preLabelCount = 0
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

def autoLabel(traceArr):
    """Label traces with no value changes (Fix-value)"""
    label(traceArr, 1)

def saveToFile():
    """Save traces and labels to a folder (out-dataset/dataset.npz)"""
    global isContinue, preLabelCount, traces, labels
    
    lengths = [len(i) for i in traces]
    print("Saving...")
    if(isContinue):
        with np.load(dirOut + 'dataset.npz', allow_pickle=True) as dataset: 
            tracesOld = dataset['traces'].tolist()
            lengthsOld = dataset['lengths'].tolist()
            labelsOld = dataset['labels'].tolist()
        
        tracesOld.extend(traces)
        lengthsOld.extend(lengths)
        labelsOld.extend(labels)
        traces = tracesOld
        lengths = lengthsOld
        labels = labelsOld
        
        
        
    np.savez(dirOut + 'dataset.npz'
            , traces=traces
            , lengths=lengths
            , labels=labels)
    
    print("File saved to ", dirOut, "dataset.npz", sep='')
    print("Old dataset length:", preLabelCount)
    print("New dataset length:", lengths.__len__())
    
    pass

def readTraceArr(traceTextFile):
    """Handle multiple traces in one file, return trace text array"""
    content = traceTextFile.read()
    tracesRaw = [i.split(" -> ") for i in content.splitlines()]
    tracesDone = []
    newTrace = []
    b = -999
    for t in tracesRaw:# black magic
        if(t[0] == '-1'): 
            if(newTrace.__len__() != 0):
                tracesDone.append(newTrace)
            newTrace = []
            newTrace.append(t[0])
            newTrace.append(t[1])
        elif(t[0] != b):
            newTrace.append(t[0])
            newTrace.append(t[1])
        else: 
            newTrace.append(t[1])
        b = t[1]
    tracesDone.append(newTrace)
    
    return tracesDone
    

def printTraceText(fileName, traceArr, labelCount):
    """Clean the screen, and print the trace text"""
    _ = os.system('cls')
    print("---", "label count: ", labelCount, "---")
    print('')
    print("File name--- ", fileName, "------", sep="\n")
    print("(value -1: unassigned)")
    print(' -> '.join(traceArr), "------", sep="\n")
    print("('1': Fixed value, '2': Stepper, '3': Gatherer, '': noise, 'q': save & quit)")

def label(traceArr, userInput): 
    """Process the text, return x: variable trace (in an array), and y: label id"""
    #replace '-1' to '999' for input format
    if (traceArr[0] == '-1'):
        traceArr[0] = 999
    else:
        traceArr.insert(0, 999)
    
    #replace '' to '0' for input format
    if (userInput == ''):
        userInput = '0'
    
    x, y = [int(i) for i in traceArr], int(userInput)
    traces.append(x)
    labels.append(y)

def main():
    """Pack the program into main() so that I can use 'return' to quit"""
    global preLabelCount
    
    validLabels = ['', '1', '2', '3', 'q']
    badLabelError = 'Unvalid label! Please try again'
    traceTextFileNames = [f for f in os.listdir(dir) if isfile(join(dir, f))]
    random.shuffle(traceTextFileNames)
    labelCount = preLabelCount
    
    for traceTextFileName in traceTextFileNames: 
        textFilePath = join(dir, traceTextFileName)
        with open(textFilePath, "r") as txtFile: 
            traceTextArr = readTraceArr(txtFile)
        
        #Label all traces in a file
        for traceArr in traceTextArr: 
            if (traceArr.__len__() == 2): 
                autoLabel(traceArr)
                continue
            
            # basic UI
            labelCount += 1
            printTraceText(traceTextFileName, traceArr, labelCount)
            
            # handling input
            userInput = input()
            #1 wrong input
            while(userInput not in validLabels): 
                printTraceText(traceTextFileName, traceArr, labelCount)
                print(badLabelError)
                userInput = input()
            #2 cmd 'q', save and quit
            if(userInput.lower() == 'q'):
                saveToFile()
                return
            #done handling input
                
            #userInput: label id
            label(traceArr, userInput)
        
        #Finished a file, move it out
        os.rename(textFilePath, join(dirDone, traceTextFileName))
        
def main2():
    """Pack the program into main() so that I can use 'return' to quit"""
    global preLabelCount
    
    validLabels = ['0', '1', '2', '3']
    traceTextFileNames = [f for f in os.listdir(dir) if isfile(join(dir, f))]
    labelCount = preLabelCount
    
    for traceTextFileName in traceTextFileNames: 
        textFilePath = join(dir, traceTextFileName)
        baseName = traceTextFileName.replace('.txt', '').replace('log-', '')
        traceText = baseName.split('-')
        # [0]: program name (*.exe), [1]: roles of variable, [2]: variable address
        if(len(traceText) != 3): 
            continue
        
        exeName = traceText[0]
        rolesOfVariableId = traceText[1]
        variableAddress = traceText[2]
        print(exeName, rolesOfVariableId, variableAddress)
        
        with open(textFilePath, "r") as txtFile: 
            traceTextArr = readTraceArr(txtFile)
        
        #Label all traces in a file
        for traceArr in traceTextArr: 
            print(traceArr.__len__(), 'roles =', rolesOfVariableId)
            if (traceArr.__len__() == 2 and rolesOfVariableId != '1'): 
                continue
            
            label(traceArr, rolesOfVariableId)
            
        
        #Finished a file, move it out
        # os.rename(textFilePath, join(dirDone, traceTextFileName))
        
    saveToFile()
    

if __name__ == '__main__':
    init()
    main2()
    
    if(debug == True): 
        print("traces:", traces)
        print("labels:", labels)
        print("")
        print("Old dataset length:", preLabelCount)
        print("New dataset length:", traces.__len__())
    