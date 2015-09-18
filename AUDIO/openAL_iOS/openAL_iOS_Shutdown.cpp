ALCcontext	*context = NULL;
ALCdevice	*device = NULL;

// Delete the Sources
alDeleteSources(1, &_source);
// Delete the Buffers
alDeleteBuffers(1, &_buffer);

//Get active context (there can only be one)
context = alcGetCurrentContext();
//Get device for active context
device = alcGetContextsDevice(context);
//Release context
alcDestroyContext(context);
//Close device
alcCloseDevice(device);   