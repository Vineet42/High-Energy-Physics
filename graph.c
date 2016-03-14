void graph() {

   TCanvas *c1 = new TCanvas("c1","Rate of Events vs. E",200,10,700,500);

   c1->SetFillColor(42);
   c1->SetGrid();

   const Int_t n = 10;
   Double_t x[n], y[n];
   Double_t width = 2.5;
   Double_t E = 91.2;
   Double_t M = 91.2;
   
   for (Int_t i=0;i<n/2;i++) {
     x[i] = E - (4-i)*width;
     y[i] = 1/((x[i] - M)^2)+(width/2));
     }
     
   for (Int_t i=n/2;i<n;i++) {
     x[i] = E + (i-4)*width;
     y[i] = 1/((x[i] - M)^2)+(width/2));
     }
     
   TGraph *gr = new TGraph(n,x,y);
   gr->SetLineColor(2);
   gr->SetLineWidth(4);
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->SetTitle("Briet-Wigner Distribution");
   gr->Draw("ACP");
}

