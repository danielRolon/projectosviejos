///scrApproach(start, end, increment);

var numStart     = argument0;
var numEnd       = argument1;
var numIncrement = argument2;

if (numStart < numEnd)
    return min(numStart + numIncrement, numEnd);
else
    return max(numStart - numIncrement, numEnd);