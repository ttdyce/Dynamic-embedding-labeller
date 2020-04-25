import numpy as np
import random
from sklearn.preprocessing import LabelBinarizer
from sklearn.model_selection import train_test_split
import random

class Trace(): 
    def load(self, **kwargs): 
        return self.preprocess(self.path, **kwargs)
    
    def padZero(self, traces, lengths):
        out = traces
        lenMax = lengths.max()
        for i in range(traces.__len__()):
            out[i] = np.pad(traces[i], (0, lenMax - lengths[i]))

        return np.array(out), lenMax

    def normalize(self, traces):
        for t in traces:
            for i in range(t.__len__()):
                item = t[i]
                # replace -1 to 999
                if item == -1:
                    t[i] = 999
                # x becomes x / x.max()
                # tracesMax = np.array(traces.max()).max()
                # t[i] = item / tracesMax

        return traces
    
class StateTrace(Trace): 
    def __init__(self, path): 
        self.path = path
        self.isState = True
        
    def preprocess(self, datasetPath, flatten=True): 
        "Default return [state, timestep, features], if flatten=True, "
        traces, labels, _lengths, exeNames, roleInStates = loadRaw(datasetPath)
        # flatten 3D to 2D
        traces = [np.transpose(t) for t in traces]
        traces = [t for ts in traces for t in ts]
        lengths = np.array([t.__len__() for t in traces])
        
        traces, lengthsMax = self.padZero(traces, lengths)
        traces, lengthsMax = self.normalize(traces)

        labels = self.oneHot(labels)
        lengthMax = np.array(lengths).max()
        # x_train, x_test, y_train, y_test = train_test_split(traces, labels, test_size=0.2)

        return np.array([t for t in traces]), labels, lengths, lengthMax , exeNames, roleInStates
    
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
        super().normalize(traces)
        
        return np.delete(traces, np.s_[300:], axis=1), 300
    
class VariableTrace(Trace): 
    def __init__(self, path): 
        self.path = path
        self.isState = False
    
    def preprocess(self, datasetPath): 
        traces, labels, lengths = loadRaw(datasetPath, False)
            
        traces = self.normalize(traces)
        traces, lengthsMax = self.padZero(traces, lengths)

        # labels = self.oneHot(labels)
        lengthMax = np.array(lengths).max()

        # print("traces", np.array([t for t in traces]).shape)
        # print("labels", traces[:3])
        # print("")
        # print("labels", labels[:3])

        # x_train, x_test, y_train, y_test = train_test_split(traces, labels, test_size=0.2)
        return np.array([t for t in traces]), labels, lengths, lengthMax
    
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

stateTrace = StateTrace("out-dataset/dataset.npz")
variableTrace = VariableTrace("out-dataset/dataset-variable-trace-110.npz")

def loadRaw(datasetPath, isState=True):
    with np.load(datasetPath, allow_pickle=True) as dataset:
        traces = dataset["traces"]
        lengths = dataset["lengths"]
        labels = dataset["labels"]
            # only found in state
        if(isState): 
            exeNames = dataset["exeNames"]
            roleInStates = dataset["roleInStates"]

    if(isState): 
        return traces, labels, lengths, exeNames, roleInStates
    else: 
        return traces, labels, lengths
        
# loaded = variableTrace.load()
loaded = stateTrace.load()
print(loaded)
# t = variableTrace.loadPredition(20, stack=True)
# print([np.array(i).shape for i in variableTrace.loadPredition(20, stack=True)])
