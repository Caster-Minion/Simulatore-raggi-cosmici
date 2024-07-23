#ifndef RILEVATORE_H
#define RILEVATORE_H
#include "Rettangolo.h"
#include "Cerchio.h"
#include "Triangolo.h"
#include "Figura.h"
#include <iostream>
#include <iostream>
#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TPolyLine.h"
using namespace std;

class Rilevatore
{
public:
  Rilevatore(TCanvas* c);

  ~Rilevatore();
  
  void questions();
  void distribuzioneNP();
  void distribuzioneT();
  

private:
  TCanvas* r;
  int fig;
  int figura;//0 rettangolo, 1 triangolo, 2 cerchio
  Figura* Pt;
  float Ar;
  float integ, runtime;
  vector<int> vec_i;
  vector<float> vec_f;
  int NP_tot=0; //Numero totale di particelle nel run time
  vector<float> vec_T;
};

#endif

