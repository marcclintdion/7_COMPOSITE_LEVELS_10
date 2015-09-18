
char          buffer[200]   = {0};
unsigned int  version       = 0;

/*
 Create a System object and initialize
 */    
result = FMOD::System_Create(&system_iOS_fMod); 


result = system_iOS_fMod->getVersion(&version);



result = system_iOS_fMod->init(32, FMOD_INIT_NORMAL | FMOD_INIT_ENABLE_PROFILE, NULL);


[[NSString stringWithFormat:@"%@/bell6.wav", [[NSBundle mainBundle] resourcePath]] getCString:buffer maxLength:200 encoding:NSASCIIStringEncoding];
result = system_iOS_fMod->createStream(buffer, FMOD_SOFTWARE | FMOD_LOOP_NORMAL, NULL, &sound);

specLeft  = new float[sampleSize];
specRight = new float[sampleSize]; 

/*
 Play the sound
 */    

 