extends Node2D

var bolPuerta = true;

export (int) var numFrame;

func _ready():
	$spr.frame = numFrame;
	
	if numFrame == 1:
		$btn_up.position.x += 78
		$btn_up.position.y -= 1
		$btn_up.scale.x    = -1
		global_position.x = 80
	
func _process(delta):
	$spr.visible = bolPuerta;

func _on_btn_up_input_event(viewport, event, shape_idx):
	if event is InputEventMouseButton:
		if event.is_pressed():
			bolPuerta = !bolPuerta;
