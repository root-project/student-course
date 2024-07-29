import ROOT
import numpy as np

# Create a graph with three points: (1,0), (2,3), (3,4)
x = np.array([1,2,3], dtype=float)
y = np.array([0,3,4], dtype=float)
g = ROOT.TGraph(n=x.size, x=x, y=y)

# Set its title to My graph, its X axis title to myX and Y axis title to myY
g.SetTitle("My graph;myX;myY")

# Set a red full square marker
g.SetMarkerStyle(ROOT.kFullSquare)
g.SetMarkerColor(ROOT.kRed)

# Draw an orange line between points
g.SetLineColor(ROOT.kOrange)

# Draw the graph
# "A": draw the axis
# "P": draw the points
# "L": draw graph as a simple line
g.Draw("APL")
