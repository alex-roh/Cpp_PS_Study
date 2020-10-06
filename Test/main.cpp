#include<stdio.h>
#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<iterator>
using namespace std;
int unf[10001];

struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
	bool operator<(Edge &b){
		return val<b.val;
	}
};

ostream& operator<<(ostream& os, const Edge& Edge)
{
    os << "Edge(" << Edge.s << ", " << Edge.e << ", " << Edge.val <<")";
    return os;
}

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main(){
	freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;
	int i, n, m, a, b, c, cnt=0, res=0;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		unf[i]=i;
	}
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));	
	}
	sort(Ed.begin(), Ed.end());
	copy(Ed.begin(), Ed.end(), ostream_iterator<Edge>(cout, "\n"));
	for(i=0; i<m; i++){
		int fa=Find(Ed[i].s);
		int fb=Find(Ed[i].e);
		if(fa!=fb){
			res+=Ed[i].val;
			Union(Ed[i].s, Ed[i].e);
		}
	}
	printf("%d\n", res);
	return 0;
}
