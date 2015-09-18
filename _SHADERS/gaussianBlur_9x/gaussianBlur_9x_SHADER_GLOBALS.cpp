//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#ifdef __APPLE__
                  GLfloat      gaussianBlur_9x_Radius     =   0.000499988*2.0;
#endif
//--------------
#ifdef WIN32
                  GLfloat      gaussianBlur_9x_Radius     =   0.000719988*1.5;
#endif
//==================================================================================== 
GLfloat adjuster = 0.0;

GLuint      gaussianBlur_9x_Horizontal_SHADER_VERTEX;                                                                                                      
GLuint      gaussianBlur_9x_Horizontal_SHADER_FRAGMENT;                                                                                                    
GLuint      gaussianBlur_9x_Horizontal_SHADER;   
//-----------------------------------------------------                              

GLuint      UNIFORM_TEXTURE_gaussianBlur_9x_Horizontal; 
//----------------------------------------------------- 
GLuint      UNIFORM_blurRadius_gaussianBlur_9x_Horizontal;  
GLuint UNIFORM_adjust_gaussianBlur_9x_Horizontal;
//==================================================================================== 


GLuint      gaussianBlur_9x_Vertical_SHADER_VERTEX;                                                                                                      
GLuint      gaussianBlur_9x_Vertical_SHADER_FRAGMENT;                                                                                                    
GLuint      gaussianBlur_9x_Vertical_SHADER;    
//----------------------------------------------------- 

GLuint      UNIFORM_TEXTURE_gaussianBlur_9x_Vertical; 
//----------------------------------------------------- 
GLuint      UNIFORM_blurRadius_gaussianBlur_9x_Vertical; 
GLuint      UNIFORM_screenRatio_gaussianBlur_9x_Vertical;                                                                                                   
GLuint    UNIFORM_adjust_gaussianBlur_9x_Vertical;
//====================================================================================

