extends Node2D

# Move
var cameraMoveX    = 1
var cameraSpeedX   = 100

func _ready():
	pass
	
func _process(delta):
	cameraMoveX = int(Input.is_action_pressed("Right")) - int(Input.is_action_pressed("Left"))
	$camara.move_local_x(cameraMoveX * cameraSpeedX * delta);


func _on_Area2D_input_event(viewport, event, shape_idx):
	if event is InputEventMouseButton:
		if event.is_pressed():
			Global.open_camera = !Global.open_camera;
