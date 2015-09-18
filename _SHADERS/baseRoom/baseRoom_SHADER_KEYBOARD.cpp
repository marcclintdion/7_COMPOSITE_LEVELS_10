if(configureShader == 12)
{
    //==========================================================================================
    if(selectBaseRoomLight == 1)
    {
    //========================== 
        if (keys['D'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
            baseRoom_LIGHT_01_POSITION[0]         +=  0.1404;
        }	
        if (keys['A'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
            baseRoom_LIGHT_01_POSITION[0]         -=  0.1404;
        }
        //-----------
        if (keys['W'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
            baseRoom_LIGHT_01_POSITION[1]         +=  0.1404;
        }
        if (keys['S'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
            baseRoom_LIGHT_01_POSITION[1]         -=  0.1404;       
        } 
        //-----------
        if (keys['E'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_01_POSITION[2]       +=  0.1404;      
        }
        if (keys['Q'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
            baseRoom_LIGHT_01_POSITION[2]         -=  0.1404;
        }
        //====================================================           
        if (keys['M'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            ambient_LIGHT_01_baseRoom           +=   0.01015;
   
        }
        if (keys['N'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            ambient_LIGHT_01_baseRoom           -=   0.01015;

        }  
        //====================================================
        if (keys['B'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            shininess_LIGHT_01_baseRoom           +=   1.0;
   
        }
        if (keys['V'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            shininess_LIGHT_01_baseRoom           -=   1.0;

        }  
        //====================================================    
    
    
    }//if(selectBaseRoomLight == 1)
    //==========================================================================================
    //==========================================================================================    
    if(selectBaseRoomLight == 2)
    {
    //==========================  
        if (keys['D'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[0]   +=  0.1404;
        }	
        if (keys['A'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[0]   -=  0.1404;
        }
        //-----------
        if (keys['W'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[1]   +=  0.1404;
        }
        if (keys['S'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[1]   -=  0.1404;       
        } 
        //-----------
        if (keys['E'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[2]   +=  0.1404;      
        }
        if (keys['Q'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[2]   -=  0.1404;
        }
        //====================================================           
        if (keys['M'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            ambient_LIGHT_02_baseRoom           +=   0.01015;
   
        }
        if (keys['N'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            ambient_LIGHT_02_baseRoom           -=   0.01015;

        }  
        //====================================================
        if (keys['B'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            shininess_LIGHT_02_baseRoom           +=   1.0;
   
        }
        if (keys['V'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            shininess_LIGHT_02_baseRoom           -=   1.0;

        }  
        //====================================================   
    
    }//if(selectBaseRoomLight == 2)
    //==========================================================================================
    //==========================================================================================   
    if(selectBaseRoomLight == 3)
    {
    //========================== 
        if (keys['D'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[0]   +=  0.1404;
        }	
        if (keys['A'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[0]   -=  0.1404;
        }
        //-----------
        if (keys['W'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[1]   +=  0.1404;
        }
        if (keys['S'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[1]   -=  0.1404;       
        } 
        //----------- 
        if (keys['E'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[2]   +=  0.1404;      
        }
        if (keys['Q'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[2]   -=  0.1404;
        }
        //====================================================           
        if (keys['M'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            ambient_LIGHT_03_baseRoom           +=   0.01015;
   
        }
        if (keys['N'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            ambient_LIGHT_03_baseRoom           -=   0.01015;

        }  
        //====================================================
        if (keys['B'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            shininess_LIGHT_03_baseRoom           +=   1.0;
   
        }
        if (keys['V'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
        {
            shininess_LIGHT_03_baseRoom           -=   1.0;

        }  
        //====================================================   
    
    }//if(selectBaseRoomLight == 3)
    //==========================================================================================
    //==========================================================================================   
    if(keys[VK_F8])
    {
         ofstream outSettings("_SHADERS/baseRoom/settings.cpp");
         
         //=================================================================
         outSettings << "var         baseRoom_LIGHT_01_POSITION[]    =  {"   
                                  << baseRoom_LIGHT_01_POSITION[0] << ", "
                                  << baseRoom_LIGHT_01_POSITION[1] << ", "
                                  << baseRoom_LIGHT_01_POSITION[2] << ", "
                                  << baseRoom_LIGHT_01_POSITION[3] << "};\n";            
         //---------------------------------------------------------------------
         outSettings << "var         baseRoom_LIGHT_02_POSITION[]    =  {"   
                                  << baseRoom_LIGHT_02_POSITION[0] << ", "
                                  << baseRoom_LIGHT_02_POSITION[1] << ", "
                                  << baseRoom_LIGHT_02_POSITION[2] << ", "
                                  << baseRoom_LIGHT_02_POSITION[3] << "};\n";            
         //---------------------------------------------------------------------      
         outSettings << "var         baseRoom_LIGHT_03_POSITION[]    =  {"   
                                  << baseRoom_LIGHT_03_POSITION[0] << ", "
                                  << baseRoom_LIGHT_03_POSITION[1] << ", "
                                  << baseRoom_LIGHT_03_POSITION[2] << ", "
                                  << baseRoom_LIGHT_03_POSITION[3] << "};\n\n";            
         //--------------------------------------------------------------------- 
         outSettings << "var         ambient_LIGHT_01_baseRoom       =  "    
                                  << ambient_LIGHT_01_baseRoom        << ";\n";   
         //--------------------------------------------------------------------- 
         outSettings << "var         ambient_LIGHT_02_baseRoom       =  "    
                                  << ambient_LIGHT_02_baseRoom        << ";\n";         
         //--------------------------------------------------------------------- 
         outSettings << "var         ambient_LIGHT_03_baseRoom       =  "    
                                  << ambient_LIGHT_03_baseRoom        << ";\n\n";            
         //--------------------------------------------------------------------- 
         outSettings << "var         shininess_LIGHT_01_baseRoom     =  "    
                                  << shininess_LIGHT_01_baseRoom      << ";\n";   
         //--------------------------------------------------------------------- 
         outSettings << "var         shininess_LIGHT_02_baseRoom     =  "    
                                  << shininess_LIGHT_02_baseRoom      << ";\n";         
         //--------------------------------------------------------------------- 
         outSettings << "var         shininess_LIGHT_03_baseRoom     =  "    
                                  << shininess_LIGHT_03_baseRoom      << ";\n\n";            
          
    
    }//if(keys[VK_F8])
    //==========================================================================================

}//if(configureShader == 12;
