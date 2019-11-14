
#include "Riostream.h"
void pfiles(const char *letters,const int number) {

   gROOT->Reset();

   ifstream in;
   in.open(letters);
   TTree *tree = new TTree("T","data from scintillator");
   
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

   auto f = TFile::Open("Hexagon.root","RECREATE");

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
   f.Close();
   //exit (0);
}
