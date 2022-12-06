#pragma once

#include "webpage.h"
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

#define DAMPING_FACTOR 0.15

/// <summary>
/// iterator class to iterate on map keys
/// used for ease of coding
/// </summary>
struct keyIt : public map<webpage*, list<webpage*>>::iterator
{
    keyIt() : map<webpage*, list<webpage*>>::iterator() {}
    keyIt(map<webpage*, list<webpage*>>::iterator it) : map<webpage*, list<webpage*>>::iterator(it) {}
    webpage* operator*() { return map<webpage*, list<webpage*>>::iterator::operator*().first; }

};

/// <summary>
/// webEdge class
/// </summary>
class webEdge
{
public:

    webpage* _source;
    webpage* _destination;

    webEdge(webpage* src, webpage* dst)
    {
        _source = src;
        _destination = dst;
    }
};

/// <summary>
/// graph of webpages implemented as an adjacency list
/// </summary>
class webGraph
{
public:
    //pointers to webpage to avoid having instances of webpage and bloating memory
    map<webpage*, bool> _visited;
    vector<webpage*> _finished;
    map<webpage*, list<webpage*>> _adjList;
    map<string, set<webpage*>> _searchList;

    //constructors

    /// <summary>
    /// constructor
    /// </summary>
    webGraph();

    /// <summary>
    /// parameterized constructor
    /// </summary>
    /// <param name="edges">vector of webEdges</param>
    /// <param name="searchList">search list of keyword keys and a set of webpages</param>
    webGraph(vector<webEdge*> const& edges, map<string, set<webpage*>> searchList);

    //methods

    /// <summary>
    /// adds an edge to the graph
    /// </summary>
    /// <param name="src">source edge</param>
    /// <param name="dst">destination edge</param>
    void add_edge(webpage* src, webpage* dst);

    /// <summary>
    /// dfs search: not used
    /// </summary>
    /// <param name="n">node</param>
    void dfs(webpage* n);

    /// <summary>
    /// prints graph as a webpage pointing to another
    /// </summary>
    void print_graph();

    /// <summary>
    /// prints graph's webpage content
    /// </summary>
    void print_webpages_content();
    
    int size();

    /// <summary>
    /// retrieves sink webpages in a graph
    /// </summary>
    /// <param name="transpose">the transpose of graph</param>
    /// <returns>returns set of sink webpages</returns>
    set<webpage*> get_sinkNodes(webGraph* transpose);

    /// <summary>
    /// gets the transpose of the graph
    /// </summary>
    /// <returns>the transpose of the graph</returns>
    webGraph transpose();

    /// <summary>
    /// calculates all the ctr of a graph (used in initialization)
    /// </summary>
    void calculate_ctr();

    /// <summary>
    /// calculates one iteration of page rank with a damping factor of 0.15
    /// </summary>
    /// <param name="transpose">transpose of the graph</param>
    /// <param name="sinkNodes">sink webpages</param>
    /// <returns>returns the webpages with their page rank results for the iteration</returns>
    map<webpage*, float> calculate_ranks_iteration(webGraph* transpose, set<webpage*> sinkNodes);

    /// <summary>
    /// calculates rank until there is no longer a change in pagerank (used in initialization)
    /// </summary>
    void calculate_ranks();

    /// <summary>
    /// calculates scores of all webpages (used in initialization)
    /// </summary>
    void calculate_scores();

    /// <summary>
    /// searches for webpages in a graph given a query
    /// </summary>
    /// <param name="normalizedQry">The normalized query</param>
    /// <returns>vector of webpages</returns>
    vector<webpage*> search(vector<string> normalizedQry);

};