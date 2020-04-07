import numpy as np
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import OneHotEncoder
from sklearn.model_selection import train_test_split


class DatasetLoader:
    def loadRaw(self): 
        datasetPath = "out-dataset/dataset.npz"
        with np.load(datasetPath, allow_pickle=True) as dataset:
            traces = dataset["traces"]
            lengths = dataset["lengths"]
            labels = dataset["labels"]
            
        return traces, labels, lengths
    
    def loadDefault(self):
        return self.load("out-dataset/dataset.npz")

    def load(self, datasetPath):
        with np.load(datasetPath, allow_pickle=True) as dataset:
            traces = dataset["traces"]
            lengths = dataset["lengths"]
            labels = dataset["labels"]
            exeNames = dataset["exeNames"]
        
        # print(np.array(traces[:2]))
        # print(traces[0].tolist())
        # print(traces[1].tolist())

        print(traces.dtype)
        traces, lengthsMax = self.padZeroTraces(traces)
        
        traces = np.array([t for t in traces])
        
        # labels = self.oneHot(labels)
        lengthMax = np.array(lengths).max()
        # print(traces.flatten())
        print(traces.shape)
        # print("\n\n")
        # print([t.shape for t in traces[0]])
        # print("\n\n")
        # print([t.shape for t in traces[0][0]])
        # print("\n\n")
        # print([np.array(i[0]).shape for i in traces])
        # print(np.array(traces[0]).shape)
        # print(np.array(traces[1]).shape)
        # print(np.array(traces[2]).shape)
        # print(np.array(traces[3][0]).tolist())
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

    # ref: https://machinelearningmastery.com/how-to-one-hot-encode-sequence-data-in-python/
    def oneHot(self, labels): 
            values = np.array(labels)
            # integer encode
            label_encoder = LabelEncoder()
            integer_encoded = label_encoder.fit_transform(values)
            # binary encode
            onehot_encoder = OneHotEncoder(sparse=False)
            integer_encoded = integer_encoded.reshape(len(integer_encoded), 1)
            onehot_encoded = onehot_encoder.fit_transform(integer_encoded)
            
            return onehot_encoded

DatasetLoader().loadDefault()