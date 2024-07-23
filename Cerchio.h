#ifndef CERCHIO_H
#define CERCHIO_H
#include <iostream>
#include "Figura.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TPolyLine.h"
using namespace std;

class Cerchio : public Figura
{
 public:
  Cerchio(TCanvas*);
  ~Cerchio();
  virtual float Area() const;
  virtual void Disegna() const;
 private:
  float raggio;
  TCanvas* r;
};
#endif
