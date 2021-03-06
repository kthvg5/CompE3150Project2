/*maps for maze
key:
W: Wall, Represented by a solit light
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
char map1[7][7] = {
  {'W','W','W','W','W','W', 'W'} ,
  {'W','W','W','W','W','W', 'W'} ,
  {'W','R','R','D','W','W', 'W'} ,
  {'W','W','W','D','W','W', 'W'} ,
  {'W','W','W','D','W','W', 'W'} ,
  {'W','W','W','G','W','W', 'W'} ,
  {'W','W','W','W','W','W', 'W'} ,
}
int M1startX = 1;
int M1startY = 2;

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
char map2[7][7] = {
  {'W','W','W','W','W','W', 'W'} ,
  {'W','D','W','W','D','W', 'W'} ,
  {'W','R','R','D','L','L', 'W'} ,
  {'W','W','W','D','W','W', 'W'} ,
  {'W','W','R','R','R','D', 'W'} ,
  {'W','R','U','W','W','G', 'W'} ,
  {'W','W','W','W','W','W', 'W'} ,
}
int M2startX = 1;
int M2startY = 1;

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
char map3[12][12] = {
  {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'D', 'L', 'L', 'L', 'L', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'D', 'W', 'U', 'W', 'W', 'W', 'R', 'R', 'R', 'G', 'W'},
  {'W', 'D', 'W', 'W', 'W', 'D', 'W', 'U', 'W', 'W', 'W', 'W'},
  {'W', 'R', 'R', 'D', 'L', 'L', 'W', 'U', 'W', 'D', 'W', 'W'},
  {'W', 'U', 'W', 'D', 'W', 'W', 'W', 'U', 'L', 'L', 'W', 'W'},
  {'W', 'W', 'W', 'R', 'R', 'D', 'W', 'W', 'W', 'U', 'L', 'W'},
  {'W', 'W', 'R', 'U', 'W', 'R', 'D', 'W', 'R', 'U', 'W', 'W'},
  {'W', 'W', 'W', 'U', 'W', 'W', 'R', 'R', 'U', 'W', 'W', 'W'},
  {'W', 'W', 'R', 'R', 'L', 'W', 'U', 'W', 'U', 'L', 'W', 'W'},
  {'W', 'W', 'U', 'W', 'W', 'W', 'U', 'L', 'U', 'W', 'W', 'W'),
  {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'),
}
int M3startX = 2;
int M3startY = 10;
