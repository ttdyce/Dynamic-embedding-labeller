import numpy as np
# from sklearn.preprocessing import LabelEncoder
# from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.model_selection import train_test_split


class DatasetLoader:
    def loadDefault(self):
        return self.load("out-dataset/dataset.npz")
    
    def loadRaw(self, datasetPath): 
        datasetPath = datasetPath
        with np.load(datasetPath, allow_pickle=True) as dataset:
            traces = dataset["traces"]
            lengths = dataset["lengths"]
            labels = dataset["labels"]
            exeNames = dataset["exeNames"]
            
        return traces, labels, lengths, exeNames

    def load(self, datasetPath):
        
        traces, labels, lengths, exeNames = self.loadRaw(datasetPath)

        stateLengths = [t[0].__len__() for t in traces]
        traces, lengthsMax = self.padZeroTraces(traces)
        
        traces = np.array([t for t in traces])
        
        labels = self.compress(labels, stateLengths)
        labels = self.oneHot(labels)
        lengthMax = np.array(lengths).max()
        # print(traces.flatten())
        print(traces.shape)
        
        # x_train, x_test, y_train, y_test = train_test_split(traces, labels, test_size=0.2)

        return traces, labels, lengths, lengthMax, exeNames

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
            
        # vectorize
        # for i in range(out.__len__()):
        #     trace = out[i]
        #     arr = []
        #     for traceItem in trace:
        #         arr.append([traceItem])
            
        #     out[i] = arr
        
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
        one_hot = MultiLabelBinarizer()
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
        

DatasetLoader().loadDefault()