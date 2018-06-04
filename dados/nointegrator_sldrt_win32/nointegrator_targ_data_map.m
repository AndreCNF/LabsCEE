  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nointegrator_P)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% nointegrator_P.A
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nointegrator_P.K
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 25;
	
	  ;% nointegrator_P.L
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 30;
	
	  ;% nointegrator_P.MOTOR_SAT
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 40;
	
	  ;% nointegrator_P.TH1_BOUND
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 41;
	
	  ;% nointegrator_P.TH2_BOUND
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 42;
	
	  ;% nointegrator_P.TIME_DELAY
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 43;
	
	  ;% nointegrator_P.AnalogOutput1_FinalValue
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 44;
	
	  ;% nointegrator_P.EncoderInput_InputFilter
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 45;
	
	  ;% nointegrator_P.EncoderInput_MaxMissedTicks
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 46;
	
	  ;% nointegrator_P.AnalogOutput1_MaxMissedTicks
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 47;
	
	  ;% nointegrator_P.RealTimeSynchronization_MaxMissedTicks
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 48;
	
	  ;% nointegrator_P.EncoderInput_YieldWhenWaiting
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 49;
	
	  ;% nointegrator_P.AnalogOutput1_YieldWhenWaiting
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 50;
	
	  ;% nointegrator_P.RealTimeSynchronization_YieldWhenWaiting
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% nointegrator_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nointegrator_P.AnalogOutput1_Channels
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 2;
	
	  ;% nointegrator_P.AnalogOutput1_RangeMode
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 3;
	
	  ;% nointegrator_P.AnalogOutput1_VoltRange
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% nointegrator_P.Zero1_Value
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nointegrator_P.EncoderCalibration2piENCODER_RESradcount_Gain
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nointegrator_P.Bias_Bias
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% nointegrator_P.Bias2_Bias
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 4;
	
	  ;% nointegrator_P.Constant1_Value
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 5;
	
	  ;% nointegrator_P.Bias3_Bias
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 6;
	
	  ;% nointegrator_P.Selectang1_Gain
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 7;
	
	  ;% nointegrator_P.Zero_Value
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 9;
	
	  ;% nointegrator_P.Selectang2_Gain
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 10;
	
	  ;% nointegrator_P.StateSpaceController_X0
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 12;
	
	  ;% nointegrator_P.Backlash_BacklashWidth
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 13;
	
	  ;% nointegrator_P.Backlash_InitialOutput
	  section.data(12).logicalSrcIdx = 31;
	  section.data(12).dtTransOffset = 14;
	
	  ;% nointegrator_P.Gain_Gain
	  section.data(13).logicalSrcIdx = 32;
	  section.data(13).dtTransOffset = 15;
	
	  ;% nointegrator_P.Constant_Value
	  section.data(14).logicalSrcIdx = 33;
	  section.data(14).dtTransOffset = 16;
	
	  ;% nointegrator_P.Step_Y0
	  section.data(15).logicalSrcIdx = 34;
	  section.data(15).dtTransOffset = 17;
	
	  ;% nointegrator_P.Step_YFinal
	  section.data(16).logicalSrcIdx = 35;
	  section.data(16).dtTransOffset = 18;
	
	  ;% nointegrator_P.Timedelay_Threshold
	  section.data(17).logicalSrcIdx = 36;
	  section.data(17).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nointegrator_B)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% nointegrator_B.Bias
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nointegrator_B.Bias3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% nointegrator_B.Selectang1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% nointegrator_B.Selectang2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% nointegrator_B.StateSpaceController
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% nointegrator_B.Backlash
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% nointegrator_B.Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% nointegrator_B.Timedelay
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nointegrator_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% nointegrator_DW.PrevY
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% nointegrator_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nointegrator_DW.AnalogOutput1_PWORK
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nointegrator_DW.RealTimeSynchronization_PWORK
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% nointegrator_DW.angles_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% nointegrator_DW.AnglesradandControluV_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 21386234;
  targMap.checksum1 = 3183576253;
  targMap.checksum2 = 1336835628;
  targMap.checksum3 = 2660123903;

