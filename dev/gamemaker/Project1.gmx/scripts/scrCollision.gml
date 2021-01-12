///scrCollision(VX, VY, Obj, Mask, Solid);
    
var numVX    = argument0;
var numVY    = argument1;
var insObj   = argument2;
var insMask  = argument3;
var insSolid = argument4;

//Collision X
if (collision_line(insMask.x, insMask.y, insMask.x + numVX, insMask.y, insSolid, false, false))
{
    while(!place_meeting(insMask.x + sign(numVX), insMask.y, insSolid))
    {
        insObj.x += sign(numVX);
        insMask.x += sign(numVX);
    }
    numVX = 0;
}

//Collision Y
if (collision_line(insMask.x, insMask.y, insMask.x, insMask.y + numVY, insSolid, false, false))
{
    while(!place_meeting(insMask.x, insMask.y + sign(numVY), insSolid))
    {
        insObj.y += sign(numVY);
        insMask.y += sign(numVY);
    }
    numVY = 0;
}

numVel[0] = numVX;
numVel[1] = numVY;

return numVel;
