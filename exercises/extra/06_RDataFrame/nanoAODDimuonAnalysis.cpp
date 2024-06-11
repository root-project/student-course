/*
Adaptation of the tutorial at https://root.cern/doc/master/df102__NanoAODDimuonAnalysis_8py.html
*/
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include <TCanvas.h>

int main()
{
   // Create dataframe from NanoAOD files
   ROOT::RDataFrame df_full{"Events", "root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/"
                                      "Run2012BC_DoubleMuParked_Muons.root"};

   // Optional: to see the results faster, restrict the tutorial to the first one million entries of the dataset
   auto df = df_full.Range(1000000);

   // Select events with exactly two muons
   auto df_2mu = df.Filter([](unsigned int nMuon) { return nMuon == 2; }, {"nMuon"});

   // Select events with two muons of opposite charge
   auto df_os = df_2mu.Filter([](const ROOT::RVecI &muonCharge) { return muonCharge[0] != muonCharge[1]; },
                              {"Muon_charge"});

   // Compute invariant mass of the dimuon system
   auto df_mass =
      df_os.Define("Dimuon_mass", ROOT::VecOps::InvariantMass<float>, {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass"});

   // Book histogram of dimuon mass spectrum
   const auto bins = 30000;
   const auto low = 0.25;
   const auto up = 300.0;
   auto hist =
      df_mass.Histo1D<float>({"Dimuon_mass", "Dimuon mass;m_{#mu#mu} (GeV);N_{Events}", bins, low, up}, "Dimuon_mass");

   // Produce the plot
   TCanvas c;
   c.SetLogx();
   c.SetLogy();

   hist->SetTitle("");
   hist->GetXaxis()->SetTitleSize(0.04);
   hist->GetYaxis()->SetTitleSize(0.04);
   hist->Draw();

   c.SaveAs("dimuon_spectrum.png");
}
