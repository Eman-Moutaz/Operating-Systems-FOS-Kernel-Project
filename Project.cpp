#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

class Graph
{
public:

	//----------------------------------------------------------------------//
	Graph()
	{
		SizeOfGraph = 0;
		Distance = new list<int>[0];
		Edge = new list<int>[0];
	}

	//----------------------------------------------------------------------//
	void AddMenu()
	{
		int Option;
		do
		{
			// Main Screen
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                              Add menu                               |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(70) << "|- 1) Add vertex" << "|" << endl;
			cout << left << setw(70) << "|- 2) Add Edge" << "|" << endl;
			cout << left << setw(70) << "|- 3) Back to main menu" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			// to check if right input or not
			do
			{
				cout << "|- Please enter option : ";
				cin >> Option;
				if (Option <= 0 || Option > 3)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				break;
			} while (true);

			//Select what happen from option
			if (Option == 1)
			{
				cout << "+---------------------------------------------------------------------+" << endl;
				Addvertex();
				continue;
			}
			else if (Option == 2) {
				cout << "+---------------------------------------------------------------------+" << endl;
				AddEdge();
				continue;
			}
			else {
				break;
			}

		} while (true);
	}

	//----------------------------------------------------------------------//
	void UpdateMenu()
	{
		int Option;
		do
		{
			// Main Screen
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                            Update menu                              |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(70) << "|- 1) Update town's name" << "|" << endl;
			cout << left << setw(70) << "|- 2) Update distance" << "|" << endl;
			cout << left << setw(70) << "|- 3) Back to main menu" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			// to check if right input or not
			do
			{
				cout << "|- Please enter option : ";
				cin >> Option;
				if (Option <= 0 || Option > 3)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				break;
			} while (true);

			//Select what happen from option
			if (Option == 1)
			{
				if (SizeOfGraph > 0)
				{
					cout << "+---------------------------------------------------------------------+" << endl;
					UpdateTown();
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << left << setw(70) << "|- There is no vertex yet ." << "|\a" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|- ";
				system("pause");
				cout << "+---------------------------------------------------------------------+" << endl << endl;
				continue;
			}
			else if (Option == 2) {
				if (SizeOfGraph > 1)
				{
					cout << "+---------------------------------------------------------------------+" << endl;
					UpdateDistance();
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << left << setw(70) << "|- There is no edge yet ." << "|\a" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|- ";
				system("pause");
				cout << "+---------------------------------------------------------------------+" << endl << endl;
				continue;
			}
			else {
				break;
			}
		} while (true);
	}

	//----------------------------------------------------------------------//
	void DeleteMenu()
	{
		int Option;
		do
		{
			// Main Screen
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                             Delete menu                             |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(70) << "|- 1) Delete Graph" << "|" << endl;
			cout << left << setw(70) << "|- 2) Back to main menu" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			// to check if right input or not
			do
			{
				cout << "|- Please enter option : ";
				cin >> Option;
				if (Option <= 0 || Option > 2)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				break;
			} while (true);

			//Select what happen from option
			if (Option == 1)
			{
				SizeOfGraph = 0;
				Vertex.clear();
				Town.clear();
				Edge = new list<int>[0];
				Distance = new list<int>[0];
			}
			else {
				break;
			}

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(70) << "|- The Graph Deleted sucssessfuly ." << "|\a" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- ";
			system("pause");
			cout << "+---------------------------------------------------------------------+" << endl << endl;

		} while (false);
	}

	//----------------------------------------------------------------------//
	void DisplayMenu()
	{
		// part of decler data
		list<string> TempVertexList;
		list<string> TempTownList;

		// part of display
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "|                          Display Graph Data                         |" << endl;
		cout << "+---------------------------------------------------------------------+" << endl << endl;

		// if there is Vertex data display it
		if (SizeOfGraph > 0)
		{
			// part of initialize data
			TempVertexList = Vertex;
			TempTownList = Town;

			// part of display
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                              Vertex Data                            |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(25) << "|Vertex" << setw(25) << "|Town's Name" << setw(20) << "|destinations" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			// part of display vertex data
			for (int i = 0; i < SizeOfGraph; i++)
			{
				cout << left << setw(25) << "|" + TempVertexList.front() << setw(25) << "|" + TempTownList.front() << setw(20) << "|" + PrintDestination(i) << "|" << endl;
				TempVertexList.pop_front();
				TempTownList.pop_front();
			}

			// part of display
			cout << "+---------------------------------------------------------------------+" << endl << endl;

			// if there is Edge data display it
			if (SizeOfGraph > 1)
			{
				// part of decler
				int Counter1;
				int Counter2;
				list<int> DestinationList;
				// part of decleer collected data
				int Dis = 1;
				string Src = "";
				string Des = "";

				// part of display
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|                              Edge Data                              |" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << left << setw(25) << "|Vertex's Source" << setw(25) << "|Vertex's destination" << setw(20) << "|Distance " << "|" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;

				// loop to collect Edge Data
				for (int i = 0; i < SizeOfGraph; i++)
				{
					DestinationList = Edge[i];
					Counter1 = 0;

					for (int DestinationData : DestinationList)
					{
						if (i < DestinationData)
						{
							Counter2 = 0;
							for (int DistanceData : Distance[i])
							{
								if (Counter2 == Counter1)
								{
									Dis = DistanceData;
									break;
								}
								Counter2++;
							}

							Counter2 = 0;
							for (string VertexData : Vertex)
							{
								if (Counter2 == i)
								{
									Src = VertexData;
								}

								if (Counter2 == DestinationData)
								{
									Des = VertexData;
								}
								Counter2++;
							}
							cout << left << setw(25) << "|" + Src << setw(25) << "|" + Des << "|" << setw(19) << Dis << "|" << endl;
						}
						Counter1++;
					}
				}

				// part of display
				cout << "+---------------------------------------------------------------------+" << endl << endl;
			}
		}

		// if there is not data
		else
		{
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(70) << "|- There is no data yet ." << "|\a" << endl;
			cout << "+---------------------------------------------------------------------+" << endl << endl;
		}

		// part of display
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "|- ";
		system("pause");
		cout << "+---------------------------------------------------------------------+" << endl << endl;

	}

	//----------------------------------------------------------------------//
	void FindShortPath()
	{
		int Option;
		do
		{
			// Main Screen
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                          Short Path menu                            |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(70) << "|- 1) dijkstra's Algorithm" << "|" << endl;
			cout << left << setw(70) << "|- 2) Second Algorithm" << "|" << endl;
			cout << left << setw(70) << "|- 3) Back to main menu" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			// to check if right input or not
			do
			{
				cout << "|- Please enter option : ";
				cin >> Option;
				if (Option <= 0 || Option > 3)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				break;
			} while (true);

			//Select what happen from option
			if (Option == 1)
			{
				if (SizeOfGraph > 1)
				{
					cout << "+---------------------------------------------------------------------+" << endl;
					First();
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << left << setw(70) << "|- There is no Edge yet ." << "|\a" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|- ";
				system("pause");
				cout << "+---------------------------------------------------------------------+" << endl << endl;
				continue;
			}
			else if (Option == 2) {
				if (SizeOfGraph > 1)
				{
					cout << "+---------------------------------------------------------------------+" << endl;
					Second();
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << left << setw(70) << "|- There is no edge yet ." << "|\a" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|- ";
				system("pause");
				cout << "+---------------------------------------------------------------------+" << endl << endl;
				continue;
			}
			else {
				break;
			}

		} while (true);
	}


private:

	//----------------------------------------------------------------------//
	int SizeOfGraph;
	list<string> Vertex;
	list<string> Town;
	list<int>* Edge;
	list<int>* Distance;

	//----------------------------------------------------------------------//
	void Addvertex()
	{
		// part of decler data
		int Option;
		int IntInput; // Distance;
		bool found; 

		string ExitOrNot;
		string StringInput; // vertex , town;

		do
		{
			// part of add vertex
			do
			{
				found = false;
				cout << "|- Please enter Vertex : ";
				cin >> StringInput; // vertex

				for (string VertexData: Vertex)
				{
					if (VertexData == StringInput)
					{
						found = true;
						cout << "|- this vertex is already found ! " << endl;
						break;
					}
				}

				if (!found)
				{
					Vertex.push_back(StringInput);
					break;
				}
			} while (true);

			// part of display
			cout << "+---------------------------------------------------------------------+" << endl;

			// part of add Town
			do
			{
				found = false;
				cout << "|- Please enter Town's Name : ";
				cin >> StringInput;

				for (string TownData : Town)
				{
					if (TownData == StringInput)
					{
						found = true;
						cout << "|- this Town's name is already found ! " << endl;
						break;
					}
				}

				if (!found)
				{
					Town.push_back(StringInput);
					break;
				}
			} while (true);

			// reload data
			list<int>* TempEdgeList = new list<int>[SizeOfGraph];
			list<int>* TempDistanceList = new list<int>[SizeOfGraph];

			for (int i = 0; i < SizeOfGraph; i++)
			{
				TempEdgeList[i] = Edge[i];
				TempDistanceList[i] = Distance[i];
			}

			SizeOfGraph++;

			Edge = new list<int>[SizeOfGraph];
			Distance = new list<int>[SizeOfGraph];


			for (int i = 0; i < SizeOfGraph - 1; i++)
			{
				Edge[i] = TempEdgeList[i];
				Distance[i] = TempDistanceList[i];
			}


			// part of add one Link at least
			if (SizeOfGraph > 1)
			{
				// part of decler data
				list<string> TempVertexList = Vertex;
				list<string> TempTownList = Town;

				// part of display
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|                             Vertex Data                             |" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;

				// loop to collect Edge Data
				for (int i = 0; i < SizeOfGraph - 1; i++)
				{
					cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
					TempVertexList.pop_front();
					TempTownList.pop_front();
				}

				// part of display
				cout << "+---------------------------------------------------------------------+" << endl;

				// part of add one Link at least
				do
				{
					cout << "|- Please enter vertex no. to link it : ";
					cin >> Option;

					cout << "+---------------------------------------------------------------------+" << endl;
					
					if (Option < 0 || Option >= SizeOfGraph - 1)
					{
						cout << "\a|- Wrong input, Input should be in the above range !" << endl;
						continue;
					}

					Edge[Option].push_back(SizeOfGraph - 1);
					Edge[SizeOfGraph - 1].push_back(Option);
					
					break;

				} while (true);

				// part of input distance
				cout << "|- Please enter distance between them : ";
				cin >> IntInput;
				Distance[Option].push_back(IntInput);
				Distance[SizeOfGraph - 1].push_back(IntInput);

			}

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- If you want to add another one enter (Y/y) : ";
			cin >> ExitOrNot;

			if (ExitOrNot == "Y" || ExitOrNot == "y")
			{
				cout << "+---------------------------------------------------------------------+" << endl;
				continue;
			}

			cout << "+---------------------------------------------------------------------+" << endl << endl;
			break;
		} while (true);
	}

	void AddEdge()
	{
		string ExitOrNot;
		if (SizeOfGraph > 1) {
			do
			{
				list<string> TempVertexList = Vertex;
				list<string> TempTownList = Town;
				int Option1;
				int Option2;
				int IntInput;

				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|                             Vertex Data                             |" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;

				for (int i = 0; i < SizeOfGraph; i++)
				{
					cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
					TempVertexList.pop_front();
					TempTownList.pop_front();
				}

				cout << "+---------------------------------------------------------------------+" << endl;

				do
				{
					cout << "|- Please enter vertex source no. : ";
					cin >> Option1;
					if (Option1 < 0 || Option1 >= SizeOfGraph)
					{
						cout << "\a|- Wrong input, Input should be in the above range !" << endl;
						continue;
					}
					cout << "+---------------------------------------------------------------------+" << endl;
					break;
				} while (true);

				list<int> DestinationList = Edge[Option1];

				if (DestinationList.size() < SizeOfGraph - 1) {
					TempVertexList = Vertex;
					TempTownList = Town;
					cout << "+---------------------------------------------------------------------+" << endl;
					cout << "|                              Graph Data                             |" << endl;
					cout << "+---------------------------------------------------------------------+" << endl;
					cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
					cout << "+---------------------------------------------------------------------+" << endl;
					
					for (int i = 0; i < SizeOfGraph; i++)
					{
						bool f = false;
						for (int DestinationData : DestinationList)
						{
							if (DestinationData == i)
							{
								f = true;
							}
						}
						if (!f && i != Option1)
						{
							cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
						}
						TempVertexList.pop_front();
						TempTownList.pop_front();
					}

					cout << "+---------------------------------------------------------------------+" << endl;

					do
					{
						bool f = false;
						cout << "|- Please enter vertex destenation no. : ";
						cin >> Option2;

						for (int DestinationData : DestinationList)
						{
							if (DestinationData == Option2 || Option2 == Option1 || Option2 >= SizeOfGraph || Option2 < 0)
							{
								f = true;
							}
						}

						if (f)
						{
							cout << "\a|- Wrong input, Input should be in the above range !" << endl;
							continue;
						}

						Edge[Option1].push_back(Option2);
						Edge[Option2].push_back(Option1);

						cout << "+---------------------------------------------------------------------+" << endl;
						break;
					} while (true);

					cout << "|- Please enter distance between them : ";
					cin >> IntInput;

					Distance[Option1].push_back(IntInput);
					Distance[Option2].push_back(IntInput);
				}
				else
				{
					cout << left << setw(70) << "|- you Can't Add Edge for this vertex !" << "|\a" << endl;
				}

				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|- If you want to add another one enter (Y/y) : ";
				cin >> ExitOrNot;

				if (ExitOrNot == "Y" || ExitOrNot == "y")
				{
					cout << "+---------------------------------------------------------------------+" << endl;
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl << endl;
				break;

			} while (true);
		}

		else
		{
			cout << left << setw(70) << "|- you Can't Add Edge Because there is less tow !" << "|\a" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- ";
			system("pause");
			cout << "+---------------------------------------------------------------------+" << endl << endl;
		}
	}


	//----------------------------------------------------------------------//
	void UpdateTown()
	{
		bool found;
		int Option;
		string ExitOrNot;
		string StringInput; // Town's Name

		do
		{
			list<string> TempVertexList = Vertex;
			list<string> TempTownList = Town;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                             Vertex Data                             |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			for (int i = 0; i < SizeOfGraph; i++)
			{
				cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
				TempVertexList.pop_front();
				TempTownList.pop_front();
			}
			cout << "+---------------------------------------------------------------------+" << endl;
			
			do
			{
				cout << "|- Please enter vertex no. : ";
				cin >> Option;

				if (Option < 0 || Option >= SizeOfGraph)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				break;
			} while (true);


			
			do
			{
				found = false;
				cout << "|- Please enter new Town's name : ";
				cin >> StringInput;

				for (string TownData : Town)
				{
					if (TownData == StringInput)
					{
						found = true;
						cout << "\a|- this vertex is already found !" << endl;
						break;
					}
				}
			} while (found);

			TempTownList = Town;
			int Counter = 0;

			Town.clear();

			for (string TempTownData : TempTownList)
			{
				if (Counter == Option)
				{
					Town.push_back(StringInput);
				}
				else {
					Town.push_back(TempTownData);
				}
				Counter++;
			}

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- If you want to update another one (Y/y) : ";
			cin >> ExitOrNot;

			if (ExitOrNot == "Y" || ExitOrNot == "y")
			{
				cout << "+---------------------------------------------------------------------+" << endl;
				continue;
			}
			cout << "+---------------------------------------------------------------------+" << endl << endl;
			break;
		} while (true);
	}

	void UpdateDistance()
	{
		bool Found;
		int IntInput; // Distance
		int Option1;
		int Option2;
		string ExitOrNot;

		do
		{
			list<string> TempVertexList = Vertex;
			list<string> TempTownList = Town;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                             Vertex Data                             |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			for (int i = 0; i < SizeOfGraph; i++)
			{
				cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
				TempVertexList.pop_front();
				TempTownList.pop_front();
			}

			cout << "+---------------------------------------------------------------------+" << endl;

			do
			{
				cout << "|- Please enter vertex no. : ";
				cin >> Option1;

				if (Option1 < 0 || Option1 >= SizeOfGraph)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				break;
			} while (true);

			TempVertexList = Vertex;
			TempTownList = Town;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                             Vertex Data                             |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			list<int> DestinationList = Edge[Option1];

			for (int i = 0; i < SizeOfGraph; i++)
			{
				Found = false;
				for (int DestinationData : DestinationList)
				{
					if (DestinationData == i)
					{
						Found = true;
						break;
					}
				}

				if (Found && i != Option1)
				{
					cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
				}

				TempVertexList.pop_front();
				TempTownList.pop_front();
			}
			cout << "+---------------------------------------------------------------------+" << endl;

			do
			{
				cout << "|- Please enter vertex destenation no. : ";
				cin >> Option2;

				Found = false;

				for (int DestinationData : DestinationList)
				{
					if (DestinationData == Option2)
					{
						Found = true;
					}
				}

				if (!Found)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				break;
			} while (true);

			list<int> TempList1 = Edge[Option1];
			list<int> TempList2 = Edge[Option2];

			// {a,b,c}

			// Edge[0] = {1}
			// Edge[1] = {0,2}
			// Edge[2] = {1}

			// Distance [0] = {5}
			// Distance [1] = {5,10}
			// Distance [2] = {10}



			int Possion1;
			int Possion2;

			int Counter = 0;
			for (int DestinationData : TempList1)
			{
				if (DestinationData == Option2)
				{
					Possion1 = Counter;
					break;
				}
				Counter++;
			}

			Counter = 0;

			for (int DestinationData : TempList2)
			{
				if (DestinationData == Option1)
				{
					Possion2 = Counter;
					break;
				}
				Counter++;
			}

			TempList1 = Distance[Option1];
			TempList2 = Distance[Option2];


			Distance[Option1].clear();
			Counter = 0;

			for (int DistanceData : TempList1)
			{
				if (Counter == Possion1)
				{
					cout << "+---------------------------------------------------------------------+" << endl;
					cout << "|- The Old Distance Between them : " << left << setw(35) << DistanceData << "|" << endl;
					cout << "+---------------------------------------------------------------------+" << endl;
					break;
				}
				Counter++;
			}

			cout << "|- Please enter the new distance between them : ";
			cin >> IntInput;

			Counter = 0;
			for (int DistanceData : TempList1)
			{
				if (Counter == Possion1)
				{
					Distance[Option1].push_back(IntInput);
				}
				else
				{
					Distance[Option1].push_back(DistanceData);
				}
				Counter++;
			}

			Counter = 0;
			Distance[Option2].clear();
			for (int DistanceData : TempList2)
			{
				if (Counter == Possion2)
				{
					Distance[Option2].push_back(IntInput);
					Counter++;
				}
				else
				{
					Distance[Option2].push_back(DistanceData);
					Counter++;
				}
			}

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- If you want to update another one (Y/y) : ";
			cin >> ExitOrNot;

			if (ExitOrNot == "Y" || ExitOrNot == "y")
			{
				cout << "+---------------------------------------------------------------------+" << endl;
				continue;
			}
			cout << "+---------------------------------------------------------------------+" << endl << endl;
			break;

		} while (true);
	}

	//----------------------------------------------------------------------//
	string PrintDestination(int IndexOfVertex)
	{
		// part of intialize and declere
		list<int> DestinationList = Edge[IndexOfVertex];
		string ReturnData = "";
		int Counter;

		// loop to Collect Destinations of this Vertex
		for (int DestinationData : DestinationList)
		{
			Counter = 0;
			for (string VertexData : Vertex)
			{
				if (Counter == DestinationData)
					ReturnData += VertexData + ",";
				Counter++;
			}
		}

		// return all Destinations Data as a string
		if (SizeOfGraph > 1)
		{
			return ReturnData.substr(0, ReturnData.size() - 1);
		}

		else
		{
			return "";
		}

	}

	string PrintPath(list<int> DestinationList)
	{
		// part of intialize and declere
		string ReturnData = "";
		int Counter;

		// loop to Collect Destinations of this Vertex
		for (int DestinationData : DestinationList)
		{
			Counter = 0;
			for (string TownData : Town)
			{
				if (Counter == DestinationData)
					ReturnData += TownData + "->";
				Counter++;
			}
		}

		// return all Destinations Data as a string
		return ReturnData.substr(0, ReturnData.size() - 2);
	}


	//----------------------------------------------------------------------//

	void First()
	{
		int Option1;
		int Option2;
		string ExitOrNot;
		do
		{
			list<string> TempVertexList = Vertex;
			list<string> TempTownList = Town;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                             Vertex Data                             |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			for (int i = 0; i < SizeOfGraph; i++)
			{
				cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
				TempVertexList.pop_front();
				TempTownList.pop_front();
			}

			cout << "+---------------------------------------------------------------------+" << endl;

			do
			{
				cout << "|- Please enter vertex no. : ";
				cin >> Option1;

				if (Option1 < 0 || Option1 >= SizeOfGraph)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				break;
			} while (true);

			TempVertexList = Vertex;
			TempTownList = Town;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                             Vertex Data                             |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			list<int> DestinationList = Edge[Option1];

			for (int i = 0; i < SizeOfGraph; i++)
			{
				if (i != Option1)
				{
					cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
				}
				TempVertexList.pop_front();
				TempTownList.pop_front();
			}
			cout << "+---------------------------------------------------------------------+" << endl;

			do
			{
				cout << "|- Please enter vertex destenation no. : ";
				cin >> Option2;

				if (Option2 < 0 || Option2 >= SizeOfGraph || Option2 == Option1)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				break;
			} while (true);

			//
			list<int>* DistanceGrid = new list<int>[SizeOfGraph - 1];
			list<int> PathList;
			list<int> HeaderList;
			list<int> ShortPathList;
			int ShortDistance = INT_MAX;
			int SmallDistance = INT_MAX;
			int LastDistance = 0;
			int CurrntVertex;
			int NextVertex = 0;
			int Counter;
			int Posstion;
			bool InPath;

			HeaderList.push_back(Option1);
			for (int i = 0; i < SizeOfGraph; i++)
			{
				if (i != Option1 && i != Option2)
				{
					HeaderList.push_back(i);
				}
			}
			HeaderList.push_back(Option2);



			PathList.push_back(Option1);

			for (int i = 0; i < SizeOfGraph; i++)
			{
				CurrntVertex = PathList.back();
				SmallDistance = INT_MAX;

				for (int HeaderData : HeaderList)
				{
					list<int> DestinationList = Edge[CurrntVertex];
					Posstion = -1;
					InPath = false;

					Counter = 0;
					for (int DestinationData : DestinationList)
					{
						if (DestinationData == HeaderData)
						{
							Posstion = Counter;
							break;
						}
						Counter++;
					}

					Counter = 0;
					for (int DestinationData : PathList)
					{
						if (DestinationData == HeaderData)
						{
							InPath = true;
							break;
						}
						Counter++;
					}
					if (InPath)
					{
						DistanceGrid[i].push_back(0);
					}
					else if (CurrntVertex == HeaderData)
					{
						DistanceGrid[i].push_back(0);
					}
					else if (Posstion >= 0)
					{
						Counter = 0;
						for (int DistanceData : Distance[CurrntVertex])
						{
							if (Counter == Posstion)
							{
								DistanceGrid[i].push_back(DistanceData + LastDistance);
								break;
							}
							Counter++;
						}
					}
					else
					{
						DistanceGrid[i].push_back(INT_MAX);
					}

					if (DistanceGrid[i].back() < SmallDistance && DistanceGrid[i].back() > 0)
					{
						SmallDistance = DistanceGrid[i].back();
						NextVertex = HeaderData;
					}
				}

				if (ShortDistance > DistanceGrid[i].back())
				{
					ShortDistance = DistanceGrid[i].back();
				}
				if (NextVertex == Option2)
				{
					break;
				}
				LastDistance = SmallDistance;
				PathList.push_back(NextVertex);
			}

			Counter = 0;

			for (int DestnitaionData : PathList)
			{
				ShortPathList.push_back(DestnitaionData);
				if (DistanceGrid[Counter].back() == ShortDistance)
				{
					break;
				}
				Counter++;
			}

			ShortPathList.push_back(Option2);

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(70) << "|- The Short path is : " + PrintPath(ShortPathList) << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- The Distance of Short path is : " << left << setw(35) << ShortDistance << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- ";
			system("pause");

			//

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- If you want to do another one (Y/y) : ";
			cin >> ExitOrNot;

			if (ExitOrNot == "Y" || ExitOrNot == "y")
			{
				cout << "+---------------------------------------------------------------------+" << endl;
				continue;
			}
			cout << "+---------------------------------------------------------------------+" << endl << endl;
			break;

		} while (true);
	}

	void Second()
	{
		int Option1;
		int Option2;
		string ExitOrNot;
		do
		{
			list<string> TempVertexList = Vertex;
			list<string> TempTownList = Town;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                             Vertex Data                             |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			for (int i = 0; i < SizeOfGraph; i++)
			{
				cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
				TempVertexList.pop_front();
				TempTownList.pop_front();
			}

			cout << "+---------------------------------------------------------------------+" << endl;

			do
			{
				cout << "|- Please enter vertex no. : ";
				cin >> Option1;

				if (Option1 < 0 || Option1 >= SizeOfGraph)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				break;
			} while (true);

			TempVertexList = Vertex;
			TempTownList = Town;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|                             Vertex Data                             |" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(10) << "|No." << setw(30) << "|Vertex" << setw(30) << "|Town's Name" << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;

			list<int> DestinationList = Edge[Option1];

			for (int i = 0; i < SizeOfGraph; i++)
			{
				if (i != Option1)
				{
					cout << "|" << left << setw(9) << i << setw(30) << "|" + TempVertexList.front() << setw(30) << "|" + TempTownList.front() << "|" << endl;
				}

				TempVertexList.pop_front();
				TempTownList.pop_front();
			}
			cout << "+---------------------------------------------------------------------+" << endl;

			do
			{
				cout << "|- Please enter vertex destenation no. : ";
				cin >> Option2;

				if (Option2 < 0 || Option2 >= SizeOfGraph || Option2 == Option1)
				{
					cout << "\a|- Wrong input, Input should be in the above range !" << endl;
					continue;
				}
				cout << "+---------------------------------------------------------------------+" << endl;
				break;
			} while (true);

			//
			list<int> *DistanceGrid = new list<int>[SizeOfGraph - 1];
			list<int> PathList;
			list<int> HeaderList;
			list<int> ShortPathList;
			int ShortDistance = INT_MAX;
			int SmallDistance = INT_MAX;
			int LastDistance = 0;
			int CurrntVertex;
			int NextVertex = 0;
			int Counter;
			int Posstion;
			bool InPath;

			HeaderList.push_back(Option1);
			for (int i = 0; i < SizeOfGraph; i++)
			{
				if (i != Option1 && i != Option2)
				{
					HeaderList.push_back(i);
				}
			}
			HeaderList.push_back(Option2);

			PathList.push_back(Option1);
			
			for (int i = 0; i < SizeOfGraph; i++)
			{
				CurrntVertex = PathList.back();
				SmallDistance = INT_MAX;

				for (int HeaderData : HeaderList)
				{
					list<int> DestinationList = Edge[CurrntVertex];
					Posstion = -1;
					InPath = false;

					Counter = 0;
					for (int DestinationData : DestinationList)
					{
						if (DestinationData == HeaderData)
						{
							Posstion = Counter;
							break;
						}
						Counter++;
					}

					Counter = 0;
					for (int DestinationData : PathList)
					{
						if (DestinationData == HeaderData)
						{
							InPath = true;
							break;
						}
						Counter++;
					}
					if (InPath)
					{
						DistanceGrid[i].push_back(0);
					}
					else if (CurrntVertex == HeaderData)
					{
						DistanceGrid[i].push_back(0);
					}
					else if (Posstion >= 0)
					{
						Counter = 0;
						for (int DistanceData : Distance[CurrntVertex])
						{
							if (Counter == Posstion)
							{
								DistanceGrid[i].push_back(DistanceData + LastDistance);
								break;
							}
							Counter++;
						}
					}
					else
					{
						DistanceGrid[i].push_back(INT_MAX);
					}

					if (DistanceGrid[i].back() < SmallDistance && DistanceGrid[i].back() > 0)
					{
						SmallDistance = DistanceGrid[i].back();
						NextVertex = HeaderData;
					}
				}

				if (ShortDistance > DistanceGrid[i].back())
				{
					ShortDistance = DistanceGrid[i].back();
				}
				if (NextVertex == Option2)
				{
					break;
				}
				LastDistance = SmallDistance;
				PathList.push_back(NextVertex);
			}

			Counter = 0;

			for (int DestnitaionData : PathList)
			{
				ShortPathList.push_back(DestnitaionData);
				if (DistanceGrid[Counter].back() == ShortDistance)
				{
					break;
				}
				Counter++;
			}

			ShortPathList.push_back(Option2);

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << left << setw(70) << "|- The Short path is : " + PrintPath(ShortPathList) << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- The Distance of Short path is : " << left << setw(35) << ShortDistance << "|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- ";
			system("pause");
			
			//
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|- If you want to do another one (Y/y) : ";
			cin >> ExitOrNot;

			if (ExitOrNot == "Y" || ExitOrNot == "y")
			{
				cout << "+---------------------------------------------------------------------+" << endl;
				continue;
			}
			cout << "+---------------------------------------------------------------------+" << endl << endl;
			break;

		} while (true);
	}
};

//----------------------------------------------------------------------//

int main()
{
	Graph GraphOBJ;
	int Option;

	do
	{
		// part of display
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "|                              Graph Task                             |" << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << left << setw(70) << "|- 1) Add Data To Graph" << "|" << endl;
		cout << left << setw(70) << "|- 2) Update Graph Data" << "|" << endl;
		cout << left << setw(70) << "|- 3) Delete Graph" << "|" << endl;
		cout << left << setw(70) << "|- 4) Display Graph Data" << "|" << endl;
		cout << left << setw(70) << "|- 5) Find shortest Path" << "|" << endl;
		cout << left << setw(70) << "|- 6) Exit" << "|" << endl;
		cout << "+---------------------------------------------------------------------+" << endl;

		// to check if right input or not
		do
		{
			cout << "|- Please enter option (1-6) : ";
			cin >> Option;
			if (Option <= 0 || Option > 6)
			{
				cout << left << setw(70) << "|- Wrong input, Input should be between (1-6) !" << endl;
				continue;
			}
			break;
		} while (true);

		cout << "+---------------------------------------------------------------------+" << endl << endl;

		//Select what happen from option
		if (Option == 1) {
			GraphOBJ.AddMenu();
			continue;
		}

		else if (Option == 2) {
			GraphOBJ.UpdateMenu();
			continue;
		}
		else if (Option == 3) {
			GraphOBJ.DeleteMenu();
			continue;
		}
		else if (Option == 4)
		{
			GraphOBJ.DisplayMenu();
			continue;
		}
		else  if (Option == 5) {
			GraphOBJ.FindShortPath();
			continue;
		}

		else
			break;

	} while (true);

	// Screen when exit from program
	cout << "+---------------------------------------------------------------------+" << endl;
	cout << left << setw(70) << "|- Thanks for using this program." << "|" << endl;
	cout << "+---------------------------------------------------------------------+" << endl << endl;
	cout << "+---------------------------------------------------------------------+" << endl;
	cout << "|- ";
	system("pause");
	cout << "+---------------------------------------------------------------------+" << endl;

	// to clear Data from memory
	return 0;
}

//----------------------------------------------------------------------//