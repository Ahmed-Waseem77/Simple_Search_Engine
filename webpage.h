#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class webpage
{
public:
	string _url;
	vector<string> _keywords; 
	int _impressions;
	int _clickThroughs;
	float _ctr;
	float _rank;
	float _score;

	//constructors//

	/// <summary>
	/// constructor of webpage
	/// </summary>
	webpage();

	/// <summary>
	/// parameterized constructor of webpage
	/// </summary>
	/// <param name="url">string of url</param>
	/// <param name="keywords">vector of keywords</param>
	/// <param name="impressions">impressions of webpage</param>
	/// <param name="clickthr">click throughs of a webpage</param>
	/// <param name="ctr">click through rate of a webpage</param>
	/// <param name="rank">page rank</param>
	/// <param name="score">score</param>
	webpage(string url, vector<string> keywords, int impressions, int clickthr, float ctr, float rank, float score);
	
	//methods//

	/// <summary>
	/// updates click through rate
	/// </summary>
	void update_ctr();

	/// <summary>
	/// updates score
	/// </summary>
	void update_score();

	//comparator overloads//
	bool operator<(const webpage& rhs) const noexcept { return this->_score < rhs._score; }
	bool operator>(const webpage& rhs) const noexcept { return this->_score > rhs._score; }
	bool operator<=(const webpage& rhs) const noexcept { return !(this->_score > rhs._score); }
	bool operator>=(const webpage& rhs) const noexcept { return !(this->_score < rhs._score); }

	//stream operators
	friend ostream& operator<<(ostream& os, const webpage& dt);
	friend istream& operator>>(istream& os, webpage& wp);



};
