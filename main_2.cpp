#include "Rilevatore.h"
#include "Rettangolo.h"
#include "Cerchio.h"
#include "Triangolo.h"
#include <iostream>
#include <iostream>
#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TPolyLine.h"
using namespace std;


int main(int argc, char* argv[]){
  
  TApplication app("app", &argc, argv);

  TCanvas* c = new TCanvas("canvas", "Forma Rilevatore e distribuzione", 0, 0, 1600, 1200);

  
  Rilevatore rl(c);
  rl.questions();

  rl.distribuzioneNP();

  rl.distribuzioneT();


  
   c->Modified(); c->Update();
   TRootCanvas *rc = (TRootCanvas *) c->GetCanvasImp();
   rc->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

   app.Run();

  
   return 0;
}
