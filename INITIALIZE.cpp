//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        //==========================================================================
        #ifdef WIN32
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp"
            alutInit(NULL, 0);
            //-------------------------------------
            SetVSyncState(true);
            //-----------------------------------------------------------------------------
                        rotateModelWithMiddleMouse[0] = Pass_MIDDLE_Mouse[0];
                        rotateModelWithMiddleMouse[1] = Pass_MIDDLE_Mouse[1];
                        //-----------------------------------------------------------------
                        zoomModelWithMiddleMouse      = Pass_MIDDLE_CONTROL_Mouse;
                        //-----------------------------------------------------------------     
                        moveModelWithMiddleMouse[0]   = Pass_MIDDLE_SHIFT_Mouse[0];
                        moveModelWithMiddleMouse[1]   = Pass_MIDDLE_SHIFT_Mouse[1];
                        //-----------------------------------------------------------------       
       
        //=================
        #endif
                   
                   
                  
start = getMilliCount();
                
//################################################################################################################################
/*
        #ifdef __APPLE__
        
                if(sound_API_selector == 0)
                {
                        #include "AUDIO/openAL_iOS/openAL_iOS_Init.cpp"
                }        
                if(sound_API_selector == 1)
                {        
                        //#include "AUDIO/fMod_iOS/fMod_iOS_Init.cpp" //_____found_in_EAGLView
                }
        
        #endif
        //=========================================================
        #ifdef WIN32
                
                if(sound_API_selector == 0)
                {
                        #include "AUDIO/openAL_WIN/openAL_WIN_Init.cpp"
                }
                
                if(sound_API_selector == 1)
                {    
                        #include "AUDIO/fMod_WIN/fMod_WIN_Init.cpp"
                }
        
        #endif
*/



//========================================================================
#ifdef WIN32
                screenRatio                = (GLfloat)viewWidth / (GLfloat)viewHeight;
#endif
//--------------
#ifdef __APPLE__
                screenRatio                = (GLfloat)viewHeight/(GLfloat)viewWidth;
#endif
//========================================================================    
 
    
//NSLog(@"screenRatio: %f", (GLfloat)screenRatio);
   
//=====================================================================================================
//-----------------------------------------------------------------------------------------------------
//_____________________________________________________________________________________________________
GLfloat adjustToResolution = (GLfloat)viewWidth/(GLfloat)viewHeight;
//===================================================================
#ifdef WIN32
        display_00_SCALE[0] = 1.0/(GLfloat)viewWidth * (GLfloat)viewWidth * adjustToResolution*4.52/10;   
        display_00_SCALE[1] = display_00_SCALE[0]; 
        
        //------------------------------------------------------------------------------------------------
        scaleScreenAlignedQuadRatio   = (GLfloat)viewWidth / (GLfloat)viewHeight;
        //-----------------------------------------------------------------------
        inverseScreenRatio            = 1.0 / (GLfloat)viewWidth * (GLfloat)viewHeight; 
        display_00_MOVE[0]           += inverseScreenRatio * display_00_SCALE[0] * 0.5; 
        display_00_MOVE[1]           -=  display_00_SCALE[1] * 0.5;
        //------------------------------------------------------------------------------------------------
        GLfloat skipTouchIncrement = display_00_SCALE[1] / scaleScreenAlignedQuadRatio;
        display_00_MOVE[0] += skipTouchIncrement;
#endif       
//========================= 
#ifdef __APPLE__
        display_00_SCALE[0] = 1.0/(GLfloat)viewWidth * (GLfloat)viewWidth * adjustToResolution*4.52/10*4.0;   
        display_00_SCALE[1] = display_00_SCALE[0]; 
        
        //-----------------------------------------------------------------------
        scaleScreenAlignedQuadRatio   =  (GLfloat)viewWidth / (GLfloat)viewHeight;
        //-----------------------------------------------------------------------
        inverseScreenRatio            = (1.0 / (GLfloat)viewHeight) * viewWidth; 
        display_00_MOVE[1]           -=  inverseScreenRatio * display_00_SCALE[0] * 0.5; 
        display_00_MOVE[0]           -=  display_00_SCALE[1] * 0.5 ;        
        //---------------------------------------------------------------------------------------------
        GLfloat skipTouchIncrement = display_00_SCALE[1] * scaleScreenAlignedQuadRatio;
        display_00_MOVE[1] -= skipTouchIncrement;
#endif        
//_____________________________________________________________________________________________________
//-----------------------------------------------------------------------------------------------------
//=====================================================================================================


//===========================================================================================================
//===========================================================================================================
#ifdef WIN32        
        glGenTextures(1, &m_uiShadowMapTexture);
	    //------------
        glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth  * resize_SHADOW_FBO, 
                                                           (GLsizei)viewHeight * resize_SHADOW_FBO, 
                                                            0, GL_DEPTH_COMPONENT,  GL_UNSIGNED_INT,  NULL);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);        
        //------------------------------------------------------------------
	    glGenFramebuffers(1, &m_uiFrameBufferObject);
	    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        //---------------------
        glDrawBuffer(GL_NONE);//_ON_SOME_MACHINES_THIS_IS_REQUIRED / ON_SOME_IT_FAILS
        glReadBuffer(GL_NONE);//_SAME_AS_ABOVE
	    //---------------------
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
#endif
//===================== NSLog(@"viewWidth: %f", (GLfloat)viewWidth);   
#ifdef __APPLE__
        glGenTextures(1, &m_uiShadowMapTexture);
	    //------------
        glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 2000, 
                                                           1000, 
                                                           0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, 0);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //------------------------------------------------------------------
	    glGenFramebuffers(1, &m_uiFrameBufferObject);
	    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        //---------------------
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
 #endif
//==========================================================================================================
//==========================================================================================================
//==============================================================================
//==============================================================================
#ifdef WIN32   
        atexit(KillALData);//_tell_openAL_to_run_KillALData_function_at_shutdown 
#endif    
        
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
        
//==============================================================================
//==============================================================================



    //====================================================================================
    // #include "_MODEL_FOLDERS_/lightSpheres/lightSpheres_Init.cpp"
    //====================================================================================
    //#include "_SHADERS/drawMainColor_FBO/drawMainColor_FBO_INIT.cpp"
    //====================================================================================
    #include "_SHADERS/drawMainColor_PRIMARY_FBO/drawMainColor_PRIMARY_FBO_INIT.cpp"
    //====================================================================================
    //#include "_SHADERS/hardEdgeShadow_FBO/hardEdgeShadow_FBO_INIT.cpp"
    //====================================================================================
    #include "_SHADERS/generic_FBO/generic_FBO_INIT.cpp"
    //====================================================================================
    #include "_SHADERS/softDiffuse_FBO/softDiffuse_FBO_INIT.cpp"
    //====================================================================================
    
    //######################################################################################################  
    
    
    //====================================================================================
    #include "_SHADERS/finalComposite/finalComposite_SHADER_INIT.cpp"
    //====================================================================================
    #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_INIT.cpp"    
    //====================================================================================
    //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Horizontal_SHADER_INIT.cpp"                                                                   
    //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Vertical_SHADER_INIT.cpp"  
    //====================================================================================
    #include "_SHADERS/copyFBO/copyFBO_SHADER_INIT.cpp"        
    //====================================================================================
    #include "_SHADERS/PowerVR_blur/PowerVR_blur_SHADER_INIT.cpp"
    //====================================================================================
    #include "_SHADERS/baseRoom/baseRoom_SHADER_INIT.cpp"
    //====================================================================================
    #include "_SHADERS/basic/basic_SHADER_INIT.cpp"
    //====================================================================================
    #include "_SHADERS/sky/sky_SHADER_INIT.cpp"
    //====================================================================================    
    
    //######################################################################################################
    //====================================================================================
    #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_INIT.cpp"
    //====================================================================================      
    //-------------------------------
    //====================================================================================    
    
    
    //====================================================================================
    #include "_MODEL_FOLDERS_/marc/marc_INIT.cpp"
    //====================================================================================
    //#include "_MODEL_FOLDERS_/ROOMS/ROOM_01/room_01_softDiffuse/room_01_softDiffuse_INIT.cpp"

    #include "_MODEL_FOLDERS_/ROOMS/room_01/BEAMS_01_A/BEAMS_01_A_INIT.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/BEAMS_01_B/BEAMS_01_B_INIT.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/BEAMS_01_C/BEAMS_01_C_INIT.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/TILES_01_BOTTOM/TILES_01_BOTTOM_INIT.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/TILES_01_TOP/TILES_01_TOP_INIT.cpp"
    //=================================================================================
    //=================================================================================
    #include "_MODEL_FOLDERS_/backGround/backGround_INIT.cpp"
