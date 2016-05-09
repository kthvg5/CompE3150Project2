//This map will primarily be used for testing and will be the easy level
/*

map:
WWWWWWW
WWWWWWW
WRRDWWW
WWWDWWW
WWWDWWW
WWWGWWW
WWWWWWW

key:
W: Wall, Represented by a solit light
R: Right is the quickest way to goal, Represented by no light
L: Left is the quickest way to goal, Represented by no light
U: Up is the quickest way to goal, Represented by no light
D: Down is the quickest way to goal, Represented by no light
G: goal, Represented by a blinking light
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
