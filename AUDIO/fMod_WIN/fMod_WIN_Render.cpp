/*        

        if(FMOD_Channel_IsPlaying(channel_fMod_WIN, &playing_fMod_WIN) && playOnce)
        {
                result_fMod_WIN = FMOD_System_PlaySound(system_fMod_WIN, FMOD_CHANNEL_FREE, sound1, 0, &channel_fMod_WIN);
                //result_fMod_WIN = FMOD_System_PlaySound(system_fMod_WIN, FMOD_CHANNEL_FREE, sound2, 0, &channel_fMod_WIN);
                //result_fMod_WIN = FMOD_System_PlaySound(system_fMod_WIN, FMOD_CHANNEL_FREE, sound3, 0, &channel_fMod_WIN);
        playOnce = false;
        }
        
        FMOD_System_Update(system_fMod_WIN);




                //FMOD_SOUND *currentsound = 0;

                //result_fMod_WIN = FMOD_Channel_IsPlaying(channel_fMod_WIN, &playing_fMod_WIN);

                //result_fMod_WIN = FMOD_Channel_GetPaused(channel_fMod_WIN, &paused);

                //result_fMod_WIN = FMOD_Channel_GetPosition(channel_fMod_WIN, &ms, FMOD_TIMEUNIT_MS);


                //FMOD_Channel_GetCurrentSound(channel_fMod_WIN, &currentsound);


                //FMOD_System_GetChannelsPlaying(system_fMod_WIN, &channelsplaying_fMod_WIN);

*/ 
//#########################################################################################################################
//_OLD_FMOD

        if(!FSOUND_IsPlaying(ch))
        {
                ch  = FSOUND_PlaySound(FSOUND_FREE,g_sample);
                directionSoundTravels *= -1.0;
        }

        spectrum = FSOUND_DSP_GetSpectrum();      

        for(unsigned int i = 0; i < 512; i++) 
        {
                frequency[i] = spectrum[i];
        } 



// for(unsigned int i=0;i!=512;++i) 
// {
// glColor3f(1.0-4*spectrum[i],4*spectrum[i],0);
// glVertex2f(10+i,0.5+20*spectrum[i]);
// }











 

 

