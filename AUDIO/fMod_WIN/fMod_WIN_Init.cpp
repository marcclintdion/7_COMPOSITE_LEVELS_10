 /*    
   
    result_fMod_WIN = FMOD_System_Create(&system_fMod_WIN);
  
    result_fMod_WIN = FMOD_System_GetVersion(system_fMod_WIN, &version_fMod_WIN);
  
    result_fMod_WIN = FMOD_System_Init(system_fMod_WIN, 32, FMOD_INIT_NORMAL, NULL);

    result_fMod_WIN = FMOD_System_CreateSound(system_fMod_WIN, "AUDIO/bell6.wav", FMOD_HARDWARE, 0, &sound1);
 
    result_fMod_WIN = FMOD_Sound_SetMode(sound1, FMOD_LOOP_OFF); //drumloop.wav has embedded loop points which automatically makes looping turn on

    result_fMod_WIN = FMOD_System_CreateSound(system_fMod_WIN, "AUDIO/dung.wav", FMOD_SOFTWARE, 0, &sound2);

    result_fMod_WIN = FMOD_System_CreateSound(system_fMod_WIN, "AUDIO/g.wav", FMOD_HARDWARE, 0, &sound3);

*/


//#########################################################################################################################
//_OLD_FMOD

FSOUND_Init(44000,64,0);
       
        //------------------------------------------------------------------------
        // attempt to open the mp3 file as a stream
        g_sample = FSOUND_Sample_Load(FSOUND_FREE,"AUDIO/bell6.wav",FSOUND_2D,0,0);

        //g_sample2 = FSOUND_Sample_Load(FSOUND_FREE,"AUDIO/dung.wav",FSOUND_2D,0,0);

        //------------------------------------------------------------------------
	            // start the sound playing
	    ch  = FSOUND_PlaySound(FSOUND_FREE,g_sample);
	    FSOUND_SetLoopMode(ch,FSOUND_LOOP_OFF);
        
        //ch2 = FSOUND_PlaySound(FSOUND_FREE,g_sample2);
 
        //FSOUND_SetLoopMode(ch2,FSOUND_LOOP_NORMAL);
        
        //============================================================================================
        //__________________________________________________________________frequencies
    	        // initialise fmod, 44000 Hz, 64 channels
                // attempt to open the mp3 file as a stream
        //g_mp3_stream = FSOUND_Stream_Open( "AUDIO/Hawaii5O.mp3" , FSOUND_2D , 0 , 0 );
                // play the mp3
        //FSOUND_Stream_Play(0,g_mp3_stream);
        
        
	            // get a pointer to fmods fft (fast fourier transform) unit 
	    DLL_API FSOUND_DSPUNIT *fft = FSOUND_DSP_GetFFTUnit();
        
	            // enable the fft unit 
	    FSOUND_DSP_SetActive(fft,TRUE);

