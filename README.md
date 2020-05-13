# Dynamic-embedding-labeller

A Labelling system

## Recommended requirement

- Python 3.7.5
- TensorFlow 2
- numpy
- matplotlib
- sklearn
  
## Labelling steps

1. Do Labelling in the source code, under folder `selected-data/`

~~2. Run the Labeller~~
~~`python main.py`~~

~~3. `dataset.npz` is generated, under folder `out-dataset/`~~

## Labelling

Here is the label id reference (Not all of them are used)

| id  | role               |
| --- | ------------------ |
| 1   | Fixed value        |
| 2   | Stepper            |
| 3   | Gatherer           |
| 4   | Most-recent holder |
| 5   | Most-wanted holder |
| 6   | Follower           |
| 7   | Temporary          |
| 8   | One-way flag       |
| 9   | -                  |
| 10  | -                  |

### Variable trace

To label a variable, replace the initial value to a construtor `Intercept<int>(int initial_value, int label id)` like the follow example.

```c++
for(int stepper = 0; stepper < 10; stepper++){
  //some operation
}
```

```c++
for(Intercept<int> stepper(0, 2); stepper < 10; stepper++){
  //some operation
}
```

Where `Intercept<int> stepper(0, 2)` is equal to `Intercept<int> stepper = Intercept<int>(0, 2)`

Some example can be found in [demo-Intercept.cpp](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/demo-Intercept.cpp) (see commented part) , running this program is easier to understand the class

### State trace

`Assuming you know about variable trace part`  

State trace is eventually putting variable traces into an array, and change the way to access the variable.  
Examples can be found in [demo-Intercept.cpp](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/demo-Intercept.cpp).

```cpp
/* state trace labelling demo */
// labelling 2 variables, [0]: initial value = 1, role = 2 (stepper), [1]: initial value = 0, role = 3 (gatherer)
Intercept<int> intercepts[2] = {Intercept<int>(1, 2), Intercept<int>(0, 3)};
StateIntercept state(intercepts, 2);

// access variable using the class StateIntercept
state[0] = 10;

for (state[0]; state[0] > 0; state[0]--)
{
    state[1] += state[0];
}
```

## Use the dataset

A class called `DatasetLoader` is recommended to access `dataset.npz` file easily, like this:

```python
# assuming DatasetLoader.py is under the same folder
import DatasetLoader as loader

x, y, lengths, lengthMax = loader.variableTrace.load()
x, y, lengths, lengthMax, exeNames, roleInStates = loader.stateTrace.load()
x, y, lengths, lengthMax, exeNames, roleInStates = loader.stateTrace.load(model='2b')
(x1, x2), y, lengths, lengthMax, exeNames, roleInStates = loader.stateTrace.load(model='3')
(x1, x2), y, lengths, lengthMax, exeNames, roleInStates = loader.stateTrace.r5.load(model='3')

```

See [simple_rnn_model3.py](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/simple_rnn_model3.py) for the latest dataset demo

~~See [simple_autoencoder.py](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/simple_autoencoder.py), [simple_classifier.py](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/simple_classifier.py), [simple_demo1.py](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/simple_demo1.py)~~

The above program is built for variable trace, not sure if they work with state trace.
