# Dynamic-embedding-labeller

A Labelling system

## Suggested requirement

- Python 3.7.5
  - with numpy installed (pip install numpy)

## Input

```json
'1': Fixed value, '2': Stepper, '3': Gatherer, '': noise, 'q': save & quit
```

1. Type the label id according to the 'variable trace text' showing on the screen
2. (Repeat step 1 untill you want to stop)
3. Type `q` when you are finished labelling

## Output

```python
# import numpy as np

dirOut = "out-dataset/"
# do save & exits
np.savez(dirOut + 'dataset.npz'
        , traces=datasets
        , lengths=[len(i) for i in datasets]
        , labels=labels)
```

A file `out-dataset/dataset.npz` will be created after typing `q`. 

## Using the output

Take `Training.py` as a demo

**Important note**
**Copy the `out-dataset/dataset.npz` to the same folder with `Training.py`**

```python
# class Training: ...

def numpy_fillna(data):
    # Get lengths of each row of data
    lens = np.array([len(i) for i in data])

    # Mask of valid places in each row
    mask = np.arange(lens.max()) < lens[:,None]

    # Setup output array and put elements from data into masked positions
    out = np.zeros(mask.shape, dtype=data.dtype)
    out[mask] = np.concatenate(data)
    return out

traces = []
lengths = []
labels = []

with np.load('dataset.npz', allow_pickle=True) as dataset: 
    traces = dataset['traces'];
    lengths = dataset['lengths'];
    labels = dataset['labels'];

traces = numpy_fillna(traces)

CLASSES = 4
program_number = labels.__len__()
batch_size = labels.__len__()

print(traces)
print(lengths)
print(labels)

print(CLASSES, program_number, batch_size)

t = Training(traces, lengths, labels, traces, lengths, labels)
t.train_evaluate()
```

## Usage

1. Run the Labeller
`python labeller.py`

2. Do Labelling
3. Quit and output labelling
4. Generate the `dataset.npz`
