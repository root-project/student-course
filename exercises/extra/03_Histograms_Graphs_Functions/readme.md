# Histograms, Graphs and Functions Exercises

Welcome to the exercises of the **Histograms, Graphs and Functions** learning module!

As we saw earlier in the course, there are multiple ways of running ROOT - for example, you can use notebooks or you can create macros. Here you can find exercises and examples using both notebooks and macros. 

## Notebooks

For the beginning you can try with the notebooks: 

- [CreateAHistogram](CreateAHistogram.ipynb)
- [graphDraw](graphDraw.ipynb)

if you are stuck in these exercises, take a look at the provided solutions. 

## Macros

The next step is writing your own macros. You have 3 different exercises here, again, in case you're stuck the solutions are provided both as macros, but also as notebooks. 
### Build a histogram
Create a macro which builds and draws a histogram with the following features:
- The number of bins is 50 and the x axis ranges from 0 to 10.
- It is filled with random numbers distributed according to an exponential distribution which has a rate = 0.5.
  Suggestion: see the [TRandom](https://root.cern.ch/doc/master/classTRandom.html) for generating random numbers or
  [TH1::FillRandom](https://root.cern.ch/doc/master/classTH1.html#random-numbers)
- Its line width is thicker than the default one.

You can find the solution as C++ macro [SimpleHistogram.C](SimpleHistogram.C) and [notebook](SimpleHistogram.ipynb).

### Build a graph
Create a macro which builds and draws a graph with the following features:
- The title of the plot is *My graph*.
- The x and y axis have labels `my_{X}` and `my_{Y}` respectively.
- It has three points with the following coordinates (1,0), (2,3), (3,4).
- The marker is a full square. Its colour is red.
- An orange line joins the points.

You can find the solution as C++ macro [SimpleGraph.C](SimpleGraph.C) and as [notebook](SimpleGraph.ipynb).

### Build a function
Create a macro that follows these steps:
- Create a function with formula *cos(x)* and draw it.
- Create another *cos(x)*, but scale the argument of the cosine by adding a parameter.
- Set a value for the parameter.
- Change the line color of the second function.
- Draw the second function in the same canvas as the first one.

You can find the solution as C++ macro [SimpleFunction.C](SimpleFunction.C) and as [notebook](SimpleFunction.ipynb).
