//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
GLint getOpenGL_ExtentionValues;
//==============================


bool room_01_IS_ACTIVE = true;
bool room_02_IS_ACTIVE = false;
bool room_03_IS_ACTIVE = false;



GLfloat setPosition[]  = {0.0, 0.0, 0.0, 0.0};

//=======================================================================================================================
        extern GLuint msaaFramebuffer;
        extern GLuint viewRenderbuffer;

        bool iOS_MSAA_IS_ON = true;
        
        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
        #ifdef __APPLE__
               GLuint  viewFramebuffer;
        #endif
          
        //-------------------------------------------------------------------------------


        GLuint m_uiShadowMapTexture;
        GLuint m_uiFrameBufferObject;



//=======================================================================================================================
void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{

        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        //---------------
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
        //---------------
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        #endif
        
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        //----------------
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
        //----------------
        glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif
}
//===============================================================================================================================


var     lightMatrix[16];

var     view[16];
var     view_rotate[16];
var     modelWorld[16];
var     modelView[16];
var     projection[16];

var     modelRotation[16];

var     moveSetMatrix[16];

var     light_modelWorld[16];
var     light_view[16];
var     light_modelView[16];
var     light_projection[16];
var     shadowLight_textureMatrix[16];
var     invertView[16];

var     biasMatrix[] = {0.5, 0.0, 0.0, 0.0, 
                        0.0, 0.5, 0.0, 0.0, 
                        0.0, 0.0, 0.5, 0.0, 
                        0.5, 0.5, 0.5, 1.0};

//============================================================================================================================
var     moveShadowPivot_Z = 0.0;
//============================================================================================================================







//=======================================================================================
GLuint countFrames = 0;

//=======================================================================================

GLfloat       screenRatio;

//=======================================================================================


GLuint        boxCount                                         =  1;
GLuint        selectedModel                                    =  0;     

GLfloat       collisionBoxArray[500][32];                                    
                         
            
//=======================================================================================

var           fieldOfView                                            =     30.0;

//---------------------------------------------------------------------------------------
GLsizei       resize_SHADOW_FBO = 1;
GLsizei       resize_LIGHTS_FBO = 1;


//---------------------------------------------------------------------------------------
var           moveSet[]                                              =  {  0, 0, 0, 0.0};
//---------------------------------------------------------------------------------------

//=============================================================================================
#define eye_POSITION_02   11.157

#ifdef WIN32
var           eyePosition[]                                          =  {  0, 0.0, -eye_POSITION_02, 0.0};

#endif
//--------------
#ifdef __APPLE__
var           eyePosition[]                                          =  {  0, 0.0, -eye_POSITION_02, 0.0};
#endif 
//=============================================================================================
var           eyePosition_SHADOW[]                                   =  {-1.32213, -0.980399, -13.8523 + eye_POSITION_02, 0};

var           adjustNearFar_CAMERA[]                                 =  {  7.07007, 20.0 };
var           adjustNearFar_LIGHT[]                                  =  {  7.07007, 20.0 };
//=============================================================================================
#ifdef WIN32
var           shadow_BIAS                                            =     0.006114;
#endif
//--------------
#ifdef __APPLE__
var           shadow_BIAS                                            =     0.006114*2.0;
#endif 
//=============================================================================================

var           rotateModelWithMiddleMouse[]                           =  {  0.0, 0.0};
var           zoomModelWithMiddleMouse                               =     0.0;
var           moveModelWithMiddleMouse[]                             =  {  0.0, 0.0};
//---------------------------------------------------------------------------------------


//===============================================================================================================
//===============================================================================================================
var           scaleScreenAlignedQuadRatio                            = 0.0;
var           inverseScreenRatio;     
//------------------------------------                       
    #ifdef WIN32
        var         display_00_MOVE[]               =  { -1.0,  1.0,  0.0,  1.0};
    #endif
    //--------------
    #ifdef __APPLE__
        var         display_00_MOVE[]               =  {  1.0,  1.0,  0.0,  1.0};
    #endif
    //--------------------------------
    var             display_00_SCALE[]              =  {  1.0,  1.0,  0.0,  1.0};
//===============================================================================================================
GLuint  configureShader = 12;                      
//===============================================================================================================
//===============================================================================================================
void setupTransforms_MainColor(void)
{
        
        LoadIdentity(view);
        Translate(view,             eyePosition[0], 
                                    eyePosition[1], 
                                    eyePosition[2]);


        //===========================================
        LoadIdentity(invertView);
        InvertMatrix(invertView, view);
        //=============================
        
        LoadIdentity(view_rotate);
        //--------------------   
        Rotate(view_rotate, 1.0, 0.0, 0.0, rotateModelWithMiddleMouse[0]);
        Rotate(view_rotate, 0.0, 1.0, 0.0, rotateModelWithMiddleMouse[1]);        
}
//===============================================================================================================
void setupTransforms_Shadows(void)
{

        LoadIdentity(light_view);
        //-------------------------------------------------
        Translate(light_view,       eyePosition[0] + eyePosition_SHADOW[0],
                                    eyePosition[1] + eyePosition_SHADOW[1],
                                    eyePosition[2] + eyePosition_SHADOW[2]);
        
//LookAt(light_View, eyePosition_SHADOW[0] + eyePosition[0] * scaleViewMovement[0], eyePosition_SHADOW[1], eyePosition_SHADOW[2] ,  0 + eyePosition[0] * scaleViewMovement[0], 0, 0, 0.0f, 1.0f, 0.0f);

}

//===============================================================================================================
//---------------------------------------------------------------------------------------------------------------                     
//===============================================================================================================
        
GLsizei scaleFrameBufferPlaneViewPort = 1;
        
    //#####################################__FBO__#######################################################          
    //=====================================================================================================      
    //#include "_SHADERS/drawMainColor_FBO/drawMainColor_FBO_GLOBALS.cpp"
    //=====================================================================================================
    #include    "_SHADERS/drawMainColor_PRIMARY_FBO/drawMainColor_PRIMARY_FBO_GLOBALS.cpp"
    //=====================================================================================================

    //#include "_SHADERS/hardEdgeShadow_FBO/hardEdgeShadow_FBO_GLOBALS.cpp"
    //=====================================================================================================
    #include "_SHADERS/generic_FBO/generic_FBO_GLOBALS.cpp"
    //=====================================================================================================
    #include "_SHADERS/softDiffuse_FBO/softDiffuse_FBO_GLOBALS.cpp"
    //=====================================================================================================
    //#####################################__SHADERS__#####################################################
    //=====================================================================================================
    //#include    "_SHADERS/SHADOWS/flatten_3D_shadow_SHADER_GLOBALS.cpp"//_FOR_USE_AS_A_MASK
    //=====================================================================================================
    #include "_SHADERS/finalComposite/finalComposite_SHADER_GLOBALS.cpp"
    //=====================================================================================================
    #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_GLOBALS.cpp"
    //=====================================================================================================
    //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_SHADER_GLOBALS.cpp"
    //=====================================================================================================
    #include "_SHADERS/copyFBO/copyFBO_SHADER_GLOBALS.cpp"
    //====================================================================================     
    #include "_SHADERS/PowerVR_blur/PowerVR_blur_SHADER_GLOBALS.cpp"
    //====================================================================================
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        
    //====================================================================================
    #include "_SHADERS/baseRoom/baseRoom_SHADER_GLOBALS.cpp"
    //====================================================================================
    //#include "_SHADERS/softDiffuse_SHADER/softDiffuse_SHADER_GLOBALS.cpp"
    //====================================================================================                                 
    #include "_SHADERS/basic/basic_SHADER_GLOBALS.cpp"
    //====================================================================================   
    #include "_SHADERS/sky/sky_SHADER_GLOBALS.cpp"
    //====================================================================================       
                                 
    //#####################################__MODELS__#######################################################
    //=========================================================================
    #include    "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GLOBALS.cpp"
    //=================================================================================    
    //--------------------------------------
    //=================================================================================
    #include "_MODEL_FOLDERS_/marc/marc_GLOBALS.cpp"
    //=================================================================================    
    
    //====================================================================================================================     
    //#include "_MODEL_FOLDERS_/ROOMS/room_01/room_01_softDiffuse/room_01_softDiffuse_GLOBALS.cpp"
    

    

    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/BEAMS_01_A/BEAMS_01_A_GLOBALS.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/BEAMS_01_B/BEAMS_01_B_GLOBALS.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/BEAMS_01_C/BEAMS_01_C_GLOBALS.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/TILES_01_BOTTOM/TILES_01_BOTTOM_GLOBALS.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/ROOMS/room_01/TILES_01_TOP/TILES_01_TOP_GLOBALS.cpp"
    //=================================================================================
    //=================================================================================
    #include "_MODEL_FOLDERS_/backGround/backGround_GLOBALS.cpp"
