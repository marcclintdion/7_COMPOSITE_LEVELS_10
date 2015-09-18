mainBodyPosition_setSelectionLimit  = 6;
mainBodyPosition_SelectionCount     = 6;


mainBodyPosition_setSelectionLimit  = 6;
mainBodyPosition_SelectionCount     = 6;


setSelectionLimit_HEAD      = 6;
SelectionCount_HEAD         = 6;


setSelectionLimit_TORSO     = 6;
SelectionCount_TORSO        = 6;


setSelectionLimit_HIPS      = 6;
SelectionCount_HIPS         = 6;


setSelectionLimit_LEFT_ARM  = 6;
SelectionCount_LEFT_ARM     = 6;


setSelectionLimit_RIGHT_ARM = 6;
SelectionCount_RIGHT_ARM    = 6;


setSelectionLimit_LEFT_LEG  = 6;
SelectionCount_LEFT_LEG     = 6;


setSelectionLimit_RIGHT_LEG = 6;
SelectionCount_RIGHT_LEG    = 6;


if(mainBodyPosition_setSelection == 1)
{
    mainBodyPosition_MOVE_FRAMEA[0]     = 0;
    mainBodyPosition_MOVE_FRAMEA[1]     = -0.00481075;
    mainBodyPosition_MOVE_FRAMEA[2]     = 0;
    mainBodyPosition_MOVE_FRAMEB[0]     = 0;
    mainBodyPosition_MOVE_FRAMEB[1]     = -0.232626;
    mainBodyPosition_MOVE_FRAMEB[2]     = 0;
}
if(setSelection_LEFT_ARM == 1)
{    leftUpperArm_ROTATE_FRAMEA[3]   = -0.212224;
    leftUpperArm_ROTATE_FRAMEA[0]   = 1;
    leftUpperArm_ROTATE_FRAMEA[1]   = 0;
    leftUpperArm_ROTATE_FRAMEA[2]   = 0;
    leftUpperArm_ROTATE_FRAMEB[3]   = 27.0833;
    leftUpperArm_ROTATE_FRAMEB[0]   = 1;
    leftUpperArm_ROTATE_FRAMEB[1]   = 0;
    leftUpperArm_ROTATE_FRAMEB[2]   = 0;
    leftLowerArm_ROTATE_FRAMEA[3]   = 1.05216;
    leftLowerArm_ROTATE_FRAMEA[0]   = 1;
    leftLowerArm_ROTATE_FRAMEA[1]   = 0;
    leftLowerArm_ROTATE_FRAMEA[2]   = 0;
    leftLowerArm_ROTATE_FRAMEB[3]   = -53.7619;
    leftLowerArm_ROTATE_FRAMEB[0]   = 1;
    leftLowerArm_ROTATE_FRAMEB[1]   = 0;
    leftLowerArm_ROTATE_FRAMEB[2]   = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
    leftHand_ROTATE_FRAMEB[3]   = 0;
    leftHand_ROTATE_FRAMEB[0]   = 1;
    leftHand_ROTATE_FRAMEB[1]   = 0;
    leftHand_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_RIGHT_ARM == 1)
{    rightUpperArm_ROTATE_FRAMEA[3]   = -0.150272;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightUpperArm_ROTATE_FRAMEB[3]   = 25.0299;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]   = 1.64454;
    rightLowerArm_ROTATE_FRAMEA[0]   = 1;
    rightLowerArm_ROTATE_FRAMEA[1]   = 0;
    rightLowerArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -55.6033;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEA[3]   = 0;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_LEFT_LEG == 1)
{    leftUpperLeg_ROTATE_FRAMEA[3]   = -0.898558;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[3]   = -59.7257;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 4.03763;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 103.531;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]       = -2.92326;
    leftFoot_ROTATE_FRAMEA[0]       = 1;
    leftFoot_ROTATE_FRAMEA[1]       = 0;
    leftFoot_ROTATE_FRAMEA[2]       = 0;
    leftFoot_ROTATE_FRAMEB[3]       = 1.27181;
    leftFoot_ROTATE_FRAMEB[0]       = 1;
    leftFoot_ROTATE_FRAMEB[1]       = 0;
    leftFoot_ROTATE_FRAMEB[2]       = 0;
}
if(setSelection_RIGHT_LEG == 1)
{    rightUpperLeg_ROTATE_FRAMEA[3]   = -0.66867;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[3]   = -60.7964;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 3.57785;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 106.326;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = -1.34938;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 1.30714;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_HEAD == 1)
{
    head_ROTATE_FRAMEA[3]   = 0.0919041;
    head_ROTATE_FRAMEA[0]   = 0.16;
    head_ROTATE_FRAMEA[1]   = 0.84;
    head_ROTATE_FRAMEA[2]   = 0;
    head_ROTATE_FRAMEB[3]   = -29.2369;
    head_ROTATE_FRAMEB[0]   = 0.92;
    head_ROTATE_FRAMEB[1]   = 0.0799999;
    head_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_TORSO == 1)
{
    torso_ROTATE_FRAMEA[3]   = 1.17786;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
    torso_ROTATE_FRAMEB[3]   = 32.1411;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_HIPS == 1)
{
    hips_ROTATE_FRAMEA[3]   = -0.461568;
    hips_ROTATE_FRAMEA[0]   = 0.16;
    hips_ROTATE_FRAMEA[1]   = 0.84;
    hips_ROTATE_FRAMEA[2]   = 0;
    hips_ROTATE_FRAMEB[3]   = 0;
    hips_ROTATE_FRAMEB[0]   = 0.92;
    hips_ROTATE_FRAMEB[1]   = 0.0799999;
    hips_ROTATE_FRAMEB[2]   = 0;
}
if(mainBodyPosition_setSelection == 2)
{
    mainBodyPosition_MOVE_FRAMEA[0]         = 0;
    mainBodyPosition_MOVE_FRAMEA[1]         = -0.232626;
    mainBodyPosition_MOVE_FRAMEA[2]         = 0;

   if(mainBodyPosition_SelectionCount == 2)
{
   mainBodyPosition_MOVE_FRAMEB[0]          = 0;
   mainBodyPosition_MOVE_FRAMEB[1]          = -0.00481075;
   mainBodyPosition_MOVE_FRAMEB[2]          = 0;
}
     else 
    {
    mainBodyPosition_MOVE_FRAMEB[0]         = 0;
    mainBodyPosition_MOVE_FRAMEB[1]         = 0.450871;
    mainBodyPosition_MOVE_FRAMEB[2]         = 0;
}
}
if(setSelection_LEFT_ARM == 2)
{
    leftUpperArm_ROTATE_FRAMEA[3]     = 27.0833;
    leftUpperArm_ROTATE_FRAMEA[0]     = 1;
    leftUpperArm_ROTATE_FRAMEA[1]     = 0;
    leftUpperArm_ROTATE_FRAMEA[2]     = 0;
    leftLowerArm_ROTATE_FRAMEA[3]      = -53.7619;
    leftLowerArm_ROTATE_FRAMEA[0]      = 1;
    leftLowerArm_ROTATE_FRAMEA[1]      = 0;
    leftLowerArm_ROTATE_FRAMEA[2]      = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_ARM == 2)
    {
    leftUpperArm_ROTATE_FRAMEB[3]     = -0.212224;
    leftUpperArm_ROTATE_FRAMEB[0]     = 1;
    leftUpperArm_ROTATE_FRAMEB[1]     = 0;
    leftUpperArm_ROTATE_FRAMEB[2]     = 0;
    leftLowerArm_ROTATE_FRAMEB[3]      = 1.05216;
    leftLowerArm_ROTATE_FRAMEB[0]      = 1;
    leftLowerArm_ROTATE_FRAMEB[1]      = 0;
    leftLowerArm_ROTATE_FRAMEB[2]      = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
     else 
    {
    leftUpperArm_ROTATE_FRAMEB[3]      = -33.7299;
    leftUpperArm_ROTATE_FRAMEB[0]      = 1;
    leftUpperArm_ROTATE_FRAMEB[1]      = 0;
    leftUpperArm_ROTATE_FRAMEB[2]      = 0;
    leftLowerArm_ROTATE_FRAMEB[3]       = -106.248;
    leftLowerArm_ROTATE_FRAMEB[0]       = 1;
    leftLowerArm_ROTATE_FRAMEB[1]       = 0;
    leftLowerArm_ROTATE_FRAMEB[2]       = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
}
if(setSelection_RIGHT_ARM == 2)
{
    rightUpperArm_ROTATE_FRAMEA[3]   = 25.0299;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]    = -55.6033;
    rightLowerArm_ROTATE_FRAMEA[0]    = 1;
    rightLowerArm_ROTATE_FRAMEA[1]    = 0;
    rightLowerArm_ROTATE_FRAMEA[2]    = 0;
    rightHand_ROTATE_FRAMEA[3]   = 0;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_ARM == 2)
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = -0.150272;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 1.64454;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = -33.1474;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -96.6875;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_LEFT_LEG == 2)
{
    leftUpperLeg_ROTATE_FRAMEA[3]   = -59.7257;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 103.531;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]   = 1.27181;
    leftFoot_ROTATE_FRAMEA[0]   = 1;
    leftFoot_ROTATE_FRAMEA[1]   = 0;
    leftFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_LEG == 2)
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -0.898558;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 4.03763;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -2.92326;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -11.0402;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 21.9053;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = 28.6139;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_LEG == 2)
{
    rightUpperLeg_ROTATE_FRAMEA[3]   = -60.7964;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 106.326;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = 1.30714;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_LEG == 2)
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -0.66867;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 3.57785;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -1.34938;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -12.9054;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 28.2059;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 29.0788;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HEAD == 2)
{
    head_ROTATE_FRAMEA[3]   = -29.2369;
    head_ROTATE_FRAMEA[0]   = 0.92;
    head_ROTATE_FRAMEA[1]   = 0.0799999;
    head_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HEAD == 2)
{
    head_ROTATE_FRAMEB[3]   = 0.0919041;
    head_ROTATE_FRAMEB[0]   = 0.16;
    head_ROTATE_FRAMEB[1]   = 0.84;
    head_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    head_ROTATE_FRAMEB[3]   = -23.546;
    head_ROTATE_FRAMEB[0]   = 1;
    head_ROTATE_FRAMEB[1]   = 0;
    head_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_TORSO == 2)
{
    torso_ROTATE_FRAMEA[3]   = 32.1411;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_TORSO == 2)
{
    torso_ROTATE_FRAMEB[3]   = 1.17786;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    torso_ROTATE_FRAMEB[3]   = 10.6152;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HIPS == 2)
{
    hips_ROTATE_FRAMEA[3]   = 0;
    hips_ROTATE_FRAMEA[0]   = 0.92;
    hips_ROTATE_FRAMEA[1]   = 0.0799999;
    hips_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HIPS == 2)
{
    hips_ROTATE_FRAMEB[3]   = -0.461568;
    hips_ROTATE_FRAMEB[0]   = 0.16;
    hips_ROTATE_FRAMEB[1]   = 0.84;
    hips_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    hips_ROTATE_FRAMEB[3]   = -0.074496;
    hips_ROTATE_FRAMEB[0]   = 1;
    hips_ROTATE_FRAMEB[1]   = 0;
    hips_ROTATE_FRAMEB[2]   = 0;
}
}
if(mainBodyPosition_setSelection == 3)
{
    mainBodyPosition_MOVE_FRAMEA[0]      = 0;
    mainBodyPosition_MOVE_FRAMEA[1]      = 0.450871;
    mainBodyPosition_MOVE_FRAMEA[2]      = 0;

     if(mainBodyPosition_SelectionCount == 3)
    {
    mainBodyPosition_MOVE_FRAMEB[0]      = 0;
    mainBodyPosition_MOVE_FRAMEB[1]      = -0.00481075;
    mainBodyPosition_MOVE_FRAMEB[2]      = 0;
}
     else
    {
    mainBodyPosition_MOVE_FRAMEB[0]      = 0;
    mainBodyPosition_MOVE_FRAMEB[1]      = 0.502531;
    mainBodyPosition_MOVE_FRAMEB[2]      = 0;
}
}
if(setSelection_LEFT_ARM == 3)
{
    leftUpperArm_ROTATE_FRAMEA[3]   = -33.7299;
    leftUpperArm_ROTATE_FRAMEA[0]   = 1;
    leftUpperArm_ROTATE_FRAMEA[1]   = 0;
    leftUpperArm_ROTATE_FRAMEA[2]   = 0;
    leftLowerArm_ROTATE_FRAMEA[3]    = -106.248;
    leftLowerArm_ROTATE_FRAMEA[0]    = 1;
    leftLowerArm_ROTATE_FRAMEA[1]    = 0;
    leftLowerArm_ROTATE_FRAMEA[2]    = 0;
    leftHand_ROTATE_FRAMEA[3] = 0;
    leftHand_ROTATE_FRAMEA[0] = 1;
    leftHand_ROTATE_FRAMEA[1] = 0;
    leftHand_ROTATE_FRAMEA[2] = 0;

     if(SelectionCount_LEFT_ARM == 3)
    {
    leftUpperArm_ROTATE_FRAMEB[3]   = -0.212224;
    leftUpperArm_ROTATE_FRAMEB[0]   = 1;
    leftUpperArm_ROTATE_FRAMEB[1]   = 0;
    leftUpperArm_ROTATE_FRAMEB[2]   = 0;
    leftLowerArm_ROTATE_FRAMEB[3]   = 1.05216;
    leftLowerArm_ROTATE_FRAMEB[0]   = 1;
    leftLowerArm_ROTATE_FRAMEB[1]   = 0;
    leftLowerArm_ROTATE_FRAMEB[2]   = 0;
    leftHand_ROTATE_FRAMEB[3]   = 0;
    leftHand_ROTATE_FRAMEB[0]   = 1;
    leftHand_ROTATE_FRAMEB[1]   = 0;
    leftHand_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    leftUpperArm_ROTATE_FRAMEB[3]   = 29.1057;
    leftUpperArm_ROTATE_FRAMEB[0]   = 1;
    leftUpperArm_ROTATE_FRAMEB[1]   = 0;
    leftUpperArm_ROTATE_FRAMEB[2]   = 0;
    leftLowerArm_ROTATE_FRAMEB[3]   = -97.723;
    leftLowerArm_ROTATE_FRAMEB[0]   = 1;
    leftLowerArm_ROTATE_FRAMEB[1]   = 0;
    leftLowerArm_ROTATE_FRAMEB[2]   = 0;
    leftHand_ROTATE_FRAMEB[3]   = 0;
    leftHand_ROTATE_FRAMEB[0]   = 1;
    leftHand_ROTATE_FRAMEB[1]   = 0;
    leftHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_ARM == 3)
{
    rightUpperArm_ROTATE_FRAMEA[3]   = -33.1474;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]    = -96.6875;
    rightLowerArm_ROTATE_FRAMEA[0]    = 1;
    rightLowerArm_ROTATE_FRAMEA[1]    = 0;
    rightLowerArm_ROTATE_FRAMEA[2]    = 0;
    rightHand_ROTATE_FRAMEA[3] = 0;
    rightHand_ROTATE_FRAMEA[0] = 1;
    rightHand_ROTATE_FRAMEA[1] = 0;
    rightHand_ROTATE_FRAMEA[2] = 0;

     if(SelectionCount_RIGHT_ARM == 3)
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = -0.150272;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 1.64454;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = 11.5929;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -89.8755;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_LEFT_LEG == 3)
{
    leftUpperLeg_ROTATE_FRAMEA[3]   = -11.0402;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 21.9053;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]   = 28.6139;
    leftFoot_ROTATE_FRAMEA[0]   = 1;
    leftFoot_ROTATE_FRAMEA[1]   = 0;
    leftFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_LEG == 3)
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -0.898558;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 4.03763;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -2.92326;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -98.0679;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 126.503;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = 33.9363;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_LEG == 3)
{
    rightUpperLeg_ROTATE_FRAMEA[3]   = -12.9054;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 28.2059;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = 29.0788;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_LEG == 3)
    {
     rightUpperLeg_ROTATE_FRAMEB[3]   = -0.66867;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 3.57785;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -1.34938;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -99.0377;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 122.394;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 26.2318;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HEAD == 3)
{
    head_ROTATE_FRAMEA[3]   = -23.546;
    head_ROTATE_FRAMEA[0]   = 1;
    head_ROTATE_FRAMEA[1]   = 0;
    head_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_HEAD == 3)
    {
    head_ROTATE_FRAMEB[3]   = 0.0919041;
    head_ROTATE_FRAMEB[0]   = 0.16;
    head_ROTATE_FRAMEB[1]   = 0.84;
    head_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    head_ROTATE_FRAMEB[3]   = 0.179396;
    head_ROTATE_FRAMEB[0]   = 1;
    head_ROTATE_FRAMEB[1]   = 0;
    head_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_TORSO == 3)
{
    torso_ROTATE_FRAMEA[3]   = 10.6152;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_TORSO == 3)
    {
    torso_ROTATE_FRAMEB[3]   = 1.17786;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    torso_ROTATE_FRAMEB[3]   = 24.4436;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HIPS == 3)
{
    hips_ROTATE_FRAMEA[3]   = -0.074496;
    hips_ROTATE_FRAMEA[0]   = 1;
    hips_ROTATE_FRAMEA[1]   = 0;
    hips_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_HIPS == 3)
    {
    hips_ROTATE_FRAMEB[3]   = -0.461568;
    hips_ROTATE_FRAMEB[0]   = 0.16;
    hips_ROTATE_FRAMEB[1]   = 0.84;
    hips_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    hips_ROTATE_FRAMEB[3]   = -0.428352;
    hips_ROTATE_FRAMEB[0]   = 1;
    hips_ROTATE_FRAMEB[1]   = 0;
    hips_ROTATE_FRAMEB[2]   = 0;
}
}
if(mainBodyPosition_setSelection == 4)
{
    mainBodyPosition_MOVE_FRAMEA[0]         = 0;
    mainBodyPosition_MOVE_FRAMEA[1]         = 0.502531;
    mainBodyPosition_MOVE_FRAMEA[2]         = 0;

   if(mainBodyPosition_SelectionCount == 4)
{
   mainBodyPosition_MOVE_FRAMEB[0]          = 0;
   mainBodyPosition_MOVE_FRAMEB[1]          = -0.00481075;
   mainBodyPosition_MOVE_FRAMEB[2]          = 0;
}
     else 
    {
    mainBodyPosition_MOVE_FRAMEB[0]         = 0;
    mainBodyPosition_MOVE_FRAMEB[1]         = -0.216982;
    mainBodyPosition_MOVE_FRAMEB[2]         = 0;
}
}
if(setSelection_LEFT_ARM == 4)
{
    leftUpperArm_ROTATE_FRAMEA[3]     = 29.1057;
    leftUpperArm_ROTATE_FRAMEA[0]     = 1;
    leftUpperArm_ROTATE_FRAMEA[1]     = 0;
    leftUpperArm_ROTATE_FRAMEA[2]     = 0;
    leftLowerArm_ROTATE_FRAMEA[3]      = -97.723;
    leftLowerArm_ROTATE_FRAMEA[0]      = 1;
    leftLowerArm_ROTATE_FRAMEA[1]      = 0;
    leftLowerArm_ROTATE_FRAMEA[2]      = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_ARM == 4)
    {
    leftUpperArm_ROTATE_FRAMEB[3]     = -0.212224;
    leftUpperArm_ROTATE_FRAMEB[0]     = 1;
    leftUpperArm_ROTATE_FRAMEB[1]     = 0;
    leftUpperArm_ROTATE_FRAMEB[2]     = 0;
    leftLowerArm_ROTATE_FRAMEB[3]      = 1.05216;
    leftLowerArm_ROTATE_FRAMEB[0]      = 1;
    leftLowerArm_ROTATE_FRAMEB[1]      = 0;
    leftLowerArm_ROTATE_FRAMEB[2]      = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
     else 
    {
    leftUpperArm_ROTATE_FRAMEB[3]      = -3.29594;
    leftUpperArm_ROTATE_FRAMEB[0]      = 1;
    leftUpperArm_ROTATE_FRAMEB[1]      = 0;
    leftUpperArm_ROTATE_FRAMEB[2]      = 0;
    leftLowerArm_ROTATE_FRAMEB[3]       = -9.18912;
    leftLowerArm_ROTATE_FRAMEB[0]       = 1;
    leftLowerArm_ROTATE_FRAMEB[1]       = 0;
    leftLowerArm_ROTATE_FRAMEB[2]       = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
}
if(setSelection_RIGHT_ARM == 4)
{
    rightUpperArm_ROTATE_FRAMEA[3]   = 11.5929;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]    = -89.8755;
    rightLowerArm_ROTATE_FRAMEA[0]    = 1;
    rightLowerArm_ROTATE_FRAMEA[1]    = 0;
    rightLowerArm_ROTATE_FRAMEA[2]    = 0;
    rightHand_ROTATE_FRAMEA[3]   = 0;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_ARM == 4)
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = -0.150272;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 1.64454;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = 9.27059;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -16.2353;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_LEFT_LEG == 4)
{
    leftUpperLeg_ROTATE_FRAMEA[3]   = -98.0679;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 126.503;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]   = 33.9363;
    leftFoot_ROTATE_FRAMEA[0]   = 1;
    leftFoot_ROTATE_FRAMEA[1]   = 0;
    leftFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_LEG == 4)
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -0.898558;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 4.03763;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -2.92326;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -65.519;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 108.024;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -5.94163;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_LEG == 4)
{
    rightUpperLeg_ROTATE_FRAMEA[3]   = -99.0377;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 122.394;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = 26.2318;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_LEG == 4)
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -0.66867;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 3.57785;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -1.34938;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -63.5905;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 110.167;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -10.7072;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HEAD == 4)
{
    head_ROTATE_FRAMEA[3]   = 0.179396;
    head_ROTATE_FRAMEA[0]   = 1;
    head_ROTATE_FRAMEA[1]   = 0;
    head_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HEAD == 4)
{
    head_ROTATE_FRAMEB[3]   = 0.0919041;
    head_ROTATE_FRAMEB[0]   = 0.16;
    head_ROTATE_FRAMEB[1]   = 0.84;
    head_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    head_ROTATE_FRAMEB[3]   = -11.5696;
    head_ROTATE_FRAMEB[0]   = 1;
    head_ROTATE_FRAMEB[1]   = 0;
    head_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_TORSO == 4)
{
    torso_ROTATE_FRAMEA[3]   = 24.4436;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_TORSO == 4)
{
    torso_ROTATE_FRAMEB[3]   = 1.17786;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    torso_ROTATE_FRAMEB[3]   = 21.0777;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HIPS == 4)
{
    hips_ROTATE_FRAMEA[3]   = -0.428352;
    hips_ROTATE_FRAMEA[0]   = 1;
    hips_ROTATE_FRAMEA[1]   = 0;
    hips_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HIPS == 4)
{
    hips_ROTATE_FRAMEB[3]   = -0.461568;
    hips_ROTATE_FRAMEB[0]   = 0.16;
    hips_ROTATE_FRAMEB[1]   = 0.84;
    hips_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    hips_ROTATE_FRAMEB[3]   = -2.99078;
    hips_ROTATE_FRAMEB[0]   = 1;
    hips_ROTATE_FRAMEB[1]   = 0;
    hips_ROTATE_FRAMEB[2]   = 0;
}
}
if(mainBodyPosition_setSelection == 5)
{
    mainBodyPosition_MOVE_FRAMEA[0]         = 0;
    mainBodyPosition_MOVE_FRAMEA[1]         = -0.216982;
    mainBodyPosition_MOVE_FRAMEA[2]         = 0;

   if(mainBodyPosition_SelectionCount == 5)
{
   mainBodyPosition_MOVE_FRAMEB[0]          = 0;
   mainBodyPosition_MOVE_FRAMEB[1]          = -0.00481075;
   mainBodyPosition_MOVE_FRAMEB[2]          = 0;
}
     else 
    {
    mainBodyPosition_MOVE_FRAMEB[0]         = 0;
    mainBodyPosition_MOVE_FRAMEB[1]         = -0.0216484;
    mainBodyPosition_MOVE_FRAMEB[2]         = 0;
}
}
if(setSelection_LEFT_ARM == 5)
{
    leftUpperArm_ROTATE_FRAMEA[3]     = -3.29594;
    leftUpperArm_ROTATE_FRAMEA[0]     = 1;
    leftUpperArm_ROTATE_FRAMEA[1]     = 0;
    leftUpperArm_ROTATE_FRAMEA[2]     = 0;
    leftLowerArm_ROTATE_FRAMEA[3]      = -9.18912;
    leftLowerArm_ROTATE_FRAMEA[0]      = 1;
    leftLowerArm_ROTATE_FRAMEA[1]      = 0;
    leftLowerArm_ROTATE_FRAMEA[2]      = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_ARM == 5)
    {
    leftUpperArm_ROTATE_FRAMEB[3]     = -0.212224;
    leftUpperArm_ROTATE_FRAMEB[0]     = 1;
    leftUpperArm_ROTATE_FRAMEB[1]     = 0;
    leftUpperArm_ROTATE_FRAMEB[2]     = 0;
    leftLowerArm_ROTATE_FRAMEB[3]      = 1.05216;
    leftLowerArm_ROTATE_FRAMEB[0]      = 1;
    leftLowerArm_ROTATE_FRAMEB[1]      = 0;
    leftLowerArm_ROTATE_FRAMEB[2]      = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
     else 
    {
    leftUpperArm_ROTATE_FRAMEB[3]      = -0.955008;
    leftUpperArm_ROTATE_FRAMEB[0]      = 1;
    leftUpperArm_ROTATE_FRAMEB[1]      = 0;
    leftUpperArm_ROTATE_FRAMEB[2]      = 0;
    leftLowerArm_ROTATE_FRAMEB[3]       = 4.73472;
    leftLowerArm_ROTATE_FRAMEB[0]       = 1;
    leftLowerArm_ROTATE_FRAMEB[1]       = 0;
    leftLowerArm_ROTATE_FRAMEB[2]       = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
}
if(setSelection_RIGHT_ARM == 5)
{
    rightUpperArm_ROTATE_FRAMEA[3]   = 9.27059;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]    = -16.2353;
    rightLowerArm_ROTATE_FRAMEA[0]    = 1;
    rightLowerArm_ROTATE_FRAMEA[1]    = 0;
    rightLowerArm_ROTATE_FRAMEA[2]    = 0;
    rightHand_ROTATE_FRAMEA[3]   = 0;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_ARM == 5)
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = -0.150272;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 1.64454;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = -0.676225;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 7.40045;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_LEFT_LEG == 5)
{
    leftUpperLeg_ROTATE_FRAMEA[3]   = -65.519;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 108.024;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]   = -5.94163;
    leftFoot_ROTATE_FRAMEA[0]   = 1;
    leftFoot_ROTATE_FRAMEA[1]   = 0;
    leftFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_LEG == 5)
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -0.898558;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 4.03763;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -2.92326;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -4.04351;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 18.1693;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -13.1547;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_LEG == 5)
{
    rightUpperLeg_ROTATE_FRAMEA[3]   = -63.5905;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 110.167;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = -10.7072;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_LEG == 5)
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -0.66867;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 3.57785;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -1.34938;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -3.00902;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 16.1004;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -6.07219;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HEAD == 5)
{
    head_ROTATE_FRAMEA[3]   = -11.5696;
    head_ROTATE_FRAMEA[0]   = 1;
    head_ROTATE_FRAMEA[1]   = 0;
    head_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HEAD == 5)
{
    head_ROTATE_FRAMEB[3]   = 0.0919041;
    head_ROTATE_FRAMEB[0]   = 0.16;
    head_ROTATE_FRAMEB[1]   = 0.84;
    head_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    head_ROTATE_FRAMEB[3]   = 0.413569;
    head_ROTATE_FRAMEB[0]   = 0.72;
    head_ROTATE_FRAMEB[1]   = 0.28;
    head_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_TORSO == 5)
{
    torso_ROTATE_FRAMEA[3]   = 21.0777;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_TORSO == 5)
{
    torso_ROTATE_FRAMEB[3]   = 1.17786;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    torso_ROTATE_FRAMEB[3]   = 5.30035;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HIPS == 5)
{
    hips_ROTATE_FRAMEA[3]   = -2.99078;
    hips_ROTATE_FRAMEA[0]   = 1;
    hips_ROTATE_FRAMEA[1]   = 0;
    hips_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HIPS == 5)
{
    hips_ROTATE_FRAMEB[3]   = -0.461568;
    hips_ROTATE_FRAMEB[0]   = 0.16;
    hips_ROTATE_FRAMEB[1]   = 0.84;
    hips_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    hips_ROTATE_FRAMEB[3]   = -2.07706;
    hips_ROTATE_FRAMEB[0]   = 0.72;
    hips_ROTATE_FRAMEB[1]   = 0.28;
    hips_ROTATE_FRAMEB[2]   = 0;
}
}
if(mainBodyPosition_setSelection == 6)
{
    mainBodyPosition_MOVE_FRAMEA[0]     = 0;
    mainBodyPosition_MOVE_FRAMEA[1]     = -0.0216484;
    mainBodyPosition_MOVE_FRAMEA[2]     = 0;
    mainBodyPosition_MOVE_FRAMEB[0]     = 0;
    mainBodyPosition_MOVE_FRAMEB[1]     = -0.00481075;
    mainBodyPosition_MOVE_FRAMEB[2]     = 0;
    
    
                                                                  marcJumping    = false;
}
if(setSelection_LEFT_ARM == 6)
{    leftUpperArm_ROTATE_FRAMEA[3]   = -0.955008;
    leftUpperArm_ROTATE_FRAMEA[0]   = 1;
    leftUpperArm_ROTATE_FRAMEA[1]   = 0;
    leftUpperArm_ROTATE_FRAMEA[2]   = 0;
    leftUpperArm_ROTATE_FRAMEB[3]   = -0.212224;
    leftUpperArm_ROTATE_FRAMEB[0]   = 1;
    leftUpperArm_ROTATE_FRAMEB[1]   = 0;
    leftUpperArm_ROTATE_FRAMEB[2]   = 0;
    leftLowerArm_ROTATE_FRAMEA[3]   = 4.73472;
    leftLowerArm_ROTATE_FRAMEA[0]   = 1;
    leftLowerArm_ROTATE_FRAMEA[1]   = 0;
    leftLowerArm_ROTATE_FRAMEA[2]   = 0;
    leftLowerArm_ROTATE_FRAMEB[3]   = 1.05216;
    leftLowerArm_ROTATE_FRAMEB[0]   = 1;
    leftLowerArm_ROTATE_FRAMEB[1]   = 0;
    leftLowerArm_ROTATE_FRAMEB[2]   = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
    leftHand_ROTATE_FRAMEB[3]   = 0;
    leftHand_ROTATE_FRAMEB[0]   = 1;
    leftHand_ROTATE_FRAMEB[1]   = 0;
    leftHand_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_RIGHT_ARM == 6)
{    rightUpperArm_ROTATE_FRAMEA[3]   = -0.676225;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightUpperArm_ROTATE_FRAMEB[3]   = -0.150272;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]   = 7.40045;
    rightLowerArm_ROTATE_FRAMEA[0]   = 1;
    rightLowerArm_ROTATE_FRAMEA[1]   = 0;
    rightLowerArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 1.64454;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEA[3]   = 0;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_LEFT_LEG == 6)
{    leftUpperLeg_ROTATE_FRAMEA[3]   = -4.04351;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[3]   = -0.898558;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 18.1693;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 4.03763;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]       = -13.1547;
    leftFoot_ROTATE_FRAMEA[0]       = 1;
    leftFoot_ROTATE_FRAMEA[1]       = 0;
    leftFoot_ROTATE_FRAMEA[2]       = 0;
    leftFoot_ROTATE_FRAMEB[3]       = -2.92326;
    leftFoot_ROTATE_FRAMEB[0]       = 1;
    leftFoot_ROTATE_FRAMEB[1]       = 0;
    leftFoot_ROTATE_FRAMEB[2]       = 0;
}
if(setSelection_RIGHT_LEG == 6)
{    rightUpperLeg_ROTATE_FRAMEA[3]   = -3.00902;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[3]   = -0.66867;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 16.1004;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 3.57785;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = -6.07219;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -1.34938;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_HEAD == 6)
{
    head_ROTATE_FRAMEA[3]   = 0.413569;
    head_ROTATE_FRAMEA[0]   = 0.72;
    head_ROTATE_FRAMEA[1]   = 0.28;
    head_ROTATE_FRAMEA[2]   = 0;
    head_ROTATE_FRAMEB[3]   = 0.0919041;
    head_ROTATE_FRAMEB[0]   = 0.16;
    head_ROTATE_FRAMEB[1]   = 0.84;
    head_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_TORSO == 6)
{
    torso_ROTATE_FRAMEA[3]   = 5.30035;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
    torso_ROTATE_FRAMEB[3]   = 1.17786;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_HIPS == 6)
{
    hips_ROTATE_FRAMEA[3]   = -2.07706;
    hips_ROTATE_FRAMEA[0]   = 0.72;
    hips_ROTATE_FRAMEA[1]   = 0.28;
    hips_ROTATE_FRAMEA[2]   = 0;
    hips_ROTATE_FRAMEB[3]   = -0.461568;
    hips_ROTATE_FRAMEB[0]   = 0.16;
    hips_ROTATE_FRAMEB[1]   = 0.84;
    hips_ROTATE_FRAMEB[2]   = 0;
}
