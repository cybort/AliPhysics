/*
 * AliAnalysisTaskLeuteronNanoAOD.h
 *
 *  Created on:	06 November 2019
 *	Author:	Michael Jung
 */

#ifndef PWGCF_FEMTOSCOPY_FEMTODREAM_ALIANALYSISTASKLEUTERONNANOAOD_H_
#define PWGCF_FEMTOSCOPY_FEMTODREAM_ALIANALYSISTASKLEUTERONNANOAOD_H_

#include "AliAnalysisTaskSE.h"
#include "AliFemtoDreamEvent.h"
#include "AliFemtoDreamEventCuts.h"
#include "AliVTrack.h"
#include "AliFemtoDreamTrack.h"
#include "AliFemtoDreamTrackCuts.h"
#include "AliFemtoDreamv0.h"
#include "AliFemtoDreamv0Cuts.h"
#include "AliFemtoDreamCollConfig.h"
#include "AliFemtoDreamPairCleaner.h"
#include "AliFemtoDreamPartCollection.h"

class AliAnalysisTaskLeuteronNanoAOD : public AliAnalysisTaskSE {

  public:

    AliAnalysisTaskLeuteronNanoAOD();							// class constructor without parameters
    AliAnalysisTaskLeuteronNanoAOD(const char* name,bool isMC);				// class constructor with parameters
    AliAnalysisTaskLeuteronNanoAOD& operator = (const AliAnalysisTaskLeuteronNanoAOD &task);	// copy assignment operator
    AliAnalysisTaskLeuteronNanoAOD(const AliAnalysisTaskLeuteronNanoAOD &task);		// copy constructor
    virtual ~AliAnalysisTaskLeuteronNanoAOD();						// class destructor

    virtual void UserCreateOutputObjects();			// is called only once -> define output objects within this function
    virtual void UserExec(Option_t *option);			// is called in every event -> define what to search for in the events 
    virtual void Terminate(Option_t *option){};			// is called only once -> terminates the analysis

    void SetEventCuts(AliFemtoDreamEventCuts *evtCuts){
      fEventCuts = evtCuts;
    };
    void SetTrackCutsPart1(AliFemtoDreamTrackCuts *trkCuts){	// particle 1 will be Deuterons
      fTrackCutsPart1 = trkCuts;
    };
    void SetTrackCutsPart2(AliFemtoDreamTrackCuts *trkCuts){	// particle 2 will be Antideuterons
      fTrackCutsPart2 = trkCuts;
    };
    void Setv0CutsPart3(AliFemtoDreamv0Cuts *v0Cuts){		// particle 3 will be Lambdas
      fv0CutsPart3 = v0Cuts;
    };
    void Setv0CutsPart4(AliFemtoDreamv0Cuts *v0Cuts){		// particle 4 will be Antilambdas
      fv0CutsPart4 = v0Cuts;
    };
    void SetCollectionConfig(AliFemtoDreamCollConfig *config){
      fConfig = config;
    };

  private:

    void ResetGlobalTrackReference();				// is called in every event -> resets the track information
    void StoreGlobalTrackReference(AliVTrack *track);		// is called for every track -> stores the track information
    bool fIsMC;							// run over data "fIsMC(false)" or over Monte Carlo data "fIsMC(true)"
    int fTrackBufferSize;						

    TList			    *fOutput;			// list with output objects
    AliFemtoDreamEvent		    *fEvent;
    AliFemtoDreamTrack		    *fTrack;
    AliFemtoDreamv0		    *fFemtov0;

    AliFemtoDreamEventCuts	    *fEventCuts;		// cuts for the events
    AliFemtoDreamTrackCuts	    *fTrackCutsPart1;		// cuts for the tracks of particle 1 (Deuterons)
    AliFemtoDreamTrackCuts	    *fTrackCutsPart2;		// cuts for the tracks of particle 2 (Antideuterons)
    AliFemtoDreamv0Cuts		    *fv0CutsPart3;		// cuts for the tracks of particle 3 (Lambdas)
    AliFemtoDreamv0Cuts		    *fv0CutsPart4;		// cuts for the tracks of particle 4 (Antilambdas)

    AliFemtoDreamCollConfig	    *fConfig;			// store the configurations needed for the calculation of the correlation function
    AliFemtoDreamPairCleaner	    *fPairCleaner;
    AliFemtoDreamPartCollection	    *fPartColl;
    AliVTrack			    **fGTI;			// global track information (GTI)

    ClassDef(AliAnalysisTaskLeuteronNanoAOD,1);
	
};

#endif /* PWGCF_FEMTOSCOPY_FEMTODREAM_ALIANALYSISTASKLEUTERONNANOAOD_H_ */

