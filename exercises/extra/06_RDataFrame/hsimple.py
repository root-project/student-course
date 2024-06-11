"""
Simple tutorial showing distribution of the sum of px and py observables of a dataset.
"""
import ROOT

# Create an RDataFrame to process the dataset
dataset_name = "ntuple"
file_path = "https://root.cern/files/tutorials/hsimple.root"
df = ROOT.RDataFrame(dataset_name, file_path)

# Define the steps to produce the histogram of the distribution
h = (
    df.Filter("std::abs(pz) < 2")
      .Define("pxpy", "px+py")
      .Histo1D(("xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10), "pxpy")
)

# Produce the plot
c = ROOT.TCanvas()
h.Draw()
c.SaveAs("hsimple.png")
