extends Node

# Monsters
var light_left  = false;
var light_right = false;

# Batery
var batery_out    = false;
var batery_count  = 100;
var batery_scaled = 0;

# Camera
var open_camera    = false;
var currentMiniCam = -1;
var maxMiniCams    =  3;
#array
var arrCameras = [-1, 0, -1]

func _ready():
	pass
	
func update_cameras():
	pass
	
func rest_batery(value):
	batery_count -= value;
	
	if batery_count < 0:
		batery_count = 0
		
	batery_scaled = 5 - int(batery_count / 20)
