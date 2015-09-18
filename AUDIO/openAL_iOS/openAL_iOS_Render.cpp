
alGetSourcei(_source, AL_SOURCE_STATE, &state_gSound);		

if(state_gSound != AL_PLAYING)
{
        alSourcePlay(_source);
}