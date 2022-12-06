#define _CRT_SECURE_NO_DEPRECATE

#include "utils.h"
#include <string>
#include <string.h>
#include <sstream>
#include <cstdio>
#include <set>

vector<webpage*> utils::parse_webpages()
{
	//getting webpages and their impressions to intialize them//

	fstream keywordsIN, impressionsIN, clickThroughsIN;

	keywordsIN.open("keywords.csv", ios::in);
	impressionsIN.open("impressions.csv", ios::in);
	clickThroughsIN.open("clickThroughs.csv", ios::in);

	vector<vector<string>> rows;
	vector<string> tmp, keywords;
	vector<float> impressions;
	vector<int> clickThroughs;
	vector<webpage*> webpages;
	string row, url, cell;
	int j = 0;

	//webpages and keywords
	while (getline(keywordsIN, row))
	{
		for (int i = 0; i < row.size(); i++)
		{
			//checks if there is a comma if so pushes back the first column content
			if (row[i] == ',')
			{
				tmp.push_back(cell);
				i++;
				cell = "";
			}
			cell += row[i];

			//checks end of line
			if (i == row.size() - 1 && row != "")
			{
				tmp.push_back(cell);
				cell = "";
			}

		}
		rows.push_back(tmp);
		tmp = {};
	}

	//impressions
	while (getline(impressionsIN, row))
	{
		for (int i = 0; i < row.size(); i++)
		{
			if (row[i] == ',')
			{
				i++;
				cell = "";
			}
			cell += row[i];

			if (i == row.size() - 1 && row != "")
			{
				impressions.push_back(stof(cell));
				cell = "";
			}
		}
	}

	while (getline(clickThroughsIN, row))
	{
		for (int i = 0; i < row.size(); i++)
		{
			if (row[i] == ',')
			{
				i++;
				cell = "";
			}
			cell += row[i];

			if (i == row.size() - 1 && row != "")
			{
				clickThroughs.push_back(stof(cell));
				cell = "";
			}
		}
	}

	keywordsIN.close();

	//intialization
	webpages.resize(rows.size());

	for (int i = 0; i < rows.size(); i++)
	{
		url = rows[i][0];

		for (int j = 1; j < rows[i].size(); j++)
		{
			keywords.push_back(rows[i][j]);
		}

		webpage* tmpWp = new webpage(url, keywords, impressions[i], clickThroughs[i], 0, 0, 0);
		keywords = {};
		webpages[i] = tmpWp;
	}
	impressionsIN.close();

	return webpages;
}

pair<vector<webEdge*>, vector<webpage*>> utils::parse_webEdges()
{
	vector<webpage*> webpages = parse_webpages();

	//getting edges and constructing graph//
	fstream edgesIN;
	string row, cell;
	vector<string> tmp;
	vector<vector<string>> rows;
	vector<webEdge*> webEdges;

	edgesIN.open("edges.csv", ios::in);

	//getting edges data//
	while (getline(edgesIN, row))
	{
		for (int i = 0; i < row.size(); i++)
		{
			//checks if there is a comma if so pushes back the first column content
			if (row[i] == ',')
			{
				tmp.push_back(cell);
				i++;
				cell = "";
			}
			cell += row[i];

			if (i == row.size() - 1)
			{
				tmp.push_back(cell);
				cell = "";
			}
		}
		rows.push_back(tmp);
		tmp = {};
	}

	//constructing webedges//
	webpage* src = new webpage();
	webpage* dst = new webpage();

	for (int i = 0; i < rows.size(); i++)
	{
		for (auto k : webpages)
		{
			if (rows[i][0] == (*k)._url)
			{
				src = k;
			}

			if (rows[i].size() != 1 && rows[i][1] == (*k)._url)
			{
				dst = k;
			}
		}
		webEdge* tmpEdge = new webEdge(src, dst);
		webEdges.push_back(tmpEdge);
	}

	return { webEdges, webpages };
}

webGraph* utils::intialize_webGraph()
{
	vector<webEdge*> webEdges = parse_webEdges().first;
	vector<webpage*> webpagesVec = parse_webEdges().second;

	set<webpage*> webpages(webpagesVec.begin(), webpagesVec.end());

	//intializing _searchList of webGraph//
	map<string, set<webpage*>> searchList;
	for (auto i : webpages)
	{
		for (auto j : i->_keywords)
		{
			searchList[j].insert(i);
		}
	}

	//intializing webGraph//
	webGraph* g = new webGraph(webEdges, searchList);

	g->calculate_scores();

	return g;
}

vector<string> utils::normalizeQry(string qry)
{
	vector<string> normalizedQry;
	istringstream stream(qry);
	string s;

	//normalizes spaces
	while (getline(stream, s, ' ')) {
		normalizedQry.push_back(s);
	}

	string temp;
	bool insideQuote = false;

	//normalizes quotations
	for (auto string = normalizedQry.begin(); string != normalizedQry.end(); string++)
	{
		if ((*string)[0] == '\"')
		{
			(*string).erase((*string).begin());

			while ((*string).back() != '\"')
			{
				temp = *string;
				string = normalizedQry.erase(string);
				*string = temp + " " + *string;
			}
		}
		if ((*string).back() == '\"')
		{
			(*string).pop_back();
		}
	}

	//normalising default or
	
	for (auto key = normalizedQry.begin(); key != normalizedQry.end() - 1; key++)
	{
		
		if (*key != "OR" && *key != "AND" && *(key + 1) != "OR" && *(key + 1) != "AND")
		{
			key = normalizedQry.insert(key + 1, "OR");
		}
	}

	return normalizedQry;
}

void utils::write_to_files(webGraph* g)
{
	fstream clickThroughsOUT, impressionsOUT;

	clickThroughsOUT.open("clickThroughs.csv", ios::out | ofstream::trunc);
	impressionsOUT.open("impressions.csv", ios::out | ofstream::trunc);

	for (auto i : g->_adjList)
	{
		clickThroughsOUT << i.first->_url << ","  <<i.first->_clickThroughs <<"\n";
		impressionsOUT << i.first->_url << "," << i.first->_impressions <<"\n";
	}

	return;
}



