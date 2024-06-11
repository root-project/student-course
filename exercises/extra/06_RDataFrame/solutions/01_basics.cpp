/*
C++ solution for the 01_basics exercise, using fully-compiled RDataFrame execution.
*/
#include <cmath>
#include <string>

#include <TCanvas.h>
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RLogger.hxx>

int main()
{
    // Create an RDataFrame to process the dataset
    const std::string dataset_name{"dataset"};
    const std::string file_path{"../data/example_file.root"};
    ROOT::RDataFrame df{dataset_name, file_path};

    // Select the events where column `b` values are less than 0.5
    // Define a new column with the natural logarithm of values from column `a`
    // Create the histogram of the new column
    auto h = df.Filter([](double b){ return b <= 0.5;}, {"b"})
               .Define("loga", [](double a) { return std::log(a); }, {"a"})
               .Histo1D<double>({"h","A beautiful histo", 30, -5, 5}, "loga");

    // Produce the plot
    TCanvas c;
    h->Draw();
    c.SaveAs("01_basics.png");
}
