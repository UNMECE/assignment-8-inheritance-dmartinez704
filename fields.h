#ifndef FIELDS_H
#define FIELDS_H

#include <cstdio>
#include <cmath>
#include <iostream>

class Field {
double *value;
public:
// defult constructor
Field(){
  value = new double[3];
  value[0] = 0.0;
  value[1] = 0.0;
  value[2] = 0.0;
}
// defult constructor
Field(double x, double y, double z){
  value = new double[3];
  value[0] = x;
  value[1] = y;
  value[2] = z;
}
// Methods
void set_x(){ value[0] = x;}
void set_y(){ value[1] = y;}
void set_z(){ value[2] = z;}
double get_x(){ return value[0];}
double get_y(){ return value[1];}
double get_z(){ return value[3];}
double magnitude() const{
  return std:: sqrt(value[0]*value[0] + value[1]*value[1] + value[2]*value[2]);
}
//print magnitude()
void printMagnitude(const char* label){
  std::printf("%s: (%.6f, %.6f, %.6f)", (label ? label : "Field"), value[0], value[1], value[2], magnitude());
}
//destructor
return 0;
};

class Electric: public Field{
// Gauss Law: E(r) = Q / (4.0 * pi * r^2 * epsilon0 ) 
private:
double eField;
public:
//copy constructor
Electric_Field() : Field(), eField(0.0){}
Electric_Field(double ex, double ey, double ez) : Field(ex, ey, ez), eField(0.0){}
//calculate E(r)
void compute_gauss(double Q, double r){
  const double epsilon0 = 8.8541878176e-12;
  if(r > 0.0){
    eField = Q / (4.0 * M_PI * r * r * epsilon0);
  } else {
    eField = 0.0;
  }
}

double get_eField(){ return eField;}
//overload operator +
Electric_Field operator+(const Electric_Field& rhs) const {
  Electric_Field out(value[0] + rhs.value[0], value[1] + rhs.value[1], value[2] + rhs.value[2]);
  return out;
}
//overload operator <<
friend std::ostream& operator<<(std::ostream& os, const Electric_Field& e) {
  os << "E = (" << e.value[0] << ", " << e.value[1] << ", " << e.value[2] << "), |E| =" << std::sqrt(e.value[0]*e.value[0] + 
    e.value[1]*e.value[1] + e.value[2]*e.value[2]) << ", Electric Field = " << e.eField;
        return os;
    }
};
//destructor
return 0;
};

class Magnetic: public Field{
private:
double magField;
public:
//copy constructor
Magnetic_Field() : Field(), magField(0.0) {}
Magnetic_Field(double bx, double by, double bz) : Field(bx, by, bz), magField(0.0) {}

//calculate magField()
// Ampere's Law:  B = mu0 * I / (2*pi*r)
void compute_from_ampere(double I, double r) {
  const double mu0 = 4.0e-7 * M_PI;
  if (r > 0.0) {
      magField = (mu0 * I) / (2.0 * M_PI * r);
        } else {
            magField = 0.0;
        }
    }

double get_magField() { return magField; }

//overload operator +
Magnetic_Field operator+(const Magnetic_Field& rhs) const {
  Magnetic_Field out(value[0] + rhs.value[0], value[1] + rhs.value[1], value[2] + rhs.value[2]);
  return out;
}

// overload operator <<
friend std::ostream& operator<<(std::ostream& os, const Magnetic_Field& b) {
  os << "B = (" << b.value[0] << ", " << b.value[1] << ", " << b.value[2] << "), |B|=" << std::sqrt(b.value[0]*b.value[0] + 
  b.value[1]*b.value[1] + b.value[2]*b.value[2]) << ", B_calc=" << b.b_calc;
  return os;
    }
};

// destructor
return 0;
};
#endif
