#include "Cerchio.h"
#include "Figura.h"
#include <iostream>
#include <iostream>
#include "TH1F.h"
#include <TEllipse.h>
#include "TCanvas.h"
#include "TRandom3.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TPolyLine.h"
#include <cmath>
using namespace std;

Cerchio::Cerchio(TCanvas* c) : Figura(){//chiamata al costruttore di figura
  r=c;
  cout << "Costruisco un cerchio" << endl;
  cout << "Inserisci raggio: ";
  cin >> raggio;
}

Cerchio::~Cerchio()
{cout << "Distruggo un cerchio" << endl;}


void Cerchio::Disegna() const
{
  TEllipse* ell = new TEllipse(0.3,0.5,0.2,0.4);
  ell->SetLineColor(kRed);
  ell->SetFillColor(kWhite);
  ell->SetLineWidth(4);
  r->Divide(2,2);
  r->cd(1);
  ell->Draw("");
  ell->Draw("f");
  
}

float Cerchio::Area() const
{
  return raggio*raggio*M_PI;
}
