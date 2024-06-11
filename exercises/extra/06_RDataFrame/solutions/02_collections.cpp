/*
C++ solution for the 02_collections exercise, using fully-compiled RDataFrame execution.
*/
#include <string>

#include <TCanvas.h>
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RLogger.hxx>
#include <ROOT/RVec.hxx>

int main()
{
    // Create an RDataFrame to process the dataset
    const std::string dataset_name{"dataset"};
    const std::string file_path{"../data/example_file.root"};
    ROOT::RDataFrame df{dataset_name, file_path};

    // Select the elements of `vec1` for which the square of the corresponding elements in `vec2` is less than 0.1
    // Create the histogram of the new column
    auto h = df.Define("v1_to_plot", [](const ROOT::RVecF &v1, const ROOT::RVecF &v2)
                       { return v1[v2 * v2 < 0.1]; },
                       {"vec1", "vec2"})
                 .Histo1D<ROOT::RVecF>("v1_to_plot");

    // Produce the plot
    TCanvas c;
    h->Draw();
    c.SaveAs("02_collections.png");
}
