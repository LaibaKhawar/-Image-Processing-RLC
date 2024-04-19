
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;

class Node
{
	Node* next;
	int data;

public:
	Node(int key)
	{
		data = key;
		next = nullptr;
	}
	void setNext(Node* ptr)
	{
		next = ptr;
	}
	void setData(int n)
	{
		data = n;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}
};
class TreeNode {
	int row;
	int col;
	int rowE;
	int colE;
	string color;
	TreeNode* child1;
	TreeNode* child2;
	TreeNode* child3;
	TreeNode* child4;
public:
	TreeNode(int rows, int columns, int rowe, int columne, string color) {
		this->row = rows;
		this->col = columns;
		this->rowE = rowe;
		this->colE = columne;
		this->color = color;
		child1 = nullptr;
		child2 = nullptr;
		child3 = nullptr;
		child4 = nullptr;
	}
	int getRows() {
		return row;
	}
	int getColumns() {
		return col;
	}
	int getRowe() {
		return rowE;
	}
	int getCole() {
		return colE;
	}
	string getColor() {
		return color;
	}
	void setColor(string color) {
		this->color = color;
	}
	TreeNode* getChild3() {
		return child3;
	}
	TreeNode* getChild4() {
		return child4;
	}
	TreeNode* getChild1() {
		return child1;
	}
	TreeNode* getChild2() {
		return child2;
	}
	void setChild1(TreeNode* child) {
		child1 = child;
	}
	void setChild2(TreeNode* child) {
		child2 = child;
	}
	void setChild3(TreeNode* child) {
		child3 = child;
	}
	void setChild4(TreeNode* child) {
		child4 = child;
	}

};
class List {
	Node* head;
	Node* current;
	Node* lastCurrent;
	int size;
public:
	List() {
		head = nullptr;
		current = nullptr;
		lastCurrent = nullptr;
		// lastNode = nullptr;
		size = 0;
	}
	
	Node* getHead()
	{
		return head;
	}
	void add(int num) {
		Node* newNode = new Node(num);
		if (head != nullptr) {
			newNode->setNext(current->getNext());
			current->setNext(newNode); 
			newNode->setData(num);
			lastCurrent = current;
			current = newNode;

		}
		else
		{
			//newNode->setData(num);
			newNode->setNext(nullptr);
			head = newNode;
			lastCurrent = head;
			current = head;

		}
	}
	void displayList() {
		Node* headptr = head;
		while (headptr != nullptr) {
			cout << headptr->getData();
			headptr = headptr->getNext();
			cout << "  ";
		}
	}
};
class Stack
{
	Node* top;
public:
	Stack()
	{
		top = nullptr;
	}
	bool isEmpty()
	{
		if (top == nullptr)
		{
			return 1;
		}
		return 0;
	}
	void push(int key)
	{
		Node* ptr = new Node(key);
		if (isEmpty())
		{
			top = ptr;
		}
		else
		{
			ptr->setNext(top);
			top = ptr;
		}
	}
	Node* pop()
	{
		if (top == nullptr)
		{
			cout << "\n Stack underflow";
			return 0;
		}
		Node* temp = top;
		top = top->getNext();
		return temp;
	}
	void Display()
	{
		Node* temp = top;
		while (temp != nullptr)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
	}
	//void Display()
	//{
		// if (top == nullptr)
		// {
		// 	return;
		// }
		// cout << "Stack elements are: ";
		// while (top != nullptr)
		// {
		// 	cout << top->getData() << " ";
		// 	top = top->getNext();
		// }
	//}
};

class Queue
{
	Node* front;
	Node* rear;

public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}
	void Enqueue(int value)
	{
		// enqueue value
		Node* newnode = new Node(value);
		newnode->setNext(nullptr);
		if (front == nullptr)
		{
			front = newnode;
			rear = newnode;
		}
		else
		{
			rear->setNext(newnode);
			rear = newnode;
		}
	}
	Node* Dequeue()
	{
		if (front == nullptr)
		{
			cout << "Queue's empty now";
		}
		Node* temp = front;
		front = front->getNext();
		return temp;
	}
	bool isEmpty()
	{
		if (front == nullptr)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void Display()
	{
		Node* temp = front;
		if ((front == NULL) && (rear == NULL))
		{
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Queue elements are: ";
		while (temp != NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}
};

class Image
{
	int size;
	int** matrix;
	int rows;
	int cols;
	List* l_x;
	List* l_y;
public:
	Image()
	{
		size = 0;
		rows = 0;
		cols = 0;
		// matrix = nullptr;
		matrix = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			matrix[i] = new int[cols];
		}
		l_x = new List();
		l_y = new List();
	}
	Image(int val)
	{
		size = 0;
		rows = 255;
		cols = 255;
		matrix = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			matrix[i] = new int[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = val;
			}
		}

		l_x = new List();
		l_y = new List();
	}
	void readfile(string filename)
	{
		fstream fin(filename, ios::in);
		string inputLine = " ";
		/*getline(fin, inputLine);
		getline(fin, inputLine);
		getline(fin, inputLine);*/

		fin >> inputLine;
		// cout << inputLine << endl;
		fin >> inputLine;
		// cout << inputLine << endl;
		fin >> inputLine;
		// cout << inputLine << endl;
		fin >> inputLine;
		// cout << inputLine << endl;
		fin >> inputLine;
		// cout << inputLine << endl;
		fin >> inputLine;
		// cout <<"rows are"<<inputLine << endl;
		rows = stoi(inputLine);
		cout << "Rows : " << rows << endl;
		fin >> inputLine;
		// cout << inputLine << endl;
		cols = stoi(inputLine);
		cout << "Cols : " << cols << endl;
		fin >> inputLine;
		// cout << inputLine << endl;
		// fin >> inputLine;*/
		// fin >> rows >> cols;
		// cout << "rows : " << rows << " cols :" << cols << endl;

		// getline(fin, inputLine);

		matrix = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			matrix[i] = new int[cols];
		}
		char char1;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				fin >> char1;
				char1 = int(char1 + 1);
				if (char1 == 0) //(char1 == '�')
					matrix[i][j] = 255;
				else
					matrix[i][j] = 0;
			}
		}
		// for (int i = 0; i < rows; ++i) {
		// 	for (int j = 0; j < cols; ++j) {

		// 		cout << matrix[i][j];
		// 	}
		// 	cout << endl;
		// }
		fin.close();
	}
	/*void Write() {
		ofstream writefile;
		time_t now = time(0);
		char* date_time = ctime(&now);
		string datetime = date_time;
		datetime += ".pgm";
		for (int i = 0; i < datetime.length(); i++)
		{
			if (datetime[i] == '\n' || datetime[i] == ' ' || datetime[i] == ':')
			{
				datetime[i] = '_';
			}
		}
		cout << datetime;
		writefile.open(datetime);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				writefile << matrix[i][j];
			}
			writefile << '\n';
		}
		writefile.close();
	}*/
	void SaveImage()
	{
		ofstream fout("output.txt");
		fout << "P2" << endl;
		fout << "# Created by GIMP PNM Filter Version 1.1" << endl;
		fout << cols << " " << rows << endl;
		fout << "255" << endl;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				fout << matrix[i][j] << " ";
			}
			fout << endl;
		}
		fout.close();
	}
	void ConvertRLC() {
		for(int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == 255) {
					//l_y->add(i);
					l_x->add(j); //enter respective x coordinates
				}
			}
			l_x->add(-1);
		}
		//l_x->displayList(); 
		int j;
		Node* temp = l_x->getHead();
		ofstream fout("RLC.txt");
		fout << "P5" << endl;
		fout << rows <<" "<< cols<<endl;
		while (temp != nullptr) {
			j = temp->getData();
			fout << j<<" ";
			if (j == -1)
			{
				fout << endl;
			}
			

			temp = temp->getNext();
		}
	}
	void ConvertRLCtoPGM() {
		int** matrix2;
		matrix2 = new int* [rows];  //creating a new 2D array
		for (int i = 0; i < rows; ++i)
		{
			matrix2[i] = new int[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix2[i][j] = 0;
			}
		}
		string filename = "RLC.txt";
		fstream fin(filename, ios::in);
		string inputLine = " ";
		fin >> inputLine;
		fin >> inputLine;
		char char2;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				fin >> char2;
				char2 = int(char2 + 1);
				if (i == char2) {
					matrix2[i][j] = 255;
				}
				if (i == -1) {
					continue;
				}
			} 
		}
		Savepgm();
	}
		void Savepgm(){
			ofstream fout("newpgm.txt");
			fout << "P2" << endl;
			//fout << "# Created by GIMP PNM Filter Version 1.1" << endl;
			fout << cols << " " << rows << endl;
			fout << "255" << endl;
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					fout << matrix[i][j] << " ";
				}
				fout << endl;
			}
			fout.close();
		}
		void RLCblackpixcount() {
			string filename = "RLC.txt";
			fstream fin(filename, ios::in);
			string inputLine = " ";
			fin >> inputLine;
			fin >> inputLine;
			char char2;
			int count = 0;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					fin >> char2;
					char2 = int(char2 + 1);
					if(char2 != -1) {
						count=count+1;
					}
					else
						continue;
					}
				}
			cout << "Number of black pixels" << count;
		}
		int GetPixel(int r, int c)
		{
			return matrix[r][c];
		}
	void SetPixel(int pix, int r, int c)
	{ // even after entering correct row n col it is entering 2nd ifstate
		if (r < 0 || r >= rows || c < 0 || c >= cols)
		{
			cout << "Invalid row or column" << endl;
		}
		else
		{
			matrix[r][c] = pix;
		}
	}
	int GetSize()
	{
		return rows * cols;
	}
	
	void ConvertToNegative()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == 255)
				{
					matrix[i][j] = 0;
				}
				else
					matrix[i][j] = 255;
			}
		}
		SaveImage();
		// print matrix
		//  for (int i = 0; i < rows; i++) {
		//  	for (int j = 0; j < cols; j++) {
		//  		cout << matrix[i][j];
		//  	}
		//  	cout << endl;
		//  }
	}
	void Statistic_image()
	{
		// int sum = 0;
		// int sumPix = 0;
		// int whitePix = 0;
		// int blackPix = 0;
		// for (int i = 0; i < rows; i++) {
		// 	for (int j = 0; j < cols; j++) {
		// 		sum += matrix[i][j];
		// 		if (matrix[i][j] == 0) {
		// 			whitePix++;
		// 		}
		// 		else {
		// 			blackPix++;
		// 		}
		// 	}
		// }
		// // blackPix = rows*cols - whitePix;
		// cout << "\nMean number of pixel in image = ";
		// cout << sum / GetSize();
		// cout << endl;
		// cout << " White pixels = " << whitePix << endl;
		// cout << " Black Pixels = "<< blackPix;
		// cout << endl << endl;
		// int count = 0;
		// int len = 0;
		// for(int i=0; i<rows; i++){
		// 	count=0;
		// 	cout << "\nAverage black pixels in " << i << " row = ";
		// 	for (int j = 0; j < cols; j++) {
		// 		if (matrix[i][j] == 255) {
		// 			count++;
		// 		}
		// 	}
		// 	cout << float(count/cols);
		// 	cout<<endl;
		// }
		cout << "\nMean number of pixel in image = ";
		double sum = 0;
		int sumPix = 0;
		int whitePix = 0;
		int blackPix = 0;
		int count = 0;
		int temp = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				sum += matrix[i][j];
				if (matrix[i][j] == 255)
				{
					blackPix++;
					count++;
				}
				temp = count;
			}
			cout << "\nAverage black pixels in " << rows << temp / rows;
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == 0)
				{
					whitePix++;
				}
			}
		}
		cout << sum / GetSize();
		cout << endl;
		cout << "Number of White pixels = " << whitePix;
		cout << "\nNumber of Black pixels = " << blackPix;
	}
	int getRows()
	{
		return rows;
	}
	int getCol()
	{
		return cols;
	}
	int* getrowcolofpix(Node* pix)
	{
		int* array = new int[2];
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				if (matrix[r][c] == pix->getData())
				{
					array[0] = rows;
					array[1] = cols;
				}
			}
		}
		return array;
	}
};

void getchildnegative(TreeNode* root, char** arr) {
	if (root->getColor() == "black") {
		for (int i = root->getRows(); i <= root->getRowe(); i++) {
			for (int j = root->getColumns(); j <= root->getCole(); j++) {
				arr[i][j] = 0;
			}
		}
	}
	else if (root->getColor() == "white") {
		for (int i = root->getRows(); i <= root->getRowe(); i++) {
			for (int j = root->getColumns(); j <= root->getCole(); j++) {
				arr[i][j] = 255;
			}
		}
	}
	else {
		getchildnegative(root->getChild1(), arr);
		getchildnegative(root->getChild2(), arr);
		if (root->getChild3() != nullptr) {
			getchildnegative(root->getChild3(), arr);
		}
		if (root->getChild4() != nullptr) {
			getchildnegative(root->getChild4(), arr);
		}
	}
}
void getchild(TreeNode* root, char** arr) {
	if (root->getColor() == "white") {
		for (int i = root->getRows(); i <= root->getRowe(); i++) {
			for (int j = root->getColumns(); j <= root->getCole(); j++) {
				arr[i][j] = 0;
			}
		}
	}
	else if (root->getColor() == "black") {
		for (int i = root->getRows(); i <= root->getRowe(); i++) {
			for (int j = root->getColumns(); j <= root->getCole(); j++) {
				arr[i][j] = 255;
			}
		}
	}
	else {
		getchild(root->getChild1(), arr);
		getchild(root->getChild2(), arr);
		if (root->getChild3() != nullptr) {
			getchild(root->getChild3(), arr);
		}
		if (root->getChild4() != nullptr) {
			getchild(root->getChild4(), arr);
		}
	}
}


void setchild(TreeNode* root, Image i) {
	
}
void preorder(TreeNode* treeNode){
	if (treeNode != nullptr){
		cout << treeNode->getColor() << " ";
		preorder(treeNode->getChild1());
		preorder(treeNode->getChild2());
		preorder(treeNode->getChild2());
		preorder(treeNode->getChild4());
	}
}
void postorder(TreeNode* treeNode){
	if (treeNode != NULL){
		postorder(treeNode->getChild1());
		postorder(treeNode->getChild2());
		postorder(treeNode->getChild3());
		postorder(treeNode->getChild4());
		cout << (treeNode->getColor()) << " ";
	}
}
int main(){
	Image i;
	Queue q; // Queue object created
	Stack s;
	TreeNode* root = nullptr;
	//list l;

	i.readfile("apple-18.pgm"); // file reading function called
	int pixel = 0;
	// printing menu for the user
	int option = 0;
	int num = 0;
	cout << "Enter number of times you want to run this program";
	cin >> num;
	while (num != 0)
	{

		num--;
		cout << "Press 1 for question 1 :";
		cout << "\nPress 2 for question 2 :";
		cout << "\nPress 3 for question 3:";
		cout << "\nPress 4 for question 4:";
		cout << "\nPress 5 for question 5:";
		cout << "\nPress 6 for question 6:";
		cout << "\nEnter a valid option number  ";
		cin >> option;

		switch (option)
		{
		case 1:
		{
			// question 1
			cout << endl
				<< "*******************************************" << endl;
			cout << "\nBasic Statistic of image";
			i.Statistic_image();
			cout << "\nNegitive image will be: ";
			i.ConvertToNegative();
			break;
		}
		case 2:
		{

			cout << endl
				<< "*******************************************" << endl;
			// question 2
			int pixrow;
			int pixcol;
			cout << "Enter pixel x: ";
			cin >> pixrow;
			cout << "Enter pixel y: ";
			cin >> pixcol;
			// to avoid getting any pixel with less than 8 neighbours
			int validRows = i.getRows() - 1;
			int validCol = i.getCol() - 1;

			// Make an empty output image by setting all the values to 255.
			Image output_img(255);
			int arr[2] = {};
			// i.getPixelCoordinates(pixel, arr);
			// cout << "Pixel Coordinates are: " << arr[0] << " " << arr[1] << endl;
			// int pixrow = arr[0];
			// int pixcol = arr[1];

			if ((pixrow >= 0) && (pixcol >= 0)) // to make sure the pixel entered by user has 8 neighbours
			{
				q.Enqueue(i.GetPixel(pixrow, pixcol));
				// cout << "1: " << i.GetPixel(pixrow, pixcol) << endl;
				q.Enqueue(i.GetPixel(pixrow - 1, pixcol - 1));
				// cout << "2: " << i.GetPixel(pixrow - 1, pixcol - 1) << endl;
				q.Enqueue(i.GetPixel(pixrow, pixcol - 1));
				// cout << "3: " << i.GetPixel(pixrow, pixcol - 1) << endl;
				q.Enqueue(i.GetPixel(pixrow + 1, pixcol - 1));
				// cout << "4: " << i.GetPixel(pixrow + 1, pixcol - 1) << endl;
				q.Enqueue(i.GetPixel(pixrow - 1, pixcol + 1));
				// cout << "5: " << i.GetPixel(pixrow - 1, pixcol + 1) << endl;
				q.Enqueue(i.GetPixel(pixrow, pixcol + 1));
				// cout << "6: " << i.GetPixel(pixrow, pixcol + 1) << endl;
				q.Enqueue(i.GetPixel(pixrow + 1, pixcol + 1));
				// cout << "7: " << i.GetPixel(pixrow + 1, pixcol + 1) << endl;
				q.Enqueue(i.GetPixel(pixrow - 1, pixcol));
				// cout << "8: " << i.GetPixel(pixrow - 1, pixcol) << endl;
				q.Enqueue(i.GetPixel(pixrow + 1, pixcol));
				// cout << "9: " << i.GetPixel(pixrow + 1, pixcol) << endl;
			}
			cout << "\nEnqueueing done" << endl;
			q.Display();
			int ok = 1;
			while (!q.isEmpty())
			{
				Node* temp = q.Dequeue();
				int* a = i.getrowcolofpix(temp);
				output_img.SetPixel(0, *(arr + 0), *(arr + 1));
				if (ok == 1)
				{
					cout << "Dequeueing...";
				}
				ok++;
			}
			cout << "Dequeueing done" << endl;
			i.SaveImage();
			break;
		}
		case 3:
		{
			// question 3
			cout << endl
				<< "*******************************************" << endl;
			int pixrow;
			int pixcol;
			cout << "Enter pixel x: ";
			cin >> pixrow;
			cout << "Enter pixel y: ";
			cin >> pixcol;
			// to avoid getting any pixel with less than 8 neighbours
			int validRows = i.getRows() - 1;
			int validCol = i.getCol() - 1;

			// Make an empty output image by setting all the values to 255.
			Image output_img(255);
			int arr[2] = {};
			// i.getPixelCoordinates(pixel, arr);
			// cout << "Pixel Coordinates are: " << arr[0] << " " << arr[1] << endl;
			// int pixrow = arr[0];
			// int pixcol = arr[1];

			if ((pixrow >= 0) && (pixcol >= 0)) // to make sure the pixel entered by user has 8 neighbours
			{
				s.push(i.GetPixel(pixrow, pixcol));
				cout << "1: " << i.GetPixel(pixrow, pixcol) << endl;
				s.push(i.GetPixel(pixrow - 1, pixcol - 1));
				// cout << "2: " << i.GetPixel(pixrow - 1, pixcol - 1) << endl;
				s.push(i.GetPixel(pixrow, pixcol - 1));
				// cout << "3: " << i.GetPixel(pixrow, pixcol - 1) << endl;
				s.push(i.GetPixel(pixrow + 1, pixcol - 1));
				// cout << "4: " << i.GetPixel(pixrow + 1, pixcol - 1) << endl;
				s.push(i.GetPixel(pixrow - 1, pixcol + 1));
				// cout << "5: " << i.GetPixel(pixrow - 1, pixcol + 1) << endl;
				s.push(i.GetPixel(pixrow, pixcol + 1));
				// cout << "6: " << i.GetPixel(pixrow, pixcol + 1) << endl;
				s.push(i.GetPixel(pixrow + 1, pixcol + 1));
				// cout << "7: " << i.GetPixel(pixrow + 1, pixcol + 1) << endl;
				s.push(i.GetPixel(pixrow - 1, pixcol));
				// cout << "8: " << i.GetPixel(pixrow - 1, pixcol) << endl;
				s.push(i.GetPixel(pixrow + 1, pixcol));
				// cout << "9: " << i.GetPixel(pixrow + 1, pixcol) << endl;
			}
			cout << "\nEntering elements in stack" << endl;
			s.Display();
			int ok = 1;
			while (!s.isEmpty())
			{
				Node* temp = s.pop();
				int* a = i.getrowcolofpix(temp);
				output_img.SetPixel(0, *(arr + 0), *(arr + 1));
				if (ok == 1)
				{
					cout << "Poping...";
				}
				ok++;
			}
			cout << "Emptying stack done" << endl;
			i.SaveImage();

			break;
		}
		case 4:
		{  // question 4
			//part a converting pgm into RLC format
			i.ConvertRLC();
			//part b converting RLC into pgm format
			//converting RLC into pgm
			i.ConvertRLCtoPGM();
			//part c
			i.RLCblackpixcount();
			//partd 
			i.ConvertToNegative();
		}
		case 5:
		{		
				//part a
				root = new TreeNode(0, 0, i.getRows() - 1, i.getCol() - 1, "grey");
				setchild(root, i);
				preorder(root);
				
				//part b
				root = new TreeNode(0, 0, i.getRows() - 1, i.getCol() - 1, "grey");
				setchild(root, i);

				char** temp = new char* [i.getRows()];
				for (int j = 0; j < i.getRows(); j++) {
					temp[j] = new char[i.getCol()];
				}
				getchild(root, temp);
				i.SaveImage();
				
				//part c
				root = new TreeNode(0, 0, i.getRows() - 1, i.getCol() - 1, "grey");
				setchild(root, i);
				char** temp1 = new char* [i.getRows()];
				for (int j = 0; j < i.getRows(); j++) {
					temp1[j] = new char[i.getCol()];
				}
				getchildnegative(root, temp1);
				i.SaveImage();
				
				//part d
				root = new TreeNode(0, 0, i.getRows() - 1, i.getCol() - 1, "grey");
				setchild(root, i);
				cout << "Post Order: \n";
				cout << endl << endl << endl << endl;
				postorder(root);
				cout << "\nPre-Order: \n";
				preorder(root);
			
						}
					}
				}
	return 0;
}