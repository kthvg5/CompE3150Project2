/*maps for maze
key:
W: Wall, Represented by a solid light
R: Right is the quickest way to goal, Represented by no light
L: Left is the quickest way to goal, Represented by no light
U: Up is the quickest way to goal, Represented by no light
D: Down is the quickest way to goal, Represented by no light
G: goal, Represented by a blinking light
*/

/*
map 1, 5x5:
WWWWWWW
WWWWWWW
WRRDWWW
WWWDWWW
WWWDWWW
WWWGWWW
WWWWWWW
*/
code /*const*/ char map1[7][7] = {
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'D', 'D', 'R', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'R', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'R', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'G', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' }
};
/*const*/ unsigned char M1startX = 2;
/*const*/ unsigned char M1startY = 1;

//coordinate system is mirrored across XY axis, flip board around to see
//without changing the map, just swap the X and Y in the the redraw, function, and maybe everything else (apply fixes invrementally)

/*
map 2 5x5
WWWWWWW
WDWWDWW
WRRDLLW
WWWDWWW
WWRRRDW
WRUWWGW
WWWWWWW
*/
code /*const*/ char map2[7][7] = {
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'R', 'W', 'W', 'R', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'D', 'D', 'R', 'U', 'U', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'R', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'D', 'D', 'D', 'R', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'D', 'L', 'W', 'W', 'G', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W', 'W', 'W', 'W' }
};
/*const*/ unsigned char M2startX = 1;
/*const*/ unsigned char M2startY = 1;

/*
map 3 10x10
WWWWWWWWWWWW
WDLLLLWWWWWW
WDWUWWWRRRGW
WDWWWDWUWWWW
WRRDLLWUWDWW
WUWDWWWULLWW
WWWRRDWWWULW
WWRUWRDWRUWW
WWWUWWRRUWWW
WWRRLWUWULWW
WWUWWWULUWWW
WWWWWWWWWWWW
*/
code /*const*/ char map3[12][12] = {
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
	{ 'W', 'R', 'U', 'U', 'U', 'U', 'W', 'W', 'W', 'W', 'W', 'W' },
	{ 'W', 'R', 'W', 'L', 'W', 'W', 'W', 'D', 'D', 'D', 'G', 'W' },
	{ 'W', 'R', 'W', 'W', 'W', 'R', 'W', 'L', 'W', 'W', 'W', 'W' },
	{ 'W', 'D', 'D', 'R', 'U', 'U', 'W', 'L', 'W', 'R', 'W', 'W' },
	{ 'W', 'L', 'W', 'R', 'W', 'W', 'W', 'L', 'U', 'U', 'W', 'W' },
	{ 'W', 'W', 'W', 'D', 'D', 'R', 'W', 'W', 'W', 'L', 'U', 'W' },
	{ 'W', 'W', 'D', 'L', 'W', 'D', 'R', 'W', 'D', 'L', 'W', 'W' },
	{ 'W', 'W', 'W', 'L', 'W', 'W', 'D', 'D', 'L', 'W', 'W', 'W' },
	{ 'W', 'W', 'D', 'D', 'U', 'W', 'L', 'W', 'L', 'U', 'W', 'W' },
	{ 'W', 'W', 'L', 'W', 'W', 'W', 'L', 'U', 'L', 'W', 'W', 'W' },
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' }
	};
	/*const*/ unsigned char M3startX = 2;
	/*const*/ unsigned char M3startY = 10;
