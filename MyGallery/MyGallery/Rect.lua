
local width=50;
local height=100;

function init(drawing)
	Drawing.add(drawing,"¿í¶È",width);
	Drawing.add(drawing,"¸ß¶È",height);
end

function clac()
	local Rect_obj = Geometry.create_polyline()
	Geometry.set_start(Rect_obj,0,0);
	Geometry.insert_node(Rect_obj,width,0);
	Geometry.insert_node(Rect_obj,width,height);
	Geometry.insert_node(Rect_obj,0,height);
	Geometry.insert_node(Rect_obj,0,0);

	local cadgroup=Geometry.create_cadgroup();
	Geometry.emplace(cadgroup,Rect_obj);

	return cadgroup;
end

function valid()
	--todo ...
end

function draw()
	--todo ...
end