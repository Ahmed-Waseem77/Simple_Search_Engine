
#include "webGraph.h"

webGraph::webGraph()
{
    _adjList = {};
    _visited = {};
    _finished = {};
    _searchList = {};
}

webGraph::webGraph(vector<webEdge*> const& edges, map<string, set<webpage*>> searchList)
{
    _visited = {};
    _finished = {};
    _searchList = searchList;

    for (auto i = edges.begin(); i != edges.end(); i++)
    {
        _adjList[(*i)->_source].push_back((*i)->_destination);
    }
}

void webGraph::add_edge(webpage* src, webpage* dst)
{
    _adjList[src].push_back(dst);
}

void webGraph::dfs(webpage* n)
{
    _visited[n] = true;

    list<webpage*>::iterator i;
    for (i = _adjList[n].begin(); i != _adjList[n].end(); ++i)
    {
        if (!_visited[*i])
        {
            dfs(*i);
        }
    }
    _finished.push_back(n);
}

void webGraph::print_graph()
{
    for (auto i = _adjList.begin(); i != _adjList.end(); i++)
    {
        cout << (*i).first->_url << " --> ";

        for (auto j = (*i).second.begin(); j != (*i).second.end(); j++)
        {
            cout << (*j)->_url << " ";
        }
        cout << "\n";
    }
}

void webGraph::print_webpages_content()
{
    for (auto i = _adjList.begin(); i != _adjList.end(); i++)
    {
        cout << *(i->first) << "\n\n";
    }
}

webGraph webGraph::transpose()
{
    webGraph transpose;

    for (auto it = _adjList.begin(); it != _adjList.end(); it++)
    {
        for (auto jt = (*it).second.begin(); jt != (*it).second.end(); jt++)
            transpose.add_edge(*jt, (*it).first);
    }

    return transpose;
}

int webGraph::size()
{
    return _adjList.size();
}

map<webpage*, float> webGraph::calculate_ranks_iteration(webGraph* transpose, set<webpage*> sinkNodes)
{
    //temporary vector to store calculated ranks
    map<webpage*, float> rankstemp;
    float sumOfSinkNodesPR = 0;
    float sumOfPR = 0;
    float s = 1;

    for (auto i : sinkNodes)
    {
        sumOfSinkNodesPR += i->_rank;
    }

    //where s is the summation of sink nodes PR over the number of nodes in webgraph

    s = (float)(sumOfSinkNodesPR / _adjList.size())*DAMPING_FACTOR;

    for (auto it = _adjList.begin(); it != _adjList.end(); it++)
    {
        //for every webpage in the map its PR is the sum of the Ingoing Nodes' PRs (outgoing since we are looping on transpose) over their number
        for (auto li = transpose->_adjList[(*it).first].begin(); li != transpose->_adjList[(*it).first].end(); li++)
        {
            sumOfPR += (float)(*li)->_rank / (float)_adjList[*li].size();
            rankstemp[(*it).first] += (float)(*li)->_rank / (float)_adjList[*li].size();
        }

        rankstemp[(*it).first] += s;
        rankstemp[(*it).first] *= DAMPING_FACTOR;
    }
    sumOfPR += s;
    sumOfPR * DAMPING_FACTOR;
    return rankstemp;
}

bool cmp(pair<webpage*, float>& a, pair<webpage*, float>& b)
{
    return a.first->_rank < b.first->_rank;
}

vector<pair<webpage*, float>> sort(map<webpage*, float>& M)
{
    vector<pair<webpage*, float>> A;

    for (auto& it : M) {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);

    return A;
}

set<webpage*> webGraph::get_sinkNodes(webGraph* transpose)
{
    //getting sinkNodes

    bool found = false;
    set<webpage*> sinkNodesPr;

    for (keyIt graphIt = _adjList.begin(); graphIt != _adjList.end(); graphIt++)
    {
        for (keyIt transposeIt = transpose->_adjList.begin(); transposeIt != transpose->_adjList.end(); transposeIt++)
        {
            if (*graphIt == *transposeIt)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            sinkNodesPr.insert(*graphIt);
        }

        found = false;
    }

    return sinkNodesPr;
}

void webGraph::calculate_ranks()
{
    //moved transpose from calculate_ranks_iteration to avoid calculating transpose every iteration
    webGraph transpose = this->transpose();

    map<webpage*, float> rankstemp;
    map<webpage*, float> rankstemp2;
    

    //PR intialization
    for (auto it = _adjList.begin(); it != _adjList.end(); it++)
    {
        (*it).first->_rank = (float)(1.0 - DAMPING_FACTOR) / (float) _adjList.size();
    }

    set<webpage*> RanksSinkNodes = this->get_sinkNodes(&transpose);

    //iterations to size - 2 ( -2 because iteration 0 is already done )
    for (int i = 0; i < _adjList.size() - 1; i++)
    {
        rankstemp = this->calculate_ranks_iteration(&transpose, RanksSinkNodes);
        
        if (rankstemp == rankstemp2)
        {
            break;
        }
        else
        {
            //ranks updated with calculated ranks
            for (auto it = _adjList.begin(); it != _adjList.end(); it++)
            {
                (*it).first->_rank = (float)rankstemp[(*it).first];
            } 
            rankstemp2 = this->calculate_ranks_iteration(&transpose, RanksSinkNodes); 
            i++;
        }
    }

    //normalizing pageranks
    auto norm = sort(rankstemp);
    int temp = 1;
    for (auto i = norm.begin(); i != norm.end(); i++)
    {
        if ((i + 1) != norm.end() && (*i).first->_rank == (*(i + 1)).first->_rank )
        {
            (*i).first->_rank = temp;
            (*(i + 1)).first->_rank = temp;
            i++;
        }
        else
        {
            (*i).first->_rank = temp;
        }

        temp++;
    }

}

void webGraph::calculate_ctr()
{
    for (auto it = _adjList.begin(); it != _adjList.end(); it++)
    {
        (*it).first->update_ctr();
    }
}

void webGraph::calculate_scores() 
{
    this->calculate_ctr();
    this->calculate_ranks();

    for (auto it = _adjList.begin(); it != _adjList.end(); it++)
    {
        (*it).first->_score = ((float)0.4 * (*it).first->_rank) + ((1.0 - (0.1 * (*it).first->_impressions / (1.0 + 0.1 * (*it).first->_impressions)) * (*it).first->_rank) + (*it).first->_ctr) * 0.6;
    }
}

bool cmp_score(webpage*& a, webpage*& b)
{
    return a->_score > b->_score;
}

vector<webpage*> webGraph::search(vector<string> normalizedQry)
{
    set<webpage*> searchResults;
    vector<webpage*> searchResultsProper;
    set<webpage*> temp;
    for (auto it = normalizedQry.begin(); it != normalizedQry.end(); it++)
    {
        if (*it != "AND" && *it != "OR")
        {
            searchResults = _searchList[*it];
        }
        else if (*it == "AND")
        {
            it++;
            set_intersection(searchResults.begin(), searchResults.end(), _searchList[*it].begin(), _searchList[*it].end(), inserter(temp, temp.end()));
            searchResults = temp;
            temp = {};
        }
        else //if token is OR
        {
            it++;
            set_union(searchResults.begin(), searchResults.end(), _searchList[*it].begin(), _searchList[*it].end(), inserter(temp, temp.end()));
            searchResults = temp;
            temp = {};
        }
    }

    for (auto i : searchResults)
    {
        for (keyIt it = _adjList.begin(); it != _adjList.end(); it++)
        {
            if (i->_url == (*it)->_url)
            {
                searchResultsProper.push_back(*it);
            }
        }
    }

    //updating impressions

    for (auto i : searchResultsProper)
    {
        i->_impressions++;
    }

    sort(searchResultsProper.begin(), searchResultsProper.end(), cmp_score);

    return searchResultsProper;
}
