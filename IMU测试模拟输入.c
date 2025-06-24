
   if(IMUdateSwitch == 1u)
   {  
      /* signal correct check */
      ImuSgPoolMgr_CompleteData.SlotData[0].RawSignal.Data = P_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[1].RawSignal.Data = P_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[2].RawSignal.Data = PZ_Direct * P_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[3].RawSignal.Data = P_A_Sensitivity * (sint16)90;
      ImuSgPoolMgr_CompleteData.SlotData[4].RawSignal.Data = P_A_Sensitivity * (sint16)90;
      ImuSgPoolMgr_CompleteData.SlotData[5].RawSignal.Data = P_A_Sensitivity * (sint16)90;

      ImuSgPoolMgr_CompleteData.SlotData[6].RawSignal.Data =  S_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[7].RawSignal.Data = S_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[8].RawSignal.Data = SZ_Direct * S_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[9].RawSignal.Data = S_A_Sensitivity * (sint16)90;
      ImuSgPoolMgr_CompleteData.SlotData[10].RawSignal.Data = S_A_Sensitivity * (sint16)90;
      ImuSgPoolMgr_CompleteData.SlotData[11].RawSignal.Data = S_A_Sensitivity * (sint16)90;
   }
   else if(IMUdateSwitch == 2u)
   {
      /* LOG out of sample */
      ImuSgPoolMgr_CompleteData.SlotData[0].RawSignal.Data = (P_G_Sensitivity * (sint16)51)/(sint16)100;
      ImuSgPoolMgr_CompleteData.SlotData[1].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[2].RawSignal.Data = PZ_Direct * P_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[3].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[4].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[5].RawSignal.Data = (sint16)0;

      ImuSgPoolMgr_CompleteData.SlotData[6].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[7].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[8].RawSignal.Data = SZ_Direct * S_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[9].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[10].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[11].RawSignal.Data = (sint16)0;
   }
   else if(IMUdateSwitch == 3u)
   {
      /* sensor invalid */
      ImuSgPoolMgr_CompleteData.SlotData[0].RawSignal.Status = 0x40;
   }
   else if(IMUdateSwitch == 4u)
   {
      /*ARS out of sample*/
      ImuSgPoolMgr_CompleteData.SlotData[0].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[1].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[2].RawSignal.Data = PZ_Direct * P_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[3].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[4].RawSignal.Data = P_A_Sensitivity * (sint16)11;
      ImuSgPoolMgr_CompleteData.SlotData[5].RawSignal.Data = (sint16)0;

      ImuSgPoolMgr_CompleteData.SlotData[6].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[7].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[8].RawSignal.Data = SZ_Direct * S_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[9].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[10].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[11].RawSignal.Data = (sint16)0;
   }
   else if(IMUdateSwitch == 5u)
   {
      /* LOG out of average*/
      ImuSgPoolMgr_CompleteData.SlotData[0].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[1].RawSignal.Data = (P_G_Sensitivity * (sint16)11)/(sint16)100;
      ImuSgPoolMgr_CompleteData.SlotData[2].RawSignal.Data = PZ_Direct * P_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[3].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[4].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[5].RawSignal.Data = (sint16)0;

      ImuSgPoolMgr_CompleteData.SlotData[6].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[7].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[8].RawSignal.Data = SZ_Direct * S_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[9].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[10].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[11].RawSignal.Data = (sint16)0;
   }
   else if(IMUdateSwitch == 6u)
   {
      /*ARS out of average */
      ImuSgPoolMgr_CompleteData.SlotData[0].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[1].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[2].RawSignal.Data = PZ_Direct * P_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[3].RawSignal.Data = P_A_Sensitivity * (sint16)4;
      ImuSgPoolMgr_CompleteData.SlotData[4].RawSignal.Data = (sint16)11;
      ImuSgPoolMgr_CompleteData.SlotData[5].RawSignal.Data = (sint16)0;

      ImuSgPoolMgr_CompleteData.SlotData[6].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[7].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[8].RawSignal.Data = SZ_Direct * S_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[9].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[10].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[11].RawSignal.Data = (sint16)0;
   }
   else if(IMUdateSwitch == 7u)
   {
      /* all data in range */
      ImuSgPoolMgr_CompleteData.SlotData[0].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[1].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[2].RawSignal.Data = PZ_Direct * P_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[3].RawSignal.Data = P_A_Sensitivity * (sint16)2;
      ImuSgPoolMgr_CompleteData.SlotData[4].RawSignal.Data = (sint16)11;
      ImuSgPoolMgr_CompleteData.SlotData[5].RawSignal.Data = (sint16)0;

      ImuSgPoolMgr_CompleteData.SlotData[6].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[7].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[8].RawSignal.Data = SZ_Direct * S_G_Sensitivity * (sint16)1;
      ImuSgPoolMgr_CompleteData.SlotData[9].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[10].RawSignal.Data = (sint16)0;
      ImuSgPoolMgr_CompleteData.SlotData[11].RawSignal.Data = (sint16)0;
   }
   else if(IMUdateSwitch == 8u)
   {  /* MAX output */
      ImuSgPoolMgr_CompleteData.SlotData[0].RawSignal.Data = P_G_Sensitivity * (sint16)3;
      ImuSgPoolMgr_CompleteData.SlotData[1].RawSignal.Data = P_G_Sensitivity * (sint16)3;
      ImuSgPoolMgr_CompleteData.SlotData[2].RawSignal.Data = PZ_Direct * P_G_Sensitivity * (sint16)3;
      ImuSgPoolMgr_CompleteData.SlotData[3].RawSignal.Data = P_A_Sensitivity * (sint16)300;
      ImuSgPoolMgr_CompleteData.SlotData[4].RawSignal.Data = P_A_Sensitivity * (sint16)300;
      ImuSgPoolMgr_CompleteData.SlotData[5].RawSignal.Data = P_A_Sensitivity * (sint16)300;

      ImuSgPoolMgr_CompleteData.SlotData[6].RawSignal.Data =  S_G_Sensitivity * (sint16)3;
      ImuSgPoolMgr_CompleteData.SlotData[7].RawSignal.Data = S_G_Sensitivity * (sint16)3;
      ImuSgPoolMgr_CompleteData.SlotData[8].RawSignal.Data = SZ_Direct * S_G_Sensitivity * (sint16)3;
      ImuSgPoolMgr_CompleteData.SlotData[9].RawSignal.Data = S_A_Sensitivity * (sint16)300;
      ImuSgPoolMgr_CompleteData.SlotData[10].RawSignal.Data = S_A_Sensitivity * (sint16)300;
      ImuSgPoolMgr_CompleteData.SlotData[11].RawSignal.Data = S_A_Sensitivity * (sint16)300;
   }
   else
   {

   }

   