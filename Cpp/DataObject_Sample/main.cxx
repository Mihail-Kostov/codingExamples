#include "DecayVertex.h"

int main(int argv, char** argc){

	using dv = AuxVertex::DecayVertex;

	dv::DecayVertex v1(10.,-52.,1322.,0,0,"t","t");
	dv::DecayVertex v2(45.,32.,789.,1,1,"s","s");

	dv::DecayVertex v0 = AuxVertex::MeanVertex(v1,v2);
	printf("Distance: %.1f\n", AuxVertex::Distance(v1,v2));
	printf("Vertex coordinates: [%.1f,%.1f,%.1f]\n", v0.GetX(), v0.GetY(), v0.GetZ());
	printf("Vertex parent types: [%s,%s]\n",v0.GetParType1().c_str(),v0.GetParType2().c_str());

	return 0;
}
