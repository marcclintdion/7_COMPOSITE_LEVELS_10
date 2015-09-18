ALCcontext		*newContext = NULL;
ALCdevice		*newDevice = NULL;

// Create a new OpenAL Device
// Pass NULL to specify the system’s default output device
newDevice = alcOpenDevice(NULL);

// Create a new OpenAL Context
// The new context will render to the OpenAL Device just created 
newContext = alcCreateContext(newDevice, 0);

// Make the new context the Current OpenAL Context
alcMakeContextCurrent(newContext);

// Create some OpenAL Buffer Objects
alGenBuffers(1, &_buffer_openAL_iOS);


// Create some OpenAL Source Objects
alGenSources(1, &_source);




ALenum  format;
ALsizei size;
ALsizei freq;

NSBundle*				bundle = [NSBundle mainBundle];

// get some audio data from a wave file
CFURLRef fileURL = (CFURLRef)[[NSURL fileURLWithPath:[bundle pathForResource:@"g" ofType:@"wav"]] retain];

_data = MyGetOpenALAudioData(fileURL, &size, &format, &freq);
CFRelease(fileURL);


// use the static buffer data API
alBufferDataStaticProc(_buffer_openAL_iOS, format, _data, size, freq);



alSourcei(_source, AL_LOOPING, AL_TRUE);


// attach OpenAL Buffer to OpenAL Source
alSourcei(_source, AL_BUFFER, _buffer_openAL_iOS);


float newVolume = 1.0f;
alSourcef(_source, AL_GAIN, newVolume);