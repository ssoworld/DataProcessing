class HGEdge;
class HighwaySystem;
class Region;
class Waypoint;
#include <list>
#include <string>
#include <unordered_set>

class HGVertex
{   /* This class encapsulates information needed for a highway graph
    vertex.
    */
	public:
	double lat, lng;
	const std::string *unique_name;
	char visibility;
	Waypoint *first_waypoint;
	std::unordered_set<Region*> regions;
	std::unordered_set<HighwaySystem*> systems;
	std::list<HGEdge*> incident_s_edges; // simple
	std::list<HGEdge*> incident_c_edges; // collapsed
	std::list<HGEdge*> incident_t_edges; // traveled
	int *s_vertex_num;
	int *c_vertex_num;
	int *t_vertex_num;

	HGVertex(Waypoint*, const std::string*, unsigned int);
	~HGVertex();
};
