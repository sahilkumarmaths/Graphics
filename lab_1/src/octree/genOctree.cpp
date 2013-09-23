#include<iostream>
#include<string>
using namespace std;
string getTabs(int n){
	string tabs = "";
	for(int i = 0;i<n;i++)
		tabs+='\t';
	return tabs;
}

string octree(int level, int maxLevel){
	string retVal = "";
	if(level == maxLevel){
		retVal = getTabs(level) + "\"10001110\"\n";
	}
	else{
		retVal = 
			getTabs(level) + "\"2\"" + "\n" + octree((level + 1),maxLevel) +
			getTabs(level) + "\"0\"" + "\n" +
			getTabs(level) + "\"0\"" + "\n" +
			getTabs(level) + "\"0\"" + "\n" +
			getTabs(level) + "\"1\"" + "\n" +
			getTabs(level) + "\"2\"" + "\n" + octree((level + 1),maxLevel) +
			getTabs(level) + "\"2\"" + "\n" + octree((level + 1),maxLevel) +
			getTabs(level) + "\"0\"" + "\n";
	}
		return retVal;
}

int main()
{
	cout<< octree(1,4);
}



