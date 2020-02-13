import os
from os.path import isfile, join

# config
dir = "out-datasetText/"
dirDone = dir + "labeled/"
dirOut = "out-dataset/"
traces = []
labels = []

def init():
    """Initiate folders"""
    
    for path in [dirDone, dirOut]: 
        try:
            os.makedirs(path)
        except FileExistsError:
            # directory already exists
            pass

def autoLabel(traceText):
    """Label traces with no value changes (Fix-value)"""
    pass

def getVariableTraceTextFile():
    """Load *.txt in datasetText folder (out-datasetText/)"""
    pass

def saveToFile(traces, labels):
    """Save traces and labels to a folder (out-dataset/dataset.npz)"""
    print("Saving...")
    
    print("File saved to ", dirOut, "dataset.npz", sep='')
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
    

def printTraceText(fileName, traceText, labelCount):
    """Clean the screen, and print the trace text"""
    _ = os.system('cls')
    print("---", "label count: ", labelCount, "---")
    print('')
    print("File name--- ", fileName, "------", sep="\n")
    print(traceText)
    print("------")
    print("('1': Fixed value, '2': Stepper, '3': Gatherer, '': noise, 'q': save & quit)")

def label(traceText, userInput): 
    """Process the text, return x: variable trace (in an array), and y: label id"""
    
    pass

def main():
    """Pack the program into main() so that I can use 'return' to quit"""
    
    validLabels = ['', '1', '2', '3']
    badLabelError = 'Unvalid label! Please try again'
    traceTextFileNames = [f for f in os.listdir(dir) if isfile(join(dir, f))]
    labelCount = 0
    
    for traceTextFileName in traceTextFileNames: 
        textFilePath = join(dir, traceTextFileName)
        with open(textFilePath, "r") as txtFile: 
            traceTextArr = readTraceArr(txtFile)
        
        #Label all traces in a file
        for traceText in traceTextArr: 
            if (traceText.__len__() == 1): 
                autoLabel(traceText)
                continue
            
            labelCount += 1
            printTraceText(traceTextFileName, traceText, labelCount)
            
            # handling input
            userInput = input()
            #1 save and quit
            if(userInput.lower() == 'q'):
                saveToFile(traces, labels)
                return
            #2 wrong input
            while(userInput not in validLabels): 
                printTraceText(traceTextFileName, traceText, labelCount)
                print(badLabelError)
                userInput = input()
            #done handling input
                
            #userInput: label id
            # x, y = label(traceText, userInput)
            # traces.append(x)
            # labels.append(y)
        
        #Finished a file, move it out
        # os.rename(textFilePath, join(dirDone, traceTextFileName))
        

if __name__ == '__main__':
    init()
    main()
    