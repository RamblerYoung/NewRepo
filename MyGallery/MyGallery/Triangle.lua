
local width=100;
local height=70;
local peak=80;

function init(drawing)
	Drawing.add(drawing,"底边长度",width);
	Drawing.add(drawing,"高度",height);
	Drawing.add(drawing,"峰值点",peak);
end

function clac()
	local triangle_obj = Polyline.create()
	Polyline.set_start(triangle_obj,0,0);
	Polyline.add_node(triangle_obj,width,0);
	Polyline.add_node(triangle_obj,peak,height);
	Polyline.add_node(triangle_obj,0,0);
	return triangle_obj;
end

function valid()
	--todo ...
end

function draw()
	--todo ...
end