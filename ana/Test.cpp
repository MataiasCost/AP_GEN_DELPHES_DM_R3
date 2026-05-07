#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Test{

    //int variable1Name;   [example]

    float leading_jet_pt,leading_jet_eta,leading_jet_phi;
    float leading_Fatjet_pt,leading_Fatjet_eta,leading_Fatjet_phi;

    float leading_bjet_pt,leading_bjet_eta,leading_bjet_phi;

    int N_bJets, N_fatJets, N_jets,GEN_N_bJets;
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupTest() {

    //======SETUP CUTFLOW==========================================================================
    //_cutFlow.insert(pair<string,double>("CutName", 0) );   [example]

    //======SETUP HISTOGRAMS=======================================================================
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &Test::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    HDF_insert("GenJet_PT", &GenJet_PT[0]);
    HDF_insert("GenJet_size",&GenJet_size);
    
    HDF_insert("GenJet_PT", &GenJet_PT[0]);
    HDF_insert("GenJet_size",&GenJet_size);
    
    HDF_insert("Jet_size",&Jet_size);
    HDF_insert("FatJet_Number",&FatJet_size);

    HDF_insert("MET_pt",&MissingET_MET[0]);
    HDF_insert("MET_phi",&MissingET_Phi[0]);

    HDF_insert("HT",&ScalarHT_HT[0]);

    HDF_insert("N_FatJets",&Test::N_fatJets);
    HDF_insert("Leading_FatJets_pt",&Test::leading_Fatjet_pt);
    HDF_insert("Leading_Fatjet_eta",&Test::leading_Fatjet_eta);
    HDF_insert("Leading_Fatjet_phi",&Test::leading_Fatjet_phi);

    HDF_insert("N_Jets",&Test::N_jets);
    HDF_insert("Leading_Jets_pt",&Test::leading_jet_pt);
    HDF_insert("Leading_jet_eta",&Test::leading_jet_eta);
    HDF_insert("Leading_jet_phi",&Test::leading_jet_phi);

    HDF_insert("N_bJets",&Test::N_bJets);
    HDF_insert("Leading_bJets_pt",&Test::leading_bjet_pt);
    HDF_insert("Leading_bjet_eta",&Test::leading_bjet_eta);
    HDF_insert("Leading_bjet_phi",&Test::leading_bjet_phi);
    

    
    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::TestRegion() {

    //-------------------------------------------------------------------------
    // Cut description
    //-------------------------------------------------------------------------
    //if( !(CutCondition) ) return false;           [Example]
    //_cutFlow.at("CutName") += evtWeight;          [Example]

    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::TestSelection() {

////////////////////
//    GEN LOOP
////////////////////



    

////////////////////
//    RECO LOOP - JETS e bJETS
////////////////////

    
    Test::N_bJets=0;
    Test::leading_bjet_pt=0;
    Test::leading_bjet_eta=0;
    Test::leading_bjet_phi=0;

    Test::N_jets=0;
    Test::leading_jet_pt=0;
    Test::leading_jet_eta=0;
    Test::leading_jet_phi=0;

    
    std::vector<int> nSelJet;
    std::vector<int> nSelbJet;

    nSelJet.clear();
    nSelbJet.clear();
    
    for(int ijet = 0; ijet < Jet_size; ++ijet){
        if(Jet_PT[ijet]<20){continue;}
        if(abs(Jet_Eta[ijet])>2.5){continue;}
            nSelJet.push_back(ijet);
        if (Jet_BTag[ijet]==1){
            nSelbJet.push_back(ijet);
        }
    }
    if (nSelJet.size()>0){
        Test::leading_jet_pt = Jet_PT[nSelJet.at(0)];
        Test::leading_jet_eta = Jet_Eta[nSelJet.at(0)];
        Test::leading_jet_phi = Jet_Phi[nSelJet.at(0)];
    }
    if (nSelbJet.size()>0){
        Test::leading_bjet_pt = Jet_PT[nSelbJet.at(0)];
        Test::leading_bjet_eta = Jet_Eta[nSelbJet.at(0)];
        Test::leading_bjet_phi = Jet_Phi[nSelbJet.at(0)];
    }

    Test::N_jets = nSelJet.size();
    Test::N_bJets = nSelbJet.size();

////////////////////
//    RECO LOOP - FAT JETS
////////////////////

    


    Test::N_fatJets=0;
    Test::leading_Fatjet_pt=0;
    Test::leading_Fatjet_eta=0;
    Test::leading_Fatjet_phi=0;
    
    std::vector<int> nSelfatJet;
   

    nSelfatJet.clear();
    
    for(int ijet = 0; ijet < FatJet_size; ++ijet){
        if(FatJet_PT[ijet]<170){continue;}
        if(abs(FatJet_Eta[ijet])>2.5){continue;}
        nSelfatJet.push_back(ijet);
    
    }
    if (nSelfatJet.size()>0){
        Test::leading_Fatjet_pt = FatJet_PT[nSelfatJet.at(0)];
        Test::leading_Fatjet_eta = FatJet_Eta[nSelfatJet.at(0)];
        Test::leading_Fatjet_phi = FatJet_Phi[nSelfatJet.at(0)];
    }
   

    Test::N_fatJets = nSelfatJet.size();

    



    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //Test::variable1Name = 100;      [Example]

    //======FILL THE HISTOGRAMS====================================================================
    //_histograms1D.at("histogram1DName").Fill( var, evtWeight );               [Example]
    //_histograms2D.at("histogram2DName").Fill( var1, var2, evtWeight );        [Example]

    //======FILL THE OUTPUT TREE===================================================================
    //_outputTree->Fill();

    //======FILL THE OUTPUT HDF5 INFO===============================================================
    HDF_fill();

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::TestSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishTest() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
