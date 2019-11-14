
#include "Riostream.h"
void pfiles(const char *letters,const int number) {

   gROOT->Reset();
   struct datasc_t {
      Int_t id;
      Int_t Energy;
      Float_t id2;
      Float_t px;
      Float_t py;
      Float_t pz;
      Float_t pt;
   };
   datasc_t datasc;



   ifstream in;
   //in.open("/Users/emoreno/Desktop/fast/data/fastC2pasameanpri00006.txt");
   in.open(letters);
   //TCanvas* c1=new TCanvas("c1", "Signals", 600, 900);
   TTree *tree = new TTree("T","data from scintillator");
   // create one branch with all information from the stucture
   //tree->Branch("datasc",&datasc.id,"id/I:Energy:id2:px:py:pz:pt");
   Int_t id;
   Float_t px,py,pz,penergia,pt,plamda;


   tree->Branch("id",&id,"id/I");
   tree->Branch("px",&px,"px/F");
   tree->Branch("py",&py,"py/F");
   tree->Branch("pz",&pz,"pz/F");
   tree->Branch("penergia",&penergia,"penergia/F");
   tree->Branch("plamda",&plamda,"plamda/F");
   tree->Branch("pt",&pt,"pt/F");

   Int_t idd;
   Float_t pxx,pyy,pzz,penergia2,ptt,plamda2;

   auto f = TFile::Open("Hex.root","RECREATE");
//processing file of data
   while (!in.eof()) {
      in >> idd >> pxx >> pyy >> pzz >> penergia2 >> plamda2 >> ptt;
      if (!in.good()) break;
      id=idd;
      px=pxx;
      py=pyy;
      pz=pzz;
      penergia=penergia2;
      plamda=plamda2;
      pt=ptt;
      tree->Fill();
      //cout << ptt<< endl;
      //cout << idd << "->" << ene << " "<<idd2<<" " <<pxx <<" " <<pyy<<" "<< pzz << " "<<ptt<<endl;
   }
   //gSystem->Sleep( 10000 );
   tree->Print();
   tree->Write();
   //exit (0);
}
