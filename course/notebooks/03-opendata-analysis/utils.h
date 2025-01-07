#ifndef HIGGSTOFOURLEPTONS_UTILS
#define HIGGSTOFOURLEPTONS_UTILS

#include <ROOT/RDF/RSampleInfo.hxx>
#include <ROOT/RVec.hxx>
#include <TGraph.h>

float scale(unsigned int slot, const ROOT::RDF::RSampleInfo &id)
{
    return id.Contains("mc_363490.llll.4lep.root") ? 1.3f : 1.0f;
}

bool GoodElectronsAndMuons(const ROOT::RVecI &type, const ROOT::RVecF &pt, const ROOT::RVecF &eta, const ROOT::RVecF &phi, const ROOT::RVecF &e, const ROOT::RVecF &trackd0pv, const ROOT::RVecF &tracksigd0pv, const ROOT::RVecF &z0)
{
    for (size_t i = 0; i < type.size(); i++)
    {
        ROOT::Math::PtEtaPhiEVector p(0.001 * pt[i], eta[i], phi[i], 0.001 * e[i]);
        if (type[i] == 11)
        {
            if (pt[i] < 7000 || abs(eta[i]) > 2.47 || abs(trackd0pv[i] / tracksigd0pv[i]) > 5 || abs(z0[i] * sin(p.Theta())) > 0.5)
                return false;
        }
        else
        {
            if (abs(trackd0pv[i] / tracksigd0pv[i]) > 5 || abs(z0[i] * sin(p.Theta())) > 0.5)
                return false;
        }
    }
    return true;
}

double weights(float scaleFactor_1, float scaleFactor_2, float scaleFactor_3, float scaleFactor_4, float scale, float mcWeight, double xsecs, double sumws, double lumi)
{
    return scaleFactor_1 * scaleFactor_2 * scaleFactor_3 * scaleFactor_4 * scale * mcWeight * xsecs / sumws * lumi;
}

float ComputeInvariantMass(const ROOT::RVecF &pt, const ROOT::RVecF &eta, const ROOT::RVecF &phi, const ROOT::RVecF &e)
{
    ROOT::Math::PtEtaPhiEVector p1{pt[0], eta[0], phi[0], e[0]};
    ROOT::Math::PtEtaPhiEVector p2{pt[1], eta[1], phi[1], e[1]};
    ROOT::Math::PtEtaPhiEVector p3{pt[2], eta[2], phi[2], e[2]};
    ROOT::Math::PtEtaPhiEVector p4{pt[3], eta[3], phi[3], e[3]};
    return 0.001 * (p1 + p2 + p3 + p4).M();
}

class VaryHelper
{
    const std::vector<double> x{5.50e3, 5.52e3, 12.54e3, 17.43e3, 22.40e3, 27.48e3, 30e3, 10000e3};
    const std::vector<double> y{0.06628, 0.06395, 0.06396, 0.03372, 0.02441, 0.01403, 0, 0};
    TGraph graph;

public:
    VaryHelper() : graph(x.size(), x.data(), y.data()) {}
    ROOT::RVecD operator()(double w, const ROOT::RVecF &pt, const ROOT::RVec<unsigned int> &type)
    {
        const auto v = Mean(Map(pt[type == 11], [this](auto p)
                                { return this->graph.Eval(p); }));
        return ROOT::RVecD{(1 + v) * w, (1 - v) * w};
    }
};

#endif // HIGGSTOFOURLEPTONS_UTILS