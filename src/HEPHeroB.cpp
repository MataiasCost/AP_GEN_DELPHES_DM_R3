#include "HEPHero.h"


//---------------------------------------------------------------------------------------------
// FILL CONTROL VARIABLES WITH INPUT FILE LINES
//---------------------------------------------------------------------------------------------
void HEPHero::FillControlVariables( string key, string value){

    //----CORRECTIONS------------------------------------------------------------------------------------


    //----METADATA FILES---------------------------------------------------------------------------------


    //----SELECTION--------------------------------------------------------------------------------------


}


//---------------------------------------------------------------------------------------------
// Init
//---------------------------------------------------------------------------------------------
bool HEPHero::Init() {
    
    //======SET HISTOGRAMS STYLE===================================================================
    setStyle(1.0,true,0.15);

    if( _ANALYSIS != "GEN" ){
        //======SET THE BRANCH ADDRESSES===============================================================
       // _inputTree->SetBranchAddress("run", &run);
       // _inputTree->SetBranchAddress("luminosityBlock", &luminosityBlock);
       // _inputTree->SetBranchAddress("event", &event);
       // _inputTree->SetBranchAddress("bunchCrossing", &bunchCrossing);
        
        _inputTree->SetBranchAddress("GenJet.PT", &GenJet_PT);
        _inputTree->SetBranchAddress("GenJet_size",&GenJet_size);
        _inputTree->SetBranchAddress("GenJet.BTag",&GenJet_BTag);
        
        _inputTree->SetBranchAddress("Jet.PT", &Jet_PT);
        _inputTree->SetBranchAddress("Jet.Eta", &Jet_Eta);
        _inputTree->SetBranchAddress("Jet.Phi", &Jet_Phi);
        _inputTree->SetBranchAddress("Jet.BTag", &Jet_BTag);
        _inputTree->SetBranchAddress("Jet_size", &Jet_size);

        _inputTree->SetBranchAddress("FatJet.PT", &FatJet_PT);
        _inputTree->SetBranchAddress("FatJet.Eta", &FatJet_Eta);
        _inputTree->SetBranchAddress("FatJet.Phi", &FatJet_Phi);
        _inputTree->SetBranchAddress("FatJet.Mass", &FatJet_Mass);
        _inputTree->SetBranchAddress("FatJet.BTag", &FatJet_BTag);
        _inputTree->SetBranchAddress("FatJet_size", &FatJet_size);

        _inputTree->SetBranchAddress("MissingET.MET", &MissingET_MET);
        _inputTree->SetBranchAddress("MissingET.Phi", &MissingET_Phi);

        _inputTree->SetBranchAddress("ScalarHT.HT", &ScalarHT_HT);

        
        //-----------------------------------------------------------------------------------------------------
        if( dataset_group != "Data" ) {
/*
            _inputTree->SetBranchAddress("nGenJetAK8", &nGenJetAK8);
            _inputTree->SetBranchAddress("GenJetAK8_eta", &GenJetAK8_eta);
            _inputTree->SetBranchAddress("GenJetAK8_mass", &GenJetAK8_mass);
            _inputTree->SetBranchAddress("GenJetAK8_phi", &GenJetAK8_phi);
            _inputTree->SetBranchAddress("GenJetAK8_pt", &GenJetAK8_pt);

            _inputTree->SetBranchAddress("nGenJet", &nGenJet);
            _inputTree->SetBranchAddress("GenJet_eta", &GenJet_eta);
            _inputTree->SetBranchAddress("GenJet_mass", &GenJet_mass);
            _inputTree->SetBranchAddress("GenJet_phi", &GenJet_phi);
            _inputTree->SetBranchAddress("GenJet_pt", &GenJet_pt);

            _inputTree->SetBranchAddress("nGenPart", &nGenPart);
            _inputTree->SetBranchAddress("GenPart_genPartIdxMother", &GenPart_genPartIdxMother);
            _inputTree->SetBranchAddress("GenPart_statusFlags", &GenPart_statusFlags);
            _inputTree->SetBranchAddress("GenPart_pdgId", &GenPart_pdgId);
            _inputTree->SetBranchAddress("GenPart_status", &GenPart_status);
            _inputTree->SetBranchAddress("GenPart_eta", &GenPart_eta);
            _inputTree->SetBranchAddress("GenPart_mass", &GenPart_mass);
            _inputTree->SetBranchAddress("GenPart_phi", &GenPart_phi);
            _inputTree->SetBranchAddress("GenPart_pt", &GenPart_pt);

            _inputTree->SetBranchAddress("nSubGenJetAK8", &nSubGenJetAK8);
            _inputTree->SetBranchAddress("SubGenJetAK8_eta", &SubGenJetAK8_eta);
            _inputTree->SetBranchAddress("SubGenJetAK8_mass", &SubGenJetAK8_mass);
            _inputTree->SetBranchAddress("SubGenJetAK8_phi", &SubGenJetAK8_phi);
            _inputTree->SetBranchAddress("SubGenJetAK8_pt", &SubGenJetAK8_pt);

            _inputTree->SetBranchAddress("genWeight", &genWeight);
            _inputTree->SetBranchAddress("LHEWeight_originalXWGTUP", &LHEWeight_originalXWGTUP);
            _inputTree->SetBranchAddress("nLHEPdfWeight", &nLHEPdfWeight);
            _inputTree->SetBranchAddress("LHEPdfWeight", &LHEPdfWeight);
            _inputTree->SetBranchAddress("nLHEReweightingWeight", &nLHEReweightingWeight);
            _inputTree->SetBranchAddress("LHEReweightingWeight", &LHEReweightingWeight);
            _inputTree->SetBranchAddress("nLHEScaleWeight", &nLHEScaleWeight);
            _inputTree->SetBranchAddress("LHEScaleWeight", &LHEScaleWeight);
            _inputTree->SetBranchAddress("nPSWeight", &nPSWeight);
            _inputTree->SetBranchAddress("PSWeight", &PSWeight);
            
*/
        }

    }

    return true;
}


//---------------------------------------------------------------------------------------------
// ANAFILES' ROUTINES
//---------------------------------------------------------------------------------------------
void HEPHero::SetupAna(){
    if( false );
    else if( _SELECTION == "Test" ) SetupTest();
    // SETUP YOUR SELECTION HERE
    else {
      cout << "Unknown selection requested. Exiting. " << endl;
      return;
    }
}

bool HEPHero::AnaRegion(){
    bool Selected = true;
    if( _SELECTION == "Test" && !TestRegion() ) Selected = false;
    // SET THE REGION OF YOUR SELECTION HERE

    return Selected;
}

void HEPHero::AnaSelection(){
    if( _SELECTION == "Test" ) TestSelection();
    // CALL YOUR SELECTION HERE
}

void HEPHero::AnaSystematic(){
    if( _SELECTION == "Test" ) TestSystematic();
    // PRODUCE THE SYSTEMATIC OF YOUR SELECTION HERE
}

void HEPHero::FinishAna(){
    if( _SELECTION == "Test" ) FinishTest();
    // FINISH YOUR SELECTION HERE
}
   




