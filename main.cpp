#include "webGraph.h"
#include "utils.h"

using namespace std;

//max search query character input
#define MAX_QUERY_INPUT 100

//definitions
void clear_console();
void main_menu(webGraph*);
void view_menu(webGraph*, map<int, webpage*>&,int , bool&);
void search_menu(webGraph*, map<int, webpage*> , bool&);

/// <summary>
/// clears console
/// </summary>
void clear_console()
{
	cout << "\x1B[2J\x1B[H";
}

/// <summary>
/// main menu
/// </summary>
/// <param name="g">initialized with graph from main</param>
void main_menu(webGraph* g)
{
	int userChoice;
	bool NewSearch = true;
	cout << "Welcome!\nWhat would you like to do?\n1. New Search\n2. Exit\n\nType in your choice: ";
	cin >> userChoice;

	switch (userChoice)
	{
	case(1):
		search_menu(g, {}, NewSearch);
		break;
	case(2):
		cout << "\nExiting program...";
		utils::write_to_files(g);
		exit(1);
	}
}

/// <summary>
/// search menu
/// </summary>
/// <param name="g">graph that is initialized in main</param>
/// <param name="indexedResutls">search results with their indexes in menu</param>
/// <param name="NewSearch">boolean if user will do a newsearch</param>
void search_menu(webGraph* g, map<int, webpage*> indexedResutls, bool& NewSearch)
{
	int userChoice;
	clear_console();
	if (NewSearch)
	{
		char str[MAX_QUERY_INPUT];
		cin.ignore();
		cout << "\nEnter your search query: \n";
		cin.getline(str, MAX_QUERY_INPUT);

		auto results = g->search(utils::normalizeQry(str));

		cout << "\nYour Results\n";
		int index = 1;
		for (auto webpage : results)
		{
			indexedResutls[index] = webpage;
			webpage->_impressions++;
			webpage->update_score();
			cout << index << ". " << webpage->_url << " score: " << webpage->_score << "\n";
			index++;
		}

		cout << "\n\n Would you like to: \n1. Choose a webpage to open\n2. Do a new search\n3. Exit\n";
		cout << "Type in your Choice: ";
		cin >> userChoice;

		int webIndex;
		switch (userChoice)
		{ 
		case(1):
			cout << "\nChoose your webpage index: \n";
			cin >> webIndex;
			view_menu(g, indexedResutls, webIndex, NewSearch);

			break;
		case(2):
			NewSearch = true;
			indexedResutls = {};
			clear_console();
			search_menu(g, {}, NewSearch);
			break;
		case(3):
			cout << "\nExiting program...";
			utils::write_to_files(g);
			exit(1);
		}
	}
	else
	{
		cout << "\nYour Results\n";
		int index = 1;
		for (auto webpage : indexedResutls)
		{
			cout << index << ". " << webpage.second->_url << " score: " << webpage.second->_score << "\n";
			index++;
		}

		cout << "\n\n Would you like to: \n1. Choose a webpage to open\n2. Do a new search\n3. Exit\n";
		cout << "Type in your Choice: ";
		cin >> userChoice;

		int webIndex;
		switch (userChoice)
		{
		case(1):
			cout << "\nChoose your webpage index: \n";
			cin >> webIndex;
			view_menu(g, indexedResutls, webIndex, NewSearch);

			break;
		case(2):
			NewSearch = true;
			indexedResutls = {};
			search_menu(g, {}, NewSearch);

			break;
		case(3):
			cout << "\nExiting program...";
			utils::write_to_files(g);
			exit(1);
		}
	}
}

/// <summary>
/// viewing menu
/// </summary>
/// <param name="g"> graph that is intialized in main</param>
/// <param name="results">search results</param>
/// <param name="index">chosen result inde</param>
/// <param name="NewSearch">boolean if user will do a new search</param>
void view_menu(webGraph* g, map<int, webpage*>& results, int index, bool& NewSearch)
{
	int userChoice;
	clear_console();
	results[index]->_clickThroughs++;
	results[index]->update_score();
	cout << "You're viewing: " << results[index]->_url;
	cout << "\nWould you like to: \n1. Back to search results\n2. New search\n3. Exit\n\nType in your choice: ";
	cin >> userChoice;
	
	switch (userChoice)
	{
	case(1):
		NewSearch = false;
		search_menu(g, results, NewSearch);
		return;
	case(2):
		NewSearch = true;
		results = {};
		search_menu(g, results, NewSearch);
		return;
	case(3):
		cout << "\nExiting program...";
		utils::write_to_files(g);
		exit(1);
	}

}

int main()
{
	webGraph* webGraph = utils::intialize_webGraph();
	map<int, webpage*> indexedSearchResults; 
	main_menu(webGraph);

	return 0;
}
