#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include <iostream>
#include "Figura.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TPolyLine.h"
using namespace std;

class Rettangolo : public Figura
{
 public:
  Rettangolo(TCanvas* c);
  ~Rettangolo();
  virtual float Area() const;
  virtual void Disegna() const;
 private:
  float lato_a, lato_b;
  TCanvas* r;
};
#endif
