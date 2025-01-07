// Remember to always write header guards to avoid redefinition
#ifndef DIMUON_UTILITY_HEADER
#define DIMUON_UTILITY_HEADER
#include "ROOT/RVec.hxx"

// Notice we use a const reference to the vector type to avoid one extra copy
// per each vector per each event
using CVecF = const ROOT::RVecF &;

float custom_InvariantMass(CVecF pt, CVecF eta, CVecF phi, CVecF mass)
{

   auto size = pt.size();

   R__ASSERT(eta.size() == size && phi.size() == size && mass.size() == size);

   float x_sum = 0.;
   float y_sum = 0.;
   float z_sum = 0.;
   float e_sum = 0.;

   for (decltype(size) i{}; i < size; ++i)
   {
      // Convert to (e, x, y, z) coordinate system and update sums
      const auto x = pt[i] * std::cos(phi[i]);
      x_sum += x;
      const auto y = pt[i] * std::sin(phi[i]);
      y_sum += y;
      const auto z = pt[i] * std::sinh(eta[i]);
      z_sum += z;
      const auto e = std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(mass[i], 2));
      e_sum += e;
   }

   // Return invariant mass with (+, -, -, -) metric
   return std::sqrt(std::pow(e_sum, 2) - std::pow(x_sum, 2) - std::pow(y_sum, 2) - std::pow(z_sum, 2));
}

#endif // DIMUON_UTILITY_HEADER