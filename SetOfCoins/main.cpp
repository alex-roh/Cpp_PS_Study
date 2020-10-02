#include <iostream>
#include <string>

using namespace std;

int cents[5] = {1, 5, 10, 25, 50};
bool paths[5];
int amount;
static int count;

void findSetOfCoins(int level){
	
	if(level > 4){
		cout << ++count << ": " << amount << "\n";
		for(int i = 0; i < 5; i++){
			if(paths[i]) cout << cents[i] << " ";
			else cout << "0" << " ";
		}
		cout << "\n";
		return;
	}
	else{
		paths[level] = true;
		amount += cents[level];
		findSetOfCoins(level + 1);
		paths[level] = false;
		amount -= cents[level];
		findSetOfCoins(level + 1);
	}
}

int main(int argc, char** argv) 
{
	findSetOfCoins(0);
	return 0;
}
