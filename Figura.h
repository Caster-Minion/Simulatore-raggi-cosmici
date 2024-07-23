#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TPolyLine.h"
using namespace std;

class Figura
{
public:
  Figura() {
    cout << "Costruttore figura"<< endl;
  }
  
  virtual ~Figura()
{
  cout << "Distruttore figura" << endl;
}

  virtual void Disegna() const = 0;
  virtual float Area() const = 0;


};
#endif
