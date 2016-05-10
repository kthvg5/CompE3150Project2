//Looping Code for playing the game
void GameStart(Map[][],Start_x,Start_Y) {
	bool GameOver = false; //reset every new game
	int Play_x = Start_x;	//Load starting positions
	int Play_y = Start_y;
	Redraw_Map(Play_x,Play_y,Map[][])
	int i=0 ,k=0;

	while (GameOver==false) { //This loop plays the game until finished
		while (P2.0==0 || P2.3==0 || P0.1==0 || P0.3==0 || P0.2==0 || P0.0==0 ) { //Check if any input
			//Nothing to do here
		}

		for(i

		//waiting for input
		if (P2.0==0) //Exit Button
			GameOver = false;
		else if (P2.3==0) // Help Button
			Help(Play_x,Play_y,Map[][]);
		else if (P0.1==0)
			Up(Play_x,Play_y,Map[][]);
		else if (P0.3==0)
			Down(Play_x,Play_y,Map[][]);
		else if (P0.2==0)
			Left(Play_x,Play_y,Map[][]);
		else if (P0.0==0)
			Right(Play_x,Play_y,Map[][]);
		//Check if Game Over
		If (Map[Play_x][Play_y]== 'G')
			GameOver = true;
	}
  	return;
}

//Button Actions
//Up button
void Up(Play_x,Play_y,Map[][]) {
	If (Map[Play_x][Play_y-1]!= W) 
		Play_y -= 1;
	Redraw_Map();
	return;
}

//Down
void Down(Play_x,Play_y,Map[][]) {
	If (Map[Play_x][Play_y+1]!= W) 
		Play_y += 1
	Redraw_Map();
	return;
}

//Right 
void Right(Play_x,Play_y,Map[][]) {
	If (Map[Play_x+1][Play_y]!= W) 
		Play_x += 1
	Redraw_Map();
	return;
}

//Left 
void Left(Play_x,Play_y,Map[][]) {
	If (Map[Play_x-1][Play_y]!= W) 
		Play_x -= 1
	Redraw_Map();
	return;
}
//Check if Player is at goal
	
