
local width=50;
local height=100;

function init(drawing)
	Drawing.add(drawing,"¿í¶È",width);
	Drawing.add(drawing,"¸ß¶È",height);
end

function clac()
	local Rect_obj = Polyline.create()
	Polyline.set_start(Rect_obj,0,0);
	Polyline.add_node(Rect_obj,width,0);
	Polyline.add_node(Rect_obj,width,height);
	Polyline.add_node(Rect_obj,0,height);
	Polyline.add_node(Rect_obj,0,0);
	return Rect_obj;
end

function valid()
	--todo ...
end

function draw()
	--todo ...
end