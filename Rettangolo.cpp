#include "Rettangolo.h"
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

Rettangolo::Rettangolo(TCanvas* c) : Figura(){//chiamata al costruttore di figura
  r=c;
  cout << "Costruisco un rettangolo" << endl;
  cout<<"inserisci lato 1"<<endl;
  cin>>lato_a;
  cout<<"inserisci lato 2"<<endl;
  cin>>lato_b;
}

Rettangolo::~Rettangolo()
{cout << "Distruggo un rettangolo" << endl;}


void Rettangolo::Disegna() const
{
  const int nPt= 5;
  Double_t x[nPt]= {0.1,0.7,0.7,0.1,0.1};
  Double_t y[nPt]= {0.2,0.2,0.8,0.8,0.2};
  TPolyLine *pline = new TPolyLine(nPt, x, y);
  pline->SetFillColor(kWhite);
  pline->SetLineColor(kRed);
  pline->SetLineWidth(4);
  r->Divide(2,2);
  r->cd(1);
  pline->Draw("f");
  pline->Draw("");
}

float Rettangolo::Area() const
{
  return lato_a*lato_b;
}
