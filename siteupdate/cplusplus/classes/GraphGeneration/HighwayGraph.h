class ElapsedTime;
class GraphListEntry;
class HGEdge;
class HGVertex;
class HighwaySystem;
class TravelerList;
class Waypoint;
class WaypointQuadtree;
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class HighwayGraph
{   /* This class implements the capability to create graph
    data structures representing the highway data.

    On construction, build a set of unique vertex names
    and determine edges, at most one per concurrent segment.
    Create three sets of edges:
     - one for the simple graph
     - one for the collapsed graph with hidden waypoints compressed into multi-point edges
     - one for the traveled graph: collapsed edges split at endpoints of users' travels
    */

	public:
	// first, find unique waypoints and create vertex labels
	std::unordered_set<std::string> vertex_names;
	// to track the waypoint name compressions, add log entries
	// to this list
	std::list<std::string> waypoint_naming_log;
	std::unordered_map<Waypoint*, HGVertex*> vertices;

	HighwayGraph(WaypointQuadtree&, std::list<HighwaySystem*>&, unsigned int, ElapsedTime&);

	void clear();

	inline void matching_vertices_and_edges
	(	GraphListEntry&, WaypointQuadtree*,
		std::list<TravelerList*> &,
		std::unordered_set<HGVertex*>&,	// final set of vertices matching all criteria
		std::unordered_set<HGEdge*>&,	// matching    simple edges
		std::unordered_set<HGEdge*>&,	// matching collapsed edges
		std::unordered_set<HGEdge*>&,	// matching  traveled edges
		unsigned int&, unsigned int&
	);

	void write_master_graphs_tmg(std::vector<GraphListEntry>&, std::string, std::list<TravelerList*>&);
	void write_subgraphs_tmg(std::vector<GraphListEntry>&, std::string, size_t, unsigned int, WaypointQuadtree*, ElapsedTime*);
};
