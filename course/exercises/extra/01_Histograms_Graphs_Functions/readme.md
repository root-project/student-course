# Histograms, Graphs and Functions Exercises

Welcome to the exercises of the **Histograms, Graphs and Functions** learning module!

There are multiple ways of running ROOT - for example, you can use notebooks or you can create macros. Here you can find exercises and examples using both notebooks and macros. 

## Notebooks

For the beginning you can try with the notebooks: 

- [CreateAHistogram](CreateAHistogram.ipynb)
- [graphDraw](graphDraw.ipynb)

if you are stuck in these exercises, take a look at the provided solutions in the `solutions` folder. For the `CreateAHistogram.ipynb` exercise, the solution is provided both as a python notebook and the C++ notebook for you to see and compare the differences.

## Python macros

Now instead of using notebooks, try writing your own python macros. These are the two different exercises, in case you're stuck the solutions are provided both as ROOT macros, but also as notebooks. 

### Build a histogram

In order to complete this exercise about ROOT histograms in PyROOT, please follow these steps:
- Open the Python interpreter.
- Import the ROOT module.
- Create a histogram with 64 bins and an x-axis ranging from 0 to 16.
- Fill it with random numbers distributed according to a linear function (*pol1*).
- Make the line width a bit larger.
- Draw it.

You can find the solution [here](solutions/HistogramMacro.py).

## Build a graph

In order to complete this exercise about ROOT graphs in PyROOT, please follow these steps:
- Create a new Python module.
- In the module, create a graph (*TGraph*).
- Set its title to *My graph*, its X axis title to *myX* and Y axis title to *myY*.
- Fill it with three points: (1,0), (2,3), (3,4).
- Set a red full square marker.
- Draw an orange line between points.

You can find the solution [here](solutions/GraphMacro.py).

## Cpp macros

The next step is writing your own cpp macros. You have 3 different exercises here, again, in case you're stuck, the solutions are provided both as ROOT macros, but also as notebooks. 

### Build a histogram

Create a macro which builds and draws a histogram with the following features:
- The number of bins is 50 and the x axis ranges from 0 to 10.
- It is filled with random numbers distributed according to an exponential distribution which has a rate = 0.5.
  Suggestion: see the [TRandom](https://root.cern.ch/doc/master/classTRandom.html) for generating random numbers or
  [TH1::FillRandom](https://root.cern.ch/doc/master/classTH1.html#random-numbers)
- Its line width is thicker than the default one.

You can find the solution as C++ macro [SimpleHistogram.C](solutions/SimpleHistogram.C) and [notebook](solutions/SimpleHistogram.ipynb).

### Build a graph
Create a macro which builds and draws a graph with the following features:
- The title of the plot is *My graph*.
- The x and y axis have labels `my_{X}` and `my_{Y}` respectively.
- It has three points with the following coordinates (1,0), (2,3), (3,4).
- The marker is a full square. Its colour is red.
- An orange line joins the points.

You can find the solution as C++ macro [SimpleGraph.C](solutions/SimpleGraph.C) and as [notebook](solutions/SimpleGraph.ipynb).

### Build a function
Create a macro that follows these steps:
- Create a function with formula *cos(x)* and draw it.
- Create another *cos(x)*, but scale the argument of the cosine by adding a parameter.
- Set a value for the parameter.
- Change the line color of the second function.
- Draw the second function in the same canvas as the first one.

You can find the solution as C++ macro [SimpleFunction.C](solutions/SimpleFunction.C) and as [notebook](solutions/SimpleFunction.ipynb).
