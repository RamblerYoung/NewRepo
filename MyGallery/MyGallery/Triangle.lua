
local width=100;
local height=70;
local peak=80;

function init(drawing)
	Drawing.add(drawing,"底边长度",width);
	Drawing.add(drawing,"高度",height);
	Drawing.add(drawing,"峰值点",peak);
end

function change(name,value)
	--todo...
end

function clac()
	local triangle_obj = Geometry.create_polyline()
	Geometry.set_start(triangle_obj,0,0);
	Geometry.insert_node(triangle_obj,width,0);
	Geometry.insert_node(triangle_obj,peak,height);
	Geometry.insert_node(triangle_obj,0,0);

	local group_obj=Geometry.create_cadgroup();
	Geometry.emplace(group_obj,triangle_obj);

	return group_obj;
end

function valid()
	--todo ...
end

function draw()
	--todo ...
end