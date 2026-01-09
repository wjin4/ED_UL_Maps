string source="IC171106A";

char * getFilename(string pwd, string source, string basename, string filetype = "png") {
  string filename = pwd + basename + "_" + source + "." + filetype;
  return filename.c_str();
}
//light curve
double alpha= -2.5;
double iMinEnergy_TeV=0.3;
double E0=1;
double iMaxEnergy_TeV=30; 
double iThresholdSignificance=20;
double iMinEvents=3;
double iUpperLimit=0.95;
double iUpperlimitMethod=4;
double E_th=0.35; //TeV
double days_bin=1; 
double start_MJD=58069;
double stop_MJD=58078;

//spectrum
double E_bin=0.25; //bin per energy decade = 1/E_bin

void printresults(){

  gSystem->Load("$EVNDISPSYS/lib/libVAnaSum.so");

  // *** Input parameters ***
 for (int i = 1; i < 537; i++) 
{
  string  filename= source+"_para" + Form("%d",i)+".root";

  // Output folder where all the plots will be save
  string pwd = "./";


  // *** Light curve ***
  // Defining parameters for the light curve
  TCanvas * lcCanvas = new TCanvas("lc", "lc", 700, 350);
  VFluxCalculation b(filename.c_str());
  b.setSpectralParameters(iMinEnergy_TeV, E0, alpha, iMaxEnergy_TeV);
  b.setSignificanceParameters(iThresholdSignificance, iMinEvents, iUpperLimit, iUpperlimitMethod);//iLiMaEqu = 17
  b.calculateIntegralFlux(E_th); // energy threshold for integral flux calculation in TeV (0.3 TeV)
 // TGraphErrors * lc = b.plotFluxesVSMJD();
  //TGraphErrors * lc = b.plotFluxesInBINs();
  lcCanvas->cd();
//  lc->Draw("AP");
//  lcCanvas->Print(getFilename(pwd, source, "lc"));
//  lcCanvas->Print(getFilename(pwd, source, "lc", "png"));
  b.printResults();
  //b.printRunList();

  }
 }
