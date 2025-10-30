#include "fields.h"

int main() {
    // Construct
    Electric_Field E0;                    // defaults to (0,0,0)
    Electric_Field E1(1e5, 10.9, 1.7e2);  // calls base Field(x,y,z)

    Magnetic_Field M0;                    // defaults to (0,0,0)
    Magnetic_Field M1(0.0, 5.0, 12.0);    // calls base Field(x,y,z)

    // Print components + magnitude
    E0.printMagnitude("E0");
    E1.printMagnitude("E1");
    M0.printMagnitude("M0");
    M1.printMagnitude("M1");

    // Compute class-specific const's
    double Q  = 2.5e-6;
    double rE = 0.15;
    E1.compute_gauss(Q, r);
    std::printf("Electrical Field at r = %.3f m, Q = %.3e C: %.6e (N/C)\n",
                rE, Q, E1.get_eField());

    double I  = 7.2; 
    double rM = 0.08; 
    B1.getAmp(I, rM);
    std::printf("Magnetic Field at r = %.3f m, I = %.3e A: %.6e (T)\n",
                rM, I, B1.get_magField());

    // Operator+ usage
    Electric_Field E2(100.0, 200.0, 300.0);
    Electric_Field E3(1.0, 2.0, 3.0);
    Electric_Field E_sum = E2 + E3; 
    std::cout << "E2 + E3 => " << E_sum << std::endl;

    Magnetic_Field B2(0.5, 0.5, 0.0);
    Magnetic_Field B3(0.1, 0.2, 0.3);
    Magnetic_Field B_sum = B2 + B3; 
    std::cout << "B2 + B3 => " << B_sum << std::endl;

    // << usage
    std::cout << "E1: " << E1 << std::endl;
    std::cout << "B1: " << B1 << std::endl;

    return 0;
}
