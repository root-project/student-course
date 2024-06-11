# Fitting and parameter estimation
Welcome to the exercises of the **Fitting and parameter estimation** learning module!

Since fitting is a complex topic we provide a number of exercises. We know the time at the today's course is limited, so please follow your pace and attempt as many exercises as you can. You can always come back to them later. The section is split into notebook exercises and examples as well as the macros.

## The beginning

Open the [notebook](histograms_histogram_fitting_and_graphs.ipynb). The notebook is filled, it contains a chain of operations in which you create a histogram (recap from the previous module), fit the function to this histogram and draw a graph. A useful tool of histogram stacks and efficiency curves are also introduced. Once you're more familiar with the methods, start with the following exercises.

## Notebooks

### Simple fitting example 

Fill in the following [notebook](FittingExample.ipynb). This notebook shows how to fit an histogram in Python (using PyROOT) with a user defined function (implemented in C++ for better CPU efficiency). The solution is also available. 

### Example of fitting an histogram with a Gaussian function

The [notebook](GausFit.ipynb) shows how to fit an histogram using ROOT with a simple function such as a Gaussian. We show how to use the default chi-square method and the binned likelihood method for fitting histograms. We also show how to plot the fit residual using the TRatioPlot and to compute the chi2 for a goodness of fit test.

### Additional examples

We provide two extra examples for those of you who want to train even more or would like to come back to the fitting module exercises in the future:
- [GausFit_2](GausFit_2.ipynb)
- [CentralLimittheorem](CentralLimitTheorem.ipynb)
- [HiggsBinFit](HiggsBinFit.ipynb) - which shows how we really work with the data, here looking for the Higgs signal events. 

## Macros

### Your First fit with ROOT
The macro [firstFit.C](firstFit.C) is only half-way complete. In the code a fit of a histogram is performed
and the parameters of the fitted model are inspected.
Try to complete the code putting to a good use what you learned during the lectures.
The solution is available in the [firstFit_Solution.C](firstFit_Solution.C) macro.

### Correlation of Parameters
The [correlatedParameters.C](correlatedParameters.C) is a simple macro which fits an exponential to a histogram. It seems that there is a problem. While the fit parameters look ok, the correlation matrix shows something fishy. Can you say what is going wrong and why?

### Likelihood and Chi-Square estimators
Run the macro [fitPanel.C](fitPanel.C) with this command
```
root -l fitPanel.C
```
This leaves a window with a histogram drawn open. The entries are distributed according to a Gauss but the bins are narrow and the number of entries is low. Right click on the histogram line (or with two fingers if you have a mac). Select *FitPanel* to open a fit panel. Now fit the histogram selecting the Chi-Square and Likelihood estimators.
What changes to the parameter values and to their uncertainties?
