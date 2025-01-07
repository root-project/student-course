"""
Adaptation of the tutorial at https://root.cern/doc/master/df102__NanoAODDimuonAnalysis_8py.html
"""
import ROOT

# Create dataframe from NanoAOD files
dataset_name = "Events"
file_path = "root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root"
df = ROOT.RDataFrame(dataset_name, file_path)

# Optional: to see the results faster, restrict the tutorial to the first one million entries of the dataset
df = df.Range(1_000_000)

# For simplicity, select only events with exactly two muons and require opposite charge
df_2mu = df.Filter("nMuon == 2")
df_os = df_2mu.Filter("Muon_charge[0] != Muon_charge[1]")

# Compute invariant mass of the dimuon system
df_mass = df_os.Define("Dimuon_mass", "InvariantMass(Muon_pt, Muon_eta, Muon_phi, Muon_mass)")

# Make histogram of dimuon mass spectrum. Note how we can set titles and axis labels in one go.
bins = 30_000
xlow = 0.25
xup = 300
h = df_mass.Histo1D(("Dimuon_mass", "Dimuon mass;m_{#mu#mu} (GeV);N_{Events}", bins, xlow, xup), "Dimuon_mass")

# Produce the plot
c = ROOT.TCanvas("c", "", 800, 700)
c.SetLogx()
c.SetLogy()

h.SetTitle("")
h.GetXaxis().SetTitleSize(0.04)
h.GetYaxis().SetTitleSize(0.04)
h.Draw()

c.SaveAs("dimuon_spectrum.png")
