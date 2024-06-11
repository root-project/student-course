/*
Simple tutorial showing distribution of the sum of px and py observables of a dataset.
*/
#include <string>

#include <TCanvas.h>
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RLogger.hxx>

int main()
{
   // Create an RDataFrame to process the dataset
   const std::string dataset_name{"ntuple"};
   const std::string file_path{"https://root.cern/files/tutorials/hsimple.root"};
   ROOT::RDataFrame df{dataset_name, file_path};

   // Define the steps to produce the histogram of the distribution
   auto h = df.Filter([](float pz) { return std::abs(pz) < 2; }, {"pz"})
               .Define("pxpy", [](float px, float py) { return px + py; }, {"px", "py"})
               .Histo1D<float>({"xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10}, "pxpy");

   // Produce the plot
   TCanvas c;
   h->Draw();
   c.SaveAs("hsimple.png");
}
