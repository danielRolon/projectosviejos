///scrNormalizeAngle(angle);

var angle = argument0;

angle = angle % 360;

if (angle < 0)
    angle = angle + 360;

return angle;

