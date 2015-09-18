

     if(gaussianBlur_9x_Horizontal_SHADER != 0)
     {
         glDeleteProgram(gaussianBlur_9x_Horizontal_SHADER); 
         gaussianBlur_9x_Horizontal_SHADER = 0;
     }     
     //------------------------------------------------
     if(gaussianBlur_9x_Vertical_SHADER != 0)
     {
         glDeleteProgram(gaussianBlur_9x_Vertical_SHADER); 
         gaussianBlur_9x_Vertical_SHADER = 0;
     }
