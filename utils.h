#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "webGraph.h"

using namespace std;

/// <summary>
/// utilties class
/// contains all functions unrelated to other classes
/// </summary>
class utils
{
public:

	/// <summary>
	/// parses webpages from csv files 
	/// </summary>
	/// <returns>vector of webpages</returns>
	static vector<webpage*> parse_webpages();

	/// <summary>
	/// parses edges csv
	/// </summary>
	/// <returns></returns>
	static pair<vector<webEdge*>, vector<webpage*>> parse_webEdges();

	/// <summary>
	/// intialization of the graph of webpages
	/// </summary>
	/// <returns>pointer to webGraph</returns>
	static webGraph* intialize_webGraph();

	/// <summary>
	/// normalizes the search query into a vector of strings
	/// each string is a keyword or a token
	/// </summary>
	/// <param name="qry">query as a string</param>
	/// <returns>vector of string</returns>
	static vector<string> normalizeQry(string qry);

	/// <summary>
	/// updates files with new calues of impressions and clickthroughs after user session
	/// </summary>
	/// <param name="g">graph intialized in main</param>
	static void write_to_files(webGraph* g);


	
};
