//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    //===================================================================================================================
    glGenFramebuffers( 1, &softDiffuse_FBO);
    //--------------------------------------
    glGenTextures(1, &softDiffuse_FBO_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, softDiffuse_FBO_TEXTURE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //-----------------------------------------------------------------    
    glBindFramebuffer(GL_FRAMEBUFFER, softDiffuse_FBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, softDiffuse_FBO_TEXTURE, 0);
    //===================================================================================================================   
