




    //////////////////************************************************	
    ALenum format;
	ALsizei size;
	ALvoid* data;
	ALsizei freq;
	ALboolean loop;
    //////////////////************************************************
    //////////////////************************************************	
    //////////////////************************************************ 
    
    
    alGenBuffers(1, &Buffer_dungeonWAV);

	alutLoadWAVFile("AUDIO/dung.wav", &format, &data, &size, &freq, &loop);
	alBufferData(Buffer_dungeonWAV, format, data, size, freq);
	alutUnloadWAV(format, data, size, freq);

	alGenSources(1, &Source_dungeonWAV);

	alSourcei (Source_dungeonWAV, AL_BUFFER,   Buffer_dungeonWAV   );
	alSourcefv(Source_dungeonWAV, AL_POSITION, SourcePos_dungeonWAV);
	//////////////////------------------------------------------------	




