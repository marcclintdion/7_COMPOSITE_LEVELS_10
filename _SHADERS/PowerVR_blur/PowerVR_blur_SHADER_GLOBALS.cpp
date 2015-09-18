//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
var         PowerVR_blur_LIGHT_POSITION_01[]     =  {  0.0, 0.0, 7.10018, 1};

GLfloat      TexelOffsetX_PowerVR_blur;
GLfloat      TexelOffsetY_PowerVR_blur;

#ifdef __APPLE__
GLfloat      adjustBlurOffset = 0.5;
#endif
#ifdef WIN32
GLfloat      adjustBlurOffset = 1.5;
#endif


GLfloat      adjustShadowPos[]  =  {-0.0004, 0.0004};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	float m_fTexelOffset;

	// Altered weights for the faster filter kernel
	float w1 = 0.0555555f;
	float w2 = 0.2777777f;
    float intraTexelOffset;

    float horizontalBlur_X;
    float horizontalBlur_Y;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//=====================================================================================
GLuint      PowerVR_blur_SHADER_VERTEX;                                                                                 
GLuint      PowerVR_blur_SHADER_FRAGMENT;                                                                               
GLuint      PowerVR_blur_SHADER;     
//-------------------------------------------------------------------------------------
GLuint      UNIFORM_TexelOffsetX_PowerVR_blur;
GLuint      UNIFORM_TexelOffsetY_PowerVR_blur;

GLuint      UNIFORM_adjustShadowPos_PowerVR_blur;
//-------------------------------------------------------------------------------------

GLuint      UNIFORM_TEXTURE_PowerVR_blur;
