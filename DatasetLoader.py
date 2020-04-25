import numpy as np
# from sklearn.preprocessing import LabelEncoder
# from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import LabelBinarizer
from sklearn.model_selection import train_test_split
import random


class DatasetLoader:
    def loadDefault(self):
        return self.load("out-dataset/dataset.npz")
    
    def loadRaw(self, datasetPath): 
        datasetPath = datasetPath
        with np.load(datasetPath, allow_pickle=True) as dataset:
            traces = dataset["traces"]
            lengths = dataset["lengths"]
            labels = dataset["labels"]
            # exeNames = dataset["exeNames"]
            
        return traces, labels, lengths #, exeNames

    def load(self, datasetPath):
        
        traces, labels, lengths = self.loadRaw(datasetPath)

        # stateLengths = [t[0].__len__() for t in traces]
        # traces, lengthsMax = self.padZeroTraces(traces)
        traces, lengthsMax = self.padZero(traces, lengths)
        
        
        # labels = self.compress(labels, stateLengths)
        labels = self.oneHot(labels)
        lengthMax = np.array(lengths).max()
        
        # print("traces", np.array([t for t in traces]).shape)
        # print("labels", labels[:3])
        
        # x_train, x_test, y_train, y_test = train_test_split(traces, labels, test_size=0.2)

        return np.array([t for t in traces]), labels, lengths, lengthMax #, exeNames

    def padZero(self, traces, lengths):
        out = traces
        lenMax = lengths.max()
        for i in range(traces.__len__()): 
            out[i] = np.pad(traces[i], (0, lenMax - lengths[i]))
            
        return out, lenMax
        
    def padZeroTraces(self, data):
        # Get lengths of each row of data
        lens = [i.__len__() for i in data]
        
        variableCountInState = [d[0].__len__() for d in data]
        countMax = np.array(variableCountInState).max()
        for i in range(variableCountInState.__len__()): 
            for j in range(data[i].__len__()): 
                data[i][j] = np.pad(data[i][j], (0, countMax - data[i][j].__len__()))
            
              
        lensMax = np.array(lens).max()
        out = data 
        # print(np.array(data[0]).shape)
        # print(data[0])
        for i in range(out.__len__()):
            trace = out[i]
            # print(np.array(trace).shape)
            out[i] = np.pad(trace, ((0, lensMax - lens[i]), (0, 0)), constant_values=0)
        
        return out, lensMax

    def compress(self, labels, stateLengths): 
        # unique, counts = np.unique(names, return_counts=True) # ? Sometimes the order is wrong
        count = 0
        compressedLabels = []
        for i in stateLengths: 
            cLabel = []
            
            for k in range(i): 
                cLabel.append(labels[count])
                count += 1
                
            compressedLabels.append(cLabel)
        
        return compressedLabels
        
    # ref: https://chrisalbon.com/machine_learning/preprocessing_structured_data/one-hot_encode_features_with_multiple_labels/
    def oneHot(self, labels): 
        one_hot = LabelBinarizer()
        return one_hot.fit_transform(labels)
        
            # values = np.array(labels)
            # # integer encode
            # label_encoder = LabelEncoder()
            # integer_encoded = label_encoder.fit_transform(values)
            # # binary encode
            # onehot_encoder = OneHotEncoder(sparse=False)
            # integer_encoded = integer_encoded.reshape(len(integer_encoded), 1)
            # onehot_encoded = onehot_encoder.fit_transform(integer_encoded)
            
        # return labels
    
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
        

# print(DatasetLoader().loadDefault())