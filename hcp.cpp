#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;


/***************************************UTILITY FUNCTIONS***********************************************/
struct Info {
	string VName;
	int weight;
	Info() {
		VName = "";
		weight = 0;
	}

	void operator=(const Info& other) {
		this->VName = other.VName;
		this->weight = other.weight;
	}

	bool operator==(Info& other) {
		if (this->VName == other.VName)
			return true;
		return false;
	}
};

// a Node
struct Node {
	Info data;
	Node* next;

	Node() {
		next = NULL;
	}
	Node(Info& toadd) {
		data.VName = toadd.VName;
		data.weight = toadd.weight;
		next = NULL;
	}
};

// a Queue ADT
class Queue {
	Node* first;
	Node* last; // LAST USED TO MAKE INSERTION O(1)
public:

	Queue() {
		first = NULL;
		last = NULL;
	}

	void Enqueue(Info toadd) { // ADDS ONLY IF DATA IS NOT PRESENT
		if (first == NULL) {
			first = new Node(toadd);
			last = first;
			return;
		}
		last->next = new Node(toadd);
		last = last->next;
	}

	bool inQueue(Info& tocheck) { // checks if present in queue
		Node* temp = first;
		while (temp != NULL) {
			if (temp->data == tocheck)
				return true;
			temp = temp->next;
		}
		return false;
	}
	bool inQueue(string tocheck) { // checks if present in queue
		Node* temp = first;
		while (temp != NULL) {
			if (temp->data.VName == tocheck)
				return true;
			temp = temp->next;
		}
		return false;
	}

	void Dequeue() {
		Node* temp = first;
		if (first != NULL) {
			first = first->next;
			delete temp;
		}
	}
	void DequeueEnd() {
		Node* temp = last;
		Node* temp2 = first;
		if (first == last) {
			first = NULL;
			delete last;
			last = NULL;
		}
		else {
			if (first != NULL) {
				while (temp2->next != last) {
					temp2 = temp2->next;
				}
				delete temp;
				last = temp2;
				temp = NULL;
				last->next = NULL;
				
			}
		}
	}

	Info getFirst() {
		return(first->data); // when calling from outside call after checking list is not empty
	}
	Info getLast() {
		return(last->data);
	}

	Node* getLastNode() {
		return last;
	}

	int countQueue() {
		Node* temp = first;
		int count = 0;

		while (temp != NULL) {
			count++;
			temp = temp->next;
		}

		return count;
	}
	bool isEmpty() {
		if (first == NULL)
			return true;
		return false;
	}

	void Display() {
		Node* temp = first;
		if (temp == NULL)
			return;
		cout << temp->data.VName << " " <<temp->data.weight <<" ";
		temp = temp->next;
		while (temp != NULL) {
			cout << "  ---> " << temp->data.VName << " " << temp->data.weight << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	int getSum() {
		Node* temp = first;
		int sum = 0;
		while (temp != NULL) {
			sum += temp->data.weight;
			temp = temp->next;
		}
		return sum;
	}

	void MakeString(string& str) {
		Node* temp = first;
		str = "(";
		while (temp != NULL) {
			str += temp->data.VName + ",";
			temp = temp->next;
		}
		str[str.length()-1] = ')';
	}

	~Queue() {
		while (first != NULL) {
			Dequeue();
		}
	}


};

// a Stack ADT
class Stack {
	Node* top;
public:
	Stack() {
		top = NULL;
	}

	void push(Info toadd) {
		if (top == NULL) {
			top = new Node(toadd);
			return;
		}
		Node* temp = new Node(toadd);
		temp->next = top;
		top = temp;
	}

	bool instack(Info & tocheck) {
		Node* temp = top;
		while (temp != NULL) {
			if (temp->data == tocheck)
				return true;
			temp = temp->next;
		}
		return false;
	}

	bool instack(string tocheck) {
		Node* temp = top;
		while (temp != NULL) {
			if (temp->data.VName == tocheck)
				return true;
			temp = temp->next;
		}
		return false;
	}

	void Pop() {
		if (top != NULL) {
			Node* temp = top;
			top = top->next;
			delete temp;
		}
	}

	Info Top() {
		return(top->data); // call after checking if top stack is empty or not
	}

	bool isEmpty() {
		if (top == NULL)
			return true;
		return false;
	}

	int countStack() {
		Node* temp = top;
		int count = 0;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	~Stack() {
		while (top != NULL) {
			Pop();
		}
	}


};
 
// A normal Linked List
class List {
	Node* head;
	Node* tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	void addToList(Info & toadd) {
		if (head == NULL) {
			head = new Node(toadd);
			tail = head;
 			return;
		}
		tail->next = new Node(toadd);
		tail = tail->next;
	}

	void RemoveFromList(Info toremove) {
		Node* temp = head;
		Node* temp2;
		if (head == NULL)
			return;

		if (temp->data == toremove) {
			head = head->next;
			delete temp;
			return;
		}

		while (temp != NULL) {
			if (temp->next->data == toremove) {
				temp2 = temp->next;
				temp->next = temp->next->next;
				delete temp2;
				if (temp->next == NULL)
					tail = temp;
				return;
			}
			temp = temp->next;
		}
	}

	bool checkInList(Info & tocheck) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == tocheck)
				return true;
			temp = temp->next;
		}
		return false;
	}
	bool checkInList(string tocheck) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data.VName == tocheck)
				return true;
			temp = temp->next;
		}
		return false;
	}

	void Display() {
		Node* temp = head;
		cout << "-------Data In List---------" << endl;
		while (temp != NULL) {
			cout << temp->data.VName << " -> ";
			temp = temp->next;
		}
		cout << endl;
		cout << "----------------------------" << endl;
	}


};

// A node for graph edges Linked List
struct Vertice {
	string Name;
	Vertice* next;
	int weight;

	Vertice() {
		Name = "";
		next = NULL;
		weight = 0;
	}
	Vertice(string Name) {
		this->Name = Name;
		next = NULL;
		weight = 0;
	}
	Vertice(string Name, int weight) {
		this->Name = Name;
		next = NULL;
		this->weight = weight;
	}
};

// A Linked List Node for a 2D Linked List
struct VerticeList {
	string vertice; // the vertice which has edges
	Vertice * edges; // the edges of the vertice
	VerticeList* next; // pointing to the next vertice if there is any

	VerticeList() {
		vertice = "";
		edges = NULL;
		next = NULL;
	}
	VerticeList(string Vertname) {
		vertice = Vertname;
		edges = NULL;
		next = NULL;
	}

	void AddEdge(string edgeName,int weight) {
		if (edges == NULL) {
			edges = new Vertice(edgeName,weight);
			return;
		}
		Vertice* temp = edges;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new Vertice(edgeName,weight);
	}

	void showNeighbours() {
		Vertice* temp = edges;
		cout << vertice << " = ";
		while (temp != NULL) {
			cout << " -> " << temp->Name << " " << temp->weight << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	Info smallestEdge(string tocheck) {
		int minWeight = INT_MAX; // just in case if test cases get negative edges weighted as well
		Info minEdge;
		Vertice* temp = edges;
		while (temp != NULL) {
			if (temp->Name == tocheck && temp->weight < minWeight) {
				minWeight = temp->weight;
				minEdge.weight = minWeight;
				minEdge.VName = tocheck;
			}
			temp = temp->next;
		}
		return minEdge;
	}

};

// A 2D Linked List (Adjacency List for graph)
class GraphList { // 2D Linklist (linked list of linked lists)
private:
	VerticeList* head;
	int totalDeliveryTimes;
	int totalTime;
public:

	GraphList() {
		head = NULL;
		totalDeliveryTimes = 0;
		totalTime = 0;
	}

	bool createList(string filename) {

		ifstream fin;
		string str,str2;

		fin.open(filename);

		if (!fin) {
			cout << "File Failed To Open " << endl;
			return false;
		}

		getline(fin,str,'\n'); // first line for vertices
		str = str.substr(3,str.find('}')-3);
		SeperateVertices(str);

		getline(fin, str, '\n'); // second line for edges
		str = str.substr(3, str.find('}') - 3);

		getline(fin, str2, '\n'); // third line weights
		str2 = str2.substr(9, str2.find('}') - 9);
		SeperateEdges(str,str2);

		getline(fin, str, '\n');
		SeperateDelivery(str); // fourth line totalDeliveryTimes

		getline(fin, str); // fifth line Total Time constraint
		str = str.substr(2, str.length() - 2);
		totalTime = stoi(str);
		
		fin.close();
	}
	void SeperateVertices(string str) {
		string str2;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ',') {
				AddNewVertice(str2);
				str2 = "";
			}
			else {
				str2 += str[i];
			}
		}
		AddNewVertice(str2);
	}

	void SeperateEdges(string str,string weights) {
		string vert;
		string edge;
		int commaCount=0;

		for (int i = 0; i < weights.length(); i++)
			if (weights[i] == ',')
				commaCount++;

		int* weightArr = new int[commaCount + 1];
		int index = 0;
		
		for (int i = 0; i < weights.length(); i++) {
			if (weights[i] == ',') {
				weightArr[index] = stoi(vert);
				vert = "";
				index++;
			}
			else {
				vert += weights[i];
			}
		}
		weightArr[commaCount] = stoi(vert);
		index = 0;
		vert = "";
		commaCount = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != '(' && str[i] != ')') {
				if (str[i] != ',' && commaCount == 0) {
					vert += str[i];
				}
				if (str[i] != ',' && commaCount == 1) {
					edge += str[i];
				}
				if (str[i] == ',' && commaCount == 0) {
					commaCount++;
				}
				else {
					if (str[i] == ',' && commaCount == 1) {
						commaCount = 0;
						AddEdges(vert, edge,weightArr[index]);
						AddEdges(edge, vert,weightArr[index]); // THE GRAPH IS UNDIRECTED SO ADDING Edges to both sides
						vert = "";
						edge = "";
						index++;
					}
				}
			}
		}
		AddEdges(vert, edge, weightArr[index]);
		AddEdges(edge, vert, weightArr[index]);

		delete[] weightArr;
	}
	
	void SeperateDelivery(string str) {
		string temp;
		bool equalstart = false;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ',') {
				totalDeliveryTimes += stoi(temp);
				equalstart = false;
				temp = "";
			}
			if (equalstart) {
				temp += str[i];
			}
			if (str[i] == '=')
				equalstart = true;
		}
		totalDeliveryTimes += stoi(temp);
	}

	void AddNewVertice(string VertName) {
		VerticeList* temp = head;
		if (temp == NULL) {
			head = new VerticeList(VertName);
			return;
		}
		while (temp->next != NULL) {
			if (temp->vertice == VertName)
				return; // same vertice can not have 2 lists associated with it
			else
				temp = temp->next;
		}
		temp->next = new VerticeList(VertName);
	}

	void AddEdges(string VertName,string EdgeName,int weight) {
		VerticeList* temp = head;
		while (temp->vertice != VertName) {
			temp = temp->next;
		}
		temp->AddEdge(EdgeName,weight);
		
	}

	VerticeList* getHead() {
		return(head);
	}

	int getTotalDelivery() {
		return totalDeliveryTimes;
	}
	int getTotalTime() {
		return totalTime;
	}

	int CountVertice() {
		int count = 0;
		VerticeList* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}

	void Display() {
		VerticeList* temp = head;
		while (temp != NULL) {
			temp->showNeighbours();
			temp = temp->next;
		}
	}
};
/*******************************************************************************************************/


/*
-------------------------------------------------------------------
* Everything Above is a utility and the solution
* starts from below.
------------------------------------------------------------------
*/

int PushNeighbours(GraphList& g,Stack& stack,List& visited,Queue& queue,Info & tocheck) {

	int pushCounter = 0;
	VerticeList* tempList=g.getHead();

	while (tempList->vertice != tocheck.VName) {
		tempList = tempList->next;
	}
	Vertice* tempVert= tempList->edges;

	while (tempVert != NULL) {
		if (!(tempVert->Name == "h")) { // returning back to Home address? 
			if (!visited.checkInList(tempVert->Name) && !queue.inQueue(tempVert->Name)) { // Queue condition to avoid duplication with self loops
				stack.push(tempList->smallestEdge(tempVert->Name));
				pushCounter++;
			}
		}
		else {
			if (queue.countQueue()==g.CountVertice()) { // all vertices visited and going back to h path found
				queue.Enqueue(tempList->smallestEdge(tempVert->Name));
				return INT_MAX; // TELLS that hamiltonian circuit is made
			}
		}
		tempVert = tempVert->next;
	}

	return pushCounter; // return the amount of vertices pushed
}

int HamiltonianCircuit(GraphList& g,string& OUTPUT) {

	OUTPUT = "NO FEASIBLE CIRCUIT"; // initially no circuit exists. The value is unchanged if no hamiltonian circuit found

	Stack stack;
	Queue queue,totalPushed;
	List visited;
	Info info,info2;
	int retVal=3,minWeightCircuit=INT_MAX,unvisitCounter=0,compVal=0;


	info.VName = "h"; // home vertice initially
	stack.push(info);

	while (!stack.isEmpty()) { // DOING DFS (Depth first Search)
		info = stack.Top();
		stack.Pop();
		retVal = 3;// dummy value to remove uninitialization error
		if (!visited.checkInList(info.VName)) { // PUSH ONLY if it is not already visited
			visited.addToList(info);
			queue.Enqueue(info);
			retVal = PushNeighbours(g, stack, visited, queue, info);
			info2.weight = retVal;
			totalPushed.Enqueue(info2); // Counting the number of neighbours each vertice pushed in stack (helps with back tracking)
		}

		if (retVal == INT_MAX) { // One version of Hamiltonian circuit complete
			// display the queue and store the weighted result
			// then dequeueEnd to get other variations
			compVal = queue.getSum();
			if (compVal < minWeightCircuit) {
				minWeightCircuit = compVal;
				queue.MakeString(OUTPUT);
			}
			queue.DequeueEnd();

			if (!stack.isEmpty()) {
				while ((totalPushed.getLast().weight == 0 || totalPushed.getLast().weight == 1 || totalPushed.getLast().weight == INT_MAX)) {
					visited.RemoveFromList(queue.getLast());
					queue.DequeueEnd();
					totalPushed.DequeueEnd();
				}
				info2.weight = totalPushed.getLast().weight;
				totalPushed.DequeueEnd();
				info2.weight = info2.weight - 1;
				totalPushed.Enqueue(info2);
			}
		}
		if (retVal == 0) { // nothing was pushed. reached a dead end
			if (!stack.isEmpty()) {
				while ((totalPushed.getLast().weight == 0 || totalPushed.getLast().weight == 1 || totalPushed.getLast().weight == INT_MAX)) {
					visited.RemoveFromList(queue.getLast());
					queue.DequeueEnd();
					totalPushed.DequeueEnd();
				}
				info2.weight = totalPushed.getLast().weight;
				totalPushed.DequeueEnd();
				info2.weight = info2.weight - 1;
				totalPushed.Enqueue(info2);
			}
		}		
	}

	if (minWeightCircuit != INT_MAX) {
		minWeightCircuit += g.getTotalDelivery();
		if (minWeightCircuit > g.getTotalTime()) {
			OUTPUT = "NO FEASIBLE CIRCUIT";
		}
	}
	return minWeightCircuit;
}

void RunP2(string path) {
	GraphList g1;
	string result;
	int val;

	g1.createList(path);
	//g1.Display(); // USE THIS TO DISPLAY THE ADJACENCY LIST
	val = HamiltonianCircuit(g1, result);

	cout << result << endl;
}

void LoopTestCases(string path,int count) {
	string temp;

	for (int i = 1; i <= count; i++) {
		temp = path;
		temp += to_string(i)+".txt";
		RunP2(temp);
	}
	
}

int main() {

	string path = "P2_test"; // general Prefix of the test Case
	LoopTestCases(path,2); // second Argument is the number of test cases, assuming they start from 1 and end at N (2 IN THIS CASE)

	return 0;
}