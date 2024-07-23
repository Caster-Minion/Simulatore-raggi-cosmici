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

Triangolo::Triangolo(TCanvas* c) : Figura(){//chiamata al costruttore di figura
  r=c;
  cout << "Costruisco un triangolo" << endl;
  cout << "Inserisci base: ";
  cin >> base;
  cout << "Inserisci altezza: ";
  cin >> altezza;
}

Triangolo::~Triangolo()
{cout << "Distruggo un triangolo" << endl;}


void Triangolo::Disegna() const
{
  const int nPt= 4;
  Double_t x[nPt]= {0.1,0.7,0.4,0.1};
  Double_t y[nPt]= {0.2,0.2,0.8,0.2};
  TPolyLine *pline = new TPolyLine(nPt, x, y);
  pline->SetFillColor(kWhite);
  pline->SetLineColor(kRed);
  pline->SetLineWidth(4);
  r->Divide(2,2);
  r->cd(1);
  pline->Draw("f");
  pline->Draw("");
}

float Triangolo::Area() const
{
  return base*altezza/2;
}
