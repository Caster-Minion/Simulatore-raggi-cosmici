#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include <iostream>
#include "Figura.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TPolyLine.h"
using namespace std;

class Triangolo : public Figura
{
 public:
  Triangolo(TCanvas*);
  ~Triangolo();
  virtual float Area() const;
  virtual void Disegna() const;
 private:
  float base, altezza;
  TCanvas* r;
};
#endif
