extends Node2D


func _ready():
	pass

func _process(delta):
	$CanvasLayer/Sprite.visible = Global.open_camera
