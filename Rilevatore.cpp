#include "Rettangolo.h"
#include "Rilevatore.h"
#include "Cerchio.h"
#include "Triangolo.h"
#include <iostream>
#include <random>
#include <cmath>
#include "TF1.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TPolyLine.h"
#include "TText.h"
#include <cstdio>
using namespace std;


Rilevatore::Rilevatore(TCanvas* c){r=c;}
Rilevatore::~Rilevatore(){}
void Rilevatore::questions()
  { 
    cout << "Intervallo di integrazione (in minuti): ";
    cin >> integ;
    cout << "Tempo totale di acquisizione (in minuti): ";
    cin >> runtime;
    runtime= runtime;
    cout << "Forma del rilevatore (possibilita: Rettangolo=0, Triangolo=1, Cerchio=2): ";
    cin >> fig;
  
    if (fig==0)
      Pt = new Rettangolo(r);
    if (fig==1)
       Pt = new Triangolo(r);
     if (fig==2)
     Pt = new Cerchio(r);
     Pt->Disegna();
     Ar= Pt->Area();//prende l'area e la mette dentro Ar
     }

void Rilevatore::distribuzioneNP()
{
  static random_device rd;
  static mt19937 gen(rd());


  poisson_distribution<int> pd(Ar*integ); // il numero che va dentro pd () arebbe il prodotto del valore atteso di particelle per unita di tempo per cm^2 moltiplicato per la superfie e per il tempo di integrazione esempio: (1 particella cm^2 / minuti) * area rilevatopre in cm^2 * il tempo di integrazione in minuti

  for (int i = 0; i < runtime/integ; ++i)
    {
      vec_i.push_back(pd(gen));
    }

  r->cd(2);

  TH1F* h = new TH1F("h", "Grafico del numero di particelle", Ar*1*integ*2, 0, Ar*1*integ*2);

  for (int i = 0; i < runtime/integ ; ++i)
    {
      h->Fill(vec_i[i]);
    }
  h->Draw();

  double funLimit[2] = {0, Ar*1*integ*2};

    // Crea la funzione di Poisson
    TF1* fPoissonByHand = new TF1("fPoisson", "[0]*TMath::Poisson(x, [1])", funLimit[0], funLimit[1]);

    // Imposta i valori iniziali dei parametri [0], [1]
    fPoissonByHand->SetParameter(0, 1); // Normalizzazione (amplitudine)
    fPoissonByHand->SetParameter(1, Ar*integ); // Media (lambda) della distribuzione di Poisson 
    h->Fit( fPoissonByHand,"","R",0,Ar*integ*2);

    r->cd(4);
        TText *text = new TText(0.05, 0.9, "Parametri fit poissoniana:");
        text->SetTextAlign(11);  // Allinea il testo a sinistra
        text->SetTextSize(0.08);  // Imposta la dimensione del testo
        text->Draw();
	TText *text2 = new TText(0.05, 0.75, "Normalizzazione = 1");
        text2->SetTextAlign(11); 
        text2->SetTextSize(0.06);  // Imposta la dimensione del testo
        text2->Draw();
	TText *text4 = new TText(0.05, 0.65, Form("Lamda = %.2f",Ar*integ));
        text4->SetTextAlign(11);
        text4->SetTextSize(0.06);  // Imposta la dimensione del testo
        text4->Draw();

	TText *text5 = new TText(0.05, 0.45, "Parametri fit esponenziale:");
        text5->SetTextAlign(11);
        text5->SetTextSize(0.08);  // Imposta la dimensione del testo
        text5->Draw();
	TText *text6 = new TText(0.05, 0.3, "Normalizzazione = 1");
        text6->SetTextAlign(11); 
        text6->SetTextSize(0.06);  // Imposta la dimensione del testo
        text6->Draw();
        TText *text7 = new TText(0.05, 0.2, Form("Lamda = %.2f",Ar));
        text7->SetTextAlign(11);
        text7->SetTextSize(0.06);  // Imposta la dimensione del testo
        text7->Draw();
	r->Update();
}

void Rilevatore::distribuzioneT()
{
   random_device rand_dev;
   mt19937 generator(rand_dev());
   uniform_real_distribution<float> distr(0, runtime);
   for (int i=0; i< runtime/integ; i++)
      {
	NP_tot = NP_tot + vec_i[i];
      }

   for (int i = 0; i < NP_tot; ++i)
     {
        vec_f.push_back(distr(generator));
     }

    float j;
    for (int i=0; i< NP_tot-1; i++)
    {
      for (int k=i+1; k < NP_tot; k++)
         {
           if (vec_f[i]>vec_f[k]){
	     j=vec_f[k];
	     vec_f[k]=vec_f[i];
	     vec_f[i] = j;
            }
        }
    }

    for (int i=0; i < NP_tot-1; i++)
      {
	vec_T.push_back(vec_f[i+1]-vec_f[i]);
      }

    r->cd(3);

    TH1F* h2 = new TH1F("h", "Grafico della distribuzione dei tempi di arrivo", sqrt(NP_tot-1)/3, 0, 1/Ar*3);

    for (int i = 0; i < NP_tot-1 ; ++i){
    h2->Fill(vec_T[i]);
}

    h2->Draw();
    // Definisce i limiti del dominio della funzione
    double funLimit2[2] = {0, 1/Ar*3};

    // Crea la funzione esponenziale
    TF1* fExponentialByHand = new TF1("fExponential", "[0]*[1]*exp(-[1]*x)", funLimit2[0], funLimit2[1]);

    // Imposta i valori iniziali dei parametri [0], [1]
    fExponentialByHand->SetParameter(0, 1); // Normalizzazione (amplitudine)
    fExponentialByHand->SetParameter(1, Ar); // Parametro lambda della distribuzione esponenziale
    h2->Fit( fExponentialByHand,"","R",0, 1/Ar*3);
}
 



