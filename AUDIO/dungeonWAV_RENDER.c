

    alGetSourcei(Source_dungeonWAV, AL_SOURCE_STATE, &state_dungeonWAV);		
    if(state_dungeonWAV != AL_PLAYING)
    {
         alSourcePlay(Source_dungeonWAV);
    }
    
