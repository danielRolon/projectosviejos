extends Node2D

export (int) var id;

func _ready():
	pass

func _process(delta):
	if Global.open_camera:
		
		visible = true
		
		var monster_id = Global.arrCameras[id]
		
		if Global.currentMiniCam == id and monster_id != -1:
			$Sprite.visible = true
			$Sprite.frame = monster_id
		else:
			$Sprite.visible = false
	else:
		visible = false
		Global.currentMiniCam = -1
			


func _on_ColorRect_gui_input(event):
	if Global.open_camera:
		if event is InputEventMouseButton:
			if event.is_pressed():
				Global.currentMiniCam = id;
