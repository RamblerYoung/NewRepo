
local width=50;
local height=100;
local hole_width=50;
local hole_height=10;
local left_margin=20;
local bottom_margin = 5;

function init(drawing)
	Drawing.add(drawing,"���",width);
	Drawing.add(drawing,"�߶�",height);
	Drawing.add(drawing,"�ڿ׿��",hole_width);
	Drawing.add(drawing,"�ڿ׸߶�",hole_height);
	Drawing.add(drawing,"�ڿ���߾�",left_margin);
	Drawing.add(drawing,"�ڿ��±߾�",bottom_margin);
end

function clac()
	local rect_obj = Geometry.create_polyline()
	Geometry.set_start(rect_obj,0,0);
	Geometry.insert_node(rect_obj,width,0);
	Geometry.insert_node(rect_obj,width,height);
	Geometry.insert_node(rect_obj,0,height);
	Geometry.insert_node(rect_obj,0,0);

	local hole_obj=Geometry.create_polyline();
	Geometry.set_start(hole_obj,left_margin,bottom_margin);
	Geometry.insert_node(hole_obj,left_margin+hole_width,bottom_margin);
	Geometry.insert_node(hole_obj,left_margin+hole_width,bottom_margin+hole_height);
	Geometry.insert_node(hole_obj,left_margin,bottom_margin+hole_height);
	Geometry.insert_node(hole_obj,left_margin,bottom_margin);

	local cadgroup=Geometry.create_cadgroup();
	Geometry.emplace(cadgroup,rect_obj);
	Geometry.emplace(cadgroup,hole_obj);

	return cadgroup;
end

function valid()
	--todo ...
end

function draw()
	--todo ...
end