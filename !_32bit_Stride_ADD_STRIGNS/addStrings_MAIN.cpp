
#include <cmath>
#include <cstring>
#include <limits>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


bool runOnceForThisModel = true;


int main(int argc, char* argv[])
{

std::string passFilename;

if(argv[1] != NULL)
{
     passFilename = argv[1];


//========================================================================================================
ifstream inModelIsWritten("modelIsWritten.c");

    std::string s0, line0;
    while(getline(inModelIsWritten, line0))
    {
          s0 += line0;
    }
    if(s0 == passFilename)
    {
         runOnceForThisModel = false;
    }
//========================================================================================================

if(runOnceForThisModel)
{
    //========================================================================================================
    ifstream inGLOBALS("../GLOBALS.cpp");
    string s1, line1;
    while(getline(inGLOBALS, line1))
    {
          s1 += line1 + "\n";
    }
    //-------------------------------------------------
    ofstream outGlobals("../GLOBALS.cpp");
    outGlobals << s1 << "\n";
    
    outGlobals << "    //================================================================================="    << "\n";      
    outGlobals << "    #include \"_MODEL_FOLDERS_/" << passFilename << "/" << passFilename << "_GLOBALS.cpp\"" << "\n";
    //=========================================================================================================
    //=========================================================================================================
    ifstream inINIT("../INITIALIZE.cpp");
    string s2, line2;
    while(getline(inINIT, line2))
    {
          s2 += line2 + "\n";
    }
    //-------------------------------------------------
    ofstream outINIT("../INITIALIZE.cpp");
    outINIT << s2 << "\n";
    
    outINIT << "    //================================================================================="       << "\n";      
    outINIT << "    #include \"_MODEL_FOLDERS_/" << passFilename << "/"  << passFilename << "_INIT.cpp\""      << "\n";
    //=========================================================================================================
    //=========================================================================================================
    ifstream inRUNDEPTH("../runDepth_FBO.cpp");
    string s3, line3;
    while(getline(inRUNDEPTH, line3))
    {
          s3 += line3 + "\n";
    }
    //-------------------------------------------------
    ofstream outRUNDEPTH("../runDepth_FBO.cpp");
    outRUNDEPTH << s3 << "\n";
    
    outRUNDEPTH << "    //================================================================================="         << "\n";      
    outRUNDEPTH << "    #include \"_MODEL_FOLDERS_/" << passFilename << "/"  << passFilename << "_SHADOW_00.cpp\""   << "\n";
    //=========================================================================================================
    //=========================================================================================================
    ifstream inDRAWMAIN("../drawMainColor_FBO.cpp");
    string s4, line4;
    while(getline(inDRAWMAIN, line4))
    {
          s4 += line4 + "\n";
    }
    //-------------------------------------------------
    ofstream outDRAWMAIN("../drawMainColor_FBO.cpp");
    outDRAWMAIN << s4 << "\n";

    outDRAWMAIN << "    //================================================================================="    << "\n";      
    outDRAWMAIN << "    #include \"_MODEL_FOLDERS_/" << passFilename << "/" << passFilename << "_RENDER.cpp\""  << "\n";
    //=========================================================================================================
    //=========================================================================================================
    ifstream inSHUTDOWN("../SHUTDOWN.cpp");
    string s5, line5;
    while(getline(inSHUTDOWN, line5))
    {
          s5 += line5 + "\n";
    }
    //-------------------------------------------------
    ofstream outSHUTDOWN("../SHUTDOWN.cpp");
    outSHUTDOWN << s5 << "\n";
    
    outSHUTDOWN << "    //================================================================================="        << "\n";   
    outSHUTDOWN << "    #include \"_MODEL_FOLDERS_/" << passFilename << "/"  << passFilename << "_SHUTDOWN.cpp\""   << "\n";
    //=========================================================================================================

}//if(runOnceForThisModel)


}//_END--> if(argv[1] != NULL)

//==============================================================================

}



















