
#include "webpage.h"

webpage::webpage()
{
	_url = "";
	_keywords = {};
	_impressions = 0;
	_clickThroughs = 0;
	_ctr = 0;
	_rank = 0;
	_score = 0;
}

webpage::webpage(string url, vector<string> keywords, int impressions, int clickthr, float ctr, float rank, float score)
{
	_url = url;
	_keywords = keywords;
	_impressions = impressions;
	_clickThroughs = clickthr;
	_ctr = ctr;
	_rank = rank;
	_score = score;
}

/// <summary>
/// updates webpage's click through rate
/// </summary>
void webpage::update_ctr()
{
	_ctr = ((float)_clickThroughs / _impressions) * 100;
}

/// <summary>
/// updates webpage's score
/// </summary>
void webpage::update_score()
{
	update_ctr();
	_score = ((float)0.4 * _rank) + ((1.0 - (0.1 * _impressions / (1.0 + 0.1 * _impressions)) * _rank) + _ctr) * (float) 0.6;
}

//////////////////////////overloads///////////////////////////

/// <summary>
/// out stream operator overload
/// </summary>
/// <param name="os">out stream</param>
/// <param name="wp">webpage</param>
/// <returns></returns>
ostream& operator<<(ostream& os, const webpage& wp)
{
	os << wp._url << "\n";
	os <<" | rank: " << wp._rank << " | score: " << wp._score << "\n";
	for (auto i : wp._keywords)
	{
		os << i << " ";
	}
	return os;
}

/// <summary>
/// in stream operator overload
/// </summary>
/// <param name="is">in stream</param>
/// <param name="wp">webpage</param>
/// <returns></returns>
istream& operator>>(istream& is, webpage& wp)
{
	is >> wp._url >> wp._impressions >> wp._ctr >> wp._rank >> wp._score;
	return is;
}

