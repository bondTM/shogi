typedef struct {
	char piece;		//駒の種類
	char owner;		//駒の所有者
	char isChosen;	//駒が選択されているか
} square;

void init(square initSq[9][9]);