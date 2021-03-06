import numpy as np
import random
from sklearn.preprocessing import LabelBinarizer
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
from collections import Counter
import random


def loadRaw(datasetPath, isState=True, replaceConstant=False):
    with np.load(datasetPath, allow_pickle=True) as dataset:
        traces = dataset["traces"]
        lengths = dataset["lengths"]
        labels = dataset["labels"]
            # only found in state
        if(isState): 
            exeNames = dataset["exeNames"]
            roleInStates = dataset["roleInStates"]

    # replace role 1:constant to 8:one way flag, if needed
    if(replaceConstant):
        for l in labels:
            for i in range(l.__len__()): 
                if(l[i] == 1): 
                    l[i] = 8

    if(isState): 
        return traces, labels, lengths, exeNames, roleInStates
    else: 
        return traces, labels, lengths

def padZero(traces, maxTimestep, dim=3, pad_dim=2): 
    lengths = np.array([item.__len__() for item in traces])
    lenMax = lengths.max()
    for index in range(len(traces)): 
        trace = traces[index].tolist()
        # for i in range(lenMax - trace.__len__()): 
        if(trace.__len__() < maxTimestep):
            for i in range(maxTimestep - trace.__len__()): 
                traces[index] = np.append(traces[index], [np.zeros(trace[0].__len__()).astype(int)], axis=0)

        traces[index] = traces[index][:maxTimestep]
    return traces

def normalize(traces, dim=3):
    for trace in traces:
        for t in trace: 
            for i in range(t.__len__()): 
                traceItem = t[i]
                if traceItem == -1:
                    t[i] = 999
                # replace <0 to 0                
                if traceItem < 0:
                    t[i] = 0
    
    return traces

def getDifferentST(indices, t, maxRole):
    originalLength = indices.__len__()
    traceLength = t[0].__len__()
    differentST = []
    
    if(originalLength == 0): 
        supportTraces = []
        for ii in range(maxRole - 1): 
            supportTraces.append([[0] for i in range(traceLength)])
        differentST.append(supportTraces)
        return differentST
    
    indices = np.pad(indices, (0, maxRole - indices.__len__() - 1), constant_values=-1)
    STIndices = []
    for index in range(maxRole - 1): 
        temp = indices
        firstElement = temp[0]
        temp = np.delete(temp, 0)
        temp = np.insert(temp, index, firstElement)
        
        # temp = np.pad(temp, (0, maxRole - temp.__len__()), constant_values=-1)
        STIndices.append(temp)
    
    for STindex in STIndices: 
        supportTraces = []
        for index in STindex: 
            if(index != -1): 
                supportTraces.append([[item] for item in t[index]])
            else: 
                supportTraces.append([[0] for i in range(traceLength)])
        # if(indices.__len__() + 1 < maxRole): 
        #     for ii in range(maxRole - (indices.__len__() + 1)): 
        #         supportTraces.append([[0] for i in range(traceLength)])
        differentST.append(supportTraces)
    
    return differentST
class Trace(): 
    def load(self, **kwargs): 
        return self.preprocess(self.path, **kwargs)
    
    def padZero(self, traces, lengths):
        out = traces
        lenMax = lengths.max()
        for i in range(traces.__len__()):
            out[i] = np.pad(traces[i], (0, lenMax - lengths[i]))
            out[i] = out[i][:22]

        return np.array(out), lenMax

    def normalize(self, traces):
        for t in traces:
            for i in range(t.__len__()):
                item = t[i]
                # replace -1 to 999
                if item == -1:
                    t[i] = 999
                # replace <0 to 0                
                if item < 0:
                    t[i] = 0
                # x becomes x / x.max()
                # tracesMax = np.array(traces.max()).max()
                # t[i] = item / tracesMax

        return traces
    
class StateTrace(Trace): 
    def __init__(self, path, isPrediction = False, maxRole = None, roles=3, replaceConstant=False): 
        self.path = path
        self.isState = True
        self.isPrediction = isPrediction
        self.maxRole = maxRole
        self.roles = roles
        self.replaceConstant = replaceConstant
        
        if(self.roles == 3): 
            self.r4 = StateTrace("out-dataset/dataset-state-trace-110-r4.npz", roles=4)
            self.r5 = StateTrace("out-dataset/dataset-state-trace-110-r5.npz", roles=5)
            self.r7 = StateTrace("out-dataset/dataset-state-trace-105-r7.npz", roles=7)
            self.r4mod = StateTrace("out-dataset/dataset-state-trace-110-r5.npz", roles=4, replaceConstant=True)
            self.r6mod = StateTrace("out-dataset/dataset-state-trace-105-r7.npz", roles=6, replaceConstant=True)
            
            if(self.isPrediction != True): 
                traces, labels, _lengths, exeNames, roleInStates = loadRaw(self.path)
                maxRole = max(roleInStates)
                self.prediction = StateTrace("out-dataset/prediction/dataset.npz", isPrediction=True, maxRole=maxRole)
        
        if(self.roles == 4): 
            if(self.isPrediction != True): 
                traces, labels, _lengths, exeNames, roleInStates = loadRaw(self.path)
                maxRole = max(roleInStates)
                self.prediction = StateTrace("out-dataset/prediction/r5/dataset.npz", isPrediction=True, maxRole=maxRole, roles=4, replaceConstant=True)
        if(self.roles == 5): 
            if(self.isPrediction != True): 
                traces, labels, _lengths, exeNames, roleInStates = loadRaw(self.path)
                maxRole = max(roleInStates)
                self.prediction = StateTrace("out-dataset/prediction/r5/dataset.npz", isPrediction=True, maxRole=maxRole, roles=5)
            
        
    def preprocess(self, datasetPath, flatten=True, model=None): 
        "Default return [state, timestep, features], if flatten=True, "
        traces, labels, _lengths, exeNames, roleInStates = loadRaw(datasetPath, replaceConstant = self.replaceConstant)
        
        if(self.isPrediction == False and self.maxRole == None): 
            maxRole = roleInStates.max()
        else: 
            maxRole  = self.maxRole
        
        
        if(model == None): 
            # flatten 3D to 2D
            traces = [np.transpose(t) for t in traces]
            traces = [t for ts in traces for t in ts]
            lengths = np.array([t.__len__() for t in traces])
            
            traces, lengthsMax = self.padZero(traces, lengths)
            traces, lengthsMax = self.normalize(traces)

            labels = self.oneHot(labels)
            # x_train, x_test, y_train, y_test = train_test_split(traces, labels, test_size=0.2)
            return np.array([t for t in traces]), labels, lengths, lengthsMax , exeNames, roleInStates
        if(model == '1'): 
            outTraces = []
            for t in traces: 
                t = np.array(t).transpose()
                traceLength = t.__len__()
                for i in range(traceLength): 
                    indices = list(range(traceLength))
                    indices.remove(i)
                    
                    mainTrace = [[item] for item in t[i]]
                    supportTraces = []
                    for index in indices: 
                        supportTraces.append([[item] for item in t[index]])
                    if(indices.__len__() == 0): 
                        supportTraces = [[[0] for i in range(mainTrace.__len__())]]
                    
                    generated = [np.concatenate((mainTrace, supportTrace), axis=1) for supportTrace in supportTraces]
                    outTraces.extend(generated)
            
            outLabels = []
            for l in labels: 
                length = l.__len__()
                for item in l: 
                    if(length == 1): 
                        outLabels.append(item)
                    else: 
                        for i in range(length-1): 
                            outLabels.append(item)
            
            outTraces = normalize(outTraces)
            outTraces = padZero(outTraces, 300)
            lengths = np.array([t.__len__() for t in outTraces])
            lengthsMax = lengths.max()
            
            return np.array(outTraces), np.array(LabelBinarizer().fit_transform(outLabels)), lengths, lengthsMax , exeNames, roleInStates
        if(model == '2a'): 
            outTraces = []
            # maxRole = roleInStates.max()
            for t in traces: 
                t = np.array(t).transpose()
                traceLength = t.__len__()
                for i in range(traceLength): 
                    indices = list(range(traceLength))
                    indices.remove(i)
                    
                    mainTrace = [[item] for item in t[i]]
                    supportTraces = []
                    for index in indices: 
                        supportTraces.append([[item] for item in t[index]])
                    if(indices.__len__() + 1 < maxRole): 
                        for ii in range(maxRole - (indices.__len__() + 1)): 
                            supportTraces.append([[0] for i in range(mainTrace.__len__())])
                    
                    generated = mainTrace
                    for supportTrace in supportTraces: 
                        generated = np.concatenate((generated, supportTrace), axis=1) 
                     
                    outTraces.append(generated)
            
            outTraces = normalize(outTraces)
            outTraces = padZero(outTraces, 300)
            lengths = np.array([t.__len__() for t in outTraces])
            lengthsMax = lengths.max()
            labels = self.oneHot(labels)
            
            return np.array(outTraces), labels, lengths, lengthsMax , exeNames, roleInStates
        
        if(model == '2b'): 
            outTraces = []
            # maxRole = roleInStates.max()
            # dig into each state
            for t in traces: 
                # each trace become [timestep, single role] ([[0,1,2,3,4], [0,0,0,0,0], ...])
                t = np.array(t).transpose()
                traceLength = t.__len__() # in terms of timestep
                for i in range(traceLength): 
                    indices = list(range(traceLength))
                    indices.remove(i)
                    
                    mainTrace = [[item] for item in t[i]]
                    differentST = getDifferentST(indices, t, maxRole)
                    
                    supportTraces = []
                    # for index in indices: 
                    #     supportTraces.append([[item] for item in t[index]])
                    # if(indices.__len__() + 1 < maxRole): 
                    #     for ii in range(maxRole - (indices.__len__() + 1)): 
                    #         supportTraces.append([[0] for i in range(mainTrace.__len__())])
                    
                    for supportTraces in differentST: 
                        generated = mainTrace
                        for supportTrace in supportTraces: 
                            generated = np.concatenate((generated, supportTrace), axis=1) 
                        
                        outTraces.append(generated)
            
            outLabels = []
            for l in labels: 
                length = l.__len__()
                for item in l: 
                    if(length == 1): 
                        outLabels.append(item)
                    else: 
                        for i in range(maxRole - 1): 
                            outLabels.append(item)
                            
            outTraces = normalize(outTraces)
            outTraces = padZero(outTraces, 300)
            lengths = np.array([t.__len__() for t in outTraces])
            lengthsMax = lengths.max()
            
            return np.array(outTraces), np.array(LabelBinarizer().fit_transform(outLabels)), lengths, lengthsMax , exeNames, roleInStates
        if(model == '3'): 
            x, y, lens, lenMax, exeNames, roleInStates = self.load(model='2b')
            x1 = []
            for i in x: 
                x1.append([[k[0]] for k in i])
            x1 = np.array(x1)

            x2 = []
            for i in x: 
                x2.append([k[1:] for k in i])
            x2 = np.array(x2)
            
            return (x1, x2), y, lens, lenMax, exeNames, roleInStates
        
    
    def oneHot(self, labels):
        "loop through labels, one hot & flatten them"
        outLabels = labels
        # flatten
        outLabels = [i for items in outLabels for i in items]
        #one hot
        outLabels = LabelBinarizer().fit_transform(outLabels)
        
        return outLabels
    
    def normalize(self, traces):
        "Further remove last dim ([300:])"
        out_traces = super().normalize(traces)
        out_traces = np.delete(out_traces, np.s_[300:], axis=1)
        
        return out_traces, 300
    
class VariableTrace(Trace): 
    def __init__(self, path): 
        self.path = path
        self.isState = False
    
    def preprocess(self, datasetPath): 
        traces, labels, lengths = loadRaw(datasetPath, False)
            
        traces = self.normalize(traces)
        traces, lengthsMax = self.padZero(traces, lengths)
        traces = np.array([t for t in traces])
        traces = traces.reshape(traces.shape[0], traces.shape[1], 1)

        labels = self.oneHot(labels)
        lengthMax = np.array(lengths).max()

        # print("traces", np.array([t for t in traces]).shape)
        # print("labels", traces[:3])
        # print("")
        # print("labels", labels[:3])

        # x_train, x_test, y_train, y_test = train_test_split(traces, labels, test_size=0.2)
        return traces, labels, lengths, lengthMax
    
    def oneHot(self, labels):
        "reference: https://chrisalbon.com/machine_learning/preprocessing_structured_data/one-hot_encode_features_with_multiple_labels/"
        return LabelBinarizer().fit_transform(labels)
    
    def loadPredition(self, length, stack=False): 
        "Generate prediction data for 3 roles"
        predictions = [None] * 3
        predictions[0] = [np.zeros(length), np.ones(length), np.full(length, 999), np.full(length, -1)] # ? -1 may not work ._.
        predictions[1] = [np.arange(0, length, 1), np.arange(length, 0, -1), np.arange(0, 3 * length, 3), np.arange(1, 2 * length, 2)]
        predictions[2] = [np.insert(np.arange(0, length - 1, 1), 0, 0), 
                         np.insert(np.arange(0, length * 2 - 2, 2), 0, 0), 
                         np.pad(sorted(np.arange(10), key=lambda k: random.random()), (0, length - 10)), 
                         np.pad(sorted(np.arange(0, 100, 10), key=lambda k: random.random()), (0, length - 10))
                         ]
        predictions = np.array([np.array(p).astype(float) for p in predictions])
        
        if (not stack):
            return predictions
        else: 
            return predictions.reshape(12, length)

stateTrace = StateTrace("out-dataset/dataset-state-trace-110.npz")
variableTrace = VariableTrace("out-dataset/dataset-variable-trace-110.npz")
# sampleTrace = StateTrace("out-dataset/dataset.npz")

loaded = variableTrace.load()
# loaded = stateTrace.r5.prediction.load(model='2b')
# loaded = sampleTrace.load(model='2b')
# loaded = stateTrace.r4mod.load()
print(loaded[0], loaded[1], sep='\n---\n')
