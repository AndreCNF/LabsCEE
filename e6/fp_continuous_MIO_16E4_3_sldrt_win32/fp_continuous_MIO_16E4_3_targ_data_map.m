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
    ;% Auto data (fp_continuous_MIO_16E4_3_P)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% fp_continuous_MIO_16E4_3_P.A
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% fp_continuous_MIO_16E4_3_P.K
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 25;
	
	  ;% fp_continuous_MIO_16E4_3_P.L
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 30;
	
	  ;% fp_continuous_MIO_16E4_3_P.MOTOR_SAT
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 40;
	
	  ;% fp_continuous_MIO_16E4_3_P.TH1_BOUND
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 41;
	
	  ;% fp_continuous_MIO_16E4_3_P.TH2_BOUND
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 42;
	
	  ;% fp_continuous_MIO_16E4_3_P.TIME_DELAY
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 43;
	
	  ;% fp_continuous_MIO_16E4_3_P.AnalogOutput_FinalValue
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 44;
	
	  ;% fp_continuous_MIO_16E4_3_P.CounterInput_MaxMissedTicks
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 45;
	
	  ;% fp_continuous_MIO_16E4_3_P.AnalogOutput_MaxMissedTicks
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 46;
	
	  ;% fp_continuous_MIO_16E4_3_P.RealTimeSynchronization_MaxMissedTicks
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 47;
	
	  ;% fp_continuous_MIO_16E4_3_P.CounterInput_YieldWhenWaiting
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 48;
	
	  ;% fp_continuous_MIO_16E4_3_P.AnalogOutput_YieldWhenWaiting
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 49;
	
	  ;% fp_continuous_MIO_16E4_3_P.RealTimeSynchronization_YieldWhenWaiting
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 50;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% fp_continuous_MIO_16E4_3_P.CounterInput_Channels
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% fp_continuous_MIO_16E4_3_P.AnalogOutput_Channels
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 2;
	
	  ;% fp_continuous_MIO_16E4_3_P.CounterInput_CounterEdge
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 3;
	
	  ;% fp_continuous_MIO_16E4_3_P.CounterInput_CounterGate
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 4;
	
	  ;% fp_continuous_MIO_16E4_3_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 5;
	
	  ;% fp_continuous_MIO_16E4_3_P.AnalogOutput_VoltRange
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% fp_continuous_MIO_16E4_3_P.Zero1_Value
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% fp_continuous_MIO_16E4_3_P.EncoderCalibration2piENCODER_RESradcount_Gain
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% fp_continuous_MIO_16E4_3_P.Bias_Bias
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% fp_continuous_MIO_16E4_3_P.Bias2_Bias
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 4;
	
	  ;% fp_continuous_MIO_16E4_3_P.Constant1_Value
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 5;
	
	  ;% fp_continuous_MIO_16E4_3_P.Bias3_Bias
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 6;
	
	  ;% fp_continuous_MIO_16E4_3_P.Selectang1_Gain
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 7;
	
	  ;% fp_continuous_MIO_16E4_3_P.Zero_Value
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 9;
	
	  ;% fp_continuous_MIO_16E4_3_P.Selectang2_Gain
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 10;
	
	  ;% fp_continuous_MIO_16E4_3_P.StateSpaceController_X0
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 12;
	
	  ;% fp_continuous_MIO_16E4_3_P.Gain_Gain
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 13;
	
	  ;% fp_continuous_MIO_16E4_3_P.Constant_Value
	  section.data(12).logicalSrcIdx = 32;
	  section.data(12).dtTransOffset = 14;
	
	  ;% fp_continuous_MIO_16E4_3_P.Step_Y0
	  section.data(13).logicalSrcIdx = 33;
	  section.data(13).dtTransOffset = 15;
	
	  ;% fp_continuous_MIO_16E4_3_P.Step_YFinal
	  section.data(14).logicalSrcIdx = 34;
	  section.data(14).dtTransOffset = 16;
	
	  ;% fp_continuous_MIO_16E4_3_P.Timedelay_Threshold
	  section.data(15).logicalSrcIdx = 35;
	  section.data(15).dtTransOffset = 17;
	
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
    ;% Auto data (fp_continuous_MIO_16E4_3_B)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% fp_continuous_MIO_16E4_3_B.Bias
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% fp_continuous_MIO_16E4_3_B.Bias3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% fp_continuous_MIO_16E4_3_B.Selectang1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% fp_continuous_MIO_16E4_3_B.Selectang2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% fp_continuous_MIO_16E4_3_B.StateSpaceController
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% fp_continuous_MIO_16E4_3_B.Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% fp_continuous_MIO_16E4_3_B.Timedelay
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
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
    nTotSects     = 1;
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
    ;% Auto data (fp_continuous_MIO_16E4_3_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% fp_continuous_MIO_16E4_3_DW.CounterInput_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% fp_continuous_MIO_16E4_3_DW.AnalogOutput_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% fp_continuous_MIO_16E4_3_DW.RealTimeSynchronization_PWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% fp_continuous_MIO_16E4_3_DW.angles_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% fp_continuous_MIO_16E4_3_DW.AnglesradandControluV_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
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


  targMap.checksum0 = 4133864875;
  targMap.checksum1 = 773794694;
  targMap.checksum2 = 4092391005;
  targMap.checksum3 = 3168618189;

