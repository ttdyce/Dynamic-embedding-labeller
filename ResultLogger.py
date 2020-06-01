import os
import datetime

def log(units, batch_size, epochs, output_size, lr, summary, trainingHistory, evaluationResult, predictionResult, predictionDetails): 
    logSimply(units, batch_size, epochs, output_size, lr,trainingHistory, evaluationResult, predictionResult, predictionDetails)
    logWithSummary(units, batch_size, epochs, output_size, lr, summary, trainingHistory, evaluationResult, predictionResult, predictionDetails)

def logWithSummary(units, batch_size, epochs, output_size, lr, summary, trainingHistory, evaluationResult, predictionResult, predictionDetails): 
    now = datetime.datetime.now()
    nowStr = now.strftime("%Y-%m-%d %H:%M:%S")
    
    log = f'''[{nowStr}] Config: units={units} batch_size={batch_size} epochs={epochs} output_size={output_size} lr={lr}
# Model summary
{summary}

# Results
Training    loss: {trainingHistory.history['loss'][epochs-1]} - accuracy: {trainingHistory.history['accuracy'][epochs-1]}
            val_loss: {trainingHistory.history['val_loss'][epochs-1]} - val_accuracy: {trainingHistory.history['val_accuracy'][epochs-1]}
Evaluation loss: {evaluationResult[0]} - accuracy: {evaluationResult[1]}
Prediction loss: {predictionResult[0]} - accuracy: {predictionResult[1]}
{predictionDetails}
---

'''
    
    # print(log)

    filename = "log/results.log"
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, "a") as logFile:
        logFile.write(log)

def logSimply(units, batch_size, epochs, output_size, lr, trainingHistory, evaluationResult, predictionResult, predictionDetails): 
    now = datetime.datetime.now()
    nowStr = now.strftime("%Y-%m-%d %H:%M:%S")
    
    log = f'''[{nowStr}] Config: units={units} batch_size={batch_size} epochs={epochs} output_size={output_size} lr={lr}
# Results
Training    loss: {trainingHistory.history['loss'][epochs-1]} - accuracy: {trainingHistory.history['accuracy'][epochs-1]}
            val_loss: {trainingHistory.history['val_loss'][epochs-1]} - val_accuracy: {trainingHistory.history['val_accuracy'][epochs-1]}
Evaluation loss: {evaluationResult[0]} - accuracy: {evaluationResult[1]}
Prediction loss: {predictionResult[0]} - accuracy: {predictionResult[1]}
{predictionDetails}
---

'''

    filename = "log/simple-results.log"
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, "a") as logFile:
        logFile.write(log)
    
# log('units', 'batch_size', 'epochs', 'output_size', 'summary', 'trainingHistory', 'evaluationResult', 'predictionResult', 'predictionDetails')
    