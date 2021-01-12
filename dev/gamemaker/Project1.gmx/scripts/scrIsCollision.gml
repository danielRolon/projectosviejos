///scrIsCollision(vx, vy, obj);

var numVX    = argument0;
var numVY    = argument1;
var objCheck = argument2;

// Collision X
if (collision_line(x, y, x + numVX, y, objCheck, false, false))
{
    while(!place_meeting(x + sign(numVX), y, objCheck))
    {
        x += sign(numVX);
    }
    numVX = 0;
}

/*// Collision Y
if (collision_line(x, y, x, y + numVY, objCheck, false, false))
{
    while(!place_meeting(x, y + sign(numVY), objCheck))
    {
        Y += sign(numVY);
    }
    numVY = 0;
};*/

arrTransform[0] = numVX;
arrTransform[1] = numVY;

return arrTransform;


