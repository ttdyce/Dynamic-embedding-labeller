import os
import datetime
import tensorflow.keras as keras

def plot_model(model, png_name): 
    keras.utils.plot_model(model, f'log/{png_name}.png')

def log(summary, training_history, evaluation_result, prediction_result, prediction_details, **kwargs): 
    logSimply(training_history, evaluation_result, prediction_result, prediction_details, **kwargs)
    log_with_summary(summary, training_history, evaluation_result, prediction_result, prediction_details, **kwargs)

def log_with_summary(summary, training_history, evaluation_result, prediction_result, prediction_details, **kwargs): 
    now = datetime.datetime.now()
    now_str = now.strftime("%Y-%m-%d %H:%M:%S")
    epochs = kwargs['epochs']
    
    log = f'''[{now_str}]
#Config
{kwargs}

# Model summary
{summary}

# Results
Training    loss: {training_history.history['loss'][epochs-1]} - accuracy: {training_history.history['accuracy'][epochs-1]}
            val_loss: {training_history.history['val_loss'][epochs-1]} - val_accuracy: {training_history.history['val_accuracy'][epochs-1]}
Evaluation loss: {evaluation_result[0]} - accuracy: {evaluation_result[1]}
Prediction loss: {prediction_result[0]} - accuracy: {prediction_result[1]}
{prediction_details}
---

'''
    
    # print(log)

    filename = "log/results.log"
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, "a") as logFile:
        logFile.write(log)

def logSimply(training_history, evaluation_result, prediction_result, prediction_details, **kwargs): 
    now = datetime.datetime.now()
    now_str = now.strftime("%Y-%m-%d %H:%M:%S")
    epochs = kwargs['epochs']
    
    log = f'''[{now_str}] 
#Config
{kwargs}

# Results
Training    loss: {training_history.history['loss'][epochs-1]} - accuracy: {training_history.history['accuracy'][epochs-1]}
            val_loss: {training_history.history['val_loss'][epochs-1]} - val_accuracy: {training_history.history['val_accuracy'][epochs-1]}
Evaluation loss: {evaluation_result[0]} - accuracy: {evaluation_result[1]}
Prediction loss: {prediction_result[0]} - accuracy: {prediction_result[1]}
{prediction_details}
---

'''

    filename = "log/simple-results.log"
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, "a") as logFile:
        logFile.write(log)
    

# logSimply('history', 'evaluationResult', 'predictionResult', 'predictionDetails', units='units', batch_size_fit='batch_size_fit', epochs='epochs', output_size='output_size', learning_rate='learning_rate', remark='trying all relu')