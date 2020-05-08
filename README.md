# Dynamic-embedding-labeller

A Labelling system

## Suggested requirement

- Python 3.7.5
  - with numpy installed (pip install numpy)
  
## Labelling steps

1. Do Labelling in the source code, under folder `selected-data/`

2. Run the Labeller
`python main.py`

3. `dataset.npz` is generated, under folder `out-dataset/`

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
| 9   |                    |
| 10  |                    |

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

Some example can be found in [demo-Intercept.cpp](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/demo-Intercept.cpp), running this program is easier to understand the class

<!-- ## Explore the dataset

A file `out-dataset/dataset.npz` will be created after labelling.

You can use the `explore-dataset.py` to see the result briefy.

`python explore-dataset.py` -->

## Use the dataset

A class called `DatasetLoader` is recommended to access the `dataset.npz` file easily, like this:

```python
# assuming DatasetLoader.py is under the same folder
import DatasetLoader as loader

x, y, lengths, lengthMax = loader.variableTrace.load()
x, y, lengths, lengthMax, exeNames, roleInStates = loader.stateTrace.load()

```

~~See [simple_autoencoder.py](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/simple_autoencoder.py), [simple_classifier.py](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/simple_classifier.py), [simple_demo1.py](https://github.com/ttdyce/Dynamic-embedding-labeller/blob/master/simple_demo1.py)~~

The above program is built for variable trace, not sure if they work with state trace.
