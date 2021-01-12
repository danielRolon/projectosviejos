///scrMoveIsExist(x, y, obj);

var numX = argument0;
var numY = argument1;
var objCheck = argument2;

if (instance_exists(objCheck))
{
    objCheck.x = numX;
    objCheck.y = numY;
}
