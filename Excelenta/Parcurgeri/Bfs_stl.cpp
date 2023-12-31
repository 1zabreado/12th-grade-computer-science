/* Parcurgere pe Latime (largime)
 * Breadth First Search
 */ 

#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("graf5.in");
ofstream fout("graf5.out");

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI>VVI;

int n;
VVI G;
VB v;

void CitesteGraf();
void Bfs(int x);

int main()
{
	CitesteGraf();
	Bfs(1);

	return 0;
}

void Bfs(int x)
{
	queue<int> Q; // coada vida

	Q.push(x);
	v[x] = true;

	fout << x << ' ';
	while (!Q.empty()) // cat timp coada nu este vida
	{
		x = Q.front();	// aflam primul nod din coada
		Q.pop();		// apoi il stergem 

		for (int const& y : G[x])
			if (!v[y])
			{
				v[y] = true;
				Q.push(y);
				fout << y << ' ';
			}
	}
}

void CitesteGraf()
{
	fin >> n;
	G = VVI(n + 1);
	v = VB(n + 1);

	int x, y;
	while (fin >> x >> y)
	{
		G[x].push_back(y);
		G[y].push_back(x);
	}
}