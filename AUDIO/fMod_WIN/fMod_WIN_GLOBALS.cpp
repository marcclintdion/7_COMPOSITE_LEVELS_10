/*
#include "fmod.hpp"


    FMOD_SYSTEM      *system_fMod_WIN;
    FMOD_SOUND       *sound1, *sound2, *sound3;
    FMOD_CHANNEL     *channel_fMod_WIN = 0;
    FMOD_RESULT       result_fMod_WIN;
    unsigned int      version_fMod_WIN;  
    
    
    unsigned int      ms = 0;
    unsigned int      lenms = 0;
    int               playing_fMod_WIN = 0;
    int               paused = 0;
    int               channelsplaying_fMod_WIN = 0;
 
*/ 
  
//#########################################################################################################################
//_OLD_FMOD    

#include "../../headerFiles/fmod.h"
#include "../../headerFiles/fmod_errors.h"        
FSOUND_SAMPLE* g_sample = NULL;
FSOUND_SAMPLE* g_sample2 = NULL;
int ch;
int ch2;

const float* spectrum;

//=============================================//frequencies
FSOUND_STREAM* g_mp3_stream = NULL;
//=============================================




 
