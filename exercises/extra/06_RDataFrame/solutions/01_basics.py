"""
Python solution for the 01_basics exercise using RDataFrame with JIT compiled C++ functions.
"""
import ROOT

# Create an RDataFrame to process the dataset
dataset_name = "dataset"
file_path = "../data/example_file.root"
df = ROOT.RDataFrame(dataset_name, file_path)

# Select the events where column `b` values are less than 0.5
# Define a new column with the natural logarithm of values from column `a`
# Create the histogram of the new column
h = (
    df.Filter("b < 0.5")
      .Define("loga", "std::log(a)")
      .Histo1D(("h", "A beautiful histo", 30, -5, 5), "loga")
)

# Produce the plot
c = ROOT.TCanvas()
h.Draw()
c.SaveAs("01_basics.png")
