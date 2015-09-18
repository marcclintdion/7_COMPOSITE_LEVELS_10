//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    glGenFramebuffers(1, &drawMainColor_PRIMARY_FBO);
    //----------------------------------------------------------------------------
    glGenTextures(1, &drawMainColor_PRIMARY_FBO_COLOR_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_COLOR_TEXTURE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
    //----------------------------------------------------------------------------
    glGenTextures(1, &drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth, (GLsizei)viewHeight,  0, GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);        
    //----------------------------------------------------------------------------
    glBindFramebuffer(GL_FRAMEBUFFER, drawMainColor_PRIMARY_FBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_COLOR_TEXTURE, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,  GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE, 0);


