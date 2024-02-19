struct TEdges {
	int StartPoint;
	int EndPoint;
	int Weight;
};
struct TTree {
	int StartPoint;
	int EndPoint;
};

int cmp(const void* a, const void* b);
int Find(int* parent, int index);
void Union(int* parent, int* rank, int start, int end);
