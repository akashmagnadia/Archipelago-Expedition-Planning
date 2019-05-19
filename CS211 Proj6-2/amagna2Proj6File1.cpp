#include "amagna2Proj6.h"

class ArchipelagoExpedition
{
private:
	// Create the Data Members for the Archipelago Network here
	int size;
	MyList* islands;
	MyList File;
	int* num;
	bool* visited;

public:

	// Use a constructor to initialize the Data Members for your expedition
	ArchipelagoExpedition()
	{
		size = 10;
		islands = new MyList[size];
		visited = new bool[size];
		num = new int[size];
		File = *new MyList;
	}


	// The main loop for reading in input
	void processCommandLoop(FILE* inFile)
	{
		char  buffer[300];
		char* input;

		input = fgets(buffer, 300, inFile);   // get a line of input

		// loop until all lines are read from the input
		while (input != NULL)
		{
			// process each line of input using the strtok functions 
			char* command;
			command = strtok(input, " \n\t");

			printf("*%s*\n", command);

			if (command == NULL)
				printf("Blank Line\n");

			else if (strcmp(command, "q") == 0) {
				islands->removeAll();
				File.removeAllFile();
				exit(1);
			}

			else if (strcmp(command, "?") == 0)
				showCommands();

			else if (strcmp(command, "t") == 0)
				doTravel();

			else if (strcmp(command, "r") == 0)
				doResize();

			else if (strcmp(command, "i") == 0)
				doInsert();

			else if (strcmp(command, "d") == 0)
				doDelete();

			else if (strcmp(command, "l") == 0)
				doList();

			else if (strcmp(command, "f") == 0)
				doFile();

			else if (strcmp(command, "#") == 0)
				;

			else
				printf("Command is not known: %s\n", command);

			input = fgets(buffer, 300, inFile);   // get the next line of input

		}
	}

	void showCommands()
	{
		printf("The commands for this project are:\n");
		printf("  q \n");
		printf("  ? \n");
		printf("  # \n");
		printf("  t <int1> <int2> \n");
		printf("  r <int> \n");
		printf("  i <int1> <int2> \n");
		printf("  d <int1> <int2> \n");
		printf("  l \n");
		printf("  f <filename> \n");
	}

	void doTravel()
	{
		int val1 = 0;
		int val2 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		// get another integer value from the input
		next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}


		printf("Performing the Travel Command from %d to %d\n",
			val1, val2);

		depthFirstSearchHelper(val1, val2);
	}

	void doResize()
	{
		int val1 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}
		if (val1 <= 0) {
			printf("Value is supposed to be greater than 0");
			return;
		}

		printf("Performing the Resize Command with %d\n", val1);

		for (int i = 0; i < size; i++) {
			islands[i].setEmpty();
		}

		if (val1 > size) {
			islands->removeAll();
			size = val1;
			islands = new MyList[size];
			visited = new bool[size];
			num = new int[size];
			return;
		}

		//just in case
		while (val1 > size) {
			MyList* islands2 = new MyList[val1];
			bool* visited2 = new bool[val1];
			int* num2 = new int[val1];
			for (int i = 0; i < val1; i++) {
				islands[i] = *new MyList();
				visited2[i] = *new bool;
				num2[i] = *new int;
				num2[i] = -1;
			}

			islands = islands2;
			visited = visited2;
			num = num2;
			size = val1;
		}

		size = val1; //experimental
	}

	void doInsert()
	{
		int val1 = 0;
		int val2 = 0;

		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		if (val1 > size || val1 - 1 < 0) {
			printf("%d island is out of range\n", val1);
			return;
		}

		if (val2 > size || val2 - 1 < 0) {
			printf("%d island is out of range\n", val2);
			return;
		}

		if (islands[val1 - 1].contains(val2)) {
			printf("%d island already exist\n", val2);
			return;
		}

		printf("Making a bridge between Island %d and Island %d\n", val1, val2);
		islands[val1 - 1].insert(val2);
		islands[val1 - 1].setVisited(true);
	}

	void doDelete()
	{
		int val1 = 0;
		int val2 = 0;

		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		if (val1 > size || val1 - 1 < 0) {
			printf("%d island is out of range\n", val1);
			return;
		}

		if (val2 > size || val2 - 1 < 0) {
			printf("%d island is out of range\n", val2);
			return;
		}

		printf("Destroying the bridge between Island %d and Island %d\n", val1, val2);
		islands[val1 - 2].remove(val2);
	}

	void doList()
	{
		for (int i = 0; i < size; i++) {
			printf("\nIsland %d: ", i + 1);
			islands[i].show();
		}
	}

	void doFile()
	{
		// get a filename from the input
		char* fname = strtok(NULL, " \n\t");
		if (fname == NULL)
		{
			printf("Filename expected\n");
			return;
		}

		printf("Performing the File command with file: %s\n", fname);

		// next steps:  (if any step fails: print an error message and return ) 
		//  1. verify the file name is not currently in use
		//  2. open the file using fopen creating a new instance of FILE*
		//  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
		//  4. close the file when processCommandLoop() returns

		printf("Working with file: %s\n", fname);
		FILE* inFile;
		if ((inFile = fopen(fname, "r")) == NULL) {
			printf("/nCan't open the file. Be sure to put correct file name. Try once more, but don't mess up again/n");
			fclose(inFile);
			return;
		}

		if (File.containsFile(fname)) {
			printf("You have already used %s before\n", fname);
			return;
		}

		File.insertFile(fname);
		processCommandLoop(inFile);
		fclose(inFile);
		//File.removeFile(fname);
	}

	void depthFirstSearchHelper(int x, int y) {
		for (int i = 0; i < size; i++) {
			visited[i] = false; //set all to islands to unvisited to make sure it is not going in a loop
		}

		if (dfs(x, y) == true) {
			cout << "You can get from island " << x << " to island " << y << " in one or more ferry rides" << endl;
		}
		else {
			cout << "You can NOT get from island " << x << " to island " << y << " in one or more ferry rides" << endl;
		}
	}

	bool dfs(int a, int b) {
		MyNode* temp = islands[a - 1].top();
		while (temp != NULL) {
			if (temp->getNextToIsland() == b) {
				return true;
			}
			if (visited[temp->getNextToIsland() - 1] == false) {
				visited[temp->getNextToIsland() - 1] = true;
				if (dfs(temp->getNextToIsland(), b) == true) {
					return true;
				}
			}
			temp = temp->getNext();
		}
		return false;
	}
};

int main(int argc, char** argv)
{
	// set up the variable inFile to read from standard input
	FILE* inFile = stdin;

	// set up the data needed for the island adjcency list
	ArchipelagoExpedition islandData;

	// call the method that reads and parses the input
	islandData.showCommands();
	printf("\nEnter commands at blank line\n");
	printf("    (No prompts are given because of f command)\n");
	islandData.processCommandLoop(inFile);

	printf("Goodbye\n");
	return 1;
}
