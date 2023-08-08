## Cheapest_Hamiltonian_Circuit
This algorithm finds the cheapest path for to complete a Hamiltonian Circuit in a undirected graph using the backtracking method.

## Pseudocode:
# STRUCTURE Info:
define VName as STRING
define weight as INTEGER
CONSTRUCTOR Info()
VName ← “ ”
weight ←0
END CONSTRUCTOR
END STRUCTURE
STRUCTURE Node
define data as INFO
define next as NODE *
CONSTRUCTOR NODE()
next ← NULL
END CONSTRUCTOR
CONSTRUCTOR NODE(Info toadd)
data.VName ← toadd.VName
Data.weight ← toadd.weight
next = NULL
END CONSTRUCTOR
END STRUCTURE
CLASS Queue
define first as NODE*
define last as NODE* // used last to make enqueue O(1)
public:
CONSTRUCTOR Queue()
first←NULL
last ← NULL
END CONSTRUCTOR
PROCEDURE Enqueue(Info toadd)
if(first is NULL) then
First ← new Node(toadd)
last ← first
else
last→next ← new Node(toadd)
last ← last→next
Endif
END PROCEDURE
BOOLEAN FUNCTION inQueue(Info tocheck)
define temp as NODE*
temp ← first
while(temp is not NULL)
if(temp→data == tocheck) then
Return TRUE
Endif
temp ← temp→next
Endwhile
RETURN FALSE
PROCEDURE Dequeue()
define temp as NODE*
temp ← first
if(first is NOT NULL) then
first ← first→next
Endif
END PROCEDURE
PROCEDURE DequeueLast()
define temp as NODE*
define temp2 as NODE*
temp ← last
temp2 ← first
if(first is last) then
first ← NULL
Endif
last ← NULL
END PROCEDURE
BOOLEAN FUNCTION isEmpty()
if(first is NULL) then
Return TRUE
Endif
RETURN FALSE
INTEGER FUNCTION countQUEUE()
define temp as NODE*
temp ← first
define count as INTEGER
count←0
while(temp is NOT NULL)
count← count+1
temp← temp→next
Endwhile
RETURN count
END CLASS
CLASS Stack
define top as NODE*
Public:
CONSTRUCTOR Stack()
top ← NULL
END CONSTRUCTOR
PROCEDURE push(Info toadd)
define temp as NODE*
if(top is NULL) then
Top← new Node(toadd)
else
temp← new Node(toadd)
temp→next ←top
top ← temp
Endif
END PROCEDURE
FUNCTION instack(tocheck: string) returns bool
temp <-- top
while (temp IS NOT EQUAL NULL) do
if (temp->data.VName IS EQUAL tocheck) then
RETURN true
END IF
temp <-- temp->next
END WHILE
RETURN false
PROCEDURE Pop()
if (top IS NOT EQUAL NULL) then
temp <-- top
top <-- top->next
END IF
END PROCEDURE
Function Top() returns Info
RETURN top->data
FUNCTION isEmpty() returns bool
if (top IS EQUAL NULL) then
RETURN true
END IF
RETURN false
FUNCTION countStack() returns int
temp <-- top
count <-- 0
while (temp IS NOT EQUAL NULL) do
count <-- count + 1
temp <-- temp->next
END WHILE
RETURN count
DESTRUCTOR ~Stack()
while (top IS NOT EQUAL NULL) do
CALL Pop()
END WHILE
END DESTRUCTOR
END CLASS
CLASS List
define head as NODE*
define tail as NODE*
Public:
PROCEDURE addToList(Info toadd)
IF head IS EQUAL NULL THEN
head ← new Node(toadd)
tail ← head
else
tail->next <-- new Node(toadd)
tail <-- tail->next
ENDIF
END PROCEDURE
PROCEDURE RemoveFromList(toremove)
DATATYPE temp <-- head
DATATYPE temp2
IF head IS EQUAL to NULL THEN
RETURN
END IF
IF temp->data IS EQUAL to toremove THEN
head <-- head->next
delete temp
RETURN
END IF
WHILE temp IS NOT EQUAL NULL
IF temp->next->data IS EQUAL to toremove THEN
temp2 <-- temp->next
temp->next <-- temp->next->next
delete temp2
IF temp->next IS EQUAL to NULL THEN
tail <-- temp
END IF
RETURN
END IF
temp <-- temp->next
END WHILE
END PROCEDURE
FUNCTION checkInList(tocheck:Info)
DATATYPE temp <-- head
WHILE temp NOT EQUAL NULL
IF temp->data IS EQUAL to tocheck THEN
RETURN true
END IF
temp <-- temp->next
END WHILE
RETURN false
END CLASS
STRUCTURE Vertice
define Name as STRING
define next as VERTICE*
CONSTRUCTOR VERTICE(STRING tName, INTEGER tweight )
Name← tName
weight← tweight
END CONSTRUCTOR
END STRUCTURE
STRUCTURE VerticeList
define vertice as STRING
define edges as VERTICE*
define next as VERTICELIST*
CONSTRUCTOR VerticeList(string VertName)
next ← NULL
edges ←NULL
vertice ← Vertname
END CONSTRUCTOR
PROCEDURE AddEdge(edgeName: string, weight: int)
IF edges IS EQUAL TO NULL THEN
edges <-- new Vertice(edgeName, weight)
ELSE
temp <-- edges
WHILE temp->next IS NOT EQUAL TO NULL DO
temp <-- temp->next
END WHILE
temp->next <-- new Vertice(edgeName, weight)
ENDIF
END PROCEDURE
PROCEDURE smallestEdge(string tocheck) as INFO
define minWeight as INTEGER
define minEdge as INFO
minWeight <-- INT_MAX
define temp as VERTICE*
temp <-- edges
WHILE temp IS NOT EQUAL TO NULL DO
IF (temp->Name IS EQUAL TO tocheck AND temp->weight < minWeight)
THEN
minWeight <-- temp->weight
minEdge.weight <-- minWeight
minEdge.VName <-- tocheck
END IF
temp <-- temp->next
END WHILE
RETURN minEdge
END STRUCTURE
CLASS GraphList
define head as VERTICELIST*
define totalDeliveryTimes as INTEGER
define totalTime as INTEGER // allowed total time T
Public:
CONSTRUCTOR GraphList()
head ← NULL
totalDeliveryTimes← 0
totalTime ← 0
END CONSTRUCTOR
BOOLEAN FUNCTION createList(fileName:string)
File fin
IF (!fin.open(fileName)) THEN
RETURN FALSE // file failed to open
ENDIF
define str as STRING
define str2 as STRING
Str←Firstline from Fin
SeperateVertices(str)
Str← SecondLine from Fin
Str2 ← Third line from Fin
seperateEdges(str,str2)
Str ← Fourth Line from Fin
SeperateDelivery(str)
TotalTime = Fifth Line from Fin
RETURN TRUE
PROCEDURE AddEdges(string VertName, string EdgeName, int weight)
DEFINE temp as VerticeList*
temp <-- head
WHILE temp->vertice IS NOT EQUAL to VertName
temp <-- temp->next
END WHILE
temp->AddEdge(EdgeName, weight)
END PROCEDURE
FUNCTION CountVertice()
DEFINE count as int
count <-- 0
DEFINE temp as VerticeList*
temp <-- head
WHILE temp IS NOT EQUAL to NULL
temp <-- temp->next
Count++
END WHILE
RETURN count
END CLASS
Function HamiltonianCircuit(GraphList& g, string& OUTPUT): INTEGER
OUTPUT ← “NO FEASIBLE CIRCUIT”
Define stack as STACK
Define queue,totalPushed as QUEUE
Define Visited as LIST
Define info,info2 as INFO
Define retVal,minWeightCircuit,unvisitCounter,CompVal as INTEGER
minWeightCircuit ← INT_MAX
unvisitCounter ← 0
compVal ← 0
info.VName ← “h”
stack.push(info)
WHILE (NOT(stack.isEmpty())) DO
info ← stack.Top()
stack.Pop()
retVal← 3 // dummy value so previous value doesnt go into any condition
IF (NOT(visited.checkInList(info.VName))) THEN
visited.addToList(info)
queue.Enqueue(info)
retVal = pushNeighbours(g, stack, visited,queue,info)
Info2.weight ←retVal
totalPushed.Enqueue(info2)
ENDIF
compVal ← queue.getSum()
IF(RetVAL IS INT_MAX) THEN // back tracked to h
IF (compVal IS LESS THAN minWeightCicuit) THEN
minWeightCircuit ←compVal
queue.MakeString(OUTPUT) // makes OUTPUT string
ENDIF
queue.DequeueEnd()
IF (NOT(stack.isEmpty())) THEN
WHILE (totalPushed.getLast().weight IS 0 OR
totalPushed.getLast().weight IS 1 OR totalPushed.getLast().weight IS INT_MAX) DO
visited.RemoveFromList(queue.getLast())
queue.DequeueEnd()
totalPushed.DequeueEnd()
END WHILE
END IF
ENDIF
IF (retVal IS 0) THEN // reached a dead end
IF (compVal IS LESS THAN minWeightCicuit) THEN
minWeightCircuit ←compVal
queue.MakeString(OUTPUT) // makes OUTPUT string
ENDIF
queue.DequeueEnd()
IF (NOT(stack.isEmpty())) THEN
WHILE (totalPushed.getLast().weight IS 0 OR
totalPushed.getLast().weight IS 1 OR totalPushed.getLast().weight IS INT_MAX) DO
visited.RemoveFromList(queue.getLast())
queue.DequeueEnd()
totalPushed.DequeueEnd()
END WHILE
END IF
ENDIF
END WHILE
IF (minWeightCircuit IS NOT INT_MAX) THEN // a hamiltonian circuit was found
minWeightCircuit ← MinWeightCircuit + g.getTotalDelivery()
IF(minWeightCircuit IS GREATER g.getTotalTime()) THEN
OUTPUT ← “NO FEASIBLE CIRCUIT”
END IF
END IF
RETURN minWeightCircuit
FUNCTION PushNeighbours(Graph g,Stack stack,List visited,Queue queue,
Info tocheck) : INTEGER
define pushCounter as INTEGER
pushCounter ← 0
define tempList as VERTICELIST*
WHILE (tempList→Vertice IS NOT tocheck.VName) DO
tempList ← tempList→next
END WHILE
define tempVert as VERTICE*
tempVert ← tempList→edges
WHILE(tempVert IS NOT NULL) DO
IF (tempVert IS NOT “h”) THEN
IF(NOT(visited.checkInLust(tempVert→Name))) THEN
stack.push(tempList→smallestEdge(tempVert->name))
pushCounter ← pushCounter + 1
ENDIF
ELSE
IF(queue.countQueue IS g.CountVertice) THEN
queue.Enqueue(tempList->smalEdge(tempVert->Name))
RETURN INT MAX
ENDIF
ENDIF
ENDWHILE
RETURN pushCounter

