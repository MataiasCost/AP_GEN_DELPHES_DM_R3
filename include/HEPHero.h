#ifndef HEPHERO_H
#define HEPHERO_H

#include "HEPBase.h"
#include "CMS.h"
#include "ML.h"



using namespace std;

class HEPHero : public HEPBase {
    public:
        static HEPHero* GetInstance( char* configFileName );
        ~HEPHero() {}
        
        bool Init();
        void RunEventLoop( int nEventsMax = -1);
        void FinishRun();
    
    private:
        static HEPHero* _instance;

        HEPHero() {}
        HEPHero( char* configFileName );

        bool RunRoutines();
        void PreRoutines();
        bool MC_processing();
        void Weight_corrections();
        void FillControlVariables( string key, string value);
        void VerticalSysSizes();
        void VerticalSys();
        void SetupAna();
        bool AnaRegion();
        void AnaSelection();
        void AnaSystematic();
        void FinishAna();


        void SetupTest();
        bool TestRegion();
        void TestSelection();
        void TestSystematic();
        void FinishTest();
        // INSERT YOUR SELECTION HERE



    //=============================================================================================
    // ANALYSIS SETUP
    //=============================================================================================

        //-------------------------------------------------------------------------------
        // Functions
        //-------------------------------------------------------------------------------

        //----ANALYSIS-----------------------------------------------


        //----EXPERIMENT---------------------------------------------


        //----WEIGHTS------------------------------------------------



        //-------------------------------------------------------------------------------
        // Variables
        //-------------------------------------------------------------------------------

        //----SELECTION----------------------------------------------


        //----TRIGGERS-----------------------------------------------


        //----JETS---------------------------------------------------


        //----LEPTONS------------------------------------------------


        //----MET----------------------------------------------------


        //----CONSTANTS----------------------------------------------


        //----VERTICAL SYSTEMATICS-----------------------------------



        //-------------------------------------------------------------------------------
        // Metadata
        //-------------------------------------------------------------------------------

        //----PILEUP---------------------------------------


        //----JERC---------------------------------------------------


        //----MET XY-------------------------------------------------


    
    //=============================================================================================
    // INPUT TREE SETUP - NANOAOD
    //=============================================================================================
    private:

        UInt_t run;
        UInt_t luminosityBlock;
        ULong64_t event;
        UInt_t bunchCrossing;

        Float_t         Event_Weight[100];   //[Event_]
/*
        Int_t           GenJet_;
        UInt_t          GenJet_fUniqueID[100];   //[GenJet_]
        UInt_t          GenJet_fBits[100];   //[GenJet_]
*/
        Float_t         GenJet_PT[100];   //[GenJet_]
        Float_t         GenJet_Eta[100];   //[GenJet_]
        Float_t         GenJet_Phi[100];   //[GenJet_]
        Float_t         GenJet_T[100];   //[GenJet_]
        Float_t         GenJet_Mass[100];   //[GenJet_]
/*
        Float_t         GenJet_DeltaEta[100];   //[GenJet_]
        Float_t         GenJet_DeltaPhi[100];   //[GenJet_]
        UInt_t          GenJet_Flavor[100];   //[GenJet_]
        UInt_t          GenJet_FlavorAlgo[100];   //[GenJet_]
        UInt_t          GenJet_FlavorPhys[100];   //[GenJet_]
        UInt_t          GenJet_TauFlavor[100];   //[GenJet_]
*/
        UInt_t          GenJet_BTag[100];   //[GenJet_]
        UInt_t          GenJet_BTagAlgo[100];   //[GenJet_]
        UInt_t          GenJet_BTagPhys[100];   //[GenJet_]
/*
        UInt_t          GenJet_TauTag[100];   //[GenJet_]
        Float_t         GenJet_TauWeight[100];   //[GenJet_]
        Int_t           GenJet_Charge[100];   //[GenJet_]
        Float_t         GenJet_EhadOverEem[100];   //[GenJet_]
        Int_t           GenJet_NCharged[100];   //[GenJet_]
        Int_t           GenJet_NNeutrals[100];   //[GenJet_]
        Float_t         GenJet_NeutralEnergyFraction[100];   //[GenJet_]
        Float_t         GenJet_ChargedEnergyFraction[100];   //[GenJet_]
        Float_t         GenJet_Beta[100];   //[GenJet_]
        Float_t         GenJet_BetaStar[100];   //[GenJet_]
        Float_t         GenJet_MeanSqDeltaR[100];   //[GenJet_]
        Float_t         GenJet_PTD[100];   //[GenJet_]
        Float_t         GenJet_FracPt[100][5];   //[GenJet_]
        Float_t         GenJet_Tau[100][5];   //[GenJet_]
        TLorentzVector  GenJet_SoftDroppedJet[100];
        TLorentzVector  GenJet_SoftDroppedSubJet1[100];
        TLorentzVector  GenJet_SoftDroppedSubJet2[100];
        TLorentzVector  GenJet_TrimmedP4[5][100];
        TLorentzVector  GenJet_PrunedP4[5][100];
        TLorentzVector  GenJet_SoftDroppedP4[5][100];
        Int_t           GenJet_NSubJetsTrimmed[100];   //[GenJet_]
        Int_t           GenJet_NSubJetsPruned[100];   //[GenJet_]
        Int_t           GenJet_NSubJetsSoftDropped[100];   //[GenJet_]
        Double_t        GenJet_ExclYmerge12[100];   //[GenJet_]
        Double_t        GenJet_ExclYmerge23[100];   //[GenJet_]
        Double_t        GenJet_ExclYmerge34[100];   //[GenJet_]
        Double_t        GenJet_ExclYmerge45[100];   //[GenJet_]
        Double_t        GenJet_ExclYmerge56[100];   //[GenJet_]
        TRefArray       GenJet_Constituents[100];
        TRefArray       GenJet_Particles[100];
        TLorentzVector  GenJet_Area[100];
*/
        Int_t           GenJet_size;
        Int_t           GenMissingET_;
//        UInt_t          GenMissingET_fUniqueID[100];   //[GenMissingET_]
//        UInt_t          GenMissingET_fBits[100];   //[GenMissingET_]
        Float_t         GenMissingET_MET[100];   //[GenMissingET_]
//        Float_t         GenMissingET_Eta[100];   //[GenMissingET_]
        Float_t         GenMissingET_Phi[100];   //[GenMissingET_]
        Int_t           GenMissingET_size;
        Int_t           Jet_;
//        UInt_t          Jet_fUniqueID[100];   //[Jet_]
//        UInt_t          Jet_fBits[100];   //[Jet_]
        Float_t         Jet_PT[100];   //[Jet_]
        Float_t         Jet_Eta[100];   //[Jet_]
        Float_t         Jet_Phi[100];   //[Jet_]
        Float_t         Jet_T[100];   //[Jet_]
        Float_t         Jet_Mass[100];   //[Jet_]
//        Float_t         Jet_DeltaEta[100];   //[Jet_]
//        Float_t         Jet_DeltaPhi[100];   //[Jet_]
        UInt_t          Jet_Flavor[100];   //[Jet_]
//        UInt_t          Jet_FlavorAlgo[100];   //[Jet_]
//        UInt_t          Jet_FlavorPhys[100];   //[Jet_]
//        UInt_t          Jet_TauFlavor[100];   //[Jet_]
        UInt_t          Jet_BTag[100];   //[Jet_]
//        UInt_t          Jet_BTagAlgo[100];   //[Jet_]
//        UInt_t          Jet_BTagPhys[100];   //[Jet_]
/*
        UInt_t          Jet_TauTag[100];   //[Jet_]
        Float_t         Jet_TauWeight[100];   //[Jet_]
        Int_t           Jet_Charge[100];   //[Jet_]
        Float_t         Jet_EhadOverEem[100];   //[Jet_]
        Int_t           Jet_NCharged[100];   //[Jet_]
        Int_t           Jet_NNeutrals[100];   //[Jet_]
        Float_t         Jet_NeutralEnergyFraction[100];   //[Jet_]
        Float_t         Jet_ChargedEnergyFraction[100];   //[Jet_]
        Float_t         Jet_Beta[100];   //[Jet_]
        Float_t         Jet_BetaStar[100];   //[Jet_]
        Float_t         Jet_MeanSqDeltaR[100];   //[Jet_]
        Float_t         Jet_PTD[100];   //[Jet_]
        Float_t         Jet_FracPt[100][5];   //[Jet_]
        Float_t         Jet_Tau[100][5];   //[Jet_]
        TLorentzVector  Jet_SoftDroppedJet[100];
        TLorentzVector  Jet_SoftDroppedSubJet1[100];
        TLorentzVector  Jet_SoftDroppedSubJet2[100];
        TLorentzVector  Jet_TrimmedP4[5][100];
        TLorentzVector  Jet_PrunedP4[5][100];
        TLorentzVector  Jet_SoftDroppedP4[5][100];
        Int_t           Jet_NSubJetsTrimmed[100];   //[Jet_]
        Int_t           Jet_NSubJetsPruned[100];   //[Jet_]
        Int_t           Jet_NSubJetsSoftDropped[100];   //[Jet_]
        Double_t        Jet_ExclYmerge12[100];   //[Jet_]
        Double_t        Jet_ExclYmerge23[100];   //[Jet_]
        Double_t        Jet_ExclYmerge34[100];   //[Jet_]
        Double_t        Jet_ExclYmerge45[100];   //[Jet_]
        Double_t        Jet_ExclYmerge56[100];   //[Jet_]
        TRefArray       Jet_Constituents[100];
        TRefArray       Jet_Particles[100];
        TLorentzVector  Jet_Area[100];
  */
        Int_t           Jet_size;
  
        
  //      Int_t           Electron_;
 //       UInt_t          Electron_fUniqueID[100];   //[Electron_]
 //       UInt_t          Electron_fBits[100];   //[Electron_]
        Float_t         Electron_PT[100];   //[Electron_]
        Float_t         Electron_Eta[100];   //[Electron_]
        Float_t         Electron_Phi[100];   //[Electron_]
     /*
        Float_t         Electron_T[100];   //[Electron_]
        Int_t           Electron_Charge[100];   //[Electron_]
        Float_t         Electron_EhadOverEem[100];   //[Electron_]
        TRef            Electron_Particle[100];
        Float_t         Electron_IsolationVar[100];   //[Electron_]
        Float_t         Electron_IsolationVarRhoCorr[100];   //[Electron_]
        Float_t         Electron_SumPtCharged[100];   //[Electron_]
        Float_t         Electron_SumPtNeutral[100];   //[Electron_]
        Float_t         Electron_SumPtChargedPU[100];   //[Electron_]
        Float_t         Electron_SumPt[100];   //[Electron_]
        Float_t         Electron_D0[100];   //[Electron_]
        Float_t         Electron_DZ[100];   //[Electron_]
        Float_t         Electron_ErrorD0[100];   //[Electron_]
        Float_t         Electron_ErrorDZ[100];   //[Electron_]
*/
        Int_t           Electron_size;

//        Int_t           Muon_;
//        UInt_t          Muon_fUniqueID[100];   //[Muon_]
//        UInt_t          Muon_fBits[100];   //[Muon_]
        Float_t         Muon_PT[100];   //[Muon_]
        Float_t         Muon_Eta[100];   //[Muon_]
        Float_t         Muon_Phi[100];   //[Muon_]
        Float_t         Muon_T[100];   //[Muon_]
/*      
        Int_t           Muon_Charge[100];   //[Muon_]
        TRef            Muon_Particle[100];
        Float_t         Muon_IsolationVar[100];   //[Muon_]
        Float_t         Muon_IsolationVarRhoCorr[100];   //[Muon_]
        Float_t         Muon_SumPtCharged[100];   //[Muon_]
        Float_t         Muon_SumPtNeutral[100];   //[Muon_]
        Float_t         Muon_SumPtChargedPU[100];   //[Muon_]
        Float_t         Muon_SumPt[100];   //[Muon_]
        Float_t         Muon_D0[100];   //[Muon_]
        Float_t         Muon_DZ[100];   //[Muon_]
        Float_t         Muon_ErrorD0[100];   //[Muon_]
        Float_t         Muon_ErrorDZ[100];   //[Muon_]
*/  
        Int_t           Muon_size;


/*
        Int_t           FatJet_;
        UInt_t          FatJet_fUniqueID[100];   //[FatJet_]
        UInt_t          FatJet_fBits[100];   //[FatJet_]
*/

        Float_t         FatJet_PT[100];   //[FatJet_]
        Float_t         FatJet_Eta[100];   //[FatJet_]
        Float_t         FatJet_Phi[100];   //[FatJet_]
//        Float_t         FatJet_T[100];   //[FatJet_]
        Float_t         FatJet_Mass[100];   //[FatJet_]
/*
        Float_t         FatJet_DeltaEta[100];   //[FatJet_]
        Float_t         FatJet_DeltaPhi[100];   //[FatJet_]
        UInt_t          FatJet_Flavor[100];   //[FatJet_]
        UInt_t          FatJet_FlavorAlgo[100];   //[FatJet_]
        UInt_t          FatJet_FlavorPhys[100];   //[FatJet_]
        UInt_t          FatJet_TauFlavor[100];   //[FatJet_]
*/
        UInt_t          FatJet_BTag[100];   //[FatJet_]
/*
        UInt_t          FatJet_BTagAlgo[100];   //[FatJet_]
        UInt_t          FatJet_BTagPhys[100];   //[FatJet_]
        UInt_t          FatJet_TauTag[100];   //[FatJet_]
        Float_t         FatJet_TauWeight[100];   //[FatJet_]
        Int_t           FatJet_Charge[100];   //[FatJet_]
        Float_t         FatJet_EhadOverEem[100];   //[FatJet_]
        Int_t           FatJet_NCharged[100];   //[FatJet_]
        Int_t           FatJet_NNeutrals[100];   //[FatJet_]
        Float_t         FatJet_NeutralEnergyFraction[100];   //[FatJet_]
        Float_t         FatJet_ChargedEnergyFraction[100];   //[FatJet_]
        Float_t         FatJet_Beta[100];   //[FatJet_]
        Float_t         FatJet_BetaStar[100];   //[FatJet_]
        Float_t         FatJet_MeanSqDeltaR[100];   //[FatJet_]
        Float_t         FatJet_PTD[100];   //[FatJet_]
        Float_t         FatJet_FracPt[100][5];   //[FatJet_]
        Float_t         FatJet_Tau[100][5];   //[FatJet_]
        TLorentzVector  FatJet_SoftDroppedJet[100];
        TLorentzVector  FatJet_SoftDroppedSubJet1[100];
        TLorentzVector  FatJet_SoftDroppedSubJet2[100];
        TLorentzVector  FatJet_TrimmedP4[5][100];
        TLorentzVector  FatJet_PrunedP4[5][100];
        TLorentzVector  FatJet_SoftDroppedP4[5][100];
        Int_t           FatJet_NSubJetsTrimmed[100];   //[FatJet_]
        Int_t           FatJet_NSubJetsPruned[100];   //[FatJet_]
        Int_t           FatJet_NSubJetsSoftDropped[100];   //[FatJet_]
        Double_t        FatJet_ExclYmerge12[100];   //[FatJet_]
        Double_t        FatJet_ExclYmerge23[100];   //[FatJet_]
        Double_t        FatJet_ExclYmerge34[100];   //[FatJet_]
        Double_t        FatJet_ExclYmerge45[100];   //[FatJet_]
        Double_t        FatJet_ExclYmerge56[100];   //[FatJet_]
        TRefArray       FatJet_Constituents[100];
        TRefArray       FatJet_Particles[100];
        TLorentzVector  FatJet_Area[100];
*/
        Int_t           FatJet_size;




        //Int_t           MissingET_;
        //UInt_t          MissingET_fUniqueID[100];   //[MissingET_]
        //UInt_t          MissingET_fBits[100];   //[MissingET_]
        Float_t         MissingET_MET[100];   //[MissingET_]
        //Float_t         MissingET_Eta[100];   //[MissingET_]
        Float_t         MissingET_Phi[100];   //[MissingET_]
        //Int_t           MissingET_size;


        //Int_t           ScalarHT_;
        //UInt_t          ScalarHT_fUniqueID[100];   //[ScalarHT_]
        //UInt_t          ScalarHT_fBits[100];   //[ScalarHT_]
        Float_t         ScalarHT_HT[100];   //[ScalarHT_]
        //Int_t           ScalarHT_size;



};

#endif
