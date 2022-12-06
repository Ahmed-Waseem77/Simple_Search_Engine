<?xml version="1.0"?><doc>
<members>
<member name="M:webpage.#ctor" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.h" line="21">
<summary>
constructor of webpage
</summary>
</member>
<member name="M:webpage.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.vector&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.allocator&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignU" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.h" line="26">
<summary>
parameterized constructor of webpage
</summary>
<param name="url">string of url</param>
<param name="keywords">vector of keywords</param>
<param name="impressions">impressions of webpage</param>
<param name="clickthr">click throughs of a webpage</param>
<param name="ctr">click through rate of a webpage</param>
<param name="rank">page rank</param>
<param name="score">score</param>
</member>
<member name="M:webpage.update_ctr" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.h" line="40">
<summary>
updates click through rate
</summary>
</member>
<member name="M:webpage.update_score" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.h" line="45">
<summary>
updates score
</summary>
</member>
<member name="T:keyIt" decl="false" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="15">
<summary>
iterator class to iterate on map keys
used for ease of coding
</summary>
</member>
<member name="T:webEdge" decl="false" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="27">
<summary>
webEdge class
</summary>
</member>
<member name="T:webGraph" decl="false" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="44">
<summary>
graph of webpages implemented as an adjacency list
</summary>
</member>
<member name="M:webGraph.#ctor" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="58">
<summary>
constructor
</summary>
</member>
<member name="M:webGraph.#ctor(std.vector&lt;webEdge**,std.allocator&lt;webEdge**&gt;&gt;!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,std.map&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.set&lt;webpage**,std.less&lt;webpage**&gt;,std.allocator&lt;webpage**&gt;&gt;,std.less&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;&gt;,std.allocator&lt;std.pair&lt;std.basi" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="63">
<summary>
parameterized constructor
</summary>
<param name="edges">vector of webEdges</param>
<param name="searchList">search list of keyword keys and a set of webpages</param>
</member>
<member name="M:webGraph.add_edge(webpage*,webpage*)" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="72">
<summary>
adds an edge to the graph
</summary>
<param name="src">source edge</param>
<param name="dst">destination edge</param>
</member>
<member name="M:webGraph.dfs(webpage*)" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="79">
<summary>
dfs search: not used
</summary>
<param name="n">node</param>
</member>
<member name="M:webGraph.print_graph" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="85">
<summary>
prints graph as a webpage pointing to another
</summary>
</member>
<member name="M:webGraph.print_webpages_content" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="90">
<summary>
prints graph's webpage content
</summary>
</member>
<member name="M:webGraph.get_sinkNodes(webGraph*)" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="97">
<summary>
retrieves sink webpages in a graph
</summary>
<param name="transpose">the transpose of graph</param>
<returns>returns set of sink webpages</returns>
</member>
<member name="M:webGraph.transpose" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="104">
<summary>
gets the transpose of the graph
</summary>
<returns>the transpose of the graph</returns>
</member>
<member name="M:webGraph.calculate_ctr" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="110">
<summary>
calculates all the ctr of a graph (used in initialization)
</summary>
</member>
<member name="M:webGraph.calculate_ranks_iteration(webGraph*,std.set&lt;webpage**,std.less&lt;webpage**&gt;,std.allocator&lt;webpage**&gt;&gt;)" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="115">
<summary>
calculates one iteration of page rank with a damping factor of 0.15
</summary>
<param name="transpose">transpose of the graph</param>
<param name="sinkNodes">sink webpages</param>
<returns>returns the webpages with their page rank results for the iteration</returns>
</member>
<member name="M:webGraph.calculate_ranks" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="123">
<summary>
calculates rank until there is no longer a change in pagerank (used in initialization)
</summary>
</member>
<member name="M:webGraph.calculate_scores" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="128">
<summary>
calculates scores of all webpages (used in initialization)
</summary>
</member>
<member name="M:webGraph.search(std.vector&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.allocator&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;&gt;&gt;)" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webGraph.h" line="133">
<summary>
searches for webpages in a graph given a query
</summary>
<param name="normalizedQry">The normalized query</param>
<returns>vector of webpages</returns>
</member>
<member name="T:utils" decl="false" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\utils.h" line="11">
<summary>
utilties class
contains all functions unrelated to other classes
</summary>
</member>
<member name="M:utils.parse_webpages" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\utils.h" line="19">
<summary>
parses webpages from csv files 
</summary>
<returns>vector of webpages</returns>
</member>
<member name="M:utils.parse_webEdges" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\utils.h" line="25">
<summary>
parses edges csv
</summary>
<returns></returns>
</member>
<member name="M:utils.intialize_webGraph" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\utils.h" line="31">
<summary>
intialization of the graph of webpages
</summary>
<returns>pointer to webGraph</returns>
</member>
<member name="M:utils.normalizeQry(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\utils.h" line="37">
<summary>
normalizes the search query into a vector of strings
each string is a keyword or a token
</summary>
<param name="qry">query as a string</param>
<returns>vector of string</returns>
</member>
<member name="M:utils.write_to_files(webGraph*)" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\utils.h" line="45">
<summary>
updates files with new calues of impressions and clickthroughs after user session
</summary>
<param name="g">graph intialized in main</param>
</member>
</members>
</doc>