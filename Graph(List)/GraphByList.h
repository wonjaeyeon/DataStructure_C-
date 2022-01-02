typedef struct graphNode
{
	int id;
	graphNode *link;
} NODE_GRAPH;

const int MAX_VERTEX = 256;

class GraphByList
{
protected:
	int totalVertex;			 //������ ����
	char vertices[MAX_VERTEX];	 //���� ����
	NODE_GRAPH *adj[MAX_VERTEX]; //�� ������ ���� ����Ʈ

public:
	GraphByList(void);
	~GraphByList(void);

	void reset(void);
	bool isEmpty();
	bool isFull();
	char getVertex(int i);

	void insertVertex(char val);
	void insertEdge(int v1, int v2);

	void printGraph();

	NODE_GRAPH *adjacent(int v);
};
