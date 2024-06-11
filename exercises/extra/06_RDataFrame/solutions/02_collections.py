"""
Python solution for the 02_collections exercise using RDataFrame with JIT compiled C++ functions.
"""
import ROOT

# Create an RDataFrame to process the dataset
dataset_name = "dataset"
file_path = "../data/example_file.root"
df = ROOT.RDataFrame(dataset_name, file_path)

# Select the elements of `vec1` for which the square of the corresponding elements in `vec2` is less than 0.1
# Create the histogram of the new column
h = df.Define("v1_to_plot", "vec1[vec2*vec2 < 0.1]").Histo1D("v1_to_plot")

# Produce the plot
c = ROOT.TCanvas()
h.Draw()
c.SaveAs("02_collections.png")
